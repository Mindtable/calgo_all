#include <iostream>
#include <vector>
#include <algorithm>

class Node {
public:
    long long value;
    long long left_child;
    long long right_child;

    Node(long long val, long long left, long long right) {
        value = val;
        left_child = left;
        right_child = right;
    }
};

bool check(std::vector<Node> &data, long long node_ind, long long min_val, long long max_val) {
    if (node_ind == -1) {
        return true;
    }

    if (data[node_ind].value <= min_val || data[node_ind].value >= max_val) {
        return false;
    }

    return check(data, data[node_ind].left_child, min_val, data[node_ind].value) &&
           check(data, data[node_ind].right_child, data[node_ind].value, max_val);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("check.in", "r", stdin);
    freopen("check.out", "w", stdout);
    long long number;
    std::cin >> number;

    const long long INF = 1e10;
    const long long MIN_INF = -1e10;

    std::vector<Node> data;

    for (long long i = 0; i < number; i++) {
        long long right, left, value;
        std::cin >> value >> left >> right;
        data.push_back(Node(value, left - 1, right - 1));
    }
    if (number == 0 || check(data, 0, MIN_INF, INF)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
    return 0;
}
