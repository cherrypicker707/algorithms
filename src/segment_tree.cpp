#include <vector>
#include <algorithms/segment_tree.hpp>

SegmentTree::SegmentTree(ll n) : n(n)
{
    tree = vll(4 * n, 0);
}

SegmentTree::SegmentTree(const vll &array) : n(array.size())
{
    tree = vll(4 * n);

    construct_with_recursion(array, 0, 0, n);
}

void SegmentTree::set(ll position, ll value)
{
    set_with_recursion(0, 0, n, position, value);
}

void SegmentTree::add(ll position, ll value)
{
    add_with_recursion(0, 0, n, position, value);
}

ll SegmentTree::get_range_sum(ll left, ll right)
{
    return get_range_sum_with_recursion(0, 0, n, left, right);
}

void SegmentTree::construct_with_recursion(const vll &array, ll u, ll tree_left, ll tree_right)
{
    if(tree_right - tree_left == 1)
    {
        tree[u] = array[tree_left];
        return;
    }

    ll tree_mid = (tree_left + tree_right) / 2;
    construct_with_recursion(array, 2 * u + 1, tree_left, tree_mid);
    construct_with_recursion(array, 2 * u + 2, tree_mid, tree_right);
    tree[u] = tree[2 * u + 1] + tree[2 * u + 2];
}

void SegmentTree::set_with_recursion(ll u, ll tree_left, ll tree_right, ll position, ll value)
{
    if(position < tree_left || position >= tree_right)
        return;

    if(tree_right - tree_left == 1)
    {
        tree[u] = value;
        return;
    }

    ll tree_mid = (tree_left + tree_right) / 2;
    set_with_recursion(2 * u + 1, tree_left, tree_mid, position, value);
    set_with_recursion(2 * u + 2, tree_mid, tree_right, position, value);
    tree[u] = tree[2 * u + 1] + tree[2 * u + 2];
}

void SegmentTree::add_with_recursion(ll u, ll tree_left, ll tree_right, ll position, ll value)
{
    if(position < tree_left || position >= tree_right)
        return;

    if(tree_right - tree_left == 1)
    {
        tree[u] += value;
        return;
    }

    ll tree_mid = (tree_left + tree_right) / 2;
    set_with_recursion(2 * u + 1, tree_left, tree_mid, position, value);
    set_with_recursion(2 * u + 2, tree_mid, tree_right, position, value);
    tree[u] = tree[2 * u + 1] + tree[2 * u + 2];
}

ll SegmentTree::get_range_sum_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right)
{
    if(right <= tree_left || left >= tree_right)
        return 0;

    if(left <= tree_left && right >= tree_right)
        return tree[u];

    ll tree_mid = (tree_left + tree_right) / 2;
    ll sum = 0;
    sum += get_range_sum_with_recursion(2 * u + 1, tree_left, tree_mid, left, right);
    sum += get_range_sum_with_recursion(2 * u + 2, tree_mid, tree_right, left, right);
    return sum;
}
