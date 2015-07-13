#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int compareVersion(string version1, string version2)
{
	while (1)
	{
		int v1,v2;
		if (version1.empty())
		{
			v1 = 0;
		}
		else
		{
			int index1 = version1.find_first_of('.');
			if (index1 == string::npos)
			{
				v1 = atoi(version1.c_str());
				version1 = "";
			}
			else
			{
				v1 = atoi(version1.substr(0,index1).c_str());
				version1 = version1.substr(index1+1);
			}
		}
		
		if (version2.empty())
		{
			v2 = 0;
		}
		else
		{
			int index2 = version2.find_first_of('.');
			if (index2 == string::npos)
			{
				v2 = atoi(version2.c_str());
				version2 = "";
			}
			else
			{
				v2 = atoi(version2.substr(0,index2).c_str());
				version2 = version2.substr(index2+1);
			}
		}		

		if (v1 < v2)
		{
			return -1;
		}
		else if (v1 > v2)
		{
			return 1;
		}
		else if (version1.empty() && version2.empty())
		{
			return 0;
		}
	}
}

int main()
{
	int res = compareVersion("1","1.0");
	return 1;
}