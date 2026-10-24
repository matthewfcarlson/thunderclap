#include "gen/global.h"

void CControllerManager::FUN_000ae9d0(int index, char value) {
    if (index >= 0 && index < 15)
        (*(char (*)[15])&this->f_0c)[index] = value;
}
