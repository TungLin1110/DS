#include<iostream>
using namespace std;
class SparseMatrix
{
public:
	SparseMatrix(int r, int c, int t);
	SparseMatrix TradictionalTranspose();
	SparseMatrix Transpose();
	SparseMatrix FastTranspose();
private:
	int rows, cols, terms, capacity;
	MatrixTerm*smArray;
};
class SparseMatrix;
class MatrixTerm
{
	friend class SparseMatrix;
private:
	int row, col, value;
};
SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix b(cols, rows, terms);
	if (terms > 0)
	{
		int currentB = 0;
		for (int c = 0; c < cols; c++)
			for (int i = 0; i < terms; i++)
				if (smArray[i].col == c)
				{
					b.smArray[currentB].row = c;
					b.smArray[currentB].col = smArray[i].row;
					b.smArray[currentB++].value = smArray[i].value;
				}
	}
	return b;
}
SparseMatrix SparseMatrix::FastTranspose()
{
	SparseMatrix b(cols, rows, terms);
	if (terms > 0)
	{
		int *rowSize = new int[cols];
		int *rowStart = new int[cols];
		fill(rowSize, rowSize + cols, 0);
		for (int i = 0; i < terms; i++)rowSize[smArray[i].col]++;
		rowStart[0] = 0;

		for (int i = 0; i < cols; i++)rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
		for (int i = 0; i < terms; i++)
		{
			int j = rowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			rowStart[smArray[i].col]++;
		}
		delete[] rowSize;
		delete[] rowStart;
	}
	return b;
}





