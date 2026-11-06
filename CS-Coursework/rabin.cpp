#include <iostream>
#include <string>
using namespace std;

void rabin(string text, string pat){
	
	int n=text.length();
	int m=pat.length();
	
	int winHash=0;
	int patHash=0;
	
	for(int i=0; i<m; i++){
		winHash+=text[i];
		patHash+=pat[i];
	}
	
	for(int i=0; i<=n-m; i++){
		
		if(patHash==winHash){
			bool match=true;
			for(int j=0; j<m; j++){
				if(text[i+j]!=pat[j]){
					match=false;
					break;
				}
			}
			if(match){
				cout<<"Pattern found at index "<<i<<endl;
				return;
			}	
			
			}
			if(i<n-m){
				winHash= winHash-text[i]+text[i+m];
			}
		}
		
	cout<<"Pattern not found."<<endl;
	
	
}


int main(){
	string text= "GGGTGATTGATTTTGA";
	string pat="TGATT";
	
	rabin(text, pat);
	
	return 0;
}