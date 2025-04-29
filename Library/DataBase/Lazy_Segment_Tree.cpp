// https://github.com/Linilys/cpp
template <typename T>
class LazySegmentTree {
private:
    int n;
    vector<T> tree, lazy;
    T identityTree, identityLazy;
    function<T(T, T)> operation; // 演算 (範囲クエリ用)
    function<T(T, T)> applyLazy; // 遅延適用演算

    // 遅延を伝搬
    void propagate(int node, int start, int end) {
        if (lazy[node] != identityLazy) {
            // 遅延値をノードに反映
            tree[node] = applyLazy(tree[node], lazy[node] * (end - start + 1));
            if (start != end) {
                // 子ノードに遅延値を伝播
                lazy[2 * node + 1] = applyLazy(lazy[2 * node + 1], lazy[node]);
                lazy[2 * node + 2] = applyLazy(lazy[2 * node + 2], lazy[node]);
            }
            // 自ノードの遅延値をクリア
            lazy[node] = identityLazy;
        }
    }

    // 範囲更新
    void updateRange(int node, int start, int end, int l, int r, T value) {
        propagate(node, start, end);
        if (r < start || end < l) return; // 範囲外
        if (l <= start && end <= r) {
            // 完全に範囲内
            lazy[node] = applyLazy(lazy[node], value);
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node + 1, start, mid, l, r, value);
        updateRange(2 * node + 2, mid + 1, end, l, r, value);
        tree[node] = operation(tree[2 * node + 1], tree[2 * node + 2]);
    }

    // 範囲クエリ
    T queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (r < start || end < l) return identityTree; // 範囲外
        if (l <= start && end <= r) return tree[node]; // 完全に範囲内
        int mid = (start + end) / 2;
        T leftQuery = queryRange(2 * node + 1, start, mid, l, r);
        T rightQuery = queryRange(2 * node + 2, mid + 1, end, l, r);
        return operation(leftQuery, rightQuery);
    }

public:
    // コンストラクタ
    LazySegmentTree(int size, T identityT, T identityL, function<T(T, T)> op, function<T(T, T)> applyL)
        : identityTree(identityT), identityLazy(identityL), operation(op), applyLazy(applyL) {
        n = size;
        tree.assign(4 * n, identityTree);
        lazy.assign(4 * n, identityLazy);
    }

    // 範囲更新
    void update(int l, int r, T value) {
        updateRange(0, 0, n - 1, l, r, value);
    }

    // 範囲クエリ
    T query(int l, int r) {
        return queryRange(0, 0, n - 1, l, r);
    }
};
