#include <iostream>
#include "BinaryTree.cpp"
#include "AVLTree.cpp"

using namespace std;

class Menu
{
public:
    void execute();
    Menu();
    int getInfo();
    int getPrintMode();
    int getNumber();
};

Menu::Menu()
{
}

void Menu::execute()
{
    int entrada = 0;

    BinaryTree *bt = new BinaryTree();
    AVLTree *at = new AVLTree();

    do
    {
        cout << "Selecione sua ação:\n";
        cout << "1 - Inserir lista na arvore\n";
        cout << "2 - Buscar elemento na arvore\n";
        cout << "3 - Remover elemento da arvore\n";
        cout << "4 - Imprimir arvore\n";
        cout << "5 - Altura máxima\n";
        cout << "6 - Chamadas recursivas\n";

        cout << "0 - Sair\n";

        cout << "Escolha: ";

        cin >> entrada;

        switch (entrada)
        {
        case 1:
        {
            int n;
            bool flag = true;
            cout << "Informe os valores a serem inseridos nas árvores: \n";

            do
            {
                cin >> n;
                if (n > 0)
                {
                    bt->insert(n);
                    at->insert(n);
                }
                else
                {
                    flag = false;
                }
            } while (flag);
            break;
        }

        case 2:
        {
            int numeroProcurado = this->getNumber();
            bt->search(numeroProcurado);
            at->search(numeroProcurado);
            break;
        }

        case 3:
        {
            int n;
            cout << "Informe o valor a ser removido das árvores: ";
            cin >> n;
            bt->remove(n, bt->root);
            at->remove(n, at->root);
            break;
        }

        case 4:
        {
            int printMode = this->getPrintMode();
            cout << "Árvore Binária - ";
            bt->print(printMode);

            cout << "Árvore AVL - ";
            at->print(printMode);
            break;
        }

        case 5:
        {
            cout << "Altura da Árvore Binária: " << bt->heightBase() << endl;
            cout << "Altura da Árvore AVL: " << at->height(at->root) << endl;
            break;
        }

        case 6:
        {
            cout << "Informe o valor a ser procurado para a contagem da recursao: ";
            int n;
            cin >> n;

            bt->recursiveCalls(n);
            at->recursiveCalls(n);
            break;
        }

        case 0:
        {
            entrada = -1;
            bt->finish();
            break;
        }

        default:
        {
            break;
        }
        }
    } while (entrada > 0);
}

int Menu::getNumber()
{
    cout << "Informe o numero a ser procurado: ";
    int value;
    cin >> value;
    return value;
}

int Menu::getInfo()
{
    int i = 0, n;
    cout << "Valor do Nodo " << i + 1 << ":\n";
    cin >> n;

    return n;
}

int Menu::getPrintMode()
{
    int n;
    do
    {
        cout << "Informe o Modo de Impressao\n";
        cout << "1 - Pre Ordem\n";
        cout << "2 - Em Ordem\n";
        cout << "3 - Pos Ordem\n";
        cout << "Escolha: ";
        cin >> n;
    } while (n < 1 && n > 3);

    return n;
}