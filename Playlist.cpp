#include "Playlist.h"
#include <iostream> 
#include <string> 
using namespace std; 


PlaylistNode :: PlaylistNode(){
    uniqueID = "none";
    songName = "none";
    artistName = "none";
    songLength = 0;
    nextNodePtr = 0;
}

PlaylistNode :: PlaylistNode(string a, string b, string c, int d){
    uniqueID = a;
    songName = b;
    artistName = c;
    songLength = d;
}


void PlaylistNode :: InsertAfter(PlaylistNode* insert){
    PlaylistNode* temp =this->nextNodePtr; //create a temp ptr set equal to whatever nextNodePts points to
    this->nextNodePtr = insert;//NNP is now set to point to whatver insert is 
    insert->nextNodePtr = temp; //insert's next is set to temp.
}


void PlaylistNode :: SetNext(PlaylistNode* next){
    PlaylistNode* temp = 0; //create a temp ptr
    if(this->nextNodePtr != 0) { //the next node is not 0
        temp = this->nextNodePtr; //then set temp as the nextNodePts
    }
    this->nextNodePtr = next; // set nextnodePrt to next to continue list 
    if(temp != 0) { 
        next->nextNodePtr = temp;
    }    
}


string PlaylistNode :: GetID(){
    return uniqueID;
}

string PlaylistNode :: GetSongName(){
    return songName;
}

string PlaylistNode :: GetArtistName(){
    return artistName;
}

int PlaylistNode :: GetSongLength(){ //in seconds 
    return songLength;
}

PlaylistNode* PlaylistNode :: GetNext(){
    if (this->nextNodePtr == 0){
        return 0; 
    }
    
    else{
        this->nextNodePtr;
    }
    
}

void PlaylistNode :: PrintPlaylistNode(){ //Printing only one node!!!!
    cout << "Unique ID: " << this->uniqueID << endl;
    cout << "Song Name: " << this->songName << endl;
    cout << "Artist Name: " << this->artistName << endl;
    cout << "Song Length (in seconds): " << this->songLength << endl;
} 
