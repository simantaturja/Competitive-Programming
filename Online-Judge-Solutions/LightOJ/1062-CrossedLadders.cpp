#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;

int main() {
    int tc;
    scanf("%d", &tc);
    for ( int kase = 1; kase <= tc; ++kase ) {
        double x, y, c;
        scanf("%lf %lf %lf", &x, &y, &c);
        double w;
        double lo = 0, hi = 1e18;
        double mid;
        int iter = 1;
        while ( iter <= 100 ) {
            mid = (hi + lo) / 2;
            double p = sqrt(x * x - mid * mid);
            double q = sqrt(y * y - mid * mid);
            double ct = (p * q) / (p + q);
            if ( ct == c ) break;
            if ( ct > c ) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
            iter++;
        }
        printf("Case %d: %.8lf\n", kase, mid);
    }
    return 0;
}
