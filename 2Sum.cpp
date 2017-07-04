#include <bits/stdc++.h>
using namespace std;

int main(){
    map <long long,int> mymap,found;
    ifstream myfile;
    myfile.open("HashInt.txt");
    string input;
    while(getline(myfile,input)){
        istringstream ss(input);
        int n;
        ss>>n;
        if(mymap.find(n)==mymap.end()){
            mymap[n] = 1;
        }
    }
    vector<long long> targets;
    for(int i = -10000; i<=10000; i++){
        targets.push_back(i);
    }
    long long res = 0;
    map<long long, int> :: iterator it;
    for(it = mymap.begin(); it!=mymap.end(); it++){
        long long x = it -> first;
        vector<long long> :: iterator it_v;
        for(it_v = targets.begin(); it_v != targets.end(); it_v++){
            int y = (*it_v) - x;
            if(x!=y){
                if(mymap.find(y)!=mymap.end()){
                    found[(*it_v)] = 1;
                }
            }
        }
    }
    for(it = found.begin(); it!=found.end(); it++){
        res += it->second;
    }
    cout<<res<<endl;
    return 0;
}
