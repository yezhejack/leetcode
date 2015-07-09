//============================================================================
// Name        : RemoveElement.cpp
// Author      : Zhe Ye
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : 
// 使用两个指针一个从头部开始扫描，一个从尾部开始扫描，设置为p1和p2，p1必须满足小于p2
// 时间复杂度为O(n)
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
void output(vector<int>&nums,int result)
{
	printf("[");
	for (int i=0;i<result-1;i++)
	{
		printf("%d,",nums[i]);
	}
	printf("%d],%d\n",nums[result-1],result);
}
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ans=nums.size();
        int p1=0;
        int p2=ans-1;
        while(p1<p2)
        {
        	//让p2指向最后一个不需要删除的数
        	while(p1<p2&&nums[p2]==val)
        	{
        		p2--;
        		ans--;
        	}
        	//让p1对准第一个需要删除的数
        	while(p1<p2&&nums[p1]!=val)
        	{
        		p1++;
        	}   	
        	if (p1<p2)
        	{
        		nums[p1]=nums[p2];
        		p1++;
        		p2--;
        		ans--;
        	}
        }
        if (p2<ans&&p1==p2&&nums[p2]==val)
        {
        	ans--;
        }
        return ans;
    }
};
int main() {
	//The input data
	int array_nums[]={1,2,3,2,1,2,3,1,0};
	vector<int> nums(array_nums,array_nums+sizeof(array_nums)/sizeof(int));
	int val=1;

	//Excucate
	Solution solution;
	int result=solution.removeElement(nums,val);
	//Output
	output(nums,result);
	return 0;
}
