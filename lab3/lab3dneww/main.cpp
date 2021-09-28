#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>

#define ll long long

std::pair<ll, ll> get_children(ll);

class BinaryHeap{
private:
    std::vector<std::pair<ll, ll>> heap;
    std::vector<ll> number_index;
    ll size;
public:
    BinaryHeap(){
        size = 0;
        for (ll i = 0; i < 10000000; i++){
            number_index.push_back(0);
            if (i < 1000000 + 7)
                heap.push_back(std::pair<ll, ll>(0, 0));
        }
    }
    void push(ll number, ll value){
        heap[size] = std::pair<ll, ll>(number, value);
        number_index[number] = size;
        size++;
        ll i = size - 1;
        while (i > 0 && heap[(i - 1) / 2].second > heap[i].second){
            std::iter_swap(heap.begin() + i, heap.begin() + (i - 1) / 2);
            number_index[heap[(i - 1) / 2].first] = (i - 1) / 2;
            number_index[heap[i].first] = i;
            i = (i - 1) / 2;
        }
    }
    void extract_min(){
        if (size == 0) {
            std::cout << "*\n";
            return;
        }
        std::cout << heap[0].second << '\n';
        std::iter_swap(heap.begin(), heap.begin() + size - 1);
        number_index[heap[0].first] = 0;
        size--;
        ll i = 0;
        while (1){
            std::pair<ll, ll> child_ind = get_children(i);
            ll j = i;
            if (child_ind.first < size &&
                heap[child_ind.first].second < heap[j].second){
                j = child_ind.first;
            }
            if (child_ind.first < size &&
                heap[child_ind.first].second < heap[j].second){
                j = child_ind.first;
            }

            if (j == i){
                return;
            }
            std::iter_swap(heap.begin() + i, heap.begin() + j);
            number_index[heap[j].first] = j;
            number_index[heap[i].first] = i;
        }

    }
    void decrease_key(ll number, ll new_value){
        ll i = number_index[number];
        heap[i] = std::make_pair(number, new_value);
        while (i > 0 && heap[(i - 1) / 2].second > heap[i].second){
            std::iter_swap(heap.begin() + i, heap.begin() + (i - 1) / 2);
            number_index[heap[(i - 1) / 2].first] = (i - 1) / 2;
            number_index[heap[i].first] = i;
            i = (i - 1) / 2;
        }
    }

    void print(){
        for (auto number: heap){
            std::cout << number.first << ' ' << number.second << '\n';
        }
    }

};
// можно делать общий счетчик строк
// и счетчик бесполезных
// когда нам нужно будет поменять элемент из строк n
// мы просто вычтем из n количество бесполезных операций
//qq
//kk
int main(){
    std::string command;
    BinaryHeap heap;
    ll number = 1;
    ll value;
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    while (std::cin >> command){
        if (command == "push"){
            std::cin >> value;
            heap.push(number, value);
        }
        else if (command == "extract-min"){
            heap.extract_min();
        }
        else if (command == "decrease-key"){
            ll number_to_change;
            ll new_value;
            std::cin >> number_to_change >> new_value;
            heap.decrease_key(number_to_change, new_value);
        }
        else{
            std::cout << "error";
            return 1;
        }
        number++;
    }
    return 0;
}

std::pair<ll, ll> get_children(ll index){
    std::pair<ll, ll> result = {2*index + 1, 2*index + 2};
    return result;
}