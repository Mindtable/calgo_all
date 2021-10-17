#include <iostream>
#include <vector>

int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    long long n;
    std::cin >> n;

    std::vector<long long> data;
    for (long long j = 0; j < n; j++){
        long long value;
        std::cin >> value;
        data.push_back(value);
    }

    for (long long i = 0; i < n; i++){
        if (2*i + 1 < n and data[i] > data[2*i + 1]){
            std::cout << "NO\n";
            return 0;
        }
        if (2*i + 2 < n and data[i] > data[2*i + 2]) {
            std::cout << "NO\n";
            return 0;
        }
    }
    std::cout << "YES\n";
    return 0;
}
