#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>

using namespace std;

class Player{
	private:
		string name;
		char symbol;
	public:
		Player(string name){
			this->name = name;
		}

		char getSymbol() const{
			return this->symbol;
		}


		void insertSymbol(char simb){
			this->symbol = simb;
		}

		string getName() const{
			return this->name;
		}
};

#endif