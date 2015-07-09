#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int evalRPN(vector<string>& tokens) {
	stack<int> S;

	for (int i = 0; i < tokens.size(); i++)
	{
		if (tokens[i] == "+")
		{
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			S.push(a+b);
		}
		else if (tokens[i] == "-")
		{
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			S.push(b-a);
		}
		else if (tokens[i] == "*")
		{
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			S.push(a*b);
		}
		else if (tokens[i] == "/")
		{
			int a = S.top();
			S.pop();
			int b = S.top();
			S.pop();
			S.push(b/a);
		}
		else
		{
			S.push(atoi(tokens[i].c_str()));
		}
	}

	return S.top();
}

int main()
{
	int N;
	cin >> N;
	vector<string> tokens(N);
	for (int i = 0; i < N; i++)
	{
		cin >> tokens[i];
	}

	cout << evalRPN(tokens) <<endl;
	return 1;
}