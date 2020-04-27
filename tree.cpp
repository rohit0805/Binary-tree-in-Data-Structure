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
void printkdistant(struct node *root,int k){
	if(root==NULL)
		return;
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printkdistant(root->left,k-1);
	printkdistant(root->right,k-1);
}
int main(){
	struct node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->left=create(6);
	root->right->right=create(7);
	printkdistant(root,1);
	return 0;
}