#include <vector>
class Set {
 public:
  Set();
  explicit Set(const std::vector<int64_t>&);
  Set Union(const Set&);
  Set Intersection(const Set&);
  Set Difference(const Set&);
  Set SymmetricDifference(const Set&);
  void Add(int64_t);
  void Remove(int64_t);
  bool Contains(int64_t);
  std::vector<int64_t> Data();

 private:
  int Search(int64_t);
  std::vector<int64_t> data_;
};

Set::Set() {}
Set::Set(const std::vector<int64_t>& _vec) {
  for (const auto& var : _vec) {
    Add(var);
  }
}

void Set::Add(int64_t value) {
  if (!Contains(value)) {
    data_.push_back(value);
  }
}

int Set::Search(int64_t value) {
  for (size_t i = 0; i < data_.size(); i++) {
    if (data_[i] == value) {
      return i;
    }
  }
  return -1;
}

Set Set::Union(const Set& other) {
  Set result = Set(data_);
  for (const auto& var : other.data_) {
    if (!result.Contains(var)) {
      result.Add(var);
    }
  }
  return result;
}

Set Set::Intersection(const Set& other) {
  Set result = Set();
  for (const auto& var : other.data_) {
    if (Contains(var)) {
      result.Add(var);
    }
  }
  return result;
}

Set Set::Difference(const Set& other) {
  Set result = Set(data_);
  for (const auto& var : other.data_) {
    if (result.Contains(var)) {
      result.Remove(var);
    }
  }
  return result;
}

Set Set::SymmetricDifference(const Set& other) {
  Set result_union = Union(other);
  Set result_intersection = Intersection(other);
  return result_union.Difference(result_intersection);
}

bool Set::Contains(int64_t value) { return Search(value) > -1; }

void Set::Remove(int64_t value) { data_.erase(data_.begin() + Search(value)); }

std::vector<int64_t> Set::Data() { return data_; }
