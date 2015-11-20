#
# Makefile for SongSearch, Assignment 5
#
CXX = g++
FLAGS = -Wall -Wextra -Wconversion -g -std=c++11

songsearch: read_lyrics.h read_lyrics.cpp main.cpp hashtable.cpp hashtable.h
	${CXX} ${FLAGS} -o songsearch read_lyrics.cpp main.cpp hashtable.cpp
	
clean:
	rm -f songsearch

provide_design:
	provide comp15 hw5_design songsearch_design.txt;

provide:
	provide comp15 hw5 read_lyrics.h read_lyrics.cpp \
	hashtable.cpp hashtable.h main.cpp \
	readme.txt Makefile