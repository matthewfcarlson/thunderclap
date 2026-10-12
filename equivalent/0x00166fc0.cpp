// STATUS: equivalent (tools/equiv.py level 3: 88 inputs, branch coverage 25/26, incomplete)
// hulkfight::motion::RayCastTargetCondition::vfunc_6 @ 0x00166fc0
extern char DAT_00494b44[];
extern char DAT_00494b60[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Vec3 {
    float x, y, z;
    float FUN_0022d110();
};

struct Matrix {
    float m[16];
    void FUN_0022c2b0(const Vec3* in, Vec3* out);
    void FUN_0022c3b0(const Vec3* in, Vec3* out);
};

struct Skeleton {
    char pad00[0x1c];
    Matrix* matrices;
    int FUN_002843a0(unsigned int lo, unsigned int hi);
};

struct Entity;

struct World {
    char pad00[0x20];
    struct Player* player;
};

struct Player {
    char pad00[0x124];
    Entity* current;
};

struct Slot {
    int pad00;
    int pad04;
    struct Entity* entity;
    int count;
};

struct Entity {
    char pad00[0x120];
    Skeleton* skeleton;
    char pad124[0x334 - 0x124];
    Entity* ignoreB;
    Entity* ignoreA;
};

struct Holder {
    char pad00[0x328];
    Slot* slot;
};

struct Target {
    Holder* FUN_000592a0();
};

struct Holder2 {
    Holder* FUN_00059a30();
};

struct Obj2 {
    Holder* FUN_00059a30();
};

struct Obj1 {
    Obj2* FUN_000592a0();
};

extern World* DAT_004dd700;
char FUN_002027c0(Vec3* a, Vec3* b, int c, int d, Vec3* hitPos, Vec3* hitNormal, int e, int f);

class RayCastTargetCondition {
public:
    virtual void v0();
    char pad04[0xc];
    unsigned int boneLo;
    unsigned int boneHi;
    Vec3 offset;
    Vec3 direction;
    float length;
    char invert;

    char vfunc_6(int arg0, Obj1* target, int arg2);
};

char RayCastTargetCondition::vfunc_6(int arg0, Obj1* target, int arg2)
{
    if (FUN_00344e74(target, 0, DAT_00494b44, DAT_00494b60, 0) == 0)
        return 0;
    Holder* holder = target->FUN_000592a0()->FUN_00059a30();
    if (holder == 0)
        return 0;

    Slot* slot = holder->slot;
    if (slot == 0)
        return 0;
    Entity* ent = slot->entity;
    if (ent == 0)
        return 0;
    if (slot->count != 1)
        return 0;

    char hit = 0;
    Skeleton* skel = ent->skeleton;
    if (skel != 0) {
        unsigned int idx = 0;
        if ((boneLo | boneHi) != 0) {
            idx = skel->FUN_002843a0(boneLo, boneHi);
            if (idx == 0xffff)
                idx = 0;
        }
        Matrix* src = &skel->matrices[idx];

        Vec3 res;
        Vec3 tmp;
        Vec3 from;
        Vec3 dir;
        Vec3 hitPos;
        Vec3 hitNormal;
        Matrix mtx;

        from.x = 0; from.y = 0; from.z = 0;
        dir.x = 0; dir.y = 0; dir.z = -1.0f;
        res.x = 0; res.y = 0; res.z = 0;
        mtx = *src;

        tmp = offset;
        mtx.FUN_0022c2b0(&tmp, &from);
        tmp = direction;
        mtx.FUN_0022c3b0(&tmp, &dir);
        dir.FUN_0022d110();

        float len = length;
        res.y = dir.y * len;
        res.z = dir.z * len;
        res.x = dir.x * len + from.x;
        res.y = res.y + from.y;
        res.z = res.z + from.z;

        Entity* cur = DAT_004dd700->player->current;
        int notIgnored = 0;
        if (cur != ent && ent->ignoreA != cur && ent->ignoreB != cur)
            notIgnored = 1;

        hit = FUN_002027c0(&from, &res, 0, notIgnored, &hitNormal, &hitPos, 0, 0);
    }
    if (invert != 0)
        return hit;
    return hit == 0;
}
