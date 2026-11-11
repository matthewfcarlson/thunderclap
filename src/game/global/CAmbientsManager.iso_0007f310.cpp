// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000788e0..0x00081340 (kind game, layer game, confidence high), dominant class CAmbientsManager
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x0007f310 FUN_0007f310 (318 B): equivalent/0x0007f310.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_0007f310@Manager_7f310@fn_f804b1ac@@QAEPAVNode@2@HHHH@Z
#include "gen/owners.h"
namespace fn_f804b1ac {} using namespace fn_f804b1ac;
namespace fn_f804b1ac {
// STATUS: equivalent (tools/equiv.py level 3: 2834 inputs, branch coverage 12/12)
// FUN_0007f310 @ 0x0007f310
void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" void *__cdecl FUN_00266da0(hulk_intptr n);

struct Timer {
    // equiv-conv: FUN_0008ced0 ecx stack stack stack stack stack stack
    void FUN_0008ced0(int which, int a, unsigned *out, int b, int c, int d);
};
Timer *__cdecl FUN_0008ceb0();

struct Entry_7f310 {
    int f0;
    int f4;
    int f8;
    unsigned char fc;
    char padd[3];
};

class Resource_7f310 {
public:
    virtual void Destroy();
    virtual void Release();
};

class Node {
public:
    virtual void v0();
    virtual void v1();
    char pad4[4];
    Node *FUN_000810f0(int a, Resource_7f310 *r, int b, int sum, float f, int flag);
};

struct Clock_7f310 {
    hulk_freg FUN_000787e0(int a, int b);
};
Clock_7f310 *__cdecl FUN_000964d0();

struct Registry_7f310 {
    char pad0[0xc];
    Registry_7f310 *sub;
    void FUN_001c3a40(void *a, Resource_7f310 *b);
    void *FUN_001c59d0(void *a);
};
Registry_7f310 *__cdecl FUN_001c3d90();

class Manager_7f310 {
public:
    char pad0[0x34a8];
    Entry_7f310 tbl[25];
    char pad3638[0xc];
    int f3644;
    int f3648;

    Resource_7f310 *FUN_0007e570(Entry_7f310 *e, int v);
    Node *FUN_0007f310(int a0, int a1, int count, int base);
};

Node *Manager_7f310::FUN_0007f310(int a0, int a1, int count, int base)
{
    unsigned stamp;
    FUN_0008ceb0()->FUN_0008ced0(10, 0, &stamp, 0, 0, 0);
    if (stamp < 0x3c00)
        return 0;

    void *saved = FUN_00266da0(10);
    Entry_7f310 *e = &tbl[count];
    Node *node = 0;
    Resource_7f310 *res = FUN_0007e570(e, base);
    if (res != 0) {
        int sum = base;
        for (int i = 0; i < count; i++)
            sum += tbl[i].f8;
        Clock_7f310 *clock = FUN_000964d0();
        float f = clock->FUN_000787e0(f3644, f3648);
        void *mem = FUN_00263ea0(0x108);
        if (mem != 0)
            node = ((Node *)mem)->FUN_000810f0(a0, res, a1, sum, f, e->fc);
        void *sub = (char *)node + 8;
        FUN_001c3d90()->FUN_001c3a40(sub, res);
        void *found = FUN_001c3d90()->sub->FUN_001c59d0(sub);
        if (found != 0) {
            ((owners::Target_80e70 *)node)->FUN_00080e70((char *)found);
        } else {
            node->v0();
            node->v1();
            node = 0;
        }
        res->Release();
    }
    FUN_00266da0((hulk_intptr)saved);
    return node;
}
} // namespace fn_f804b1ac

