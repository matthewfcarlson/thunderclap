// STATUS: equivalent (tools/equiv.py level 3: 72 inputs, branch coverage 15/16, incomplete)
// hulkfight::motion::ShoreNearCondition::vfunc_6 @ 0x00166e30
struct V3 {
    float x, y, z;
    float FUN_000111f0();
};

struct Fighter {
    char pad0[0x1a39];
    char flag1a39;
    char pad1a3a[2];
    V3 shorePos;
};

struct Holder {
    Fighter *FUN_00059a30();
    void FUN_00059a50(V3 *out);
};

struct Checker {
    bool FUN_00204350(float x, float y, float z);
};

struct Mgr54 {
    Checker *FUN_000862a0();
};

struct Nav28 {
    bool FUN_001fe380(V3 *from, V3 *out);
};

struct Game {
    char pad0[0x28];
    Nav28 *nav;
    char pad2c[0x54 - 0x2c];
    Mgr54 *mgr;
};

extern Game *DAT_004dd700;
extern unsigned DAT_004e12d4;
extern float DAT_004e12d0;

namespace fight {
class Params {
  public:
    virtual void v0();
    virtual void v1();
    Holder *FUN_000592a0();
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

    Holder *holder = params->FUN_000592a0();
    Fighter *fighter = holder->FUN_00059a30();
    if (fighter->flag1a39)
        return flag;

    V3 pos;
    V3 d;
    V3 out;
    pos.x = 0.0f;
    pos.y = 0.0f;
    pos.z = 0.0f;
    holder->FUN_00059a50(&pos);

    Game *game = DAT_004dd700;
    if (game->mgr->FUN_000862a0()->FUN_00204350(pos.x, pos.y, pos.z))
        return flag;

    V3 *shore = &fighter->shorePos;
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
