#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;


int kadanes(int val[], int n){
    int cmax=val[0], gmax=val[0];
    for(int i=1; i<n; i++){
        cmax=max(val[i], val[i]+cmax);
        gmax=max(cmax, gmax);
    }
    return gmax;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int val[n];
        for(int i=0; i<n; i++){ int x; cin>>x; val[i]=x; }
        int ans=kadanes(val,n);
        cout<<ans<<"\n";
    }
}
