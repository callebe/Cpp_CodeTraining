#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "avaliador.hpp"

TEST_CASE( "Verificar se Leilao Basico Funciona") {

    // Arrange - Given
    Leilao leilao(
        "Fiat 147 - Novinho"
    );
    Lance primeiroLance(
        Usuario("Callebe"),
        1000
    );
    Lance segundoLance(
        Usuario("Raquell"),
        1500
    );

    // Act - When
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    avaliador leiloeiro;
    leiloeiro.avalia(leilao);
    float lanceVencedor = leiloeiro.getUltimoLance();

    // Assert - Then
    REQUIRE( 1500 == lanceVencedor );
}

TEST_CASE( "Verificar se Leilao Invertido Funciona") {

    // Arrange - Given
    Leilao leilao(
        "Fiat 147 - Novinho"
    );
    Lance primeiroLance(
        Usuario("Callebe"),
        1000
    );
    Lance segundoLance(
        Usuario("Raquell"),
        1500
    );

    // Act - When
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(primeiroLance);
    avaliador leiloeiro;
    leiloeiro.avalia(leilao);
    float lanceVencedor = leiloeiro.getUltimoLance();

    // Assert - Then
    REQUIRE( 1500 == lanceVencedor );
}

TEST_CASE( "Verificar se o menor valor do Leilao Basico Funciona") {

    // Arrange - Given
    Leilao leilao(
        "Fiat 147 - Novinho"
    );
    Lance primeiroLance(
        Usuario("Callebe"),
        1000
    );
    Lance segundoLance(
        Usuario("Raquell"),
        1500
    );

    // Act - When
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    avaliador leiloeiro;
    leiloeiro.avalia(leilao);
    float lanceVencedor = leiloeiro.getMenorLance();

    // Assert - Then
    REQUIRE( 1000 == lanceVencedor );
}

TEST_CASE( "Verificar se o menor valor do Leilao Invertido Funciona") {

    // Arrange - Given
    Leilao leilao(
        "Fiat 147 - Novinho"
    );
    Lance primeiroLance(
        Usuario("Callebe"),
        1000
    );
    Lance segundoLance(
        Usuario("Raquell"),
        1500
    );

    // Act - When
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(primeiroLance);
    avaliador leiloeiro;
    leiloeiro.avalia(leilao);
    float menorLance = leiloeiro.getMenorLance();

    // Assert - Then
    REQUIRE( 1000 == menorLance );
}

TEST_CASE( "Verificar se a lista dos ultimos lances do Leilao Basico Funciona") {

    // Arrange - Given
    Leilao leilao(
        "Fiat 147 - Novinho"
    );
    Lance primeiroLance(
        Usuario("Callebe"),
        1000
    );
    Lance segundoLance(
        Usuario("Raquell"),
        1500
    );
    Lance terceiroLance(
        Usuario("Victor"),
        2000
    );
    Lance quartoLance(
        Usuario("Leandro"),
        2500
    );

    // Act - When
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    leilao.recebeLance(terceiroLance);
    leilao.recebeLance(quartoLance);
    avaliador leiloeiro;
    leiloeiro.avalia(leilao);
    float lanceVencedor = leiloeiro.getUltimoLance();
    std::vector<Lance> listaUltimosLances = leiloeiro.getUltimosLances();

    // Assert - Then
    REQUIRE( 2500 == lanceVencedor );
    REQUIRE( BACKUP_AUCTION_LIST_SIZE == listaUltimosLances.size() );
}