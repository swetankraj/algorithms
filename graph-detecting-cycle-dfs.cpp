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
    for(int i=0; i<n+1; i++){
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
        //al[y].push_back(x);
    }
}

bool solve(bool visited[], bool recstack[], int s, vector<int> al[]){

    if(!visited[s]){
        visited[s]=true;
        recstack[s]=true;

        for(int i=0; i<al[s].size(); i++){
            if(!visited[al[s][i]] && solve(visited, recstack, al[s][i], al)) return true;
            else if(recstack[al[s][i]]) return true;
        }
    }

    recstack[s]=false;
    return false;
}

bool solveutil(bool visited[], bool recstack[], vector<int> al[], int n){ //if there are disconnected components
    for(int i=0; i<n; i++){
        if(solve(visited, recstack, i, al)) return true;
    }

    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin>>n>>m;
    vector<int> al[n+1];
    bool visited[n+1]; memset(visited, false, sizeof(visited));
    bool recstack[n+1]; memset(recstack, false, sizeof(recstack));

    getinput(m, al);
    if(solveutil(visited, recstack, al, n)) cout<<"Contains cycle";
    else cout<<"No Cycle Present!";
    cout<<endl;
    printutil(n, al);

    return 0;
}


