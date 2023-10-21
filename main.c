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


int RandomInteger() {
    // 設定亂數種子以確保每次運行產生不同的隨機數
    srand(time(NULL));

    // 使用rand()函數生成0到3之間的隨機整數
    int randomValue = rand() % 4;

    //printf("隨機整數: %d\n", randomValue);

    return randomValue;
}

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
                        attack[piece.x - 1][piece.y] += 4;
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
                        attack[piece.x - 1][piece.y] += 4;
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
        return 3; //draw
    else if (survive_a > survive_b)
        return 1; // a win
    else
        return 2; // b win
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

int main()
{
    ChessPiece playerA[n];
    ChessPiece playerB[n];
    type_a[n];
    x_a[n];
    y_a[n];
    type_b[n];
    x_b[n];
    y_b[n];
    
    int** attack_a = create2DArray(BOARD_SIZE, BOARD_SIZE);
    int** attack_b = create2DArray(BOARD_SIZE, BOARD_SIZE);
    int** blood_a = create2DArray(BOARD_SIZE, BOARD_SIZE);
    int** blood_b = create2DArray(BOARD_SIZE, BOARD_SIZE);
    
    //input (chess in same team cannot place in the same position)
    for (int i = 0;i < n; i++){
        printf("playerA chess num %d\n", i+1);
        printf("type: ");
        type_a[i] = RandomInteger();
        printf("%d\n", type_a[i])
        printf("(x,y): ");
        x_a[i] = RandomInteger();
        y_a[i] = RandomInteger();
        printf("%d %d\n", x_a[i], y_a[i])
        printf("playerB chess num %d\n", i+1);
        printf("type: ");
        scanf("%d", &(playerB[i].type));
        printf("(x,y): ");
        scanf("%d %d", &(playerB[i].x), &(playerB[i].y));
    }
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
    if (winner == 1)
        printf("winner A.\n");
    else if (winner == 2)
        printf("winner B.\n");
    else
        printf("draw.\n");
    
    free2DArray(attack_a, BOARD_SIZE);
    free2DArray(attack_b, BOARD_SIZE);
    free2DArray(blood_a, BOARD_SIZE);
    free2DArray(blood_b, BOARD_SIZE);
    
    return 0;
}
