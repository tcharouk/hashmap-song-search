// Song Search
// Timothy Charouk
//
// read_lyrics.h
// Class definition for a lyrics database
// Also defines a Song struct

#ifndef __read_lyrics__
#define __read_lyrics__

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "hashtable.h"

using namespace std;

struct Song {
        string artist; //artist name
        string title; //song name
        vector<string> lyrics; //vector for each word in lyrics
};

class Database {
public:
        Database();
        void read_lyrics(char * filename, bool show_progress );
        void search(string word);
        void print(string word, size_t index);
        string alpha(string s);
private:
        vector<Song> songList; //vector for storing song structs
        Hashtable hashtable; //uses hashtable defined in other class
};

#endif
