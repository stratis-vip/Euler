//
//  main.cpp
//  problem21
//
//  Created by Στρατής Χριστοδούλου on 29/3/20.
//  Copyright © 2020 Στρατής Χριστοδούλου. All rights reserved.
//


#include <iostream>
#include <memory>

struct node{
  int val;
  std::shared_ptr<node> next{NULL};
  node(const int value):val(value){}
};

//void clearMemory(node * n){
//  if (n->left != NULL){
//    clearMemory(n->left);
//  }
//  if (n->right != NULL){
//    clearMemory(n->right);
//  }
//  delete n;
//}


int main(int argc, const char * argv[]) {
  // insert code here...
  std::shared_ptr<node> a =  std::make_shared<node>(34);
  a->next = std::make_shared<node>(55);
 
  std::cout << a->val << std::endl;
//  clearMemory(a);
//  delete a;
  return 0;
}
