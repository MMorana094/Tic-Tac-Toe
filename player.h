#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cstdlib>


using namespace std;

class player{
	private:
		string Name;
		char Symbol;

		friend class Cross;
		friend class Circle;
	public:
		player(string name){
			this->Name = name;
		}

		char getSymbol(){
			return this->Symbol;
		}

		friend ostream& operator<<(ostream& os, player& obj){
			os << "Player = " << obj.getName() << ", Symbol = " << obj.getSymbol() << endl;
			return os;
		}

		void insertName(string name){
			this->Name = name;
		}

		void insertSymbol(char simb){
			this->Symbol = simb;
		}

		string getName(){
			return this->Name;
		}
};

class Cross : public player{
	public:
		Cross(string name) : player(name){
			insertSymbol('X');
		}
};

class Circle : public player{
	public:
		Circle(string name) : player(name){
			insertSymbol('O');
		}
};
#endif