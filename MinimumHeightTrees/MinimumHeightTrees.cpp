//
//  main.cpp
//  MinimumHeightTrees
//  每次讲入度为1的删除，然后调整所有节点的入度
//  当最后剩下1个或两个点的时候，这个就是最后的答案了
//  Created by 叶哲 on 16/5/14.
//  Copyright © 2016年 叶哲. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<int> ans;
        if (n==1){
            ans.push_back(0);
            return ans;
        }
        int degree[n];
        queue<int> q;
        vector<vector<int> > g(n,vector<int>());
        for (int i=0;i<n;i++){
            degree[i]=0;
        }
        for (vector<pair<int,int> >::iterator iter=edges.begin();iter<edges.end();iter++){
            degree[iter->first]++;
            degree[iter->second]++;
            g[iter->first].push_back(iter->second);
            g[iter->second].push_back(iter->first);
        }
        int count=n;
        while (count>2){
            for (int i=0;i<n;i++){
                if (degree[i]==1){
                    q.push(i);
                }
            }
            while(!q.empty()){
                int node=q.front();
                degree[node]=0;
                q.pop();
                count--;
                for (int i=0;i<g[node].size();i++){
                    if (degree[g[node][i]]--==1){
                        ans.push_back(g[node][i]);
                        return ans;
                    }
                }
                
                
            }
        }

        for (int i=0;i<n;i++){
            if (degree[i]>0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
    vector<pair<int,int> > edges;
    vector<pair<int,int> > ::iterator iter;
    edges.push_back(pair<int,int>(0,1));
    edges.push_back(pair<int,int>(0,2));
    edges.push_back(pair<int,int>(0,3));
    edges.push_back(pair<int,int>(4,0));
    edges.push_back(pair<int,int>(5,4));
    iter=edges.begin();
    for (;iter!=edges.end();iter++){
        cout<<"["<<iter->first<<","<<iter->second<<"]"<<endl;
    }
    Solution s;
    vector<int> ans = s.findMinHeightTrees(6,edges);
    for (vector<int> ::iterator iter2=ans.begin();iter2<ans.end();iter2++){
        cout<<*iter2<<endl;
    }
    return 0;
}