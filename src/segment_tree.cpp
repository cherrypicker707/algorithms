#include <functional>
#include <vector>
#include <algorithms/segment_tree.hpp>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::function<ll (ll, ll)> func;

SegmentTree::SegmentTree(ll n, const func &operation, ll neutral_value) : n(n), neutral_value(neutral_value), operation(operation)
{
    tree = vll(4 * n, neutral_value);
}

SegmentTree::SegmentTree(const vll &array, const func &operation, ll neutral_value) : n(array.size()), neutral_value(neutral_value), operation(operation)
{
    tree = vll(4 * n);

    construct_recursively(array, 0, 0, n);
}

void SegmentTree::set(ll position, ll value)
{
    set_recursively(0, 0, n, position, value);
}

void SegmentTree::add(ll position, ll value)
{
    add_recursively(0, 0, n, position, value);
}

ll SegmentTree::get_range_value(ll left, ll right)
{
    return get_range_value_recursively(0, 0, n, left, right);
}

void SegmentTree::construct_recursively(const vll &array, ll u, ll tree_left, ll tree_right)
{
    if(tree_right - tree_left == 1)
    {
        tree[u] = array[tree_left];
        return;
    }

    ll tree_mid = (tree_left + tree_right) / 2;
    construct_recursively(array, 2 * u + 1, tree_left, tree_mid);
    construct_recursively(array, 2 * u + 2, tree_mid, tree_right);
    tree[u] = operation(tree[2 * u + 1], tree[2 * u + 2]);
}

void SegmentTree::set_recursively(ll u, ll tree_left, ll tree_right, ll position, ll value)
{
    if(position < tree_left || position >= tree_right)
        return;

    if(tree_right - tree_left == 1)
    {
        tree[u] = value;
        return;
    }

    ll tree_mid = (tree_left + tree_right) / 2;
    set_recursively(2 * u + 1, tree_left, tree_mid, position, value);
    set_recursively(2 * u + 2, tree_mid, tree_right, position, value);
    tree[u] = operation(tree[2 * u + 1], tree[2 * u + 2]);
}

void SegmentTree::add_recursively(ll u, ll tree_left, ll tree_right, ll position, ll value)
{
    if(position < tree_left || position >= tree_right)
        return;

    if(tree_right - tree_left == 1)
    {
        tree[u] += value;
        return;
    }

    ll tree_mid = (tree_left + tree_right) / 2;
    add_recursively(2 * u + 1, tree_left, tree_mid, position, value);
    add_recursively(2 * u + 2, tree_mid, tree_right, position, value);
    tree[u] = operation(tree[2 * u + 1], tree[2 * u + 2]);
}

ll SegmentTree::get_range_value_recursively(ll u, ll tree_left, ll tree_right, ll left, ll right)
{
    if(right <= tree_left || left >= tree_right)
        return neutral_value;

    if(left <= tree_left && right >= tree_right)
        return tree[u];

    ll tree_mid = (tree_left + tree_right) / 2;
    ll value_left = get_range_value_recursively(2 * u + 1, tree_left, tree_mid, left, right);
    ll value_right = get_range_value_recursively(2 * u + 2, tree_mid, tree_right, left, right);

    return operation(value_left, value_right);
}
