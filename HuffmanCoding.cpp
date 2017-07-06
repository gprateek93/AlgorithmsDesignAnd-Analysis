#include <bits/stdc++.h>
using namespace std;

struct minHeapNode{
    int num;
    long long weight;
    minHeapNode *left, *right;
    minHeapNode(int n, long long wt){
        this->num = n;
        this->weight = wt;
        left = NULL;
        right = NULL;
    }
};

void printCode(int count, vector<int> &countArray, struct minHeapNode *root){
    if(!root)
        return;
    if(root->num != -1){
        countArray[root->num] = count;
    }
    printCode(count+1, countArray, root->left);
    printCode(count+1, countArray, root->right);
}
struct compare{
    bool operator () (minHeapNode *a, minHeapNode *b){
        return a->weight>b->weight;
    }
};

void huffman(vector<long long> &weight, vector<int> &countArray){
    struct minHeapNode *left, *right, *par;
    priority_queue<minHeapNode*, vector<minHeapNode*>, compare> pq;
    for(int i = 0; i<weight.size(); i++){
        pq.push(new minHeapNode(i,weight[i]));
    }
    while(pq.size()!=1){
        left = pq.top();
        pq.pop();
        right = pq.top();
        pq.pop();
        par = new minHeapNode(-1,left->weight+right->weight);
        par->left = left;
        par->right = right;
        pq.push(par);
    }
    printCode(0,countArray,pq.top());
    sort(countArray.begin(),countArray.end());
}

int main(){
    ifstream myfile;
    myfile.open("huffman.txt");
    string input;
    getline(myfile,input);
    istringstream ss(input);
    int n;
    ss>>n;
    vector<long long> weight(n,0);
    vector<int> countArray(n,0);
    int i = 0;
    while(getline(myfile,input)){
        istringstream s(input);
        long long w;
        s>>w;
        weight[i] = w;
        i++;
    }
    huffman(weight,countArray);
    cout<<countArray[0]<<" "<<countArray[n-1];
    return 0;
}
