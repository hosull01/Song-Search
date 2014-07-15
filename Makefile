#
# Makefile for SongSearch, Assignment 5
#
CXX = g++
FLAGS = -Wall -Wextra -Wconversion -g -std=c++11 

songsearch: data.h data.cpp hashtable.h hashtable.cpp main.cpp
${CXX} ${FLAGS} -o songsearch data.cpp hashtable.cpp main.cpp

clean:
rm -f songsearch

provide_design:
provide comp15 hw5_design songsearch_design.txt

provide:
provide comp15 hw5 main.cpp data.h data.cpp hashtable.h hashtable.cpp README.txt Makefile 
