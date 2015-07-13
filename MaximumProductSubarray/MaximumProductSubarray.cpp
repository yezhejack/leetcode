#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len=nums.size();
        if (len==0)
        {
        	return 0;
        }
        int rec_max[len];
        int rec_min[len];
        int temp_max,temp_min;
        int result=nums[0];
        rec_max[0]=nums[0];
        rec_min[0]=nums[0];
        for (int i=1;i<len;i++)
        {
        	rec_max[i]=nums[i];
        	rec_min[i]=nums[i];
        	temp_max=rec_max[i-1]*nums[i];
        	temp_min=rec_min[i-1]*nums[i];
        	if (temp_max>rec_max[i])
        	{
        		rec_max[i]=temp_max;
        	}
        	if (temp_min>rec_max[i])
        	{
        		rec_max[i]=temp_min;
        	}
        	if (temp_min<rec_min[i])
        	{
        		rec_min[i]=temp_min;
        	}
        	if (temp_max<rec_min[i])
        	{
        		rec_min[i]=temp_max;
        	}
        	if (rec_max[i]>result) result=rec_max[i];
        	if (rec_min[i]>result) result=rec_min[i];
        }
        return result;
    }
};
int main()
{
	int a[]={2,3,-2,4};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution solution;
	printf("%d\n",solution.maxProduct(nums));
	return 0;
}