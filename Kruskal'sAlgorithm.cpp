

#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int parent[N];
int size[N];
void make(int v){
	parent[v]=v;
	size[v]=1;
}
int find(int v){
	if(v==parent[v])
		return v;
	return parent[v]=find(parent[v]);	
}
void Union(int a,int b){
	a=find(a);
	b=find(b);
	if(a!=b){
		if(size[a]<size[b])
		swap(a,b);
		parent[b]=a;
	}
	size[a]+=size[b];
}
int main(){
	int n,m;
	cout<<"Enter number of nodes and edges\n";
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges;
	for(int i=0;i<m;i++){
		int u,v,wt;
		cout<<"Enter edge(nodes) and its weight\n";
		cin>>u>>v>>wt;
		edges.push_back({wt,{u,v}});
	}
	cout<<endl;
	sort(edges.begin(),edges.end());
	
	for(int i=0;i<=n;i++) make(i);
	
	int total_cost=0;
	cout<<"Edges are:\n";
	for(auto edge:edges){
		int wt=edge.first;
		int u=edge.second.first;
		int v=edge.second.second;
		if(find(u)==find(v)) continue;
		Union(u,v);
		total_cost+=wt;
		cout<<u<<" "<<v<<endl;
	}
	cout<<"Total cost is:"<<total_cost<<endl;
	return 0;
}
