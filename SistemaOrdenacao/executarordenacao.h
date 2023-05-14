#ifndef EXECUTARORDENACAO_H
#define EXECUTARORDENACAO_H

#include <Qstring>
#include <fila.h>
#include <random>
#include <ctime>


namespace ggs{
    class ExecutarOrdenacao
    {
    private:
        int quantidadeElementos;
        int *array;
    public:
        ExecutarOrdenacao(int quantidadeElementos);
        ~ExecutarOrdenacao();

        QString imprimirVetor()const;
        void ordenarCrescente();
        void ordenarDecrescente();
    };
}
#endif // EXECUTARORDENACAO_H
