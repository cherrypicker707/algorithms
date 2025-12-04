#include <functional>
#include <vector>
#include <algorithms/binary_search.hpp>

#include <iostream>

typedef long long ll;
typedef std::function<bool (ll)> func;

// Finds first integer in range [left, right) which satisfies condition.
ll BinarySearch::find_first(ll left, ll right, const func &condition)
{
    while(left < right)
    {
        ll mid = (left + right) / 2;

        if(condition(mid))
        {
            right = mid;
            continue;
        }

        left = mid + 1;
    }

    return left;
}

ll BinarySearch::find(const vll &array, ll value)
{
    ll n = array.size();

    ll left = 0, right = n;
    while(left < right)
    {
        ll mid = (left + right) / 2;

        if(array[mid] < value)
        {
            left = mid + 1;
            continue;
        }

        if(array[mid] > value)
        {
            right = mid;
            continue;
        }

        return mid;
    }

    return n;
}
