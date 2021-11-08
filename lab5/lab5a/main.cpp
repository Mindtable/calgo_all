#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

class Set {
private:
    const long long A = 37;
    const long long MOD = 1e7 + 19;
    const long long NONE = 1e11;
    std::vector<std::vector<long long>> data;

    [[nodiscard]] long long get_hash(long long key) const {
        return (key * A) % MOD;
    }

public:
    Set() {
        data = std::vector<std::vector<long long>>(MOD);
    }

    bool exists(long long key) {
        long long hash = get_hash(key);
        for (long long &i: data[hash]) {
            if (i == key) {
                return true;
            }
        }
        return false;
    }

    void delete_key(long long key) {
        long long hash = get_hash(key);
        for (long long &i: data[hash]) {
            if (i == key) {
                i = NONE;
                return;
            }
        }
    }

    void insert(long long key) {
        long long hash = get_hash(key);
        for (long long &i: data[hash]) {
            if (i == key || i == NONE) {
                if (i == NONE) {
                    i = key;
                }
                return;
            }
        }
        data[hash].push_back(key);
    }
};


int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    Set dataset;
    std::string input;
    while (std::cin >> input) {
        long long value;
        std::cin >> value;
        if (input == "insert") {
            dataset.insert(value);
        } else if (input == "exists") {
            if (dataset.exists(value)) {
                std::cout << "true\n";
            } else {
                std::cout << "false\n";
            }
        } else if (input == "delete") {
            dataset.delete_key(value);
        }
    }
    return 0;
}
