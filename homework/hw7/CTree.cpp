#include "CTree.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;

CTree::CTree(char ch): data(ch), kids(NULL), sibs(NULL), prev(NULL) {}

ostream& operator<<(ostream& os, CTree& rt){
  os << rt.toString();
  return os;
}

bool CTree::operator==(const CTree &root){
  if (data != root.data){
    return false;
  }
  if (root.sibs != sibs && root.kids != kids){
    return false;
  }
  return true;
}

CTree& CTree::operator^(CTree& rt){
  addChild(&rt);
  return *this;
}

CTree::~CTree(){
  if (kids != NULL){
    delete kids;
  }
  if (sibs != NULL){
    delete sibs;
  }
}

bool CTree::addChild(char ch){
  return addChild(new CTree(ch));
}

bool CTree::addChild(CTree *root){
  if (root->prev != NULL || root->sibs != NULL){
    return false;
  }else{
    if (kids != NULL){
      return kids->addSibling(root);
    }else{
      root->prev = this;
      kids = root;
      return true;
    }
  }
}

bool CTree::addSibling(CTree *novel){
  if (prev == NULL){
    return false;
  }
  CTree *cur = this;
  while (cur != NULL){
    if (cur->data == novel->data){
      return false;
    }
    cur = cur->sibs;
  }
  cur = this;
  if (novel->data < cur->data){
    CTree *temp = this->prev;
    novel->sibs = cur;
    cur->prev = novel;
    temp->kids = novel;
    novel->prev = temp;
    return true;
  }
  while (cur != NULL){
    
    if (cur->sibs != NULL){
      if (novel->data > cur->data && novel->data < cur->sibs->data){
      CTree *temp = cur->sibs;
      cur->sibs = novel;
      novel->prev = cur;
      novel->sibs = temp;
      temp->prev = novel;
      return true;
      }
    }else{
      cur->sibs = novel;
      novel->prev = cur;
      return true;
    }
    cur = cur->sibs;
  }
  return true;
}

bool CTree::addSibling(char ch){
  return addSibling(new CTree(ch));
}

string CTree::toString(){
  string output = "";
  output.push_back(data);
  output += "\n";
  if (kids != NULL){
    //output += "\n";
    output += kids->toString();
  }
  if (sibs != NULL){
    //output += "\n";
    output += sibs->toString();
  }
  /*if (prev == NULL){
  output += "\n";
  }*/
  return output;
}
