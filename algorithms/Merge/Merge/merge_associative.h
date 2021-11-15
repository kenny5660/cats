#include <unordered_map>
#include <unordered_set>

#include <type_traits>

#include <map>
#include <set>



template <typename T>
struct to_void {
  typedef void type;
};

template <typename Container, typename dummy = void>
struct is_map_container : std::false_type {};

template <typename Container>
struct is_map_container<Container,
                        typename to_void<typename Container::mapped_type>::type>
    : std::true_type {};

template <typename Container, typename dummy = void>
struct is_associative_container : std::false_type {};

template <typename Container>
struct is_associative_container<
    Container, typename to_void<typename Container::key_type>::type>
    : std::true_type {};

template <typename Container>
struct is_multi_container : std::false_type {};

template <typename Container>
struct is_unique_container
    : std::conditional<is_multi_container<Container>::value, std::false_type,
                       std::true_type>::type {};

template <typename Container>
struct is_unordered_container : std::false_type {};

template <typename Container>
struct is_ordered_container
    : std::conditional<is_unordered_container<Container>::value,
                       std::false_type, std::true_type>::type {};

template <typename T, typename Compare, typename Alloc>
struct is_multi_container<std::multiset<T, Compare, Alloc>> : std::true_type {};

template <typename T, typename Compare, typename Alloc>
struct is_multi_container<std::multimap<T, Compare, Alloc>> : std::true_type {};

template <typename T, typename Hash, typename Pred, typename Alloc>
struct is_multi_container<std::unordered_multimap<T, Hash, Pred, Alloc>>
    : std::true_type {};

template <typename T, typename Hash, typename Pred, typename Alloc>
struct is_multi_container<std::unordered_multiset<T, Hash, Pred, Alloc>>
    : std::true_type {};

template <typename T, typename Hash, typename Pred, typename Alloc>
struct is_unordered_container<std::unordered_multimap<T, Hash, Pred, Alloc>>
    : std::true_type {};

template <typename T, typename Hash, typename Pred, typename Alloc>
struct is_unordered_container<std::unordered_map<T, Hash, Pred, Alloc>>
    : std::true_type {};

template <typename T, typename Hash, typename Pred, typename Alloc>
struct is_unordered_container<std::unordered_multiset<T, Hash, Pred, Alloc>>
    : std::true_type {};

template <typename T, typename Hash, typename Pred, typename Alloc>
struct is_unordered_container<std::unordered_set<T, Hash, Pred, Alloc>>
    : std::true_type {};

template <class C1, class C2>
bool MergeAssociative(
    C1* c1, const C2& c2,
    typename std::enable_if<is_map_container<C1>::value &&
                                is_map_container<C2>::value,
                            int>::type* = 0,
    typename std::enable_if<
        (is_multi_container<C1>::value ||
         (!is_multi_container<C1>::value && !is_multi_container<C2>::value)) &&
            std::is_same<
                typename std::remove_cv<typename C1::key_type>::type,
                typename std::remove_cv<typename C2::key_type>::type>::value &&
            std::is_same<
                typename std::remove_cv<typename C1::mapped_type>::type,
                typename std::remove_cv<typename C2::mapped_type>::type>::value,
        int>::type* = 0

) {
  c1->insert(c2.begin(), c2.end());
  return false;
}

template <class C1, class C2>
bool MergeAssociative(
    C1* c1, const C2& c2,
    typename std::enable_if<(is_associative_container<C1>::value &&
                             !is_map_container<C1>::value) &&
                                (is_associative_container<C2>::value &&
                                 !is_map_container<C2>::value),
                            int>::type* = 0,
    typename std::enable_if<
        (is_multi_container<C1>::value ||
         (!is_multi_container<C1>::value && !is_multi_container<C2>::value)) &&
            std::is_same<
                typename std::remove_cv<typename C1::key_type>::type,
                typename std::remove_cv<typename C2::key_type>::type>::value,
        int>::type* = 0

) {
  c1->insert(c2.begin(), c2.end());
  return false;
}

template <class C1, class C2>
bool MergeAssociative(
    C1* c1, const C2& c2,
    typename std::enable_if<is_map_container<C1>::value &&
                                is_map_container<C2>::value,
                            int>::type* = 0,
    typename std::enable_if<
        !((is_multi_container<C1>::value || (!is_multi_container<C1>::value &&
                                             !is_multi_container<C2>::value)) &&
          std::is_same<
              typename std::remove_cv<typename C1::key_type>::type,
              typename std::remove_cv<typename C2::key_type>::type>::value &&
          std::is_same<
              typename std::remove_cv<typename C1::mapped_type>::type,
              typename std::remove_cv<typename C2::mapped_type>::type>::value),
        int>::type* = 0

) {
  return true;
}

template <class C1, class C2>
bool MergeAssociative(
    C1* c1, const C2& c2,
    typename std::enable_if<(is_associative_container<C1>::value &&
                             !is_map_container<C1>::value) &&
                                (is_associative_container<C2>::value &&
                                 !is_map_container<C2>::value),
                            int>::type* = 0,
    typename std::enable_if<
        !((is_multi_container<C1>::value || (!is_multi_container<C1>::value &&
                                             !is_multi_container<C2>::value)) &&
          std::is_same<
              typename std::remove_cv<typename C1::key_type>::type,
              typename std::remove_cv<typename C2::key_type>::type>::value),
        int>::type* = 0

) {
  return true;
}

template <class C1, class C2>
bool MergeAssociative(
    C1* c1, const C2& c2,
    typename std::enable_if<is_map_container<C1>::value &&
                                    (is_associative_container<C2>::value &&
                                     !is_map_container<C2>::value) ||
                                is_map_container<C2>::value &&
                                    (is_associative_container<C1>::value &&
                                     !is_map_container<C1>::value),
                            bool>::type** = 0

) {
  return true;
}
//
//template <class C1, class C2>
//bool MergeAssociative(
//    C1* c1, const C2& c2,
//    typename std::enable_if<!(is_associative_container<C1>::value &&
//                              is_associative_container<C2>::value),
//                            bool>::type* = 0
//
//) {
//  return true;
//}
