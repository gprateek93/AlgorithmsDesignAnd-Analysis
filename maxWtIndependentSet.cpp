#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream myfile;
    myfile.open("mwis.txt");
    string input;
    getline(myfile,input);
    int n;
    istringstream ss(input);
    ss>>n;
    vector<int> weight(n+1,0);
    vector<int> cumWeight(n+1,0);
    int i = 1;
    while(getline(myfile,input)){
        istringstream s(input);
        int w;
        s>>w;
        weight[i] = w;
        i++;
    }
    cumWeight[1] = weight[1];
    for(int i = 2; i<=n; i++){
        cumWeight[i] = max(cumWeight[i-1],cumWeight[i-2]+weight[i]);
    }
    set<int> maxWtIndSet;
    i = n;
    while(i>=1){
        if(cumWeight[i] == cumWeight[i-1])
            i--;
        else{
            maxWtIndSet.insert(i);
            i-=2;
        }
    }
    int test[] = {1, 2, 3, 4, 17, 117, 517, 997};
    vector<int> res(8,0);
    for(int i = 0; i< 8; i++){
        if(maxWtIndSet.find(test[i])!=maxWtIndSet.end()){
            res[i] = 1;    
        }
        cout<<res[i]<<" ";
    }
    return 0;
}
