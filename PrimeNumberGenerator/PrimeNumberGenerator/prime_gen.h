#pragma once
#include <algorithm>
#include <limits>

class PrimeNumberGenerator {
 public:
  explicit PrimeNumberGenerator(int start);
  int GetNextPrime();

 private:
  int current_;
};

PrimeNumberGenerator::PrimeNumberGenerator(int start) { current_ = start - 1; }

int PrimeNumberGenerator::GetNextPrime() {
  bool is_prime = true;
  for (int i = std::max(current_ + 1, 2); i < INT_MAX; i++) {
    is_prime = true;
    for (int j = 2; j < sqrt(i + 1); j++) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      current_ = i;
      return i;
    }
  }
}
