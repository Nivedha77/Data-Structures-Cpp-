#include "Playlist.h"
#include <iostream>
#include <string>

using namespace std; 



char PrintMenu(string title);

char PrintMenu(string title){
    char choice;          
    
    cout << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    
    cout << "Choose an option:" << endl;
    cin >> choice;
    
    return choice;
}

int main(){
    string id;
    string name;
    string artist;
    int length; 
    
    PlaylistNode* head = 0; 
    PlaylistNode* tail = 0; 
    string title;
    char choice =' '; 
    int totalSize = 0;
    
    
    cout << "Enter playlist's title:" << endl << endl; 
    //cin.ignore();
    getline(cin, title);

    while(choice != 'q'){
       choice = PrintMenu(title);
       
       
       
    //switch(choice){ //switch cases!
    //while (choice != '')
    
        if (choice == 'a'){
            
            
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin  >> id;
            //getline(cin, id);
            cout << "Enter song's name:" << endl;
            //cin  >> name;
            cin.ignore();
            getline(cin, name);
            cout << "Enter artist's name:" << endl;
            //cin  >> artist;
            //cin.ignore();
            getline(cin, artist);
            cout  << "Enter song's length (in seconds):" << endl;
            cin  >> length;
            cout << endl;
            
            
            PlaylistNode* addNode = new PlaylistNode(id, name, artist, length); //create new node populated with new info
                
            if(head == 0) { 
                head = new PlaylistNode(id, name, artist, length);
                tail = new PlaylistNode(id, name, artist, length);
            }
            
            else {
                PlaylistNode* temp = head;
                while (temp->GetNext() != 0){
                    temp = temp->GetNext(); //running the list no matter the size until the last node
                }
                
                //PlaylistNode* newNooddee = new PlaylistNode(id, name, artist, length);
                temp->SetNext(addNode);
               // head.->SetNext(addNode); // you cant do this, bc it just tacks on the new node instead of rewriting the empty head node 
                tail = addNode;
            }
            
            totalSize ++;
        }
        //break;
        
        
        
        
        //DONE
        if (choice == 'd'){
            string id;
            //cout << "OPTION D" << endl << endl << endl;
            PlaylistNode* temp = head; //start at head to traverse list
            //bool test = true;
            
            if (head != 0){
                cout << "REMOVE SONG" << endl;
                cout << "Enter song's unique ID:" << endl;
                cin >> id;
                bool test = true;
            
            while(test== true && temp != 0) {
                if(id== temp->GetID()) {
                    //delete;
                    cout << "\""<< temp-> GetSongName() << "\""<< " removed." << endl << endl;
                    
                    if(temp==head  &&  head ==tail){//list has only one node
                        delete temp;
                        //reset head and tail to null
                        head = 0;
                        tail = 0;
                        test = false;
                    }
                    
                    else if(temp == head){ // node chosen is first node in list
                        PlaylistNode* tempp = head;
                        head = head->GetNext(); //set head to the next node
                        delete tempp; //delete head node
                        test = false;
                    }
                    
                    else if( temp == tail){ //node chosen is last node in list 
                        PlaylistNode* lastTemp = head;
                        while(lastTemp->GetNext()!=tail){ //stops one node before tail node
                            lastTemp = lastTemp->GetNext(); //sets temp to tail node
                        }
                        
                        tail = lastTemp;
                        delete temp;
                        lastTemp->SetNext(0); //set as null
                        test = false;
                    }
                    
                    else{ //somewhere in the middle 
                        PlaylistNode* newTemp = head;
                        while(newTemp->GetNext() != temp){
                            newTemp = newTemp->GetNext();
                        }
                        
                        newTemp->SetNext(temp->GetNext());
                        delete temp;
                        test = false;
                    }
                }
                
                if(test == true){
                    temp = temp->GetNext();
                }
            }
        }
        }
        //break;

        //DONE works kinda
        if (choice == 'c'){
            int oldLoc;
            int newLoc;
            
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> oldLoc;
            cout << "Enter new position for song:" << endl;
            cin >> newLoc;
            
            //COVER ALL CRAZY CASES
            if (newLoc < 1){
                newLoc = 1;
            }
            
            if(newLoc > totalSize){
                newLoc = totalSize;
            }
            
            if(newLoc != oldLoc){
                PlaylistNode* temp = head;
                PlaylistNode* newTempNode = new PlaylistNode();
                
                newTempNode->SetNext(temp);
                bool test = true;
                int counter1 = 1;
                int counter2 =1;
                PlaylistNode* oldNodePos;
                
                while(temp!=0 && test){
                    if (counter1 == oldLoc){
                        oldNodePos = temp;
                        
                        if(counter1 == 1){
                            head = head->GetNext();
                        }
                        
                        else{
                            newTempNode->SetNext(temp->GetNext());
                        }
                        
                        if(tail == temp){
                            tail = newTempNode;
                        }
                        
                        test = false;
                    }
                     
                    temp = temp->GetNext();
                    newTempNode = newTempNode->GetNext();
                    counter1++;
                        
                    }
                    
                    PlaylistNode* tempp = head;
                    bool test2 = true;
                    
                    while( test2 && tempp !=0){
                        if(newLoc == 1){
                            oldNodePos->SetNext(head);
                            head = oldNodePos;
                            test2 = false;
                            cout << "\"" << oldNodePos->GetSongName() << "\" moved to position " << newLoc<< endl<< endl;
                            
                        }
                        
                        else if(counter2 ==(newLoc - 1)){
                            tempp->InsertAfter(oldNodePos);
                            test2 = false;
                            cout << "\"" << oldNodePos->GetSongName() << "\" moved to position " << newLoc<< endl<< endl;
                        }
                        
                        tempp = tempp->GetNext();
                        counter2 ++;
                    }
                }
            }
            

        


        //Kinda done
        if(choice == 's'){
            //cout << endl << endl <<"OPTION S" << endl << endl << endl;

            string artistN = "";
            //int counter = 1;
            
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            if (head == 0){
                cout << endl << "Playlist is empty." << endl << endl;
            }
            
            else{
                cout << "Enter artist's name:" << endl;
                cin >> artistN;
                //getline(cin, artistN);
                cout << endl;
                
                PlaylistNode* temp = head;
                int nodeNum = 1;
                    while (temp !=0 ){ // while temp is not a null node
                        if (temp -> GetArtistName() == artistN){ // compare every node to find
                            cout << nodeNum << "." << endl;
                            temp->PrintPlaylistNode();
                            cout << endl;
                        } 
                        temp = temp->GetNext();
                        nodeNum+=1;
                    }
            }
            
            
        }
        //break;



        //DONE should work 
        if(choice == 't'){
            //cout << endl << endl <<"OPTION T" << endl << endl << endl;
            
            int totalLength = 0;
            PlaylistNode* temp = head;
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            while(temp != 0){
                totalLength = totalLength + temp->GetSongLength();
                temp = temp->GetNext();
            }
            
            cout << "Total time: " << totalLength << " seconds" << endl << endl; 
        }
        //break;
        
        
        
        
        //DONE WORKS FINE
        if(choice == 'o'){
           cout  << title << " - OUTPUT FULL PLAYLIST" << endl;
           int numofSongs = 1;           
           PlaylistNode* curr = head;
           
           if(head != 0){
               while (curr!=0){
                    cout << numofSongs << "." << endl;
                    curr->PrintPlaylistNode();
                    cout << endl;
                    numofSongs = numofSongs + 1;
                    curr = curr->GetNext();
                    //numofSongs++;                   
               }
           }
            else{
                cout << "Playlist is empty" << endl << endl;
                }
            }

    }
    
    
    
    return 0;
}




