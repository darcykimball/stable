#pragma once

#include <array>

#include <boost/hana.hpp>

namespace detail {

namespace hana = boost::hana;

// Construct an array type
constexpr auto make_array_type = [](auto&& elem_type, auto&& size) {
  constexpr auto size_v = hana::value(size);  
  using elem_t = typename decltype(+elem_type)::type;
  return hana::type_c<std::array<elem_t, size_v>>;
};

// Calculate the appropriate nested std::array type should be for a multi-
// dimensional array
constexpr auto get_mdarray_type = [](auto&& elem_type, auto&& ...dims) {
  return hana::fold_right(
    hana::make_tuple(dims...),
    elem_type,
    hana::flip(make_array_type)
  );
};

} // namespace detail

namespace util {

namespace hana = boost::hana;

// Type alias for multidimensional arrays
template <typename Elem, size_t ...Dims>
using mdarray_t = 
  typename decltype(
    detail::get_mdarray_type(hana::type_c<Elem>, hana::size_c<Dims>...)
  )::type;

} // namespace util
