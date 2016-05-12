#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class MyListNode{
public:
    TreeNode* val;
    MyListNode* next;
    MyListNode(TreeNode* x,MyListNode* y):val(x),next(y){}
};
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root==NULL) return 0;
        MyListNode* this_level;
        this_level=new MyListNode(root,NULL);
        MyListNode* next_level=NULL;
        int ans=1;
        int index=1;
        while (true){
            while(this_level){
                TreeNode* left_child=this_level->val->left;
                TreeNode* right_child=this_level->val->right;
                if (left_child==NULL and right_child==NULL){
                    return ans;
                }
                if (left_child){
                    next_level=new MyListNode(left_child,next_level);
                }
                if (right_child){
                    next_level=new MyListNode(right_child,next_level);
                }
                MyListNode* tmp=this_level;
                this_level=this_level->next;
                delete tmp;
            }
            this_level=next_level;
            next_level=NULL;
            ans++;
        }
    }
};
int main(){
	TreeNode* root=new TreeNode(1);
	root->left=new TreeNode(2);
	root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    
	Solution sol;
	cout<<sol.minDepth(root);
	return 0;
}