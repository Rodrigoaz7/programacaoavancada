#include <iostream>
using namespace std;

//Função para inverter números inteiros
//int inverte(unsigned int n)
//{
//    unsigned int num=0;
//
//    while(n>0)
//    {
//        num = (num*10) + n%10;
//        n = n/10;
//    }
//
//    return num;
//}

// Função de manipulação de vetor
void questao9(float v[])
{
    float soma=0.0, menor;
    menor = v[0];

    for(int i=0; i<4; i++)
    {
        if(v[i] < menor)
        {
            menor = v[i];
        }

        soma = soma + v[i];
    }

    cout << "Media: " << soma/5.0 << endl;
    cout << "Menor: " << menor << endl;
    cout << "Retorno = Media - Menor: " << (soma/5.0)-menor << endl;
}

int main()
{
    float v[5]={};

    for(int i=0; i<4; i++)
    {
        cin >> v[i];
    }

    questao9(v);

    return 0;
}
