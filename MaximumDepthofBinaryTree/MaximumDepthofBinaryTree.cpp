#include <iostream>
#include <stdio.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
using namespace std;
class QNode{
public:
    int depth;
    TreeNode* node;
    QNode(int d,TreeNode* n){
        depth=d;
        node=n;
        next=NULL;
    }
    QNode* next;
};
class Queue{
public:
    QNode* head;
    QNode* tail;
    Queue(){
        head=NULL;
        tail=NULL;
    }
    void insert(int depth,TreeNode* node){
        if (head==NULL){
            head=new QNode(depth,node);
            tail=head;
        }
        else{
            tail->next=new QNode(depth,node);
            tail=tail->next;
        }
    }
    QNode* pop(){
        QNode* result=head;
        if (head!=NULL){
            head=head->next;
        }
        else{
            
        }
        return result;
    }
    bool isEmpty(){
        if (head==NULL){
            return true;
        }
        else{
            return false;
        }
    }
};
class Solution {
public:
    int maxDepth(TreeNode* root) {
        Queue queue;
        int curr_depth=0;
        queue.insert(curr_depth,root);
        while (queue.isEmpty()==false){
            QNode* curr=queue.pop();
            curr_depth=curr->depth;
            if (curr->node->left){
                queue.insert(curr_depth+1,curr->node->left);
            }
            if (curr->node->right){
                queue.insert(curr_depth+1,curr->node->right);
            }
        }
        return curr_depth;
    }
};
int main(){
    Solution solution;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    cout<<solution.maxDepth(root);
    return 0;
}