// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ef2a0 @ 0x001ef2a0
#include "decls/data/game/unknown.h"

struct Rng;
Rng* FUN_000964d0();

class Spawner_1ef2a0 {
public:
    char pad0[0x14];
    int count;          // 0x14
    void FUN_001ef2a0(int a, int b);
};

class Pool_1ef2a0 {
public:
    class Emitter_1ef2a0* FUN_001eefc0();
};

class Emitter_1ef2a0 {
public:
    void FUN_001eed50(Spawner_1ef2a0* owner, int a, int b, int flags);
};

       // function-local static
   // its init guard

void Spawner_1ef2a0::FUN_001ef2a0(int a, int b)
{
    DAT_004e3740++;
    if (count < 1)
        return;
    if ((DAT_004e375c & 1) == 0) {
        DAT_004e375c |= 1;
        (*(Rng**)&DAT_004e3758) = FUN_000964d0();
    }
    Emitter_1ef2a0* e = (*(Pool_1ef2a0**)&DAT_004e370c)->FUN_001eefc0();
    if (e == 0) {
        DAT_004e3718++;
        return;
    }
    DAT_004e3744++;
    e->FUN_001eed50(this, a, b, 0);
}
