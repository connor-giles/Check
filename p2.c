#include <stdio.h>

//FUNCTION PROTOTYPES
void PrintChessboard(char[8][8]);
void CheckRook(int*, int, int, char[8][8]);
int CheckKnight(int, int, char[8][8]);
void CheckQueen(int*, int, int, char[8][8]);
int CheckKing(int, int, char[8][8]);
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
                numberOfChecks += CheckKnight(i,j,chessBoard);
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
                numberOfChecks += CheckKing(i,j,chessBoard);
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

int CheckKnight(int currentRow, int currentColumn, char cBoard[8][8])
{
    //Up-Left
    if(cBoard[currentRow - 2][currentColumn - 1] == 'k' && (currentRow - 2) < 8 && (currentRow - 2) >= 0 && (currentColumn - 1) < 8 && (currentColumn - 1) >= 0)
    {
        return 1;
    }

    //Up-Right
    if(cBoard[currentRow - 2][currentColumn + 1] == 'k' && (currentRow - 2) < 8 && (currentRow - 2) >= 0 && (currentColumn + 1) < 8 && (currentColumn + 1) >= 0)
    {
        return 1;
    }

    //Right-Up
    if(cBoard[currentRow - 1][currentColumn + 2] == 'k' && (currentRow - 1) < 8 && (currentRow - 1) >= 0 && (currentColumn + 2) < 8 && (currentColumn + 2) >= 0)
    {
        return 1;
    }

    //Right-Down
    if(cBoard[currentRow + 1][currentColumn + 2] == 'k' && (currentRow + 1) < 8 && (currentRow + 1) >= 0 && (currentColumn + 2) < 8 && (currentColumn + 2) >= 0)
    {
        return 1;
    }

    //Down-Right
    if(cBoard[currentRow + 2][currentColumn + 1] == 'k' && (currentRow + 2) < 8 && (currentRow + 2) >= 0 && (currentColumn + 1) < 8 && (currentColumn + 1) >= 0)
    {
        return 1;
    }

    //Down-Left
    if(cBoard[currentRow + 2][currentColumn - 1] == 'k' && (currentRow + 2) < 8 && (currentRow + 2) >= 0 && (currentColumn - 1) < 8 && (currentColumn - 1) >= 0)
    {
        return 1;
    }

    //Left-Down
    if(cBoard[currentRow + 1][currentColumn - 2] == 'k' && (currentRow + 1) < 8 && (currentRow + 1) >= 0 && (currentColumn - 2) < 8 && (currentColumn - 2) >= 0)
    {
        return 1;
    }

    //Left-Up
    if(cBoard[currentRow - 1][currentColumn - 2] == 'k' && (currentRow - 1) < 8 && (currentRow - 1) >= 0 && (currentColumn - 2) < 8 && (currentColumn - 2) >= 0)
    {
        return 1;
    }

    return 0;
}

int CheckKing(int currentRow, int currentColumn, char cBoard[8][8])
{
    //NW
    if(cBoard[currentRow - 1][currentColumn - 1] == 'k' && (currentRow - 1) < 8 && (currentRow - 1) >= 0 && (currentColumn - 1) < 8 && (currentColumn - 1) >= 0)
    {
        return 1;
    }

    //N
    if(cBoard[currentRow - 1][currentColumn] == 'k' && (currentRow - 1) < 8 && (currentRow - 1) >= 0 && (currentColumn) < 8 && (currentColumn) >= 0)
    {
        return 1;
    }

    //NE
    if(cBoard[currentRow - 1][currentColumn + 1] == 'k' && (currentRow - 1) < 8 && (currentRow - 1) >= 0 && (currentColumn + 1) < 8 && (currentColumn + 1) >= 0)
    {
        return 1;
    }

    //E
    if(cBoard[currentRow][currentColumn + 1] == 'k' && (currentRow) < 8 && (currentRow) >= 0 && (currentColumn + 1) < 8 && (currentColumn + 1) >= 0)
    {
        return 1;
    }

    //SE
    if(cBoard[currentRow + 1][currentColumn + 1] == 'k' && (currentRow + 1) < 8 && (currentRow + 1) >= 0 && (currentColumn + 1) < 8 && (currentColumn + 1) >= 0)
    {
        return 1;
    }

    //S
    if(cBoard[currentRow + 1][currentColumn] == 'k' && (currentRow + 1) < 8 && (currentRow + 1) >= 0 && (currentColumn) < 8 && (currentColumn) >= 0)
    {
        return 1;
    }

    //SW
    if(cBoard[currentRow + 1][currentColumn - 1] == 'k' && (currentRow + 1) < 8 && (currentRow + 1) >= 0 && (currentColumn - 1) < 8 && (currentColumn - 1) >= 0)
    {
        return 1;
    }

    //W
    if(cBoard[currentRow][currentColumn - 1] == 'k' && (currentRow) < 8 && (currentRow) >= 0 && (currentColumn - 1) < 8 && (currentColumn - 1) >= 0)
    {
        return 1;
    }

    return 0;

}




