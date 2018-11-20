#include <functional>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>

bool operator>(const GameObject& a, const GameObject& b) { return a.id > b.id; }

class GameDatabase {
 public:
  GameDatabase() = default;
  void Insert(ObjectId id, std::string name, size_t x, size_t y) {
    auto it = data_base_.find(id);
    if (it == data_base_.end()) {
      data_base_.insert(
          pair<ObjectId, GameObject>(id, GameObject{id, name, x, y}));
      deleted.erase(id);
    } else {
      auto itName = data_base_name.find((*it).second.name);
      (*itName).second.erase((*it).first);
      auto itPos =
          data_base_pos.find(make_pair((*it).second.x, (*it).second.y));
      (*itPos).second.erase((*it).first);
      (*it).second = GameObject{id, name, x, y};
      deleted.erase(id);
    }
    auto itName = data_base_name.find(name);
    if (itName == data_base_name.end()) {
      set<ObjectId, std::greater<ObjectId>> setId;
      setId.insert(id);
      data_base_name.insert(make_pair(name, setId));
    } else {
      (*itName).second.insert(id);
    }

    auto itPos = data_base_pos.find(make_pair(x, y));
    if (itPos == data_base_pos.end()) {
      set<ObjectId, std::greater<ObjectId>> setId;
      setId.insert(id);
      data_base_pos.insert(make_pair(make_pair(x, y), setId));
    } else {
      (*itPos).second.insert(id);
    }
  }

  void Remove(ObjectId id) { deleted.insert(id); }

  std::pair<GameObject, bool> DataById(ObjectId id) const {
    auto it = data_base_.find(id);
    auto itDel = deleted.find(id);
    if (it != data_base_.end() && itDel == deleted.end()) {
      return make_pair((*it).second, true);
    } else {
      return make_pair(GameObject(), false);
    }
  }

  std::vector<GameObject> DataByName(std::string name) const {
    std::vector<GameObject> out;
    auto itName = data_base_name.find(name);
    if (itName != data_base_name.end()) {
      for (auto it = (*itName).second.begin(); it != (*itName).second.end();
           ++it) {
        auto itDel = deleted.find(*it);

        if (itDel == deleted.end()) {
          auto itData = data_base_.find(*it);
          out.push_back((*itData).second);
        }
      }
    }
    return out;
  }

  std::vector<GameObject> DataByPosition(size_t x, size_t y) const {
    std::vector<GameObject> out;
    auto itName = data_base_pos.find(make_pair(x, y));
    if (itName != data_base_pos.end()) {
      for (auto it = (*itName).second.begin(); it != (*itName).second.end();
           ++it) {
        auto itDel = deleted.find(*it);

        if (itDel == deleted.end()) {
          auto itData = data_base_.find(*it);
          out.push_back((*itData).second);
        }
      }
    }
    return out;
  }
  std::vector<GameObject> Data() const {
    std::vector<GameObject> out;
    for (auto it = data_base_.begin(); it != data_base_.end(); ++it) {
      auto itDel = deleted.find((*it).first);
      if (itDel == deleted.end()) {
        out.push_back((*it).second);
      }
    }

    return out;
  }

 private:
  std::map<ObjectId, GameObject, std::greater<ObjectId>> data_base_;
  std::map<pair<int, int>, set<ObjectId, std::greater<ObjectId>>> data_base_pos;
  std::map<std::string, set<ObjectId, std::greater<ObjectId>>> data_base_name;
  std::set<ObjectId> deleted;
};
