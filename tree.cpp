#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

struct node* newNode(int data){
	struct node *newnode=new node;
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
int maxwidth(struct node *root){
    if(root==NULL)
        return 0;
    int count=0,maximum=INT_MIN;
    queue<struct node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        root=q.front();
        q.pop();
        if(root!=NULL){count++;}
        if(root==NULL){
            maximum=max(maximum,count);
            count=0;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            if(root->left)
                q.push(root->left);
            if(root->right)
                q.push(root->right);
            }
    }
    return maximum;
}
int main(){
	struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    //root->right->left = newNode(6);
    //root->right->right=newNode(7); 
    root->left->left->left=newNode(8);
    cout<<maxwidth(root)<<endl;    
	return 0;
}