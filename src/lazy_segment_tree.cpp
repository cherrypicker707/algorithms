#include <vector>
#include <algorithms/lazy_segment_tree.hpp>

typedef std::vector<bool> vbool;
typedef long long ll;
typedef std::vector<ll> vll;

LazySegmentTree::LazySegmentTree(const vll &array)
{
    n = array.size();
    tree = vll(4 * n, 0);
    lazy = vll(4 * n, 0);
    equal = vbool(4 * n, false);

    construct_with_recursion(0, 0, n, array);
}

void LazySegmentTree::add(ll left, ll right, ll value)
{
    add_with_recursion(0, 0, n, left, right, value);
}

void LazySegmentTree::set(ll left, ll right, ll value)
{
    set_with_recursion(0, 0, n, left, right, value);
}

ll LazySegmentTree::get_range_sum(ll left, ll right)
{
    return get_range_sum_with_recursion(0, 0, n, left, right);
}

void LazySegmentTree::construct_with_recursion(ll u, ll tree_left, ll tree_right, const vll &array)
{
    if(tree_right - tree_left == 1)
    {
        tree[u] = array[tree_left];
        return;
    }

    ll tree_mid = (tree_left + tree_right) / 2;
    construct_with_recursion(2 * u + 1, tree_left, tree_mid, array);
    construct_with_recursion(2 * u + 2, tree_mid, tree_right, array);
    tree[u] = tree[2 * u  + 1] + tree[2 * u + 2];
}

void LazySegmentTree::add_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right, ll value)
{
    if(right <= tree_left || left >= tree_right)
        return;

    if(left <= tree_left && right >= tree_right)
    {
        tree[u] += (tree_right - tree_left) * value;
        lazy[u] += value;
        return;
    }

    push(u, tree_left, tree_right);

    ll tree_mid = (tree_left + tree_right) / 2;
    add_with_recursion(2 * u + 1, tree_left, tree_mid, left, right, value);
    add_with_recursion(2 * u + 2, tree_mid, tree_right, left, right, value);
    tree[u] = tree[2 * u + 1] + tree[2 * u + 2];
}

void LazySegmentTree::set_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right, ll value)
{
    if(right <= tree_left || left >= tree_right)
        return;

    if(left <= tree_left && right >= tree_right)
    {
        tree[u] = (tree_right - tree_left) * value;
        lazy[u] = value;
        equal[u] = true;
        return;
    }

    push(u, tree_left, tree_right);

    ll tree_mid = (tree_left + tree_right) / 2;
    set_with_recursion(2 * u + 1, tree_left, tree_mid, left, right, value);
    set_with_recursion(2 * u + 2, tree_mid, tree_right, left, right, value);
    tree[u] = tree[2 * u + 1] + tree[2 * u + 2];
}

ll LazySegmentTree::get_range_sum_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right)
{
    if(right <= tree_left || left >= tree_right)
        return 0;

    if(left <= tree_left && right >= tree_right)
        return tree[u];

    push(u, tree_left, tree_right);

    ll tree_mid = (tree_left + tree_right) / 2;
    ll left_value = get_range_sum_with_recursion(2 * u + 1, tree_left, tree_mid, left, right);
    ll right_value = get_range_sum_with_recursion(2 * u + 2, tree_mid, tree_right, left, right);
    return left_value + right_value;
}

void LazySegmentTree::push(ll u, ll tree_left, ll tree_right)
{
    ll tree_mid = (tree_left + tree_right) / 2;

    if(equal[u])
    {
        tree[2 * u + 1] = (tree_mid - tree_left) * lazy[u];
        tree[2 * u + 2] = (tree_right - tree_mid) * lazy[u];

        lazy[2 * u + 1] = lazy[u];
        lazy[2 * u + 2] = lazy[u];
        equal[2 * u + 1] = true;
        equal[2 * u + 2] = true;

        lazy[u] = 0;
        equal[u] = false;
        return;
    }

    tree[2 * u + 1] += (tree_mid - tree_left) * lazy[u];
    tree[2 * u + 2] += (tree_right - tree_mid) * lazy[u];

    lazy[2 * u + 1] += lazy[u];
    lazy[2 * u + 2] += lazy[u];

    lazy[u] = 0;
}
