#include <iostream>
#include "Node.h"

using namespace std;


Node :: Node(){
    root = 0;
    left = 0;
    right = 0;
    parent = 0;
    str = "";
    counter = 1;
}

Node :: Node(string str){
    root = 0;
    left = 0;
    right = 0;
    parent = 0;
    this->str = str;
    counter = 1;
}


Node :: ~Node(){
    delete left;
    delete right; 
    counter = 0;
    //cout << "This is hitting";
    return; 
}

Node& Node :: operator=(const Node &rhs){
    if (this!= &rhs){
        this->counter = rhs.counter;
        this->str = rhs.str;
    }
    return *this;
}

