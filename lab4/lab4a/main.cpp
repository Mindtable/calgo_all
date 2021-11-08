#include <iostream>
#include <vector>
#include <string>

#define ll long long

class Stack {
private:
    std::vector<ll> data = std::vector<ll>(10000);
    ll size = 0;
public:
    void push(ll value) {
        data[size] = value;
        size += 1;
    }

    ll pop() {
        size -= 1;
        return data[size];
    }

};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("stack.in", "r", stdin);
    freopen("stack.out", "w", stdout);
    Stack bracket_stack;
    ll number;
    std::cin >> number;

    for (ll i = 0; i < number; i++) {
        std::string operation;
        std::cin >> operation;
        if (operation == "+") {
            ll value;
            std::cin >> value;
            bracket_stack.push(value);
        } else if (operation == "-") {
            ll value = bracket_stack.pop();
            std::cout << value << "\n";
        }
    }
}