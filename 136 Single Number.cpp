#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int singleNumber(vector<int>& nums) 
{
	for (int i = 1; i < nums.size(); i++)
	{
		nums[0] ^= nums[i];
	}

	return nums[0];
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);

	for (int i=0; i < N; i++)
	{
		cin >> nums[i];
	}
	
	int sol = singleNumber(nums);
	return 1;
}