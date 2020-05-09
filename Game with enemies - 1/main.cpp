#include "mainController.h"

int main(int argc, char** argv)
{
    MainController mainController(argc, argv);

    return 0;
}

/*
    Atualização:
        Classe Phase1 e Phase2 excluidas, a phaseManager está fazendo o papel delas
        phaseManager é uma "singleton class"
        Opção de selecionamento de fase implementada junto com a seleção de 1 ou 2 jogadores
        Limitação de caracteres para a nomeação do personagem
*/