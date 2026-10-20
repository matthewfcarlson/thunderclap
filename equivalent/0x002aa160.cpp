// STATUS: equivalent (tools/equiv.py level 3: 20036 inputs, branch coverage 22/26, incomplete)
// FUN_002aa160 @ 0x002aa160
#include "gen/pure3d.h"
typedef void (*Code)();
void FUN_002d12f0();
void FUN_002d1310();
void FUN_002d1330();
void FUN_002d1370();
void FUN_002d1390();
void FUN_002d1410();
void FUN_002d12d0();
void FUN_002d12e0();
void FUN_002d15f0();
void FUN_002d1620();
void FUN_002d1650();
void FUN_002d1670();
void FUN_002d1490();
void FUN_002d1540();
void FUN_002d1680();
void FUN_002d16d0();
void FUN_002d16e0();
void FUN_002d1730();
void FUN_002d1740();
void FUN_002d17a0();
void FUN_002d17b0();
void FUN_002d1850();
void FUN_002d18b0();
void FUN_002d1970();
void FUN_002d1a00();
void FUN_002d1b00();
void FUN_002d1bc0();
void FUN_002d1cc0();

void* __cdecl FUN_0008d690(unsigned int size);

struct SpriteParticleUpdater_nv_2aa160 {
    pure3d::SpriteParticleUpdater* FUN_002d11f0();
    void FUN_002d1240(Code a, Code b);
    void FUN_002d1260(Code a, Code b);
    void FUN_002d1280(Code a, Code b);
    void FUN_002d12a0(Code a, Code b);
};

pure3d::SpriteParticleUpdater* __cdecl FUN_002aa160(unsigned int n)
{
    unsigned int code = n / 3;
    unsigned int kind = n % 3;
    unsigned int s0 = code & 3;
    unsigned int s1 = (code >> 2) & 3;
    unsigned int s2 = (code >> 4) & 3;

    void* mem = FUN_0008d690(0x28);
    pure3d::SpriteParticleUpdater* e = 0;
    if (mem)
        e = ((SpriteParticleUpdater_nv_2aa160*)(((pure3d::SpriteParticleUpdater*)mem)))->FUN_002d11f0();

    switch (kind) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1240(FUN_002d1310, FUN_002d12f0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1240(FUN_002d1370, FUN_002d1330); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1240(FUN_002d1410, FUN_002d1390); break;
    }
    switch (s0) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1260(FUN_002d12e0, FUN_002d12d0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1260(FUN_002d1620, FUN_002d15f0); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1260(FUN_002d1670, FUN_002d1650); break;
    case 3: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1260(FUN_002d1540, FUN_002d1490); break;
    }
    switch (s1) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1280(FUN_002d12e0, FUN_002d12d0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1280(FUN_002d16d0, FUN_002d1680); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1280(FUN_002d1730, FUN_002d16e0); break;
    case 3: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d1280(FUN_002d17a0, FUN_002d1740); break;
    }
    switch (s2) {
    case 0: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d12a0(FUN_002d1850, FUN_002d17b0); break;
    case 1: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d12a0(FUN_002d1970, FUN_002d18b0); break;
    case 2: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d12a0(FUN_002d1b00, FUN_002d1a00); break;
    case 3: ((SpriteParticleUpdater_nv_2aa160*)(e))->FUN_002d12a0(FUN_002d1cc0, FUN_002d1bc0); break;
    }
    return e;
}
