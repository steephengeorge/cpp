//http://stackoverflow.com/questions/28432977/generic-way-of-lazily-evaluating-short-circuiting-template-conditional-types
#include <iostream>
#include <type_traits>
#include <tuple>

template <typename T>
struct OneParam
{
  void foo(){std::cout << "OneParam" << std::endl;}
};

template <typename T, typename U>
struct TwoParam
{
  void foo(){std::cout << "TwoParam" << std::endl;}
};

template <bool B, template <typename...> class TrueTemplate, template <typename...> class FalseTemplate, typename ArgsTuple>
struct LazyConditional;

template <template <typename...> class TrueTemplate, template <typename...> class FalseTemplate, typename ... Args>
struct LazyConditional<true, TrueTemplate, FalseTemplate, std::tuple<Args...>>
{
  using type = TrueTemplate<Args...>;
};

template <template <typename...> class TrueTemplate, template <typename...> class FalseTemplate, typename ... Args>
struct LazyConditional<false, TrueTemplate, FalseTemplate, std::tuple<Args...>>
{
  using type = FalseTemplate<Args...>;
};

template <typename ... Args>
struct OneOrTwoParam
{
  using type = typename LazyConditional<sizeof...(Args)==1, OneParam, TwoParam, std::tuple<Args...> >::type;
};

int main()
{
  OneOrTwoParam<int>::type().foo();
  OneOrTwoParam<int, int>::type().foo();
  return 0;
}
