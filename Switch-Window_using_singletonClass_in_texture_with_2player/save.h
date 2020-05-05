/*
    Character(s) name
    Character(s) position
    Character(s) life point
    // Maybe Character(s) hability

    Enemys position
    Enemys life point
    Witch Enemy is

    If completed or not

    Total points earned form enemys


Desing:

CharacterName   Character2Name(if there is)     Total Points earned
*/

#pragma once

#include "library.h"
#include <fstream>


using std::ofstream;
using std::ifstream;

class Save
{
private:
    Save();
    Save(Save const&);
    static Save* s_instance;

public:
    static Save* getInstance();
    ~Save();
};