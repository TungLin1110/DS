#include <stack>
#include <iostream>
#include <fstream>
using namespace std;

class ratmaze
{
public:
	ratmaze()
	{
		fstream fin;											//第一次開檔 算大小
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
		cout << countrow << endl << countcol << endl;
		fin.close();
		maze = new char *[countrow + 2];					//建char maze(有牆)
		for (int i = 0; i < countrow + 2; i++)
		{
			maze[i] = new char[countcol + 2];
			for (int j = 0; j < countcol + 2; j++)
			{
				if (i == 0 || j == 0 || i == countrow + 1 || j == countcol + 1)
				{
					maze[i][j] = '1';
				}
				else
					maze[i][j] = '0';
			}
		}
		/*														//檢查maze
		for (int i = 0; i < countrow + 2; i++)
		{
		for (int j = 0; j < countcol + 2; j++)
		{
		cout << maze[i][j];
		}
		cout << endl;
		}
		*/
		fstream fin2;											//第2次開檔 存資料到maze
		fin2.open("p3.in.txt", ios::in);
		for (int i = 1; i <= countrow; i++)
		{
			for (int j = 1; j <= countcol; j++)
			{
				fin2 >> maze[i][j];
			}
		}
		fin2.close();
		///檢察存maze
		for (int i = 0; i < countrow + 2; i = i + 1)
		{
			for (int j = 0; j < countcol + 2; j = j + 1)
			{
				cout << maze[i][j];
			}
			cout << endl;
		}

		mark = new int *[countrow + 2];					//建int mark
		for (int i = 0; i < countrow + 2; i++)
		{
			mark[i] = new int[countcol + 2];
			for (int j = 0; j < countcol + 2; j++)
			{
				mark[i][j] = 0;
			}
		}
		for (int i = 0; i < countrow + 2; i = i + 1)			//maze->mark
		{
			for (int j = 0; j < countcol + 2; j = j + 1)
			{
				if (maze[i][j] == 's')
				{
					mark[i][j] = 2;
					px.push(i);									//找起點 放到stack
					py.push(j);
				}
				if (maze[i][j] == 'd')
					mark[i][j] = 3;
				if (maze[i][j] == '1')
					mark[i][j] = 1;
				if (maze[i][j] == '0')
					mark[i][j] = 0;
			}

		}

	}
	struct offsets
	{
		int a;
		int b;
	};
	void path()
	{
		int x = px.top();
		int y = py.top();


		for (int i = 0; i < 8; i++)
		{
			int g = x + move[i].a;
			int h = y + move[i].b;
			if (maze[g][h] == '0' && mark[g][h] == 0)
			{
				px.push(g);
				py.push(h);
				mark[g][h] = 1;
				cout << px.top();
				cout << py.top();
				path();
				break;
			}
			if (maze[g][h] == 3)
			{
				end();
				break;
			}
			/*else
			{
			px.pop();
			py.pop();
			mark[g][h] = 1;
			path();
			break;
			}*/
		}

	}
	void end()
	{
		cout << "a";
	}
private:
	char **maze;
	int **mark;
	stack<int>px;
	stack<int>py;
	offsets move[8] = { { -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 },{ -1,-1 } };
};
int main()
{
	ratmaze a;
	a.path();


}











