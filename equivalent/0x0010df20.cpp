// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 8/8)
// hulkfight::ai::TokenSupressAction::vfunc_4 @ 0x0010df20
struct Ctx {
    void *FUN_00059a30();
};

class Owner {
public:
    Ctx *FUN_000592a0();
};

struct Player {
    char pad0[0x368];
    int f368;
    void FUN_00065aa0();
};

struct Tracker {
    char pad0[0x18];
    float f18;
    char b1c;
    char b1d;
};

Player *FUN_000678d0();

class TokenSupressAction {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void vfunc_4();
    virtual void v5();
    char pad4[0x18];
    Tracker *f1c;
    Owner *f20;
    int f24;
};

void TokenSupressAction::vfunc_4()
{
    if (f20 != 0) {
        f20->FUN_000592a0()->FUN_00059a30();
        if (f1c->f18 >= 0.0f && f1c->b1c == 0) {
            int v = f24;
            FUN_000678d0()->f368 = v;
        }
        if (f1c->b1d != 0) {
            FUN_000678d0()->FUN_00065aa0();
        }
    }
}
