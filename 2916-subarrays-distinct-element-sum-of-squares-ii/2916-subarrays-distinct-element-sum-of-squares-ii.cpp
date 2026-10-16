class Solution {
public:
    static const int mod = 1e9+7;
    struct Node{
        long long sum;
        long long sq;
        long long lazy;
    };
    vector<Node>tree;
    void apply(int node, int l, int r, long long delta) {
        long long len = r - l + 1;
        tree[node].sq = (tree[node].sq + 2LL * delta * tree[node].sum % mod + delta * delta % mod * len % mod) % mod;
        tree[node].sum = (tree[node].sum + delta * len) % mod;
        tree[node].lazy += delta;
    }
    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;
        int mid = (l + r) / 2;
        long long delta = tree[node].lazy;
        apply(2 * node, l, mid, delta);
        apply(2 * node + 1, mid + 1, r, delta);
        tree[node].lazy = 0;
    }
    void pull(int node) {
        tree[node].sum = (tree[2 * node].sum+tree[2 * node + 1].sum) % mod;
        tree[node].sq = (tree[2 * node].sq+tree[2 * node + 1].sq) % mod;
    }
    void update(int node, int l, int r,int ql, int qr, long long delta) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, delta);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        if (ql <= mid)
            update(2 * node, l, mid, ql, qr, delta);
        if (qr > mid)
            update(2 * node + 1, mid + 1, r, ql, qr, delta);
        pull(node);
    }
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n + 5, Node{});
        unordered_map<int, int> last;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int prev = -1;
            if (last.count(nums[i]))
                prev = last[nums[i]];
            update(1, 0, n - 1, prev + 1, i, 1);
            last[nums[i]] = i;
            ans = (ans + tree[1].sq) % mod;
        }
        return ans;
    }
};