#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <iomanip>

using namespace std;

class Board{
    private:
        char** matrix;
        int rows = 3;
        int columns = 3;
    
    public:
        Board(){
            matrix = new char*[rows];
            for(int i = 0; i < rows; i++){
                matrix[i] = new char[columns];
                for(int j = 0; j < columns; j++)
                    matrix[i][j] = '?';
            }
        }


        void print(){
            for(int i = 0; i < rows; i++){
                cout << "------------------\n|";
                for(int j = 0; j < columns; j++){
                    cout << setw(3);
                    if(matrix[i][j] == '?')
                        cout << " " << setw(4) << "| ";
                    else
                        cout << matrix[i][j] << setw(4) << "| ";
                }
                cout << endl;
            }
            cout << "------------------\n";
        }


        void insert(Player& obj){
            string input = "";
            int x = 900;
            int y = 900;

            cout << "Dove vuole inserire il suo simbolo?\nLo specifichi nel seguente modo:\nes: 1x2 (riga 1 colonna 2)\n";
            
            do{
                getline(cin, input);
                const char *ptr = &(input[0]);
                
                x = atoi(ptr);
                x = x - 1;
                ptr = &(input[2]);
                y= atoi(ptr);
                y = y - 1;

                if(x < 0 || x >2 || y < 0 || y > 2 || (input)[1] != 'x')
                    cerr << "Il valore deve essere compreso fra 1 e 3, deve essere formattato in tale modo (es. 1x2 (riga 1 colonna 2))\n";
                else if(matrix[x][y] != '?')
                    cerr<< "Il posto da lei selezionato e' gia' occupato, proceda a selezionarne un altro\n";

            }while(x < 0 || x > 2 || y < 0 || y > 2 || (input)[1] != 'x' || matrix[x][y] != '?');
            
            matrix[x][y] = obj.getSymbol();
        }


        bool wincondition(Player& obj){

            int contx = 0;
            int conty = 0;
            int contd = 0;

            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 2; j++){
                    if(matrix[i][j] == matrix[i][j+1] && matrix[i][j] == obj.getSymbol()){
                        contx++;
                        }
                    if(matrix[j][i] == matrix[j+1][i] && matrix[j][i] == obj.getSymbol()){
                        conty++;
                        }
                    if(contx == 2 || conty == 2 || contd == 3){
                        cout << obj.getName() << " ha vinto la partita!" << endl;
                        return false;
                    }
                }
                contx = 0;
                conty = 0;
            }

            if( matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] == obj.getSymbol())
                contd = 3;

            if(contx == 2 || conty == 2 || contd == 3){
                cout << obj.getName() << " ha vinto la partita!" << endl;
                return false;
            }
            contx = 0;
            for (int i = 0; i < 3; i++)
                for(int j= 0 ; j < 3; j++)
                    if(matrix[i][j] == '?')
                        contx++;
            
            if(contx == 0){
                cout << "La partita e' finita in pareggio!";
                return false;
            }

            return true;
        }
        
};

#endif