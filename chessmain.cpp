#include "chessgame.h"
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <cwchar>
#include <Wincon.h>
#define _WIN32_WINNT 0x0601
typedef struct _CONSOLE_FONT_INFOEX
{
    ULONG cbSize;
    DWORD nFont;
    COORD dwFontSize;
    UINT  FontFamily;
    UINT  FontWeight;
    WCHAR FaceName[LF_FACESIZE];
}CONSOLE_FONT_INFOEX, *PCONSOLE_FONT_INFOEX;
using namespace std;

//the function declaration begins
#ifdef __cplusplus
extern "C" {
#endif
BOOL WINAPI SetCurrentConsoleFontEx(HANDLE hConsoleOutput, BOOL bMaximumWindow, PCONSOLE_FONT_INFOEX
lpConsoleCurrentFontEx);
#ifdef __cplusplus
}
#endif
//the function declaration ends
int main()
{

      HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	  CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	  WORD saved_attributes;

        		 /* Save current attributes */
	  GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	  saved_attributes = consoleInfo.wAttributes;

	   SetConsoleTextAttribute(hConsole, 23);
        CONSOLE_FONT_INFOEX info = {0};
         info.cbSize       = sizeof(info);
        info.dwFontSize.Y = 20; // leave X as zero
        info.FontWeight   = 700;
     SetCurrentConsoleFontEx(hConsole, NULL, &info);
      char ch;
    int x = choseplayer();

do
 {
 x++ ;
 system( "cls" ) ;
displayboard();

 if( (x%2) == 0 )
 {
        first_player();
 }
 else
 {
    second_player();
 }

 cout << "q- kill the program peacefully" << endl;
 ch = _getch();



 }while(ch != 'q') ;
 SetConsoleTextAttribute(hConsole, saved_attributes);

}
