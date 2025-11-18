#include <functional>
#include <vector>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::function<ll (ll, ll)> func;

class SegmentTree
{
public:
    SegmentTree(ll n, func operation = std::plus<ll>(), ll neutral_value = 0);
    SegmentTree(const vll &array, func operation = std::plus<ll>(), ll neutral_value = 0);
    void set(ll position, ll value);
    void add(ll position, ll value);
    ll get_range_value(ll left, ll right);
private:
    void construct_recursively(const vll &array, ll u, ll tree_left, ll tree_right);
    void set_recursively(ll u, ll tree_left, ll tree_right, ll position, ll value);
    void add_recursively(ll u, ll tree_left, ll tree_right, ll position, ll value);
    ll get_range_value_recursively(ll u, ll tree_left, ll tree_right, ll left, ll right);
    const ll n, neutral_value;
    vll tree;
    const func operation;
};
