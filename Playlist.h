#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream> 
#include <string>

using namespace std; 


class PlaylistNode{
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
        
    
    public:
        PlaylistNode();
        PlaylistNode(string a, string b, string c, int d);    
        void InsertAfter(PlaylistNode* insert);
        void SetNext(PlaylistNode *next);
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
    

};

#endif