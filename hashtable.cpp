//
// hashtable.cpp
// Name: Harry O'Sullivan
// Date: 4/27/2014
// Purpose: stores words into a hashtable that is an unordered map
//

#include "hashtable.h"

Hash::Hash(){
    hashtable.clear();
}

void Hash::insert_word(string word, size_t index){
    
    // if there is no bucket for the word, create one and insert
    if (hashtable.find(word) == hashtable.end()){
        insert_new_word(word, index);
    }
    // else, that word has already been stored
    else {
        // if we're still within the same song, simply update count
        if (index == hashtable[word].current_index){
            hashtable[word].count++;
        }
        // else, we've switched songs
        else {
            // if the array already has ten elements, compare it with the
            // last one to see if it needs to go inside topten
            if (hashtable[word].topten.size() == 10){
                if (hashtable[word].count > hashtable[word].topten[9].frequency){
                    hashtable[word].topten[9].index = hashtable[word].current_index;
                    hashtable[word].topten[9].frequency = hashtable[word].count;
                }
            }
            // else, simply create a new struct and pushback to topten
            else {
                push_to_topten(word);
            }
            // reinitialize the count and set the current index to the new
            // index, then sort the topten
            hashtable[word].count = 1;
            hashtable[word].current_index = index;
            descending desc;
            sort(hashtable[word].topten.begin(), hashtable[word].topten.end(),
                 desc);
        }
    }
}

// called when this word has never been entered into the hashtable
void Hash::insert_new_word(string word, size_t index){
    info new_word;
    new_word.count = 1;
    new_word.current_index = index;
    hashtable[word] = new_word;
}

void Hash::push_to_topten(string word){
    songwithfreq new_song;
    new_song.index = hashtable[word].current_index;
    new_song.frequency = hashtable[word].count;
    hashtable[word].topten.push_back(new_song);
}

vector<songwithfreq> Hash::search(string word){
    
    // if nothing is in that bucket, return empty vector
    if (hashtable.find(word) == hashtable.end()){
        vector<songwithfreq> empty_table;
        empty_table.clear();
        return empty_table;
    }
    // take care of the last element, which is currently not stored in topten
    else {
        if (hashtable[word].topten.size() == 10){
            if (hashtable[word].count > hashtable[word].topten[9].frequency){
                hashtable[word].topten[9].index = hashtable[word].current_index;
                hashtable[word].topten[9].frequency = hashtable[word].count;
            }
        }
        else {
            songwithfreq new_song;
            new_song.index = hashtable[word].current_index;
            new_song.frequency = hashtable[word].count;
            hashtable[word].topten.push_back(new_song);
        }
    }
    
    descending desc;
    // once the last one is in, sort topten 
    sort(hashtable[word].topten.begin(), hashtable[word].topten.end(), desc);
    
    // once sorted, return the topten 
    return hashtable[word].topten;
}