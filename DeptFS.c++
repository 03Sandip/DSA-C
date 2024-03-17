#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int node, int vis[]) {
    vis[node] = 1;
    cout<<node<<" ";
   for(auto i:adj[node]){
    if(!vis[i]){
        dfs(adj,i,vis);
    }
   }
}

int main(){
    vector<vector<int>> a= {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2, 4},
        {3, 5},
        {4}
    };

    int vis[a.size()] = {0}; 

    for(int i = 0; i < a.size(); i++){
        if(!vis[i]){
            dfs(a, i, vis);
        }
    }
    return 0;
} 
