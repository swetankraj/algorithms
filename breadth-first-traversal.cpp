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

void printutil(int n, vector<int> al[]){
    for(int i=1; i<n+1; i++){
        cout<<i<<" -> ";
        for(int j=0; j<al[i].size(); j++){
            cout<<al[i][j]<<" ";
        }
        cout<<'\n';
    }

}

void getinput(int m, vector<int> al[]){

    for(int i=0; i<m; i++){
        int x,y; cin>>x>>y;

        al[x].push_back(y);
        al[y].push_back(x);
    }
}

void solve(bool visited[], int s, queue<int> q, vector<int> al[]){

    visited[s]=true;
    q.push(s);

    while(!q.empty()){
        int k=q.front();
        q.pop();

        cout<<k<<" ";

        for(int i=0; i<al[k].size(); i++){
            if(!visited[al[k][i]]){
                visited[al[k][i]]=true;
                q.push(al[k][i]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin>>n>>m;
    vector<int> al[n+1];
    bool visited[n+1]; memset(visited, false, sizeof(visited));
    queue<int> q;

    getinput(m, al);
    solve(visited, 1, q, al); cout<<endl;
    printutil(n, al);

    return 0;
}
