#include "mainController.h"

int main(int argc, char** argv)
{
    MainController::getInstance()->Initialize();

    return 0;
}

/*
    Atualização:
        Habilitação da opção de "Continuar Jogo"
        Feito o método de "recuperar dados, da classe save"
*/