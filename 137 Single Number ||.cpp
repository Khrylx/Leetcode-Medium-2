#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int singleNumber(vector<int>& nums) 
{
	int zero = 0xFFFFFFFF;
	int one = 0;
	int two = 0;
	int newZ;
	int num;
	int rNum;

	for (int i = 0; i < nums.size(); i++)
	{
		num = nums[i];
		rNum = ~num;
		newZ = (two&num) | (zero&rNum);
		two = (one&num) | (two&rNum);
		one = (zero&num) | (one&rNum);
		zero = newZ;
	}

	return one;
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