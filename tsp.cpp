#include<bits/stdc++.h>
using namespace std;

struct compareCost {    
	bool operator()(vector<int> p1,vector<int>  p2) 
	{ 
		return p1[p1.size()-1] +p1[p1.size()-2]> p2[p2.size()-1]+p2[p2.size()-2]; 
	} 
};

int checkGoal(vector<int> state,int InitialState)
{
	if(state[InitialState]==state.size()-1)
		return 1;
	return 0 ;

}

int main()
{
	int NoofCity,NoofEdges;
	cout<<"Enter no. of cities: ";
	cin>>NoofCity;
	cout<<"Enter no. of connecting Roads: ";
	cin>>NoofEdges;
	cout<<"Enter City1 City2 PathCost: \n";
	vector<vector<int>>pathCost(NoofCity);
	for ( int i = 0 ; i < NoofCity; i++ )
		pathCost[i].resize(NoofCity);
	int minpath=INT_MAX;
	for(int i=0;i<NoofEdges;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		pathCost[x][y]=c;
		pathCost[y][x]=c;
		if(minpath>c)
			minpath=c;
	}

	int InitialState;
	cout<<"Enter the initial City: ";
	cin>>InitialState;

	vector<int> State;

	for(int i=0;i<NoofCity;i++)
	{
		if(i==InitialState)	
			State.push_back(1);
		else if(i!=NoofCity)	 
			State.push_back(-1);	  	
	}
	State.push_back(0);
	State.push_back(0);
	priority_queue <vector<int>,vector<vector<int>>,compareCost> OPEN;
	int y=0;
	OPEN.push(State);
	vector<int> sol;
	for(int i=0;i<=NoofCity+1;i++)
	{
		if(i==NoofCity||i==NoofCity+1)
			sol.push_back(100000);
		else
		{
			sol.push_back(-1);
		}

	}

	while(!OPEN.empty())
	{
		vector<int> top=OPEN.top();
		OPEN.pop();
		if(checkGoal(top,InitialState))
		{
			y++;

			if(sol[sol.size()-1] + sol[sol.size()-2]>top[top.size()-1] + top[top.size()-2])
				sol=top;

		}

		int max=0,maxi=0;
		for(int i=0;i<top.size()-2;i++)
		{  
			if(top[i]>max)
			{
				max=top[i];
				maxi=i;
			}	
		}

		int countvisit=0;
		if(max<top.size()-1)
			for(int i=0;i<NoofCity;i++)
			{   	
				int gn=top[top.size()-1]+pathCost[maxi][i];

				int hn=minpath*(NoofCity-max-1)+pathCost[maxi][i];

				if(pathCost[i][maxi]>0)
				{
					vector<int> tmp;
					for(int x=0;x<top.size();x++)
					{
						tmp.push_back(top[x]);
					}

					if(tmp[i]==-1)
					{   tmp[i]=max+1;
						tmp[tmp.size()-1]=gn;
						tmp[tmp.size()-2]=hn;    
						OPEN.push(tmp); 
						countvisit++;  
					} 
				}
			}

		if(countvisit==0 && max<top.size()-1)
		{
			
			int gn=top[top.size()-1]+pathCost[maxi][InitialState];
			int hn=minpath*(NoofCity-max-1)+pathCost[maxi][InitialState];
			vector<int> tmp=top;
			tmp[InitialState]=max+1;
			tmp[tmp.size()-1]=gn;
			tmp[tmp.size()-2]=hn;  

			OPEN.push(tmp); 
		}

	}

	cout<<InitialState<<"->";
	for(int i=2;i<=sol.size()-1;i++)
	{
		for(int j=0;j<sol.size()-2;j++)
		{
			if(sol[j]==i)
				cout<<j<<"->";
		}
	}
	cout<<" \nCost "<<sol[sol.size()-1]<<"\n";
	return 0;  
}
