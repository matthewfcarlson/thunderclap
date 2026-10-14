// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// hulkfight::motion::CivilianAnimationAction::vfunc_3 @ 0x00147f90
// hulkfight::motion::CivilianAnimationAction::vfunc_3
union FlagWord {
    unsigned char b;
    unsigned int w;
};

struct Params {
    int f2c;
    FlagWord flag;
    int f24;
};

struct Source_147f90 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual float v6();
    char pad04[0xc];
    float f10;
    char pad14[4];
    int f18;
    int f1c;
    int f20;
    int f24;
    char b28;
    char pad29[3];
    int f2c;
};

struct Target_147f90 {
    void FUN_000819f0(int a, int b, int c, float d, int e, unsigned int f, int g);
};

struct Player_147f90 {
    Target_147f90 *FUN_00036020();
};

struct Anchor_147f90 {
    Player_147f90 *FUN_00059a30();
};

struct Owner_147f90 {
    Anchor_147f90 *FUN_000592a0();
};

class CivilianAnimationAction {
public:
    char pad00[0x1c];
    Source_147f90 *src;
    Owner_147f90 *owner;

    char FUN_00147f90(int unused1, int unused2);
};

char CivilianAnimationAction::FUN_00147f90(int unused1, int unused2)
{
    Player_147f90 *p = owner->FUN_000592a0()->FUN_00059a30();
    if (p == 0)
        return 0;
    Target_147f90 *t = p->FUN_00036020();
    if (t == 0)
        return 0;
    Source_147f90 *s = src;
    Params q;
    q.f2c = s->f2c;
    q.flag.b = s->b28;
    q.f24 = s->f24;
    float start = s->f10;
    int a = s->f18;
    int b = s->f1c;
    int c = s->f20;
    t->FUN_000819f0(a, b, c, start - s->v6(), q.f24, q.flag.w, q.f2c);
    return 1;
}
