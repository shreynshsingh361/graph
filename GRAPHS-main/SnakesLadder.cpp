#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int u,v;
    int snakes,ladders;
    cin>>ladders;
    map<int,int>lad;
    map<int,int>snak;
    for(int i=0;i<ladders;i++)
    {
        cin>>u>>v;
        lad[u]=v;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++)
    {
        cin>>u>>v;
        snak[u]=v;
    }
    queue<int>q;
    q.push(1);
    int moves=0;
    bool found=false;
    vector<int>vis(101,0);
    vis[1]=1;
    while(!q.empty()&&!found)
    {
        int sz=q.size();
        while(sz--)
        {
            int t=q.front();
            q.pop();
            for(int die=1;die<=6;die++)
            {
                if(die+t==100)
                found=true;
                else if(die+t<=100&&!vis[die+t] && lad[t+die])
                {
                    vis[lad[t+die]]=1;
                    if(lad[t+die==100])
                    found=true;
                    q.push(lad[die+t]);
                }
                else if(die+t<=100&&!vis[die+t] && snak[t+die])
                {
                    vis[snak[t+die]]=1;
                    if(snak[t+die]==100)
                    found=true;
                    q.push(snak[die+t]);
                }
                  else if(die+t<=100&&!vis[die+t] && !lad[t+die]&&!snak[die+t])
                  {
                       vis[t+die]=1;
                    q.push(die+t);
                  }
                
            }
           
        } 
        moves++;
    }
    if(found)
    cout<<moves;
    else cout<<-1;
    return 0;

}
