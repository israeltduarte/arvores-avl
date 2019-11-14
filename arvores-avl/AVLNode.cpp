class AVLNode
{
public:
    int info;
    int height;
    AVLNode *right;
    AVLNode *left;

    AVLNode();
    AVLNode(int info);
    AVLNode(int info, AVLNode *left, AVLNode *right);
};

AVLNode::AVLNode()
{
}

AVLNode::AVLNode(int info)
{
    this->info = info;
    this->right = NULL;
    this->left = NULL;
    this->height = 0;
}

AVLNode::AVLNode(int info, AVLNode *left, AVLNode *right)
{
    this->info = info;
    this->right = right;
    this->left = left;
    this->height = 0;
}