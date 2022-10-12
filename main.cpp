#include "board.h"

int main(){
	
	string name1;
	string name2;
	int choice;
	bool partita = true;
	bool turno = true;
	cout << "benvenuto nel Tic-Tac-Toe" << endl;
	cout << "Player 1 Inserisci il nome" << endl;
	cin >> name1;
	player Player1(name1);
	cout << "Player 2 Inserisci il nome" << endl;
	cin >> name2;
	player Player2(name2);
	cout << Player1.getName() << " scegli 1 = X oppure 0 = O " << endl;
	cin >> choice;
	if(choice == 1){
		Player1.insertSymbol('X');
		Player2.insertSymbol('O');
		} else {
		Player1.insertSymbol('O');
		Player2.insertSymbol('X');
		}
	Board Board1;
	while(partita == true){
        system("clear");
        Board1.print();
        if(turno==true){
           Board1.insert(Player1);
            if(Board1.wincondition(Player1)==false){
                system("clear");
                Board1.print();
                partita = Board1.wincondition(Player1);
            }
            turno=false;
        }else{
			Board1.insert(Player2);
            if(Board1.wincondition(Player2)==false){
                system("clear");
                Board1.print();
                partita = Board1.wincondition(Player2);
            }
            turno = true;
        }

    }
}