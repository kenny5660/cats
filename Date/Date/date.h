#include <iomanip>
#include <string>

class Date {
 public:
  Date(int year, int month, int day);
  bool IsLeap();
  std::string ToString();
  Date DaysLater(int days);
  int DaysLeft(Date date);

 private:
  static Date FromJDN(int jdn);
  int ToJDN();
  int year_;
  int month_;
  int day_;
};

Date::Date(int year, int month, int day)
    : year_(year), month_(month), day_(day) {}

bool Date::IsLeap() {
  return (year_ % 4 == 0 && year_ % 100 != 0) || year_ % 400 == 0;
}

std::string Date::ToString() {
  std::ostringstream str_stream;
  str_stream << std::setfill('0') << std::setw(2) << day_ << "."
             << std::setfill('0') << std::setw(2) << month_ << "."
             << std::setfill('0') << std::setw(4) << year_;
  return str_stream.str();
}

int Date::ToJDN() {
  int a = (14 - month_) / 12;
  int y = year_ + 4800 - a;
  int m = month_ + 12 * a - 3;
  return day_ + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;
}

Date Date::FromJDN(int jdn) {
  int a = jdn + 32044;
  int b = (4 * a + 3) / 146097;
  int c = a - (146097 * b) / 4;
  int d = (4 * c + 3) / 1461;
  int e = c - (1461 * d) / 4;
  int m = (5 * e + 2) / 153;
  int day = e - (153 * m + 2) / 5 + 1;
  int month = m + 3 - 12 * (m / 10);
  int year = 100 * b + d - 4800 + (m / 10);
  return Date(year, month, day);
}

Date Date::DaysLater(int days) {
  int JDN_days = this->ToJDN() + days;
  return Date::FromJDN(JDN_days);
}

int Date::DaysLeft(Date date) { return date.ToJDN() - this->ToJDN(); }
