#include "controllermanager.h"

ControllerManager::ControllerManager()
{
    mPosX = 0;
    mPosY = 0;
}

ControllerManager::~ControllerManager()
{

}

void ControllerManager::setPosX_Y(int pPosX, int pPosY)
{
    mPosX = pPosX;
    mPosY = pPosY;
    emit newPosX_Y(mPosX, mPosY);
}


