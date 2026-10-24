#include "gen/global.h"

void CScenarioManager::FUN_001cc9b0(int i, float v) {
    if (i >= 0 && i < 0x40)
        *(float*)((char*)this + i * 4 + 0x10) = v;
}
