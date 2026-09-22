class Solution {
public:
//try again
    struct Node {
        int prod;
        long long cnt[5];
        Node() {
            prod = 1;
            for(int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };
    int n, k;
    vector<Node> seg;
    Node merge(Node left, Node right) {
        Node res;
        res.prod = (left.prod * right.prod) % k;
        for(int r = 0; r < k; r++) {
            res.cnt[r] = left.cnt[r];
        }
        for(int r = 0; r < k; r++) {
            int nr = (left.prod * r) % k;
            res.cnt[nr] += right.cnt[r];
        }
        return res;
    }
    void build(int node, int l, int r, vector<int>& nums) {
        if(l == r) {
            int rem = nums[l] % k;
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            int rem = val % k;
            seg[node] = Node();
            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;
            return;
        }
        int mid = (l + r) / 2;
        if(idx <= mid) {
            update(node * 2, l, mid, idx, val);
        }
        else {
            update(node * 2 + 1, mid + 1, r, idx, val);
        }
        seg[node] = merge(seg[node * 2], seg[node * 2 + 1]);
    }
    Node query(int node, int l, int r, int ql, int qr) {
        if(r < ql || qr < l) {
            return Node();
        }
        if(ql <= l && r <= qr) {
            return seg[node];
        }
        int mid = (l + r) / 2;
        Node left = query(node * 2, l, mid, ql, qr);
        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        this->n = nums.size();
        this->k = k;
        seg.resize(4 * n);
        build(1, 0, n - 1, nums);
        vector<int> ans;
        for(auto &q : queries) {
            int idx = q[0];
            int val = q[1];
            int strt = q[2];
            int x = q[3];
            nums[idx] = val;
            update(1, 0, n - 1, idx, val);
            Node res = query(1, 0, n - 1, strt, n - 1);
            ans.push_back(res.cnt[x]);
        }
        return ans;
    }
};