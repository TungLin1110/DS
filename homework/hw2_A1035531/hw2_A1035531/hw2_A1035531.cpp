#include<iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <ctime>
using namespace std;
class Tradictional
{
public:
	Tradictional();
	virtual void read();
	virtual void transpose();
	virtual void print();
private:
	int count;
	char *buffer;
	int **tmp;
	int **transAr;
	int **Ar;
	double duration;
};
Tradictional::Tradictional()
{
	count = 0;
}
void Tradictional::read()
{
	fstream file_read;
	file_read.open("p2.in.txt");
	char *buffer = new char[50];
	int i = 0, j = 0;
	int R = 50;
	int C = 3;
	tmp = new int *[R];
	for (int i = 0; i < R; i = i + 1) {
		tmp[i] = new int[C];
		for (int j = 0; j < C; j = j + 1) tmp[i][j] = 0;
	}

	while (file_read.getline(buffer, 50))
	{
		count++;
		stringstream ss3(buffer);
		while (ss3 >> tmp[i][j])
		{
			j++;
		}
		i++;
		j = 0;
	}
	
	delete[] buffer;
	
}
void Tradictional::transpose()
{
	int M = tmp[0][0];
	int N = tmp[0][1];
	Ar = new int *[M];
	for (int i = 0; i < M; i = i + 1) {
		Ar[i] = new int[N];
		for (int j = 0; j < N; j = j + 1) Ar[i][j] = 0;
	}
	transAr = new int *[N];
	for (int i = 0; i < N; i = i + 1) {
		transAr[i] = new int[M];
		for (int j = 0; j < M; j = j + 1) transAr[i][j] = 0;
	}
	for (int i = 1;i < count;i++)
	{
		int a = tmp[i][0];
		int b = tmp[i][1];
		Ar[a][b] = tmp[i][2];
	}


	clock_t start, finish;
	long     time = 10000000L;
	start = clock();
	while (time--)
		
		for (int i = 0;i < M;i++)
			for (int j = 0;j < N;j++)
				transAr[j][i] = Ar[i][j];


	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	for (int i = 0; i <M; i++)
		delete[] Ar[i];
	delete[] Ar;

}
void Tradictional::print()
{
	int R = 10;
	int C = 3;
	int **trans;
	trans = new int *[R];
	for (int i = 0; i < R; i = i + 1) {
		trans[i] = new int[C];
		for (int j = 0; j < C; j = j + 1) trans[i][j] = 0;
	}
	for (int i = 1;i < count;i++)
	{
		trans[i][0] = tmp[i][1];
		trans[i][1] = tmp[i][0];
		trans[i][2] = tmp[i][2];
	}

ofstream out("p2.out.txt");


	for (int m = 1; m<count;m++)
	{
		out << "(" << tmp[m][0] << "," << tmp[m][1] << "," << tmp[m][2] << ")  becomes " << "(" << trans[m][0] << "," << trans[m][1] << "," << trans[m][2] << ") in the transpose " << endl;
	}
	out << duration << endl;
	out.close();

}





class Transpose :public Tradictional
{
public:
	Transpose();
	virtual void read();
	virtual void transpose();
	virtual void print();
private:
	int count;
	char *buffer;
	int **tmp;
	int **transtmp;
	double duration;
};
Transpose::Transpose()
{
	count = 0;
}
void Transpose::read()
{
	fstream file_read;
	file_read.open("p2.in.txt");
	char *buffer = new char[50];
	int i = 0, j = 0;
	int R = 50;
	int C = 3;
	tmp = new int *[R];
	for (int i = 0; i < R; i = i + 1) {
		tmp[i] = new int[C];
		for (int j = 0; j < C; j = j + 1) tmp[i][j] = 0;
	}
	transtmp = new int *[R];
	for (int i = 0; i < R; i = i + 1) {
		transtmp[i] = new int[C];
		for (int j = 0; j < C; j = j + 1) transtmp[i][j] = 0;
	}

	while (file_read.getline(buffer, 50))
	{
		count++;
		stringstream ss3(buffer);
		while (ss3 >> tmp[i][j])
		{
			j++;
		}
		i++;
		j = 0;
	}
	
	delete[] buffer;
}
void Transpose::transpose()
{
	

	long     time = 10000000L;
	clock_t start, finish;
	start = clock();
	while (time--);
	{

		int currentB = 1;
		for (int c = 0; c < tmp[0][0]; c++)
			for (int i = 1; i < count; i++)
				if (tmp[i][1] == c)
				{
					transtmp[currentB][0] = c;
					transtmp[currentB][1] = tmp[i][0];
					transtmp[currentB++][2] = tmp[i][2];
				}

	}

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;


}
void Transpose::print()
{

	ofstream out("p2.out.txt",ios::out | ios::app);

	out << duration << endl;
	
	out.close();
}



class Fast_Transpose :public Tradictional
{
public:
	Fast_Transpose();
	virtual void read();
	virtual void transpose();
	virtual void print();
private:
	int count;
	char *buffer;
	int **tmp;
	int *rowSize;
	int *rowStart;
	int **transtmp;
	double duration;
};
Fast_Transpose::Fast_Transpose()
{
	count = 0;
}
void Fast_Transpose::read()
{
	fstream file_read;
	file_read.open("p2.in.txt");
	char *buffer = new char[50];
	int i = 0, j = 0;
	int R = 50;
	int C = 3;
	tmp = new int *[R];
	for (int i = 0; i < R; i = i + 1) {
		tmp[i] = new int[C];
		for (int j = 0; j < C; j = j + 1) tmp[i][j] = 0;
	}
	transtmp = new int *[R];
	for (int i = 0; i < R; i = i + 1) {
		transtmp[i] = new int[C];
		for (int j = 0; j < C; j = j + 1) transtmp[i][j] = 0;
	}
	while (file_read.getline(buffer, 50))
	{
		count++;
		stringstream ss3(buffer);
		while (ss3 >> tmp[i][j])
		{
			j++;
		}
		i++;
		j = 0;
	}
	
}
void Fast_Transpose::transpose()
{



	

	long     time = 10000000L;
	clock_t start, finish;
	start = clock();
	while (time--)
	{
	
	int col = tmp[0][1] - 1;
	rowSize = new int[col]();
	rowStart = new int[col]();
	

	for (int i = 1; i < count; i++)rowSize[tmp[i][1]]++;
	rowStart[0] = 0;
	for (int i = 1; i <= col; i++)rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
	for (int i = 1; i < count; i++)
	{
		int j = rowStart[tmp[i][1]];
		transtmp[j][0] = tmp[i][1];
		transtmp[j][1] = tmp[i][0];
		transtmp[j][2] = tmp[i][2];
		rowStart[tmp[i][1]]++;
	}

}

	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	

}
void Fast_Transpose::print()
{
	ofstream out("p2.out.txt", ios::out | ios::app);

	out << duration << endl;

	out.close();
}



int main()
{
	Tradictional a;
	a.read();
	a.transpose();
	a.print();

	
	Transpose b;
	b.read();
	b.transpose();
	b.print();

	Fast_Transpose c;
	c.read();
	c.transpose();
	c.print();
	
}
