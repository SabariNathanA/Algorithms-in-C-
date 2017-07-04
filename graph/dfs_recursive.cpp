#include <iostream>
#include <vector>
#include <utility>
using namespace std;
typedef pair<int,int> pii;//dst,weight
typedef vector<pii> vpii;//list of dst,weight
typedef vector<vpii> vvpii;//all the vertices

int count = 0;
vvpii adj_list()
{
	unsigned int nodes,noofedges;
	int srcfromcin,efromcin;
	int wfromcin;
	cout<<"Enter nodes and edges count"<<endl;
	cin>>nodes;
	cin>>noofedges;
	vvpii adjlist(nodes+1);//for node 1-n initialising
	unsigned int ii=0;
	for(ii=0;ii<noofedges;ii++)
	{
		cin>>srcfromcin>>efromcin>>wfromcin;
		adjlist[srcfromcin].push_back(make_pair(efromcin,wfromcin));
	}	
	return adjlist;
}
void disp_adjlist(vvpii a)
{
	int j;
	vvpii::size_type si = a.size();
	for(int i=1;i<(int)si;i++)
	{
		for(j=0;j<(int)a[i].size();j++){
			cout<<i<<" to "<<a[i][j].first<<" with "<<a[i][j].second<<endl;
		}
	}
}
int * only_dfs(vvpii a,int src,bool *visited,int *starttime,int*finishtime,int *parent)
{
	visited[src] = true;
	starttime[src] = ++count;
	int no_of_neighbours = (int)a[src].size(),i;
	for(i=0;i<no_of_neighbours;i++)
	{ 
		int neigh = a[src][i].first;
		if(!visited[neigh])
		{
			parent[neigh] = src;
			
			only_dfs(a,neigh,visited,starttime,finishtime,parent);
			finishtime[neigh] = ++count;
//			cout<<src<<'\t'<<neigh<<'\t'<<finishtime[neigh]<<endl;
		}
	}
	return finishtime;
}
int *dfsr(int src,vvpii a,int number_of_nodes,int *finishtime)
{
	bool visited[number_of_nodes];
	for(int i=0;i<number_of_nodes;i++)
		visited[i] = false;
	int starttime[number_of_nodes];
	int parent[number_of_nodes];
	finishtime = only_dfs(a,src,visited,starttime,finishtime,parent);
/*	for(int i=1;i<number_of_nodes;i++)
	{
		cout<<i<<'\t'<<finishtime[i]<<endl;
	}
*/	return finishtime;
}

int main()
{
	vvpii a = adj_list();
	int src;
	vvpii::size_type si = a.size();
	disp_adjlist(a);
	cin>>src;
	int finishtime[(int)si];
	int *finished = dfsr(src,a,(int)si,finishtime);
	for(int i=1;i<(int)si;i++)
	{
		cout<<finished[i]<<" - ";
	}
}
