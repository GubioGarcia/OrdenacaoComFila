#include "executarordenacao.h"

namespace ggs{
    ExecutarOrdenacao::ExecutarOrdenacao(int quantidadeElementos):
        quantidadeElementos(0),
        array(0)
    {
        try{
            array = new int[quantidadeElementos];
            this->quantidadeElementos = quantidadeElementos;

            std::srand(time(NULL)); //usando time() para definir uma semente aleatoria
            for (int i=0; i<quantidadeElementos; i++){
                array[i] = 1 + std::rand() % 100; //gerando numero aleatorio no intervalo entre 0 e 100
            }
        } catch(std::bad_alloc){
            throw QString("Não foi possível criar o vetor");
        }
    }

    ExecutarOrdenacao::~ExecutarOrdenacao(){
        if(array) delete[] array;
    }

    QString ExecutarOrdenacao::imprimirVetor()const{
        QString strVetor = "[";
        for(int i=0; i<quantidadeElementos; i++){
            strVetor += QString::number(array[i]);
            if(i<quantidadeElementos-1) strVetor += ", ";
        }
        return strVetor += "]";
    }

    void ExecutarOrdenacao::ordenarCrescente(){
        Fila fila(quantidadeElementos);
        fila.inserir(array[0]);

        int aux = array[0];
        for(int i=1; i<quantidadeElementos; i++){
            if(fila.acessar() > array[i]){
                fila.inserir(array[i]);
                while(fila.acessar() > array[i]){
                    aux = fila.acessar();
                    fila.inserir(fila.retirar());
                }
            } else{
                if(aux < array[i]){
                    fila.inserir(array[i]);
                    aux = array[i];
                } else{
                    while(fila.acessar() < array[i]) fila.inserir(fila.retirar());
                    fila.inserir(array[i]);
                    while(fila.acessar() > array[i]) fila.inserir(fila.retirar());
                }
            }
        }

        for(int i=0; i<quantidadeElementos; i++){
            array[i] = fila.retirar();
        }
    }

    void ExecutarOrdenacao::ordenarDecrescente(){
        Fila fila(quantidadeElementos);
        fila.inserir(array[0]);

        int aux = array[0];
        for(int i=1; i<quantidadeElementos; i++){
            if(fila.acessar() < array[i]){
                fila.inserir(array[i]);
                while(fila.acessar() < array[i]){
                    aux = fila.acessar();
                    fila.inserir(fila.retirar());
                }
            } else{
                if(aux > array[i]){
                    fila.inserir(array[i]);
                    aux = array[i];
                } else{
                    while(fila.acessar() > array[i]) fila.inserir(fila.retirar());
                    fila.inserir(array[i]);
                    while(fila.acessar() < array[i]) fila.inserir(fila.retirar());
                }
            }
        }

        for(int i=0; i<quantidadeElementos; i++){
            array[i] = fila.retirar();
        }
    }
}
