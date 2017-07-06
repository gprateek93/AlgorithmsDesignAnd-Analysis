#include <bits/stdc++.h>
using namespace std;

long long knapsack(int n, vector<int> wt, int m, vector<int> val){
    vector<vector<int> > k(m+1,vector<int>(n+1,0));
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(wt[i-1]<=j)
                k[i][j] = max(val[i-1] + k[i-1][j-wt[i-1]],  k[i-1][j]);
           else
                 k[i][j] = k[i-1][j];
        }
    }
    return k[m][n];
}

int main(){
    ifstream myfile;
    myfile.open("knapsack1.txt");
    string input;
    getline(myfile,input);
    int n,m;
    istringstream ss(input);
    ss>>n;
    ss>>m;
    vector<int> wt(m,0);
    vector<int> val(m,0);
    int i = 0;
    while(getline(myfile,input)){
        int v,w;
        istringstream s(input);
        s>>v;
        s>>w;
        wt[i] = w;
        val[i] = v;
        i++;
    }
    cout<<knapsack(n,wt,m,val);
    return 0;
} 
