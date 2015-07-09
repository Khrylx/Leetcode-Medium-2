#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void reverseWords(string &s) 
{
	int lb = s.find_first_not_of(' ');
	if (lb == string::npos)
		s = "";

	int rb = s.find_last_not_of(' ');

	int index = 0;
	bool spaceRead = false;
	for (int i = lb; i <= rb; i++)
	{
		if (s[i] != ' ')
		{
			s[index++] = s[i];
			spaceRead = false;
		}
		else if (!spaceRead)
		{
			s[index++] = ' ';
			spaceRead = true;
		}
	}
	s = s.substr(0,index);

	int index1 = 0;
	int index2;
	bool flag = true;
	while (flag)
	{
		index2 = s.find(' ',index1);
		if (index2 == string::npos)
		{
			index2 = s.length();
			flag = false;
		}
		int i = index1;
		int j = index2-1;
		while (i < j)
		{
			swap(s[i++],s[j--]);
		}
		index1 = index2+1;
	}

	reverse(s.begin(),s.end());
}

int main()
{
	string s = "  the   sky  is blue   ";
	reverseWords(s);
	
	return 1;
}