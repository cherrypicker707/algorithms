#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;

class SegmentTree
{
public:
    SegmentTree(ll n);
    SegmentTree(const vll &array);
    void set(ll position, ll value);
    void add(ll position, ll value);
    ll get_range_sum(ll left, ll right);
private:
    void construct_with_recursion(const vll &array, ll u, ll tree_left, ll tree_right);
    void set_with_recursion(ll u, ll tree_left, ll tree_right, ll position, ll value);
    void add_with_recursion(ll u, ll tree_left, ll tree_right, ll position, ll value);
    ll get_range_sum_with_recursion(ll u, ll tree_left, ll tree_right, ll left, ll right);
    const ll n;
    vll tree;
};
