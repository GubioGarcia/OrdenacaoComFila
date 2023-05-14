#include "fila.h"

namespace ggs{
    Fila::Fila(int tamanho):
        tamanho(0), arrayFila(0), inicio(-1), fim(-1), quantidadeElementos(0)
    {
        try{
            if(tamanho<=0) throw QString("Tamanho deve ser maior que zero");
            this->arrayFila = new int[tamanho];
            this->tamanho = tamanho;
        } catch(std::bad_alloc &erro){
            throw QString("Não foi possível criar a Fila, falta memória");
        }
    }

    Fila::~Fila(){
        if(arrayFila) delete[] arrayFila;
    }

    bool Fila::estaVazia()const{
        return (quantidadeElementos==0);
    }

    bool Fila::estaCheia()const{
        return (quantidadeElementos==tamanho);
    }

    int Fila::acessar()const{
        if(estaVazia()) throw QString("Fila está vazia");
        return arrayFila[inicio];
    }

    void Fila::inserir(int elemento){
        if(estaCheia()) throw QString("Fila está cheia");
        if(estaVazia()) inicio = 0;
        if(fim==tamanho) fim = 0;
        else fim++;
        arrayFila[fim] = elemento;
        quantidadeElementos++;
    }

    int Fila::retirar(){
        if(estaVazia()) throw QString("Fila está vazia");
        int aux = arrayFila[inicio];
        if(inicio==tamanho) inicio = 0;
        else inicio++;
        quantidadeElementos--;
        if(estaVazia()) inicio = fim = -1;
        return aux;
    }
}
