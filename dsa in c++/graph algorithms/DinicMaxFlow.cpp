
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    long long cap;
    int rev; // index of reverse edge in adjacency list
    Edge(int _to, long long _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
};

struct Dinic {
    int n;
    vector<vector<Edge>> g;
    vector<int> level;     // level graph
    vector<int> iter;      // iteration pointer used in DFS

    Dinic(int n) : n(n), g(n), level(n), iter(n) {}

    // add directed edge u -> v with capacity c
    void add_edge(int u, int v, long long c) {
        g[u].emplace_back(v, c, (int)g[v].size());
        g[v].emplace_back(u, 0, (int)g[u].size()-1); // reverse edge with 0 initial cap
    }

    // BFS to build level graph
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (const Edge &e : g[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
    }

    // DFS to send flow in level graph
    long long dfs(int v, int t, long long f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < (int)g[v].size(); ++i) {
            Edge &e = g[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                long long d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    // compute max flow from s to t
    long long max_flow(int s, int t) {
        long long flow = 0;
        const long long INF = (1LL<<60);
        while (true) {
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            long long f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // Example usage:
    // Input format (example):
    // n m
    // then m lines: u v cap  (0-based nodes)
    //
    // Example:
    // 4 5
    // 0 1 40
    // 0 2 20
    // 1 2 10
    // 1 3 30
    // 2 3 20
    //
    // Output: maximum flow from 0 to n-1

    int n, m;
    if (!(cin >> n >> m)) return 0;
    Dinic dinic(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long c;
        cin >> u >> v >> c;
        dinic.add_edge(u, v, c);
    }

    int s = 0, t = n - 1;
    long long maxflow = dinic.max_flow(s, t);
    cout << maxflow << "\n";
    return 0;
}
