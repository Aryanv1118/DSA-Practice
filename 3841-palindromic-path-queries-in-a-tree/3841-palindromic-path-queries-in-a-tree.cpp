
class Solution {
public:
    vector<vector<int>> adj, up;
    vector<int> tin, tout, par, dep, mask, bit;
    int timer, n, LOG;
    string s;
    void dfs(int u, int p, int d, int m) {
        par[u] = p;
        dep[u] = d;
        mask[u] = m;
        tin[u] = ++timer;
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, d + 1,
                    m ^ (1 << (s[v] - 'a')));
            }
        }

        tout[u] = timer;
    }
    void upd(int i, int x) {
        for (; i <= n; i += i & -i)
            bit[i] ^= x;
    }
    int sum(int i) {
        int x = 0;
        for (; i > 0; i -= i & -i)
            x ^= bit[i];
        return x;
    }
    void rangeUpd(int l, int r, int x) {
        upd(l, x);
        if (r + 1 <= n)
            upd(r + 1, x);
    }
    int getMask(int u) {
        return mask[u] ^ sum(tin[u]);
    }
    int lca(int u, int v) {
        if (dep[u] < dep[v])
            swap(u, v);
        int diff = dep[u] - dep[v];
        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j))
                u = up[j][u];
        }
        if (u == v)
            return u;
        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }
        return par[u];
    }
    vector<bool> palindromePath(
        int n, vector<vector<int>>& edges,
        string s, vector<string>& queries) {
        this->n = n;
        this->s = s;
        timer = 0;
        adj.assign(n, {});
        tin.resize(n);
        tout.resize(n);
        par.resize(n);
        dep.resize(n);
        mask.resize(n);
        bit.assign(n + 2, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        dfs(0, 0, 0, 1 << (s[0] - 'a'));
        LOG = 1;
        while ((1LL << LOG) <= n)
            LOG++;
        up.assign(LOG, vector<int>(n));
        for (int i = 0; i < n; i++)
            up[0][i] = par[i];
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }
        vector<bool> ans;
        for (string &q : queries) {
            stringstream ss(q);
            string op;
            int u, v;
            char c;
            ss >> op >> u;
            if (op == "update") {
                ss >> c;
                int delta =(1 << (s[u] - 'a')) ^(1 << (c - 'a'));
                rangeUpd(tin[u], tout[u], delta);
                s[u] = c;
            } 
            else {
                ss >> v;
                int w = lca(u, v);
                int m = getMask(u) ^ getMask(v)^ (1 << (s[w] - 'a'));
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};
