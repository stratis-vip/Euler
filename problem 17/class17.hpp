//
//  class17.hpp
//  project Euler
//
//  Created by Στρατής Χριστοδούλου on 23/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#ifndef class17_hpp
#define class17_hpp

#include <map>
#include <string>

class Class17 {

private:
  size_t _aValue{};
  std::string _sValue{};
  size_t _size{};

public:
  static const std::map<size_t, std::string> dic;
  //    friend std::string getSVal(size_t, const Class17 &);
  Class17(const size_t);
  size_t aValue() const;
  std::string sValue() const;
  size_t size() const;
};

#endif /* class17_hpp */
