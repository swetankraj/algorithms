#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

void knapsack(vector<vector<int>> &dp, int n, int w, int wt[], int val[]){
    for(int i=1; i<n; i++){
        for(int j=1; j<w; j++){
            if(wt[i-1]<=j) dp[i][j]=max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
}

int main() {
    int t; cin>>t;
    while(t--){
        int n,w; cin>>n>>w;
        int wt[n], val[n];
        for(int i=0; i<n; i++){ int x; cin>>x; val[i]=x; }
        for(int i=0; i<n; i++){ int x; cin>>x; wt[i]=x; }
        vector<vector<int>> dp(n+1, vector<int>(w+1));
        knapsack(dp, n+1, w+1, wt, val);
        cout<<dp[n][w]<<"\n";
    }
}
