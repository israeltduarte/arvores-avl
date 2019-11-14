#include <iostream>

using namespace std;

class Node
{
public:
    Node();
    Node(int info);
    int obterInfo();
    Node *obterProx();
    void setProx(Node *p);

private:
    int info;
    Node *prox;
};

Node::Node()
{
    this->info = (int)NULL;
    this->prox = NULL;
}

Node::Node(int info)
{
    this->info = info;
    this->prox = NULL;
}

int Node::obterInfo()
{
    return info;
}

Node *Node::obterProx()
{
    return this->prox;
}

void Node::setProx(Node *p)
{
    prox = p;
}