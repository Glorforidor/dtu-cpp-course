#include <iostream>
#include <string>

using namespace std;

enum dir
{
    TOP,
    LEFT,
    RIGHT
};

class Node
{
public:
    int value;
    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    };

    ~Node(){};
};

class Tree
{
public:
    Node *root;
    int tsize;

    Tree()
    {
        this->root = nullptr;
    };

    ~Tree()
    {
        deleteTree(this->root);
        this->root = nullptr;
        this->tsize = 0;
    };

    void deleteTree(Node *n)
    {
        if (n == nullptr)
        {
            return;
        }

        deleteTree(n->left);
        deleteTree(n->right);

        // cout << "Deleting node with value: " << n->value << endl;
        delete n;
    };

    // insertFibonacci inserts the fibonacci sequence into the tree.
    void insertFibonacci(int value)
    {
        this->root = insertFib(value);
    };

    // size returns the number of nodes in the tree.
    int size()
    {
        return size(this->root);
    }

    // depth returns the tree's depth.
    int depth()
    {
        return depth(this->root);
    };

    // leafs returns the number of leafs in the tree.
    int leafs()
    {
        return leafs(this->root);
    };

private:
    Node *insertFib(int value)
    {
        Node *current = new Node(value);
        tsize += 1;

        if (value <= 1)
        {
            current->value = 1;
        }
        else
        {
            current->left = insertFib(value - 1);
            current->right = insertFib(value - 2);
            current->value = current->left->value + current->right->value;
        }

        return current;
    };

    int size(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        return size(n->left) + size(n->right) + 1;
    }

    int depth(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        int leftDepth = depth(n->left);
        int rightDepth = depth(n->right);

        if (leftDepth > rightDepth)
        {
            return leftDepth + 1;
        }
        else
        {
            return rightDepth + 1;
        }
    };

    int leafs(Node *n)
    {
        if (n == nullptr)
        {
            return 0;
        }

        if (n->left == nullptr && n->right == nullptr)
        {
            return 1;
        }

        return leafs(n->left) + leafs(n->right);
    };
};

void preOrderTraverse(Node *n)
{
    if (n == nullptr)
    {
        return;
    }
    cout << n->value << " ";
    preOrderTraverse(n->left);
    preOrderTraverse(n->right);
}

int main()
{
    int input;
    cin >> input;

    // create pretty tree
    Tree t;
    t.insertFibonacci(input);

    cout << "Call tree in pre-order: ";
    preOrderTraverse(t.root);

    cout << endl;
    cout << "Call tree size: " << t.size() << endl;
    cout << "Call tree tsize: " << t.tsize << endl;
    cout << "Call tree depth: " << t.depth() << endl;
    cout << "Call tree leafs: " << t.leafs() << endl;
    return 0;
}
