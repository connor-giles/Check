#include <stdio.h>
#include <stdbool.h>


//FUNCTION PROTOTYPES
void PrintChessboard(char[8][8]);
void FindKing(int*, int*, char[8][8]);
int CheckRook(int, int, int, int, char[8][8]);
int CheckKnight(int, int, char[8][8]);
int CheckQueen(int, int, char[8][8]);
int CheckKing(int, int, char[8][8]);
int CheckBishop(int, int, int, int, char[8][8]);
int CheckPawn(int, int, char[8][8]);



int main()
{
    char chessBoard[8][8]; //creates the character array for the chessboard

    char piece = ' ';
    int row = 0;
    int column = 0;

    int kingCol = 0;
    int kingRow = 0;
    int numberOfChecks = 0; //variable to keep track of number of pieces that have black king in check


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

    //PrintChessboard(chessBoard);
    FindKing(&kingRow, &kingCol, chessBoard);

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
                numberOfChecks += CheckQueen(i,j,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE ROOK
            else if(chessBoard[i][j] == 'R')
            {
                numberOfChecks += CheckRook(i,j,kingRow,kingCol,chessBoard);
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE BISHOP
            else if(chessBoard[i][j] == 'B')
            {
                numberOfChecks += CheckBishop(i,j,kingRow,kingCol,chessBoard);
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

int CheckRook(int currentRow, int currentColumn, int kRow, int kCol, char cBoard[8][8])
{
    //IMPLIES THE ROOK IS NOT IN THE SAME ROW OR COLUMN AS THE KING AND HAS NO CHANCE TO PUT IT IN CHECK
    if(currentRow != kRow && currentColumn != kCol)
        return 0;

    //IMPLIES THE ROOK AND THE KING SHARE THE SAME ROW AND HAVE THE POTENTIAL TO BE IN CHECK
    else if(currentRow == kRow)
    {
        //check only that row
        if(kCol > currentColumn)
        {
            //CHECKS THE COLUMN IN ASCENDING ORDER
            while(currentColumn < 8)
            {
                if(cBoard[currentRow][currentColumn + 1] == 'k') //implies black king is found
                    return 1;

                //implies there is a black piece in the way
                else if(cBoard[currentRow][currentColumn + 1] > 'a' && cBoard[currentRow][currentColumn + 1] < 'z')
                    return 0;

                //implies there is a white piece in the way
                else if(cBoard[currentRow][currentColumn + 1] > 'A' && cBoard[currentRow][currentColumn + 1] < 'Z')
                    return 0;

                //moves the check to next highest square
                else
                    currentColumn++;

            }//end ascending column while
        }

        else //implies the kings column is less than the current column
        {
            //CHECKS THE COLUMN IN DESCENDING ORDER
            while(currentColumn >= 0)
            {
                if(cBoard[currentRow][currentColumn - 1] == 'k') //implies black king is found
                    return 1;

                //implies there is a black piece in the way
                else if(cBoard[currentRow][currentColumn - 1] > 'a' && cBoard[currentRow][currentColumn - 1] < 'z')
                    return 0;

                //implies there is a white piece in the way
                else if(cBoard[currentRow][currentColumn - 1] > 'A' && cBoard[currentRow][currentColumn - 1] < 'Z')
                    return 0;

                //moves the check to next lowest square
                else
                    currentColumn--;

            }//end descending column while
        }



    }

    //IMPLIES THE ROOK AND THE KING SHARE THE SAME COL AND HAVE THE POTENTIAL TO BE IN CHECK
    else if(currentColumn == kCol)
    {
        //check only that col
        if(kRow > currentRow)
        {
            //CHECKS THE COLUMN IN ASCENDING ORDER
            while(currentRow < 8)
            {
                if(cBoard[currentRow + 1][currentColumn] == 'k') //implies black king is found
                    return 1;

                //implies there is a black piece in the way
                else if(cBoard[currentRow + 1][currentColumn] > 'a' && cBoard[currentRow + 1][currentColumn] < 'z')
                    return 0;

                //implies there is a white piece in the way
                else if(cBoard[currentRow + 1][currentColumn] > 'A' && cBoard[currentRow + 1][currentColumn] < 'Z')
                    return 0;

                //moves the check to next highest square
                else
                    currentRow++;

            }//end ascending row while
        }

        else //implies that the kings row is less than the rooks
        {
            while(currentRow >= 0)
            {
                if(cBoard[currentRow - 1][currentColumn] == 'k') //implies black king is found
                    return 1;

                //implies there is a black piece in the way
                else if(cBoard[currentRow - 1][currentColumn] > 'a' && cBoard[currentRow - 1][currentColumn] < 'z')
                    return 0;

                //implies there is a white piece in the way
                else if(cBoard[currentRow - 1][currentColumn] > 'A' && cBoard[currentRow - 1][currentColumn] < 'Z')
                    return 0;

                //moves the check to next lowest square
                else
                    currentRow--;

            }//end descending row while
        }

    }

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

int CheckQueen(int currentRow, int currentColumn, char cBoard[8][8])
{

}

int CheckBishop(int currentRow, int currentColumn, int kRow, int kCol, char cBoard[8][8])
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

void FindKing(int *kRow, int *kCol, char cBoard[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if(cBoard[i][j] == 'k')
            {
                *kRow = i;
                *kCol = j;
            }
        }
    }
}


