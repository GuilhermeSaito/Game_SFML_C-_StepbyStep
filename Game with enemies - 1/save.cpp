#include "save.h"

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

