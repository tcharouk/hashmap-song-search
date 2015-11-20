// Song Search
// Timothy Charouk
//
// hashtable.cpp
//
// Class implementation for hashtable class
// This implements the functions required for the hashing algorithm

#include "hashtable.h"
using namespace std;

// Constructor for hashtable
// Utilizes the clear() function of unordered maps
Hashtable::Hashtable() {
        hashtable.clear();
}

// Insert function inserts words into the hashtable
void Hashtable::insert(string word, size_t index) {
        // if it's a new word create that word and insert it
        if(hashtable.count(word) == 0) {
            Data newWord;
            // initialize count and set index
            newWord.currentCount = 1;
            newWord.currentIndex = index;
            //insert newWord
            hashtable[word] = newWord;
        } else { //word already exists
            // check if still in same song
            if(index == hashtable[word].currentIndex) {
                // increment count for that song
                hashtable[word].currentCount++;
            } else {
                place(word); //store variables in vector within hashtable
                // reinitialize count and set new index
                hashtable[word].currentCount = 1;
                hashtable[word].currentIndex = index;
            }
        }
}

// Place function stores the temporary variables if needed
// currentCount and currentIndex are stored if the count is big enough
void Hashtable::place(string word) {
        // check if the stored vector is less than 10
        // if so than the words variables can be stored directly
        if(hashtable[word].songs.size() < 10) {
            songwithfreq newSong;
            newSong.index = hashtable[word].currentIndex;
            newSong.frequency = hashtable[word].currentCount;
            hashtable[word].songs.push_back(newSong);
        } else { //check if the count is big enough to be considered
            // simply check against the 9th element because it is the smallest
            if(hashtable[word].currentCount >
               hashtable[word].songs[9].frequency) {
                songwithfreq newSong;
                newSong.index = hashtable[word].currentIndex;
                newSong.frequency = hashtable[word].currentCount;
                // store in 9th spot to replace smallest element
                hashtable[word].songs[9] = newSong;
            }
        }
        // once the new song is inserted sort the vector again
        descending desc;
        sort(hashtable[word].songs.begin(), hashtable[word].songs.end(), desc);
}

// find function returns the songs vector for the given word
// it also places the temporary variables still left in the hashtable
vector<songwithfreq> Hashtable::find(string word) {
        // if word not found return an empty vector
        if(hashtable.count(word) == 0) {
            vector<songwithfreq> emptyVector;
            emptyVector.clear();
            return emptyVector;
        }
        // still need to store currentCount and index for last song
        place(word);
        return hashtable[word].songs;
}