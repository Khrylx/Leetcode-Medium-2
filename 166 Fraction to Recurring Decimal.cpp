#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

string fractionToDecimal(int numerator, int denominator) 
{
	long long N = numerator;
	long long D = denominator;

	if (N == 0)
		return "0";

	string s;

	if (N < 0 && D >0 )
	{
		N = -N;
		s.push_back('-');
	}
	if (N > 0 && D < 0)
	{
		D = -D;
		s.push_back('-');
	}

	if (N == D)
		return "1";
	else
	{
		s += to_string(N / D);
		if (N % D == 0)
			return s;

		s.push_back('.');
		N = N % D * 10;
	}

	

	unordered_map<long long,long long> M;
	int index = s.length();
	while (1)
	{
		unordered_map<long long,long long>::iterator itr = M.find(N);
		if (itr == M.end())
		{
			s.push_back('0' + N / D);
			M.insert(pair<long long,long long>(N,index));
			index++;
			N =  N % D * 10;
			if (N == 0)
				return s;
		}
		else
		{
			int index = itr->second;
			s.insert(index,1,'(');
			s.push_back(')');
			return s;
		}
	}

	return s;
}

int main()
{
	string s = fractionToDecimal(-50,8);
	return 1;
}