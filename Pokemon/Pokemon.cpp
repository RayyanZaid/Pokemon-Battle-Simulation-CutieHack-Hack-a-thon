#include<vector>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include "Pokemon.h"
#include "Moves.h"
using namespace std;

Pokemon::Pokemon() {
    name = "";
}

Pokemon::Pokemon(string name, string type, int health) {
    this->name = name;
    this->type = type;
    this->health = health;
}

void Pokemon::setName(string n) {
    name = n;
    
}

void Pokemon::setType(string t) {
    type = t;
}

void Pokemon::setHealth(int h) {
    health = h;
}

void Pokemon::setMoves(vector<Moves> m) {
    moves = m;
}

string Pokemon::getPokeName() {
    return name;
}

string Pokemon::getPokeType() {
    return type;
}
int Pokemon::getPokeHealth() {
    return health;
}

vector<Moves> Pokemon::getPokeMoves() {
    return moves;
}

void Pokemon::display() {
    cout << "Name: " << name;
    cout << "Type: " << type;
    cout << "Health: " << health << endl;
}