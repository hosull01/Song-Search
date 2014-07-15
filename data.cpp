//
// data.cpp
// Name: Harry O'Sullivan
// Date: 4/27/2014
// Purpose: stores all of the data in a vector and pushes each word into a HT
//

// in comments: 'HT' = hash-table

#include "data.h"
#include <sstream>

Data::Data(){
    songlist.clear();
}

void Data::process(string title, string artist, vector<string> lyrics)
{
    // create a struct, then add the song to the songlist vector
    song thesong;
    thesong.title = title;
    thesong.artist = artist;
    thesong.lyrics = lyrics;
    songlist.push_back(thesong);
}

void Data::read_lyrics(char * filename, bool show_progress)
{
    ifstream in(filename); // creates an input stream
    int song_count = 0; // for progress indicator
    string artist, title, word; // data from the file
    vector<string> lyrics;
    size_t index = 0;
    
    // -- While more data to read...
    while (!in.eof())
    {
        // -- First line is the artist
        getline(in, artist);
        if (in.fail()) break;
        
        // -- Second line is the title
        getline(in, title);
        if (in.fail()) break;
        
        if ( show_progress )
        {
            song_count++;
            if (song_count % 10000 == 0) {
                cout << "At " << song_count <<
                " Artist: " << artist <<
                " Title:" << title << endl;
            }
        }
        
        // -- Then read all words and insert into HT until we hit the
        // -- special <BREAK> token
        while ( in >> word && word != "<BREAK>" ){
            lyrics.push_back(word);
            thetable.insert_word(alphaOnly(word), index);
        }
        
        // -- Important: skip the newline left behind
        in.ignore();
        process(title, artist, lyrics);
        lyrics.clear();
        index++;
    }
}


void Data::search(string word){
    // strip the word of any punctuation
    string theword = alphaOnly(word);
    
    // retrieve the topten vector
    vector<songwithfreq> list = thetable.search(theword);
    
    // print all in topten
    if (list.empty()){
        cout << endl;
    }
    else {
        for (size_t i = 0; i < list.size(); i++){
            print(list[i], theword);
        }
    }
    cout << "<END-OF-REPORT>" << endl;
}

void Data::print(songwithfreq song, string theword){
    size_t count = 0;
    
    for (size_t i = 0; i < songlist[song.index].lyrics.size(); i++){
        if (alphaOnly(songlist[song.index].lyrics[i]) == theword){
            cout << "Title: " << songlist[song.index].title << endl;
            cout << "Artist: " << songlist[song.index].artist << endl;
            cout << "Context: ";
            // print 5 before and after each instance, unless there aren't 5
            if (i < 5) {
                for (size_t j = 0; j < (i+6); j++){
                    cout << songlist[song.index].lyrics[j] << " ";
                }
                cout << endl;
                count++;
            }
            else {
                for (size_t j = (i-5); j < (i+6); j++){
                    cout << songlist[song.index].lyrics[j] << " ";
                    if (j + 1 == songlist[song.index].lyrics.size()){
                        break;
                    }
                }
                cout << endl;
                count++;
            }
            cout << endl;
        }
        if (count == song.frequency) break;
    }
}

// strip a word of punctuation and tolower all letters 
string Data::alphaOnly(string word){
    ostringstream ss;
    for (size_t i = 0;i < word.length(); i++) {
        if (isalnum(word[i])){
            ss << (char)(tolower(word[i]));
        }
    }
    return ss.str();
}