#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <queue>


#define ll long long

class BinaryHeap{
private:
    std::vector<std::pair<ll, ll>> heap;
    ll size;
public:
    BinaryHeap(){
        size = 0;
        for (ll i = 0; i < 10000000; i++){
            if (i < 1000000 + 7)
                heap.push_back(std::pair<ll, ll>(0, 0));
        }
    }
    void push(ll number, ll value){
        heap[size] = std::pair<ll, ll>(number, value);
        size++;
        ll i = size - 1;
        while (i > 0 && heap[(i - 1) / 2].second > heap[i].second){
            std::iter_swap(heap.begin() + i, heap.begin() + (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }
    void extract_min(){
        if (size == 0) {
            std::cout << "*\n";
            return;
        }
        std::cout << heap[0].second << ' ';
        std::iter_swap(heap.begin(), heap.begin() + size - 1);
        size--;
        ll i = 0;
        while (1){
            std::pair<ll, ll> child_ind = std::pair<ll, ll>(2*i + 1, 2*i + 2);
            ll j = i;
            if (child_ind.first < size &&
                heap[child_ind.first].second < heap[j].second){
                j = child_ind.first;
            }
            if (child_ind.second < size &&
                heap[child_ind.second].second < heap[j].second){
                j = child_ind.second;
            }

            if (j == i){
                return;
            }
            std::iter_swap(heap.begin() + i, heap.begin() + j);
            i = j;
        }

    }

    void print(){
        for (ll j = size; j > 0; j--){
            this->extract_min();
        }
    }

};

int main() {
    BinaryHeap heap;
    ll n;
    std::cin >> n;
    for (ll j = 0; j < n; j++){
        ll value;
        std::cin >> value;
        heap.push(j, value);
    }
    heap.print();
    return 0;
}
