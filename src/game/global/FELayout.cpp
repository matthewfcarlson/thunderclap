// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1dd0..0x000e1ff0 (kind game, layer game, confidence high), dominant class FELayout
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_ff3bead7 {
#define TREE_TU_END }
namespace fn_ff3bead7 {} using namespace fn_ff3bead7;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff3bead7 {
struct Entry_e1dd0 {
    int f0;
    const char* name;
};
class Table_e1dd0 {
public:
    int f0;
    int f4;
    Entry_e1dd0* entries[32];     // 0x8
    Entry_e1dd0* FUN_000e1dd0(const char* key);
};
struct V {
    float x, y, z;
};
struct Sub_e1e90 {
    void Get(V* out);
};
struct Node {
    char pad[0x18];
    Sub_e1e90 sub;
};
struct Handle_e1e90 {
    Node* p;
};


// 0x000e1dd0 FUN_000e1dd0 (112 B): equivalent/0x000e1dd0.cpp
// sym: ?FUN_000e1dd0@Table_e1dd0@fn_ff3bead7@@QAEPAUEntry_e1dd0@2@PBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000e1dd0 @ 0x000e1dd0
Entry_e1dd0* Table_e1dd0::FUN_000e1dd0(const char* key)
{
    for (int i = 0; i < 32; i++) {
        if (entries[i] == 0)
            return 0;
        if (strcmp(entries[i]->name, key) == 0)
            return entries[i];
    }
    return 0;
}


// 0x000e1e90 FUN_000e1e90 (124 B): matches/0x000e1e90.cpp
// sym: _FUN_000e1e90
extern "C" int FUN_000e1e90(Handle_e1e90* a, Handle_e1e90* b) {
    Node* na = a->p;
    Node* nb = b->p;
    if (!na)
        return nb != 0;
    if (!nb)
        return -1;
    V va, vb;
    na->sub.Get(&va);
    nb->sub.Get(&vb);
    int r = 0;
    if (va.z != vb.z) {
        if (va.z > vb.z)
            r = -1;
        else
            r = 1;
    }
    return r;
}

} // namespace fn_ff3bead7

// 0x000e1f10 FUN_000e1f10 (91 B): matches/0x000e1f10.cpp [wrapped: conflict: FELayout]
// sym: ?init@FELayout@fn_000e1f10@@QAEPAV12@PAVManager_e1f10@2@H@Z
namespace fn_000e1f10 {
extern "C" char DAT_0040c0f4[];
class Manager_e1f10 {
  public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47(int, void*);
    virtual void s48();
    virtual void s49();
    virtual void s50(int, void*);
    char pad[0x848];
    float value;
};
class FELayout {
  public:
    FELayout* init(Manager_e1f10* p, int arg);
    hulk_intptr vt;
    int a;
    Manager_e1f10* m;
    int b;
    int c;
    int e;
    int d[4];
    int f[3];
    float scale;
};
FELayout* FELayout::init(Manager_e1f10* p, int arg) {
    int* q = &d[0];
    vt = ((hulk_intptr)DAT_0040c0f4);
    q[0] = 0;
    q[2] = 0;
    q[3] = 0;
    m = p;
    c = 0;
    e = 0;
    p->s47(arg, q);
    m->s50(arg, &f[0]);
    scale = m->value * 0.001f;
    return this;
}
} // namespace fn_000e1f10

namespace fn_ff3bead7 {

// 0x000e1f70 FELayout::vfunc_0 (1 B): matches/0x000e1f70.cpp
// sym: ?FUN_000e1f70@fn_ff3bead7@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000e1f70() {}

} // namespace fn_ff3bead7

// 0x000e1f80 FELayout::vfunc_3 (3 B): matches/0x000e1f80.cpp
// sym: ?vfunc_3@FELayout@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FELayout::vfunc_3(int a) {
    (void)a;
}


// 0x000e1f90 FELayout::vfunc_4 (3 B): matches/0x000e1f90.cpp
// sym: ?vfunc_4@FELayout@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FELayout::vfunc_4(int a) {
    (void)a;
}

namespace fn_ff3bead7 {

// 0x000e1fa0 FELayout::vfunc_20 (4 B): matches/0x000e1fa0.cpp
// sym: ?FUN_000e1fa0@fn_ff3bead7@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_000e1fa0(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_ff3bead7
