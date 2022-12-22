#ifndef DAMA_HPP
#define DAMA_HPP

#include "peca.hpp"

class Dama : public Peca_t{
public:
    Dama(int cor, Posicao_t posicao);
    bool verifica_movimento(Posicao_t novaPosicao) override;
};

#endif