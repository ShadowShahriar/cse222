#include <iostream>
#include <set>
using namespace std;

int main()
{
	int n = 9;
	int arr[81] = {0};
	for (int i = 0; i < n * n; i++)
		cin >> arr[i];

	int col_flag = 1;
	int row_flag = 1;
	int sub_flag = 1;

	for (int j = 0; j < 9; j++)
	{
		set<int> col;
		for (int i = j * 9; i < 9 + (j * 9); i++)
			col.insert(arr[i]);
		if (col.size() != 9)
		{
			col_flag = 0;
			break;
		}
	}

	for (int j = 0; j < 9; j++)
	{
		set<int> row;
		for (int i = j; i <= 72 + j; i += 9)
			row.insert(arr[i]);
		if (row.size() != 9)
		{
			row_flag = 0;
			break;
		}
	}

	for (int l = 0; l < 3; l++)
		for (int k = 0; k < 3; k++)
		{
			set<int> sub;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					sub.insert((arr[(j + (k * 3)) + ((i + (l * 3)) * 9)]));
			if (sub.size() != 9)
			{
				sub_flag = 0;
				break;
			}
		}

	cout << ((row_flag && col_flag && sub_flag) ? "YES" : "NO") << endl;
	return 0;
}
