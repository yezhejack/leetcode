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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        Stack stack;
        if (root){
            stack.push(root);
        }
        while (!stack.isEmpty()){
            TreeNode* curr_node=stack.pop();
            res.push_back(curr_node->val);
            if (curr_node->right){
                stack.push(curr_node->right);
            }
            if (curr_node->left){
                stack.push(curr_node->left);
            }
        }
        return res;
    }
};
int main(){
    cout<<"hello world"<<endl;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(4);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(2);
    Solution s;
    vector<int> res=s.preorderTraversal(root);
    for (vector<int>::iterator it=res.begin();it!=res.end();it++){
        cout<<*it<<endl;
    }
    return 0;
}