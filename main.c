#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void start_solution ();
int check_sol();
void print_BUZZLE ();

extern int sudoku [9][9];
extern int sud_flag [9][9];

int main()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;



    print_PUZZLE();
    start_solution();
    if(check_sol())
    {
        correct_sol();
    }


    return 0;
}
