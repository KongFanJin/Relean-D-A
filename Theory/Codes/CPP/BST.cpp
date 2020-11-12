#include <cassert>
#include <cstddef>
#include <iostream>
#include <queue>

using namespace std;

// 二分搜索树
template <typename Key, typename Value> class BST {
private:
  // 二分搜索树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
  struct Node {
    Key key;
    Value value;
    Node *left;
    Node *right;

    Node(Key key, Value value) {
      this->key = key;
      this->value = value;
      this->left = this->right = NULL;
    }
    
    // 拷贝赋值构造
    Node(Node *node){
      this->key = node->key;
      this->value = node->value;
      this->left = node->left;
      this->right = node->right;      
    }
  };

  Node *root; // 根节点
  int count;  // 节点个数

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
  Value *search(Key key) { return search(root, key); }

  void preOrder() { preOrder(root); }

  void inOrder() { inOrder(root); }

  void postOrder() { postOrder(root); }

  void levelOrder() { levelOrder(root); }

  Key minimum() {
    assert(count != 0);
    return minimum(root)->key;
  }

  Key maximum() {
    assert(count != 0);
    return maximum(root)->key;
  }

  void removeMin() {
    if (root != nullptr)
      root = removeMin(root);
  }

  void removeMax() {
    if (root != nullptr)
      root = removeMax(root);
  }

  void remove(Key key) { root = remove(root, key); }

private:
  // Recursion
  Node *insertRecursive(Node *&node, Key key, Value value) {
    if (node == nullptr) { // base
      count++;
      return new Node(key, value);
    }
    if (key == node->key)
      node->value = value; // update value
    else if (key < node->key)
      node->left = insert(node->left, key, value);
    else
      node->right = insert(node->right, key, value);
  }

  // 用两个指针记录父节点和子节点,迭代匹配,找到后插入父节点
  // Iterative function to insert a key into BST.
  // Root is passed by reference to the function
  Node *insertIterative(Node *&node, Key key, Value value) {
    // start with root node
    Node *curr = root;

    // pointer to store parent node of current node
    Node *parent = nullptr;

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

  bool contain(const Node *&node, Key key) const {
    if (node == nullptr) // base
      return false;

    if (key == node->key)
      return true;

    else if (key < node->key)
      contain(node->left, key);
    else
      contain(node->right, key);
  }

  Value *search(const Node *&node, Key key) const {
    if (node == nullptr) { // base
      return nullptr;
    }
    if (key == node->key)
      return &(node->value);
    else if (key < node->key)
      return search(node->left, node->key, node->value);
    else
      return search(node->right, node->key, node->value);
  }

  void preOrder(Node *node) {
    if (node != nullptr) {
      cout << node->key << "\n";
      preOrder(node->left);
      preOrder(node->right);
    }
  }

  void inOrder(Node *node) {
    if (node != nullptr) {
      inOrder(node->left);
      cout << node->key << "\n";
      inOrder(node->right);
    }
  }

  void postOrder(Node *node) {
    if (node != nullptr) {
      inOrder(node->left);
      inOrder(node->right);
      cout << node->key << "\n";
    }
  }

  void levelOrder(Node *&node) {
    queue<Node *> q;
    q.push(node);
    while (!q.empty()) {
      Node *node = q.front();
      q.pop();

      cout << node->key << "\n";

      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
  }

  Node *minimum(Node *node) {
    if (node->left == nullptr)
      return node;

    return minimum(node->left);
  }

  Node *maximum(Node *node) {
    if (node->right == nullptr)
      return node;

    return maximum(node->left);
  }

  Node *removeMin(Node *node) {
    if (node->left == nullptr) {
      // 包含了node是叶子节点和不是叶子节点两种情况:
      // 叶子节点返回空(叶子节点的右儿子也为空);非叶子节点,返回右儿子
      Node *rightNode = node->right;
      delete node;
      count--;
      return rightNode;
    }

    node->left = removeMin(node->left);
    return node;
  }

  Node *removeMax(Node *node) {
    if (node->right == nullptr) {
      // 包含了node是叶子节点和不是叶子节点两种情况:
      // 叶子节点返回空(叶子节点的右儿子也为空);非叶子节点,返回左儿子
      Node *leftNode = node->left;
      delete node;
      count--;
      return leftNode;
    }

    node->right = removeMax(node->right);
    return node;
  }

  Node *remove(Node *node, Key key) {
    if (node == nullptr)
      return nullptr;

    if (key == node->key){
      if(node->left == nullptr){ // min
        Node* rightNode = node->right;
        delete node;
        count--;
        return rightNode;
      }

      if(node->right == nullptr){ // max
        Node* leftNode = node->left;
        delete node;
        count--;
        return leftNode;
      }     

      // 关键部分
      Node* successor = minimum(node->right); // 指向node右子树的最小值
      count++;

      // successor->right = removeMin(node->right),
      // 若直接这么用有问题removeMin(node->right)后,node->right的值变为未定义/空
      successor->right = new Node(removeMin(node->right)); 
      successor->right = node->left;

      // 关键部分

      delete node;
      count--;

      return successor;
    }else if (key < node->key) {
      node->left = remove(node->left, key);
      return node;
    } else {
      node->right = remove(node->right, key);
      return node;
    }
  }

  // Post Order
  void destroy(Node *node) {
    if (node != nullptr) {
      destroy(node->left);
      destroy(node->right);

      delete node;
      count--;
    }
  }
};