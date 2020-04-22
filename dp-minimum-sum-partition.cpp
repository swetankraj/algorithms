#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int R=0;

int getrange(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    return sum;
}

void initialize(vector<vector<bool>> &dp, int n, int range){
    for(int i=0; i<n; i++){
        for(int j=0; j<range; j++){
            if(i==0) dp[i][j]=0;
            if(j==0) dp[i][j]=1;
        }
    }
}

void subsetsum(vector<vector<bool>> &dp, int arr[], int n, int range){
    for(int i=1; i<n; i++){
        for(int j=1; j<range; j++){
            if(arr[i-1]<=j){
                dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
}

int main() {
	int t; cin>>t;
	while(t--){
	    int n; cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        int x; cin>>x;
	        arr[i]=x;
	    }
	    int range=getrange(arr, n);
	    vector<vector<bool>> dp(n+1, vector<bool>(range+1));
	    R=range+1;
	    initialize(dp, n+1, range+1);

        cout<<"initialize"<<endl;
	    for(int i=0;i<=n;i++){
            for(int j=0; j<=range; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
	    }
	    cout<<endl;

	    subsetsum(dp, arr, n+1, range+1);

        cout<<"subsetsum"<<endl;
	    for(int i=0;i<=n;i++){
            for(int j=0; j<=range; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
	    }
	    cout<<endl;

	    vector<int> myvec;
	    for(int j=0; j<=range/2; j++){
	        if(dp[n][j])
	        myvec.push_back(j);
	    }
	    cout<<"my vector"<<endl;
	    for(auto x: myvec) cout<<x<<" ";
	    cout<<endl;
	    int mini=INT_MAX;
	    for(int i=0; i<myvec.size(); i++){
	        int x=range-(2*myvec[i]);
	        mini=min(mini,x);
	    }
	    cout<<mini<<"\n";
	}
	return 0;
}
