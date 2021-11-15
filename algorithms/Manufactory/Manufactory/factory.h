#pragma once
#include <functional>
#include <map>
#include <string>
#include <utility>
class Object {
 public:
  virtual std::string ToString() const = 0;
};
class Child : public Object {
 public:
  explicit Child(std::string name_id) : name_id_(name_id) {}
  std::string ToString() const override { return name_id_; }

 private:
  std::string name_id_;
};

Object* creator_apple() { return new Child("apple!"); }
Object* creator_list() { return new Child("list"); }
Object* creator_yet() { return new Child("yet another identifier"); }

class Factory {
 public:
  Factory() {
    creator_table.insert(std::make_pair("apple!", &creator_apple));
    creator_table.insert(std::make_pair("list", &creator_list));
    creator_table.insert(
        std::make_pair("yet another identifier", &creator_yet));
  }
  Object* Create(const std::string& class_id) {
    auto it = creator_table.find(class_id);
    return (*it).second();
  }

  void Register(const std::string& class_id, Object* (*instance_creator)()) {
    creator_table.insert(std::make_pair(class_id, instance_creator));
  }

 private:
  std::map<std::string, Object* (*)()> creator_table;
};
