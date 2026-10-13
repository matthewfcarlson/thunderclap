// STATUS: equivalent (tools/equiv.py level 3: 3037 inputs, branch coverage 42/42)
// hulkfight::ai::TargetDistanceCondition::vfunc_6 @ 0x001251f0
extern "C" double sqrt(double);

extern char DAT_00494b44[];
extern char DAT_00494b60[];
void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);
char __cdecl FUN_00018960(float a, float b, float eps);

struct V3 {
    float x, y, z;
    bool FUN_0022d2b0(const V3 *other, float eps);
};

struct Mgr10 {
    bool FUN_00059a50(V3 *out);
};

struct Obj10 {
    char pad0[0x10];
    Mgr10 *f10;
};

struct Target;

struct Agent {
    char pad0[0x1a60];
    V3 pos;                 // 0x1a60
};

struct Target {
    char pad0[8];
    Agent *p8;              // 0x8
    int kind;               // 0xc
    char pad10[0x40 - 0x10];
    V3 v40;
};

struct Player {
    char pad0[0x10];
    Mgr10 *f10;
    char pad14[0x328 - 0x14];
    Target *f328;
    char pad32c[0x1d54 - 0x32c];
    V3 v1d54;
    int lo1d60;
    int hi1d64;
};

struct Mgr {
    Player *FUN_00059a30();
};

struct Source {
    Mgr *FUN_000592a0();
};

struct Mid {
    char pad0[0x40];
    V3 v40;                 // 0x40
};

struct Hero {
    char pad0[0x12c];
    Mid *f12c;
    char pad130[0x1a60 - 0x130];
    V3 pos;                 // 0x1a60
};

struct Reg {
    char pad0[0x124];
    Hero *f124;
    Obj10 *FUN_00024280(int lo, int hi);
};

struct Globals {
    char pad0[0x20];
    Reg *f20;
};
extern Globals *DAT_004dd700;

class TargetDistanceCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int a, Source *source, int c);
    char pad04[8];
    int mode;               // 0xc
    float threshold;        // 0x10
    char flag14;
    char flag15;
};

char TargetDistanceCondition::vfunc_6(int a, Source *source, int c)
{
    V3 A;
    V3 B;
    V3 T;
    V3 C;

    if (!FUN_00344e74(source, 0, DAT_00494b44, DAT_00494b60, 0))
        return false;

    Player *pl = source->FUN_000592a0()->FUN_00059a30();
    A.x = 0.0f;
    A.y = 0.0f;
    A.z = 0.0f;
    B.x = 0.0f;
    B.y = 0.0f;
    B.z = 0.0f;
    pl->f10->FUN_00059a50(&A);
    Target *tgt = pl->f328;

    if (flag14) {
        Hero *x = DAT_004dd700->f20->f124;
        if (x) {
            Mid *y = x->f12c;
            if (flag15 == 0)
                T = y->v40;
            else
                T = x->pos;
        }
    } else {
        if (!tgt)
            return false;
        C = pl->v1d54;
        bool done = false;
        if (!C.FUN_0022d2b0(&B, 0.00001f)) {
            Reg *reg = DAT_004dd700->f20;
            if (reg) {
                Obj10 *o = reg->FUN_00024280(pl->lo1d60, pl->hi1d64);
                if (o) {
                    o->f10->FUN_00059a50(&T);
                    done = true;
                }
            }
        }
        if (!done) {
            if (tgt->kind == 1 && tgt->p8 && flag15)
                T = tgt->p8->pos;
            else
                T = tgt->v40;
        }
    }

    float dist = (float)sqrt((double)((T.z - A.z) * (T.z - A.z) + (T.y - A.y) * (T.y - A.y) + (T.x - A.x) * (T.x - A.x)));

    switch (mode) {
    case 0:
        return dist < threshold;
    case 1:
        return dist <= threshold;
    case 2:
        return FUN_00018960(dist, threshold, 0.00001f);
    case 3:
        return FUN_00018960(dist, threshold, 0.00001f) == 0;
    case 4:
        return dist >= threshold;
    case 5:
        return dist > threshold;
    }
    return false;
}
