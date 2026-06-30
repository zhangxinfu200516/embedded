#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s = "loveleetcccode";
	char C = 'e';
	vector<int> record;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == C)
		{
			record.push_back(i);
		}
	}
	vector<int> result(s.size(), INT_MAX);
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < record.size(); j++)
		{
			result[i] = min(result[i], abs(i - record[j]));
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}