#include <iostream>
#include <vector>

#define ll long long

int main() {
    ll n;
    std::cin >> n;
    std::vector<ll> data;
    for (ll j = 0; j < n; j++){
        ll value;
        std::cin >> value;
        data.push_back(value);
    }
    ll m;
    std::cin >> m;
    for (ll phase_number = 0; phase_number < m; phase_number++) {
        ll left = -1;
        ll right = n;
        ll key;
        std::cin >> key;
        while (right - left > 1) {
            ll middle = (left + right) / 2;
            if (data[middle] < key) {
                left = middle;
            } else {
                right = middle;
            }
        }
        ll right_prev = right;
        left = -1;
        right = n;
        while (right - left > 1) {
            ll middle = (left + right) / 2;
            if (data[middle] <= key) {
                left = middle;
            } else {
                right = middle;
            }
        }
        if (right_prev > left){
            std::cout << "-1 -1\n";
        }
        else {
            std::cout << right_prev + 1 << " " << left + 1 << " \n";
        }
    }
    return 0;
}
