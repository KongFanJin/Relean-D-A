#include <iostream>

using namespace std;

// 二分搜索树
template <typename Key, typename Value>
class BST {
   private:
    // 二分搜索树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };

    Node* root;  // 根节点
    int count;   // 节点个数

   public:
    // 构造函数, 默认构造一棵空二分搜索树
    BST() {
        root = NULL;
        count = 0;
    }

    ~BST() {
        // TODO: ~BST()
        destroy(root);
    }

    // 返回二分搜索树的节点个数
    int size() { return count; }

    // 返回二分搜索树是否为空
    bool isEmpty() { return count == 0; }

    void insert(Key key, Value value) {
        root = insertRecursive(root, key, value);
    }

    bool contain(Key key) { return contain(root, key); }

    // Node* search(Key key); // public: Node
    // Value search(Key key); // Value is not NULL
    Value* search(Key key) { return search(root, key); }

    void preOrder() { preOrder(root); }

    void inOrder() { inOrder(root); }

    void postOrder() { postOrder(root); }

   private:
    // Recursion
    Node* insertRecursive(Node* &node, Key key, Value value) {
        if (node == nullptr) {  // base
            count++;
            return new Node(key, value);
        }
        if (key == node->key)
            node->value = value;  // update value
        else if (key < node->key)
            node->left = insert(node->left, key, value);
        else
            node->right = insert(node->right, key, value);
    }

    // 用两个指针记录父节点和子节点,迭代匹配,找到后插入父节点
    // Iterative function to insert a key into BST.
    // Root is passed by reference to the function
    Node* insertIterative(Node* &node, Key key, Value value) {
        // start with root node
        Node* curr = root;

        // pointer to store parent node of current node
        Node* parent = nullptr;

        // if tree is empty, create a new node and set root
        if (root == nullptr) {
            count++;
            return root = new Node(key, value);
        }

        // traverse the tree and find parent node of key
        while (curr != nullptr) {
            // update parent node as current node
            parent = curr;

            // if given key is less than the current node, go to left subtree
            // else go to right subtree
            if (key < curr->key)
                curr = curr->left;
            else
                curr = curr->right;
        }

        // construct a new node and assign to appropriate parent pointer
        if (key == node->key) {
            parent->value = value;
        } else if (key < parent->key) {
            parent->left = new Node(key, value);
        } else {
            parent->right = new Node(key, value);
        }

        return root;
    }

    bool contain(const Node* &node, Key key) const {
        if (node == nullptr)  // base
            return false;

        if (key == node->key)
            return ture;
        else if (key < node->key)
            contain(node->left, key);
        else
            contain(node->right, key);
    }

    Value* search(const Node* &node, Key key) const {
        if (node == nullptr) {  // base
            return nullptr;
        }
        if (key == node->key)
            return &(node->value);
        else if (key < node->key)
            return search(node->left, key, value);
        else
            return search(node->right, key, value);
    }

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


    // Post Order
    void destroy(Node* node){
        if(node != nullptr){
            destroy(node->left);
            destroy(node->right);

            delete node;
            count--;
        }
    }
};