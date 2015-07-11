#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int findPeakElement(vector<int>& nums) 
{
	if (nums.size() == 1)
	{
		return 0;
	}
	int left = 0;
	int right = (int)nums.size()-1;

	if (nums[left] > nums[left+1])
	{
		return left;
	}
	if (nums[right] > nums[right-1])
	{
		return right;
	}

	while (1)
	{
		int newPos = (left + right)/2;
		if (nums[newPos] > max(nums[newPos-1],nums[newPos+1]))
		{
			return newPos;
		}
		if (nums[newPos] < nums[newPos-1])
		{
			right = newPos;
		}
		else 
		{
			left = newPos;
		}
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);

	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}
	int sol = findPeakElement(nums);
	return 1;
}