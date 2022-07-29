#include <iostream>
#include <type_traits>


namespace tps {   // Types
  using size_t = decltype(sizeof(int));
}

template <class>
constexpr bool is_array_v = false;

template <typename _Ty, size_t _Nx>
constexpr bool is_array_v<_Ty[_Nx]> = true;

template <typename _Ty>
constexpr bool is_array_v<_Ty[   ]> = true;

static_assert(is_array_v<int[]>, " == is_array_v<int[]> == ");

//static_assert(std::is_same_v<char[], char[1]>, " == is_array_v<int[]> == ");


int main()
{
  // using size_t = decltype(sizeof(int));
  // + x86 -> unsigned int  ,   x64 -> unsigned __int64
  std::cout << typeid(tps::size_t).name() << std::endl;
  


  return 0;
};