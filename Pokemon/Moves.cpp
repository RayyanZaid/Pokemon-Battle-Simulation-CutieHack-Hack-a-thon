#include "Moves.h"
Moves::Moves() {
    name = "null";
}

Moves::Moves(string n, string t, int d, int a) {
    name = n;
    type = t;
    damage = d;
    accuracy = a;
}

void Moves::printMoveObject() {
    cout << "Name: " << name << "   ";
    cout << "Type: " << type << endl;
    cout << "Damage:  " << damage << "   ";
    cout << "Accuracy: " << accuracy << endl;
    cout << endl;
}

string Moves::getMoveName() {
    return name;
}

int Moves::getMoveAccuracy() {
    return accuracy;
}

int Moves::getMoveDamage() {
    return damage;
}

string Moves::getMoveType() {
    return type;
}