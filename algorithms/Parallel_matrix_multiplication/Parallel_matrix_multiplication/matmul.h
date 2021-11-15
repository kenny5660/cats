#pragma once
#include <vector>
void MatMulParalByRowsThread(const DenseMat& a, const DenseMat& b, DenseMat* c,
                             size_t startRow, size_t endRow) {
  for (int i = startRow; i < endRow; i++) {
    for (int j = 0; j < b.Cols(); j++) {
      for (int k = 0; k < a.Cols(); k++) {
        (*c)(i, j) += a(i, k) * b(k, j);
      }
    }
  }
}

DenseMat MatMulParal(const DenseMat& a, const DenseMat& b, int thread_count) {
  DenseMat c(a.Rows(), b.Cols());
  std::vector<std::thread*> threads;
  size_t rows = a.Rows();
  size_t oneThredRows = rows / thread_count;
  size_t startRow = 0;
  for (int k = 1; k < thread_count; ++k) {
    threads.push_back(new std::thread(MatMulParalByRowsThread, std::ref(a),
                                      std::ref(b), &c, startRow,
                                      startRow + oneThredRows));
    startRow += oneThredRows;
  }
  threads.push_back(new std::thread(MatMulParalByRowsThread, std::ref(a),
                                    std::ref(b), &c, startRow, rows));
  for (int k = 0; k < thread_count; ++k) {
    threads[k]->join();
  }
  return c;
}
