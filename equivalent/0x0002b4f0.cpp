// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0002b4f0 @ 0x0002b4f0
// Distance from a named pawn to an object found by id (-1 when either is missing).
#include "decls/address.h"

struct Vec3_2b4f0 {
    float x, y, z;
};

struct Body_2b4f0 {
    bool FUN_00059a50(Vec3_2b4f0 *out);
};

struct Pawn_2b4f0 {
    char pad[0x10];
    Body_2b4f0 *body;
};

class Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Vec3_2b4f0 *GetPos(Vec3_2b4f0 *out);
};

struct Finder_2b4f0 {
    Object *FUN_001fd780(int key);
};

struct Env_2b4f0 {
    char pad[0x28];
    Finder_2b4f0 *finder;
};

float __cdecl FUN_0002a380(Vec3_2b4f0 *a, Vec3_2b4f0 *b);

struct Group_2b4f0 {
    Env_2b4f0 *env;
    Pawn_2b4f0 *FUN_00024280(unsigned __int64 key);
    float FUN_0002b4f0(const char *name, int objectKey);
};

float Group_2b4f0::FUN_0002b4f0(const char *name, int objectKey)
{
    struct Frame {
        Vec3_2b4f0 copy;
        Vec3_2b4f0 pawnPos;
        Vec3_2b4f0 objPos;
    } fr;
    Pawn_2b4f0 *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn && env->finder) {
        Object *obj = env->finder->FUN_001fd780(objectKey);
        if (obj && pawn->body->FUN_00059a50(&fr.pawnPos)) {
            fr.copy = *obj->GetPos(&fr.objPos);
            return FUN_0002a380(&fr.pawnPos, &fr.copy);
        }
    }
    return -1.0f;
}
