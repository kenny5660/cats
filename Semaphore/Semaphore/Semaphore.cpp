#include <atomic>
#include <cassert>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

#include "semaphore.h"

using namespace std::chrono_literals;

int main() {
  {
    for (int i = 0; i < 10; ++i) {
      Semaphore s(1);
      int time = 0;
      std::atomic_int wait = 1;
      std::vector<std::thread> threads;

      threads.emplace_back([&time, &s, &wait]() {
        s.Wait();
        assert(time == 0);
        ++time;
        while (wait) {
        }
        s.Notify();
      });

      std::this_thread::sleep_for(50ms);

      threads.emplace_back([&time, &s]() {
        s.Wait();
        assert(time == 1);
        ++time;
        s.Notify();
      });

      threads.emplace_back([&time, &s, &wait]() {
        while (wait) {
        }
        s.Wait();
        assert(time == 2);
        ++time;
        s.Notify();
      });

      std::this_thread::sleep_for(50ms);
      wait = 0;

      for (auto& th : threads) {
        th.join();
	      }
    }
  }

  {
    for (int thread_cnt = 1; thread_cnt <= 4; ++thread_cnt) {
      Semaphore s(thread_cnt);

      for (int cnt = 5; cnt < 10; ++cnt) {
        std::vector<int> v;
        std::vector<std::thread> threads;

        std::thread st([&s, &threads, &v, cnt, thread_cnt]() {
          s.Wait();
          for (int i = 0; i < cnt; ++i) {
            threads.emplace_back(
                [i, &s, &v](int val) {
                  s.Wait();
                  v.push_back(val);
                  s.Notify();
                },
                i / thread_cnt);
            std::this_thread::sleep_for(10ms);
          }
          s.Notify();
        });
        st.join();
        for (auto& th : threads) {
          th.join();
        }

        assert(v.size() == cnt);
        for (int i = 0; i < cnt; ++i) {
          assert(v[i] == i / thread_cnt);
        }
      }
    }
  }

  std::cout << 1;
}