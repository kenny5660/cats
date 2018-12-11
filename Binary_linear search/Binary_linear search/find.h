#include <iterator>

template <typename T, typename Iterator>

Iterator Find(
    const T& value, Iterator first, Iterator last,
    typename std::enable_if<
        std::is_same<typename std::iterator_traits<Iterator>::iterator_category,
                     std::random_access_iterator_tag>::value,
        Iterator>::type* = 0) {
  Iterator it = std::lower_bound(first, last, value);
  if ((*it) == value) {
    return it;
  }
  return last;
}

template <typename T, typename Iterator>
Iterator Find(
    const T& value, Iterator first, Iterator last,
    typename std::enable_if<
        !std::is_same<
            typename std::iterator_traits<Iterator>::iterator_category,
            std::random_access_iterator_tag>::value,
        Iterator>::type* = 0) {
  return std::find(first, last, value);
}
