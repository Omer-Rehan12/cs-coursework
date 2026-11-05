#include <iostream>
#include <string>
using namespace std;

void search(string text, string pat){
	int n= text.length();
	int m= pat.length();
	
	for(int i=0; i<=n-m; i++){
		int j=0;
		
		while(j<m && text[i+j]==pat[j])
		j++;
		
		if(j==m){
			cout<<"Pattern found at index "<<i<<endl;
			return;
		}
	}
	
	cout<<"pattern not found."<<endl;
}

int main(){
	
	string text= "GGGTGATTGATTTTGA";
	string pat="TGATT";
	
	search(text, pat);
	
}