// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 24/27, incomplete)
// hulkfight::ai::FormationReadyCondition::vfunc_6 @ 0x0010e040
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

struct Vec3 {
    float x, y, z;
};
struct Pair {
    int a, b;
};

struct Body {
    char pad0[0x40];
    Vec3 pos;
};

struct Actor {
    char pad0[8];
    int idA;                 // 0x08
    int idB;                 // 0x0c
    char pad10[0x328 - 0x10];
    Body *body;              // 0x328
    char pad32c[0x1b38 - 0x32c];
    float value;             // 0x1b38
    char pad1b3c[4];
    int nameLo;              // 0x1b40
    int nameHi;              // 0x1b44
    void FUN_00023d30(const char *name);
};

struct Chain {
    Actor *FUN_00059a30();
};

struct Owner {
    Chain *FUN_000592a0();
};

struct Registry {
    char pad0[0x150];
    int cur;                 // 0x150
    char pad154[0x2c8 - 0x154];
    int lo;                  // 0x2c8
    int hi;                  // 0x2cc
    void FUN_00065dd0(Pair *key);
    void FUN_000671b0(Vec3 *pos);
};
Registry *__cdecl FUN_000678d0();

class FormationReadyCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual char vfunc_6(int unused1, Owner *owner, int unused3);
    char pad4[8];
    unsigned int mode;
};

char FormationReadyCondition::vfunc_6(int unused1, Owner *owner, int unused3)
{
    if (!FUN_00344e74(owner, 0, DAT_00494b44, DAT_00494b60, 0))
        return 0;
    Actor *actor = owner->FUN_000592a0()->FUN_00059a30();
    if (!actor)
        return 0;
    Body *body = actor->body;
    if (!body)
        return 0;

    Vec3 pos = body->pos;
    if ((actor->nameLo | actor->nameHi) == 0)
        actor->FUN_00023d30("default");

    Pair key;
    key.a = actor->idA;
    key.b = actor->idB;
    FUN_000678d0()->FUN_00065dd0(&key);
    FUN_000678d0()->FUN_000671b0(&pos);

    int cur = FUN_000678d0()->cur;
    if (cur < FUN_000678d0()->lo)
        return 0;
    cur = FUN_000678d0()->cur;
    if (cur > FUN_000678d0()->hi)
        return 0;

    // The original's jump table sends every mode 0..5 to the same test.
    if (mode > 5)
        return 0;
    return actor->value != 0.0f;
}
