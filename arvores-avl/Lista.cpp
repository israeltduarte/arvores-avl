#include <iostream>
#include "Node.cpp"

class Lista
{
public:
    Node *primeiro;
    Node *ultimo;
    int tamanhoTotal;

    Lista();
    Lista(int info);
    ~Lista();
    bool vazia();
    void mostrar();
    int buscar(int value);
    void inserirFim(int value);
    int tamanho();
    void remover();
};

Lista::Lista()
{
    primeiro = NULL;
    ultimo = NULL;
    tamanhoTotal = 0;
}

Lista::Lista(int info)
{
    primeiro = new Node();
    this->inserirFim(info);
    ultimo = NULL;
    tamanhoTotal = 1;
}

Lista::~Lista()
{
    delete primeiro;
}

bool Lista::vazia()
{
    return (primeiro == NULL);
}

void Lista::mostrar()
{
    Node *c = primeiro;

    if (vazia())
        cout << "Lista vazia\n";
    else
    {
        while (c)
        {
            cout << c->obterInfo() << " ";
            c = c->obterProx();
        }
    }

    cout << endl;
}

int Lista::buscar(int value)
{
    Node *b = primeiro;

    while (b)
    {
        if (b->obterInfo() == value)
        {
            return value;
        }
        b = b->obterProx();
    }

    return 666;
}

void Lista::inserirFim(int value)
{
    Node *novo = new Node(value);

    if (vazia())
    {
        primeiro = novo;
        ultimo = novo;
    }
    else
    {
        ultimo->setProx(novo);
        ultimo = novo;
    }
    tamanhoTotal++;
}

int Lista::tamanho()
{
    return tamanhoTotal;
}

void Lista::remover()
{
    if (!vazia())
    {
        if (primeiro->obterProx() == NULL)
            primeiro = NULL;
        else if (primeiro->obterProx()->obterProx() == NULL)
            primeiro->setProx(NULL);
        else
        {
            Node *ant_ant = primeiro;
            Node *ant = primeiro->obterProx();
            Node *corrente = primeiro->obterProx()->obterProx();

            while (corrente)
            {
                Node *aux = ant;
                ant = corrente;
                ant_ant = aux;
                corrente = corrente->obterProx();
            }

            delete ant_ant->obterProx();
            ant_ant->setProx(NULL);
            ultimo = ant_ant;
        }
    }
}