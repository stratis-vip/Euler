//
//  class18.cpp
//  problem 18
//
//  Created by Στρατής Χριστοδούλου on 23/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#include "class18.hpp"
#include <sstream>

size_t max(const size_t a, const size_t b) { return a > b ? a : b; }

vectorTable createTable(const vectorTable &a, const size_t offset) {
  vectorTable retVal{};
  for (size_t row = 0; row != a.size() - 1; row++) {
    std::vector<size_t> temp{};
    for (size_t col = 0; col != row + 1; col++) {
      temp.push_back(a.at(row + 1).at(offset + col));
    }
    retVal.push_back(temp);
  }
  //  for (auto i = a.at(1).cbegin(); i != a.at(1).cend(); i++) {

  return retVal;
}

size_t getMaxFromTriangle(const vectorTable &a, const size_t row) {
  size_t retVal{};
  size_t lastRow = a.size() - 1;
  if (a.at(lastRow).size() == 2) {
    retVal = a.at(row).at(0) + max(a.at(row + 1).at(0), a.at(row + 1).at(1));
  } else {
    vectorTable left = createTable(a, 0);
    vectorTable right = createTable(a, 1);

    retVal = a.at(0).at(0) +
             max(getMaxFromTriangle(left), getMaxFromTriangle(right));
  }
  return retVal;
}

/**
  @brief create an Class18 object
  @param a is the input in string format "number number ... number"
  @param position the position to check the [position, position+1] values
 */
Class18::Class18(const std::string &a, const size_t position) : _pos(position) {
  std::istringstream s{a};
  int b{};
  while (s >> b) {
    members.push_back(b);
  }
}

Class18::Class18(const std::string &a) {
  std::ifstream f;
  f.open(a, std::ios::in);
  if (f.is_open()) {
    std::string strFromFile{};
    while (std::getline(f, strFromFile)) {
      std::vector<size_t> row{};
      std::istringstream s{strFromFile};
      size_t a{};
      while (s >> a) {
        row.push_back(a);
      }
      table.push_back(row);
    }
  } else {
    throw std::invalid_argument(a + " is not a valid file");
  }
}

std::string Class18::toString() {
  std::ostringstream out{};
  for (auto i = members.begin(); i != members.end(); i++) {
    out << *i;
    if (i + 1 < members.end()) {
      out << " ";
    }
  }
  return out.str();
}

size_t Class18::value() {
  if (members.size() == 1) {
    return members.at(0);
  }
  size_t a, b;
  a = members.at(_pos);
  b = members.at(_pos + 1);
  return a > b ? a : b;
}

size_t Class18::position() {
  if (members.size() == 1) {
    return 0;
  }
  size_t a, b;
  a = members.at(_pos);
  b = members.at(_pos + 1);
  return a > b ? _pos : _pos + 1;
}
