#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	int m1=obstacleGrid.size();
    	int n1;
    	if (m1<1)
    	{
    		return 0;
    	}
    	else
    	{
    		n1=obstacleGrid[0].size();
    		if (n1<1)
    		{
    			return 0;
    		}
    	}
    	int rec[m1][n1];
    	//初始化边界
    	//输出m1,n1
    	//printf("m1=%d,n1=%d\n",m1,n1);
    	if (obstacleGrid[0][0]==0) rec[0][0]=1;
    	else
    		rec[0][0]=0;
    	for (int i=1;i<m1;i++)
    	{
    		if (obstacleGrid[i][0]==0)
    		{
    			rec[i][0]=rec[i-1][0];
    		}
    		else
    		{
    			rec[i][0]=0;
    		}
    	}
    	for (int i=1;i<n1;i++)
		{
			if (obstacleGrid[0][i]==0)
    		{
    			rec[0][i]=rec[0][i-1];
    		}
    		else
    		{
    			rec[0][i]=0;
    		}
		}
		/*for (int i=0;i<m1;i++)
		{
			for (int j=0;j<n1;j++)
			{
				printf("%d ",rec[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
		//DP
		for (int i=1;i<m1;i++)
		{
			for (int j=1;j<n1;j++)
			{
				if (obstacleGrid[i][j]==0)
				{
					rec[i][j]=rec[i-1][j]+rec[i][j-1];
				}
				else
				{
					rec[i][j]=0;
				}
				/*for (int i=0;i<m1;i++)
				{
					for (int j=0;j<n1;j++)
					{
						printf("%d ",rec[i][j]);
					}
					printf("\n");
				}
				printf("\n");*/
			}
		}
        return rec[m1-1][n1-1];
    }
};
int main()
{
	const int m=1,n=1;
	int a[m][n]={0};
	vector< vector<int> > input;
	for (int i=0;i<m;i++)
	{
		vector<int> temp(a[i],a[i]+n);
		input.push_back(temp);
	}
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf("%d ",input[i][j]);
		}
		printf("\n");
	}
	Solution solution;
	printf("%d\n",solution.uniquePathsWithObstacles(input));
	return 0;
}