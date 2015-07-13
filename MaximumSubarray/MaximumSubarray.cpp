#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len=nums.size();
        if (len==0)
        {
        	return 0;
        }
        int rec[len];
        rec[0]=nums[0];
        int result=nums[0];
        for (int i=1;i<len;i++)
        {
        	if (rec[i-1]>0)
        	{
        		rec[i]=nums[i]+rec[i-1];
        	}
        	else
        	{
        		rec[i]=nums[i];
        	}
        	if (rec[i]>result) result=rec[i];
        }
        return result;
    }
};
int main()
{
	int a[]={-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution solution;
	printf("%d\n",solution.maxSubArray(nums));
	return 0;
}