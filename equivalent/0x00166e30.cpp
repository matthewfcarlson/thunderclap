// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::ShoreNearCondition::vfunc_6 @ 0x00166e30
#include "decls/address.h"
struct V3_166e30 {
    float x, y, z;
    float FUN_000111f0();
};

struct Fighter_166e30 {
    char pad0[0x1a39];
    char flag1a39;
    char pad1a3a[2];
    V3_166e30 shorePos;
};

struct Holder_166e30 {
    Fighter_166e30 *FUN_00059a30();
    void FUN_00059a50(V3_166e30 *out);
};

struct Checker_166e30 {
    bool FUN_00204350(float x, float y, float z);
};

struct Mgr54_166e30 {
    Checker_166e30 *FUN_000862a0();
};

struct Nav28 {
    bool FUN_001fe380(V3_166e30 *from, V3_166e30 *out);
};

struct World {
    char pad0[0x28];
    Nav28 *nav;
    char pad2c[0x54 - 0x2c];
    Mgr54_166e30 *mgr;
};

extern unsigned DAT_004e12d4;
extern float DAT_004e12d0;

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
    Holder_166e30 *FUN_000592a0();
};
}

class CFightParams : public fight::Params {
  public:
    virtual void v2();
};

class ShoreNearCondition {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual char FUN_00166e30(int a1, fight::Params *params, int a3);
    char pad4[8];
    char flag;
};

char ShoreNearCondition::FUN_00166e30(int a1, fight::Params *params, int a3)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return false;

    Holder_166e30 *holder = params->FUN_000592a0();
    Fighter_166e30 *fighter = holder->FUN_00059a30();
    if (fighter->flag1a39)
        return flag;

    V3_166e30 pos;
    V3_166e30 d;
    V3_166e30 out;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    holder->FUN_00059a50(&pos);

    World *game = DAT_004dd700;
    if (game->mgr->FUN_000862a0()->FUN_00204350(pos.x, pos.y, pos.z))
        return flag;

    V3_166e30 *shore = &fighter->shorePos;
    d.x = shore->x;
    d.y = shore->y;
    d.z = shore->z;
    float dist2 = (d.z - pos.z) * (d.z - pos.z) + (d.x - pos.x) * (d.x - pos.x);
    d.y = 0.0f;
    if ((DAT_004e12d4 & 1) == 0) {
        DAT_004e12d4 |= 1;
        DAT_004e12d0 = 3600.0f;
    }
    if (dist2 < DAT_004e12d0)
        return flag;

    out.x = 0.0f;
    out.y = 0.0f;
    out.z = 0.0f;
    if (game->nav->FUN_001fe380(&pos, &out)) {
        d.x = out.x - pos.x;
        d.y = 0.0f;
        d.z = out.z - pos.z;
        if (d.FUN_000111f0() < DAT_004e12d0)
            return flag;
    }
    return flag == 0;
}
