// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 14/14)
// FUN_00029740 @ 0x00029740
// Group method: look up a named pawn and a named object, and start the pawn's controller on a
// path between two of the object's points (clears the controller's dirty flag for an empty name).
#include "decls/address.h"

struct Vec3_29740 {
    float x, y, z;
};

class Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Vec3_29740 *GetPos(Vec3_29740 *out);            // slot 8
    virtual void v9();
    virtual void GetTarget(Vec3_29740 *out);          // slot 10
};

struct Path_29740 {
    void FUN_00025a20(unsigned __int64 key, Vec3_29740 *from, Vec3_29740 *to, float a, float b);
};

class Controller_29740 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void SetMode(int mode);             // slot 8
    virtual int GetMode();                      // slot 9
    char pad04[0x54];
    Path_29740 path;                                  // 0x58
    char pad5c[0x9e - 0x58 - sizeof(Path_29740)];
    char dirty;                                 // 0x9e
};

struct Pawn_29740 {
    char pad[0x1ca0];
    Controller_29740 *controller;                     // 0x1ca0
};

struct Finder_29740 {
    Object *FUN_001fd780(const char *name);
};

struct Env_29740 {
    char pad[0x28];
    Finder_29740 *finder;
};

struct Group_29740 {
    Env_29740 *env;
    Pawn_29740 *FUN_00024280(unsigned __int64 key);
    void FUN_00029740(const char *pawnName, const char *objectName, float a, float b);
};

void Group_29740::FUN_00029740(const char *pawnName, const char *objectName, float a, float b)
{
    struct Frame {
        Vec3_29740 target;
        Vec3_29740 pos;
    } fr;
    Pawn_29740 *pawn = FUN_00024280(FUN_002672f0(pawnName, 0, 0));
    if (!pawn)
        return;
    if (!env->finder)
        return;
    Controller_29740 *c = pawn->controller;
    if (!c)
        return;
    if (!objectName || !*objectName) {
        c->dirty = 0;
        return;
    }
    Object *obj = env->finder->FUN_001fd780(objectName);
    if (!obj)
        return;
    obj->GetPos(&fr.pos);
    obj->GetTarget(&fr.target);
    c->path.FUN_00025a20(FUN_0027b020(objectName), &fr.pos, &fr.target, a, b);
    c->dirty = 1;
    if (c->GetMode() < 3)
        c->SetMode(3);
}
