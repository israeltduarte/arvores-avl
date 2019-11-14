#include "Lista.cpp"

class BinaryNode
{
public:
    int info;
    int height;
    BinaryNode *right;
    BinaryNode *left;

    BinaryNode(int info);
    BinaryNode(int info, BinaryNode *left, BinaryNode *right);
};

BinaryNode::BinaryNode(int info)
{
    this->info = info;
    this->right = NULL;
    this->left = NULL;
    this->height = 0;
}

BinaryNode::BinaryNode(int info, BinaryNode *left, BinaryNode *right)
{
    this->info = info;
    this->right = right;
    this->left = left;
    this->height = 0;
}