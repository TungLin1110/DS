#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <cstdio>
using namespace std;
int term=50;													//初始化且使用全域變數
int terms = 0;
char down[20];
struct eng_int													//將文及轉換後的編嗎綁在一起
{
	char a;
	string code;
};
struct eng_int *aa = new struct eng_int[term - 2];
struct node {													//建立node
	int weight;
	 char value;
	const node *child0;
	const node *child1;
	node( char c = 0, int i = -1) {
		value = c;
		weight = i;
		child0 = 0;
		child1 = 0;
	}
	node(const node* c0, const node *c1) {
		value = 0;
		weight = c0->weight + c1->weight;
		child0 = c0;
		child1 = c1;
	}
	bool operator<(const node &a) const {
		return weight >a.weight;
	}
	
	void traverse(string code = "") const {
		
		

		if (child0) {
			child0->traverse(code + '0');
			child1->traverse(code + '1');
			
		}
		else {
			
			aa[terms].a = value;
			aa[terms].code = code;
			terms++;
			
		}
		
	}
	
};


void countchars(int *counts)
{
	for (int i = 0; i <256; i++)								//建立256個長度之陣列陣列位置為出現字母之ascii碼，值則為出現頻率
		counts[i] = 0;
	term = 0;
	fstream in;
	in.open("p5.in");
	char buffer[20];
	char a1[20] = { '\0' };
	
	int a2[20];
	int len;
	while (in.getline(buffer, sizeof(buffer), '\n')) {			//讀一行進buffer
																//cout << buffer << endl;

		if (buffer[1] > 60)
			for (int k = 0; k < strlen(buffer); k++)			//最後一行存入down
			{
				down[k] = buffer[k];
				len = strlen(buffer);
			}
		else
		{
			char c;												//讀取字母數字放入陣列
			c = buffer[0];
			int a = strlen(buffer) - 1;

			if (a == 1)
				counts[(int)c] = buffer[1] - '0';
			else
			{
				int a2value = 0;
				int n = 1;
				for (a; a >= 1; a--)
				{
					a2value = a2value + (buffer[a] - '0')*n;	//處理超過10位數之數字因為char將其分開存
					n = n * 10;
				}
				counts[(int)c] = a2value;
			}
		}
		term++;													//總共i行
	}
}
int main()
{
	int counts[256];
	countchars(counts);
	
	
	priority_queue < node > q;									//用queue 但這種用法是參考網路上的
	for (int i = 0; i <256; i++)
		if (counts[i])
			q.push(node(i, counts[i]));
	while (q.size() >1) {
		node *child0 = new node(q.top());						
		q.pop();
		node *child1 = new node(q.top());
		q.pop();
		q.push(node(child0, child1));
	}
	
	q.top().traverse();
	

	char newch[20];
	for (int i = 0; i < term - 2; i++)
	{
		newch[i] = aa[i].a;
	}
	for (int k = 1; k < term - 2; k++)								
		for (int j = k; j > 0; j--)
		{
			if (newch[j] < newch[j - 1])

			{

				newch[j] ^= newch[j - 1] ^= newch[j] ^= newch[j - 1];
				
			}
		}

	
	
	ofstream out;													//寫檔
	out.open("p5.out", ios::trunc);
	for (int i = 0; i < term - 2; i++)
	{
		for (int j = 0; j < term - 2; j++)
		{
			if (aa[j].a==newch[i])
				out << aa[j].a << aa[j].code << endl;
		}
	}
	out << endl;
	for (int i = 0; i < term - 2; i++)
	{
		for (int j = 0; j < term - 2; j++)
		{
			if (aa[j].a == down[i])
				out << aa[j].code;
		}
	}
	
	return 0;
}
