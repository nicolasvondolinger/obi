#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 1000;

vector<vector<int>> amizades(MAX);
bool visitados [MAX];

void dfs(int n){
    visitados[n] = 1;
    
    for(auto w: amizades[n])if(!visitados[w]){
        dfs(w);
    }
}

int main(){
    int n, r; cin >> n >> r;
    for(int k = 0; k < r; k++){
        int i, j; cin >> i >> j; i--, j--;
        
        amizades[i].push_back(j);
        amizades[j].push_back(i);
    }
    
    memset(visitados, 0, sizeof(visitados));
    
    int times = 0;
    for(int i = 0; i < n; i++) if(!visitados[i]){
        dfs(i);
        times++;
    }
    
    cout << times << endl;

    return 0;
}
