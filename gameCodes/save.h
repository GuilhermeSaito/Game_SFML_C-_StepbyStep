/*
SAVE.JSON       <----   Save q vai ter como recuperar o último jogo salvo (N pode ter terminado a 2 fase)

    multiplayer
        0 - false
        1 - true
    Character(s) name
    Character(s) position
    Character(s) life point
    Character score
    // Maybe Character(s) hability

    Enemys position
    Enemys life point
    Witch Enemy is
        1 - 1 tipo
        2 - outro tipo
        3 - outro
        4 - boss

    Witch phase is
----------------------------------------------------------------------------------------------------
RANKING.JSON    <------ Save q vai conter os Ids(ou pode ser o nome) do(s) player(s) com a pontuação

Desing (Ranking window):

CharacterName   Character2Name(if there is)     Total Points earned
*/
#pragma once

#include <fstream>
using std::ofstream;
using std::ifstream;
using std::fstream;
using std::ios;

#include "nlohmann/json.hpp"
using json = nlohmann::json;


#include "openMenu.h"
#include "mainController.h"
#include "player.h"

class Save
{
private:
    Save();
    Save(Save const&);
    static Save* s_instance;

    OpenMenu* openMenu;
    Player1* player1;
    Player2* player2;

public:
    static Save* getInstance();
    ~Save();

    void setOpenMenu(OpenMenu* openM);

    void Save_save();
    bool Recover_save();
};
