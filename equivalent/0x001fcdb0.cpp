// STATUS: equivalent (tools/equiv.py level 3: 344 inputs, branch coverage 13/14, incomplete)
// FUN_001fcdb0 @ 0x001fcdb0
class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual bool Accepts(int a, int b);
};

struct Entity {
    char pad0[8];
    int fieldA;         // 8
    int fieldB;         // 0xc
    void FUN_00043350(int a, int b, int c, float d, int e, int f);
};

struct EntityList {
    char pad0[0xc];
    int count;          // 0xc
    Entity *FUN_00024190(int index);
    bool FUN_000242d0(Entity *e);
};

struct Holder {
    char pad0[0x20];
    EntityList *list;   // 0x20
};

unsigned __int64 __cdecl FUN_00096d80(int key);

class Spawner {
public:
    char pad0[4];
    Holder *holder;     // 4
    Target *FUN_001fc850(unsigned __int64 id);
    void FUN_001fcdb0(int key, int arg);
};

void Spawner::FUN_001fcdb0(int key, int arg)
{
    Target *target = FUN_001fc850(FUN_00096d80(key));
    if (target == 0)
        return;
    EntityList *list = holder->list;
    int count = list->count;
    for (int i = 0; i < count; i++) {
        Entity *e = list->FUN_00024190(i);
        if (e == 0)
            continue;
        if (list->FUN_000242d0(e))
            continue;
        if (target->Accepts(e->fieldA, e->fieldB))
            e->FUN_00043350(arg, 0, 0, 1.0f, 1, 0);
    }
}
