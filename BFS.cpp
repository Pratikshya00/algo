#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
vector<int> g[N];
bool visit[N];
void BFS(int src)
{
	queue<int> q;
	q.push(src);
	visit[src]=true;
	while(!q.empty())
	{
		int cur_src=q.front();
		q.pop();
		cout<<cur_src<<" ";
		for(auto child:g[cur_src]){
			if(!visit[child]){
				q.push(child);
				visit[child]=true;
			}
		}
	}
}
int main()
{
	int n;
	cout<<"Enter number of vertices";
	cin>>n;
	for(int i=0;i<=n-1;i++)
	{
	  int v1,v2;
	  cout<<"Enter edge\n";
	  cin>>v1>>v2;
	  g[v1].push_back(v2);
	  g[v2].push_back(v1);
	}
	BFS(1);
}
