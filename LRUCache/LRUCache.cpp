#include<iostream>
#include<stdio.h>
using namespace std;
class MyListNode{
public:
    int key;
    int value;
    MyListNode* pre;
    MyListNode* next;
    MyListNode(int k,int val,MyListNode* p,MyListNode* n):key(k),value(val),pre(p),next(n){}
};
class MyList{
public:
    MyListNode* header;
    MyListNode* tailer;
    int get(int key){
        if (header){
            if (header->key==key){
                return header->value;
            }else{
                MyListNode* curr=header->next;
                while(curr){
                    if (curr->key == key){
                        curr->pre->next=curr->next;
                        if (curr==tailer){
                            tailer=curr->pre;
                        }else{
                            curr->next->pre=curr->pre;
                        }
                        
                    }
                    curr=curr->next;
                }
                return -1;
            }
        }else{
            return -1;
        }
    }
    
    bool push_front(MyListNode* node){
        if (node==NULL) return false;
        else{
            if (header){
                node->next=header;
                header->pre=node;
                header=node;
                return true;
            }else{
                header=node;
                tailer=node;
                return true;
            }

        }
    }
    
    MyListNode* pop(){
        if (header){
            MyListNode* ans=header;
            header=header->next;
            ans->next=NULL;
            if (header==NULL){
                tailer=NULL;
            }else{
                header->pre=NULL;
            }
            return ans;
        }else{
            return NULL;
        }
    }
    
    bool insert_full(int key,int value){
        if (header){
            if (header!=tailer){
                MyListNode* curr=header;
                while (curr->next!=tailer){
                    curr=curr->next;
                }
                tailer=curr;
                curr->next->next=header;
                header=curr->next;
                curr->next=NULL;
            }
            header->key=key;
            header->value=value;
            return true;
        }else{
            return false;
        }
    }

    MyList(int n){
        if (n<1){
            header=NULL;
        }else{
            header=new MyListNode(0,0,NULL,NULL);
            tailer=header;
            for (int i=0;i<n-1;i++){
                tailer->next=new MyListNode(0,0,tailer,NULL);
                tailer=tailer->next;
            }
        }
    }
};
class LRUCache{
public:
    MyList* used_list;
    MyList* free_list;
    LRUCache(int capacity) {
        free_list=new MyList(capacity);
        used_list=new MyList(0);
    }
    
    int get(int key) {
        return used_list->get(key);
    }
    
    void set(int key, int value) {
        if (used_list->get(key)==-1){
            if (free_list->header){
                MyListNode* tmpnode=free_list->pop();
                tmpnode->key=key;
                tmpnode->value=value;
                used_list->push_front(tmpnode);
            }else{
                used_list->insert_full(key,value);
            }
        }else{
            used_list->header->value=value;
        }
    }
};
int main(){
    LRUCache* cache=new LRUCache(3);
    cache->set(2,1);
    cache->set(1,1);
    cout<<cache->get(2)<<endl;
    cache->set(3,3);
    cout<<cache->get(1)<<endl;
    cache->set(2,100);
    cout<<cache->get(2)<<endl;
    cout<<cache->get(1)<<endl;
    return 0;
}