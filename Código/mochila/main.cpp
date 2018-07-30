#include <iostream>
#include <stdlib.h>

using namespace std;

// Colocando vetores em ordem crescente
int ordenar (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}

// Cálculo da carga ótima
int cargaOtima(int capacidade, int pesos[], int beneficio[], int numItens) {

    int tabela[numItens + 1][capacidade + 1]; // tabela com todos os dados

    for(int i = 0; i <= capacidade; i++)
        tabela[0][i] = 0;
    for(int j = 1; j <= numItens; j++)
        tabela[j][0] = 0;

    for(int i = 1; i <= numItens; i++) {
        for(int j = 1; j <= capacidade; j++) {
            if(pesos[i - 1] <= j) {
                if((beneficio[i - 1] + tabela[i - 1][j - pesos[i - 1]]) > tabela[i - 1][j]) {
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

// Cálculo pelos melhores benefícios
int melhorValor(int capacidade, int peso[], int beneficio[], int numItens) {

    int melhorValor = 0, aux = 0, pesoTotal = 0;
    qsort(beneficio, numItens, sizeof(int), ordenar);

    for (int i = numItens-1; i >= 0; --i) {
        if (pesoTotal > capacidade) {
            return aux;
        } else if (i == 0){
            return melhorValor;
        } else {
            aux = melhorValor;
            pesoTotal = pesoTotal + peso[i];
            melhorValor = melhorValor + beneficio[i];
        }
    }
}

// Cálculo pelos menores pesos
int menorPeso(int capacidade, int peso[], int beneficio[], int numItens) {

    int melhorPeso = 0, aux = 0, pesoTotal = 0;
    qsort(beneficio, numItens, sizeof(int), ordenar);

    for (int i = 0; i < numItens; ++i) {
        if (pesoTotal > capacidade) {
            return aux;
        } else if (i == numItens-1){
            return melhorPeso;
        } else {
            aux = melhorPeso;
            pesoTotal = pesoTotal + peso[i];
            melhorPeso = melhorPeso + beneficio[i];
        }
    }
}

int main(){
    int capacidade, itens = 0, opc, solucao;

    cout << "Entre com a capacidade da mochila: ";
    cin >> capacidade;

    cout << "Quantidade de itens: ";
    cin >> itens;

    int beneficios[itens], pesos[itens];

    cout << endl << "Entre com os pesos e beneficios respectivamente de cada item:" << endl;
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
    cout << "> (1) Carga otima" << endl;
    cout << "> (2) Melhores valores" << endl;
    cout << "> (3) Menores pesos" << endl;
    cout << "> (4) Todos" << endl << endl;
    cout << "> Escolha: ";
    cin >> opc;

    cout << endl;

    switch (opc) {
    case 1:
        solucao = cargaOtima(capacidade, pesos, beneficios, itens);
        cout << "- RESULTADO -" << endl << "> Carga otima: " << solucao << endl;
        break;

    case 2:
        solucao = melhorValor(capacidade, pesos, beneficios, itens);
        cout << "- RESULTADO -" << endl << "> Melhores valores: " << solucao << endl;
        break;

    case 3:
        solucao = menorPeso(capacidade, pesos, beneficios, itens);
        cout << "- RESULTADO -" << endl << "> Menores pesos: " << solucao << endl;
        break;
    case 4:
        int s1 = cargaOtima(capacidade, pesos, beneficios, itens);
        int s2 = melhorValor(capacidade, pesos, beneficios, itens);
        int s3 = menorPeso(capacidade, pesos, beneficios, itens);
        cout << "- RESULTADO -" << endl << "> Carga otima: " << s1 << endl;
        cout << "- RESULTADO -" << endl << "> Melhores valores: " << s2 << endl;
        cout << "- RESULTADO -" << endl << "> Menores pesos: " << s3 << endl;
        break;

    }

    cout << endl << endl;
    system("pause");
    return 0;
}
