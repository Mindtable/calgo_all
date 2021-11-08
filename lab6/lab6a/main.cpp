#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("height.in", "r", stdin);
    freopen("height.out", "w", stdout);
    long long number;
    std::cin >> number;
    std::vector<long long> data(number + 1, 0);
    if (number == 0) {
        std::cout << 0;
        return 0;
    }

    long long max_height = 0;
    for (long long i = 1; i <= number; i++) {
        long long value, left, right;
        std::cin >> value >> left >> right;
        if (left != 0) {
            data[left] = data[i] + 1;
        }

        if (right != 0) {
            data[right] = data[i] + 1;
        }
        max_height = std::max(max_height, data[left]);
        max_height = std::max(max_height, data[right]);
    }

    std::cout << max_height + 1;
    return 0;
}
