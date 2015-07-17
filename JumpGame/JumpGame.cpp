#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len=nums.size();
        if (len<1)
        {
        	return false;
        }
        int pos=0;
        int rest=nums[0];
        while(rest>0)
        {
        	pos++;
        	if (pos>=len-1)
        	{
        		return true;
        	}
        	rest--;
        	if (nums[pos]>rest)
        	{
        		rest=nums[pos];
        	}
        }
        if (pos>=len-1)
        {
        	return true;
        }
        else
        {
        	return false;
        }
    }
};
int main()
{
	//int a[]={2,3,1,1,4};
	int a[]={3,2,1,0,4};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution solution;
	if (solution.canJump(nums))
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	return 0;
}