#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	struct node *left,*right;
};
struct node *create(int data){
	struct node *newnode=new node;
	newnode->data=data;
	newnode->left=newnode->right=NULL;
	return newnode;
}
void levelorder(struct node *root){
	if(root==NULL){
		return ;
	}
	queue<struct node*> q;
	q.push(root);
	while(!q.empty()){
		root=q.front();
		q.pop();
		cout<<root->data<<" ";
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
	cout<<endl;
}
int height(struct node *root){
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
void check(struct node *root,int level){
	if(root==NULL){
		return;
	}
	else if(level==1){
		cout<<root->data<<" ";
	}
	else if(level>1){
		check(root->left,level-1);
		check(root->right,level-1);
	}
}
void printlevel(struct node *root){
	int i,h=height(root);
	for(i=1;i<=h;i++){
		check(root,i);
	}
}
int main(){
	struct node *root=create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->left=create(6);
	root->right->right=create(7);
	levelorder(root);
	cout<<endl;
	printlevel(root);
	return 0;
}
