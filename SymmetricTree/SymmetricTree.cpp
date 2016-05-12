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
    int index;
    TreeNode* node;
    MyListNode* pre;
    MyListNode* next;
    MyListNode(int i,TreeNode* N,MyListNode* p,MyListNode* n):index(i),node(N),pre(p),next(n){}
};
class MyList{
public:
    int count;
    MyListNode* header;
    MyListNode* tailer;
    MyList(){header=NULL;tailer=NULL;count=0;}
    void push_back(TreeNode* n,int i){
        if (n==NULL) return;
        if (header==NULL){
            header=new MyListNode(i,n,NULL,NULL);
            tailer=header;
            count=1;
        }else{
            tailer->next=new MyListNode(i,n,tailer,NULL);
            tailer=tailer->next;
            count++;
        }
    }
    ~MyList(){
        while (header){
            MyListNode* tmp=header;
            header=header->next;
            delete tmp;
        }
    }
};
//2 3 3*2^(level)-1   4 5 6 7
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        if (root->left==NULL and root->right==NULL) return true;
        if (root->left && root->right){          
            int level=2;
            MyList* curr_list=new MyList();
            MyList* next_list=NULL;
            curr_list->push_back(root->left,2);
            curr_list->push_back(root->right,3);
            while(curr_list->count!=0){
                MyListNode* tmp_h=curr_list->header;
                MyListNode* tmp_t=curr_list->tailer;
                while (true){
                    cout<<"tmp_h->index="<<tmp_h->index<<endl;
                    cout<<"tmp_t->index="<<tmp_t->index<<endl;
                    cout<<"tmp_h->val="<<tmp_h->node->val<<endl;
                    cout<<"tmp_t->val="<<tmp_t->node->val<<endl;
                    if (tmp_h->index != 3*level-1-tmp_t->index ||tmp_h->node->val != tmp_t->node->val){
                        return false;
                    }
                    tmp_h=tmp_h->next;
                    tmp_t=tmp_t->pre;
                    if (tmp_h==tmp_t) return false;
                    if (tmp_h->index >tmp_t->index){
                        break;
                    }
                }
                next_list=new MyList();
                tmp_h=curr_list->header;
                while (tmp_h){
                    next_list->push_back(tmp_h->node->left,2*tmp_h->index);
                    next_list->push_back(tmp_h->node->right,2*tmp_h->index+1);
                    tmp_h=tmp_h->next;
                }
                delete curr_list;
                curr_list=next_list;
                level *= 2;
            }
            return true;
        }else{
            return false;
        }
    }
};
int main(){
	TreeNode* root=new TreeNode(2);
	root->left=new TreeNode(3);
	root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->right=new TreeNode(4);
    
	Solution sol;
	cout<<sol.isSymmetric(root)<<endl;
	return 0;
}