#include <iostream>
#include <stdio.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        int rec[m][n];
        if (m<1 || n<1)
        {
        	return 0;
        }
        if (m==1 || n==1)
        {
        	return 1;
        }
        //初始化
        for (int i=0;i<m;i++)
        {
        	rec[i][0]=1;
        }
        for (int i=0;i<n;i++)
        {
        	rec[0][i]=1;
        }
        //DP
        for (int i=1;i<m;i++)
        {
        	for (int j=1;j<n;j++)
        	{
        		rec[i][j]=rec[i-1][j]+rec[i][j-1];
        	}
        }
        return rec[m-1][n-1];
    }
};
int main()
{
	Solution solution;
	printf("%d\n",solution.uniquePaths(3,7));
	return 0;
}