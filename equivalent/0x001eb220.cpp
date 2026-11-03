// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001eb220 @ 0x001eb220
#include "decls/data/game/global.h"
#include "gen/owners.h"

struct Resource_1eb220 {
    void* FUN_001f1270();
};
extern "C" Resource_1eb220* __cdecl FUN_0008d710(int size, int category);
owners::State_1eb220* owners::State_1eb220::FUN_001eb220(hulk_uintptr ownerValue, hulk_uintptr unused, unsigned char modeValue) {
    mode = modeValue;
    (*(owners::State_1eb220**)&DAT_004e36d8) = this;
    active = 0;
    first = 100.0f;
    third = 100.0f;
    second = 100.0f;
    count = 1;
    Resource_1eb220* allocated = FUN_0008d710(20, 6);
    void* result = 0;
    if (allocated)
        result = allocated->FUN_001f1270();
    resource = result;
    owner = ((unsigned int)ownerValue);
    return this;
}
