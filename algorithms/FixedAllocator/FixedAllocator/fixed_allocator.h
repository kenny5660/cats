#pragma once
#include <vector>

struct Chunk {
  char buff[1024];
  Chunk* next = nullptr;
};

class FixedAllocator {
 public:
  FixedAllocator(size_t chunk_size, size_t page_size)
      : chunk_size_(chunk_size), page_size_(page_size) {}
  void* Allocate() {
    if (free == nullptr) new_pool();
    auto result = free;
    free = free->next;
    return static_cast<void*>(result);
  }
  void Deallocate(void* ptr) {
    auto node = static_cast<Chunk*>(ptr);
    node->next = free;
    free = node;
  }
  ~FixedAllocator() {
    for (int i = 0; i < pools.size(); ++i) {
      delete pools[i];
    }
  }

 private:
  size_t chunk_size_;
  size_t page_size_;
  std::vector<void*> pools;
  void new_pool() {
    Chunk* pool = new Chunk[sizeof(Chunk) * page_size_];
    pools.push_back(pool);
    for (int i = 0; i < page_size_; ++i) {
      pool[i].next = &pool[i + 1];
    }
    free = pool;
  }

  Chunk* free = nullptr;  // current pool std::vector<Chunk*> pools;
};
