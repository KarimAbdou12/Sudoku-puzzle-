
#include <windows.h>


int sudoku [9][9]=
{
    {0,0,0,0,0,0,8,6,0},
    {0,0,0,8,0,7,0,0,0},
    {8,0,0,0,3,6,1,0,2},
    {7,0,0,0,0,0,0,9,3},
    {0,0,5,0,0,0,4,0,0},
    {1,8,0,0,0,0,0,0,6},
    {6,0,8,1,9,0,0,0,7},
    {0,0,0,2,0,3,0,0,0},
    {0,3,4,0,0,0,0,0,0}

};
int sud_flag [9][9]=
{
    {0,0,0,0,0,0,8,6,0},
    {0,0,0,8,0,7,0,0,0},
    {8,0,0,0,3,6,1,0,2},
    {7,0,0,0,0,0,0,9,3},
    {0,0,5,0,0,0,4,0,0},
    {1,8,0,0,0,0,0,0,6},
    {6,0,8,1,9,0,0,0,7},
    {0,0,0,2,0,3,0,0,0},
    {0,3,4,0,0,0,0,0,0}

};

void start_solution ()
{


    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    /* SetConsoleTextAttribute(hConsole, red);
     printf("This is red text.\n");
     SetConsoleTextAttribute(hConsole, green);
     printf("This is green text.\n");
     SetConsoleTextAttribute(hConsole, yellow);
     printf("This is yellow text.\n");
     SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
     SetConsoleTextAttribute(hConsole, yellow);*/



    int x=0,y=0,testx,testy,flag=0;
    SetConsoleTextAttribute(hConsole, green);
    printf("    start_solution\n\n");
    SetConsoleTextAttribute(hConsole, red);
    printf("please select row and column :\n");
    printf("when you finish enter number greater than 9 \n");
    while(1)
    {
        flag=0;
        SetConsoleTextAttribute(hConsole, yellow);
        printf("\nselect row :");
        scanf("%d",&testx);
        if(testx>9)
        {
            SetConsoleTextAttribute(hConsole, red);
            printf("\nyou can't select row greater than 9 \n\nenter another row \nand if you want finish the game enter again number greater then 9 :\n");
            SetConsoleTextAttribute(hConsole, yellow);
            printf("\nselect row : ");
            scanf("%d",&testx);

            if(testx>9)
                break;
        }
        x=testx;

        SetConsoleTextAttribute(hConsole, yellow);
        printf("select column : ");
        scanf("%d",&testy);
        if(testy>9)
        {
            SetConsoleTextAttribute(hConsole, red);
            printf("\nyou can't select coloumn greater than 9 \n\nenter another column \nand if you want finish the game enter again number greater then 9 :\n");
            SetConsoleTextAttribute(hConsole, yellow);
            printf("\nselect column : ");
            scanf("%d",&testy);

            if(testy>9)
                break;
        }
        y=testy;

        if(sud_flag[x-1][y-1])
        {
            flag=1;
        }

        if(flag==0)
        {
            SetConsoleTextAttribute(hConsole, green);
            printf("enter value : ");
            int val;
            scanf("%d",&val);
            if(val>9)
            {
                SetConsoleTextAttribute(hConsole, red);
                printf("\nyou can't put number greater than 9 \n");
                SetConsoleTextAttribute(hConsole, yellow);
                printf("\nenter another value \nand if you want finish the game enter again number greater then 9 :\n");
                SetConsoleTextAttribute(hConsole, green);
                printf("\nenter value : ");
                scanf("%d",&val);
                if(val>9)
                {
                    return ;
                }
                sudoku[x-1][y-1]=val;
            }
            else
            {
                sudoku[x-1][y-1]=val;
            }

        }
        system("cls");
        print_PUZZLE();
        if(flag==1)
        {
            SetConsoleTextAttribute(hConsole, red);
            printf("\nyou can't change this element\nTry again \n");
        }

    }
    return ;

}



int check_sol()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    /* SetConsoleTextAttribute(hConsole, red);
     printf("This is red text.\n");
     SetConsoleTextAttribute(hConsole, green);
     printf("This is green text.\n");
     SetConsoleTextAttribute(hConsole, yellow);
     printf("This is yellow text.\n");
     SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
     SetConsoleTextAttribute(hConsole, yellow);*/


    int i,j,k,flag=0;
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(sudoku[i][j]==0)
            {
                if(flag==0)
                {
                    wrong_sol();
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("\nThere are ");
                    SetConsoleTextAttribute(hConsole, red);
                    printf("zeros ");
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("in your solution, and there are in : \n\n");

                    //printf("\n\ncomplete the solution\n");
                }
                printf("row %d\t column %d\n",i+1,j+1);
                flag=1;

            }
        }
    }


    if(flag==1)
        return 0;

    for(i=0; i<9; i++)
    {
        for(k=0; k<9; k++)
        {
            for(j=0; j<9; j++)
            {

                if(sudoku[i][k]==sudoku[i][j]&&(k!=j))
                {
                    // printf("%d  %d \n",sudoku[i][k],sudoku[k][j]);
                    if(flag==0)
                    {
                        wrong_sol();
                    }

                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number \t row %d\t column %d\n",sudoku[i][k],i+1,j+1);
                    flag=1;
                }
                if(sudoku[k][i]==sudoku[j][i]&&(j!=k))
                {
                    // printf("%d  %d \n",sudoku[i][k],sudoku[j][k]);
                    if(flag==0)
                    {
                        wrong_sol();
                    }
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number \t row %d\t column %d\n",sudoku[k][i],j+1,i+1);
                    flag=1;
                }

            }
        }

    }
    char count[10]= {0};

    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }
                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the first group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }
    for(i=0; i<10; i++)
        count[i]=0;

    for(i=0; i<3; i++)
    {
        for(j=3; j<6; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the second group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }

    for(i=0; i<10; i++)
        count[i]=0;

    for(i=0; i<3; i++)
    {
        for(j=6; j<9; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the third group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }
    for(i=0; i<10; i++)
        count[i]=0;

    for(i=3; i<6; i++)
    {
        for(j=0; j<3; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the fourth group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }
    for(i=0; i<10; i++)
        count[i]=0;

    for(i=3; i<6; i++)
    {
        for(j=3; j<6; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the fifth group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }
    for(i=0; i<10; i++)
        count[i]=0;

    for(i=3; i<6; i++)
    {
        for(j=6; j<9; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the sixth group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }
    for(i=0; i<10; i++)
        count[i]=0;

    for(i=6; i<9; i++)
    {
        for(j=0; j<3; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the seventh group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }
    for(i=0; i<10; i++)
        count[i]=0;

    for(i=6; i<9; i++)
    {
        for(j=3; j<6; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the eighth group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }
    for(i=0; i<10; i++)
        count[i]=0;

    for(i=6; i<9; i++)
    {
        for(j=6; j<9; j++)
        {
            count[sudoku[i][j]]++;

            if(count[sudoku[i][j]]>1)
            {
                if(flag==0)
                {
                    wrong_sol();
                }

                if(count[0]==0)
                {
                    SetConsoleTextAttribute(hConsole, yellow);
                    printf("%d is repeated number in the ninth group\n",sudoku[i][j]);
                    flag=1;
                }
            }

        }

    }


    if(flag==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void wrong_sol()
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    system("cls");
    print_PUZZLE();
    SetConsoleTextAttribute(hConsole, red);
    printf("\n    wrong solution");
    printf("\n    ______________\n\n\n");
    printf("     *         *\n");
    printf("      *       *\n");
    printf("       *     *\n");
    printf("        *   *\n");
    printf("         * *\n");
    printf("          *\n");
    printf("         * *\n");
    printf("        *   *\n");
    printf("       *     *\n");
    printf("      *       *\n");
    printf("     *         *\n");

    SetConsoleTextAttribute(hConsole, green);
    printf("\n\nmistakes :\n\n");
    SetConsoleTextAttribute(hConsole, yellow);
    return ;
}

void correct_sol()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;


    system("cls");
    print_PUZZLE();
    SetConsoleTextAttribute(hConsole, green);
    printf("\n    congratulation");
    printf("\n    ______________\n\n\n");



    printf("                *\n");
    printf("               *\n");
    printf("              *\n");
    printf("             *\n");
    printf("            *\n");
    printf("           *\n");
    printf("      *   *\n");
    printf("      *  *\n");
    printf("      * *\n");
    printf("      *\n");
    SetConsoleTextAttribute(hConsole, yellow);
    return ;
}


void print_PUZZLE ()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int red = FOREGROUND_RED | FOREGROUND_INTENSITY;
    const int green = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    const int yellow = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;

    /* SetConsoleTextAttribute(hConsole, red);
     printf("This is red text.\n");
     SetConsoleTextAttribute(hConsole, green);
     printf("This is green text.\n");
     SetConsoleTextAttribute(hConsole, yellow);
     printf("This is yellow text.\n");
     SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
     Se6tConsoleTextAttribute(hConsole, yellow);*/



    int flag =0;
    int i,j,k;
    SetConsoleTextAttribute(hConsole, red);
    printf("\n        PUZZLE\n\n");
    SetConsoleTextAttribute(hConsole, yellow);
    for (i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(j==3||j==6)
            {
                SetConsoleTextAttribute(hConsole, yellow);
                printf("| ");
            }


            if(sud_flag[i][j])
            {
                SetConsoleTextAttribute(hConsole, red);
                printf("%d ",sudoku[i][j]);
            }
            else
            {
                SetConsoleTextAttribute(hConsole, yellow);
                printf("%d ",sudoku[i][j]);

            }

            if(j==8)
            {
                SetConsoleTextAttribute(hConsole, yellow);
                printf("|\n");
            }

        }
        if(flag==2||flag==5||flag==8)
        {
            SetConsoleTextAttribute(hConsole, yellow);
            printf("______________________\n\n");
        }
        flag++;
    }
}
