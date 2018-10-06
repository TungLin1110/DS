#include<iostream>
using namespace std;

class List
{
public:
	List()
	{
		cout << "k=";
		cin >> k;
		Setnode();
	}
	void Setnode()
	{
														//呼叫輸入值
	
		
		createnode = new struct node;
		createnode->value = 1;

		firstnode = createnode;
		currentptr = createnode;
		first = firstnode;

		for (int i = 0; i < 2 * k - 1; i++)
		{
			createnode = new struct node;
			createnode->value = 0;
			createnode->llink = NULL;

			createnode->value = i + 2;
			currentptr->llink = createnode;
			currentptr = currentptr->llink;
		}
		currentptr->llink = first;							//接到開頭



															/*
															struct node *deletenode;
															struct node *beforenode;
															deletenode = first;
															beforenode = first;
															for (int i = 1; i < 4; i++)
															{
															deletenode = deletenode->llink;
															}
															for (int i = 1; i < 3; i++)
															{
															beforenode = beforenode->llink;
															}

															beforenode->llink = beforenode->llink->llink;
															delete deletenode;
															first= beforenode->llink;

															deletenode = first;
															beforenode = first;
															for (int i = 1; i < 4; i++)
															{
															deletenode = deletenode->llink;
															}

															for (int i = 1; i < 3; i++)
															{
															beforenode = beforenode->llink;
															}

															beforenode->llink = beforenode->llink->llink;

															delete deletenode;
															*/



		/*													//檢查是否有circular 
		currentptr = firstnode;
		for (int i = 0; i < 2 * k; i++)
		{
			cout << currentptr->value << endl;
			currentptr = currentptr->llink;
		}
		*/
	}
	int Deletenode()
	{
		
		deletenode = first;
		beforenode = first;
		for (int i = 1; i < n; i++)
		{
			deletenode = deletenode->llink;
		}
		for (int i = 1; i < n-1; i++)
		{
			beforenode = beforenode->llink;
		}

		
		if (deletenode->value <= k)
		{
			return 0;
		}
		
		else
		{
			beforenode->llink = beforenode->llink->llink;
			delete deletenode;
			first = beforenode->llink;
			return 1;
		}
		


	}
	void Findsol()
	{
		n = k;
		while (count != k)
		{
			n++;
			Setnode();
			count = 0;
			while (Deletenode() == 1)
			{
				count++;
				if (count == k)
					cout << n;
			}
		}	
	}



private:
	int k, n,count;
	struct node
	{
		int value;
		struct node* llink;
	};
	struct node *firstnode,*currentptr,*first, *createnode;
	struct node *deletenode, *beforenode;
};
int main()
{
	List a;
	a.Findsol();

}