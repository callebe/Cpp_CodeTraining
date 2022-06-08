#ifndef __AVALIADOR_H__
#define __AVALIADOR_H__

#include "Leilao.hpp"

#define BACKUP_AUCTION_LIST_SIZE    3

class avaliador
{
    private:
        float maiorValor = (float) INT_MIN;
        float menorValor = (float) INT_MAX;
        std::vector<Lance> ultimosLances;
        static bool verificaOrdemLances (Lance Lance1, Lance Lance2);

    public:
        void avalia(Leilao);
        float getUltimoLance() const;
        float getMenorLance() const;
        std::vector<Lance> getUltimosLances() const;
};


#endif // __AVALIADOR_H__