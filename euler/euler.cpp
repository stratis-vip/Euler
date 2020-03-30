#include "euler.hpp"
#include <algorithm>
#include <cstring>

bool euler::areDivided(const LL number, const LL divider) {
  if (divider == 0) {
    throw std::invalid_argument("Division by 0");
  }
  return number % divider == 0;
}

bool euler::areDivided(const LL number, const std::vector<LL> dividers) {
  bool retVal = true;
  if (dividers.empty()) {
    return false;
  }
  for (std::vector<LL>::const_iterator i = dividers.begin();
       i != dividers.end(); i++) {
    if (euler::areDivided(number, *i) == false) {
      return false;
    }
  }
  return retVal;
}

bool euler::areAnyDivided(const LL number, const std::vector<LL> dividers) {
  bool retVal = false;
  if (dividers.empty()) {
    return false;
  }
  for (std::vector<LL>::const_iterator i = dividers.begin();
       i != dividers.end(); i++) {
    retVal = retVal || euler::areDivided(number, *i);
  }
  return retVal;
}

std::vector<LL> euler::getFactors(const LL a, bool sorted) {
  std::vector<LL> retVal{};
  if (a == 0) {
    return retVal;
  }
  retVal.push_back(1);
  if (a < 0) {
    retVal.push_back(-1);
  }
  if (a == 1 || a == -1) {
    return retVal;
  } else {
    retVal.push_back(a);
    if (a < 0) {
      retVal.push_back(abs(a));
    }
  }
  const LL upper = sqrt(abs(a));
  const LL positiveA = abs(a);
  for (LL b = 2; b < upper; b++) {
    if (positiveA % b == 0) {
      retVal.push_back(b);
      retVal.push_back(positiveA / b);
      if (a < 0) {
        retVal.push_back(-b);
        retVal.push_back((-positiveA) / b);
      }
    }
  }

  if (sorted) {
    std::sort(retVal.begin(), retVal.end());
  }

  return retVal;
}

bool euler::isPalindromic(const int a) {
  std::string sa = std::to_string(a);
  // std::cout << "sa " << sa << std::endl;
  int count = 0;
  size_t up = sa.size() - 1;
  while (count < up) {
    //  std::cout << "sa.at("<<count<<") " << sa.at(count)
    //             << " sa.at(" << up << ") " << sa.at(up)
    //             << std::endl;
    if (sa.at(count) != sa.at(up)) {
      return false;
    }
    ++count;
    --up;
  }

  return true;
}

LL euler::primeAt(const size_t index) {
  if (index < 1)
    return 0;
  LL point = 7920;
  std::vector<LL> primes = euler::primesTo(point);
  size_t idx = primes.size();

  if (index <= idx) {
    return primes.at(index - 1);
  } else {
    while (idx != index) {
      bool isPrime = true;
      if (point % 2 == 0) {
        isPrime = false;
      } else {
        LL upLimit = sqrt(point);

        for (size_t i = 3; i <= upLimit; i++) {
          if (point % i == 0) {
            isPrime = false;
            break;
          }
        }
        if (isPrime) {
          primes.push_back(point);
          idx++;
        }
      }
      point++;
    }
    return primes.at(index - 1);
  }
}

std::vector<LL> euler::primesTo(const LL a) {
  if (a <= 4) {
    return std::vector<LL>{2};
  }
  std::vector<LL> v = euler::fillFrom<LL>(2, a);
  // eliminate multiplies
  size_t cnt = 0;
  do {
    const size_t val = *(v.begin() + cnt);
    v.erase(std::remove_if(v.begin() + cnt + 1, v.end(),
                           [&val](int a) { return a % val == 0; }),
            v.end());
    cnt++;
  } while (v.begin() + cnt != v.end());
  return v;
}

LL euler::pow(const LL base, const size_t toPower) {
  if (base == 0) {
    return 0;
  }
  if (toPower == 0) {
    return 1;
  }
  size_t cnt = toPower;
  LL retVal{base};
  while (cnt > 1) {
    retVal *= base;
    cnt--;
  }
  return retVal;
};

std::vector<LL> euler::pow(const std::vector<LL> &base,
                           const std::vector<size_t> &power) {
  if (base.size() != power.size())
    throw std::invalid_argument("Vectors must have same size!");
  std::vector<LL> retVal{};
  for (size_t i = 0; i != base.size(); i++) {
    retVal.push_back(euler::pow(base[i], power[i]));
  }
  return retVal;
}

LL euler::sumTo(const LL to) { return to * (to + 1) / 2; }

LL euler::sumSquaresTo(const LL to) {
  LL retVal{};
  for (LL i = 1; i <= to; i++) {
    retVal += i * i;
  }
  return retVal;
}

bool euler::isP(const LL a) {
  if (a == 2) {
    return true;
  }
  if (a < 2 || a % 2 == 0) {
    return false;
  }
  return false;
}

LL euler::getSumofPrimesTo(size_t MAX) {
  std::vector<bool> prime = euler::getPrimeBooleanTo(MAX);

  LL retVal{};
  for (LL p = 2; p != MAX; p++) {
    if (prime.at(p)) {
      retVal += p;
    }
  }
  return retVal;
}

std::vector<bool> euler::getPrimeBooleanTo(size_t MAX) {
  std::vector<bool> prime(MAX + 1, true);
  prime.at(0) = prime.at(1) = false;

  for (LL p = 2; p * p <= MAX; p++) {
    if (prime.at(p) == true) {
      for (LL i = p * 2; i < MAX; i += p) {
        prime.at(i) = false;
      }
    }
  }
  return prime;
}

int euler::getUpperLeftMax(std::vector<int> &fVec, size_t con,
                           size_t vector_size) {
  int localMax{};
  std::vector<size_t> left{};
  size_t untilTo = vector_size - con + 1;
  for (size_t a = 0; a != untilTo; a++) {
    left.push_back(a);
    int count{1};
    while (count != untilTo) {
      left.push_back(a + count * vector_size);
      count++;
    }
  }
  std::cout << "\nprint Left -> \n";
  printVector(left);
  std::for_each(left.begin(), left.end(), [&](int a) {
    int sum{1}, count = 0;
    while (count != con) {
      sum *= fVec[a + count * (vector_size + 1)];
      count++;
    }
    if (sum > localMax) {
      localMax = sum;
    }
  });
  return localMax;
}
