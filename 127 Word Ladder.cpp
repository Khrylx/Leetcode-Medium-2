#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int ladderLengthHelper(unordered_set<string>& s1, unordered_set<string>& s2, unordered_set<string>& wordDict, int level)
{
	if (s1.empty())
		return 0;

	unordered_set<string> s3;

	for (unordered_set<string>::const_iterator itr = s1.begin(); itr != s1.end(); itr++)
	{
		string word = *itr;
		for (int i = 0; i < itr->length(); i++)
		{
			char oldC = word[i];
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (c == oldC)
					continue;
				word[i] = c;

				if (s2.count(word))
				{
					return level;
				}
				if (wordDict.count(word))
				{
					s3.insert(word);
					wordDict.erase(word);
				}
			}
			word[i] = oldC;

		}
	}

	return s3.size() < s2.size() ? ladderLengthHelper(s3,s2,wordDict,level+1) : ladderLengthHelper(s2,s3,wordDict,level+1);
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict)
{
	unordered_set<string> s1;
	unordered_set<string> s2;
	s1.insert(beginWord);
	s2.insert(endWord);
	wordDict.erase(beginWord);
	wordDict.erase(endWord);

	return ladderLengthHelper(s1,s2,wordDict,2);

}

int main()
{
	unordered_set<string> set;
	set.insert("hot");
	set.insert("dot");
	set.insert("dog");
	set.insert("lot");
	set.insert("log");

	cout << ladderLength("hit","cog",set) <<endl;

	return 1;
}