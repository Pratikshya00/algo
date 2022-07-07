#include<bits/stdc++.h>
using namespace std;
#define MAX 10
int stack_arr[MAX];
int top=-1;
bool isFull(){
	if(top==MAX-1)
		return true;
	else return false;	
}
bool isEmpty(){
	if(top==-1)
		return true;
	else return false;	
}
void push(int item){
	if(isFull()){
		cout<<"Stack Overflow\n";
		return;
	}
	top=top+1;
	stack_arr[top]=item;
}
int pop(){
	int item;
	if(isEmpty()){
		cout<<"Stack Underflow\n";
		exit(1);
	}
	item=stack_arr[top];
	top=top-1;
	return item;
}
void Display(){
	if(isEmpty()){
		cout<<"Stack Underflow"<<endl;
		return;
	}
	for(int i=top;i>=0;i--)
		cout<<stack_arr[i]<<" ";
		cout<<endl;
}
int main()
{
	int choice,item;
	while(1){
		cout<<"1=Push\n";
		cout<<"2=Pop\n";
		cout<<"3=Display\n";
		cout<<"4=Quit\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		
		switch(choice){
			case 1:
				cout<<"Enter the item to be pushed\n";
				cin>>item;
				push(item);
				break;
				
			case 2:
				cout<<"Poped item is "<<pop()<<"\n";
				break;	
			
			case 3:
				Display();
				break;
			
			case 4:
				exit(1);
			default:
				cout<<"Wrong choice\n";			
		}	
	}
	return 0;
}
