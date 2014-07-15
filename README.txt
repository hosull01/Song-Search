README.txt
Name: Harry O'Sullivan
Program: Song Search
Date: 4/27/2014

Purpose of the Program -------------------------------------------------------

Ever hear a song on the radio and wonder what it is? What is the song
title and the artist? You've heard a few of the lyrcs but how do you find the 
song? This program aims to solve this program by creating a search engine for
song lyrics. Given a word, my program will identify the songs that contain that
word. For each matching song, my program will print out the artist, title, and
context of the match. The context consists of a fragment of the lyrics contain-
ing the word. My program also ranks the matching songs and presents only the 
top 10 best matching songs. Matching songs are ranked by the number of times 
the word occurs in the lyrics of a particular song. 

List of Files ----------------------------------------------------------------

main.cpp: main uses data.h to run the program. 

data.h: this is the header file to data.cpp. The member functions of this 
class read in each title, artist, and lyric, and also pushes every 
single word into a hashtable. The search process commences with the 
commence_search(word) function in this file. 

data.cpp: the implementation of data.h.

hashtable.h: this is the header file to hashtable.cpp. The member functions of
this class have many purposes. In a nutshell, they store and keep 
track of how many and from which song each word came from.

hashtable.cpp: the implementation of hashtable.h. 

How to Compile ---------------------------------------------------------------

One compiles by simply typing 'make' in the command line. 

Outline of Data Structure ----------------------------------------------------

Step One: Storing Each Song
A vector of structs was used to store each of the songs in the file.

Step Two: Keeping track of every word and where it came from 
An unordered map of structs. Each bucket in the unordered map (hash
table) consists of a vector of the topten songs, a current count
and a current index. 


Outline of Algorithm ---------------------------------------------------------

Step One: Storing Each Song 
A vector of structs was used to store each of the songs in the given 
file. Each index of this vector represents a song, and within it, it 
has the title, the artist, and a vector of all of the lyrics. This 
vector will be used later on to print the context of a given search
word. 

Step Two: Keeping track of every word and where it came from 
Instead of using a dynamic array and a hashfunction, I opted to use an 
unordered_map. Thus, actions like expanding the array and dealing with 
collisions are already taken care of. Hashing a word into an unordered
map is very simple. One can access an element of the map by simply 
saying map[word]. 

Each bucket of this map consists of a vector of topten songs (based on
frequency), a current_index variable, and a count variable. Once a new
song is being entered, the original current_index and count are com-
piled into a struct and pushed into the vector. Then, current_index and
count are set to the incoming index and 1, respectively. However, this
means that the last occurence of a word in a particular song will not
be pushed into the topten vector (since, to tell if the same word is 
coming from a different song, the incoming index and the current_index
are compared). So, when the search commences, the final current_index
and count is compiled and pushed onto the topten vector if it needs to 
go inside. After each push, the vector is sorted in descending order 
by frequency. 


===================================END========================================




