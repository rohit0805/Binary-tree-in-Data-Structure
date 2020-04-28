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
int height(struct node *root){
    if(root==NULL)return 0;
    return 1+max(height(root->left),height(root->right));
}
int isbalanced(struct node *root){
    if(root==NULL)
        return 1;
    int leftheight=0,rightheight=0;
    leftheight=height(root->left);
    rightheight=height(root->right);
    if(abs(leftheight-rightheight)<=1 && isbalanced(root->left) && isbalanced(root->right)){
        return 1;
    }
    return 0;
}
int isbalancedfast(struct node *root,int *height){
    int lh=0,rh=0,l,r;
    if(root==NULL){
        *height=0;
        return 1;
    }
    l=isbalancedfast(root->left,&lh);
    r=isbalancedfast(root->right,&rh);
    *height=(lh>rh?lh:rh)+1;
    if(abs(lh-rh)>=2)
        return 0;
    else
        return l&&r;
}
int main(){
	struct node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->left = newNode(8); 
    int height=0;
    if (isbalanced(root)) 
        cout << "Tree is balanced"; 
    else
        cout << "Tree is not balanced";
    cout<<endl;
    if (isbalancedfast(root,&height)) 
        cout << "Tree is balanced"; 
    else
        cout << "Tree is not balanced"; 
    
	return 0;
}