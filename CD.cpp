
using namespace std;
#include <iostream>
#include "CD.h"

CD* createCD(string artist, string title, int year, int rate, int numOfSongs){
    CD* c = new CD;

    c->__artist = artist;
    c->__cdTitle = title;
    c->__releaseYear = year;
    c->__cdRating = rate;
    c->__songsOnCD = numOfSongs;
    c->__songs = new Song*[numOfSongs];

    return c;
}

void displayCD(CD* c){
    int arrSize = c->__songsOnCD;

    cout << "Artist: " << c->__artist << endl;
    cout << "Title: " << c->__cdTitle << endl;
    cout << "Year: " << c->__releaseYear << endl;
    cout << "Rating: " << c->__cdRating << endl;

    for(int i = 0; i < arrSize; i++){
        displaySong(c->__songs[i]);
    }

    cout << endl;
}

void destroyCD(CD* c){
    int arrSize = c->__songsOnCD;

    for(int i = 0; i < arrSize; i++){
        destroySong(c->__songs[i]);
    }

    delete c;

}

void addSong(CD* c, string title, string length){
    int arrSize = c->__songsOnCD;
    int newSize = arrSize + 1;

    Song** newArr = new Song*[newSize];

    for(int i = 0; i < arrSize; i++){
        newArr[i] = c->__songs[i];
    }

    newArr[arrSize] = createSong(title, length);

    c->__songs = newArr;

}