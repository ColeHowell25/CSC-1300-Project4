
#include <iostream>
#include <fstream>
#include "CDs.h"
#include <string>

using namespace std;

int main(int argc, char* argv[]){
//    if(argc != 2){
//        cout << "Error! Please reformat your command line."<<endl;
//        cout << "Proper format: <Main.exe> <cds.txt>" << endl;
//        return 1;
//    }

    string userInput;
    CDs* foundCDs = new CDs;
    CDs* myCDs = new CDs;
    myCDs = createCDs(argv[1]);
	
	cout << "Welcome to the CD's\n";
	
    do{
        cout << "Enter your selection below :" << endl;
		cout << "1. Find the CDs by an artist" << endl;
		cout << "2. Sort the CD listing." << endl;
		cout << "3. Exit" << endl;
        getline(cin,userInput);
		
		if(userInput == "1")
		{
			cout << "Enter the artist's name." << endl;
			getline(cin,userInput);
			foundCDs = findCDs(myCDs, userInput);
		}
		
		if(userInput == "2")
		{
			sortCDs(myCDs);
			
		}
		
        if(userInput == "3"){
            cout << endl;
            cout << "Have a nice day!" << endl;
            break;
        }
        else if(foundCDs->___currentSize == 0){
            cout << endl;
            cout << "No CD's by that artist were found.";
        }else{
            cout << endl;
            displayCDs(foundCDs);
        }

    }while(userInput != "q");


}