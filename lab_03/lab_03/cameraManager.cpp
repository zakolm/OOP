#include "cameraManager.h"

void cCameraManager::yaw(double y, camIterator iter)
{
    if (!*iter)
        throw cManagerNoTarget();

    (*iter)->yaw(y);
}

void cCameraManager::pitch(double p, camIterator iter)
{
    if (!*iter)
        throw cManagerNoTarget();

    (*iter)->pitch(p);
}

void cCameraManager::roll(double r, camIterator iter)
{
    if (!*iter)
        throw cManagerNoTarget();

    (*iter)->roll(r);
}
