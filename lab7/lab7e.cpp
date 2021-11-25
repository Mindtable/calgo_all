#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

class BinarySearchTree {
private:
    class Node {
    public:
        long long value;
        long long height;
        long long number;
        Node *left_child;
        Node *right_child;

        explicit Node(long long value) {
            this->value = value;
            this->height = 1;
            this->left_child = nullptr;
            this->right_child = nullptr;
        }
    };

    Node *root;

    static long long get_height(Node *tile) {
        if (tile == nullptr) {
            //FIXME
            return 0;
        }
        return tile->height;
    }

    long long get_balance(Node *tile) {
        if (tile == nullptr) {
            return 0;
        }
        return get_height(tile->left_child) - get_height(tile->right_child);
    }

    Node *small_left_rotate(Node *tile) {
        Node *tmp = tile->right_child;
        tile->right_child = tmp->left_child;
        tmp->left_child = tile;
        tile->height = std::max(get_height(tile->left_child), get_height(tile->right_child)) + 1;
        tmp->height = std::max(get_height(tmp->left_child), get_height(tmp->right_child)) + 1;
        return tmp;
    }

    Node *small_right_rotate(Node *tile) {
        Node *tmp = tile->left_child;
        tile->left_child = tmp->right_child;
        tmp->right_child = tile;
        tile->height = std::max(get_height(tile->left_child), get_height(tile->right_child)) + 1;
        tmp->height = std::max(get_height(tmp->left_child), get_height(tmp->right_child)) + 1;
        return tmp;
    }

    Node *big_left_rotate(Node *tile) {
        tile->right_child = small_right_rotate(tile->right_child);
        tile = small_left_rotate(tile);
        return tile;
    }

    Node *big_right_rotate(Node *tile) {
        tile->left_child = small_left_rotate(tile->left_child);
        tile = small_right_rotate(tile);
        return tile;
    }

    Node *balance(Node *tile) {
        if (tile == nullptr) {
            std::cout << "nullptr to balance func exception";
            std::exit(1);
        }
        long long status_left = get_balance(tile->left_child);
        long long status_root = get_balance(tile);
        long long status_right = get_balance(tile->right_child);
        if (status_root == -2) {
            if (status_right == 1) {
                tile = big_left_rotate(tile);
            } else {
                tile = small_left_rotate(tile);
            }
        } else if (status_root == 2) {
            if (status_left == -1) {
                tile = big_right_rotate(tile);
            } else {
                tile = small_right_rotate(tile);
            }
        }
        return tile;
    }

    Node *insert(Node *tile, long long value) {
        if (tile == nullptr) {
            return new Node(value);
        }

        if (value > tile->value) {
            tile->right_child = insert(tile->right_child, value);
        } else if (value < tile->value) {
            tile->left_child = insert(tile->left_child, value);
        }
        tile = balance(tile);
        tile->height = std::max(get_height(tile->left_child), get_height(tile->right_child)) + 1;
        return tile;
    }

    Node *successor(Node *tile, long long value) {
        Node *current = tile;
        Node *res = nullptr;
        while (current != nullptr) {
            if (value < current->value) {
                res = current;
                current = current->left_child;
            } else {
                current = current->right_child;
            }
        }
        return res;
    }

    Node *predecessor(Node *tile, long long value) {
        Node *current = tile;
        Node *res = nullptr;
        while (current != nullptr) {
            if (value > current->value) {
                res = current;
                current = current->right_child;
            } else {
                current = current->left_child;
            }
        }
        return res;
    }

    Node *delete_value(Node *tile, long long value) {
        if (tile == nullptr) {
            return nullptr;
        }

        if (value > tile->value) {
            tile->right_child = delete_value(tile->right_child, value);
        } else if (value < tile->value) {
            tile->left_child = delete_value(tile->left_child, value);

        } else if (tile->left_child != nullptr && tile->right_child != nullptr) {
            Node *next = successor(tile, value);
            tile->value = next->value;
            tile->right_child = delete_value(tile->right_child, tile->value);
        } else {
            Node *temp = tile;
            if (tile->right_child == nullptr && tile->left_child == nullptr) {
                delete tile;
                return nullptr;
            }
            if (tile->right_child == nullptr) {
                tile = tile->left_child;
            } else if (tile->left_child == nullptr) {
                tile = tile->right_child;
            }
            delete temp;
        }
        tile->height = std::max(get_height(tile->right_child), get_height(tile->left_child)) + 1;
        tile = balance(tile);
        return tile;
    }

    Node *search(Node *tile, long long value) {
        if (tile == nullptr) {
            return tile;
        }
        if (value == tile->value) {
            return tile;
        }

        if (value > tile->value) {
            return search(tile->right_child, value);
        }
        return search(tile->left_child, value);
    }

    void enumerate(Node *tile, long long &number) {
        if (tile == nullptr) {
            return;
        }
        tile->number = number;
        number++;
        enumerate(tile->left_child, number);
        enumerate(tile->right_child, number);
    }

    static long long get_number(Node *tile) {
        if (tile == nullptr) {
            return 0;
        }
        return tile->number;
    }

    void preorder_traversal(Node *tile) {
        if (tile == nullptr) {
            return;
        }
        std::cout << tile->value << " " << get_number(tile->left_child) << " " << get_number(tile->right_child) << "\n";
        preorder_traversal(tile->left_child);
        preorder_traversal(tile->right_child);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(long long value) {
        root = insert(root, value);
    }

    void delete_value(long long value) {
        root = delete_value(root, value);
    }

    bool search(long long value) {
        Node *result = search(root, value);
        return result != nullptr;
    }

    long long balance() {
        return get_balance(root);
    }

    void prev(long long value) {
        Node *prev = predecessor(root, value);
        if (prev == nullptr) {
            std::cout << "none\n";
        } else {
            std::cout << prev->value << "\n";
        }
    }

    void next(long long value) {
        Node *nxt = successor(root, value);
        if (nxt == nullptr) {
            std::cout << "none\n";
        } else {
            std::cout << nxt->value << "\n";
        }
    }

    void preorder_traversal() {
        long long number = 1;
        enumerate(root, number);
        preorder_traversal(root);
    }
};

int main() {
    freopen("avlset.in", "r", stdin);
    freopen("avlset.out", "w", stdout);

    long long n;
    BinarySearchTree test;
    std::cin >> n;

    for (long long i = 0; i < n; i++) {
        char command;
        long long key;
        std::cin >> command >> key;

        switch (command) {
            case ('A'): {
                test.insert(key);
                std::cout << -test.balance() << "\n";
                break;
            }
            case ('D'): {
                test.delete_value(key);
                std::cout << -test.balance() << "\n";
                break;
            }
            case ('C'): {
                std::cout << (test.search(key) ? "Y\n" : "N\n");
                break;
            }
            default: {
                std::cout << "error! " << command << key;
                return 1;
            }
        }
    }

    return 0;
}

