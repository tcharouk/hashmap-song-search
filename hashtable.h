// Song Search
// Timothy Charouk
//
// hashtable.h
//
// hashtable class definition
// This header file declares the needed structs and hashtable class
// Uses an unordered map as central data structure

#ifndef __hashtable__
#define __hashtable__

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
#include <iostream>
using namespace std;

// songwithfreq struct stores the index of the song the word appears in
// and the frequency of that word in the given song
struct songwithfreq {
    size_t index;
    int frequency;
};

// Data stores a vector of songwithfreq's and temporary variables
// currentCount is the accumulated count for a given word for the current song
// currentIndex is the index of the song currently being searched
struct Data {
    vector<songwithfreq> songs;
    int currentCount;
    size_t currentIndex;
};

// sorting algorithm to sort the songwithfreq vector in descending order
// sorts in terms of frequency
struct descending{
    bool operator()(songwithfreq lhs, songwithfreq rhs){
        return lhs.frequency > rhs.frequency;
    }
};

// Hashtable class with necessary functions
class Hashtable {
public:
    Hashtable();
    void insert(string word, size_t index);
    void place(string word);
    vector<songwithfreq> find(string word);
private:
    unordered_map<string, Data> hashtable; //hashtable is an unordered_map
};

#endif