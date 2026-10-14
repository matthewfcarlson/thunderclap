inline void *operator new(unsigned int, void *p) throw() { return p; }

int FUN_00266da0(int heap);

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[4];
    char nameHolder[8];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

struct Params {
    int f00;
    int f04;
    char c08, c09, c0a, c0b, c0c, c0d, c0e;
    char c0f;
    int f10;
    int f14;
    char b18, b19;
    char pad1a[2];
    int f1c;
    int f20;
};

class Part {
public:
    virtual void v0(int a, int b, int c);
};

class Instance {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Part *v4();
    virtual void v5(Part *part);
    virtual void v6();
};

class Factory {
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
    virtual Instance *v10(Params *params);
};
extern Factory *DAT_0052c2a0;

struct Entry {
    int count;
    char pad04[0xc];
    Instance *instance;
    char pad14[8];
};

namespace pure3d {
namespace prop {
class CDecalQueue : public Entity {
public:
    virtual void v1();
    int f10;
    int f14;
    int f18;
    int f1c;
    char pad20[8];
    Entry entries[100];

    CDecalQueue(int heap);
};
}
}

pure3d::prop::CDecalQueue::CDecalQueue(int heap)
{
    f14 = 0xf;
    f18 = 0;
    f1c = heap;
    int previous = FUN_00266da0(heap);
    Params p;
    p.c0b = ' ';
    p.c0a = ' ';
    p.c09 = ' ';
    p.c08 = ' ';
    p.c0c = ' ';
    p.c0d = ' ';
    p.c0e = ' ';
    p.f00 = 0;
    p.f04 = 0x2021;
    p.f10 = 0x42;
    p.f14 = 0;
    p.b18 = 0;
    p.b19 = 0;
    p.f1c = 0;
    p.f20 = 0;
    for (int i = 0; i < 100; i++) {
        entries[i].count = 0;
        entries[i].instance = DAT_0052c2a0->v10(&p);
        entries[i].instance->v0();
        Part *part = entries[i].instance->v4();
        for (int n = 0x42; n != 0; n--)
            part->v0(0, 0, 0);
        entries[i].instance->v5(part);
        entries[i].instance->v6();
    }
    FUN_00266da0(previous);
}
