#include <iostream>
#include "BinaryNode.cpp"

class BinaryTree
{
public:
	BinaryNode *root;

	BinaryTree();
	~BinaryTree();

	bool isEmpty();
	void insert();
	void insert(int info);
	BinaryNode *insert(int info, BinaryNode *novo);
	void search(int value);
	int search(int info, BinaryNode *start);
	int searchRecursiveCount(int info, int rec, BinaryNode *start);

	BinaryNode *remove(int info, BinaryNode *root);
	void print(int printMode);

	void PreOrdem(BinaryNode *start);
	void EmOrdem(BinaryNode *start);
	void PosOrdem(BinaryNode *start);
	void finish();

	int heightBase();
	int heightTeste(BinaryNode *t, int height);

	void recursiveCalls(int value);
};

BinaryTree::BinaryTree()
{
	this->root = NULL;
}

BinaryTree::~BinaryTree()
{
	delete root;
}

bool BinaryTree::isEmpty()
{
	return this->root == NULL;
}

void BinaryTree::insert(int info)
{
	if (this->root == NULL)
	{
		this->root = new BinaryNode(info);
	}
	else
	{
		insert(info, this->root);
	}
}

BinaryNode *BinaryTree::insert(int info, BinaryNode *arv)
{
	if (arv == NULL)
	{
		arv = new BinaryNode(info);
		arv->height++;
	}
	else if (arv->info >= info)
	{
		arv->left = insert(info, arv->left);
	}
	else if (arv->info < info)
	{
		arv->right = insert(info, arv->right);
	}

	return arv;
}

void BinaryTree::search(int value)
{
	int numeroInformado = search(value, this->root);

	if (numeroInformado == 666)
	{
		cout << "Número " << value << " não encontrado na árvore Binária." << endl;
	}
	else
	{
		cout << "Número " << value << " encontrado na árvore Binária." << endl;
	}
}

int BinaryTree::search(int info, BinaryNode *start)
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

BinaryNode *BinaryTree::remove(int info, BinaryNode *tr)
{
	if (tr == NULL)
	{
		return NULL;
	}
	else if (tr->info > info)
	{
		tr->left = remove(info, tr->left);
	}
	else if (tr->info < info)
	{
		tr->right = remove(info, tr->right);
	}
	else
	{
		if (tr->left == NULL && tr->right == NULL)
		{
			free(tr);
			tr = NULL;
		}

		else if (tr->left == NULL)
		{
			BinaryNode *t = tr;
			tr = tr->right;
			free(t);
		}

		else if (tr->right == NULL)
		{
			BinaryNode *t = tr;
			tr = tr->left;
			free(t);
		}

		else
		{
			BinaryNode *f = tr->left;
			while (f->right != NULL)
			{
				f = f->right;
			}
			int i = tr->info;
			tr->info = f->info;
			f->info = i;

			tr->left = remove(i, tr->left);
		}
	}

	return tr;
}

void BinaryTree::print(int printMode)
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

void BinaryTree::PreOrdem(BinaryNode *tn)
{
	if (tn != NULL)
	{
		cout << tn->info << endl;
		this->PreOrdem(tn->left);
		this->PreOrdem(tn->right);
	}
}

void BinaryTree::EmOrdem(BinaryNode *tn)
{
	if (tn != NULL)
	{
		this->EmOrdem(tn->left);
		cout << tn->info << endl;
		this->EmOrdem(tn->right);
	}
}

void BinaryTree::PosOrdem(BinaryNode *tn)
{
	if (tn != NULL)
	{
		this->PosOrdem(tn->left);
		this->PosOrdem(tn->right);
		cout << tn->info << endl;
	}
}

void BinaryTree::finish()
{
	this->~BinaryTree();
}

int BinaryTree::heightBase()
{
	return heightTeste(this->root, -1);
}

int BinaryTree::heightTeste(BinaryNode *t, int height)
{
	if (t == NULL)
	{
		return height;
	}
	else if (t->left == NULL && t->right == NULL)
	{
		return ++height;
	}
	else if (t->left != NULL && t->right != NULL)
	{
		height++;
		int l = heightTeste(t->left, height);
		int r = heightTeste(t->right, height);

		return (l < r) ? r : l;
	}
	else if (t->left != NULL && t->right == NULL)
	{
		return heightTeste(t->left, ++height);
	}
	else if (t->right != NULL && t->left == NULL)
	{
		return heightTeste(t->right, ++height);
	}

	return height;
}

void BinaryTree::recursiveCalls(int value)
{
	int rec = 0;
	cout << "Quantidade de chamadas recursivas na Árvore Binária: " << searchRecursiveCount(value, rec, this->root) << endl;
}

int BinaryTree::searchRecursiveCount(int info, int rec, BinaryNode *start)
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