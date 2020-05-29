/*
    Author : Simanta Deb Turja
    Email : simantaturja@gmail.com
    Website: https://simantaturja.github.io
*/
#include <bits/stdc++.h>
using namespace std;

// ==========Begin typedefs===========
typedef long long ll;
typedef unsigned long long i64;
// ==========End typedefs=============

//==========Functions==============
template <typename T>
T Min (T a, T b, T c) {
    return min(a, min(b, c));
}
template <typename T>
T Min (T a, T b, T c, T d) {
    return min(a, min(b, min(c, d)));
}
template <typename T>
T Max (T a, T b, T c) {
    return max(a, max(b, c));
}
template <typename T>
T Max (T a, T b, T c, T d) {
    return max(a, max(b, max(c, d)));
}
template <typename T>
T Power (T a, T b) {
    
}
// ==========End Functions===========

//===========Constants===============
const int N = (int)1e5 + 10;
const double EPS = 1e-7;
const double PI = acos(-1.0);
//===========End Constants===========

//===========FASTIO==================
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
//===========End FASTIO==============

int main() {
    FASTIO;
    int tc;
    cin >> tc;
    for (int kase = 1; kase <= tc; ++kase) {
        int row, col;
        cin >> row >> col;
        vector <vector <bool> > v(row + 2, vector <bool> (col + 2, 0));
        for (int i = 0; i < row; ++i) {
            int x;
            cin >> x;
            string numbers;
            getline(cin, numbers);
            stringstream ss(numbers);
            int num;
            while (ss >> num) {
                v[x][num] = 1;
            }
        }
        vector <vector <int> > dp(row + 2, vector <int>(col + 2, 0));
        for (int i = 1; i <= row; ++i) {
            for (int j = 1; j <= col; ++j) {
                if (i == 1 && j == 1) {
                    dp[i][j] = 1;
                    continue;
                }
                if (v[i][j]) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        cout << dp[row][col] << "\n";
        if (kase != tc) {
            cout << "\n";
        }
    }
    return 0;
}
