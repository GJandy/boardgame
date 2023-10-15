# define Row 4
# define Col 4
#include <stdio.h>
#include <stdlib.h>

void Initboard(char board[Row][Col], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';	
		} 
	}
}

void Displayboard(char board[Row][Col], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i=0;i < row; i++)
	{
		for (j = 0;j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i< row - 1)
		{
			for (j=0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[Row][Col], int row, int col)
{
	int x = 0;
	int y = 0;
	int chess_type;
	int blood_A[4];
	int attack_A[4];
	int coor_A[4][2];
	int blood_B[4];
	int attack_B[4];
	int coor_B[4][2];
	
	for (int i = 0; i < 4; i++)
	{
		printf("A玩家下第%d棋, 請輸入棋子種類: ", i+1);
		scanf("%d", &chess_type);
		
		if (chess_type > 3)
		{
			printf("available number for chess type is 0,1,2,3.\n");
			i--;
			continue;
		}
		
		switch (chess_type)
		{
			case 0:
				blood_A[i] = 5;
				attack_A[i] = 3;
				break;
			case 1:
				blood_A[i] = 2;
				attack_A[i] = 2;
				break;
			case 2:
				blood_A[i] = 5;
				attack_A[i] = 3;
				break;
			case 3:
				blood_A[i] = 10;
				attack_A[i] = 10;
				break;
			default:
				break;	
		}
		printf("A玩家下第%d棋, 請輸入棋子座標: ", i+1);
		scanf("%d %d", &x, &y);
		coor_A[i][0] = x;
		coor_A[i][1] = y;
		
		printf("B玩家下第%d棋, 請輸入棋子種類: ", i+1);
		scanf("%d", &chess_type);
		
		if (chess_type > 3)
		{
			printf("available number for chess type is 0,1,2,3.\n");
			i--;
			continue;
		}
		
		switch (chess_type)
		{
			case 0:
				blood_B[i] = 5;
				attack_B[i] = 3;
				break;
			case 1:
				blood_B[i] = 2;
				attack_B[i] = 2;
				break;
			case 2:
				blood_B[i] = 5;
				attack_B[i] = 3;
				break;
			case 3:
				blood_B[i] = 10;
				attack_B[i] = 10;
				break;
			default:
				break;	
		}
		
		printf("B玩家下第%d棋, 請輸入棋子座標: ", i+1);
		scanf("%d %d", &x, &y);
		coor_B[i][0] = x;
		coor_B[i][1] = y;
	}
	
		
}
