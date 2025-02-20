#include <iostream>
using namespace std;

int main()
{
	string str = "voicenotereceived";
	string pattern = "note";
	int l_str = str.length();
	int l_pattern = pattern.length();
	int max_substr = l_str - l_pattern + 1;
	int found = -1;

	int j;
	for (int i = 0; i < max_substr; i++)
	{
		for (j = 0; j < l_pattern; j++)
			if (str[i + j] != pattern[j])
				break;

		if (j == l_pattern)
		{
			found = i;
			break;
		}
	}

	(found == -1) ? cout << "Pattern not found" : cout << "Matched pattern at index " << found;
	cout << endl;
	return 0;
}