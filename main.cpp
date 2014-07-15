//
// main.cpp
// Name: Harry O'Sullivan
// Purpose: the main program for the song search
// Date: 4/27/2014
//

#include <iostream>
#include "data.h"

using namespace std;

int main(int argc, char *argv[])
{
    Data library;
    if (argc == 2){
        library.read_lyrics(argv[1], false);
        string target;
        while (target != "<BREAK>"){
            cin >> target;
            if (target == "<BREAK>") break;
            library.search(target);
        }
    }
    else {
        cout << "Usage: songsearch database.txt\n";
    }
    return 0;
}