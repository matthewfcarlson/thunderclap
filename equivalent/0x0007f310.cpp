// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_0007f310 @ 0x0007f310
void *__cdecl FUN_00263ea0(unsigned int size);
void *__cdecl FUN_00266da0(int n);

struct Timer {
    // equiv-conv: FUN_0008ced0 ecx stack stack stack stack stack stack
    void FUN_0008ced0(int which, int a, unsigned *out, int b, int c, int d);
};
Timer *__cdecl FUN_0008ceb0();

struct Entry {
    int f0;
    int f4;
    int f8;
    unsigned char fc;
    char padd[3];
};

class Resource {
public:
    virtual void Destroy();
    virtual void Release();
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    char pad4[4];
    Node *FUN_000810f0(int a, Resource *r, int b, int sum, float f, int flag);
    void FUN_00080e70(void *p);
};

struct Clock {
    float FUN_000787e0(int a, int b);
};
Clock *__cdecl FUN_000964d0();

struct Registry {
    char pad0[0xc];
    Registry *sub;
    void FUN_001c3a40(void *a, Resource *b);
    void *FUN_001c59d0(void *a);
};
Registry *__cdecl FUN_001c3d90();

class Manager {
public:
    char pad0[0x34a8];
    Entry tbl[25];
    char pad3638[0xc];
    int f3644;
    int f3648;

    Resource *FUN_0007e570(Entry *e, int v);
    Node *FUN_0007f310(int a0, int a1, int count, int base);
};

Node *Manager::FUN_0007f310(int a0, int a1, int count, int base)
{
    unsigned stamp;
    FUN_0008ceb0()->FUN_0008ced0(10, 0, &stamp, 0, 0, 0);
    if (stamp < 0x3c00)
        return 0;

    void *saved = FUN_00266da0(10);
    Entry *e = &tbl[count];
    Node *node = 0;
    Resource *res = FUN_0007e570(e, base);
    if (res != 0) {
        int sum = base;
        for (int i = 0; i < count; i++)
            sum += tbl[i].f8;
        Clock *clock = FUN_000964d0();
        float f = clock->FUN_000787e0(f3644, f3648);
        void *mem = FUN_00263ea0(0x108);
        if (mem != 0)
            node = ((Node *)mem)->FUN_000810f0(a0, res, a1, sum, f, e->fc);
        void *sub = (char *)node + 8;
        FUN_001c3d90()->FUN_001c3a40(sub, res);
        void *found = FUN_001c3d90()->sub->FUN_001c59d0(sub);
        if (found != 0) {
            node->FUN_00080e70(found);
        } else {
            node->v0();
            node->v1();
            node = 0;
        }
        res->Release();
    }
    FUN_00266da0((int)saved);
    return node;
}
