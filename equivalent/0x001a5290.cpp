// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 22/22)
// FUN_001a5290 @ 0x001a5290
extern "C" int __cdecl strcmp(const char *, const char *);

class Checker {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21();
    virtual bool v22();
};

class Readiness {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual bool v7();
};

struct Resource {
    bool FUN_00222a00(int arg);
};

struct Info {
    char pad0[0x4c];
    const char *name;
};

struct Slot {
    char used;
    char pad1[3];
    int arg;
    Resource *resource;
    char pad0c[0x18 - 0xc];
};

class Loader {
public:
    char pad00[0x1c];
    Info *info;
    char pad20[4];
    Checker *checker;
    char pad28[4];
    Slot slots[20];
    char pad_end[0x210 - 0x2c - 20 * 0x18];
    Readiness *ready;
    bool FUN_001a5290();
};

bool Loader::FUN_001a5290()
{
    if (checker) {
        const char *name = info->name;
        if (name && strcmp(name, "1aa_01_vr_helmet.p3d") == 0) {
            if (checker->v22())
                return true;
        }
        if (!checker->v22())
            return false;
    }
    for (int i = 0; i < 20; i++) {
        if (slots[i].used && slots[i].resource) {
            if (!slots[i].resource->FUN_00222a00(slots[i].arg))
                return false;
        }
    }
    if (ready && !ready->v7())
        return false;
    return true;
}
