#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        int m,n;
        //处理边角情况
        m=grid.size();
        if (m==0)
        {
        	return 0;
        }
        n=grid[0].size();
        if (n==0)
        {
        	return 0;
        }
        //DP
        int rec[m][n];
        rec[0][0]=grid[0][0];
        //处理第一行
        for (int i=1;i<n;i++)
        {
        	rec[0][i]=rec[0][i-1]+grid[0][i];
        }
        //处理第一列
        for (int i=1;i<m;i++)
        {
        	rec[i][0]=rec[i-1][0]+grid[i][0];
        }
        for (int i=1;i<m;i++)
        {
        	for (int j=1;j<n;j++)
        	{
        		if (rec[i-1][j]<rec[i][j-1])
        		{
        			rec[i][j]=rec[i-1][j]+grid[i][j];
        		}
        		else
        		{
        			rec[i][j]=rec[i][j-1]+grid[i][j];
        		}
        	}
        }
        return rec[m-1][n-1];
    }
};
int main()
{
	const int m1=3,n1=3;
	int a[m1][n1]={1,2,3,
				   1,-3,3,
				   1,0,3};
	vector< vector<int> > input;
	for (int i=0;i<m1;i++)
	{
		vector<int> temp(a[i],a[i]+n1);
		input.push_back(temp);
	}
	Solution solution;
	printf("%d\n",solution.minPathSum(input));
	return 0;
}