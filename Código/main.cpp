#include <iostream>
using namespace std;

int mochila(int capacidade, int pesos[], int beneficio[], int numItens){
    int tabela[numItens + 1][capacidade + 1]; // tabela com todos os dados

    // inicializando a primeira linha e primeira coluna com 0
    for(int i = 0; i <= capacidade; i++)
        tabela[0][i] = 0;
    for(int j = 1; j <= numItens; j++)
        tabela[j][0] = 0;

    for(int i = 1; i <= numItens; i++)
    {
        for(int j = 1; j <= capacidade; j++)
        {
            // elemento pode fazer parte da solução
            if(pesos[i - 1] <= j)
            {
                if((beneficio[i - 1] + tabela[i - 1][j - pesos[i - 1]]) > tabela[i - 1][j]){
                    tabela[i][j] = beneficio[i - 1] + tabela[i - 1][j - pesos[i - 1]];
                } else {
                    tabela[i][j] = tabela[i - 1][j];
                }
            } else {
                tabela[i][j] = tabela[i - 1][j];
            }
        }
    }

    return tabela[numItens][capacidade];
}

int main(){
    int capacidade, itens, opc;
    cout << "Entre com a capacidade da mochila: ";
    cin >> capacidade;

    cout << "Quantidade de itens: ";
    cin >> itens;

    int beneficios[itens];
    int pesos[itens];

    cout << "Entre com os pesos e beneficios respectivamente de cada item:" << endl;
    for (int i = 0; i < itens; ++i) {
        cout << "Item " << i+1 << endl;
        cout << "Peso: ";
        cin >> pesos[i];
        cout << "Beneficio: ";
        cin >> beneficios[i];
        cout << "---------------------------" << endl;
    }

    system("cls");

    cout << "- Escolha qual metodo utilizar -" << endl << endl;
    cout << "> (1) Carga ótima" << endl;
    cout << "> (2) Melhores valores" << endl;
    cout << "> (3) Menores pesos" << endl;
    cin >> opc;

    switch (opc) {
    case 1:
        int melhorCarga = mochila(capacidade, pesos, beneficios, itens);
        cout << "Carga otima: " << melhorCarga << endl;
        break;

    case 2:
        cout << "Melhores valores: " << endl;
        break;

    case 3:
        cout << "Menores pesos: " << endl;
        break;
    }

    return 0;
}
