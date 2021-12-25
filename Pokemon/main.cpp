#include<vector>
#include<cstdlib>
#include<fstream>
#include<iostream>
#include <ctime> 
#include <string>
#include <sstream>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include<string>
#include "Pokemon.h"
#include "Moves.h"
using namespace std;

void setMovesList(string poke, vector<Moves>& pokemonMoves);
void PokemonList(vector<Pokemon>& pokemonList);
void setPlayerMoves(Pokemon& player, vector<Moves>& pokemonMoves);
void BattleSimulator(Pokemon& p1, Pokemon& p2, string player1Name, string player2Name);
double TypeAdv( Pokemon& player, Moves& move);

int main() {

    cout << "Press ENTER to continue";
    cin.get();

    string player1Name;
    string player2Name;
    
    string temp = "Player 1, Input your name: ";
    int x = 0;
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    }
    getline(cin,player1Name);
    cout << endl;

    temp = "Player 2, Input your name: ";
    x = 0;
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    }
    
    getline(cin,player2Name);
    cout << endl;

    temp = "Welcome to the Pokemon Center " + player1Name + " and " + player2Name + "!";
    x = 0;
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    }
    cout << endl;
    cout << endl;

    cout << "Your Pokemon will be chosen for you" << endl;
    cout << endl;
    
    vector<Pokemon> pokemonList;
    PokemonList(pokemonList);
    srand(time(0));
    
    //choosing p1's pokemon
    int random1 = rand() % 5;
    string poke1 = pokemonList.at(random1).getPokeName();
    string poke1type = pokemonList.at(random1).getPokeType();
    int poke1Health = pokemonList.at(random1).getPokeHealth();
    Pokemon p1 = Pokemon(poke1, poke1type, poke1Health);
    
    //choosing p2's pokemon
    int random2 = rand() % 5;
    string poke2 = pokemonList.at(random2).getPokeName();
    string poke2type = pokemonList.at(random2).getPokeType();
    int poke2Health = pokemonList.at(random2).getPokeHealth();
    Pokemon p2 = Pokemon(poke2, poke2type, poke2Health);



    cout <<  player1Name << " your Pokemon is " << p1.getPokeName() << "!" << endl;

    cout << "Player 2's Pokemon is " << p2.getPokeName() << endl;
 
    cout << p1.getPokeName() << " is a " << p1.getPokeType() << " type with " << p1.getPokeHealth() << " HP.";
    cout << endl;
    cout << endl;
    //setting p1's moves
   
    vector<Moves> moves1;
    setPlayerMoves(p1,moves1); // asks players what moves they want based on their Poke and stores it into a moves vector
    p1.setMoves(moves1);
    vector<Moves> p1Moves = p1.getPokeMoves();
    // for(int i = 0; i<p1Moves.size(); i++) {
    //     p1Moves.at(i).printMoveObject();
    // }
   
    


    
    cout << endl;
    cout <<  player2Name << " your Pokemon is " << p2.getPokeName() << "!" << endl;

    cout << p2.getPokeName() << " is a " << p2.getPokeType() << " type with " << p2.getPokeHealth() << " HP.";

    cout << endl;
    cout << endl;

    //setting p2's moves
    vector<Moves> moves2;
    setPlayerMoves(p2,moves2); // asks players what moves they want based on their Poke and stores it into a moves vector
    p2.setMoves(moves2);
    vector<Moves> p2Moves = p2.getPokeMoves();
    // for(int i = 0; i<p2Moves.size(); i++) {
    //     p2Moves.at(i).printMoveObject();
    // }

    BattleSimulator(p1, p2, player1Name, player2Name);
    
    return 0;

}



void PokemonList(vector<Pokemon>& pokemonList) {
        Pokemon p;
        string name;
        string type;
        int health;
        ifstream inFS;
        inFS.open("pokemonlist.txt");
        
        while(inFS >> name >> type >> health) {
        p.setName(name);
        p.setType(type);
        p.setHealth(health);
        pokemonList.push_back(p);
    }

    inFS.close();


}

void setMovesList(string poke, vector<Moves>& pokemonMovesList) {
    string name;
    string type;
    int damage;
    double accuracy;
    
        if(poke == "Charizard") {
            ifstream inFS;
            inFS.open("charizardmoves.txt");
            
            while(inFS >> name >> type >> damage >> accuracy) {
                Moves m1 = Moves(name, type, damage, accuracy);
                pokemonMovesList.push_back(m1);
            }
            
        }
        
        if(poke == "Venusaur") {
            ifstream inFS;
            inFS.open("venusaurmoves.txt");
            
            while(inFS >> name >> type >> damage >> accuracy) {
                Moves m1 = Moves(name, type, damage, accuracy);
                pokemonMovesList.push_back(m1);
            }
            
        }

        if(poke == "Blastoise") {
            ifstream inFS;
            inFS.open("blastoisemoves.txt");
            
            while(inFS >> name >> type >> damage >> accuracy) {
                Moves m1 = Moves(name, type, damage, accuracy);
                pokemonMovesList.push_back(m1);
            }
            
        }

        if(poke == "Pikachu") {
            ifstream inFS;
            inFS.open("pikachumoves.txt");
            
            while(inFS >> name >> type >> damage >> accuracy) {
                Moves m1 = Moves(name, type, damage, accuracy);
                pokemonMovesList.push_back(m1);
            }
            
        }
        if(poke == "Pidgeot") {
            ifstream inFS;
            inFS.open("pidgeotmoves.txt");
            
            while(inFS >> name >> type >> damage >> accuracy) {
                Moves m1 = Moves(name, type, damage, accuracy);
                pokemonMovesList.push_back(m1);
            }
            
        }
    
    
}

void setPlayerMoves(Pokemon& player, vector<Moves>& pokemonMoves) {

    string move;
    bool match;
    vector<Moves> pokemonMovesList;
    setMovesList(player.getPokeName(), pokemonMovesList); // provides a list of moves based on current Pokemon
    
    cout << "What moves do you want " << player.getPokeName() << " to learn?" << endl;



    for(int i = 0; i<pokemonMovesList.size(); i++) {
        pokemonMovesList.at(i).printMoveObject();
        cout << endl;
    }

    cout << "Enter the name of Move 1" << endl;
    cin >> move;
    while(pokemonMoves.size() != 1) {
    for(int i = 0; i<pokemonMovesList.size(); i++) {
        if(move == pokemonMovesList.at(i).getMoveName()) {
            pokemonMoves.push_back(pokemonMovesList.at(i));
            
        }
    }
    if(pokemonMoves.size() != 1) {
        cout << "Enter the name of Move 1" << endl;
        cin >> move;
    }
}

    cout << "Enter the name of Move 2" << endl;
    cin >> move;
    while(pokemonMoves.size() != 2) {
    for(int i = 0; i<pokemonMovesList.size(); i++) {
        if(move == pokemonMovesList.at(i).getMoveName()) {
            pokemonMoves.push_back(pokemonMovesList.at(i));
            
        }
    }
    if(pokemonMoves.size() != 2) {
        cout << "Enter the name of Move 2" << endl;
        cin >> move;
    }
}
    cout << "Enter the name of Move 3" << endl;
    cin >> move;
    while(pokemonMoves.size() != 3) {
    for(int i = 0; i<pokemonMovesList.size(); i++) {
        if(move == pokemonMovesList.at(i).getMoveName()) {
            pokemonMoves.push_back(pokemonMovesList.at(i));
            
        }
    }
    if(pokemonMoves.size() != 3) {
        cout << "Enter the name of Move 3" << endl;
        cin >> move;
    }
}
    cout << "Enter the name of Move 4" << endl;
    cin >> move;
    while(pokemonMoves.size() != 4) {
    for(int i = 0; i<pokemonMovesList.size(); i++) {
        if(move == pokemonMovesList.at(i).getMoveName()) {
            pokemonMoves.push_back(pokemonMovesList.at(i));
            
        }
    }
    if(pokemonMoves.size() != 4) {
        cout << "Enter the name of Move 4" << endl;
        cin >> move;
    }
}
    
}

void BattleSimulator(Pokemon& p1, Pokemon& p2, string player1Name, string player2Name) {
    
    cout << endl;
    cout << endl;

    string welcome = "Welcome to the Battlefield!";
    
    int x = 0;
    while(welcome[x] != 0) {
        cout << welcome[x];
       
        x++;
    }
    cout << endl;
    cout << endl;

    x = 0;
    string temp = player1Name + " sends out " + p1.getPokeName();
   
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    }
    cout << endl;
    cout << endl;
    x = 0;
    temp = player2Name + " sends out " + p2.getPokeName();
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    }
    cout << endl;
    cout << endl;
    //player 1's turn

    while(p1.getPokeHealth() != 0 && p2.getPokeHealth() != 0) {
    cout << "What will " << p1.getPokeName() << " do?" << endl;
    cout << endl;
    for(int i = 0; i<p1.getPokeMoves().size(); i++) {
            p1.getPokeMoves().at(i).printMoveObject();
            cout << endl;
    }
    cout << endl;
    string move1Name;
    Moves move1;
    bool match = false;
    cout << player1Name << ", enter move name here: ";
    cin >> move1Name;
    cout << endl;
    while(!match) {
    for(int i = 0; i<p1.getPokeMoves().size(); i++) {
        if(move1Name == p1.getPokeMoves().at(i).getMoveName()) {
            match = true;
            move1 = p1.getPokeMoves().at(i);      
        }
        
    }
    if(!match) {
        cout << "Re-enter a valid move name: ";
        cin >> move1Name;
        cout << endl;
    }
}

cout << "What will " << p2.getPokeName() << " do?" << endl;
    cout << endl;
    for(int i = 0; i<p2.getPokeMoves().size(); i++) {
            p2.getPokeMoves().at(i).printMoveObject();
            cout << endl;
    }
    cout << endl;
    string move2Name;
    Moves move2;
    bool match2 = false;
    cout << player2Name << ", enter move name here: ";
    cin >> move2Name;
    cout << endl;

    while(!match2) {
    for(int i = 0; i<p2.getPokeMoves().size(); i++) {
        if(move2Name == p2.getPokeMoves().at(i).getMoveName()) {
            match2 = true;
            move2 = p2.getPokeMoves().at(i);      
        }
        
    }
    if(!match2) {
        cout << "Re-enter a valid move name: ";
        cin >> move2Name;
        cout << endl;
    }
}


    //pokemon attack at the same time
    srand(time(0));
    int rand1 = rand() % 100 + 1;
    cout << endl;
    if(move1.getMoveName() == "Hyper_Beam") {
        cout << "Hyper Beam is charging" << endl;
  
    }
    else if(move1.getMoveAccuracy() < rand1) {
        cout << p1.getPokeName() << "'s attack missed" << endl;
    
    }
    else {
        double damageChange = TypeAdv(p2,move1);
        

        p2.setHealth(p2.getPokeHealth() - move1.getMoveDamage()*damageChange);
        temp = p1.getPokeName() + " used " + move1.getMoveName() +   "!";
      
        
     x=0;   
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    }

    if(damageChange == 2) {
            cout << endl;
            cout << "It was super effective." << endl;
           
        }
        if(damageChange == 0.5) {
            cout << endl;
            cout << "It was not very effective." << endl;
            
        }
    
    cout << endl;
    cout << endl;
    }

    int rand2 = rand() % 100 + 1;
    cout << endl;
    if(move2.getMoveName() == "Hyper_Beam") {
        cout << "Hyper Beam is charging" << endl;
        
    }
    else if(move2.getMoveAccuracy() < rand2) {
        cout << p2.getPokeName() << "'s attack missed" << endl;
        
    }
    else {
        double damageChange = TypeAdv(p1,move2);
        p1.setHealth(p1.getPokeHealth() - move2.getMoveDamage()*damageChange);  
        temp = p2.getPokeName() + " used " + move2.getMoveName() +   "!";
     
    x=0; 
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    }
        if(damageChange == 2) {
            cout << endl;
            cout << "It was super effective." << endl;
           
        }
        if(damageChange == 0.5) {
            cout << endl;
            cout << "It was not very effective." << endl;
            
        }
    }
    cout << endl;
    cout << endl;
    if(p1.getPokeHealth() < 0) {
        p1.setHealth(0);
    }
    if(p2.getPokeHealth() < 0) {
        p2.setHealth(0);
    }
    stringstream ss;
    ss << p1.getPokeHealth();
    string pokeHealth = ss.str();  
    ss.clear();
    temp = p1.getPokeName() + " now has " + pokeHealth + " HP left.";
    x=0;
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    } 
 
    cout << endl;
    cout << endl;
    stringstream ss2;
    ss2 << p2.getPokeHealth();
    pokeHealth = ss2.str();  
    ss2.clear();
    temp = p2.getPokeName() + " now has " + pokeHealth + " HP left.";
    x=0;
    while(temp[x] != 0) {
        cout << temp[x];
        
        x++;
    } 

 
    cout << endl;
    cout << endl;
    string end = "";

    if(p1.getPokeHealth() == 0 && p2.getPokeHealth() == 0) {
        end = "Both Pokemon have fainted. \n DRAW.";
        x=0;
    while(end[x] != 0) {
        cout << end[x];
        
        x++;
    }
    exit(1);
    }
    else if(p1.getPokeHealth() == 0) {
        end = p1.getPokeName() + " has fainted \n" + player2Name + " has won the battle.";
         x=0;
    while(end[x] != 0) {
        cout << end[x];
        
        x++;
    }
    exit(1);
    }
    else if(p2.getPokeHealth() == 0) {
        end = p2.getPokeName() + " has fainted \n" + player1Name + " has won the battle.";
         x=0;
    while(end[x] != 0) {
        cout << end[x];
        
        x++;
    }
    exit(1);
    }
    
    }
    
}



double TypeAdv(Pokemon& player, Moves& move) {
    double num;
    double arr[15][5];
    ifstream inFS;
    inFS.open("typeArray.txt");
    for(int i = 0; i<15; i++) {
        for(int j = 0; j<5; j++) {
            inFS >> num;
            arr[i][j] = num;
        }
    }
    int row = 100;
    int column = 100;
    if(player.getPokeType() == "FIRE") {
        column = 0;
    }
    if(player.getPokeType() == "WATER") {
        column = 1;
    }
    if(player.getPokeType() == "GRASS") {
        column = 2;
    }
    if(player.getPokeType() == "ELECTRIC") {
        column = 3;
    }
    if(player.getPokeType() == "FLYING") {
        column = 4;
    }

    if(move.getMoveType() == "FIRE") {
        row = 0;
    }
    if(move.getMoveType() == "WATER") {
        row = 1;
    }
    if(move.getMoveType() == "GRASS") {
        row = 2;
    }
    if(move.getMoveType() == "ELECTRIC") {
        row = 3;
    }
    if(move.getMoveType() == "ICE") {
        row = 4;
    }
    if(move.getMoveType() == "PSYCHIC") {
        row = 5;
    }
    if(move.getMoveType() == "NORMAL") {
        row = 6;
    }
    if(move.getMoveType() == "FIGHTING") {
        row = 7;
    }
    if(move.getMoveType() == "FLYING") {
        row = 8;
    }
    if(move.getMoveType() == "GROUND") {
        row = 9;
    }
    if(move.getMoveType() == "ROCK") {
        row = 10;
    }
    if(move.getMoveType() == "BUG") {
        row = 11;
    }
    if(move.getMoveType() == "POISON") {
        row = 12;
    }
    if(move.getMoveType() == "GHOST") {
        row = 13;
    }
    if(move.getMoveType() == "DRAGON") {
        row = 14;
    }
    if(row == 100 || column == 100) {
        return 1;
    }
    else {
        return arr[row][column];
    }
    

}