#include <cstdio>
#include <vector>

#define MAX 1000 + 10

using namespace std;

int n, m;
vector<int> MGraph[MAX];
vector<int> ans;
int inDegree[MAX];
int tempDegree[MAX];

void copyDegree() {
    for( int i = 0; i < MAX; i++ ) tempDegree[i] = inDegree[i];
}

bool topSort( vector<int> &vec ) {
    for( int i = 0; i < vec.size(); i++ ) {
        int v = vec[i];
        if( tempDegree[v] == 0 ) {
            for( int j = 0; j < MGraph[v].size(); j++ ) {
                int u = MGraph[v][j];
                tempDegree[u]--;
            }
        }
        else return false;
    }
    return true;
}

int main() {
    scanf( "%d%d", &n, &m );
    for( int i = 0; i < m; i++ ) {
        int a, b;
        scanf( "%d%d", &a, &b );
        MGraph[a].push_back( b );
        inDegree[b]++;
    }

    int k, v;
    scanf( "%d", &k );
    for( int i = 0; i < k; i++ ) {
        copyDegree();
        vector<int> vec;
        for( int j = 0; j < n; j++ ) {
            scanf( "%d", &v );
            vec.push_back( v );
        }
        if( !topSort( vec ) ) { ans.push_back( i ); }
    }

    for( int i = 0; i < ans.size(); i++ ) {
        if( i == 0 ) printf( "%d", ans[i] );
        else printf( " %d", ans[i] );
    }
    return 0;
}

