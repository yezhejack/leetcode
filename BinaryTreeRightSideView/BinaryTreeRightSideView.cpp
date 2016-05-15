#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root==NULL) return ans;
        queue<TreeNode*> q;
        TreeNode* curr;
        q.push(root);
        while (!q.empty()){
            ans.push_back(q.front()->val);
            int sz=q.size();
            for (int i=0;i<sz;i++){
                curr=q.front();
                q.pop();
                if (curr->right){
                    q.push(curr->right);
                }
                if (curr->left){
                    q.push(curr->left);       
                }
        
            }
        }
        return ans;
    }
};
int main(){
    TreeNode* root=new TreeNode(1);
    //root->left=new TreeNode(2);
    //root->right=new TreeNode(3);
    //root->left->right=new TreeNode(5);
    //root->right->right=new TreeNode(4);
    
    Solution s;
    vector<int> ans=s.rightSideView(root);
    cout<<"============ Answer ==============="<<endl;
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}