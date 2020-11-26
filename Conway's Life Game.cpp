#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
using namespace std;
int height= 50;
int width= 180;
int cells[50][180];
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void startup()
{
	int i, j;
	for ( i = 0; i < height; i++)
	{
		for ( j = 0; j < width; j++)
		{
			cells[i][j] = 1;
		}
	}
}
void UpdateWithoutInput()
{
	int newCells[50][180];
	int newBornNum;
	int i, j;
	for ( i = 1; i <= height-1; i++)
	{
		for ( j = 1; j <= width-1; j++)
		{
			newBornNum = cells[i - 1][j - 1] + cells[i - 1][j] + cells[i - 1][j + 1] + cells[i][j - 1] + cells[i][j + 1] + cells[i + 1][j - 1] + cells[i + 1][j] + cells[i + 1][j + 1];
			if (newBornNum == 3)
			{
				newCells[i][j] = 1;
			}
			else if (newBornNum == 2)
			{
				newCells[i][j] = cells[i][j];
			}
			else
				newCells[i][j] = 0;
		}
	}
	for (i = 1; i <= height - 1; i++)
	{
		for ( j = 1; j <= width-1 ; j++)
		{
			cells[i][j] = newCells[i][j];
		}
	}
}
void show()
{
	gotoxy(0, 0);
	int i, j;
	for ( i = 1; i <= height-1; i++)
	{
		for ( j = 1; j <= width-1; j++)
		{
			if (cells[i][j]==1)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
void UpdateWithInput()
{
}
int main()
{
	startup();
	while (1)
	{
		show();
		UpdateWithoutInput();
		UpdateWithInput();
	}
	return 0;
}
