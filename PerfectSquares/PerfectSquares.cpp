#include <iostream>
#include <stdio.h>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> mapper;
    bool IsFirst;
    bool IsSquaresNum(int n){
        int root=(int)sqrt(n);
        return root*root==n;
    }
    int numSquares(int n) {
        /*cout<<"======================="<<endl;
        cout<<"n="<<n<<endl;
        for (int i=1;i<12;i++){
            cout<<i<<"="<<mapper[i]<<endl;
        }*/
        bool isRoot=false;
        if (IsFirst){
            IsFirst=false;
            isRoot=true;
            mapper.reserve(n+1);
            for (int i=1;i<=n;i++){
                mapper[i]=0;
            }
            int root=(int)sqrt(n);
            for (int i=1;i<=root;i++){
                mapper[i*i]=1;
            }
        }
        int ans=mapper[n];
        if (ans!=0) {
            IsFirst=isRoot;
            return ans;
        }else{
            ans=n;
            for (int i=n/2;i>=1;i--){
                int tmp_ans=numSquares(i)+numSquares(n-i);
                if (tmp_ans < ans){
                    ans=tmp_ans;
                }
            }
            mapper[n]=ans;
            //cout<<"ans="<<ans<<endl;
            IsFirst=isRoot;
            return ans;
        }   
    }
    Solution(){
        IsFirst=true;
    }
};
int main(){
    int input=6;
    Solution* sol=new Solution();
    int ans=sol->numSquares(input);
    cout<<input<<"="<<ans<<endl;
    return 0;
}