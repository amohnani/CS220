#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstdlib>
#include <string>

template <typename T>
class Tree{
  friend class TTreeTest;
 private:
  T data;
  Tree *kids;
  Tree *sibs;
  Tree *prev;
  bool addSibling(T ch);
  bool addSibling(Tree *root);
  
 public:
  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, Tree<U>& root); 

  Tree(T ch);

  ~Tree();

  Tree& operator^(Tree& rt);

  bool operator==(Tree& root);

  bool addChild(T ch);

  bool addChild(Tree *root);

  std::string toString();
};



#endif
