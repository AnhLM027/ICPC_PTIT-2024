#include<bits/stdc++.h>
#define MOD 1000000007
#define maxn 200005
#define maxx 100000009
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;



vector<int> adj[maxn];
int parent[maxn], size[maxn];
bool added[maxn];

int find(int u) {
    if (u == parent[u]) return u;
    int tmp = find(parent[u]);
    parent[u] = tmp;
    return tmp;
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return 0;
    if (size[u] < size[v]) {
        swap(u, v);// uu tien thg u co size lon hon

    }
    size[u] += size[v];
    parent[v] = u;
    return 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        size[i] = 0;
        added[i] = false;
    }
    vector<string> res(n);
    int c = 0;
    for (int i = n - 1; i >= 0; i--) {
        int u = p[i];
        added[u] = true;
        c++;
        for (int v : adj[u]) {
            if (added[v]) {
                if (find(u) != find(v)) {
                    Union(u, v);
                    c--;
                }
            }
        }
        if (c == 1) {
            res[i] = "YES";
        }
        else {
            res[i] = "NO";
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
}