#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
  if (root == NULL) return;
  traverseInOrder(root->left);
  cout << root->key << " ";
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *root, int key) {
  if (root == NULL) {
    struct node *newNode = new struct node;
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
  }

  if (key < root->key) {
    root->left = insertNode(root->left, key);
  } else if (key > root->key) {
    root->right = insertNode(root->right, key);
  }

  return root;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key) {
    root->left = deleteNode(root->left, key);
  } else if (key > root->key) {
    root->right = deleteNode(root->right, key);
  } else {
    if (root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    } else if (root->left == NULL) {
      struct node *temp = root->right;
      delete root;
      return temp;
    } else if (root->right == NULL) {
      struct node *temp = root->left;
      delete root;
      return temp;
    } else {
      struct node *minRight = root->right;
      while (minRight->left != NULL) {
        minRight = minRight->left;
      }
      root->key = minRight->key;
      root->right = deleteNode(root->right, minRight->key);
    }
  }

  return root;
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
    cin >> operation;
  }
  
  traverseInOrder(root);
  cout << endl;
  return 0;
}
