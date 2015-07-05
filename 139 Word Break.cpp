#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_set<string> unmatch;
int lb;
int ub;

bool wordBreakHelper(string s,unordered_set<string>& wordDict)
{
	if (s.empty())
	{
		return true;
	}

	for (int i = lb; i <= ub; i++)
	{
		if (i <= s.length() && wordDict.count(s.substr(0,i)))
		{
			string newS = s.substr(i);
			if (unmatch.count(newS))
				continue;

			bool res = wordBreakHelper(newS,wordDict);
			if (res)
				return true;
			else
				unmatch.insert(newS);
		}
	}

	return false;
}

bool wordBreak(string s, unordered_set<string>& wordDict) 
{
	lb = 99999;
	ub = -1;

	for (unordered_set<string>::const_iterator itr = wordDict.begin(); itr != wordDict.end(); itr++)
	{
		lb = min(lb,(int)itr->length());
		ub = max(ub,(int)itr->length());
	}

	return wordBreakHelper(s,wordDict);
}

int main()
{
	string s = "dogcat1";
	unordered_set<string> wordDict;
	wordDict.insert("dog");
	wordDict.insert("cat");

	bool res = wordBreak(s,wordDict);
	return 1;
}