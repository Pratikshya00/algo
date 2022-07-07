#include<bits/stdc++.h>
using namespace std;
struct node{
	int info;
	struct node *link;
}*top=NULL;
bool isEmpty(){
	if(top==NULL)
		return true;
	else return false;	
}
void push(int item){
	struct node *temp;
	temp=new node();
	temp->info=item;
	temp->link=top;
	top=temp;
}
int pop(){
	node *temp;
	int item;
	if(isEmpty()){
		cout<<"Stack Underflow\n";
		exit(1);
	}
	temp=top;
	item=temp->info;
	top=top->link;
	delete temp;
	return item;
}
void display(){
	node *ptr;
	ptr=top;
	if(isEmpty()){
		cout<<"Stack is empty\n";
		return;
	}
	cout<<"Stack elements are:\n";
	while(ptr!=NULL){
		cout<<ptr->info<<" ";
		ptr=ptr->link;
	}
	cout<<endl;
}
int main(){
	int choice,item;
	while(1){
		cout<<"1=Push\n";
		cout<<"2=Pop\n";
		cout<<"3=Display\n";
		cout<<"4=Quit"<<endl;
		cout<<"Enter your choice\n";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the item to be pushed\n";
				cin>>item;
				push(item);
				break;
			
			case 2:
				cout<<"poped item is:"<<pop()<<endl;
				break;
				
			case 3:
				display();
				break;	
			
			case 4:
				exit(1);
			default:cout<<"Wrong choice";			
		}
	}
}
