#include <iostream>
#include <vector>
#include <string>

#define ll long long

int main() {
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    ll n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::string> data;
    std::vector<std::string> b_vector;
    for (ll i = 0; i < n; i++){
        std::string temp_string;
        std::cin >> temp_string;
        data.push_back(temp_string);
        b_vector.push_back(" ");
    }

    for (ll phase_number = 0; phase_number < k; phase_number++){
        std::vector<ll> countsort;
        for (ll j = 'a'; j <= 'z'; j++){
            countsort.push_back(0);
        }
        for (ll j = 0; j < n; j++){
            countsort[data[j][m - 1 - phase_number] - 'a'] += 1;
        }
        ll count = 0;
        for (ll j = 'a' - 'a'; j <= 'z' - 'a'; j++){
            ll tmp = countsort[j];
            countsort[j] = count;
            count += tmp;
        }
        for (ll j = 0; j < n; j ++){
            b_vector[countsort[data[j][m - 1 - phase_number] - 'a']] = data[j];
            countsort[data[j][m - 1 - phase_number] - 'a']++;
        }
        data = b_vector;
    }
    for (auto number: data){
        std::cout << number << '\n';
    }
    return 0;
}
