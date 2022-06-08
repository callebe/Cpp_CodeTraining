#include "avaliador.hpp"
#include <algorithm>

void avaliador::avalia(Leilao leilao)
{
    std::vector<Lance> lances = leilao.recuperaLances();
    
    // Verifica se lances é o meior ou o menor ate o momento
    for (Lance lance : lances)
    {
        if(lance.recuperaValor() > this->maiorValor){
            this->maiorValor = lance.recuperaValor();
        }
        if(lance.recuperaValor() < this->menorValor){
            this->menorValor = lance.recuperaValor();
        }
    }

    // Armazena BACKUP_AUCTION_LIST_SIZE ultimos lances
    std::sort(lances.begin(), lances.end(), verificaOrdemLances);
    size_t tamanho = lances.size() > BACKUP_AUCTION_LIST_SIZE ? BACKUP_AUCTION_LIST_SIZE : lances.size();
    this->ultimosLances = std::vector<Lance>(lances.begin(),lances.begin()+tamanho);
}

float avaliador::getUltimoLance() const
{
    return this->maiorValor;
}

float avaliador::getMenorLance() const
{
    return this->menorValor;
}

std::vector<Lance> avaliador::getUltimosLances() const
{
    return this->ultimosLances;
}

bool avaliador::verificaOrdemLances(Lance Lance1, Lance Lance2)
{
    if(Lance1.recuperaValor()<Lance2.recuperaValor())
        return true;
    else
        return false;
    
}
