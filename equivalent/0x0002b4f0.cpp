// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0002b4f0 @ 0x0002b4f0
// Distance from a named pawn to an object found by id (-1 when either is missing).
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

struct Vec3 {
    float x, y, z;
};

struct Body {
    bool FUN_00059a50(Vec3 *out);
};

struct Pawn {
    char pad[0x10];
    Body *body;
};

class Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Vec3 *GetPos(Vec3 *out);
};

struct Finder {
    Object *FUN_001fd780(int key);
};

struct Env {
    char pad[0x28];
    Finder *finder;
};

float __cdecl FUN_0002a380(Vec3 *a, Vec3 *b);

struct Group {
    Env *env;
    Pawn *FUN_00024280(unsigned __int64 key);
    float FUN_0002b4f0(const char *name, int objectKey);
};

float Group::FUN_0002b4f0(const char *name, int objectKey)
{
    struct Frame {
        Vec3 copy;
        Vec3 pawnPos;
        Vec3 objPos;
    } fr;
    Pawn *pawn = FUN_00024280(FUN_002672f0(name, 0, 0));
    if (pawn && env->finder) {
        Object *obj = env->finder->FUN_001fd780(objectKey);
        if (obj && pawn->body->FUN_00059a50(&fr.pawnPos)) {
            fr.copy = *obj->GetPos(&fr.objPos);
            return FUN_0002a380(&fr.pawnPos, &fr.copy);
        }
    }
    return -1.0f;
}
