#pragma once
#include <mutex>
#include <queue>
#include <string>
#include <utility>
template <typename T>
class Queue {
 public:
  T Pop() {
    mu.lock();
    T elm = std::move(q.front());
    q.pop();
    mu.unlock();
    return elm;
  }

  size_t Size() {
    mu.lock();
    size_t size = q.size();
    mu.unlock();
    return size;
  }

  template <typename U>
  void Push(U&& elm) {
    mu.lock();
    q.push(std::move(elm));
    mu.unlock();
  }

  template <typename... U>
  void Emplace(U&&... args) {
    Push(T(args...));
  }

 private:
  std::queue<T> q;
  std::mutex mu;
};
