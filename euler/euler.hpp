#ifndef _EULER_HPP_
#define _EULER_HPP_
#include <array>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <vector>

typedef long long LL;

template <typename T> std::vector<T> reverseX(const std::vector<T> &vc) {
  const size_t size = sqrt(vc.size());

  if (size * size != vc.size()) {
    throw std::invalid_argument("sizes are differnet!");
  }
  std::vector<T> rV(size * size, 0);

  for (size_t a = 0; a != size * size; a++) {
    int multiplier = a / size;
    size_t newA = size - 1 - a + 2 * multiplier * (size);
    rV.at(a) = vc.at(newA);
  }
  return rV;
}

template <typename T> std::vector<T> reverseY(const std::vector<T> &vc) {
  const size_t size = sqrt(vc.size());

  if (size * size != vc.size()) {
    throw std::invalid_argument("sizes are differnet!");
  }
  std::vector<T> rV(size * size, 0);

  for (size_t a = 0; a != size * size; a++) {
    int multiplier = (size - 1) - (a / size);
    size_t newA = size * (2 * multiplier - size + 1) + a;
    rV.at(a) = vc.at(newA);
  }
  return rV;
}

template <typename T>
void printVector(const std::vector<T> &vc, std::ostream &out = std::cout,
                 const char *separator = " ", bool newLine = true) {
  bool isSquare{false};
  size_t size = sqrt(vc.size());
  if (size * size == vc.size()) {
    isSquare = true;
  }
  if (isSquare) {
    size_t count{0};
    for (auto a = vc.begin(); a != vc.end(); a++) {
      out << *a;
      count++;
      if (count % size == 0) {
        out << std::endl;
      } else {
        out << "\t";
      }
    }
  } else {
    std::copy(vc.begin(), vc.end(), std::ostream_iterator<T>(out, separator));
    if (newLine) {
      out << std::endl;
    }
  }
}

template <typename RES> class ReturnFromChronoGraph {
private:
  RES result;
  std::chrono::duration<double> span;
  const char *description;

public:
  ReturnFromChronoGraph(RES res, std::chrono::duration<double> s,
                        const char *desc)
      : result(res), span(s), description(desc){};
  std::string toString() {
    std::ostringstream out{};
    out << "It took " << span.count();
    if (description == "") {
      out << "(" << result << ")";
    } else {
      out << ".\n" << description << " = " << result;
    }
    return out.str();
  }
};

/**
 * @brief return the tail of vector vc
 *
 * @param vc get the remaining array
 * @return std::vector<T>
 */
template <typename T> std::vector<T> tail(const std::vector<T> &vc) {
  if (vc.size() == 0) {
    throw std::range_error("Vector empty!");
  }
  std::vector<T> retVal{};
  std::copy(vc.begin() + 1, vc.end(), std::back_inserter(retVal));
  return retVal;
}

/**
 * @brief return the first element of vector vc

 * @param vc get the first element
 * @return T
 */
template <typename T> T head(const std::vector<T> &vc) {
  if (vc.size() == 0) {
    throw std::range_error("Vector empty!");
  }
  return vc.at(0);
}

template <typename FUNCTIONTYPE, typename FARGUM>
auto getTimeToComplete(FUNCTIONTYPE function, FARGUM value,
                       const char *description = "") {
  using namespace std::chrono;
  high_resolution_clock::time_point t1 = high_resolution_clock::now();

  auto res = function(value);

  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  ReturnFromChronoGraph<double> a{res, duration_cast<duration<double>>(t2 - t1),
                                  description};
  // return duration_cast<duration<double>>(t2 - t1);
  return a;
}

namespace euler {
/**
 * @brief fill vector "vc" with increments from "from"
 *
 * @param from the initial value
 * @return std::vector<LL>
 */
template <typename T> std::vector<T> fillFrom(const T from, const T end) {
  std::vector<T> vc{from};
  if (end <= from)
    return vc;
  T cnt = from + 1;
  while (cnt != end + 1) {
    vc.push_back(cnt);
    cnt++;
  }
  return vc;
}
/**
 * @brief calculate the sum of vector's "v" members
 *
 * @param v
 * @returnLLt
 */
template <typename T> T sum(const std::vector<T> &v) {
  if (v.empty()) {
    return 0;
  }
  if (v.size() == 1) {
    return v.at(0);
  } else {
    return head(v) + euler::sum(tail(v));
  }
  return 0;
}
LL sumTo(const LL);
LL sumSquaresTo(const LL to);
template <typename T> T prod(const std::vector<T> &v) {
  if (v.empty()) {
    return 0;
  }
  if (v.size() == 1) {
    return v.at(0);
  } else {
    return head(v) * euler::prod(tail(v));
  }
}
bool areDivided(const LL, const LL);
bool areDivided(const LL, const std::vector<LL>);
bool areAnyDivided(const LL, const std::vector<LL>);

template <typename T> bool isPrime(const T a) {
  if (a < 2) {
    return false;
  }
  if (a < 4) {
    return true;
  }
  if (a % 2 == 0) {
    return false;
  }
  if (a < 9) {
    return true;
  }
  if (a % 3 == 0) {
    return false;
  }
  T up = sqrt(a);
  T f = 5;
  while (f < up) {
    if (a % f == 0) {
      return false;
    }
    if (a % (f + 2) == 0) {
      return false;
    }
    f += 6;
  }
  return true;
}
bool isP(const LL);
std::vector<LL> primesTo(const LL);
LL primeAt(const size_t);
std::vector<LL> getFactors(const LL, bool = false);
bool isPalindromic(const int);
LL pow(const LL, const size_t);
std::vector<LL> pow(const std::vector<LL> &, const std::vector<size_t> &);

template <typename T>
std::vector<T> movingFuncs(const std::vector<T> &in, size_t step,
                           std::function<T(const std::vector<T> &)> f) {
  std::vector<T> retVal{};
  const size_t size = in.size();
  if (size <= step) {
    //   throw std::range_error("not enough members!");
    // }
    // if (size == step){
    return std::vector<T>{f(in)};
  } else {
    std::vector<T> head{}, tail{};
    std::copy(in.begin(), in.begin() + step, std::back_inserter(head));
    std::copy(in.begin() + 1, in.end(), std::back_inserter(tail));
    std::vector<T> a{f(head)}, b{movingFuncs(tail, step, f)};
    std::copy(b.begin(), b.end(), std::back_inserter(a));
    return a;
  }
}
template <typename T>
const std::vector<T> fromStringArray(const std::string &a) {
  std::vector<T> retVal{};
  for (auto i = a.begin(); i != a.end(); i++) {
    retVal.push_back(*i - '0');
  }
  return retVal;
}
std::vector<bool> getPrimeBooleanTo(size_t);
LL getSumofPrimesTo(size_t);

template <typename T>
T getHorizontalMax(std::vector<T> vc, size_t vector_size, size_t con) {
  T max{0};
  for (size_t k = 0; k < vector_size; k++)
    for (size_t a = vector_size * k; a + con <= vector_size * (k + 1); a++) {
      size_t sum{1};
      std::for_each(vc.begin() + a, vc.begin() + a + con,
                    [&sum](int a) { return sum *= a; });
      if (sum > max) {
        max = sum;
      }
    }
  std::cout << std::endl;
  return max;
}
int getUpperLeftMax(std::vector<int> &fVec, size_t con, size_t vector_size);
} // namespace euler

#endif
