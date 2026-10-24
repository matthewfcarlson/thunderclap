#include "gen/global.h"

void CControllerManager::FUN_000ae9a0(unsigned char v) {
    for (int i = 0; i < 13; i++)
        (*(unsigned char (*)[15])&this->f_0c)[i] = v;
    for (int j = 13; j < 15; j++)
        (*(unsigned char (*)[15])&this->f_0c)[j] = v;
}
