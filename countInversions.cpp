#include <bits/stdc++.h>
using namespace std;

long long countInversionsConquer(int num[], int temp[], int start, int mid, int end){
	long long count = 0;
	int i = start, j = mid, k = start;
	while((i<=mid-1)&&(j<=end)){
		if(num[i]<num[j]){
			temp[k++] = num[i++];
		}
		else{
			temp[k++]=num[j++];
			count += mid-i;
		}
	}
	while(i<=mid-1){
		temp[k++] = num[i++];
	}
	while(j<=end){
		temp[k++] = num[j++];
	}
	for(i = start; i<=end; i++){
		num[i] = temp[i];
	}
	return count;
}

long long countInversionsDivide(int num[], int temp[], int start, int end){
	int mid;
	long long count = 0;
	if(start<end){
		mid = start + (end - start)/2;
		count +=countInversionsDivide(num,temp,start,mid);
		count +=countInversionsDivide(num,temp,mid+1,end);
		count +=countInversionsConquer(num,temp,start,mid+1,end);
	}
	return count;
}

long long countInversions(int num[], int n){
	int *temp = (int *)malloc(sizeof(int)*n);
	return countInversionsDivide(num,temp,0,n-1);
}

int myint(string s){
	stringstream ss;
	ss.str(s);
	int res;
	ss>>res;
	return res;
}

int main(){
	int num[100000];
	string input;
	ifstream integers;
	int i = 0;
	integers.open("Integers.txt");
	while(!integers.eof()){
		getline(integers,input);
		num[i++] = myint(input);
	}
	integers.close();
	cout<<countInversions(num,100000);
}
