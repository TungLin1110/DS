#include<iostream>
#include<fstream>

using namespace std;

int main() {
	ifstream fin0("file_A.txt");
	if (!fin0) {
		cout << "無法讀入檔案\n";
		return 0;
	}
	int  count = 0;
	char c;
	while (c != EOF)
	{
		c = fgetc(fin0);  if (c == '\n')  count++;
	}
	fin0.close();

	int num[5][3];
	ifstream fin("file_A.txt");
	if (!fin) {
		cout << "無法讀入檔案\n";
		system("pause");
		return 0;
	}
	for (int m = 0; m <= 0; m++)
		for (int n = 0; n <= 1; n++)
			fin >> num[m][n];
	//len = num[0][0] * num[0][1];

	
	for (int i = 1; i <= 4; i++)
		for (int k = 0; k <= 2; k++)
			fin >> num[i][k];
	fin.close();
	for (int m =0; m <= 0; m++)
		for (int n = 0; n <= 1; n++)
		{cout << num[m][n];
}
	cout << endl;
	for (int i = 1; i <= 4; i++){

		for (int k = 0; k <= 2; k++)
		{
			cout << num[i][k];
		}
		cout << endl;
	}

	return 0;
}
/*
int  Count = 0;
while (c != EOF)
{
	c = fgetc(RecFile);  if (c == '\n')  Count++;
}*/