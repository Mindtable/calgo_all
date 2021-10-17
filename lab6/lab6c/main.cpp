#include <iostream>
#include <string>

long long count = -1;

class Node {
public:
    Node *left;
    Node *right;
    long long value;

    Node(long long val) {
        left = nullptr;
        right = nullptr;
        value = val;
    }
};

Node *add(Node *v, long long key) {
    if (v == nullptr) {
        return new Node(key);
    }
    if (v->value > key) {
        v->left = add(v->left, key);
    } else {
        v->right = add(v->right, key);
    }
    return v;
}

Node *del(Node *root, long long key) {
    if (root->value > key) {
        root->left = del(root->left, key);
        return root;
    }
    if (root->value < key) {
        root->right = del(root->right, key);
        return root;
    }
    if (root->right == nullptr && root->left == nullptr) {
        return nullptr;
    }
    if (root->right == nullptr) {
        return root->left;
    }
    if (root->left == nullptr) {
        return root->right;
    }
    Node *cur = root->right;
    while (cur->left != nullptr) {
        cur = cur->left;
    }
    root->value = cur->value;
    root->right = del(root->right, root->value);
    return root;
}

void print_tree(Node *root) {
    count++;
    if (root == nullptr) {
        std::cout << " none ";
        count--;
        return;
    }
    std::cout << root->value << "\n" << std::string(count, ' ') << "left_br:";
    print_tree(root->left);
    if (count > 0) {
        std::cout << "\n" << std::string(count - 1, ' ') << "right_br:";
    } else {
        std::cout << "\n" << std::string(count, ' ') << "right_br:";
    }
    print_tree(root->right);
    count--;
}

int main() {
    freopen("bstsimple.in", "r", stdin);

    Node *root = nullptr;
    std::string input;
    while (std::cin >> input) {
        if (input == "insert") {
            long long input_value;
            std::cin >> input_value;
            if (root == nullptr) {
                root = new Node(input_value);
            } else {
                root = add(root, input_value);
            }
        } else if (input == "delete") {
            long long input_value;
            std::cin >> input_value;
            root = del(root, input_value);
        } else if (input == "next") {
            long long input_value;
            std::cin >> input_value;
            Node *cur = root;
            long long value = root->value;
            while (cur != nullptr) {
                if (cur->value > input_value) {
                    value = cur->value;
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }
            if (value > input_value) {
                std::cout << value << "\n";
            } else {
                std::cout << "none\n";
            }
        } else if (input == "prev") {
            long long input_value;
            std::cin >> input_value;
            Node *cur = root;
            long long value = root->value;
            while (cur != nullptr) {
                if (cur->value < input_value) {
                    value = cur->value;
                    cur = cur->right;
                } else {
                    cur = cur->left;
                }
            }
            if (value < input_value) {
                std::cout << value << "\n";
            } else {
                std::cout << "none\n";
            }
        } else if (input == "exists") {
            long long input_value;
            std::cin >> input_value;
            Node* cur = root;
            std::string value = "false\n";
            while (cur != nullptr) {
                if (cur->value == input_value) {
                    value = "true\n";
                    cur = nullptr;
                } else if (cur->value > input_value) {
                    cur = cur->left;
                } else {
                    cur = cur->right;
                }
            }
            std::cout << value;
        }
    }
    return 0;
}
