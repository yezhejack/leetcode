#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class SNode{
public:
    TreeNode* data;
    SNode* next;
    SNode(TreeNode* tnode){
        data=tnode;
        next=NULL;
    }
};
class Stack{
public:
    SNode* top;
    Stack(){
        top=NULL;
    }
    bool isEmpty(){
        if (top){
            return false;
        }else{
            return true;
        }
    }
    void push(TreeNode* node){
        if (isEmpty()){
             top=new SNode(node);
        }
        else{
            SNode* new_top=new SNode(node);
            new_top->next=top;
            top=new_top;
        }
    }
    TreeNode* pop(){
        SNode* res=top;
        if (!isEmpty()){
            top=top->next;
            return res->data;
        }
        return NULL;
    }
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        Stack stack;
        TreeNode* curr_node=root;
        while (!curr_node){
            if (curr_node->left){
                stack.push(curr_node);
                curr_node=curr_node->left;
            }else{
                res.push_back(curr_node->val);
                if (curr_node->right){
                    res.push_back(curr_node->val);
                }
                curr_node=stack.pop();
                while (!stack.isEmpty() && curr_node->right==NULL){
                    res.push_back(curr_node->val);
                    curr_node=stack.pop();
                }
                if (curr_node){
                    res.push_back(curr_node->val);
                    curr_node=curr_node->right;
                }
            }

        }
        return res;
    }
};
int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(4);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(2);
    Solution s;
    vector<int> res=s.inorderTraversal(root);
    for (vector<int>::iterator it=res.begin();it!=res.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}