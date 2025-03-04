#include <iostream>
using namespace std;

int main()
{
	string T = "voicenotereceived";
	string P = "note";
	int l_T = T.length();
	int l_P = P.length();
	int max_substr = l_T - l_P + 1;
	int found = -1;

	int j;
	for (int i = 0; i < max_substr; i++)
	{
		for (j = 0; j < l_P; j++)
			if (T[i + j] != P[j])
				break;

		if (j == l_P)
		{
			found = i;
			break;
		}
	}

	if (found != -1)
		cout << "Matched pattern at index " << found << endl;
	return 0;
}