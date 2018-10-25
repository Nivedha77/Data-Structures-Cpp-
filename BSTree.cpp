#include <fstream>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>
#include "BSTree.h"
#include "Node.h"
#include<stdio.h>
#include<stdlib.h>

using namespace std;


BSTree :: BSTree (){
    root = 0;
}

// BSTree :: ~BSTree(){
//     Node* thisNode = root;
//     string temp = "";
//     while( root!=0){
//         temp = thisNode->str;
//         remove(temp);
//     }
// }



// Insert an item into the binary search tree. Be sure to keep 
// the binary search tree properties. When an item is first inserted 
// into the tree the count should be set to 1. When adding a duplicate 
// string (case sensitive), rather than adding another node, the count 
// variable should just be incremented.
void BSTree::insert(const string & inputString){
    //Create 
    Node * temp = new Node(inputString);
    
    //Empty case
    if(root == 0){
        root = temp;
        return;
    }
    
    else{
        Node* cur = root;
        while(cur != 0){
            if (inputString < cur->str){
                if(cur->left == 0){
                    cur->left = temp;
                    return;
                }
                else {
                    cur = cur->left;
                }
            }
            
            else if(inputString > cur->str){
                if(cur->right == 0){
                    cur->right = temp;
                
                return;
                }
                else{
                    cur = cur->right;
                }
            }
            
            else if(inputString == cur->str){
                cur->counter++;
                return;
            }
        }
    }
}


//recursive function to find the node then find the count of the node with the specified string
int BSTree :: findCount(Node* cur, const string & inputString) const{
    if (cur != 0){ 
        if (cur->str == inputString){
            return cur->counter;
        }
        else if( cur->str > inputString){
            return(findCount(cur->left, inputString));
        }
        else{
            return findCount(cur->right, inputString);
        }
    }
    return 0;
}


Node* BSTree::findLeaf(Node* n, const string & inputString){
    //Base cases: 
    //String is the same as current node
    if(n->str == inputString){
        return n;
    }
    //Current node is > input string and left subtree is 0
    else if(n->str > inputString && n->left == 0){
        return n;
    }
    //Current node is < input string and right subtree is 0 
    else if(n->str < inputString && n->right == 0){
        return n;
    }
    
    //Recursive cases:
    //If current node is > inputString, go to the left subtree
    if(n->str > inputString){
        return findLeaf(n->left, inputString);
    }
    else{
        return findLeaf(n->right, inputString);
    }
    
}



//Search for a string in the binary search tree. It 
//should return true if the string is in the tree, 
//and false otherwise.
bool BSTree :: search(const string &inputString) const{
    Node* cur = root;
    if(cur !=0){
        if(cur->str == inputString){
            return true;
        }
        else if( cur->str > inputString){
            return searchHelper(cur->left, inputString);
        }
        else{
            return searchHelper(cur->right, inputString);
        }
    }
    return false;
    //return searchHelper(root, look);
} //good

bool BSTree :: searchHelper(Node* cur, const string & inputString) const{ //recursive 
    
    //base case 1
    
    if (cur!=0){ //not an empty tree
    
        if (cur->str == inputString){
            return true;
        }
    
    //base case 2
        else if( cur->str > inputString){ 
            return searchHelper(cur->left, inputString);
        }
        
        else{
            return searchHelper(cur->right, inputString);
        }
    }
    
    return false;
}//good



/* Search for a string in the binary search tree. 
It should return true if the string is in the tree, and false otherwise.
*/
Node* BSTree::search(const string & inputString, Node*  /*&*/ parent)const{
        //cout << "Enter string to search for: ";
        return searchHelper(root, inputString, parent);   
}

Node* BSTree::searchHelper(Node* n, const string & inputString, Node* /*&*/ parent)const{
    //base case 1
    if(n->str == inputString){
        return n;
    }
    //Current node is > input string and left subtree is 0
    else if(n->str > inputString && n->left == 0){
        cout << "Not Found" << endl << endl;
        //return 0;
    }
    //Current node is < input string and right subtree is 0 
    else if(n->str < inputString && n->right == 0){
        cout << "Not Found" << endl << endl;        
        //return 0;
    }
    
    //Recursive cases:
    //parent = n;
    //cout << "searchHelper: " << n->str << endl;
    
    if(n->str > inputString){
        return searchHelper(n->left, inputString, n);
    }
    else{
        return searchHelper(n->right, inputString, n);
    }
    
}




void BSTree :: inOrder() const{
    inOrder(root);
} //good

void BSTree :: inOrder(Node* n) const{
    // empty tree case;
    if (n == 0){
        return;
    }
    
    inOrder(n->left); //left of tree
    cout << n->str << "(" << n->counter << "), ";  //print
    inOrder(n->right); //right of tree
    //cout << endl;
} //good




void BSTree :: postOrder() const{
    postOrder(root);
} //good

void BSTree :: postOrder(Node* n) const{
    //empty tree case 
    if (n==0){
        return;
    }
    postOrder(n->left); //left of tree
    postOrder(n->right); //right of tree
    cout << n->str << "(" << n->counter << "), "; //print
    //cout << endl;
} //good




void BSTree :: preOrder() const{
    preOrder(root);
} //good

void BSTree :: preOrder(Node* n) const{
    //empty tree case 
    if (n==0){
        return;
    }
    
    cout << n->str << "(" << n->counter << "), "; //print    
    preOrder(n->left); //left of tree
    preOrder(n->right); //right of tree
   // cout << endl;
} //good




const string& BSTree :: largest() const{
    static const string empty = "";
    Node* temp = root;
    
    //empty tree case 
    if(root == 0){
        return empty;
    }
    
    while(temp->right != 0){
        temp = temp->right;
    }
    return temp->str;

} //good

const string& BSTree :: smallest() const{
    static const string empty = "";
    Node* temp = root;
    
    //empty tree case 
    if (root == 0){
        return empty;
    }
    
    
    while(temp->left != 0){
        temp = temp->left;
    }
    return temp->str;
} //good 




const string& BSTree :: smallest(Node* n)const{
    if(n->left == 0){
        return n->str;
    }
    smallest (n->left);
    return n->str;;
} //good

const string& BSTree :: largest(Node* n)const{
    if(n->right == 0){
        return n->str;
    }
    largest(n->right);
    return n->str;;
} //good



//Compute and return the height of a particular string in the
//tree. The height of a leaf node is 0 (count the str of 
//edges on the longest path). Return -1 if the string does not exist.
//int BSTree :: height(const string & inputString) const{
// int BSTree::height(const string& str) const {
//     	Node* tp = search(str, root);
    
//     	if (!tp){
//     		return -1;
//     	}
    
//     	if (!tp->left && !tp->right){
//     		return 0;
//     	}
//     	return heightHelper(tp);
// }

int BSTree::height(const string & inputString) const{
    
    if (root == 0){ //empty tree
        return -1;
    }
    
    //find starting node
    Node* cur = search(inputString, root);
    int cnt = 0;
    
    //if exists 
    if (cur == 0){
        return -1;
    }
    
    else{
         return heightHelper(cur, inputString, cnt);
    }
    
    
    //return -1;
}

int BSTree::heightHelper(Node* cur, const string & inputString, int c) const{
    //Base cases: 
    //String is the same as current node
    //string x = inputString;
    
    if (cur == 0){ //root
        return c;
    }
    
    if(cur->right == 0 && cur->left == 0){ //no children
        return c;
    }
    
    c = c + 1;
    int c1 = c;
    int c2 = c;
    
    //Recursive cases:
    //If current node is > inputString, go to the left subtree
    c1 = heightHelper(cur->right, inputString, c1);
    c2 = heightHelper(cur->left, inputString, c2);
    
    //Current node is > input string and left subtree is 0
    if(c1>c2){
        return c1;
    }
    
    //Current node is < input string and right subtree is 0
    else if (c1 < c2){
        return c2;
    }
    return c1;
}


// int BSTree :: heightHelper(Node* n) const{
    
//     ////base case 1
// 	if (n == 0){ //empty tree
// 		return -1;
// 	}

// 	int l = Hheight(n->left);
// 	int r = Hheight(n->right);

// 	if (l > r){
// 		return 1 + l;
// 	}
// 	else{
// 		return 1 + r;
// 	}

// }

string BSTree :: findPredecessor(Node* n)const{
    Node* temp = n;
    //temp = temp->left;
    if(temp == 0){
        return temp->str;
    }
    
    return findPredecessor(temp->right);
}

string BSTree :: findSuccessor(Node* n)const{
    Node* temp = n;
    //temp = temp->left;
    if(temp == 0){
        return temp->str;
    }
    
    return findSuccessor(temp->left);
}


Node* BSTree :: findPPredecessor(Node* n)const{
    Node* temp = n;
    //temp = temp->left;
    if(temp == 0){
        return temp;
    }
    if(temp < n && temp > findSSuccessor(n)){
        return temp;
    }
    
    return findPPredecessor(temp->right);
}

Node* BSTree :: findSSuccessor(Node* n)const{
    Node* temp = n;
    //temp = temp->left;
    if(temp == 0){
        return temp;
    }
    if(temp > n && temp < findPPredecessor(n)){
        return temp;
    }
    
    return findSSuccessor(temp->left);
}





    




