void preOrder(Node* node) {
    if (node != nullptr) {
        cout << node->key << "\n";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        cout << node->key << "\n";
        inOrder(node->right);
    }
}

void postOrder(Node* node) {
    if (node != nullptr) {
        inOrder(node->left);
        inOrder(node->right);
        cout << node->key << "\n";
    }
}