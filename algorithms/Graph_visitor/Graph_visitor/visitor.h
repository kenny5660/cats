#include <memory>
#include <unordered_map>
template <class Vertex>
struct BfsVisitor_content {
  std::unordered_map<Vertex, int> dist;
  std::unordered_map<Vertex, Vertex> ostov_parant;
  Vertex Examined_vertex;
  bool is_first = true;
};

template <class Vertex>
class BfsVisitor {
 public:
  BfsVisitor() : visit_content(new BfsVisitor_content<Vertex>()) {}
  void ExamineVertex(const Vertex& vertex) {
    visit_content->Examined_vertex = vertex;
  }
  void DiscoverVertex(const Vertex& vertex) {
    if (!visit_content->is_first) {
      visit_content->dist[vertex] =
          visit_content->dist[visit_content->Examined_vertex] + 1;
      visit_content->ostov_parant[vertex] = visit_content->Examined_vertex;
    } else {
      visit_content->dist[vertex] = 0;
      visit_content->ostov_parant[vertex] = vertex;
      visit_content->is_first = false;
    }
  }

  size_t DistanceTo(const Vertex& target) const {
    return visit_content->dist[target];
  }

  Vertex Parent(const Vertex& vertex) const {
    return visit_content->ostov_parant[vertex];
  }

 private:
  std::shared_ptr<BfsVisitor_content<Vertex>> visit_content;
};
