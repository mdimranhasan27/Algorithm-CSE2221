//~imran~
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// for(int i=0;i<n;i++){cin>>v[i];}
void subsetsum(vector<int> &st)
{
    int n = st.size();
    vector<int> sums;
    sums.push_back(0);
    for (int i = 0; i < n; i++)
    { int sz=sums.size();
        for (int j = 0; j < sz; j++)
        {
            sums.push_back(st[i] + sums[j]);
        }
    }
    for (auto x : sums)
    {
        cout << x << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> st = {1, 2, 3, 4};
    subsetsum(st);

    return 0;
}*/
//~imran~

#include <iostream>
#include <vector>

using namespace std;

void generateSubsetsAndSums(const vector<int> &st)
{
    int n = st.size();
    // Total subsets = 2^n
    int total_subsets = 1 << n; 

    cout << "Subset -> Sum\n";
    cout << "-----------------\n";

    // Loop through all numbers from 0 to (2^n - 1)
    for (int mask = 0; mask < total_subsets; mask++)
    {
        int current_sum = 0;
        cout << "{ ";
        
        // Check which bits are set to 1 in the current mask
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) != 0)
            {
                cout << st[i] << " ";
                current_sum += st[i];
            }
        }
        cout << "} -> " << current_sum << "\n";
    }
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> st = {1, 2, 3, 4};
    generateSubsetsAndSums(st);

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

void generate(int idx, vector<int>& a,
              vector<int>& subset, int sum) {

    // Base Case
    if (idx == a.size()) {

        cout << "{ ";
        for (int x : subset) {
            cout << x << " ";
        }
        cout << "} -> Sum = " << sum << '\n';

        return;
    }

    // Take the current element
    subset.push_back(a[idx]);
    generate(idx + 1, a, subset, sum + a[idx]);

    // Backtrack
    subset.pop_back();

    // Don't take the current element
    generate(idx + 1, a, subset, sum);
}

int main() {
    vector<int> a = {1, 2, 3};
    vector<int> subset;

    generate(0, a, subset, 0);

    return 0;
}*/