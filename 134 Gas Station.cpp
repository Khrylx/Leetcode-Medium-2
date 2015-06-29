#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
	int start = 0;
	int end = 0;
	int sum = 0;

	while (1)
	{
		sum += gas[end]-cost[end];
		end = (end+1) % gas.size();

		if (sum < 0){
			if (end <= start)
				return -1;
			start = end;
			sum = 0;
		}
		else if (end == start)
			return start;
	}
}

int main()
{
	return 1;
}