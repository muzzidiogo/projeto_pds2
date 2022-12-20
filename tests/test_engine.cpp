#include <vector>
#include "../third_party/doctest.h"
#include "../include/engine.hpp"
#include "../include/tabuleiro.hpp"

TEST_CASE("Teste Tabuleiro Inicial") {
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    Engine engine;
    PecaPorCapturas_t *pTest = engine.get_maior(tabuleiro, Cores::BRANCO);
    Peca_t pecaFinal = tabuleiro.get_tabuleiro()[tabuleiro.get_tabuleiro().size()-1];
    CHECK_EQ(pecaFinal, pTest->peca);
    CHECK_EQ(0, pTest->posRemover->size());
    delete pTest;
}

TEST_CASE("Teste Sem Captura") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::PRETO,Posicao_t{1,1}), 
                                         Peca_t(Cores::BRANCO,Posicao_t{1,5})};
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    PecaPorCapturas_t *pTest = engine.get_maior(tabuleiro, Cores::BRANCO);
    Peca_t pecaFinal = tabuleiro.get_tabuleiro()[1];
    CHECK_EQ(pecaFinal, pTest->peca);
    CHECK_EQ(0, pTest->posRemover->size());
    delete pTest;
}

TEST_CASE("Teste Captura 1") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::BRANCO,Posicao_t{1,1}),
                                         Peca_t(Cores::PRETO,Posicao_t{2,2}) };
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    PecaPorCapturas_t *pTest = engine.get_maior(tabuleiro, Cores::BRANCO);
    CHECK_EQ(tabuleiro.get_tabuleiro()[0], pTest->peca);
    CHECK_EQ(1, pTest->posRemover->size());
    CHECK_EQ(3, pTest->posRemover->at(0).coluna);
    CHECK_EQ(3, pTest->posRemover->at(0).linha);
    delete pTest;
}

/*TEST_CASE("Teste Captura 2") {
    std::vector<Peca_t> NovoTabuleiro = {Peca_t(Cores::BRANCO,Posicao_t{5,5}),
                                         Peca_t(Cores::PRETO,Posicao_t{4,4}),
                                         Peca_t(Cores::PRETO,Posicao_t{2,4}) };
    Tabuleiro_t tabuleiro = Tabuleiro_t();
    tabuleiro.set_tabuleiro_testes(NovoTabuleiro);
    Engine engine;
    PecaPorCapturas_t *pTest = engine.get_maior(tabuleiro, Cores::BRANCO);
    CHECK_EQ(tabuleiro.get_tabuleiro()[0], pTest->peca);
    CHECK_EQ(2, pTest->posRemover->size());
    CHECK_EQ(4, pTest->posRemover->at(0).coluna);
    CHECK_EQ(4, pTest->posRemover->at(0).linha);
    CHECK_EQ(2, pTest->posRemover->at(1).coluna);
    CHECK_EQ(4, pTest->posRemover->at(1).linha);
    delete pTest;
}
*/