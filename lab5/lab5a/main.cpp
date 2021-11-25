#include <iostream>
#include <vector>
#include <set>

class ListElem {
public:
    ListElem *prev;
    ListElem *next;
    std::string value;

    ListElem(const std::string &value, ListElem *prev) {
        this->value = value;
        this->prev = prev;
        this->next = nullptr;
    }
};

class Set {
private:
    int size = 0;
    const int A = 3;
    const int MOD = 9834497;
    std::vector<ListElem *> data;

    int get_hash(const std::string &val) {
        const int p = 31;
        int hash = 0, p_pow = 1;
        for (char i: val) {
            hash += (i - 'a' + 1) * p_pow;
            p_pow *= p;
        }
        if (hash >= 0) {
            return hash % MOD;
        } else {
            return (MOD - abs(hash) % MOD) % MOD;
        }
    }

public:
    Set() {
        data = std::vector<ListElem *>(MOD);
    }

    void put(const std::string &key) {
        int hash = get_hash(key);
        if (data[hash] == nullptr) {
            data[hash] = new ListElem(key, nullptr);
            size++;
            return;
        }
        ListElem *cur = data[hash];
        while (cur->next != nullptr) {
            if (cur->value == key) {
                return;
            }
            cur = cur->next;
        }
        if (cur->value != key) {
            cur->next = new ListElem(key, cur);
            size++;
        }
    }

    void delete_key(const std::string &key) {
        int hash = get_hash(key);
        ListElem *cur = data[hash];
        if (cur == nullptr) {
            return;
        }
        if (cur->value == key) {
            data[hash] = cur->next;
            size--;
            return;
        }
        while (cur != nullptr) {
            if (cur->value == key) {
                if (cur->prev != nullptr) {
                    cur->prev->next = cur->next;
                }
                if (cur->next != nullptr) {
                    cur->next->prev = cur->prev;
                }
                size--;
                return;
            }
            cur = cur->next;
        }
    }

    bool exists(const std::string &key) {
        int hash = get_hash(key);
        ListElem *cur = data[hash];
        while (cur != nullptr) {
            if (cur->value == key) {
                return true;
            }
            cur = cur->next;
        }
        return false;
    }
};

int main() {
    std::string input;
    std::string key;
    Set test;
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    while (std::cin >> input) {
        std::cin >> key;
        if (input == "insert") {
            test.put(key);
        } else if (input == "delete") {
            test.delete_key(key);
        } else if (input == "exists") {
            std::cout << (test.exists(key) ? "true" : "false") << "\n";
        }
    }
}