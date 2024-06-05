
using namespace std;
#include "CDs.h"
#include <fstream>
#include <string>
#include <iostream>

CDs* createCDs (const char* filename){
    string artist, cdTitle, songName, songLength, tmp;
    int releaseYear, cdRating, numOfSongs, myCounter = 0, sizer = 0 ;

    ifstream myFile;
    myFile.open(filename);

    while(getline(myFile, tmp))
        sizer++;

    CD** temps = new CD*[sizer];

    myFile.close();
    myFile.open(filename);
    for(artist; getline(myFile, artist); ){
        getline(myFile, cdTitle);
        myFile >> releaseYear;
        myFile >> cdRating;
        myFile >> numOfSongs;
        temps[myCounter] = createCD(artist, cdTitle, releaseYear, cdRating, numOfSongs);

        myFile.ignore();

        for(int i = 0; i < numOfSongs; i++){
            getline(myFile, songLength, ',');
            getline(myFile, songName);
            temps[myCounter]->__songs[i] = createSong(songName, songLength);
        }
        myCounter++;
    }
	myFile.close();
    CDs* myCDs = new CDs;

    myCDs->___cdArray = temps;
    myCDs->___currentSize = myCounter;
    myCDs->___maxSize = sizer;

    return myCDs;
}

void displayCDs (CDs* c){
    int arrSize = c->___currentSize;

    for(int i = 0; i < arrSize; i++){
        displayCD(c->___cdArray[i]);
    }
}

void destroyCDs (CDs* c){
    int arrSize = c->___currentSize;

    for(int i =0; i < 0; i++){
        destroyCD(c->___cdArray[i]);
    }

    delete c;
}

CDs* findCDs (CDs* cds, string artist){
    int arrSize = cds->___currentSize;
    int myCounter = 0;
    CDs* artistsCDs = new CDs;
    artistsCDs->___cdArray = new CD*[arrSize];

    for(int i = 0; i < arrSize; i++){
        if(cds->___cdArray[i]->__artist == artist){
            artistsCDs->___cdArray[myCounter] = cds->___cdArray[i];
            myCounter++;
        }
    }

    artistsCDs->___maxSize = arrSize;
    artistsCDs->___currentSize = myCounter;
	delete cds;
    return artistsCDs;
}

void sortCDs (CDs* cds){
	int num = 0;
	CDs* sortedCDs = new CDs;
	sortedCDs->___cdArray = new CD*[cds->___currentSize];
	string* artists = new string[1000];
	//int counter;
	//cout << "Under counter" << endl;
	//sorted= new CD*[cds->___currentSize];
		//sort by artist
			//store each unique artist into array from CDs
				//compare the artists for each CD to prevent duplication
			//pass each of these artists into findCDs
	for (int i = 0;i < cds->___maxSize; i++){
		//cout << "Outer for loop" << endl; 
		if (cds->___cdArray[i]->__artist == artists[num]){
			continue;
			//cout << "In if" << endl;
		}
		 else if (cds->___cdArray[i]->__artist != artists[num]){
			//cout << "Before artists array" << endl;
			for (int j = 0; j < i+1; j++){
				if (cds->___cdArray[i]->__artist == cds->___cdArray[j]->__artist){
					
				}		
			}
			artists[num] = cds->___cdArray[i]->__artist;
			cout << num << " " << artists[num] << endl;
			num++;
		}
	}
	delete[] artists;
	destroyCDs(cds);
	//return sortedCDs;
}