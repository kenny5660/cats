#include <atomic>
#include <mutex>
#include <queue>
#include <thread>
class Semaphore {
 public:
  explicit Semaphore(int threads_cnt) {
    count = 0;
    size = threads_cnt;
  }
  void Wait() {
    std::unique_lock<decltype(m_count)> lock(m_count);
    ++count;
    if (count > size) {
      do {
        condition_.wait(lock);
      } while (is_can == false);
      is_can == false;
    }
  }
  void Notify() {
    std::unique_lock<std::mutex> lck(m_count);
    if (--count >= size) {
      is_can = true;
      condition_.notify_one();
    }
  }

 private:
  int size;
  std::atomic<int> count;
  std::mutex m_count, condition;
  bool is_can = false;
  std::condition_variable condition_;
  std::queue<std::thread::id> qThreads;
};
