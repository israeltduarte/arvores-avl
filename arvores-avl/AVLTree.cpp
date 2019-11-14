#include <iostream>
#include "AVLNode.cpp"

using namespace std;

class AVLTree
{
public:
	AVLNode *root;

	AVLTree();
	~AVLTree();

	AVLNode *insert(int info);
	AVLNode *insert(int info, AVLNode *&t);

	AVLNode *remove(int info, AVLNode *&t);

	AVLNode *findMin(AVLNode *t);
	AVLNode *findMax(AVLNode *t);

	AVLNode *doubleRightRotate(AVLNode *&t);
	AVLNode *doubleLeftRotate(AVLNode *&t);

	AVLNode *singleRightRotate(AVLNode *&t);
	AVLNode *singleLeftRotate(AVLNode *&t);

	void search(int numero);
	int search(int info, AVLNode *start);
	int searchRecursiveCount(int info, int rec, AVLNode *start);

	void print(int printMode);
	void PreOrdem(AVLNode *start);
	void EmOrdem(AVLNode *start);
	void PosOrdem(AVLNode *start);

	int getBalance(AVLNode *t);
	int height(AVLNode *t);
	void makeEmpty(AVLNode *t);

	int heightBase();
	int heightTeste(BinaryNode *t, int height);

	void recursiveCalls(int value);
};

AVLTree::AVLTree()
{
	this->root = NULL;
}

AVLTree::~AVLTree()
{
	delete root;
}

AVLNode *AVLTree::insert(int info)
{
	return insert(info, this->root);
}

AVLNode *AVLTree::insert(int info, AVLNode *&node)
{
	if (node == NULL)
	{
		node = new AVLNode(info);
	}
	else if (info < node->info)
	{
		node->left = insert(info, node->left);
		if (height(node->left) - height(node->right) == 2)
		{
			if (info < node->left->info)
			{
				node = singleRightRotate(node);
			}
			else
			{
				node = doubleRightRotate(node);
			}
		}
	}
	else if (info > node->info)
	{
		node->right = insert(info, node->right);
		if (height(node->right) - height(node->left) == 2)
		{
			if (info > node->right->info)
			{
				node = singleLeftRotate(node);
			}
			else
			{
				node = doubleLeftRotate(node);
			}
		}
	}

	node->height = max(height(node->left), height(node->right)) + 1;

	return node;
}

AVLNode *AVLTree::remove(int info, AVLNode *&node)
{
	AVLNode *temp;

	if (node == NULL)
	{
		return NULL;
	}
	else if (info < node->info)
	{
		node->left = remove(info, node->left);
	}
	else if (info > node->info)
	{
		node->right = remove(info, node->right);
	}
	else if (node->left && node->right)
	{
		temp = findMin(node->right);
		node->info = temp->info;
		node->right = remove(node->info, node->right);
	}
	else
	{
		temp = node;
		if (node->left == NULL)
		{
			node = node->right;
		}
		else if (node->right == NULL)
		{
			node = node->left;
		}
	}

	if (node == NULL)
	{
		return node;
	}

	node->height = max(height(node->left), height(node->right)) + 1;

	if (height(node->left) - height(node->right) == 2)
	{
		if (height(node->left->left) - height(node->left->right) == 1)
		{
			return singleLeftRotate(node);
		}
		else
		{
			return doubleLeftRotate(node);
		}
	}
	else if (height(node->right) - height(node->left) == 2)
	{
		if (height(node->right->right) - height(node->right->left) == 1)
		{
			return singleRightRotate(node);
		}
		else
		{
			return doubleRightRotate(node);
		}
	}
	return node;
}

AVLNode *AVLTree::findMin(AVLNode *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	else if (node->left == NULL)
	{
		return node;
	}

	return findMin(node->left);
}

AVLNode *AVLTree::findMax(AVLNode *node)
{
	if (node == NULL)
	{
		return NULL;
	}
	else if (node->right == NULL)
	{
		return node;
	}

	return findMax(node->right);
}

AVLNode *AVLTree::singleRightRotate(AVLNode *&t)
{
	AVLNode *u = t->left;
	t->left = u->right;
	u->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(u->left), t->height) + 1;
	return u;
}

AVLNode *AVLTree::singleLeftRotate(AVLNode *&t)
{
	AVLNode *u = t->right;
	t->right = u->left;
	u->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	u->height = max(height(t->right), t->height) + 1;
	return u;
}

AVLNode *AVLTree::doubleRightRotate(AVLNode *&t)
{
	t->left = singleLeftRotate(t->left);
	return singleRightRotate(t);
}

void AVLTree::search(int numero)
{
	int numeroInformado = search(numero, this->root);

	if (numeroInformado == 666)
	{
		cout << "Número " << numero << " não encontrado na Árvore AVL." << endl;
	}
	else
	{
		cout << "Número " << numero << " encontrado na Árvore AVL." << endl;
	}
}

int AVLTree::search(int info, AVLNode *start)
{
	if (start == NULL)
	{
		return 666;
	}
	else if (start->info > info)
	{
		return search(info, start->left);
	}
	else if (start->info < info)
	{
		return search(info, start->right);
	}

	return info;
}

AVLNode *AVLTree::doubleLeftRotate(AVLNode *&t)
{
	t->right = singleRightRotate(t->right);
	return singleLeftRotate(t);
}

void AVLTree::print(int printMode)
{
	switch (printMode)
	{
	case 1:
		cout << "Pre Ordem\n";
		PreOrdem(this->root);
		break;

	case 2:
		cout << "Em Ordem\n";
		EmOrdem(this->root);
		break;

	case 3:
		cout << "Pos Ordem\n";
		PosOrdem(this->root);
		break;

	default:
		break;
	}
}

void AVLTree::PreOrdem(AVLNode *tn)
{
	if (tn != NULL)
	{
		cout << tn->info << endl;
		this->PreOrdem(tn->left);
		this->PreOrdem(tn->right);
	}
}

void AVLTree::EmOrdem(AVLNode *tn)
{
	if (tn != NULL)
	{
		this->EmOrdem(tn->left);
		cout << tn->info << endl;
		this->EmOrdem(tn->right);
	}
}

void AVLTree::PosOrdem(AVLNode *tn)
{
	if (tn != NULL)
	{
		this->PosOrdem(tn->left);
		this->PosOrdem(tn->right);
		cout << tn->info << endl;
	}
}

int AVLTree::getBalance(AVLNode *t)
{
	if (t == NULL)
		return 0;
	else
		return height(t->left) - height(t->right);
}

int AVLTree::height(AVLNode *t)
{
	return (t == NULL ? -1 : t->height);
}

void AVLTree::makeEmpty(AVLNode *t)
{
	if (t == NULL)
	{
		return;
	}
	makeEmpty(t->left);
	makeEmpty(t->right);
	delete t;
}

void AVLTree::recursiveCalls(int value)
{
	cout << "Quantidade de chamadas recursivas na Árvore AVL: " << searchRecursiveCount(value, 0, this->root) << endl;
}

int AVLTree::searchRecursiveCount(int info, int rec, AVLNode *start)
{
	if (start == NULL)
	{
		return rec;
	}
	else if (start->info > info)
	{
		return searchRecursiveCount(info, ++rec, start->left);
	}
	else if (start->info < info)
	{
		return searchRecursiveCount(info, ++rec, start->right);
	}

	return rec;
}