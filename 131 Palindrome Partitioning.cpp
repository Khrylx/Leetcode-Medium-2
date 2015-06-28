#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void generate(vector<vector<string>>& solutions, vector<vector<bool>>& P, int index, string& s, vector<string>& curSol)
{
	int N = s.length();
	if (index == N)
	{
		solutions.push_back(curSol);
		return;
	}

	for (int i = index; i < N; i++)
	{
		if (P[index][i])
		{
			curSol.push_back(s.substr(index,i-index+1));
			generate(solutions,P,i+1,s,curSol);
			curSol.pop_back();
		}
	}
}

vector<vector<string>> partition(string s)
{
	int N = s.length();
	vector<vector<bool>> P(N,vector<bool>(N,false));

	for (int i = 0; i < N; i++)
	{
		P[i][i] = true;
		int lb = i-1;
		int ub = i+1;
		while (lb >= 0 && ub < N && s[lb] == s[ub])
		{
			P[lb][ub] = true;
			lb--;
			ub++;
		}

		lb = i;
		ub = i+1;
		while (lb >= 0 && ub < N && s[lb] == s[ub])
		{
			P[lb][ub] = true;
			lb--;
			ub++;
		}
	}

	vector<vector<string>> solutions;
	vector<string> curSol;
	
	generate(solutions,P,0,s,curSol);

	return solutions;
}

int main()
{
	vector<vector<string>> solutions = partition("aab");

	return 1;
}