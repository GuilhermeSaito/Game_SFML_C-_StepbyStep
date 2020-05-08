#include "mainController.h"

int main(int argc, char** argv)
{
    MainController mainController(argc, argv);

    return 0;
}

/*
    Atualização:
        Criação do "save.cpp" e "save.h"    <-- classe responsável para o save
        Mais ou menos, todos os dados que, futuramente vão ser salvos no arquivo, estão escritos na "save.h"
        Os dados da posição do(s) personagen(s) e do(s) nome(s) estão, temporariamente, armazenados na classe "player"
        Adicionei uma opção para caso aperte o ESC em qualquer uma das 2 fases
*/