// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001fa630 @ 0x001fa630
inline void *operator new(unsigned int, void *p) { return p; }
void *FUN_0008d690(unsigned int size);
extern const char DAT_003f335c[];

class Pool_1fa630 {
public:
    virtual void AddRef();
    virtual void Release();
};

struct EncObj {
    char pad0[0x18];
    Pool_1fa630 *pool;
    void FUN_00230b60();
};

struct Tracker_1fa630 {
    void FUN_001d1900(int id);
};

struct NameHolder_1fa630 {
    char pad[8];
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

Tracker_1fa630 *__cdecl FUN_001d4c90();
void __cdecl FUN_00267760(char *dst, int size, const char *src);
void __cdecl FUN_002702a0(Pool_1fa630 **out, int a, int b, int c, int d, const char *name, int e);

struct ElemA {
    int f0, f4, f8, fc, f10, f14, f18, f1c, f20;
    char b24;
    char pad25[3];
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[0xc];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

class CEncounterGenerator : public pure3d::Entity {
public:
    class CEncounter {
    public:
        CEncounter();
        virtual void v0();
        char pad04[4];
        int f8;
        char name[0x20];
        char pad2c[4];
        NameHolder_1fa630 holder;
        char b38;
        char b39;
        char pad3a[6];
        int f40, f44, f48, f4c;
        char b50;
        char b51;
        unsigned short w52;
        char pad54[4];
    };

    CEncounterGenerator();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();

    char pad10[0x448 - 0x10];
    int f448;
    int f44c;
    char pad450[0x460 - 0x450];
    ElemA elemsA[16];
    char pad6e0[8];
    char elemsB[16 * 0x58];
    char padc68[4];
    EncObj *encounter;
    void FUN_001fa040();
};

CEncounterGenerator::CEncounter::CEncounter()
{
    holder.FUN_0027af00();
    w52 = 0;
    f8 = 0;
    FUN_00267760(name, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    b38 = (char)0xff;
    holder.FUN_0027b040(DAT_003f335c);
    b39 = (char)0xff;
    b50 = 0;
    b51 = 1;
    w52 = 0xffff;
}

CEncounterGenerator::CEncounterGenerator()
{
    int i;
    for (i = 0; i < 16; i++) {
        ElemA *e = &elemsA[i];
        e->f20 = -1;
        e->f0 = 0;
        e->f4 = -1;
        e->f8 = -1;
        e->fc = 0;
        e->f10 = 0;
        e->f14 = 0;
        e->f18 = 0;
        e->f1c = 0;
        e->b24 = 0;
        Tracker_1fa630 *t = FUN_001d4c90();
        t->FUN_001d1900(*(volatile int *)&e->f20);
        e->f20 = -1;
    }
    for (i = 0; i < 16; i++)
        new (elemsB + i * 0x58) CEncounter();

    Pool_1fa630 *pool;
    bool held = false;
    FUN_002702a0(&pool, 0x28, 0x100, 0, 0, "encounterGenerator: Memory Map Pool", 4);
    EncObj *obj = (EncObj *)FUN_0008d690(0x1c);
    if (obj) {
        Pool_1fa630 *p = pool;
        held = true;
        p->AddRef();
        obj->pool = p;
        obj->FUN_00230b60();
    } else {
        obj = 0;
    }
    encounter = obj;
    if (held)
        pool->Release();
    f448 = -1;
    f44c = -1;
    FUN_001fa040();
}
