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

void solve(bool visited[], int s, vector<int> al[]){

    visited[s]=true;
    //q.push(s);
    cout<<s<<" ";

    for(int i=0; i<al[s].size(); i++){
        if(!visited[al[s][i]]) solve(visited, al[s][i], al);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin>>n>>m>>k; //k is starting vertex;
    vector<int> al[n+1];
    bool visited[n+1]; memset(visited, false, sizeof(visited));

    getinput(m, al);
    solve(visited, k, al); cout<<endl;
    printutil(n, al);

    return 0;
}


