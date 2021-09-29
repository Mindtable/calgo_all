#include <iostream>
#include <vector>

#define ld long double
#define ll long long

ld get_next(ld h_i, ld h_i_1){
    return 2*h_i - h_i_1 + 1;
}

int main() {
    const ld eps = 0.00000000001;
    ll n;
    ld A;
    std::vector<ld> garland;
    std::cin >> n >> A;
    garland.push_back(A);
    for (ll j = 1; j < n; j++){
        garland.push_back(0.0);
    }
    ld left_bound = 0;
    ld right_bound = 1000000;
    ld min_ex = A;
    while (right_bound - left_bound >= eps){
        ld middle = (right_bound + left_bound) / 2;
//        std::cout << middle << std::endl;
        garland[1] = middle;
        ll count_zero = 0;
        ll count_neg = 0;
        for (ll j = 2; j < n; j++){
            garland[j] = 2*garland[j - 1] - garland[j - 2] + 2;
            // potential bug
            if (garland[j] == 0){
                count_zero++;
            }
            if (garland[j] < 0) {
                count_neg++;
            }
        }
        if (count_neg > 0 || count_zero > 1){
            left_bound = middle;
        }
        else { //(count_zero <= 1)
            min_ex = garland[n - 1];
            right_bound = middle;
        }
    }
    std::cout.precision(2);
    std::cout << std::fixed << min_ex;
    return 0;
}
