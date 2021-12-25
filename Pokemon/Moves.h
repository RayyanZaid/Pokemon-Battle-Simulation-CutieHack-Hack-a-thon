#include<vector>
#include<cstdlib>
#include<fstream>
#include<iostream>
using namespace std;

#ifndef MOVES_H
#define MOVES_H

class Moves {
    private:
        string name;
        string type;
        int damage;
        int accuracy;
        
    
    public:
    Moves();
    Moves(string n, string t, int d, int a);
    
    string getMoveName();
    string getMoveType();
    int getMoveDamage();
    int getMoveAccuracy();

    void printMoveObject();

        
};

#endif