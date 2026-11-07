// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_002642c0 @ 0x002642c0
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

void owners::Controller_2642c0::FUN_002642c0() {
    FUN_002640f0();
    unsigned int next = selected == 0;
    position = 0;
    limit = capacity;
    currentBuffer = ((char*)((char*)&DAT_004e7c28)) + next * 0x20000;
    selected = next;
    FUN_00264050(((char*)((char*)&DAT_004e7c28)) + (next == 0) * 0x20000);
}