#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

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
    int size = 0;
    int A = 7;
    int MOD = 317;
    ListElement NONE = ListElement("", "", nullptr);
    std::vector<std::vector<ListElement>> data;

    [[nodiscard]] int get_hash(const std::string &key) const {
        int result = 0;
        for (int j = 0; j < key.length(); j++) {
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

    void print_all() const {
        std::cout << size << " ";
        ListElement *cur = prev;
        while (cur != nullptr) {
            std::cout << cur->value << " ";
            cur = cur->prev;
        }
        std::cout << "\n";
    }

    void delete_all() {
        size = 0;
        for (long long i = 0; i < MOD; i++) {
            data[i].clear();
        }
        prev = nullptr;
    }

    //FIXME
    void delete_key(const std::string& key) {
        int hash = get_hash(key);
        for (int j = 0; j < data[hash].size(); j++) {
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
        int hash = get_hash(key);
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

class MapElement {
public:
    Map set;
    std::string key;

    MapElement(std::string key) {
        this->set = Map();
        this->key = key;
    }
};

class MultiMap {
public:
    const int A = 7;
    const int MOD = 317;
    ListElement NONE = ListElement("", "", nullptr);
    std::vector<std::vector<MapElement>> data;

    MultiMap() {
        data = std::vector<std::vector<MapElement>>(MOD);
    }

    [[nodiscard]] int get_hash(const std::string &key) const {
        int result = 0;
        for (int j = 0; j < key.length(); j++) {
            int i = key[j];
            result = (result * A + i) % MOD;
        }
        return result;
    }

    void put (const std::string &key, const std::string &value) {
        long long hash = get_hash(key);
        for (long long i = 0; i < data[hash].size(); i++) {
            long long kek = i;
            MapElement &j = data[hash][i];
            if (j.key == key) {
                j.set.put(value, value);
                return;
            }
        }
        data[hash].push_back(MapElement(key));
        data[hash][data[hash].size() - 1].set.put(value, value);
    }

    void get(const std::string &key) {
        long long hash = get_hash(key);
        for (auto &j: data[hash]) {
            if (j.key == key) {
                j.set.print_all();
                return;
            }
        }
        std::cout << "0\n";
    }

    void delete_key(const std::string &key, const std::string &value) {
        long long hash = get_hash(key);
        for (auto &j: data[hash]) {
            if (j.key == key) {
                j.set.delete_key(value);
                return;
            }
        }
    }

    void delete_all(const std::string &key) {
        long long hash = get_hash(key);
        for (auto &j: data[hash]) {
            if (j.key == key) {
                j.set = Map();
                return;
            }
        }
    }


};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    freopen("multimap.in", "r", stdin);
    freopen("multimap.out", "w", stdout);
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