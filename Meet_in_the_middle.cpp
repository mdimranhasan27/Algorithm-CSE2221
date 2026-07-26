#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

vector<ll> generateSubsetSums(const vector<ll>& a, int l, int r) {
    vector<ll> sums = {0};

    for (int i = l; i < r; i++) {
        int sz = sums.size();

        for (int j = 0; j < sz; j++) {
            sums.push_back(sums[j] + a[i]);
        }
    }
    return sums;
}

ll subsetSum(const vector<ll>& a, ll S) {
    int n = a.size();

    vector<ll> left = generateSubsetSums(a, 0, n / 2);
    vector<ll> right = generateSubsetSums(a, n / 2, n);

    sort(right.begin(), right.end());

    ll ans = 0;
    ll cnt=0;
    for (ll x : left) {
        if (x > S){ continue; }

        auto it = upper_bound(right.begin(), right.end(), S - x);

        if (it != right.begin()) {
            --it;
            cnt++;
            ans = max(ans, x + *it);
        }
    }
    cout<<cnt<<"\n";
    return ans;
   
}

int main() {
    vector<ll> a = {3, 34, 2, 12, 5, 1};
    ll S = 10;

    cout << subsetSum(a, S) << '\n';

    return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;

// Optimized generation of subset sums in O(2^n) instead of O(n * 2^n)
void generateSubsetStringSums(const std::vector<ll>& arr, int start, int end, std::vector<ll>& sums) {
    sums.push_back(0);
    for (int i = start; i < end; ++i) {
        int current_size = sums.size();
        for (int j = 0; j < current_size; ++j) {
            sums.push_back(sums[j] + arr[i]);
        }
    }
}

ll solveSubsetSum(const std::vector<ll>& a, int n, ll S) {
    std::vector<ll> X, Y;
    X.reserve(1 << (n / 2));
    Y.reserve(1 << (n - n / 2));

    // Generate subset sums for both halves safely
    generateSubsetStringSums(a, 0, n / 2, X);
    generateSubsetStringSums(a, n / 2, n, Y);

    // Sort Y for binary search
    std::sort(Y.begin(), Y.end());

    ll max_sum = 0;

    // Binary search using upper_bound (safer and cleaner)
    for (ll x_sum : X) {
        if (x_sum <= S) {
            // Find the first element strictly greater than (S - x_sum)
            auto it = std::upper_bound(Y.begin(), Y.end(), S - x_sum);
            
            // If it's not the beginning, the previous element is the best match
            if (it != Y.begin()) {
                ll y_sum = *(--it);
                if (x_sum + y_sum > max_sum) {
                    max_sum = x_sum + y_sum;
                }
            }
        }
    }
    return max_sum;
}

int main() {
    // Optimize standard I/O operations for speed
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::vector<ll> a = {3, 34, 4, 12, 5, 2};
    ll S = 10;
    
    std::cout << "Largest value smaller than or equal to given sum is " 
              << solveSubsetSum(a, a.size(), S) << "\n";
              
    return 0;
}
*/