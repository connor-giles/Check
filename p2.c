#include <stdio.h>

//FUNCTION PROTOTYPES
void PrintChessboard(char[8][8]);
void CheckRook(int*, int, int, char[8][8]);
void CheckKnight(int*, int, int, char[8][8]);
void CheckQueen(int*, int, int, char[8][8]);
void CheckKing(int*, int, int, char[8][8]);
void CheckBishop(int*, int, int, char[8][8]);
int CheckPawn(int, int, char[8][8]);



int main()
{
    char chessBoard[8][8]; //creates the character array for the chessboard

    char piece = ' ';
    int row = 0;
    int column = 0;

    //populates the chessboard
    while(scanf("%c", &piece) && row != 8)
    {
        while(piece != '\n')
        {
            chessBoard[row][column] = piece;
            column++;
            break;
        }

        if(column == 8)
        {
            column = 0;
            row++;
        }

    }

    PrintChessboard(chessBoard);

    int numberOfChecks = 0; //variable to keep track of number of pieces that have black king in check


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE KNIGHT
            if(chessBoard[i][j] == 'N')
            {
                CheckKnight(&numberOfChecks,i,j,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE QUEEN
            else if(chessBoard[i][j] == 'Q')
            {
                CheckQueen(&numberOfChecks,i,j,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE ROOK
            else if(chessBoard[i][j] == 'R')
            {
                CheckRook(&numberOfChecks,i,j,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE BISHOP
            else if(chessBoard[i][j] == 'B')
            {
                CheckBishop(&numberOfChecks,i,j,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE PAWN
            else if(chessBoard[i][j] == 'P')
            {
                numberOfChecks += CheckPawn(i,j,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE KING
            else if(chessBoard[i][j] == 'K')
            {
                CheckKing(&numberOfChecks,i,j,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS AN EMPTY SPOT OR A BLACK PIECE
            else
            {
                continue;
            }

        }
    }




    //Prints the number of white pieces that have the black king in check
    printf("%d\n", numberOfChecks);








    return 0;
}

void PrintChessboard(char cBoard[8][8])
{
    //prints the array to check if it read the input correctly
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%c", cBoard[i][j]);
        }

        printf("\n");
    }
}

void CheckRook(int *numCheck, int currentRow, int currentColumn, char cBoard[8][8])
{
    //if(cBoard[currentRow + 1][currentColumn] == 'k' && (currentRow + 1) < 8 && (currentRow + 1) >= 0)
}

int CheckPawn(int currentRow, int currentColumn, char cBoard[8][8])
{
    if(cBoard[currentRow - 1][currentColumn - 1] == 'k' && (currentRow - 1) < 8 && (currentRow - 1) >= 0 && (currentColumn - 1) < 8 && (currentColumn - 1) >= 0)
    {
        return 1;
    }

    if(cBoard[currentRow - 1][currentColumn + 1] == 'k' && (currentRow + 1) < 8 && (currentRow - 1) >= 0 && (currentColumn + 1) < 8 && (currentColumn - 1) >= 0)
    {
        return 1;
    }

    return 0;

}

void CheckQueen(int *numCheck, int currentRow, int currentColumn, char cBoard[8][8])
{

}

void CheckBishop(int *numCheck, int currentRow, int currentColumn, char cBoard[8][8])
{

}

void CheckKnight(int *numCheck, int currentRow, int currentColumn, char cBoard[8][8])
{

}

void CheckKing(int *numCheck, int currentRow, int currentColumn, char cBoard[8][8])
{

}


void foo(int *x )
{
    // x is still a *copy* of foo()'s argument, but that copy *refers* to
    // the value as seen by the caller
    *x = 42;
}

