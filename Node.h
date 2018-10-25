#ifndef NODE_H
#define NODE_H
#include <iostream>

using namespace std;

class Node {
    
    public: 
        Node *root;
        Node *left;
        Node *right;
        Node *parent;
        string str;
        int counter;
    
    public: 
        Node();
        Node(string );
        ~Node();
        Node &operator=(const Node &rhs);
        Node* removeHelper(const string&, Node*);
        
};


#endif