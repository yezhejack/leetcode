//========================================================
//使用贪心或者动态规划都可以，贪心能解的动态规划也能解，但是需要付出
//更多的时间和空间。贪心算法的时间复杂度和空间复杂度都更低，但是对于
//刚刚接触贪心算法的要想想出贪心策略还是有点难度的。
//可以记录一个当前所在位置能到达的范围，以及这个范围内所有
//========================================================
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
	int min(int a,int b)
	{
		if (a>b) return b;
		else
			return a;
	}
    int jump(vector<int>& nums) {
        int next;//从当前位置跳一次能到达的范围的最大下标
        int next_next;//从当前位置跳一次后的位置再跳一次所能达到的范围的最大下标
        int now=0;
        int len=nums.size();
        int steps=0;
        if(len==0)
        {
        	return 0;
        }
        while (now<=len-1)
        {
        	if (now>=len-1)
        	{
        		break;
        	}
        	next=min(now+nums[now],len-1);
        	if (next==len-1)
        	{
        		steps++;
        		break;
        	}
        	int i=now+1;
        	next_next=min(i+nums[i],len-1);
        	//printf("next=%d,next_next=%d",next,next_next);
        	while(i<=next)
        	{
        		if (i+nums[i]>=next_next)
        		{
        			now=i;
        			next_next=min(len-1,i+nums[i]);
        		}
        		i++;
        	}
        	steps++;
        	//printf("next=%d,next_next=%d",next,next_next);
        	//printf("now=%d\n",now);
        }
        return steps;
    }
};
int main()
{
	//int a[]={9,7,9,4,8,1,6,1,5,6,2,1,7,9,0};
	int a[]={2,3,1,1,4};
	vector<int> nums(a,a+sizeof(a)/sizeof(int));
	Solution solution;
	printf("%d\n",solution.jump(nums));
	return 0;
}
