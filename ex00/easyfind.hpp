// easyfind.hpp

#pragma once

#include <algorithm>
#include <cassert>
#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <vector>

template <class T>
typename T::iterator easyfind(T &container, int n) {

  typename T::iterator i = std::find(container.begin(), container.end(), n);

  if (i == container.end())
    throw std::runtime_error("Value not found in container");

  return i;
}
