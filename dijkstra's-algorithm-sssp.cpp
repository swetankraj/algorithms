//Single Source shortest path!

#include <iostream>
#include <unordered_map>
#include <climits>
#include <list>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>


using namespace std;

#define ll long long
#define INF 0x3f3f3f3f

void printutil(int n, vector<int> dist){
    cout<<"Distance from source to vertex"<<endl;
    for(int i=0; i<n; i++){
        cout<<i<<" -> "<<dist[i]<<endl;
    }
}

void getinput(int m, vector<pair<int,int>> al[]){

    for(int i=0; i<m; i++){
        int x,y,w; cin>>x>>y>>w;

        al[x].push_back(make_pair(y, w));
        al[y].push_back(make_pair(x, w));
    }
}

bool solve(vector<pair<int,int>> al[], int k, int n){


    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minhp;
    vector<int> dist(n, INF);

    dist[k]=0;
    minhp.push(make_pair(0, k));

    while(!minhp.empty()){
        int u=minhp.top().second;
        minhp.pop();

        for(auto it: al[u]){
            int v=it.first;
            int w=it.second;

            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                minhp.push(make_pair(dist[v], v));
            }
        }
    }

    printutil(n, dist);

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin>>n>>m>>k;
    vector<pair<int, int>> al[n+1];

    getinput(m, al);
    solve(al, k, n);
    return 0;
}
