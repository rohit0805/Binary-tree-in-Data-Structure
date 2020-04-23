#include<bits/stdc++.h>
using namespace std;
char tree[100];
void root(char data){
	if(tree[0]!='\0'){
		cout<<"Tree root is acquired"<<endl;
	}
	else
		tree[0]=data;
}
void set_right(char data,int parent){
	if(tree[parent]=='\0'){
		cout<<"\nCan't set child at "<<(parent)*2+2<<" ,no parent found";		
	}
	else{
		tree[parent*2+2]=data;
	}
}
void set_left(char data,int parent){
	if(tree[parent]=='\0'){
		cout<<"\nCan't set child at "<<(parent)*2+1<<" ,no parent found";
	}
	else{
		tree[parent*2+1]=data;
	}
}
void print_tree(){
	cout<<endl;
	for(int i=0;i<10;i++){
		if(tree[i]!='\0')
			cout<<tree[i];
		else
			cout<<"-";
	}
}
int main(){
	root('A');
	set_right('C',0);
	set_left('D',1);
	set_right('E',1);
	set_right('F',2);
	print_tree();
	return 0;
}
