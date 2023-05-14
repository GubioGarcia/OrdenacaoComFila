#ifndef FILA_H
#define FILA_H

#include <QString>

namespace ggs{
    class Fila
    {
    private:
        int tamanho;
        int *arrayFila;
        int inicio;
        int fim;
        int quantidadeElementos;
    public:
        Fila(int tamanho);
        ~Fila();
        void inserir(int elemento);//sempre inserir no fim
        int retirar();//sempre retirar no inicio
        bool estaVazia()const;//baseado na quantElementos
        bool estaCheia()const;//baseado na quantElementos
        int acessar()const;
    };
}
#endif // FILA_H
