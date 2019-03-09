#include <stdio.h>

//FUNCTION PROTOTYPES
void PrintChessboard(char[8][8]);

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


    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE KNIGHT
            if(chessBoard[i][j] == 'N')
            {
                //checkKnight()
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE QUEEN
            else if(chessBoard[i][j] == 'Q')
            {
                //checkQueen()
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE ROOK
            else if(chessBoard[i][j] == 'R')
            {
                //checkRook()
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE BISHOP
            else if(chessBoard[i][j] == 'B')
            {
                //checkBishop()
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE PAWN
            else if(chessBoard[i][j] == 'P')
            {
                //checkPawn()
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS A WHITE KING
            else if(chessBoard[i][j] == 'K')
            {
                //checkKing()
            }

            //CHECKS IF THE PIECE AT THIS LOCATION IS AN EMPTY SPOT OR A BLACK PIECE
            else
            {
                continue;
            }

        }
    }













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
