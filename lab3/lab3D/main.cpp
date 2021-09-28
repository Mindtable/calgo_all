#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <algorithm>


std::pair<long long, long long> get_children(long long);

class BinaryHeap{
private:
    std::vector<std::pair<long long, long long>> heap;
    std::map<std::pair<long long, long long>, long long> indices;
    long long size;
public:
    BinaryHeap(){
        size = 0;
    }
    void push(long long number, long long value){
        size++;
        heap.push_back(std::make_pair(number, value));
        indices[std::make_pair(number, value)] = size - 1;
        long long i = size - 1;
        while (i > 0 && heap[(i - 1) / 2].second > heap[i].second){
            std::iter_swap(heap.begin() + i, heap.begin() + (i - 1) / 2);
            indices[heap[(i - 1) / 2]] = (i - 1) / 2;
            indices[heap[i]] = i;
            i = (i - 1) / 2;
        }
    }
    void extract_min(){
        if (size == 0) {
            std::cout << "*\n";
            return;
        }
        std::cout << heap[0].second << '\n';
        indices.erase(heap[0]);
        std::iter_swap(heap.begin(), heap.end() - 1);
        indices[heap[0]] = 0;
        heap.pop_back();
        size--;
        long long i = 0;
        while (1){
            std::pair<long long, long long> child_ind = get_children(i);
            long long j = i;
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

        }

    }
    void decrease_key(std::pair<long long, long long> old_value, long long new_value){
        long long i = indices[old_value];
        indices.erase(old_value);
        heap[i] = std::make_pair(old_value.first, new_value);
        indices[heap[i]] = i;
        while (i > 0 && heap[(i - 1) / 2].second > heap[i].second){
            std::iter_swap(heap.begin() + i, heap.begin() + (i - 1) / 2);
            indices[heap[(i - 1) / 2]] = (i - 1) / 2;
            indices[heap[i]] = i;
            i = (i - 1) / 2;
        }
    }

    void print(){
        for (auto number: heap){
            std::cout << number.first << ' ' << number.second << '\n';
        }
    }

};

int main(){
    std::string command;
    BinaryHeap heap;
    std::map<long long, long long> number_value;
    long long number = 1;
    long long value;
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    while (std::cin >> command){
        if (command == "push"){
            std::cin >> value;
            number_value[number] = value;
            heap.push(number, value);
        }
        else if (command == "extract-min"){
            heap.extract_min();
        }
        else if (command == "decrease-key"){
            long long number_to_change;
            long long new_value;
            std::cin >> number_to_change >> new_value;
            std::pair<long long, long long> argument = {number_to_change, number_value[number_to_change]};
            heap.decrease_key(argument, new_value);
        }
        else{
            std::cout << "error";
            return 1;
        }
        number++;
    }
    heap.print();
    return 0;
}

std::pair<long long, long long> get_children(long long index){
    std::pair<long long, long long> result = {2*index + 1, 2*index + 2};
    return result;
}