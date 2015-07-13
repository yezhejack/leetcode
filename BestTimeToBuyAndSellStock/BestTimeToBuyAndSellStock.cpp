#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <limits.h>
using namespace std;
//维护两个数组来记录前i个数中最小的和从i+1起到最后一个的最大的数
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int size=prices.size();
    	if (size<2) return 0;
    	int min[size];
    	int max[size];
    	for (int i=0;i<size-1;i++)
    	{
    		min[i]=prices[i];
    		max[i]=prices[i+1];
    	}
    	//Set min
    	min[0]=prices[0];
    	for (int i=1;i<size-1;i++)
    	{
    		if(min[i-1]<prices[i])
    		{
    			min[i]=min[i-1];
    		}
    	}
    	//Set max
    	for (int i=size-3;i>=0;i--)
    	{
    		if (max[i+1]>prices[i+1])
    		{
    			max[i]=max[i+1];
    		}
    	}
    	/*for (int i=0;i<size;i++)
    	{
    		printf("%d:%d %d\n",i,min[i],max[i]);
    	}*/
    	int result=max[0]-min[0];
    	for (int i=1;i<size-1;i++)
    	{
    		if (result<max[i]-min[i])
    		{
    			result=max[i]-min[i];
    		}
    	}
    	if (result<0) result=0;
        return result;
    }
};
int main()
{
	int input[]={1,2,3,4,5,6,3};
	vector<int> prices(input,input+sizeof(input)/sizeof(int));
	Solution solution;
	cout<<solution.maxProfit(prices)<<endl;
	return 0;
}