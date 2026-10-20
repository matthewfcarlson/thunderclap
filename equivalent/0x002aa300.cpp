// STATUS: equivalent (tools/equiv.py level 3: 168 inputs, branch coverage 26/26)
// FUN_002aa300 @ 0x002aa300
#include "gen/pure3d.h"
void *FUN_0008d690(unsigned int size);

typedef void (*Callback_2aa300)();

void FUN_002d12c0();
void FUN_002d12d0();
void FUN_002d12e0();
void FUN_002d12f0();
void FUN_002d1310();
void FUN_002d1330();
void FUN_002d1370();
void FUN_002d1390();
void FUN_002d1410();
void FUN_002d1490();
void FUN_002d1540();
void FUN_002d15f0();
void FUN_002d1620();
void FUN_002d1650();
void FUN_002d1670();
void FUN_002d1680();
void FUN_002d16d0();
void FUN_002d16e0();
void FUN_002d1730();
void FUN_002d1740();
void FUN_002d17a0();
void FUN_002d18b0();
void FUN_002d1970();
void FUN_002d1a00();
void FUN_002d1b00();
void FUN_002d1bc0();
void FUN_002d1cc0();

struct SpriteParticleUpdater_nv_2aa300 {
    pure3d::SpriteParticleUpdater *FUN_002d11f0();
    void FUN_002d1240(Callback_2aa300 a, Callback_2aa300 b);
    void FUN_002d1260(Callback_2aa300 a, Callback_2aa300 b);
    void FUN_002d1280(Callback_2aa300 a, Callback_2aa300 b);
    void FUN_002d12a0(Callback_2aa300 a, Callback_2aa300 b);
};

pure3d::SpriteParticleUpdater *FUN_002aa300(unsigned int kind, unsigned int mode, unsigned int format, float a4, float a5)
{
    pure3d::SpriteParticleUpdater *e = 0;
    void *mem = FUN_0008d690(0x28);
    if (mem)
        e = ((SpriteParticleUpdater_nv_2aa300*)(((pure3d::SpriteParticleUpdater *)mem)))->FUN_002d11f0();

    if (a4 > 0.0f) {
        if (a5 > 0.0f)
            ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d12a0(FUN_002d1cc0, FUN_002d1bc0);
        else
            ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d12a0(FUN_002d1970, FUN_002d18b0);
    } else {
        if (a5 > 0.0f)
            ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d12a0(FUN_002d1b00, FUN_002d1a00);
        else
            ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d12a0(FUN_002d12e0, FUN_002d12c0);
    }

    if (format == 0x424752)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1280(FUN_002d16d0, FUN_002d1680);
    else if (format == 0x41)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1280(FUN_002d1730, FUN_002d16e0);
    else if (format == 0x41424752)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1280(FUN_002d17a0, FUN_002d1740);
    else
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d12a0(FUN_002d12e0, FUN_002d12c0);

    if (mode == 0x4e494c)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1260(FUN_002d1620, FUN_002d15f0);
    else if (mode == 0x444e4152)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1260(FUN_002d1540, FUN_002d1490);
    else if (mode == 0x43455053)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1260(FUN_002d1670, FUN_002d1650);
    else
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1260(FUN_002d12e0, FUN_002d12d0);

    if (kind == 0x43455053)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1240(FUN_002d1370, FUN_002d1330);
    else if (kind == 0x4c414f4d)
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1240(FUN_002d1410, FUN_002d1390);
    else
        ((SpriteParticleUpdater_nv_2aa300*)(e))->FUN_002d1240(FUN_002d1310, FUN_002d12f0);
    return e;
}
