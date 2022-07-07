#include<iostream>
using namespace std;
#define MAX 7
int a[MAX];
void build_heap(int i)
{
	if(a[i]>a[(i/2)-1])
	{
	int temp;
	temp=a[i/2];
	a[i/2]=a[i];
	a[i]=temp;
	if((i/2)-1>0)

	build_heap(i/2);
	}
}
main()
{
	for(int i=0;i<MAX;i++)
	{
		cout<<"Enter the number\n";
		cin>>a[i];
		if(i!=0)
		build_heap(i);
	}
	for(int i=0;i<MAX;i++)
	cout<<a[i]<<" ";
}
