#include<iostream>
#include<stdio.h>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
void insertion(int A[],int n,string s,int choice){
	if(choice==1){
		int i,j,key;
			for(j=1;j<n;j++){
				key=A[j];
				i=j-1;
				while(i>-1&&A[i]>key){
					A[i+1]=A[i];
					i--;
				}
				A[i+1]=key;
			}
		}
	for(int i=0;i<n;i++){
		cout<<A[i]<<"\n";
	}	
}
int main(){
	std::ifstream fp ("num.txt");
	std::string s;
	int A[100];
	int t=0;
	while(std::getline(fp,s)){
		std::istringstream l(s);
		if(!(l>>A[t])){
			break;
		}
	cout<<"Number"<<A[t]<<"\n";
	t++;	
	}

	insertion(A,t,"HI",1);	
	return 0;
}
