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
int issumproperty(struct node *root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return 1;
    }
    int leftsum=0,rightsum=0;
    if(root->left)
        leftsum=root->left->data;
    if(root->right)
        rightsum=root->right->data;
    if(root->data==leftsum+rightsum && issumproperty(root->left) && issumproperty(root->right)){
        return 1;        
    }
    return 0;
}
int main(){
	struct node *root = newNode(10); 
    root->left     = newNode(8); 
    root->right = newNode(2); 
    root->left->left = newNode(3); 
    root->left->right = newNode(5); 
    root->right->right = newNode(2); 
    if(issumproperty(root)) 
        cout << "The given tree satisfies "
            << "the children sum property "; 
    else
        cout << "The given tree does not satisfy "
            << "the children sum property "; 
	return 0;
}