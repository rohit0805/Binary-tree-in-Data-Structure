#include<bits/stdc++.h>
using namespace std;

struct node{
	int data;
	struct node *left,*right;
};

struct node* create(int data){
	struct node *newnode=new node;
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
int size(struct node *root){
	if(root==NULL)
		return 0;
	return 1+size(root->left)+size(root->right);
}
int maxi=INT_MIN;
void maximum(struct node *root){
	if(root==NULL)
		return ;
	if(root->data>maxi)
		maxi=root->data;
	maximum(root->left);
	maximum(root->right);
}
int main(){
	struct node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->left=create(6);
	root->right->right=create(7);
	//cout<<size(root)<<endl;
	maximum(root);
	cout<<maxi<<endl;
	return 0;
}