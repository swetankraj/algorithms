#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, int E, vector<vector<int>> graph);

int main(){
    int t; cin>>t;
    while(t--){
        int V,E;
        cin>>V>>E;
        vector<vector<int>> graph(V, vector<int>(V, 0));

        while(E--){
            int u,v,w;
            cin>>u>>v>>w;
            u--,v--;
            graph[u][v]=w;
            graph[v][u]=w;
        }

        cout<<spanningTree(V, E, graph)<<endl;
    }
    return 0;
}

int findmin(int key[], bool mstset[], int size){
    int globalminimum=INT_MAX;
    int vertex=-1;
    for(int i=0; i<size; i++){
        if(mstset[i]==false && key[i]<globalminimum){
            globalminimum=key[i];
            vertex=i;
        }
    }

    return vertex;
}

int spanningTree(int V,int E,vector<vector<int> > graph)
{
    bool mstset[V];
    int key[V], int parent[V], msum=0;

    for(int i=0; i<V; i++){
        key[i]=INT_MAX; mstset[i]=false;
    }

    key[0]=0;
    parent[0]=-1;

    for(int i=0; i<V; i++){

        int vertex = findmin(key, mstset, V);
        mstset[vertex]=true;

        for(int j=0; j<V; j++){

            if(graph[vertex][j] && mstset[j]==false && graph[vertex][j]<key[j]){
                parent[j]=vertex;
                key[j]=graph[vertex][j];
            }
        }
    }

    for(int x: key) msum+=x;
    return msum;

}
