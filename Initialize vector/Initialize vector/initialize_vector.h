#include <vector>
template <typename Val_t, typename Dim>
std::vector<Val_t> make_vector(Val_t val, Dim dim) {
  return std::vector<Val_t>(dim, val);
}
template <typename Val_t, typename Dim>
auto initialize_vector(Val_t val, Dim dim) {
  return make_vector(val, dim);
}
template <typename Val_t, typename Dim_head, typename... Dims>
auto initialize_vector(Val_t val, Dim_head dim_head, Dims... dims) {
  return make_vector(initialize_vector(val, dims...), dim_head);
}