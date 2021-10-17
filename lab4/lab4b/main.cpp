#include <iostream>
#include <vector>

#define ll long long

class queue{
private:
    std::vector<ll> data;
    ll front;
    ll back;
    const ll maxsize = 10000000;
public:
    queue(){
        data = data = std::vector<ll>(maxsize);
        front = 0;
        back = 0;
    }
    bool empty(){
        return front == back;
    }

    void push(ll value){
        data[back] = value;
        back = (back + 1) % maxsize;
    }

    ll pop(){
        ll result = data[front];
        front = (front + 1) % maxsize;
        return result;
    }
};

int main() {
    ll count_of_req;
    queue test_queue;
    freopen("queue.in", "r", stdin);
    std::cin >> count_of_req;



    for (ll j = 0; j < count_of_req; j++){
        char value;
        std::cin >> value;
        if (value == '+'){
            ll value_l;
            std::cin >> value_l;
            test_queue.push(value_l);
        }
        else if (value == '-'){
            std::cout << test_queue.pop() << '\n';
        }
        else {
            std::cout << "error";
            return 1;
        }
    }
    return 0;
}
