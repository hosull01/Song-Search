//
// hashtable.h
// Name: Harry O'Sullivan
// Date: 4/27/2014
// Purpose: the .h file to the hashtable class
//

#ifndef __HASHTABLE__
#define __HASHTABLE__

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct songwithfreq {
    size_t index;
    size_t frequency;
};

// inside each bucket is an 'info'
struct info {
    vector<songwithfreq> topten; // vector of structs, sorted by frequency
    size_t count;
    size_t current_index;
};

struct descending {
    bool operator()(songwithfreq lhs, songwithfreq rhs){
        return lhs.frequency > rhs.frequency;
    }
};

class Hash {
public:
    Hash();
    
    // inserts a word into the hashtable
    void insert_word(string word, size_t index);
    
    // searches for the word in the hashtable and returns the topten songs
    vector<songwithfreq> search(string word);
    
private:
    unordered_map<string, info> hashtable;
    
    // inserts a new word into the hashtable
    void insert_new_word(string word, size_t index);
    
    // pushes an index/freq pair to the topten vector of the given word
    void push_to_topten(string word);
    
};

#endif