#include "grid.h"

using namespace std;

void Grid::clearGrid(){
    for(int i = 0; i < gridSize; i++){
        delete [] theGrid[i];
    }
    delete [] theGrid;
    delete theWindow;
    delete td;
}

Grid::Grid():theGrid(NULL), gridSize(0), td(NULL), theWindow(NULL){}
Grid::~Grid(){ this->clearGrid(); }

bool Grid::isWon(){ td->isFilled(); }

void Grid::init(int n){
    this->gridSize = n;
    Cell ** newGrid = new Cell*[n];
    TextDisplay * newTd = new TextDisplay(n);
    Xwindow * newWindow = new Xwindow;

    for(int i = 0; i < n; i++){

        newGrid[i] = new Cell[n];
        //cout<<"here"<<endl;
        for(int j = 0; j < n; j++){
            newGrid[i][j].setCoords(i,j, i*500/n, j*500/n, 500/n, 500/n, newWindow);
            newGrid[i][j].setDisplay(newTd);
            newGrid[i][j].setState(0);
            newWindow->fillRectangle(i*500/n, j*500/n, 500/n, 500/n, 0);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i-1 >= 0){
                newGrid[i][j].addNeighbour(&newGrid[i-1][j]);
            }
            if(i+1 < n){
                newGrid[i][j].addNeighbour(&newGrid[i+1][j]);
            }
            if(j-1 >= 0){
                newGrid[i][j].addNeighbour(&newGrid[i][j-1]);
            }
            if(j+1 < n){
                newGrid[i][j].addNeighbour(&newGrid[i][j+1]);
            }
        }
    }

    if(this->theGrid != NULL){
        this->clearGrid();
        delete td;
    }

    this->theGrid = newGrid;
    this->td = newTd;
    this->theWindow = newWindow;

    //cout<<"TD:"<<endl;
    //cout<<*td<<endl;
}

void Grid::change(const int & state){
    theGrid[0][0].notify(state);
}

void Grid::init(int r, int c, int state){
    theGrid[r][c].setState(state);
}

ostream &operator<<(ostream &out, const Grid &g){
    out<<*g.td;
    return out;
}

/*
void Grid::clearGrid()
{
    for(int i = 0; i < gridSize; i++)
    {
        delete [] theGrid[i];
    }
    delete [] theGrid;
}

Grid::Grid():theGrid(NULL), gridSize(0), td(NULL) {}

Grid::~Grid()
{
    clearGrid();
    delete td;
}
bool Grid::isWon()
{
    return td->isFilled();
}

void Grid::init(int n)
{
    Cell ** newGrid = new Cell*[n];
    TextDisplay *newDisplay = new TextDisplay(n);
    for(int i = 0; i < n; i++)
    {
        newGrid[i] = new Cell[n];
        for(int j = 0; j < n; j++)
        {
            newGrid[i][j].setCoords(i,j);
            newGrid[i][j].setState(0);
            newGrid[i][j].setDisplay(newDisplay);

        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i-1 >= 0){
                newGrid[i][j].addNeighbour(&newGrid[i-1][j]);
            }
            if(i+1 < n){
                newGrid[i][j].addNeighbour(&newGrid[i+1][j]);
            }
            if(j-1 >= 0){
                newGrid[i][j].addNeighbour(&newGrid[i][j-1]);
            }
            if(j+1 < n){
                newGrid[i][j].addNeighbour(&newGrid[i][j+1]);
            }
        }
    }
    /*if(this->theGrid != NULL)
    {
        this->clearGrid();
    }
    //cout<<*this;
    this->theGrid = newGrid;
}


void Grid::change(const int & state)
{
    theGrid[0][0].setState(state);
}

void Grid::init(int r, int c, int state)
{
    theGrid[r][c].setState(state);
}

ostream &operator<<(ostream &out, const Grid &g){
    out<<g.td;
    return out;
}
*/
