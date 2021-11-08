#include <iostream>
#include <vector>
#include <string>

#define ll long long

class Stack {
private:
    std::vector<char> data;
public:
    ll size;
    Stack() {
        size = 0;
        data = std::vector<char>(10000000);
    }

    void push(char value) {
        data[size] = value;
        size += 1;
    }

    char pop() {
        if (size == 0) {
            return '$';
        }
        size -= 1;
        return data[size];
    }

    void clear() {
        size = 0;
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);

    std::string bracket_str;
    Stack bracket_stack;
    while (std::cin >> bracket_str) {
        bool flag = true;
        for (ll i = 0; i < bracket_str.size() && flag; i++) {
            if (bracket_str[i] == '(' || bracket_str[i] == '[') {
                bracket_stack.push(bracket_str[i]);
            } else {
                char value;
                value = bracket_stack.pop();
                if (value == '$') {
                    flag = false;
                } else if (value == '[' && bracket_str[i] == ')') {
                    flag = false;
                } else if (value == '(' && bracket_str[i] == ']') {
                    flag = false;
                }
            }
        }
        if (flag && bracket_stack.size == 0) {
            std::cout << "YES" << "\n";
        } else {
            std::cout << "NO" << "\n";
        }
        bracket_stack.clear();
    }
}