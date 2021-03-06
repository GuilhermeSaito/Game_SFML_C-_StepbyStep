#include "save.h"

#include "player.h"
#include "phaseManager.h"

Save* Save::s_instance = NULL;

Save::Save()
{

}

Save::~Save()
{
    delete s_instance;
}

Save* Save::getInstance()
{
    if (!s_instance)
        s_instance = new Save;
    return s_instance;
}

void Save::Save_save()
{
    ofstream out("save.json", ios::out | ios::trunc);
    out.exceptions(ios::badbit);
    json j;

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
                    {"phase1", PhaseManager::getInstance()->getIsPhase1()},
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
                    {"phase1", PhaseManager::getInstance()->getIsPhase1()},
                    {"multiplayer", isMultiplayer},
                    {"player1_name", Player::getInstance()->getPlayer1Name()},
                    {"pos_x_player1", Player::getInstance()->getPlayer1Position().x},
                    {"pos_y_player1", Player::getInstance()->getPlayer1Position().y},
                    //{"healthPoints", healthPoints},
                    //{"score", Score}
                },
                }
            };
        }
        out << j;
    }
    catch(ofstream::failure e)
    {
        std::cerr << "Error opening save.json" << std::endl;
        std::cerr << e.what() << '\n';
    }
    
    out.close();
}

bool Save::Recover_save()
{
    ifstream in("save.json");

    // Test if the file exist
    if (!in.good())
        throw "Save does not exist";

    // Test if the file is empty
    in.seekg(0, ios::end);
    if(!in.tellg()) {
        throw "Save is empty";
    }
    in.seekg(0, ios::beg);

    json j;

    try {
        in >> j;
    }
    catch(ifstream::failure& e) {
        std::cerr << "Error in read the save" << std::endl;
        std::cerr << e.what() << std::endl;
        in.close();
        return false;
    }

    sf::Vector2f player1Position;
    player1Position.x = j["player"]["pos_x_player1"];
    player1Position.y = j["player"]["pos_y_player1"];

    PhaseManager::getInstance()->setIsPhase1(j["player"]["phase1"]);

    bool multiplayer = j["player"]["multiplayer"];
    Player::getInstance()->setIsMultiplayer(multiplayer);
    if (multiplayer)
    {
        sf::Vector2f player2Position;
        player2Position.x = j["player"]["pos_x_player2"];
        player2Position.y = j["player"]["pos_y_player2"];

        Player::getInstance()->setPlayer1Name(j["player"]["player1_name"]);
        Player::getInstance()->setPlayer2Name(j["player"]["player2_name"]);
        Player::getInstance()->setPlayer1Position(player1Position);
        Player::getInstance()->setPlayer2Position(player2Position);
    }
    else
    {
        Player::getInstance()->setPlayer1Name(j["player"]["player1_name"]);
        Player::getInstance()->setPlayer1Position(player1Position);
    }

    in.close();
    
    return true;
}