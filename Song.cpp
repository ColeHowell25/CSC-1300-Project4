
using namespace std;
#include <iostream>
#include "Song.h"

Song* createSong(string title, string length)
{
Song* s = new Song;

s->_title = title;
s->_length = length;

return s;
}

void displaySong(Song* s){

cout << s->_title << " " << s->_length << endl;
}

void destroySong(Song* s){
delete s;
}