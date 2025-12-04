#include <functional>

typedef long long ll;
typedef std::vector<ll> vll;
typedef std::function<bool (ll)> func;

namespace BinarySearch
{
    ll find_first(ll left, ll right, const func &condition);
    ll find(const vll &array, ll value);
};
