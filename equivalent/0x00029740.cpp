// STATUS: equivalent (tools/equiv.py level 3: 2997 inputs, branch coverage 14/14)
// FUN_00029740 @ 0x00029740
// Group method: look up a named pawn and a named object, and start the pawn's controller on a
// path between two of the object's points (clears the controller's dirty flag for an empty name).
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
unsigned __int64 __cdecl FUN_0027b020(const char *name);

struct Vec3 {
    float x, y, z;
};

class Object {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual Vec3 *GetPos(Vec3 *out);            // slot 8
    virtual void v9();
    virtual void GetTarget(Vec3 *out);          // slot 10
};

struct Path {
    void FUN_00025a20(unsigned __int64 key, Vec3 *from, Vec3 *to, float a, float b);
};

class Controller {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void SetMode(int mode);             // slot 8
    virtual int GetMode();                      // slot 9
    char pad04[0x54];
    Path path;                                  // 0x58
    char pad5c[0x9e - 0x58 - sizeof(Path)];
    char dirty;                                 // 0x9e
};

struct Pawn {
    char pad[0x1ca0];
    Controller *controller;                     // 0x1ca0
};

struct Finder {
    Object *FUN_001fd780(const char *name);
};

struct Env {
    char pad[0x28];
    Finder *finder;
};

struct Group {
    Env *env;
    Pawn *FUN_00024280(unsigned __int64 key);
    void FUN_00029740(const char *pawnName, const char *objectName, float a, float b);
};

void Group::FUN_00029740(const char *pawnName, const char *objectName, float a, float b)
{
    struct Frame {
        Vec3 target;
        Vec3 pos;
    } fr;
    Pawn *pawn = FUN_00024280(FUN_002672f0(pawnName, 0, 0));
    if (!pawn)
        return;
    if (!env->finder)
        return;
    Controller *c = pawn->controller;
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
