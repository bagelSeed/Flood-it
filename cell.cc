#include "cell.h"

using namespace std;

void Cell::notifyDisplay(){
    td->notify(r, c, state);
}

Cell::Cell():state(0), prevState(0), numNeighbours(0), r(0), c(0), td(NULL), x(0), y(0), width(0), height(0), window(NULL){
    for(int i = 0; i < maxNeighbours; i++){
        neighbours[i]=NULL;
    }
}

int Cell::getState(){ return state; }

void Cell::setState(const int & change){
    this->prevState = this->state;
    this->state = change;
    char setChange = '0' + change;
    td->notify(r, c, setChange);
    window->fillRectangle(x, y, height, width, state);
}

void Cell::setCoords(const int r, const int c){
    this->r = r;
    this->c = c;
}

void Cell::setDisplay(TextDisplay * t){
    this->td = t;
}

void Cell::addNeighbour(Cell * neighbour){
    neighbours[numNeighbours] = neighbour;
    numNeighbours++;
}

void Cell::notify(const int & change){
    this->setState(change);
    //td->notify(r,c,change);
    this->notify(state, prevState);
}

void Cell::notify(const int & current, const int & previous){

    for(int i = 0; i < maxNeighbours;  i++){
        if(neighbours[i] != NULL){
            //cout<<neighbours[i]->getState()<<endl;
            if(neighbours[i]->getState() == previous){
                //cout<<"How many times does it notify??"<<endl;
                neighbours[i]->setState(current);
                neighbours[i]->notify(current, previous);
            }
        }
    }
}

void Cell::setCoords(int r, int c, int x, int y, int width, int height, Xwindow *w){
    this->r = r;
    this->c = c;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->window = w;
}


/*
Cell::Cell():state(0), prevState(0), numNeighbours(0), r(0), c(0), td(NULL)
{
    for(int i = 0; i < maxNeighbours; i++)
    {
        neighbours[i]=NULL;
    }
}

void Cell::notifyDisplay()
{
    td->notify(r, c, state);
}

int Cell::getState()
{
    return state;
}

void Cell::setState(const int & change)
{
    this->prevState = state;
    this->state = change;
}

void Cell::setCoords(const int r, const int c)
{
    this->r = r;
    this->c = c;
}

void Cell::setDisplay(TextDisplay * t)
{
    td = t;
}

void Cell::addNeighbour(Cell *neighbour)
{
    for(int i = 0; i < 4; i++)
    {
        if(neighbours[i] == NULL)
        {
            this->neighbours[i] = *neighbours;
            break;
        }
    }
}

void Cell::notify( const int & change )
{
    this->setState(change);
    this->notify(state, prevState);
}

void Cell::notify( const int & current, const int & previous )
{
    for(int i = 0; i < 4; i ++)
    {
        if(neighbours[i] != NULL)
        {
            if(neighbours[i]->state == previous)
            {
                neighbours[i]->notify(current);
            }
        }
    }
}
*/
