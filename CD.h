
using namespace std;


#if !defined CD_H
#define CD_H
#include "Song.h"
#include <string>

struct CD{
    string __artist;
    string __cdTitle;
    int __releaseYear;
    int __cdRating;
    int __songsOnCD;
    Song** __songs;
};

CD* createCD(string artist, string title, int year, int rate, int numOfSong);

void displayCD(CD* c);

void destroyCD(CD* c);

void addSong(CD* c, string title, string length);

#endif