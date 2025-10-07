// Span.hpp

#pragma once

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

class Span {
public:
  Span(unsigned int N);
  Span(const Span &other);
  Span &operator=(const Span &other);
  ~Span();

  void addNumber(int n);
  void addNumbers(int *nbr, size_t size);

  void printNumbers();

  int shortestSpan();
  int longestSpan();

private:
  std::vector<int> numbers;
  size_t capacity;
};
