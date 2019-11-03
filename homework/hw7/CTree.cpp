#include "CTree.h"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

CTree::CTree(char ch): data(ch), kids(NULL), sibs(NULL), prev(NULL) {}

CTree::~CTree(){
  clear();
}

void CTree::clear(){
  if (sibs != NULL){
    sibs->clear();
    delete sibs;
  }
  if (kids != NULL){
    kids->clear();
    delete kids;
  }
}

bool CTree::addChild(char ch){
  return addChild(new CTree(ch));
}

bool CTree::addChild(CTree *root){
  if (root->prev != NULL){
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
    if (cur->data == ch){
      return false;
    }
    cur = cur->sibs;
  }
  cur = this;
  if (ch < cur->data){
    CTree *temp = this->prev;
    novel->sibs = cur;
    cur->prev = novel;
    temp->kids = novel;
    novel->prev = temp;
    return true;
  }
  while (cur != NULL){
    
    if (cur->sibs != NULL){
      if (ch > cur->data && ch < cur->sibs->data){
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
  if (kids != NULL){
    output += "\n";
    output += kids->toString();
  }
  if (sibs != NULL){
    output += "\n";
    output += sibs->toString();
  }
  if (prev == NULL){
  output += "\n";
  }
  return output;
}
