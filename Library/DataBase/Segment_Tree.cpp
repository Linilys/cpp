// https://github.com/Linilys/cpp

template <typename T>
class SegmentTree {
private:
    int n; // サイズ
    vector<T> tree; // セグメントツリー
    T identity; // 単位元（加算なら0、乗算なら1など）
    function<T(T, T)> operation; // 演算（加算、最小値、最大値など）

    // 再帰的に木を構築する
    void build(const vector<T>& data, int node, int start, int end) {
        if (start == end) {
            // 葉ノード
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    // 再帰的に範囲クエリを処理する
    T query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            // 完全に範囲外
            return identity;
        }
        if (l <= start && end <= r) {
            // 完全に範囲内
            return tree[node];
        }
        // 部分的に範囲内
        int mid = (start + end) / 2;
        T leftResult = query(2 * node + 1, start, mid, l, r);
        T rightResult = query(2 * node + 2, mid + 1, end, l, r);
        return operation(leftResult, rightResult);
    }

    // 再帰的に値を更新する
    void update(int node, int start, int end, int idx, T value) {
        if (start == end) {
            // 葉ノード
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= idx && idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

public:
    SegmentTree(const vector<T>& data, T identityElement, function<T(T, T)> op)
        : identity(identityElement), operation(op) {
        n = data.size();
        tree.resize(4 * n, identity);
        build(data, 0, 0, n - 1);
    }
    // 範囲クエリ
    T query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
    // 値の更新
    void update(int idx, T value) {
        update(0, 0, n - 1, idx, value);
    }
};
