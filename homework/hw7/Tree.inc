#include "CTree.h"
#include <string>
#include <iostream>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::stringstream;

//constructor with character value
template <typename T>
Tree<T>::Tree(T ch): data(ch), kids(NULL), sibs(NULL), prev(NULL) {}

//outputs tree to a stream
template <typename U>
ostream& operator<<(ostream& os, Tree<U>& rt){
  os << rt.toString();
  return os;
}

//tests if two trees are equal
template <typename T>
bool Tree<T>::operator==(Tree<T> &root){
  
  if (toString() == root.toString()){
     return true;
  }
  return false;
}

//adds child and outputs resulting tree
template <typename T>
Tree<T>& Tree<T>::operator^(Tree<T>& rt){
  addChild(&rt);
  return *this;
}

//destructor for a tree
template <typename T>
Tree<T>::~Tree(){
  //recursively deletes kids
  if (kids != NULL){
    delete kids;
  }
  //recursively deletes siblings
  if (sibs != NULL){
    delete sibs;
  }
}

//adds child using character value
template <typename T>
bool Tree<T>::addChild(T ch){
  //adds child by creating a new tree
  return addChild(new Tree(ch));
}


//adds a new root to an existing tree
template <typename T>
bool Tree<T>::addChild(Tree<T> *root){
  //checks if tree to be added is a root
  if (root->prev != NULL || root->sibs != NULL){
     delete root;
    return false;
  }else{
    //checks if kids exist
    if (kids != NULL){
      return kids->addSibling(root);
    }else{
      //if not, sets new node to be the first kid
      root->prev = this;
      kids = root;
      return true;
    }
  }
}

//adds sibling to existing tree
template <typename T>
bool Tree<T>::addSibling(Tree<T> *novel){
  //checks if tree is a true root
  if (prev == NULL){
     delete novel;
    return false;
  }
  //iterates through data to ensure value is not already in tree
  Tree<T> *cur = this;
  while (cur != NULL){
    if (cur->data == novel->data){
       delete novel;
      return false;
    }
    cur = cur->sibs;
  }
  //iterates through siblings again
  cur = this;
  //checks if new tree should be added as first sibling
  if (novel->data < cur->data){
    Tree<T> *temp = this->prev;
    novel->sibs = cur;
    cur->prev = novel;
    temp->kids = novel;
    novel->prev = temp;
    return true;
  }
  //iterates through siblings
  while (cur != NULL){
    
    if (cur->sibs != NULL){
      //checks if this is the right spot to insert the new node
      if (cur->data < novel->data && novel->data < cur->sibs->data){
      Tree<T> *temp = cur->sibs;
      cur->sibs = novel;
      novel->prev = cur;
      novel->sibs = temp;
      temp->prev = novel;
      return true;
      }
      //adds node to the end
    }else{
      cur->sibs = novel;
      novel->prev = cur;
      return true;
    }
    cur = cur->sibs;
  }
  return true;
}

//adds new sibling by creating a new tree
template <typename T>
bool Tree<T>::addSibling(T ch){
  return addSibling(new Tree(ch));
}

//outputs all values of a tree
template <typename T>
string Tree<T>::toString(){
  string output = "";
  stringstream ss;
  ss << data;
  output += ss.str();
  output += "\n";
  //recursively outputs kids trees
  if (kids != NULL){
    output += kids->toString();
  }
  //recursively outputs siblings trees
  if (sibs != NULL){
    output += sibs->toString();
  }
  return output;
}
