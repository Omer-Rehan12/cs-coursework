#include <iostream>
#include<vector>
#include<string>
using namespace std;

void maze(vector<vector<int>>& mat, int r, int c, vector<string>& ans, string path, vector<vector<bool>>& visited){
	
	int n= mat.size();
	if( r<0 || c<0 || r>=n || c>=n){
		return;
	}
	
	if(mat[r][c]==0 || visited[r][c]){
		return;
	}
	if(r==n-1 && c==n-1){
		ans.push_back(path);
		return;
	}
	
	visited[r][c]= true;
	
	maze(mat, r+1, c, ans, path+'D', visited);
	maze(mat, r-1, c, ans, path+'U', visited);
	maze(mat, r, c+1, ans, path+'R', visited);
	maze(mat, r, c-1, ans, path+'L', visited);
	
	visited[r][c]= false;
	
}

int main(){
	vector<vector <int>> mat= {
	    {1, 0, 0,0},
        {1, 1, 0,1},
        {1, 1, 0,0},
        {0, 1, 1,1}
    };
    
    string path ="";
    
    vector<string> ans;
    
    int n=mat.size();
    
    vector<vector <bool>> visited(n, vector <bool> (n,false));
    
    maze(mat,0,0,ans,path,visited);
    
    for(string path: ans){
    	cout<<path<<endl;
	}
    
}
