// Song Search
// Timothy Charouk
//
// read_lyrics.cpp
//
// This file implements the Database class functions
// It reads in lyrics and hashes them into the unordered map hashtable
// Does actual searching and printing of report

#include "read_lyrics.h"

using namespace std;

Database::Database() {
	songList.clear();
}

//
// read_lyics 
//   purp: read in song data from a disk file
//   args: the name of the file, bool to ask for progress status
//   rets: nothing
//   does: calls a function each time a word is found
//
void Database::read_lyrics(char * filename, bool show_progress)
{
        ifstream in(filename);			// creates an input stream
        int song_count = 0;			// for progress indicator
	string artist, title, word;		// data from the file
	size_t i = 0;

	// -- While more data to read...
	while ( ! in.eof() ) 
	{
		// -- First line is the artist
		getline(in, artist);
		if (in.fail()) break;

		// -- Second line is the title
		getline(in, title);
		if (in.fail()) break;
		
		// create new song with artist and title
		// push the new song onto back of songList
		Song newSong;
		newSong.artist = artist;
		newSong.title = title;
		songList.push_back(newSong);

		if ( show_progress )
		{
			song_count++;
			if (song_count % 10000 == 0) {
				cout << "At "       << song_count << 
					" Artist: " << artist     << 
					" Title:"   << title << endl;
			}
		}
		// -- Then read all words until we hit the 
		// -- special <BREAK> token
		while ( in >> word && word != "<BREAK>" ){
			// add each word to lyrics vector
			songList[i].lyrics.push_back(word);
			// hash each word
			hashtable.insert(alpha(word), i);
		}
		i++;
		// -- Important: skip the newline left behind
		in.ignore();
	}
}

// Strips strings of any punctuation
string Database::alpha(string s){
        ostringstream ss;
        for (size_t i=0; i<s.length(); i++) {
                if (isalnum(s[i])){
                        ss << (char)(tolower(s[i]));
                }
        }
        return ss.str();
}

// Gets vector for given word and goes through the indices stored for that word
// Calls print for the song indices that word appears in
void Database::search(string word) {
	vector<songwithfreq> songsForWord = hashtable.find(alpha(word));
	// for each song that word appears in print
	for(size_t i = 0; i < songsForWord.size(); i++) {
            size_t index = songsForWord[i].index;
            print(alpha(word), index);
        }
        cout << "<END-OF-REPORT>" << endl;
}

// For every instance of the word in the given song it prints
void Database::print(string word, size_t index) {
	size_t size = songList[index].lyrics.size();
	// search through lyrics vector for given song
	for(size_t i = 0; i < size; i++) {
		if(alpha(songList[index].lyrics[i]) == word) {
			cout << "Title: " << songList[index].title << endl;
			cout << "Artist: " << songList[index].artist << endl;
			cout << "Context: ";
			// check if word has less than 5 words before it
			if (i < 5){
				for(size_t j = 0; j <= i+5; j++) {
					if(j < songList[index].lyrics.size()) {
						cout << songList[index].lyrics[j];
						cout << " ";
					}
				}
			} else {
				for(size_t j = i-5; j <= i+5; j++) {
					if(j < songList[index].lyrics.size()) {
						cout << songList[index].lyrics[j];
						cout << " ";
					}
				}
			}
			cout << endl << endl;
		}
	}
}
