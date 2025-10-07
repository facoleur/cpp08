// main.cpp

#include "Span.hpp"
#include <cassert>
#include <iostream>

void testBasic() {
  Span s(5);
  s.addNumber(6);
  s.addNumber(3);
  s.addNumber(17);
  s.addNumber(9);
  s.addNumber(11);

  assert(s.shortestSpan() == 2);
  assert(s.longestSpan() == 14);

  std::cout << "passed" << std::endl;
}

void testRange() {
  Span s(10);
  int arr[] = {1, 2, 3, 4, 5};
  size_t size = sizeof(arr) / sizeof(arr[0]);

  s.addNumbers(arr, size);

  assert(s.shortestSpan() == 1);
  assert(s.longestSpan() == 4);

  std::cout << "passed" << std::endl;
}

void testLarge() {
  int large = 10000;

  Span s(large);
  for (int i = 0; i < large; i++)
    s.addNumber(i);

  assert(s.shortestSpan() == 1);
  assert(s.longestSpan() == large - 1);
  std::cout << "passed" << std::endl;
}

void testOverflow() {
  bool thrown = false;
  Span s(3);

  try {
    s.addNumber(1);
    s.addNumber(2);
    s.addNumber(3);
    s.addNumber(4);
  } catch (std::exception &e) {
    thrown = true;
  }
  assert(thrown);
  std::cout << "passed" << std::endl;
}

void testNotEnoughElements() {
  Span s(5);
  s.addNumber(42);
  bool thrown = false;

  try {
    s.shortestSpan();
  } catch (std::exception &e) {
    thrown = true;
  }
  assert(thrown);
  std::cout << "passed" << std::endl;
}

void testNegative() {
  Span s(5);
  s.addNumber(-10);
  s.addNumber(-5);
  s.addNumber(0);

  assert(s.shortestSpan() == 5);
  assert(s.longestSpan() == 10);
  std::cout << "passed" << std::endl;
}

void testDuplicates() {
  Span s(5);
  s.addNumber(5);
  s.addNumber(5);
  s.addNumber(5);

  assert(s.shortestSpan() == 0);
  assert(s.longestSpan() == 0);
  std::cout << "passed" << std::endl;
}

int *generateRandomNumbers(int size, int min, int max) {
  srand(static_cast<unsigned int>(time(0)));

  int *arr = new int[size];
  for (int i = 0; i < size; ++i) {
    arr[i] = min + rand() % (max - min + 1);
  }
  return arr;
}

int main() {

  int size = 10;
  int min = 1;
  int max = 100;

  Span n(size);
  int *nbr = generateRandomNumbers(size, min, max);

  n.addNumbers(nbr, size);

  n.printNumbers();

  std::cout << "shortest: " << n.shortestSpan() << std::endl;
  std::cout << "longest : " << n.longestSpan() << std::endl;

  // testBasic();
  // testRange();
  // testLarge();
  // testOverflow();
  // testNotEnoughElements();
  // testNegative();
  // testDuplicates();

  return 0;
}

// // main of the subject:
// int main() {
//   Span sp = Span(5);
//   sp.addNumber(6);
//   sp.addNumber(3);
//   sp.addNumber(17);
//   sp.addNumber(9);
//   sp.addNumber(11);
//   std::cout << sp.shortestSpan() << std::endl;
//   std::cout << sp.longestSpan() << std::endl;
//   return 0;
// }
