#include <iostream>
#include "Menu.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Iniciando programa\n";

    Menu m = *new Menu();

    m.execute();

    cout << "Fim da Execucao\n";

    return 0;
}