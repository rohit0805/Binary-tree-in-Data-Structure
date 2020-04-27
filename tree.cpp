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
void printnode(struct node *root,int k){
	if(root==NULL){
		return;
	}
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	printnode(root->left,k-1);
	printnode(root->right,k-1);
}
int printkdistantnode(struct node *root,struct node *target,int k){
	if(root==NULL){
		return -1;
	}
	else if(root==target){
		printnode(root,k);
		return 0;
	}
	int dl=printkdistantnode(root->left,target,k);
	if(dl!=-1){
		if(dl+1==k){
			cout<<root->data<<" ";
		}
		else{
			printnode(root->right,k-dl-2);
		}
		return dl+1;
	}
	int dr=printkdistantnode(root->right,target,k);
	if(dr!=-1){
		if(dr+1==k){
			cout<<root->data<<" ";
		}
		else{
			printnode(root->left,k-dr-2);
		}
		return dr+1;
	}
	return -1;
}

int main(){
	struct node *root=create(20);
	root->left=create(8);
	root->right=create(22);
	root->left->left=create(4);
	root->left->right=create(12);
	root->left->right->left=create(10);
	root->left->right->right=create(14);
	struct node *target=root->left->right;
	printkdistantnode(root,target,2);
	return 0;
}