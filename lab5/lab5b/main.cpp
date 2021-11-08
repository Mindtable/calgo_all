#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

class Map {
private:
    const long long A = 37;
    const long long MOD = 1e7 + 19;
    const std::string NONE;
    std::vector<std::vector<std::pair<std::string, std::string>>> data;

    [[nodiscard]] long long get_hash(const std::string &key) const {
        long long result = 0;
        for (char i: key) {
            result = (result * A + i) % MOD;
        }
        return result;
    }

public:
    Map() {
        data = std::vector<std::vector<std::pair<std::string, std::string>>>(MOD);
    }

    std::string get(const std::string &key) {
        long long hash = get_hash(key);
        for (std::pair i: data[hash]) {
            if (i.first == key) {
                return i.second;
            }
        }
        return "none";
    }

    void delete_key(std::string key) {
        long long hash = get_hash(key);
        for (std::pair<std::string, std::string> &i: data[hash]) {
            if (i.first == key) {
                i.first = NONE;
                return;
            }
        }
    }

    void put(std::string key, std::string value) {
        long long hash = get_hash(key);
        for (std::pair<std::string, std::string> &i: data[hash]) {
            if (i.first == NONE) {
                i.first = key;
                i.second = value;
                return;
            }
        }
        data[hash].push_back({key, value});
    }
};


int main() {
    std::vector<std::vector<std::pair<long long, long long>>> test(10);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("map.in", "r", stdin);
    freopen("map.out", "w", stdout);
    Map dataset;
    std::string input;
    while (std::cin >> input) {
        std::string key;
        std::cin >> key;
        if (input == "put") {
            std::string value;
            std::cin >> value;
            dataset.put(key, value);
        } else if (input == "get") {
            std::cout << dataset.get(key) << "\n";
        } else if (input == "delete") {
            dataset.delete_key(key);
        }
    }
    return 0;
}