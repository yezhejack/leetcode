#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
//*两次的动态规划
void output(int array[],int len)
{
	for (int i=0;i<len;i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        if (len<=1)
        {
        	return 0;
        }

        int min[len];//表示0到i这几天最低的价格
        int max[len];//表示i+1到最后一天的最大价格
        int front_profit[len];//表示0到i这几天的最好交易
        int back_profit[len];//表示i到len-1这几天的最好交易
        //处理最小的价格
        min[0]=prices[0];
        for (int i=1;i<len;i++)
        {
        	if (min[i-1]<prices[i])
        	{
        		min[i]=min[i-1];
        	}
        	else
        	{
        		min[i]=prices[i];
        	}
        }
        //处理最大的价格
        max[len-1]=prices[len-1];
        for (int i=len-2;i>=0;i--)
        {
        	if (max[i+1]>prices[i])
        	{
        		max[i]=max[i+1];
        	}
        	else
        	{
        		max[i]=prices[i];
        	}
        }

        //开始动态规划过程
        //先处理0-i的最好交易
        for (int i=0;i<len;i++)
        {
        	front_profit[i]=0;
        	back_profit[i]=0;
        }

        for (int i=1;i<len;i++)
        {
        	if (prices[i]-min[i-1]>front_profit[i-1])
        	{
        		front_profit[i]=prices[i]-min[i-1];
        	}
        	else
        	{
        		front_profit[i]=front_profit[i-1];
        	}
        	//output(front_profit,len);
        	//output(back_profit,len);
        }
        for (int i=len-2;i>=0;i--)
        {
        	if (max[i+1]-prices[i]>back_profit[i+1])
        	{
        		back_profit[i]=max[i+1]-prices[i];
        	}
        	else
        	{
        		back_profit[i]=back_profit[i+1];
        	}
        	//output(front_profit,len);
        	//output(back_profit,len);
        }
        //output(front_profit,len);
        //output(back_profit,len);
        //选取所有的最大利润
        int maxResult=front_profit[len-1];
        for (int i=0;i<len-2;i++)
        {
        	if (front_profit[i]+back_profit[i+1]>maxResult)
        	{
        		maxResult=front_profit[i]+back_profit[i+1];
        	}
        }
        return maxResult;
    }
};
int main()
{
	int input[]={2,1,1,3,4,5};
	vector<int> prices(input,input+sizeof(input)/sizeof(int));
	Solution solution;
	printf("%d\n",solution.maxProfit(prices));
	return 0;
}