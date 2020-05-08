#include "save.h"

#include "player.h"
#include "openMenu.h"

Save* Save::s_instance = NULL;

Save::Save()
{

}

Save::~Save()
{
}

Save* Save::getInstance()
{
    if (!s_instance)
        s_instance = new Save;
    return s_instance;
}

void Save::Save_save()
{
    ofstream io("save.json", ios::binary | ios::out | ios::trunc);
    io.exceptions(ios::badbit);
    json j;
    cout << "Didnt open" << endl;

    bool isMultiplayer = Player::getInstance()->getIsMultiplayer();

    try
    {
        // if is true, then is multiplayer
        if (isMultiplayer)
        {
            cout << "Vai salvar" << endl;
            j = 
            {
                {"player",
                {
                    {"multiplayer", isMultiplayer},
                    {"player1_name", Player::getInstance()->getPlayer1Name()},
                    {"player2_name", Player::getInstance()->getPlayer2Name()},
                    {"pos_x_player1", Player::getInstance()->getPlayer1Position().x},
                    {"pos_y_player1", Player::getInstance()->getPlayer1Position().y},
                    {"pos_x_player2", Player::getInstance()->getPlayer2Position().x},
                    {"pos_y_player2", Player::getInstance()->getPlayer2Position().y}
                    //{"healthPoints", healthPoints},
                    //{"score", Score}
                },
                }
            };
        }
        else
        {
            j = 
            {
                {"player",
                {
                    {"multiplayer", isMultiplayer},
                    {"player1_name", Player::getInstance()->getPlayer1Name()},
                    {"pos_x_player1", Player::getInstance()->getPlayer1Position().x},
                    {"pos_y_player1", Player::getInstance()->getPlayer1Position().y},
                    //{"player1_name", namePlayer1}
                    //{"healthPoints", healthPoints},
                    //{"score", Score}
                },
                }
            };
        }
        io << j;
    }
    catch(ofstream::failure e)
    {
        std::cerr << "Error opening save.json" << std::endl;
        std::cerr << e.what() << '\n';
    }
    
    io.close();
}