#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long
#define MOD 65536

class queue {
private:
    std::vector<ll> data;
    ll front;
    ll back;
    const ll MAXSIZE = 10000000;
public:
    queue() {
        data = data = std::vector<ll>(MAXSIZE);
        front = 0;
        back = 0;
    }

    bool empty() {
        return front == back;
    }

    void push(ll value) {
        data[back] = value;
        back = (back + 1) % MAXSIZE;
    }

    ll pop() {
        ll result = data[front];
        front = (front + 1) % MAXSIZE;
        return result;
    }
};

int main() {
    freopen("quack.in", "r", stdin);

    std::vector<std::string> program(100000);
    std::vector<std::pair<std::string, ll>> lables(100000);
    std::vector<ll> registers(26);
    queue queue;
    std::string input;
    ll program_len = 0;
    ll lable_count = 0;
    while (std::cin >> input) {
        program[program_len] = input;
        if (program[program_len][0] == ':') {
            lables[lable_count] = {program[program_len].substr(1), program_len};
            lable_count++;
        }
        program_len++;
    }

    for (ll i = 0; i < program_len; i++) {
        char first_symbol = program[i][0];
        if (std::isdigit(first_symbol)) {
            queue.push(std::stoll(program[i]));
        } else if (first_symbol == '+') {
            ll x = queue.pop();
            ll y = queue.pop();
            queue.push((x + y) & (MOD - 1));
        } else if (first_symbol == '-') {
            ll x = queue.pop();
            ll y = queue.pop();
            queue.push((x - y) & (MOD - 1));
        } else if (first_symbol == '*') {
            ll x = queue.pop();
            ll y = queue.pop();
            queue.push((x * y) & (MOD - 1));
        } else if (first_symbol == '/') {
            ll x = queue.pop();
            ll y = queue.pop();
            if (y == 0) {
                queue.push(0);
            } else {
                queue.push(x / y);
            }
        } else if (first_symbol == '%') {
            ll x = queue.pop();
            ll y = queue.pop();
            if (y == 0) {
                queue.push(0);
            } else {
                queue.push(x % y);
            }
        } else if (first_symbol == '>') {
            char register_name = program[i][1] - 'a';
            ll x = queue.pop();
            registers[register_name] = x;
        } else if (first_symbol == '<') {
            char register_name = program[i][1] - 'a';
            ll x = registers[register_name];
            queue.push(x);
        } else if (first_symbol == 'P') {
            if (program[i].size() == 1) {
                std::cout << queue.pop() << "\n";
            } else {
                char register_name = program[i][1] - 'a';
                std::cout << registers[register_name] << "\n";
            }
        } else if (first_symbol == 'C') {
            if (program[i].size() == 1) {
                char out_char = queue.pop() % 256;
                std::cout << out_char;
            } else {
                char register_name = program[i][1] - 'a';
                char out_char = registers[register_name] % 256;
                std::cout << out_char;
            }
        } else if (first_symbol == 'J') {
            ll j = 0;
            while (program[i].substr(1) != lables[j].first) {
                j++;
            }
            i = lables[j].second;
        } else if (first_symbol == 'Z') {
            char register_name = program[i][1] - 'a';
            ll x = registers[register_name];
            if (x == 0) {
                ll j = 0;
                while (program[i].substr(2) != lables[j].first) {
                    j++;
                }
                i = lables[j].second;;
            }
        } else if (first_symbol == 'E') {
            char register_name1 = program[i][1] - 'a';
            char register_name2 = program[i][2] - 'a';
            ll x1 = registers[register_name1];
            ll x2 = registers[register_name2];
            if (x1 == x2) {
                ll j = 0;
                while (program[i].substr(3) != lables[j].first) {
                    j++;
                }
                i = lables[j].second;
            }
        } else if (first_symbol == 'G') {
            char register_name1 = program[i][1] - 'a';
            char register_name2 = program[i][2] - 'a';
            ll x1 = registers[register_name1];
            ll x2 = registers[register_name2];
            if (x1 > x2) {
                ll j = 0;
                while (program[i].substr(3) != lables[j].first) {
                    j++;
                }
                i = lables[j].second;
            }
        } else if (first_symbol == 'Q') {
            return 0;
        } else if (first_symbol == ':') {
            continue;
        } else {
            std::cout << "Error! " << program[i] << "\n";
            return 1;
        }
    }


    return 0;
}