#include <iostream>
#include <string>
using namespace std;

void build(string pat, char lastOcc[]){
	
	for(int i=0; i<256; i++){
		
		lastOcc[i]=-1;
	}
	
	for(int i=0; i<pat.length(); i++){
		lastOcc[(unsigned char)pat[i]]=i;
	}
}

void boyer(string text, string pat){
	
	int n=text.length();
	int m=pat.length();
	
	char lastOcc[256];
	
	build(pat, lastOcc);
	
	int i=0;
	
	while(i<=n-m){
		
		int j=m-1;
		
		while(j>=0 && pat[j]==text[i+j]){
			j--;
		}
		
		if(j<0){
			cout<<"Pattern found at index "<<i<<endl;
			return;
		}
		
		char badChar= text[i+j];
		
		int shift= j-lastOcc[(unsigned char)badChar];
		
		if(shift<1) shift=1;
		
		i+=shift;
		
	}
	cout<<"Pattern not found"<<endl;
}

int main(){
	
	string text= "GGGTGATTGATTTTGA";
	string pat="TGATT";
	
	boyer(text, pat);
	
	return 0;
}