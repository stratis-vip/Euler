//
//  class18.hpp
//  problem 18
//
//  Created by Στρατής Χριστοδούλου on 23/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#ifndef class18_hpp
#define class18_hpp

#include <fstream>
#include <string>
#include <vector>

using vectorTable = std::vector<std::vector<size_t>>;
size_t getMaxFromTriangle(const vectorTable &, const size_t = 0);

class Class18 {
public:
  Class18(const std::string &, const size_t);
  Class18(const std::string &);
  std::string toString();
  size_t value();
  size_t position();
  vectorTable getTable() const { return table; };
  size_t solve() { return getMaxFromTriangle(table); }

private:
  vectorTable table{};
  std::vector<size_t> members{};
  size_t _pos{};
  size_t _valuePos{};
};

#endif /* class18_hpp */
