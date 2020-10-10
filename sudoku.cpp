#include "SudokuAlgorithm.h"
#include <iostream>
#include <string>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int iMaxsol=100;
	if (argc == 2)
	{
	    iMaxsol = atoi(argv[1]);
		if (iMaxsol == 0)
        {
            printf("\n\033[31musage: sudoku 1000\n1000 is the max count of solves.\n\n\033[0m");
			return 0;
        }
    }

    CSudokuSolve ss;

    printf("\n\033[32mWelcom to Sudoku's world! - @Gaozilai (wx=qq=121997204)\n\033[0m");
    unsigned char btData[9*9];
    for (int i = 0; i < 9 ; i++)
    {
        std::string nc;
        bool bValid = false;
        while(bValid == false)
        {
            printf("\nPls input(space for blank): line %d = ", i + 1);
            std::getline(std::cin, nc);

            bValid = nc.length() >= 9;
            if (bValid)
            {
                for (int j = 0; j < 9 ; j++)
                {
                    if (!((nc[j] >= '0' && nc[j] <= '9') || nc[j] == ' '))
                    {
                        bValid = false;
                        break;
                    }
                }
            }
            if (bValid == false)
            {
                printf("\n\033[31mInput invalid!\n\033[0m");
            }
        }
        for (int j = 0; j < 9 ; j++)
        {
            btData[i * 9 + j] = (nc[j] == ' ' ? 0 : nc[j] - '0');
        }
    }

    printf("\n\n\033[31mSudoku puzzle is:");
    for (int i = 0; i < 81 ; i++)
    {
        if (i % 9 == 0)
        {
            printf("\n");
            if (i/9 == 3 || i/9 == 6)
            {
                printf("\n");
            }
        }
        if (btData[i] == 0)
        {
            printf("_ ");
        }
        else
        {
            printf("%d ", btData[i]);
        }
        if (i % 9 == 2 || i % 9 == 5)
        {
            printf("  ");
        }
    }
    printf("\n\n\n");

    int iSolves = ss.Calculate(btData, 9*9, iMaxsol);
    if (iSolves > 0)
    {
        for (int j = 0; j < iSolves ; j++)
        {
            char sz[100];
            sprintf(sz, "\033[%dmsolution %%d:", 32 + j % 6);
            printf(sz, j+1);
            unsigned char* pSolve = ss.GetSolve(j);
            for (int k = 0; k < 81 ; k++)
            {
                if (k % 9 == 0)
                {
                    printf("\n");
                    if (k/9 == 3 || k/9 == 6)
                    {
                        printf("\n");
                    }
                }
                printf("%d ", pSolve[k]);
                if (k % 9 == 2 || k % 9 == 5)
                {
                    printf("  ");
                }
            }
            printf("\n\n\n");
        }
    }
    else
    {
        printf("No solution!");
    }
    printf("\033[0m\n\n");
}

