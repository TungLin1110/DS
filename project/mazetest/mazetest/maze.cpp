#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	fstream fin;
	char ch;
	int countrow = 1;
	int countcol = 0;
	fin.open("p3.in.txt", ios::in);
	if (!fin)
		cout << "aaa";
	else
	{
		while (!fin.eof())
		{
			fin.get(ch);
			if (ch == '\n')
				countrow++;
			else if (ch != '\n')
			{
				countcol++;
			}
		}
		}
	countcol = (countcol - 1) / countrow;
	countcol = (countcol + 1) / 2;
	cout << countrow<<endl<<countcol<<endl;
fin.close();

int **maze = new int *[countrow+2];
for (int i = 0; i < countrow + 2; i = i + 1)
{
	maze[i] = new int[countcol + 2];
	for (int j = 0; j < countcol + 2; j = j + 1)
	{
		if (i == 0 || j == 0 || i == countrow + 1 || j == countcol + 1)
		{
			maze[i][j] = 1;
		}
		else
			maze[i][j] = 0;
	}}
int **mark = new int *[countrow + 2];
for (int i = 0; i < countrow + 2; i = i + 1)
{
	maze[i] = new int[countcol + 2];
	for (int j = 0; j < countcol + 2; j = j + 1)
	{
			mark[i][j] = 0;
	}}


/*
fstream fin2;
fin2.open("p3.in.txt", ios::in);
for (int i = 1; i <= countrow; i++)
{
	for (int j = 1; j <= countcol; j++)
	{
		fin2 >> maze[i][j];
	}
}
fin2.close();
for (int i = 0; i < countrow + 2; i = i + 1){	for (int j = 0; j < countcol + 2; j = j + 1)	{
		cout << maze[i][j];
	}
	cout << endl;
}
*/





}