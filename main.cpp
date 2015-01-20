#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "cell.h"
#include "grid.h"
#include "textdisplay.h"
#include "window.h"

using namespace std;

int main()
{
    string input;
    int num;
    int gridSize;
    int movesLeft=1;
    bool gameStat=false;
    bool noGame=true;
    Grid *game = NULL;

    while(cin >> input)
    {
        if(input == "new")
        {
            if(noGame)
            {
                cin >> num;
                gridSize=num;
            }
            if(game != NULL)
            {
                delete game;
            }
            game = new Grid();
            game->init(num);
            //cout<<*game;
            //cout<<"The size of grid is : "<<num<<endl;
        }
        else if(input == "init")
        {
            int row, col, states;

            while(cin >> row >> col)
            {
                if(row == -1 && col == -1)
                {
                    cout<<*game;
                    break;
                }
                cin >> states;
                if(row <= gridSize && col <= gridSize){
                    game->init(row, col, states);
                }
            }
        }
        else if(input == "game")
        {
            if(noGame)
            {
                cin >> num;
                movesLeft = num;
                noGame=false;
            }
        }
        else if(input == "switch")
        {
            cin >> num;
            movesLeft--;
            game->change(num);
            cout<<*game;
        }
        else if(input == "include")
        {
            cin >> input;
            fstream openFile(input.c_str());

            int row, col, states;
            while(openFile >> row >> col)
            {
                if(row == -1 && col == -1)
                {
                    break;
                }
                openFile >> states;
                if(row <= gridSize && col <= gridSize){
                    game->init(row, col, states);
                }
            }
            cout<<*game;
            continue;
        }

        if(!noGame)
        {
            if(game->isWon()){
                if(movesLeft!=1){
                    cout<<movesLeft<<" moves left"<<endl;
                } else {
                    cout<<movesLeft<<" move left"<<endl;
                }
                gameStat = game->isWon();
                break;
            } else if(movesLeft <= 0){
                cout<<movesLeft<<" moves left"<<endl;
                break;
            }else if(movesLeft!=1)
            {
                cout<<movesLeft<<" moves left"<<endl;
            }
            else
            {
                cout<<movesLeft<<" move left"<<endl;
            }
        }
    }

    if(gameStat)
    {
        cout<<"Won"<<endl;
    }
    else
    {
        if(movesLeft>0){
            return 0;
        }
        cout<<"Lost"<<endl;
    }
    delete game;
}
