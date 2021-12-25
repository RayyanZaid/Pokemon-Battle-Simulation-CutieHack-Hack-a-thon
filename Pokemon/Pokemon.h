#include<vector>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include "Moves.h"
using namespace std;

class Pokemon {
    private:
        string name;
        int health;
        string type;
        vector<Moves> moves;
    public: 
        Pokemon();
        Pokemon(string name, string type, int health);
        void setName(string n);
        void setType(string t);
        void setHealth(int h);
        void setMoves(vector<Moves> m);

        string getPokeName();
        string getPokeType();
        vector<Moves> getPokeMoves();
        int getPokeHealth();
        
        void display();
        
        
};