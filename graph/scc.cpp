#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;//dst,weight
typedef vector<pii> vpii;//list of dst,weight
typedef vector<vpii> vvpii;//all the vertices

int hcount = 0;
vvpii adj_list()
{
	unsigned int nodes,noofedges;
	int srcfromcin,efromcin;
	int wfromcin;
	cout<<"Enter nodes and edges hcount"<<endl;
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
	starttime[src] = ++hcount;
	int no_of_neighbours = (int)a[src].size(),i;
	for(i=0;i<no_of_neighbours;i++)
	{ 
		int neigh = a[src][i].first;
		if(!visited[neigh])
		{
			parent[neigh] = src;
			only_dfs(a,neigh,visited,starttime,finishtime,parent);
			finishtime[neigh] = ++hcount;
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
	finishtime[src] = ++hcount;
	return finishtime;
}
bool sortOnFinTime(pair<int,int> a, pair<int,int> b )
{
	return a.second < b.second;
}

vvpii transpose_list(vvpii a)
{
	int newsrc,newcost,newdst;
	vvpii toReturn((int)a.size());
	for(int i=1;i<(int)a.size();i++)
	{
		int no_of_neighbours = (int)a[i].size();
		for(int j=0;j<no_of_neighbours;j++)
		{
			newsrc = a[i][j].first;
			newcost = a[i][j].second;
			newdst = i;
			toReturn[newsrc].push_back(make_pair(newdst,newcost));
		}
	}
	return toReturn;
}

int check_scc(vvpii alist, vector<int>node_order)
{
	for(int i=1;i<(int)node_order.size;i++)
	{
		int src = node_order[i];
		if(!visited[src])
		{
			int no_of_neighbours = (int)a[src].size(),i;
			for(i=0;i<no_of_neighbours;i++)
			{ 
				int neigh = a[src][i].first;
				if(!visited[neigh])
				{
					parent[neigh] = src;
					only_dfs(a,neigh,visited,starttime,finishtime,parent);
					finishtime[neigh] = ++hcount;
//					cout<<src<<'\t'<<neigh<<'\t'<<finishtime[neigh]<<endl;
				}
			}
		}
	}
}

int main()
{
	vvpii a = adj_list();
	int src;
	vvpii::size_type si = a.size();
	cout<<"Enter the source "<<endl;
	cin>>src;
	int finishtime[(int)si];
	int *finished = dfsr(src,a,(int)si,finishtime);
	vector<pair<int,int> > node_lastvisit;//make pair
	for(int i=1;i<(int)si;i++)
	{
		cout<<finished[i]<<" - ";
		node_lastvisit.push_back(make_pair(i,finished[i]));
	}
	//sort on desccending order
	sort(node_lastvisit.begin(),node_lastvisit.end(),sortOnFinTime);
	vector<int> node_order;
	for(int i=0;i<((int)si)-1;i++)
	{
		node_order[i].first<<endl;
	}
	//transpose the graph
	vvpii inverted_alist = transpose_list(a);
	disp_adjlist(inverted_alist);
	//call different dfs to call in this order
	check_scc(inverted_alist,node_order)
	
	
}
