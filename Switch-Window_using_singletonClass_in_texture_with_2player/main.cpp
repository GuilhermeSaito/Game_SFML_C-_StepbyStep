#include "mainController.h"

int main(int argc, char** argv)
{
    MainController mainController(argc, argv);

    return 0;
}

/*
    Atualização:
        Alteração na classe "player"    <- mudei para ser uma "singleton class"
        Criação da classe "player1" e da "player2"
        Criação da classe "entity"      <- q da para ser herdada também para as classes do inimigo
*/