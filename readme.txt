README
"What's the name of that song again?" by Timothy Charouk

Purpose-----------------------------------------------------------------------
This program will read in lyrics from a lyrics database and search for a word
in that database. The user must load in the database and store the lyrics,
then they can enter a word and the program will find the top ten songs, in
terms of frequency, for that song. The frequency of a word is the number of
instances of that word in a given song. The program will then print out each
instance of that word in the top ten songs, giving a context of the five
lyrics before and after that instance. The purpose of this program is to
provide the user with a simple interface in which the user can ask the age old
question: "I wonder what songs have the most use of the word love?".

Files-------------------------------------------------------------------------
main.cpp
    Used to actually run the code and interact with the user. It reads in the
    lyrics and stores them in the local database. It then takes user queries
    and searches the database and prints the results. Continuously asks for
    input until <BREAK>.
hashtable.h
    Class definition for the Hashtable class. Declares the necessary structs
    and functions. Declares the unordered map to be used for hashing.
hashtable.cpp
    Class implementation for Hashtable class. Implements necessary functions,
    making use of the unordered map hashtable.
read_lyrics.h
    Class definition for the Database class. Declares the vector used to store
    individual songs.
read_lyrics.cpp
    Class implementation for Database class. Reads in lyrics and stores them
    in the lyrics vector within the song vectors.
    
Compiling---------------------------------------------------------------------
Use the included makefile and type "make" in the command window to compile.
Must use g++ to compile for the descending sorting algorithm used.

Data Structure----------------------------------------------------------------
The main data structures used in this program are vectors and an unordered
map. Both are used in order to avoid the hassle of expanding arrays. A vector
is used to store songs, in which another vector is used to store the lyrics.
The hashtable uses an unordered map with the key being a string (the word) and
the stored object is a vector containing both the song indices the word
appears in and the frequency of the appearances in that song.

Algorithm---------------------------------------------------------------------
For the unordered map the word is the key, therefore it serves as an index
for the vector that is the map. It maps a word to its vector of songwithfreqs.
Every time a word is encountered the program checks the map at hashtable[word]
to see if it contains anything. If a new word is encountered the count is
initialized to 1 and the index of the song gets the index of the song
currently being read in. To read in lyrics, the program looks through the
database and extracts the artist, the song title, and the lyrics. The lyrics
are pushed onto a vector word by word. Each song is then pushed onto a vector
with those elements. As each word is read in and stored it is also hashed.
When hashing, the program compares the current count of the word to the
stored songwithfreqs to see if it is big enough to be a top ten song.
If it is big enough then it is stored in the songwithfreq vector for that
word. Every time a new song is encountered the hashing does that comparison.
Therefore, when the last song is reached and gone through there is no
comparison so when the user searched for a word, the search function will make
that last comparison, and storing if necessary. To search for a word all that
is needed is to access that element in the map using the string as the key.
This is therefore done very quickly. The program then simply has to access
they song indices stored for that word and print the context in each of those
ten songs.