#include <iostream>
#define m 3
using namespace std;

void multiplyMatrices(int A[m][m], int B[m][m], int C[m][m])
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < m; k++)
				C[i][j] += A[i][k] * B[k][j];
		}
}

void displayMatrix(int A[m][m])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

int main()
{
	int A[m][m] = {{5, 7, 7}, {6, 7, 7}, {5, 4, 6}};
	int B[m][m] = {{4, 4, 4}, {1, 1, 2}, {2, 7, 5}};
	int C[m][m];

	multiplyMatrices(A, B, C);
	displayMatrix(C);
	return 0;
}