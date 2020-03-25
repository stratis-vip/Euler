//
//  class17.cpp
//  project Euler
//
//  Created by Στρατής Χριστοδούλου on 23/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "class17.hpp"
#include <algorithm>
#include <cmath>

const std::map<size_t, std::string> Class17::dic = {
    {0, "zero"},      {1, "one"},         {2, "two"},          {3, "three"},
    {4, "four"},      {5, "five"},        {6, "six"},          {7, "seven"},
    {8, "eight"},     {9, "nine"},        {10, "ten"},         {11, "eleven"},
    {12, "twelve"},   {13, "thirteen"},   {14, "fourteen"},    {15, "fifteen"},
    {16, "sixteen"},  {17, "seventeen"},  {18, "eighteen"},    {19, "nineteen"},
    {20, "twenty"},   {30, "thirty"},     {40, "forty"},       {50, "fifty"},
    {60, "sixty"},    {70, "seventy"},    {80, "eighty"},      {90, "ninety"},
    {100, "hundred"}, {1000, "thousand"}, {1000000, "million"}};

std::string under21(size_t c) { return Class17::dic.at(c); }

std::string under100(size_t c) {
  std::string ret{};
  if (c < 21) {
    return under21(c);
  } else {
    std::string s = std::to_string(c);
    size_t mag = s.size();
    if (c < 100) {
      for (size_t i = 0; i != mag; i++) {
        if (s[i] != '0') {
          if (ret != "") {
            ret += "-";
          }
          const size_t idx = static_cast<size_t>(s[i] - '0') *
                             static_cast<size_t>(pow(10, mag - 1 - i));
          ret += Class17::dic.at(idx);
        }
      }
    }
  }
  return ret;
}

std::string over100(size_t c) {
  std::string s = std::to_string(c);
  size_t mag = s.size();
  std::string ret{};
  for (size_t i = 0; i != mag; i++) {
    std::string remaining{};
    std::copy(s.begin() + i, s.end(), std::back_inserter(remaining));
    size_t rem = std::stoll(remaining);
    if (rem < 100) {
      if (rem == 0) {
        return ret;
      }
      ret += " and " + under100(rem);
      return ret;
    } else {
      const size_t lidx = static_cast<size_t>(s[i] - '0');
      if (s[i] != '0') {
        if (i == 0) {
          ret += Class17::dic.at(lidx) + " ";
        }
        size_t idx = static_cast<size_t>(s[i] - '0') *
                     static_cast<size_t>(pow(10, mag - 1 - i));
        if (i == 0) {
          idx /= lidx;
        }
        ret += Class17::dic.at(idx);
      }
    }
  }

  return ret;
}

size_t getStringSize(std::string a) {
  a.erase(std::remove(a.begin(), a.end(), ' '), a.end());
  a.erase(std::remove(a.begin(), a.end(), '-'), a.end());
  return a.size();
}

Class17::Class17(const size_t val) : _aValue(val) {
  if (val < 100) {
    _sValue = under100(val);
  } else {
    _sValue = over100(val);
  }
  _size = getStringSize(_sValue);
}

std::string Class17::sValue() const { return _sValue; }

size_t Class17::aValue() const { return _aValue; }

size_t getMagnum(const size_t &a) {
  size_t retVal{};
  size_t local{a};
  while (local > 1) {
    retVal++;
    local /= 10;
  }
  return retVal;
}

size_t Class17::size() const { return _size; }
