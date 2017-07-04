#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
using namespace std;
/* takes adjlist
 * input src for djk
 * gives a routing table for node src
 */

typedef pair<int,int> pii;//dst,weight
typedef vector<pii> vpii;//list of dst,weight
typedef vector<vpii> vvpii;//all the vertices
struct toRet
{
	int distances;
	int previous_hop;
};
struct vertex_weight
{
	int vertex;
	int dist;
};

struct compare_dist
{
	bool operator()(vertex_weight a,vertex_weight b)
	{
		return a.dist > b.dist;
	}
};

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


vector<toRet> djk(vvpii alist,int src)
{
	vector<toRet> return_this;
	vvpii::size_type si = alist.size();
	vector<int> order_of_visit;
	int vectsize = (int)si;
	int parent[vectsize];
	vector<int> distance_array(vectsize,10000);
	priority_queue<vertex_weight,vector<vertex_weight>,compare_dist > next_in;
	struct vertex_weight v1;
	for(int aa = 0; aa<vectsize; aa++)
	{
		v1.vertex = aa;
		if(aa==src)
			v1.dist = 0;
		else
			v1.dist = 10000;
		next_in.push(v1);
	}
	distance_array[src]=0;
	while (!next_in.empty())
	{
		struct vertex_weight nowpair = next_in.top();
		next_in.pop();
		int now = nowpair.vertex;
		int no_of_neighbours  = (int)alist[now].size();
		for(int j=0;j<no_of_neighbours;j++)
		{
			int neighbour = alist[now][j].first;
			int cost_now_neigh = alist[now][j].second;
			int relaxation_value = cost_now_neigh;
			if(distance_array[neighbour] > relaxation_value)
			{
				distance_array[neighbour] = relaxation_value;
				struct vertex_weight neewpair;
				neewpair.vertex = neighbour;
				neewpair.dist = relaxation_value;
				next_in.push(neewpair);
				parent[neighbour] = now; 
			}
		}	
	}
	struct toRet temp;
	for(int i=1;i<vectsize;i++){
		temp.distances = distance_array[i];
		temp.previous_hop = parent[i];
		return_this.push_back(temp);
	}
	return return_this;
}
int main()
{
	vvpii a = adj_list();
	int src;
	vvpii::size_type si = a.size();
	disp_adjlist(a);
	cin>>src;
	vector<toRet> dist_djk = djk(a,src);
	int vectsize = (int)dist_djk.size();
	for(int i=0;i<vectsize;i++)
	{
		cout<<"from "<<src<<" to "<<(i+1)<<" is "<<dist_djk[i].distances<<" via "<<dist_djk[i].previous_hop<<endl;
	}
}	
