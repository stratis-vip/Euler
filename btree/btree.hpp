//
//  btree.hpp
//  btree
//
//  Created by Στρατής Χριστοδούλου on 24/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//

#ifndef btree_hpp
#define btree_hpp

template <typename T>
struct Node {
  Node * left;
  Node * right;
  T data;
};

class BST{
private:
  Node<int> root{};
};

#endif /* btree_hpp */
