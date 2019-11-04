#include "CTree.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

//constructor with character value
CTree::CTree(char ch): data(ch), kids(NULL), sibs(NULL), prev(NULL) {}

//outputs tree to a stream
ostream& operator<<(ostream& os, CTree& rt){
  os << rt.toString();
  return os;
}

//tests if two trees are equal
bool CTree::operator==(const CTree &root){
  //tests if value of nodes are equal
  if (data != root.data){
    return false;
  }
  //checks if kids and siblings are equal for both nodes
  if (root.sibs != sibs && root.kids != kids){
    return false;
  }
  return true;
}

//adds child and outputs resulting tree
CTree& CTree::operator^(CTree& rt){
  addChild(&rt);
  return *this;
}

//destructor for a tree
CTree::~CTree(){
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
bool CTree::addChild(char ch){
  //adds child by creating a new tree
  return addChild(new CTree(ch));
}

//adds a new root to an existing tree
bool CTree::addChild(CTree *root){
  //checks if tree to be added is a root
  if (root->prev != NULL || root->sibs != NULL){
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
bool CTree::addSibling(CTree *novel){
  //checks if tree is a true root
  if (prev == NULL){
    return false;
  }
  //iterates through data to ensure value is not already in tree
  CTree *cur = this;
  while (cur != NULL){
    if (cur->data == novel->data){
      return false;
    }
    cur = cur->sibs;
  }
  //iterates through siblings again
  cur = this;
  //checks if new tree should be added as first sibling
  if (novel->data < cur->data){
    CTree *temp = this->prev;
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
      if (novel->data > cur->data && novel->data < cur->sibs->data){
      CTree *temp = cur->sibs;
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
bool CTree::addSibling(char ch){
  return addSibling(new CTree(ch));
}

//outputs all values of a tree
string CTree::toString(){
  string output = "";
  output.push_back(data);
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
