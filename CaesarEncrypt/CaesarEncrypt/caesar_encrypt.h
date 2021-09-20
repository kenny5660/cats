#pragma once
#include <string>
#include <thread>
#include <vector>
void CaesarEncryptThread(std::string::iterator begin,
                         std::string::iterator end) {
	for (std::string::iterator iter =begin; iter !=end; iter++) {
          *iter = 'a' + (*iter + 3 - 'a') % 26;
	}
}
void CaesarEncrypt(std::string* s,int n) {
  std::vector<std::thread*> threads;
  unsigned int n_threads = n;  // std::thread::hardware_concurrency();
  size_t size_sub_str = s->size() / n_threads;
  std::string::iterator begin = s->begin();
  std::string::iterator mid = begin+size_sub_str;
  std::string::iterator end = s->end();
  for (size_t i = 0; i < n_threads-1; ++i) {
    threads.push_back(new std::thread(CaesarEncryptThread,begin,mid));
    begin += size_sub_str;
    mid += size_sub_str;
  }
  threads.push_back(
      new std::thread(CaesarEncryptThread, std::ref(begin), std::ref(end)));

  for (size_t i = 0; i < n_threads; ++i) {
    threads[i]->join();
  }
}