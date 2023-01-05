#include "chessgame.h"



 char board[8][8] = {
                    {'R', 'H', 'C', 'K', 'Q', 'C', 'H', 'R'},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {'r', 'h', 'c', 'k', 'q', 'c', 'h', 'r'}

};
string bboard[8][8] = {
                    {"(11)-", "(12)-", "(13)-", "(14)-", "(15)-", "(16)-", "(17)-", "(18)-"},
                    {"(21)-", "(22)-", "(23)-", "(24)-", "(25)-", "(26)-", "(27)-", "(28)-"},
                    {"(31)-", "(32)-", "(33)-", "(34)-", "(35)-", "(36)-", "(37)-", "(38)-"},
                    {"(41)-", "(42)-", "(43)-", "(44)-", "(45)-", "(46)-", "(47)-", "(48)-"},
                    {"(51)-", "(52)-", "(53)-", "(54)-", "(55)-", "(56)-", "(57)-", "(58)-"},
                    {"(61)-", "(62)-", "(63)-", "(64)-", "(65)-", "(66)-", "(67)-", "(68)-"},
                    {"(71)-", "(72)-", "(73)-", "(74)-", "(75)-", "(76)-", "(77)-", "(78)-"},
                    {"(81)-", "(82)-", "(83)-", "(84)-", "(85)-", "(86)-", "(87)-", "(88)-"}

};

void displayboard(){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i=0; i<8; i++){
    for(int k=0; k<8; k++){
        if (board[i][k] > 96)
            SetConsoleTextAttribute(hConsole, 16);
        else if ((board[i][k] > 64 )&& (board[i][k]< 91))
                SetConsoleTextAttribute(hConsole, 23);
        else if (board[i][k] == ' ')
                SetConsoleTextAttribute(hConsole, 18);

        cout << bboard[i][k]<<board[i][k] << " | ";
    }
    cout <<"\n-----------------------------------------------------------------------"<<endl;
    }
     SetConsoleTextAttribute(hConsole, 23);

}
void change(int row1, int col1, int row2, int col2){

    board[row2][col2] = board[row1][col1];
    board[row1][col1] = ' ';
    system("cls");
    displayboard();

}
int  choseplayer(){

    srand(time(0));


    if (rand()%2 == 0)

        return 0;
        // first_player();
    else
        return 1;
        //second_player();

}
void first_player(){

    int position;
    int col1, row1, row2, col2;
    cout << "first player turn\n";
    cout << "Enter element position to change e.g 66 1st number is row and 2nd is column\n";
    againl:
    cin >> position;

    row1= (position/10)-1;
    col1= (position%10)-1;


        switch( board[row1][col1] )
    {
        case 'P': pawn( row1 , col1 );
                  break ;
        case 'R': rook( row1 , col1 ) ;
                  break ;
        case 'H': knight( row1 , col1 );
                  break ;
        case 'C': bishop( row1 , col1 );
                  break ;
        case 'K': king( row1, col1 ) ;
                  break ;
        case 'Q': queen( row1 , col1 ) ;
                  break ;
        default: cout << "invalid position try again\n" ; goto againl ;
    }
    cout << "Enter position to send to" << endl;

    cin >> position;

    row2 = (position/10)-1;
    col2 = (position%10)-1;


    change(row1, col1, row2, col2);


}

void second_player(){

    int position;
    int col1, row1, row2, col2;
    cout << "Second player turn\n";
    cout << "Enter element position to change e.g 66 1st number is row and 2nd is column\n";

    again2:
    cin >> position;

    row1= (position/10)-1;
    col1= (position%10)-1;

     switch( board[row1][col1] )
    {
        case 'p': pawnb( row1 , col1 ) ;
                  break ;
        case 'r': rook( row1 , col1 ) ;
                  break ;
        case 'h': knight( row1 , col1 ) ;
                  break ;
        case 'c': bishop( row1 , col1 ) ;
                  break ;
        case 'k': king( row1 , col1 ) ;
                  break ;
        case 'q': queen( row1 , col1 ) ;
                  break ;
        default: cout << " invalid position\n" ; goto again2 ;
    }

    cout << "Enter position to send to" << endl;

    cin >> position;

    row2 = (position/10)-1;
    col2 = (position%10)-1;


    change(row1, col1, row2, col2);

}

void pawn( int r1 , int c1 )
{

    cout << "Available are: \n" << endl;


        if( board[r1+1][c1] == ' ' )
            cout << r1+1 << c1 << endl;

        if( board[r1+2][c1] == ' ' )
            cout << r1+2 << c1<< endl;


}
void pawnb( int r1 , int c1 ) // paido black
{

    cout << "Available are: \n" << endl ;




            if( board[r1-1][c1] == ' ' )
                cout << r1-1 << c1<< endl;

            if( board[r1-2][c1] == ' ' )
                cout << r1-2 << c1<< endl;


}

void king( int r1 , int c1 )
{
        cout << "Available moves" << endl;

    if( board[r1][c1+1] == ' ' )   cout << r1 << c1+1 << endl;

    if( board[r1][c1-1] == ' ' )   cout << r1 << c1-1 << endl;

    if( board[r1+1][c1] == ' ' )   cout << r1+1 << c1 << endl;

    if( board[r1-1][c1] == ' ' )   cout << r1-1 << c1 << endl;

    if( board[r1+1][c1+1] == ' ')  cout << r1+1 << c1+1 << endl;

    if( board[r1-1][c1-1] == ' ')  cout << r1-1 << c1-1 << endl;

    if( board[r1-1][c1+1] == ' ')  cout << r1-1 << c1+1 << endl;

    if( board[r1+1][c1-1] == ' ')  cout << r1+1 << c1-1 << endl;
}

void queen( int r1 , int c1 )
{
    int x=1 , y=1 , a , b ;
   cout << "Available moves" << endl;

    cout << "Horizontal: " << endl;

    while( board[r1][c1-y] == ' ' )
    {
        if( (c1-y) == -1 ) break ;
            cout << r1 << c1-y << endl;
        y++ ;
    }

    y = 1 ;

    while( board[r1][c1+y] == ' ' )
    {
        if( (c1+y) == 8 ) break ;
            cout << r1 << c1+y << endl;
        y++ ;
    }

        cout << "vertical scan: " << endl;

    x = 1 ;

    while( board[r1-x][c1] == ' ' )
    {
        if( (r1-x) == -1 ) break ;
                cout << r1-x << c1 << endl;
        x++ ;
    }

    x = 1 ;

    while( board[r1+x][c1] == ' ' )
    {
        if( (r1+x) == 8 ) break ;
            cout << r1+x << c1 << endl;
        x++ ;
    }

    cout << "Diagonally: " << endl;

    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' ' )
    {
        if( (r1-a) == -1 || (c1+b) == 8 ) break ;
                cout << r1 - a << c1 + b << endl;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' ' )
    {
        if( (r1+a) == 8 || (c1-b) == -1 ) break ;

            cout << r1+a << c1-b << endl;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
                cout << r1+a << c1+b << endl;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
                cout << r1-a << c1-b << endl;
        a++ ;
        b++ ;
    }

}

void bishop( int r1 , int c1 )
{
    int a , b ;
        cout << "Available are: \n" << endl;


    a = 1 , b = 1 ;

    while( board[r1-a][c1+b] == ' '  &&  ( (r1-a) != -1 || (c1+b) != 8 ))
    {

                cout << r1-a << c1+b << endl;
        a++ ;
        b++ ;
    }


    a = 1 , b = 1 ;

    while( board[r1+a][c1-b] == ' '  &&   ((r1+a) != 8 || (c1-b) != -1 ))
    {

        cout << r1+a << c1-b << endl;
        a++ ;
        b++ ;
    }

    a = 1 , b = 1 ;


    while( board[r1+a][c1+b] == ' ' )
    {
        if( (r1+a) == 8 || (c1+b) == 8 ) break ;
                cout << r1+a << c1+b << endl;
        a++ ;
        b++ ;
    }

    a = 1 ;
    b = 1 ;

    while( board[r1-a][c1-b] == ' ' )
    {
        if( (r1-a) == -1 || (c1-b) == -1 ) break ;
                cout << r1-a << c1-b << endl;
        a++ ;
        b++ ;
    }

}

void knight( int r1 , int c1 )
{
    cout << "Available are: " << endl;


    if( board[r1+2][c1+1] == ' ' ) cout << r1+2 << c1+1 << endl;
    if( board[r1+2][c1-1] == ' ' ) { cout << r1+1 << c1-1 << endl;
    }

    if( board[r1+1][c1+2] == ' ' ) {   cout << r1+1 << c1+2 << endl;
     }
    if( board[r1-1][c1+2] == ' ' ) {  cout << r1-1 << c1+2 << endl;
    }

    if( board[r1-2][c1-1] == ' ' )
    {
        if( (c1-1) != -1 )
        cout << r1-2 <<c1-1 << endl;
    }

    if( board[r1-2][c1+1] == ' ' ) cout << r1-2 << c1+1 << endl;

    if( board[r1+1][c1-2] == ' ' ) cout << r1+1  << c1-2 << endl;

    if( board[r1-1][c1-2] == ' ' )
    {

            cout <<  r1-1 << c1-2 << endl;
    }
}


void rook( int r1 , int c1 )
{
    int  n ;

        cout << "Available are: "<< endl;

    n=c1;


    cout << "Vertically: "<< endl;

    while( board[r1][n-1] == ' ' )
    {
        if( n == 0 ) { break ; }
         cout << r1 <<  n-1 << endl;
        n-- ;
    }

    n=c1 ;

    while( (board[r1][n+1] == ' ' ) && ((n+1) <= 7) )
    {

        cout << r1 << n+1  << endl;
        ++n ;
    }
         cout << "Horizontally: " << endl ;

    n = r1 ;

    while( (board[n-1][c1] == ' ' )&& (n > -1) )
    {
        cout <<  n-1 << c1 << endl ;
        --n ;
    }

    n = r1 ;

    while( (board[n+1][c1] == ' ') && ( (n) <= 7 ) )
    {
        cout << n+1 <<  c1 << endl ;
        ++n ;
    }

}
