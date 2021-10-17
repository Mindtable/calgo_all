#include <iostream>
#include <vector>
#include <string>

#define ll long long
int main() {
    std::vector<ll> stack(1007, -1);
    ll stack_size = 0;
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    std::string input;
    while (std::cin >> input){
        if (input == "+") {
            ll b_oper = stack[stack_size - 1];
            ll a_oper = stack[stack_size - 2];
            stack_size -= 1;
            stack[stack_size - 1] = a_oper + b_oper;
        }
        else if (input == "-") {
            ll b_oper = stack[stack_size - 1];
            ll a_oper = stack[stack_size - 2];
            stack_size -= 1;
            stack[stack_size - 1] = a_oper - b_oper;
        }
        else if (input == "*") {
            ll b_oper = stack[stack_size - 1];
            ll a_oper = stack[stack_size - 2];
            stack_size -= 1;
            stack[stack_size - 1] = a_oper * b_oper;
        }
        else{
            stack[stack_size] = std::stoi(input);
            stack_size++;
        }
    }
    std::cout << stack[0];

    return 0;
}
