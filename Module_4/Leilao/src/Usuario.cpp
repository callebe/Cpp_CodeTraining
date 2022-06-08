#include "Usuario.hpp"

Usuario::Usuario(std::string nome): nome(nome)
{
}

std::string Usuario::recuperaNome() const
{
    return nome;
}
