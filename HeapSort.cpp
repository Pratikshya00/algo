#include<iostream>
#define MAX 11
int a[MAX];
using namespace std;
void heapify(int n,int i)
{
	int left,right,largest=i;
	left=2*i+1;
	right=left+1;
	int temp;
	if(left<n&&a[left]>a[largest])
	{
	largest=left;
	}
	if(right<n&&a[right]>a[largest])
	{
	largest=right;
	}
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		heapify(n,largest);
	}
}
void build_heap(int n)
{
	int i,temp;
	for(i=n/2-1;i>=0;i--)
	heapify(n,i);
}
void heap_sort(int n)
{
	build_heap(n);
	for(int i=n-1;i>0;i--) 
	{
		int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapify(i,0);
	}
}
main()
{
	int n;
	cout<<"Enter the number of elements\n";
	cin>>n;
	cout<<"Enter the elements\n";
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cout<<"Entered numbers are:\n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	
	heap_sort(n);
cout<<"\nSorted array is:\n";
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
