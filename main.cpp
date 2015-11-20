// Song Search
// Timothy Charouk
//
// main.cpp
//
// This file runs the actual song search process
// it takes in a file and reads in the lyrics and hashes them
// it then takes in word from the user to be searched and searches for it


#include "read_lyrics.h"
using namespace std;

int main(int argc, char *argv[]) {
        Database database;
        if(argc == 2) {
            database.read_lyrics(argv[1], true);
            string word;
            while(word != "<BREAK>") { //read word until user types: <BREAK>
                cin >> word;
                if(word == "<BREAK>") {
                    break;
                }
            database.search(word);
            }
        } else {
            cout << "Usage: songsearch database.txt\n";
        }
        return 0;
}
