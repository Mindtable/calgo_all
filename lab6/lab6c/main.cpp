#include <iostream>
#include <string>

class Node {
public:
    long long key;
    Node *left;
    Node *right;

    Node(long long value) {
        key = value;
        left = nullptr;
        right = nullptr;
    }
};

Node *search(Node *root, long long value) {
    if (root == nullptr || value == root->key) {
        return root;
    }

    if (value < root->key) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

Node *insert(Node *root, long long value) {
    if (root == nullptr) {
        return new Node(value);
    }
    if (value < root->key) {
        root->left = insert(root->left, value);
    } else if (value > root->key) {
        root->right = insert(root->right, value);
    }
    return root;
}

Node *minimum(Node *root) {
    if (root->left == nullptr) {
        return root;
    }
    return minimum(root->left);
}

Node *maximum(Node *root) {
    if (root->right == nullptr) {
        return root;
    }
    return maximum(root->right);
}

Node *next(Node *root, long long value) {
    Node *current = root;
    Node *successor = nullptr;
    while (current != nullptr) {
        if (current->key > value) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

Node *prev(Node *root, long long value) {
    Node *current = root;
    Node *successor = nullptr;
    while (current != nullptr) {
        if (current->key < value) {
            successor = current;
            current = current->right;
        } else {
            current = current->left;
        }
    }
    return successor;
}

Node *delete_key(Node *root, long long value) {
    if (root == nullptr) {
        return root;
    }

    if (value < root->key) {
        root->left = delete_key(root->left, value);
    } else if (value > root->key) {
        root->right = delete_key(root->right, value);
    } else if (root->left != nullptr && root->right != nullptr) {
        root->key = minimum(root->right)->key;
        root->right = delete_key(root->right, root->key);
    } else {
        if (root->left != nullptr) {
            root = root->left;
        } else if (root->right != nullptr) {
            root = root->right;
        } else {
            root = nullptr;
        }
    }
    return root;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    Node *root = nullptr;
    std::string input;
    while (std::cin >> input) {
        long long value;
        std::cin >> value;
        if (input == "insert") {
            root = insert(root, value);
        } else if (input == "delete") {
            root = delete_key(root, value);
        } else if (input == "next") {
            Node *nxt = next(root, value);
            if (nxt == nullptr) {
                std::cout << "none\n";
            } else {
                std::cout << nxt->key << "\n";
            }
        } else if (input == "prev") {
            Node *prv = prev(root, value);
            if (prv == nullptr) {
                std::cout << "none\n";
            } else {
                std::cout << prv->key << "\n";
            }
        } else if (input == "exists") {
            Node *elem = search(root, value);
            if (elem == nullptr) {
                std::cout << "false\n";
            } else {
                std::cout << "true\n";
            }
        }
    }
    return 0;
}
