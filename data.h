//
// data.h
// Name: Harry O'Sullivan
// Purpose: stores all of the data and pushes each word into a hashtable
// Date: 4/27/2014
//

#include <iostream>
#include <vector>
#include <fstream>
#include "hashtable.h"
using namespace std;

// an element in the songlist
struct song {
    string title;
    string artist;
    vector<string> lyrics;
};

class Data {
public:
    
    Data();
    
    // goes through the given file and stores all words and push each word to
    // a hashtable
    void read_lyrics(char * filename, bool show_progress);
    
    // displays the top ten songs with the given word
    void search(string word);
    
private:
    vector<song> songlist;
    
    Hash thetable;
    
    // processes each song
    void process(string title, string artist, vector<string> lyrics);
    
    // strips a word of punctuation and tolowers every letter
    string alphaOnly(string word);
    
    // prints 5 before and after of every instance of the word in a song
    void print(songwithfreq song, string word);
    
};