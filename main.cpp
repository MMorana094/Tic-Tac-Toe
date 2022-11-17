#include "board.h"
#include <cctype>
#include <cstdlib>

int main(){
	
	string name;
	char choice;
	bool partita = true;
	bool turno = true;
	Board board;

	cout << "Benvenuto su Tic-Tac-Toe\n[Player 1] Inserisci il nome: ";
	cin >> name;
	Player player1(name);
	
	cout << "[Player 2] Inserisci il nome: ";
	cin >> name;
	Player player2(name);


	do{
		cout << player1.getName() << " scegli il tuo simbolo [X/O]: ";
		cin >> choice;
	} while(cin.fail() || choice!='X' && choice!='O');

	player1.insertSymbol(choice);

	if(choice == 'X')
		player2.insertSymbol('O');
	else 
		player2.insertSymbol('X');
	

	while(partita){
        system("cls");
        board.print();
        if(turno){
			board.insert(player1);
            if(!board.wincondition(player1)){
                system("cls");
                board.print();
                partita = board.wincondition(player1);
            }
            turno=false;
        }else{
			board.insert(player2);
            if(!board.wincondition(player2)){
                system("cls");
                board.print();
                partita = board.wincondition(player2);
            }
            turno = true;
        }
    }

	return EXIT_SUCCESS;
}