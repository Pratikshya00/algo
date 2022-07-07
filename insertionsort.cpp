#include<iostream>
#define MAX 100
using namespace std;
int main()
{
	int a[]={9,2,5,7,1,6},i,j,temp,n=6;
	for(i=1;i<=n-1;i++)
	{
		temp=a[i];
		for(j=i-1;j>=0&&temp<a[j];j--)
		a[j+1]=a[j];
		a[j+1]=temp;
	}
	for(auto v:a)
	cout<<v<<" ";
	
}
