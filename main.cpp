#include <iostream>
#include "BSTree.h"

using namespace std;

void printOrders(BSTree *tree) {
  cout << "Preorder = ";
  tree->preOrder( );
  cout << endl;
  cout << "Inorder = ";
  tree->inOrder( );
  cout << endl; 
  cout << "Postorder = ";
  tree->postOrder( );
  cout << endl;
}

int menu() {
  BSTree tree;
  int choice = 0;
  cout << endl << "Enter menu choice: ";
  cout << endl;
  cout 
    << "1. Insert" << endl
    //<< "2. Remove" << endl
    << "2. Print" << endl
    << "3. Search" << endl
    << "4. Smallest" << endl
    << "5. Largest" << endl
    << "6. Height" << endl
    << "7. Quit" << endl;
  cin >> choice;
  
  // fix buffer just in case non-numeric choice entered
  // also gets rid of newline character
  cin.clear();
  cin.ignore(256, '\n');
  return choice;
}

int main( ) {
  
  //string x = "";

  BSTree tree;

  int choice = menu();

  string entry;
  
  while (choice != 7) {
    
    if (choice == 1) {
      cout << "Enter string to insert: ";
      getline(cin, entry);
      //cin >> x;
      cout << endl;
      
      tree.insert(entry);
      
    } 
    else if (choice == 2) {
      printOrders(&tree);
      
    } 
    else if (choice == 3) {
      cout << "Enter string to search for: ";
      getline(cin, entry);
      cout << endl;
      
      if (tree.search(entry)) {
        cout << "Found" << endl;
      } else {
        cout << "Not Found" << endl;
      }

    } else if (choice == 4) {
      cout << "Smallest: " << tree.smallest() << endl;
      
    } else if (choice == 5) {
      cout << "Largest: " << tree.largest() << endl;
      
    } else if (choice == 6) {
      cout << "Enter string: ";
      getline(cin, entry);
      cout << endl;
      cout << "Height of subtree rooted at " << entry << ": " 
        << tree.height(entry) << endl;
        
    }
    //fix buffer just in case non-numeric choice entered
    choice = menu();
  }
  
  return 0;
}
