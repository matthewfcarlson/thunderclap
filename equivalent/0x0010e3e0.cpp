// STATUS: equivalent (tools/equiv.py level 3: 125 inputs, branch coverage 30/30)
// hulkfight::ai::InActiveCondition::vfunc_6 @ 0x0010e3e0
#include "decls/address.h"
class fight_Params_10e3e0 {
public:
    virtual void vfunc_0();
};

class CFightParams : public fight_Params_10e3e0 {
public:
    virtual void vfunc_0();
};

struct StateInfo_10e3e0 {
    int FUN_00088fa0();
    int FUN_00088fb0();
};

struct Anim_10e3e0 {
    char pad0[0x80];
    StateInfo_10e3e0 state;
};

struct Holder_10e3e0 {
    Anim_10e3e0 *FUN_00086310();
};

struct World {
    char pad0[0x54];
    Holder_10e3e0 *holder;
};

struct Context { char pad[4]; };
Context *__fastcall FUN_000592a0(void *obj);

struct Fighter_10e3e0 {
    char pad0[0x1ba4];
    char flag1ba4;
    char pad1ba5[0x1cee - 0x1ba5];
    unsigned char level;
    char pad1cef[0x1d40 - 0x1cef];
    char flag1d40;
};
Fighter_10e3e0 *__fastcall FUN_00059a30(Context *ctx);

struct Clock_10e3e0 {
    char pad0[0x2b0];
    int now;
    char pad2b4[0x2d0 - 0x2b4];
    int limit;
};
Clock_10e3e0 *__cdecl FUN_000678d0();

class InActiveCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, fight_Params_10e3e0 *params, int c);
    char pad04[0xc];
    char invert;
};

char InActiveCondition::vfunc_6(int a, fight_Params_10e3e0 *params, int c)
{
    if (dynamic_cast<CFightParams *>(params) == 0)
        return 0;
    Fighter_10e3e0 *f = FUN_00059a30(FUN_000592a0(params));
    if (f == 0)
        return 0;

    int kind = -1;
    int sub = -1;
    Anim_10e3e0 *anim = DAT_004dd700->holder->FUN_00086310();
    if (anim) {
        kind = anim->state.FUN_00088fa0();
        sub = anim->state.FUN_00088fb0();
    }

    if (invert) {
        if (kind == 7 && sub == 2)
            return 1;
        if ((float)f->level == 0.0f)
            return 1;
        if (f->flag1d40)
            return 1;
        int now = FUN_000678d0()->now;
        if (now < FUN_000678d0()->limit)
            return 1;
        return f->flag1ba4;
    }
    if (kind == 7 && sub == 2)
        return 0;
    if ((float)f->level == 0.0f)
        return 0;
    if (f->flag1d40)
        return 0;
    int now = FUN_000678d0()->now;
    if (now < FUN_000678d0()->limit)
        return 0;
    return f->flag1ba4 == 0;
}
