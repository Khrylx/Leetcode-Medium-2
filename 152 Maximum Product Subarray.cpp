#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int maxProduct(vector<int>& nums) 
{
	int maxP = -99999;
	int uP = 0;
	int lP = 0;

	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] == 0)
		{
			uP = 0;
			lP = 0;
			maxP = max(maxP,0);
			continue;
		}
		else if (nums[i] > 0)
		{
			if (uP == 0)
				uP = nums[i];
			else
				uP = uP*nums[i];

			if (lP != 0)
				lP = lP*nums[i];
		}
		else
		{
			int oLP = lP;
			if (uP != 0)
				lP = uP*nums[i];
			else
				lP = nums[i];

			if (oLP != 0)
				uP = oLP*nums[i];
			else
				uP = 0;
		}

		if (uP != 0)
		{
			maxP = max(maxP,uP);
		}
		else if (lP != 0)
		{
			maxP = max(maxP,lP);
		}
		

	}

	return maxP;
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
	int res = maxProduct(nums);
	return 1;
}