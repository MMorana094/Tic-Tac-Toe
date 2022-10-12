#ifndef BOARD_H
#define BOARD_H
#include "player.h"
#include <iomanip>

using namespace std;

class Board{
    private:
        char** Matrix;
        int rows = 3;
        int columns = 3;
    
    public:
        Board(){
            Matrix = new char*[rows];
            for(int i=0; i<rows; i++){
                Matrix[i] = new char[columns];
                for(int j=0; j<columns; j++){
                    Matrix[i][j] = '?';
                }
            }
        }

        void print(){
                for(int i = 0; i<rows; i++){
                    std::cout << "------------------\n|";
                    for(int j = 0; j<columns; j++){
                        cout << setw(3);
                        if(Matrix[i][j] == '?'){
                            cout << " " << setw(4) << "| ";
                        }else{
                            cout << Matrix[i][j] << setw(4) << "| ";
                        }
                    }
                    cout << endl;
                }
                cout << "------------------\n";
        }

            void insert(player& obj){

                cout << "Dove vuole inserire il suo simbolo?\nLo specifichi nel seguente modo:\nes: 1x2 (riga 1 colonna 2)\n";
                string input = "";

                int x = 900;
                int y = 900;
                do{
                    getline(cin, input);
                    const char *ptr = &(input[0]);
                    x = atoi(ptr);
                    x = x - 1;
                    ptr = &(input[2]);
                    y= atoi(ptr);
                    y = y - 1;
                    if(x < 0 || x >2 || y < 0 || y > 2 || (input)[1] != 'x'){
                        cerr << "Il valore deve essere compreso fra 1 e 3, deve essere formattato in tale modo (es. 1x2 (riga 1 colonna 2))\n";
                        clearerr;
                    }
                    else if(Matrix[x][y] != '?'){
                        cerr<< "il posto da lei selezionato e' gia' occupato, proceda a selezionarne un altro\n";
                        clearerr;
                    }
                }while(x < 0 || x > 2 || y < 0 || y > 2 || (input)[1] != 'x' || Matrix[x][y] != '?');
                Matrix[x][y] = obj.getSymbol();
            }

            bool wincondition(player& obj){

                int contx = 0;
                int conty = 0;
                int contd = 0;

                for(int i=0; i<3; i++){
                    for(int j=0; j<2; j++){
                        if(Matrix[i][j] == Matrix[i][j+1] && Matrix[i][j] == obj.getSymbol()){
                            contx++;
                            }
                        if(Matrix[j][i] == Matrix[j+1][i] && Matrix[j][i] == obj.getSymbol()){
                            conty++;
                            }
                        if(contx == 2 || conty == 2 || contd == 3){
                            cout << obj.getName() << " Ha vinto la partita!" << endl;
                            return false;
                        }
                    }
                    contx = 0;
                    conty = 0;
                }

                if( Matrix[0][0] == Matrix[1][1] && Matrix[1][1] == Matrix[2][2] && Matrix[0][0] == obj.getSymbol()){
                    contd = 3;
                }

                if(contx == 2 || conty == 2 || contd == 3){
                    cout << obj.getName() << " Ha vinto la partita!" << endl;
                    return false;
                }
                contx = 0;
                for ( int i = 0; i<3; i++){
                    for(int j=0; j<3; j++){
                        if(Matrix[i][j]=='?'){
                            contx++;
                        }
                    }
                }
                if(contx == 0){
                    cout << "La partita e' finita in pareggio!";
                    return false;
                }
                return true;
            }
        
};

#endif

//int** Matrix = new int*[n];
//for
//int* Matrix[i] = new int[m];