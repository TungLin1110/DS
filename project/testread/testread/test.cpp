#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main()
{
	ifstream in;
	in.open("p2.txt");
	int line[5];
	while (cin.getline(line,5))
	{
		cout << line << endl;
		
	}
	in.close();
	system("pause");
}