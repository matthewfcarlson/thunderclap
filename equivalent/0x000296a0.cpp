// STATUS: equivalent (tools/equiv.py level 3: 2994 inputs, branch coverage 10/10)
// FUN_000296a0 @ 0x000296a0
// Group method: copy a value taken from a named pawn (or, failing that, a spawned prop)
// into the first pawn's controller and raise the controller's mode to at least 3.
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);

class Controller {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void SetMode(int mode);       // slot 8
    virtual int GetMode();                // slot 9
    char pad04[0x60];
    int value;                            // 0x64
    char pad68[0x36];
    char dirty;                           // 0x9e
    char pad9f[0x21];
    int flag;                             // 0xc0
};

struct Pawn {
    char pad[0x12c];
    int value;                            // 0x12c
    char pad130[0x1b70];
    Controller *controller;               // 0x1ca0
};

struct Prop {
    int FUN_001d72e0();
};

struct Manager {
    Prop *FUN_001def30(const char *name);
};

struct Env {
    char pad[0xc];
    Manager *manager;
};

struct Group {
    Env *env;
    Pawn *FUN_00024280(unsigned __int64 key);
    void FUN_000296a0(const char *nameA, const char *nameB, int flag);
};

void Group::FUN_000296a0(const char *nameA, const char *nameB, int flag)
{
    Pawn *pawn = FUN_00024280(FUN_002672f0(nameA, 0, 0));
    if (pawn) {
        int value = 0;
        Pawn *other = FUN_00024280(FUN_002672f0(nameB, 0, 0));
        if (other) {
            value = other->value;
        } else {
            Prop *prop = env->manager->FUN_001def30(nameB);
            if (prop)
                value = prop->FUN_001d72e0();
        }
        Controller *c = pawn->controller;
        if (c) {
            c->value = value;
            c->flag = flag;
            c->dirty = 1;
            if (c->GetMode() < 3)
                c->SetMode(3);
        }
    }
}
