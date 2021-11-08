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
        key = std::move(label);
        value = std::move(val);
        prev = previous;
        nxt = nullptr;
    }

    bool operator==(ListElement &elem) const {
        return this->key == elem.key && this->value == elem.value &&
               this->prev == elem.prev && this->nxt == elem.nxt;
    }
};

class Map {
private:
    const long long A = 37;
    const long long MOD = 1e7 + 19;
    ListElement NONE = ListElement("", "", nullptr);

    std::vector<std::vector<ListElement>> data;

    [[nodiscard]] long long get_hash(const std::string &key) const {
        long long result = 0;
        for (char i: key) {
            result = (result * A + i) % MOD;
        }
        return result;
    }

public:
    ListElement *first = nullptr;
    ListElement *last = nullptr;

    Map() {
        data = std::vector<std::vector<ListElement>>(MOD);
    }

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

    void delete_key(std::string key) {
        long long hash = get_hash(key);
        for (ListElement &i: data[hash]) {
            if (i.key == key) {
                if (i.prev != nullptr) {
                    (i.prev)->nxt = i.nxt;
                } else {
                    first = i.nxt;
                }
                if (i.nxt != nullptr) {
                    (i.nxt)->prev = i.prev;
                } else {
                    last = i.prev;
                }
                i = NONE;
                return;
            }
        }
    }

    void put(std::string key, std::string value) {
        long long hash = get_hash(key);
        for (ListElement &i: data[hash]) {
            if (i == NONE) {
                i = ListElement(key, value, last);
                last->nxt = &i;
                last = last->nxt;
                return;
            }
        }
        data[hash].push_back(ListElement(key, value, last));
        if (last != nullptr) {
            last->nxt = &data[hash][data[hash].size() - 1];
            last = last->nxt;
        } else {
            last = &data[hash][data[hash].size() - 1];
        }
        if (first == nullptr) {
            first = &data[hash][data[hash].size() - 1];
        }
    }

    void print() {
        ListElement *cur = first;
        long long count = 0;
        while (cur != nullptr) {
            count += 1;
            cur = cur->nxt;
        }
        std::cout << count;
        cur = first;
        while (cur != nullptr) {
            std::cout << " " << cur->value;
            cur = cur->nxt;
        }
        std::cout << "\n";
    }
};

class MultiMap {
private:
    const long long A = 41;
    const long long MOD = 1e5 + 3;
    std::vector<std::vector<std::pair<std::string, Map>>> data;

    [[nodiscard]] long long get_hash(const std::string &key) const {
        long long result = 0;
        for (char i: key) {
            result = (result * A + i) % MOD;
        }
        return result;
    }

public:
    MultiMap() {
        data = std::vector<std::vector<std::pair<std::string, Map>>>(MOD);
    }

    void get(const std::string &key) {
        long long hash = get_hash(key);
        for (std::pair<std::string, Map> &i: data[hash]) {
            if (i.first == key) {
                i.second.print();
                return;
            }
        }
        std::cout << "0\n";
    }

    void delete_key(const std::string &key, const std::string &value) {
        long long hash = get_hash(key);
        for (std::pair<std::string, Map> &i: data[hash]) {
            if (i.first == key) {
                i.second.delete_key(value);
                return;
            }
        }
    }

    void delete_all(const std::string &key) {
        long long hash = get_hash(key);
        for (std::pair<std::string, Map> &i: data[hash]) {
            if (i.first == key) {
                i.second.first = nullptr;
                i.second.last = nullptr;
                return;
            }
        }
    }

    void put(const std::string &key, const std::string &value) {
        long long hash = get_hash(key);
        for (std::pair<std::string, Map> &i: data[hash]) {
            if (i.first == key) {
                i.second.put(value, value);
                return;
            }
        }
        data[hash].push_back({key, Map()});
        data[hash][data[hash].size() - 1].second.put(value, value);
    }
};

int main() {
    std::vector<std::vector<std::pair<long long, long long>>> test(10);

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("linkedmap.in", "r", stdin);
    freopen("linkedmap.out", "w", stdout);
    MultiMap dataset;
    std::string input;

    while (std::cin >> input) {
        std::string key;
        std::cin >> key;
        if (input == "put") {
            std::string value;
            std::cin >> value;
            dataset.put(key, value);
        } else if (input == "get") {
            dataset.get(key);
        } else if (input == "delete") {
            std::string value;
            std::cin >> value;
            dataset.delete_key(key, value);
        } else if (input == "deleteall") {
            dataset.delete_all(key);
        }
    }
    return 0;
}