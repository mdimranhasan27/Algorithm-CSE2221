#include <iostream>
#include <string>
#include <vector>
using namespace std;

void rabinKarpSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    // Edge case: pattern is longer than the text
    if (m > n)
        return;

    // Parameters for Double Hashing
    const int base = 256;              // Alphabet size (ASCII)
    const long long mod1 = 1000000007; // First large prime
    const long long mod2 = 1000000009; // Second large prime

    // Initial hash values
    long long patternHash1 = 0, patternHash2 = 0;
    long long textHash1 = 0, textHash2 = 0;

    // Multipliers for the highest power: base^(m-1) % mod
    long long h1 = 1;
    long long h2 = 1;

    // Precalculate base^(m-1) % mod for rolling hash updates
    for (int i = 0; i < m - 1; i++)
    {
        h1 = (h1 * base) % mod1;
        h2 = (h2 * base) % mod2;
    }

    // Compute initial hashes for the pattern and first window of text
    for (int i = 0; i < m; i++)
    {
        patternHash1 = (base * patternHash1 + text[i]) % mod1;
        patternHash2 = (base * patternHash2 + text[i]) % mod2;

        textHash1 = (base * textHash1 + text[i]) % mod1;
        textHash2 = (base * textHash2 + text[i]) % mod2;
    }

    // Slide the pattern over the text
    for (int i = 0; i <= n - m; i++)
    {

        // If both independent hashes match, verify the actual string
        if (patternHash1 == textHash1 && patternHash2 == textHash2)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern found at index: " << i << std::endl;
            }
        }

        // Calculate hash value for the next window of text
        if (i < n - m)
        {
            // Roll Hash 1
            textHash1 = (base * (textHash1 - text[i] * h1) + text[i + m]) % mod1;
            if (textHash1 < 0)
                textHash1 += mod1; // Handle negative modulo results

            // Roll Hash 2
            textHash2 = (base * (textHash2 - text[i] * h2) + text[i + m]) % mod2;
            if (textHash2 < 0)
                textHash2 += mod2; // Handle negative modulo results
        }
    }
}

int main()
{
    string text;
    string pattern;
    int q; // number of pattern
    cin >> q;
    cin >> text;                // text
    for (int i = 0; i < q; i++) // for q pattern
    {
        cin >> pattern;
        cout << "Searching for '" << pattern << "' in '" << text << "':\n";
        rabinKarpSearch(text, pattern);
    }
    return 0;
}
