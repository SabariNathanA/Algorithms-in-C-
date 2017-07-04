#include <iostream>
#include <vector>
#include <utility>
#include <stack>
using namespace std;


typedef pair<int,int> pii;//dst,weight
typedef vector<pii> vpii;//list of dst,weight
typedef vector<vpii> vvpii;//all the vertices

vvpii adj_list()
{
	unsigned int nodes,noofedges;
	int srcfromcin,efromcin;
	int wfromcin;
	cout<<"Enter nodes and edges count"<<endl;
	cin>>nodes>>noofedges;
	
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

vector<int> dfs(vvpii alist,int src)
{
	vvpii::size_type si = alist.size();
	vector<int> order_of_visit;
	bool visited[(int)si];
	int parent[(int)si];
	stack<int> next_in;
	for(int k=0;k<(int)si;k++)
		visited[k] = false;
		
	next_in.push(src);
	parent[src] = -1;
	
	while(!next_in.empty())
	{
		int now = next_in.top();
		next_in.pop();
		if(!visited[now])
		{
			order_of_visit.push_back(now);
			cout<<"visiting "<<now<<endl;
			visited[now] = true;
			int no_of_neighbours = (int)alist[now].size(),i;
			for(i=0;i<no_of_neighbours;i++)
			{
				int neighbour = alist[now][i].first;
				if(!visited[neighbour])
				{
					next_in.push(neighbour);
					cout<<"pushing "<<neighbour<<endl;
					parent[neighbour] = now;
				}
			}
		}
	}
	return order_of_visit;
}

int main()
{
	vvpii a = adj_list();
	int src;
	vvpii::size_type si = a.size();
	disp_adjlist(a);
	cin>>src;
	vector<int>order_dfs = dfs(a,src);
	int vectsize = (int)order_dfs.size();
	for(int i=0;i<vectsize;i++)
	{
		cout<<order_dfs[i]<<" - ";
	}
}
