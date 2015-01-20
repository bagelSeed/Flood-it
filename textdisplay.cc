#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay(int n):gridSize(n){
    theDisplay = new char*[gridSize];
    for(int i = 0; i < gridSize; i++){
        theDisplay[i] = new char[gridSize];
        for(int j = 0; j < gridSize; j++){
            theDisplay[i][j] = '0';
            colourCount[0]++;
        }
    }
}

void TextDisplay::notify(int r, int c, char ch){
    int changedColour = ch - '0';
    colourCount[changedColour]++;

    int oldColour = theDisplay[r][c] - '0';
    colourCount[oldColour]--;
    theDisplay[r][c] = ch;
}

bool TextDisplay::isFilled(){
    for(int i = 0; i < 5; i++){
        if(colourCount[i] == gridSize*gridSize){
            return true;
        }
    }
    return false;
}

TextDisplay::~TextDisplay(){
    for(int i = 0; i < gridSize; i++){
        delete [] theDisplay[i];
    }
    delete [] theDisplay;
}

ostream & operator<<(ostream & out, const TextDisplay & td){
    for(int i = 0; i < td.gridSize; i++){
        for(int j = 0; j < td.gridSize; j++){
            out<<td.theDisplay[i][j];
        }
        out<<endl;
    }
    return out;
}

/*
TextDisplay::TextDisplay(int n):gridSize(n)
{
    theDisplay = new char*[n];
    for(int i = 0; i < 5; i++)
    {
        colourCount[i]= 0;
    }
    for(int i = 0; i < n; i++)
    {
        theDisplay[i] = new char[n];
        for(int j = 0; j < n; j++)
        {
            theDisplay[i][j] = '0';
            colourCount[0]++;
        }
    }
}

void TextDisplay::notify(int r, int c, char ch)
{
    int changedColour = ch - '0';
    colourCount[changedColour]++;

    int oldColour = theDisplay[r][c] - '0';
    colourCount[oldColour]--;

    theDisplay[r][c]=ch;
}

bool TextDisplay::isFilled()
{

    int expectedSum = gridSize*gridSize;
    for(int i=0; i < 5; i++)
    {
        if(colourCount[i]==expectedSum)
        {
            return true;
        }
    }
    return false;
}

TextDisplay::~TextDisplay()
{
    for(int i = 0; i < gridSize; i++)
    {
        delete [] theDisplay[i];
    }
    delete [] theDisplay;
    delete [] colourCount;
}

ostream &operator<<(ostream &out, const TextDisplay &td){
    for(int i = 0; i < td.gridSize; i++){
        for(int j = 0; j < td.gridSize; j++){
            out<<td.theDisplay[i][j];
        }
        out<<endl;
    }
    return out;
}
*/
