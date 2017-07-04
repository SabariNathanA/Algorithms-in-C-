#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int> > dpchange(int neededChange,int num_denom,vector<int> denom)
{
	vector< vector<int> > dp(num_denom, vector<int>(neededChange+1));
	int with, without;
	
	for(int i=0; i<num_denom; i++)
	{
		dp[i][0] = 0;
		for(int j=1;j<=neededChange; j++)
		{
			if(j>=denom[i])
			{
				with = ((int)j/denom[i]);
				with += dp[i][j - (denom[i] * with)];
			}
			else
				with = neededChange + 1;
			
			if (i>0) 
				without = dp[i-1][j];
			dp[i][j] = (min(with,without));
		}
	}
	return dp;
}

map<int,int> backtrack(vector<vector<int> > dp,int neededChange,int num_denom,vector<int> denom)
{
	map<int,int> to_return;
	for(int i=0; i<num_denom; i++)
		to_return[denom[i]] = 0;
	num_denom -=1;
	while(neededChange>0)	
	{
		if(neededChange == 1)
			num_denom -= 1;
		if((neededChange > 1) && (dp[num_denom][neededChange] == dp[num_denom-1][neededChange]))
		{
			num_denom -= 1;
		}
		else
		{
			neededChange = neededChange - denom[num_denom];
//			cout<<neededChange<<" ";flush(cout);
			to_return[denom[num_denom]]++;
		}
	}
	return to_return;
}
int main()
{
	int neededChange,num_denom;
	cout<<"Number of denominations? "<<endl;
	cin>>num_denom;
	cout<<"Enter the denominations "<<endl;
	vector<int> denom(num_denom);
	for(int i=0;i<num_denom;i++)
		cin>>denom[i];
	cout<<"Needed Change? "<<endl;
	cin>>neededChange;
	vector<vector<int> > filled = dpchange(neededChange,num_denom,denom);
	cout<<filled[num_denom-1][neededChange]<<endl;
	for(int i=0; i<num_denom; i++)
	{
		for(int j=0;j<=neededChange; j++)
		{
			cout<<filled[i][j]<<" ";
		}
		cout<<endl;
	}
	map<int,int> needed =  backtrack(filled,neededChange,num_denom,denom);
	while(num_denom>0){
		if(needed[denom[num_denom-1]] > 0)
			cout<<needed[denom[num_denom-1]]<<" coins of Rs. "<<denom[num_denom-1]<<endl;
		num_denom -= 1;
	}
}
