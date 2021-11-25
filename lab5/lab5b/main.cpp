#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <time.h>

class ListElement {
public:
    std::string key;
    std::string value;
    ListElement *prev;
    ListElement *nxt;

    ListElement(std::string label, std::string val, ListElement *previous) {
        key = label;
        value = val;
        prev = previous;
        nxt = nullptr;
    }
};

class Map {
private:
    long long size = 0;
    const long long A = 7;
    const long long MOD = 514229;
    ListElement NONE = ListElement("", "", nullptr);
    std::vector<std::vector<ListElement>> data;

    [[nodiscard]] long long get_hash(const std::string &key) const {
        long long result = 0;
        for (long long j = 0; j < key.length(); j++) {
            int i = key[j];
            result = (result * A + i) % MOD;
        }
        return result;
    }

public:
    Map() {
        data = std::vector<std::vector<ListElement>>(MOD);
    }
    ListElement *prev = nullptr;
    std::string get(const std::string &key) {
        long long hash = get_hash(key);
        for (const ListElement &i: data[hash]) {
            if (i.key == key) {
                return i.value;
            }
        }
        return "none";
    }

    std::string next(const std::string &key) {
        long long hash = get_hash(key);
        for (const ListElement &i: data[hash]) {
            if (i.key == key) {
                if (i.nxt == nullptr) {
                    return "none";
                }
                return (i.nxt)->value;
            }
        }
        return "none";
    }

    std::string previous(const std::string &key) {
        long long hash = get_hash(key);
        for (const ListElement &i: data[hash]) {
            if (i.key == key) {
                if (i.prev == nullptr) {
                    return "none";
                }
                return (i.prev)->value;
            }
        }
        return "none";
    }

    //FIXME
    void delete_key(const std::string& key) {
        long long hash = get_hash(key);
        for (long long j = 0; j < data[hash].size(); j++) {
            ListElement &i = data[hash][j];
            if (i.key == key) {
                if (i.prev != nullptr) {
                    (i.prev)->nxt = i.nxt;
                }
                if (i.nxt != nullptr) {
                    (i.nxt)->prev = i.prev;
                } else {
                    prev = i.prev;
                }
                i = NONE;
                size--;
            }
        }
    }

    void put(std::string key, std::string value) {
        long long hash = get_hash(key);
        for (ListElement &i: data[hash]) {
            if (i.key == key) {
                i.value = value;
                return;
            }
        }
        data[hash].push_back(ListElement(key, value, prev));
        if (prev != nullptr) {
            prev->nxt = &data[hash][data[hash].size() - 1];
        }
        prev = &data[hash][data[hash].size() - 1];
        size++;
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
        } else if (input == "next") {
            std::cout << dataset.next(key) << "\n";
        } else if (input == "prev") {
            std::cout << dataset.previous(key) << "\n";
        }
    }
    return 0;
}