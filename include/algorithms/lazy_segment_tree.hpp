#pragma once
#include <vector>

typedef std::vector<bool> vbool;
typedef long long ll;
typedef std::vector<ll> vll;

class LazySegmentTree
{
public:
    LazySegmentTree(const vll &array);
    void add(ll left, ll right, ll value);
    void set(ll left, ll right, ll value);
    ll get_range_sum(ll left, ll right);

private:
    void construct_with_recursion(ll u, ll tree_left, ll tree_right, const vll &array);
    void add_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right, ll value);
    void set_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right, ll value);
    ll get_range_sum_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right);
    void push(ll u, ll tree_left, ll tree_right);

    ll n;
    vll tree, lazy;
    vbool equal;
};
