#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define n 4

typedef struct {
    int type;
    int x;
    int y;
} ChessPiece;



int isOnBoardEdge(ChessPiece piece) {
    return (piece.x == 0 || piece.x == BOARD_SIZE - 1 || piece.y == 0 || piece.y == BOARD_SIZE - 1);
}

int** create2DArray(int rows, int cols) {
    // Allocate memory for the rows
    int** arr = (int**)malloc(rows * sizeof(int*));

    // Allocate memory for each row
    for (int i = 0; i < rows; i++) {
        arr[i] = (int*)malloc(cols * sizeof(int));
    }

    // Initialize the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = 0;
        }
    }

    return arr;  // Return a pointer to the 2D array
}

void updateAttack(ChessPiece piece, int** attack, int buff){
    
    if (piece.x >= 1 && piece.x <= 2 && piece.y >= 1 && piece.y <= 2)
    {
        switch (piece.type)
        {
            case 3:
                //ROGUE
                if (buff == 3) //LUCK
                {
                    attack[piece.x][piece.y] += 5;
                    attack[piece.x - 1][piece.y - 1] += 5;
                    attack[piece.x - 1][piece.y + 1] += 5;
                    attack[piece.x + 1][piece.y - 1] += 5;
                    attack[piece.x + 1][piece.y + 1] += 5; 
                }
                else if (buff == 4) //BALANCE
                {
                    attack[piece.x][piece.y] += 4;
                    attack[piece.x - 1][piece.y - 1] += 4;
                    attack[piece.x - 1][piece.y + 1] += 4;
                    attack[piece.x + 1][piece.y - 1] += 4;
                    attack[piece.x + 1][piece.y + 1] += 4; 
                }
                else{ 
                    attack[piece.x][piece.y] += 3;
                    attack[piece.x - 1][piece.y - 1] += 3;
                    attack[piece.x - 1][piece.y + 1] += 3;
                    attack[piece.x + 1][piece.y - 1] += 3;
                    attack[piece.x + 1][piece.y + 1] += 3; 
                }
                
                break;
            case 2:
                if (buff == 2)
                {
                    for (int i = -1;i <= 1;i++){
                        for (int j = -1;j <= 1;j++){
                            attack[piece.x + i][piece.y + j] += 5;
                        }   
                    }
                }
                else if (buff == 4)
                {
                    for (int i = -1;i <= 1;i++){
                        for (int j = -1;j <= 1;j++){
                            attack[piece.x + i][piece.y + j] += 3;
                        }   
                    }
                }
                else{
                    for (int i = -1;i <= 1;i++){
                        for (int j = -1;j <= 1;j++){
                            attack[piece.x + i][piece.y + j] += 2;
                        }
                    }
                }
                
                break;
            case 1:
                if (buff != 5)
                {
                    attack[piece.x][piece.y] += 4;
                    attack[piece.x][piece.y - 1] += 4;
                    attack[piece.x][piece.y + 1] += 4;
                    attack[piece.x - 1][piece.y] += 4;
                    attack[piece.x + 1][piece.y] += 4;
                }
                else{
                    attack[piece.x][piece.y] += 3;
                    attack[piece.x][piece.y - 1] += 3;
                    attack[piece.x][piece.y + 1] += 3;
                    attack[piece.x - 1][piece.y] += 3;
                    attack[piece.x + 1][piece.y] += 3;  
                }
                
                break;
            case 0:
                if (buff == 4)
                    attack[piece.x][piece.y] += 11;
                else
                    attack[piece.x][piece.y] += 10;
                break;
            default:
                break;
        }
    }
    else {
        
        if (piece.x == 3 && piece.y == 0)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x - 1][piece.y] += 5;
                        attack[piece.x][piece.y + 1] += 5;
                        attack[piece.x - 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x - 1][piece.y + 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x][piece.y + 1] += 3;
                        attack[piece.x - 1][piece.y + 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 20;
                        attack[piece.x - 1][piece.y] += 10;
                        attack[piece.x][piece.y + 1] += 10;
                        attack[piece.x - 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x - 1][piece.y] += 6;
                        attack[piece.x][piece.y + 1] += 6;
                        attack[piece.x - 1][piece.y + 1] += 3; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x - 1][piece.y + 1] += 2; 
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 4; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 9;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x][piece.y + 1] += 3; 
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                    break;
            }
        }
        else if (piece.x == 0 && piece.y == 0)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x + 1][piece.y] += 5;
                        attack[piece.x][piece.y + 1] += 5;
                        attack[piece.x + 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x + 1][piece.y + 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x][piece.y + 1] += 3;
                        attack[piece.x + 1][piece.y + 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 20;
                        attack[piece.x + 1][piece.y] += 10;
                        attack[piece.x][piece.y + 1] += 10;
                        attack[piece.x + 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x + 1][piece.y] += 6;
                        attack[piece.x][piece.y + 1] += 6;
                        attack[piece.x + 1][piece.y + 1] += 3; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x + 1][piece.y + 1] += 2; 
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 4; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 9;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x][piece.y + 1] += 3; 
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                    break;
            }
        }
        else if (piece.x == 0 && piece.y == 3)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x + 1][piece.y] += 5;
                        attack[piece.x][piece.y - 1] += 5;
                        attack[piece.x + 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x + 1][piece.y - 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3;
                        attack[piece.x + 1][piece.y - 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 20;
                        attack[piece.x + 1][piece.y] += 10;
                        attack[piece.x][piece.y - 1] += 10;
                        attack[piece.x + 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x + 1][piece.y] += 6;
                        attack[piece.x][piece.y - 1] += 6;
                        attack[piece.x + 1][piece.y - 1] += 3; 
                    }
                    else
                    {    
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x + 1][piece.y - 1] += 2; 
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 9;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3; 
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                    break;
            }
        }
        else if (piece.x == 3 && piece.y == 3)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x - 1][piece.y] += 5;
                        attack[piece.x][piece.y - 1] += 5;
                        attack[piece.x - 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x - 1][piece.y - 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3;
                        attack[piece.x - 1][piece.y - 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 20;
                        attack[piece.x - 1][piece.y] += 10;
                        attack[piece.x][piece.y - 1] += 10;
                        attack[piece.x - 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x - 1][piece.y] += 6;
                        attack[piece.x][piece.y - 1] += 6;
                        attack[piece.x - 1][piece.y - 1] += 3; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x - 1][piece.y - 1] += 2; 
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 12;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 9;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3; 
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                    break;
            }
        }
        else if (piece.x == 3 && piece.y != 0 && piece.y != 3)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 5;
                        attack[piece.x][piece.y - 1] += 5;
                        attack[piece.x][piece.y + 1] += 5;
                        attack[piece.x - 1][piece.y + 1] += 5;
                        attack[piece.x - 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x - 1][piece.y + 1] += 4;
                        attack[piece.x - 1][piece.y - 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3;
                        attack[piece.x][piece.y + 1] += 3;
                        attack[piece.x - 1][piece.y + 1] += 3;
                        attack[piece.x - 1][piece.y - 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x][piece.y - 1] += 10;
                        attack[piece.x][piece.y + 1] += 10;
                        attack[piece.x - 1][piece.y] += 5;
                        attack[piece.x - 1][piece.y - 1] += 5;
                        attack[piece.x - 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x][piece.y - 1] += 6;
                        attack[piece.x][piece.y + 1] += 6;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x - 1][piece.y - 1] += 3;
                        attack[piece.x - 1][piece.y + 1] += 3; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x - 1][piece.y] += 2;
                        attack[piece.x - 1][piece.y - 1] += 2;
                        attack[piece.x - 1][piece.y + 1] += 2;
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x][piece.y + 1] += 4; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3;
                        attack[piece.x][piece.y + 1] += 3;
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                        break;
            }    
        }
        else if (piece.x == 0 && piece.y != 0 && piece.y != 3)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 5;
                        attack[piece.x][piece.y - 1] += 5;
                        attack[piece.x][piece.y + 1] += 5;
                        attack[piece.x + 1][piece.y + 1] += 5;
                        attack[piece.x + 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x + 1][piece.y + 1] += 4;
                        attack[piece.x + 1][piece.y - 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3;
                        attack[piece.x][piece.y + 1] += 3;
                        attack[piece.x + 1][piece.y + 1] += 3;
                        attack[piece.x + 1][piece.y - 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x][piece.y - 1] += 10;
                        attack[piece.x][piece.y + 1] += 10;
                        attack[piece.x + 1][piece.y] += 5;
                        attack[piece.x + 1][piece.y - 1] += 5;
                        attack[piece.x + 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x][piece.y - 1] += 6;
                        attack[piece.x][piece.y + 1] += 6;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x + 1][piece.y - 1] += 3;
                        attack[piece.x + 1][piece.y + 1] += 3; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                        attack[piece.x + 1][piece.y] += 2;
                        attack[piece.x + 1][piece.y - 1] += 2;
                        attack[piece.x + 1][piece.y + 1] += 2;
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                        attack[piece.x][piece.y + 1] += 4; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3;
                        attack[piece.x][piece.y + 1] += 3;
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                    break;
            }
        }
        else if (piece.y == 0 && piece.x != 0 && piece.x != 3)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 5;
                        attack[piece.x - 1][piece.y] += 5;
                        attack[piece.x + 1][piece.y] += 5;
                        attack[piece.x - 1][piece.y + 1] += 5;
                        attack[piece.x + 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x - 1][piece.y + 1] += 4;
                        attack[piece.x + 1][piece.y + 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 3;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x - 1][piece.y + 1] += 3;
                        attack[piece.x + 1][piece.y + 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x - 1][piece.y] += 10;
                        attack[piece.x + 1][piece.y] += 10;
                        attack[piece.x][piece.y + 1] += 5;
                        attack[piece.x - 1][piece.y + 1] += 5;
                        attack[piece.x + 1][piece.y + 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x - 1][piece.y] += 6;
                        attack[piece.x + 1][piece.y] += 6;
                        attack[piece.x][piece.y + 1] += 3;
                        attack[piece.x - 1][piece.y + 1] += 3;
                        attack[piece.x + 1][piece.y + 1] += 3; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 2;
                        attack[piece.x - 1][piece.y + 1] += 2;
                        attack[piece.x + 1][piece.y + 1] += 2;
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y + 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x][piece.y + 1] += 3;
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                    break;
            }
        }
        else if (piece.y == 3 && piece.x != 0 && piece.x != 3)
        {
            switch (piece.type)
            {
                case 3:
                    if (buff == 3)
                    {
                        attack[piece.x][piece.y] += 5;
                        attack[piece.x - 1][piece.y] += 5;
                        attack[piece.x + 1][piece.y] += 5;
                        attack[piece.x - 1][piece.y - 1] += 5;
                        attack[piece.x + 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x - 1][piece.y - 1] += 4;
                        attack[piece.x + 1][piece.y - 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 3;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x - 1][piece.y - 1] += 3;
                        attack[piece.x + 1][piece.y - 1] += 3;
                    }
                        
                    break;
                case 2:
                    if (buff == 2)
                    {
                        attack[piece.x][piece.y] += 10;
                        attack[piece.x - 1][piece.y] += 10;
                        attack[piece.x + 1][piece.y] += 10;
                        attack[piece.x][piece.y - 1] += 5;
                        attack[piece.x - 1][piece.y - 1] += 5;
                        attack[piece.x + 1][piece.y - 1] += 5;
                    }
                    else if (buff == 4)
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x - 1][piece.y] += 6;
                        attack[piece.x + 1][piece.y] += 6;
                        attack[piece.x][piece.y - 1] += 3;
                        attack[piece.x - 1][piece.y - 1] += 3;
                        attack[piece.x + 1][piece.y - 1] += 3; 
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 4;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 2;
                        attack[piece.x - 1][piece.y - 1] += 2;
                        attack[piece.x + 1][piece.y - 1] += 2;
                    }
                        
                    break;
                case 1:
                    if (buff != 5)
                    {
                        attack[piece.x][piece.y] += 8;
                        attack[piece.x - 1][piece.y] += 4;
                        attack[piece.x + 1][piece.y] += 4;
                        attack[piece.x][piece.y - 1] += 4;
                    }
                    else
                    {
                        attack[piece.x][piece.y] += 6;
                        attack[piece.x - 1][piece.y] += 3;
                        attack[piece.x + 1][piece.y] += 3;
                        attack[piece.x][piece.y - 1] += 3;
                    }
                        
                    break;
                case 0:
                    if (buff == 4)
                        attack[piece.x][piece.y] += 11;
                    else
                        attack[piece.x][piece.y] += 10;
                    break;
                default:
                    break;
            }
        }
        
        
    }
    
}

void free2DArray(int** arr, int rows) {
    // Free memory for each row
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }

    // Free memory for the rows
    free(arr);
}

void updateBlood(ChessPiece piece, int** blood, int buff)
{
    
    switch(piece.type)
    {
        case 0:
            if (buff == 0)
                blood[piece.x][piece.y] = 13;
            else if (buff == 4)
                blood[piece.x][piece.y] = 11;
            else    
                blood[piece.x][piece.y] = 10;
            break;
        case 1:
            if (buff == 1)
                blood[piece.x][piece.y] = 7;
            else if (buff == 4)
                blood[piece.x][piece.y] = 6;
            else
                blood[piece.x][piece.y] = 5;
            break;
        case 2:
            if (buff == 4)
                blood[piece.x][piece.y] = 3;
            else
                blood[piece.x][piece.y] = 2;
            break;
        case 3:
            if (buff != 5)
                blood[piece.x][piece.y] = 6;
            else
                blood[piece.x][piece.y] = 5;
            break;
        default:
            break;
            
    }
    
}

int compete(int** attack_a, int** attack_b, int** blood_a, int** blood_b)
{
    int remain_a[BOARD_SIZE][BOARD_SIZE];
    int remain_b[BOARD_SIZE][BOARD_SIZE];
    
    int survive_a = 0;
    int survive_b = 0;
    
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            remain_b[i][j] = blood_b[i][j] - attack_a[i][j];
            remain_a[i][j] = blood_a[i][j] - attack_b[i][j];
        }
    }
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if (remain_b[i][j] > 0)
                survive_b++;    
            if (remain_a[i][j] > 0)
                survive_a++;
        }
    }
    
    if (survive_a == survive_b)
        return 2; //draw
    else if (survive_a > survive_b)
        return 0; // a win
    else
        return 1; // b win
}

int genBuff(ChessPiece piece[n])
{
    int buff;
    if (piece[0].type == 0 && piece[1].type == 0 && piece[2].type == 0 && piece[3].type == 0)
        buff = 0; //BRAVE
    else if (piece[0].type == 1 && piece[1].type == 1 && piece[2].type == 1 && piece[3].type == 1)
        buff = 1; //AGILE
    else if (piece[0].type == 2 && piece[1].type == 2 && piece[2].type == 2 && piece[3].type == 2)
        buff = 2;
    else if (piece[0].type == 3 && piece[1].type == 3 && piece[2].type == 3 && piece[3].type == 3)
        buff = 3;
    else if (piece[0].type != piece[1].type && piece[0].type != piece[2].type && piece[0].type != piece[3].type && piece[1].type != piece[2].type && piece[1].type != piece[3].type && piece[2].type != piece[3].type)
        buff = 4;
    else
        buff = 5;
    return buff;
}

int isCoordinateDuplicate(int coordinates[][3], int num, int x, int y) {
    // 檢查新生成的(x, y)是否與之前的(n-1)座標重複
    for (int i = 0; i < n; i++) {
        if (coordinates[i][1] == x && coordinates[i][2] == y) {
            return 1; // 重複
        }
    }
    return 0; // 不重複
}

void decimalToBinary(int decimal, FILE* file) {
    if (decimal == 0) 
	{
        fprintf(file,"00");
        return;
    }
    else if (decimal == 1)
    {
    	fprintf(file,"01");
    	return;
	}
	else if (decimal == 2)
	{
		fprintf(file,"10");
		return;
	}
	else if (decimal == 3)
	{
		fprintf(file,"11");
		return;
	}
	else
	{
		printf("Not correct input.\n");
		return;
	}
    

    
}

int main()
{
    ChessPiece playerA[n];
    ChessPiece playerB[n];
    int data[n][3];  // 用於存儲4組數據，每組包含棋子種類、x座標和y座標
    
    
    
    //input (chess in same team cannot place in the same position)
    FILE *file1;
    int x, y;
    file1 = fopen("pattern.txt", "w");  // 打開一個文件以寫入
    if (file1 == NULL) {
            printf("無法打開文件。\n");
            return 1;  // 錯誤退出
    }
    for (int k=0;k<10000;k++)
    {
        
        srand(time(NULL));  // 設置亂數種子
        
        int** attack_a = create2DArray(BOARD_SIZE, BOARD_SIZE);
    	int** attack_b = create2DArray(BOARD_SIZE, BOARD_SIZE);
    	int** blood_a = create2DArray(BOARD_SIZE, BOARD_SIZE);
    	int** blood_b = create2DArray(BOARD_SIZE, BOARD_SIZE);
        for (int i = 0; i < 4; i++)
        {
            
            // 生成棋子種類 (0 到 3)
            data[i][0] = rand() % 4;
            

            // 生成x座標和y座標，確保不與之前的組重複
            do {
                x = rand() % 4;
                y = rand() % 4;
            } while (isCoordinateDuplicate(data, i, x, y));
            
            data[i][1] = x;
            data[i][2] = y;
            
            playerA[i].type = data[i][0];
            playerA[i].x = data[i][1];
            playerA[i].y = data[i][2];
            printf("%d %d %d\n", playerA[i].type, playerA[i].x, playerA[i].y);
            
            for (int m=0;m<3;m++){
                int decimal = data[i][m];
                decimalToBinary(decimal, file1);    
            }
            
            

        }
        fprintf(file1, " ");
        for (int i = 0; i < 4; i++)
        {
            srand(time(NULL));  // 設置亂數種子
            // 生成棋子種類 (0 到 3)
            data[i][0] = rand() % 4;
            

            // 生成x座標和y座標，確保不與之前的組重複
            do {
                x = rand() % 4;
                y = rand() % 4;
            } while (isCoordinateDuplicate(data, i, x, y));
            
            data[i][1] = x;
            data[i][2] = y;
            
            playerB[i].type = data[i][0];
            playerB[i].x = data[i][1];
            playerB[i].y = data[i][2];
            printf("%d %d %d\n", playerB[i].type, playerB[i].x, playerB[i].y);
            
            for (int m=0;m<3;m++){
                int decimal = data[i][m];
                decimalToBinary(decimal, file1);
            }

        }
        fprintf(file1, " ");
        
        // buff
        int buff_a = genBuff(playerA);
        int buff_b = genBuff(playerB);
        // attack, blood
        for (int i = 0; i < n; i++){
            updateBlood(playerA[i], blood_a, buff_a);
            updateBlood(playerB[i], blood_b, buff_b);
            updateAttack(playerA[i], attack_a, buff_a);
            updateAttack(playerB[i], attack_b, buff_b);
        }
        // winner
        int winner = compete(attack_a, attack_b, blood_a, blood_b);
        if (winner == 0)
            printf("winner A.\n");
        else if (winner == 1)
            printf("winner B.\n");
        else
            printf("draw.\n");
            
        int decimal = winner;
        decimalToBinary(decimal, file1);
        fprintf(file1, "\n");

        
    
        free2DArray(attack_a, BOARD_SIZE);
        free2DArray(attack_b, BOARD_SIZE);
        free2DArray(blood_a, BOARD_SIZE);
        free2DArray(blood_b, BOARD_SIZE);
        
    }
    fclose(file1);
    
    
    
    
    
    return 0;
}
