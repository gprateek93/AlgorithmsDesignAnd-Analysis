#include <bits/stdc++.h>
using namespace std;

long long knapsack(int n, vector<int> wt, int m, vector<int> val){
    vector<int> k(n+1,0);
    for(int i = 1; i<=m; i++){
        for(int j = n; j>=wt[i]; j--){
            k[j] = max(k[j],val[i]+k[j-wt[i]]);
        }
    }
    return k[n];
}

int main(){
    ifstream myfile;
    myfile.open("knapsack_big.txt");
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
