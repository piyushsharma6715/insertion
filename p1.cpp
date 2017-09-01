#include<iostream>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void insertion(int A[][2],int n){
	ofstream a ("asc.txt");
	ofstream b("desc.txt");
	int i,j,key,key1;
	for(j=1;j<n;j++){
		key=A[j][0];
		key1=A[j][1];
		i=j-1;
		while(i>-1&&A[i][0]>key){
			A[i+1][0]=A[i][0];
			A[i+1][1]=A[i][1];
			i--;
		}
		A[i+1][0]=key;
		A[i+1][1]=key1;
	}
	for(int i=0;i<n;i++){
		a<<A[i][0]<<"\n";
	}
	a.close();
	for(int i=n-1;i>=0;i--){
		b<<A[i][0]<<"\n";
	}
	b.close();
	ofstream c("priority.txt");
	for(j=1;j<n;j++){
		key=A[j][0];
		key1=A[j][1];
		i=j-1;
		while(i>-1&&A[i][1]>key1){
			A[i+1][1]=A[i][1];
			A[i+1][0]=A[i][0];
			i--;
		}
		A[i+1][0]=key;
		A[i+1][1]=key1;
	}
	for(int i=0;i<n;i++){
		c<<A[i][0]<<"\n";
	}
	c.close();
}
int main(){
	std::ifstream fp ("num.txt");
	std::string s;
	int A[100][2];
	int t=0;
	while(std::getline(fp,s)){
		std::istringstream l(s);     //convert string to int 
		if(!(l>>A[t][0]>>A[t][1])){
			break;
		}
	t++;	
	}

	insertion(A,t);	
	return 0;
}
