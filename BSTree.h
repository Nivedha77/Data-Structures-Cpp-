#ifndef __BSTREE_H__
#define __BSTREE_H__

#include "Node.h"

using namespace std;

class BSTree {

private:
  Node *root;


public:
  BSTree();
  void insert(const string &);  //
  bool search(const string &) const; //
  void inOrder( ) const; //
  void postOrder( ) const; //
  void preOrder( ) const; //
  const string & largest( ) const; //
  const string & smallest( ) const; //
  int height(const string &) const; //
  void remove(const string &); //
  void inOrder(Node* ) const;
  //~BSTree();
  const string& smallest(Node*) const;
  const string& largest(Node*) const;
  void preOrder(Node *) const;  //const???
  void postOrder(Node * n) const; //
  
private:
  //void inOrder(Node * n) const; //
  Node* findLeaf(Node* , const string & );  //
  bool searchHelper(Node* , const string & ) const; //
  int heightHelper(Node*, const string & , int ) const;
  Node* searchHelper(Node*, const string &, Node* /*&*/)const;
  Node* search(const string & inputString, Node* /*&*/ )const;
  
  void removeHelper(Node * , Node* ,const string & );//
  int findCount(Node* , const string & ) const;
  string findSuccessor(Node* n)const;
  string findPredecessor(Node* n)const;
  string minValue()const;
  bool isLeaf(Node* cur)const;
  Node*  findPPredecessor(Node* n)const;
  Node* findSSuccessor(Node* n)const;


};

#endif