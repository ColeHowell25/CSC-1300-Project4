
using namespace std;

#if !defined CDs_H
#define CDs_H

#include "CD.h"

struct CDs{
    CD** ___cdArray;
    int ___maxSize;
    int ___currentSize;
};

CDs* createCDs (const char* filename);

void displayCDs (CDs* c);

void destroyCDs (CDs* c);

CDs* findCDs (CDs* cds, string artist);

/*CDs**/ void sortCDs (CDs* cds);
#endif