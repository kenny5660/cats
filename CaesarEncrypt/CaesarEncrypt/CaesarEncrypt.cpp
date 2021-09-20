#include <chrono>
#include <fstream>
#include <functional>

using namespace std;

template <typename TimePoint>
class basic_time_meter {
  function<TimePoint()> get_now_;
  function<double(TimePoint, TimePoint)> get_sec_;

  TimePoint begin_;
  TimePoint stop_;
  bool stopped_;

 public:
  template <typename GetNow, typename GetSec>
  basic_time_meter(GetNow&& gn, GetSec&& gs)
      : get_now_(std::forward<GetNow>(gn)),
        get_sec_(std::forward<GetSec>(gs)),
        begin_(get_now_()),
        stopped_(false) {}

  double seconds() const {
    if (stopped_) return get_sec_(begin_, stop_);
    return get_sec_(begin_, get_now_());
  }

  double restart() {
    const TimePoint now = get_now_();
    double result = seconds(now);
    stopped_ = false;
    begin_ = now;
    return result;
  }

  double stop() {
    if (stopped_) return seconds();
    stop_ = get_now_();
    stopped_ = true;
    return seconds(stop_);
  }

  void start() {
    if (!stopped_) return;
    stopped_ = false;
    begin_ += get_now_() - stop_;
  }

  bool stopped() const { return stopped_; }

 private:
  double seconds(TimePoint now) const {
    if (stopped_) return get_sec_(begin_, stop_);
    return get_sec_(begin_, now);
  }
};

class time_meter
    : public basic_time_meter<chrono::high_resolution_clock::time_point> {
  using time_point = chrono::high_resolution_clock::time_point;

  static double get_seconds(time_point p1, time_point p2) {
    return static_cast<double>((p2 - p1).count()) /
           chrono::high_resolution_clock::period::den;
  }

 public:
  time_meter()
      : basic_time_meter<time_point>(chrono::high_resolution_clock::now,
                                     get_seconds) {}
};

// **********************

void ___CaesarEncryptOneThread___(std::string* s) {
  for (char& c : *s) c = 'a' + (c + 3 - 'a') % 26;
}

#include "caesar_encrypt.h"

int main() {
  ifstream input_file("input.txt");
  ofstream output_file("output.txt");
  string s;
  input_file >> s;
  string s2 = s;

  time_meter tm;
  ___CaesarEncryptOneThread___(&s2);
  const double one_thread_result = tm.seconds();
  vector<double> results;
  output_file << "String size = "
              << s.size()<<endl;
  output_file << "one_thread_result= " << one_thread_result << endl;
  for (int i = 1; i <= 8; ++i) {
    string s1 = s;
  tm.restart();
  CaesarEncrypt(&s1, i);
  double result = tm.seconds();
  output_file << "Threads " << i << " time " << result <<" time / time_one_thread = "<< result/one_thread_result << " norm = "<< (bool)(s1 == s2) << endl;
 // results.push_back(tm.seconds());
  tm.restart();
  }
  return 0;
}
