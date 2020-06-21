#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = (int)1e5 + 10;
vector <int> primes;
bool prime[N + 8];
void sieve() {
    memset(prime, 1, sizeof(prime));
    prime[1] = prime[0] = 0;
    for (int i = 3; i * i < N; i += 2) {
        if (prime[i]) {
            for (int j = i * i; j < N; j += i) {
                prime[j] = 0;
            }
        }
    }
    primes.push_back(2);
    for (int i = 3; i < N; i += 2) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
}
int main() {
    sieve();
    int tc;
    scanf("%d", &tc);
    int kase = 1;
    while(tc--) {
        printf("Case %d: ", kase++);
        ll n;
        int k;
        scanf("%lld %d", &n, &k);
        set <ll> p;
        int psz = (int)primes.size();
        for (int i = 0; i < k; ++i) {
            ll x;
            cin >> x;
            x = abs(x);
            for (int j = 0; primes[j] * primes[j] <= x && j < psz; ++j) {
                if (x % primes[j] == 0) {
                    p.insert((ll)primes[j]);
                    while (x % primes[j] == 0) {
                        x /= primes[j];
                    }
                }
            }
            if (x > 1) {
                p.insert(x);
            }
        }
        int sz = (int)p.size();
        ll result = n;
        for (ll msk = 1; msk < (1 << sz); ++msk) {
            int bits = 0;
            ll mult = 1;
            ll i = 0;
            for (auto it : p) {
                if (msk & (1 << i)) {
                    ++bits;
                    mult *= it; 
                }
                ++i;
            }
            ll ret = (n / mult);
            if (bits % 2 != 0) {
                result -= ret;
            } else {
                result += ret;
            }
        }
        printf("%lld\n", result);
    }
    return 0;
}