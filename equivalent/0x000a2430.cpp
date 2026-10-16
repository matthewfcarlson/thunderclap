// STATUS: equivalent (tools/equiv.py level 3: 3001 inputs, branch coverage 8/8)
// FUN_000a2430 @ 0x000a2430
#include "decls/address.h"
#include "decls/data/game/global.h"
struct ResourceName_a2430 {
    int word;
    void FUN_0027b040(const char *name);
};

class __declspec(novtable) CCameraBase_a2430 {
public:
    virtual void v0();
    char pad04[4];
    ResourceName_a2430 name;
    char pad0c[0xd0 - 0xc];
    int mode;
    float f0d4;
    char padd8[0x170 - 0xd8];
    CCameraBase_a2430 *FUN_000a9400();
    CCameraBase_a2430() { FUN_000a9400(); }
};


struct Sub248 {
    char pad[0xd8];
    void FUN_000a06d0(const void *p);
};

struct Stage_a2430 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Level_a2430 {
    char pad[0x80];
    Stage_a2430 stage;
};

struct Window_a2430 {
    Level_a2430 *FUN_00086310();
};

struct World {
    char pad[0x54];
    Window_a2430 *window;
};


class CChaseCamera : public CCameraBase_a2430 {
public:
    virtual void v0();
    int f170;
    int f174;
    int f178;
    int f17c;
    int f180;
    int f184;
    int f188;
    int f18c;
    int f190;
    int f194;
    int f198;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int f1b4;
    int f1b8;
    int f1bc;
    int f1c0;
    int f1c4;
    int f1c8;
    int f1cc;
    int f1d0;
    int f1d4;
    int f1d8;
    int f1dc;
    int f1e0;
    int f1e4;
    int f1e8;
    int f1ec;
    int f1f0;
    int f1f4;
    int f1f8;
    int f1fc;
    int f200;
    int f204;
    int f208;
    int f20c;
    int f210;
    int f214;
    int f218;
    int f21c;
    int f220;
    int f224;
    int f228;
    int f22c;
    int f230;
    char pad234[0x4];
    int f238;
    int f23c;
    float f240;
    unsigned char f244;
    unsigned char f245;
    char pad246[0x2];
    Sub248 sub248;
    int f320;
    int f324;
    int f328;
    int f32c;
    int f330;
    int f334;
    int f338;
    int f33c;
    unsigned char f340;
    char pad341[0x3];
    unsigned char f344;
    unsigned char f345;
    unsigned char f346;
    unsigned char f347;
    unsigned char f348;
    unsigned char f349;
    char pad34a[0x2];
    int f34c;
    int f350;
    unsigned char f354;
    char pad355[0x3f];
    int f394;
    char pad398[0x1c];
    int f3b4;
    int f3b8;
    int f3bc;
    int f3c0;
    float f3c4;
    float f3c8;
    float f3cc;
    char pad3d0[0x3c];
    int f40c;
    int f410;
    int f414;
    char pad418[0xc];
    int f424;
    int f428;
    int f42c;
    int f430;
    int f434;
    int f438;
    int f43c;
    float f440;
    float f444;
    int f448;
    float f44c;
    int f450;
    float f454;
    int f458;
    char pad45c[0x1c];
    int f478;
    int f47c;
    float f480;
    int f484;
    int f488;
    char pad48c[0x4];
    unsigned char f490;
    char pad491[0x7];
    float f498;
    float f49c;
    int f4a0;
    int f4a4;
    int f4a8;
    int f4ac;
    int f4b0;
    int f4b4;
    unsigned char f4b8;
    unsigned char f4b9;
    unsigned char f4ba;
    unsigned char f4bb;
    CChaseCamera();
    void FUN_000a0fe0(float v);
};

CChaseCamera::CChaseCamera()
{
    f320 = 0;
    f324 = 0;
    f328 = 0;
    f32c = 0;
    f330 = 0;
    f338 = 0;
    f334 = 0;
    f33c = 0;
    f340 = 0;
    f344 = 0;
    f345 = 0;
    f346 = 0;
    f347 = 0;
    f348 = 0;
    f349 = 0;
    f34c = 0;
    f350 = 0;
    f394 = 0;
    f3b4 = 0;
    f3b8 = 0;
    f3bc = 0;
    f3c0 = 0;
    f40c = 0;
    f410 = 0;
    f414 = 0;
    f43c = 0;
    f448 = 0;
    f478 = 0;
    f47c = 0;
    f484 = 0;
    f488 = 0;
    f490 = 0;
    f498 = 3.4028235e+38f;
    f49c = -3.4028235e+38f;
    f3c8 = 50.0f;
    f3cc = 50.0f;
    f44c = (*(float*)&DAT_0049ec58);
    f3c4 = 10.0f;
    f440 = 10.0f;
    f444 = 10.0f;
    f480 = 10.0f;
    f4a0 = 0;
    f4a4 = 0;
    f4a8 = 0;
    f4ac = 0;
    f4b0 = 0;
    f4b4 = 0;
    f4b8 = 0;
    f4b9 = 0;
    f4ba = 0;
    f4bb = 0;
    f19c = 0;
    f198 = 0;
    f194 = 0;
    f178 = 0;
    f174 = 0;
    f170 = 0;
    f184 = 0;
    f180 = 0;
    f17c = 0;
    f190 = 0;
    f18c = 0;
    f188 = 0;
    f1a8 = 0;
    f1a4 = 0;
    f1a0 = 0;
    f1b4 = 0;
    f1b0 = 0;
    f1ac = 0;
    f1c0 = 0;
    f1bc = 0;
    f1b8 = 0;
    f1cc = 0;
    f1c8 = 0;
    f1c4 = 0;
    f1d8 = 0;
    f1d4 = 0;
    f1d0 = 0;
    f1e4 = 0;
    f1e0 = 0;
    f1dc = 0;
    f1f0 = 0;
    f1ec = 0;
    f1e8 = 0;
    f208 = 0;
    f204 = 0;
    f200 = 0;
    f1fc = 0;
    f1f8 = 0;
    f1f4 = 0;
    f20c = 0;
    f210 = 0;
    f218 = 0;
    f214 = 0;
    f220 = 0;
    f21c = 0;
    f228 = 0;
    f224 = 0;
    f230 = 0;
    f22c = 0;
    f238 = 0;
    f23c = 0;
    f240 = f444;
    f244 = 0;
    f245 = 0;
    sub248.FUN_000a06d0(&f170);
    f454 = f0d4;
    f450 = 0;
    FUN_000a0fe0(f0d4);
    f458 = 0;
    f354 = 0;
    mode = 0;
    name.FUN_0027b040((*(const char**)&DAT_0049ec40));
    f424 = 0;
    f428 = 0;
    f42c = 0;
    f430 = 0;
    f434 = 0;
    f438 = 0;
    World *g = DAT_004dd700;
    if (g != 0) {
        Level_a2430 *lv = g->window->FUN_00086310();
        if (lv != 0) {
            Stage_a2430 *st = &lv->stage;
            if (st->FUN_00088fa0() == 10) {
                if (st->FUN_00088fb0() == 0x2a)
                    f44c = 20.0f;
            }
        }
    }
}
