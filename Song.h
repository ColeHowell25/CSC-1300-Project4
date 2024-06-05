
using namespace std;

#if !defined SONG_H
#define SONG_H
#include <string>

struct Song{
    string _title;
    string _length;
};

Song* createSong(string title, string length);

void displaySong(Song* s);

void destroySong(Song* s);

#endif