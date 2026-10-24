#include "gen/global.h"

int* CScenarioManager::FUN_001ccf50(int x) {
    if (x >= 0 && x < 4)
        return (int*)((int*)((char*)this + x * 0x20 + 0x1418));
    return (int*)(0);
}
