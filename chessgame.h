#ifndef CHESSGAME__H
#define CHESSGAME__H

#include <iostream>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;

void first_player(void);
void second_player(void);
void change(int row1, int col1, int row2, int col2);
void displayboard(void);
int choseplayer();
void pawn(int , int ) ;
void rook(int , int ) ;
void knight(int , int ) ;
void bishop( int , int ) ;
void king( int , int ) ;
void queen( int , int ) ;
void pawnb( int , int ) ;

#endif // CHESSGAME__H
