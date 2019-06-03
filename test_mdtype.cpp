#include <iostream>

#include <boost/hana.hpp>
#include <boost/hana/experimental/printable.hpp>

#include "mdarray.hpp"

int main() {
  namespace hana = boost::hana;
  using namespace hana::literals;

  using linear_arr_type =
    decltype(detail::make_array_type(hana::type_c<long>, 10_c))::type;
  using md_type = decltype(detail::get_mdarray_type(
    hana::type_c<char>, 3_c, 4_c, 5_c))::type;

  using md_type_alias = util::mdarray_t<char, 3, 4, 5>;

  std::cout << hana::experimental::print(hana::type_c<linear_arr_type>) << '\n';
  std::cout << hana::experimental::print(hana::type_c<md_type>) << '\n';
  std::cout << hana::experimental::print(hana::type_c<md_type_alias>) << '\n';

  return 0;
}
