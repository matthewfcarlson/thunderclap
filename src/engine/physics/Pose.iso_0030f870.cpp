// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0030eba0..0x00310130 (kind game, layer engine, confidence medium), dominant class physics::Pose
// (tree_prelude.h: not needed)


// 0x0030f870 FUN_0030f870 (403 B): equivalent/0x0030f870.cpp [isolated: code differs from its standalone build]
// sym: ?FUN_0030f870@Skeleton@fn_f9a2be07@@QAEXPAV12@@Z
#include "gen/owners.h"
namespace fn_f9a2be07 {} using namespace fn_f9a2be07;
namespace fn_f9a2be07 {
// STATUS: equivalent (tools/equiv.py level 3: 75 inputs, branch coverage 30/30)
// FUN_0030f870 @ 0x0030f870
class Elem_30f870 {
public:
    int index;
    Elem_30f870 *parent;
    char pad8[4];
    int depth;
    char pad10[0xc0 - 0x10];
    void FUN_0030ebd0();
    void FUN_0030ebe0(const Elem_30f870 *src);
};

void FUN_0030eba0();
extern "C" void *__cdecl FUN_0008d6d0(unsigned int size);
void __cdecl FUN_0008d340(void *p);
void __stdcall FUN_00011520(void *p, unsigned int size, int count, void (*ctor)());

class Shared {
public:
    virtual void addRef();
    virtual void release();
    char pad4[0xc];
    int count;
    char pad14[0x28 - 0x14];
    unsigned short *parents;
};

class Skeleton {
public:
    char pad0[8];
    Shared *shared;
    Elem_30f870 *elems;
    void FUN_0030f870(Skeleton *other);
};

void Skeleton::FUN_0030f870(Skeleton *other)
{
    Shared *src = other->shared;
    if (src == shared) {
        int n = shared ? shared->count : 0;
        for (int i = 0; i < n; i++)
            elems[i].FUN_0030ebe0(&other->elems[i]);
        return;
    }

    if (src)
        src->addRef();
    if (shared)
        shared->release();
    shared = src;

    if (elems) {
        Elem_30f870 *old = elems;
        int *block = (int *)old - 1;
        for (int i = *block - 1; i >= 0; i--)
            old[i].FUN_0030ebd0();
        FUN_0008d340(block);
    }

    int n = shared->count;
    if (n <= 0) {
        elems = 0;
        return;
    }
    int *mem = (int *)FUN_0008d6d0(n * sizeof(Elem_30f870) + 4);
    Elem_30f870 *arr = 0;
    if (mem) {
        *mem = n;
        arr = (Elem_30f870 *)(mem + 1);
        FUN_00011520(arr, sizeof(Elem_30f870), n, FUN_0030eba0);
    }
    elems = arr;
    elems[0].FUN_0030ebe0(&other->elems[0]);
    for (int i = 1; i < n; i++) {
        elems[i].index = i;
        elems[i].parent = &elems[shared->parents[i]];
        ((owners::A_30ec20 *)(elems[i].parent))->FUN_0030ec20(elems[i].parent->depth + 1);
        elems[i].FUN_0030ebe0(&other->elems[i]);
    }
    for (int i = 1; i < n; i++)
        ((owners::Buffer_30ec70 *)&(elems[shared->parents[i]]))->FUN_0030ec70((hulk_uintptr)(Elem_30f870 *)(&elems[i]));
}
} // namespace fn_f9a2be07

