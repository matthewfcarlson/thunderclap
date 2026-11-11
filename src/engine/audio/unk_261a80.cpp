// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00261a80..0x002620e0 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fa1df58d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fa1df58d {} using namespace fn_fa1df58d;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_fa1df58d {
extern "C" bool __cdecl Check(void*, void*);
static inline hulk_freg fmodf_261bb0(float x, float y) { return fmod(x, y); }
struct Stream {
    char pad0[0x24];
    int indent;
};
bool __cdecl FUN_00246f50(Stream *s, const char *fmt, ...);
extern "C" bool __cdecl FUN_0024eb60(Stream **w, const char *name, void *value);
class Fraction {
public:
    int numerator;
    int denominator;
    bool FUN_00261c20(Stream **w);
};
struct Item {
    int unused;
    Link link;
};
extern "C" void FUN_00247550(Pool* pool, Item* item);
extern "C" bool __cdecl FUN_0025abd0(const char*, unsigned int*);
extern "C" bool __cdecl FUN_0025ac10(const char*, unsigned int*);
extern "C" void* __cdecl FUN_00247530(void*);
extern int gBss_261ef0;
struct Link_261f90 { Link_261f90* next; };
struct Item_261f90 { float value; Link_261f90 link; };
extern "C" void __cdecl FUN_00261d10(void *);
typedef unsigned int u32_262090;
extern int vtable_262090;
struct SeqEventLogicRepeat_262090 {
    void init();
};
extern "C" u32_262090 __cdecl FUN_002673a0(const char*, int);
struct Obj_262090 {
    hulk_uintptr vt;
    char pad[0x18];
    SeqEventLogicRepeat_262090 s;
    char pad2[0x1b];
    u32_262090 a;
    u32_262090 b;
    u32_262090 flags;
    unsigned char c[4];
};

} // namespace fn_fa1df58d

// 0x00261a80 FUN_00261a80 (56 B): matches/0x00261a80.cpp
// sym: ?FUN_00261a80@Target_261a80@owners@@QAEHPAX@Z
// Same code shape as 0x0025c000 (propagated; names are from that function)
int owners::Target_261a80::FUN_00261a80(void* p) {
    if (Check(p, this) && Check(p, (char*)this + 4))
        return 1;
    return 0;
}

namespace fn_fa1df58d {

// 0x00261bb0 FUN_00261bb0 (103 B): equivalent/0x00261bb0.cpp
// sym: _FUN_00261bb0
// STATUS: equivalent (tools/equiv.py level 3: 3003 inputs, branch coverage 2/2; Wine build 603 inputs, 2/2)
// FUN_00261bb0 @ 0x00261bb0
extern "C" double FUN_00261bb0(float a1, const int* length, int a3, int a4, float a5) {
    double beats = (double)a3 + (double)DAT_004cd470 * a4 * 0.001f;
    double rate = (double)a4 * 60.0f / a1;
    float len = (float)*length;
    float pos = (float)(beats / rate + a5);
    if (beats < 0.0)
        return len - fmodf_261bb0(-pos, len);
    return fmodf_261bb0(pos, len);
}


// 0x00261c20 FUN_00261c20 (117 B): equivalent/0x00261c20.cpp
// sym: ?FUN_00261c20@Fraction@fn_fa1df58d@@QAE_NPAPAUStream@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 952 inputs, branch coverage 8/8)
// FUN_00261c20 @ 0x00261c20
bool Fraction::FUN_00261c20(Stream **w)
{
    if (!FUN_00246f50(*w, "\n[\n"))
        return false;
    (*w)->indent++;
    if (!FUN_0024eb60(w, "mNumerator", this))
        return false;
    if (!FUN_0024eb60(w, "mDenominator", &denominator))
        return false;
    (*w)->indent--;
    if (!FUN_00246f50(*w, "]"))
        return false;
    return true;
}


// 0x00261d10 FUN_00261d10 (81 B): equivalent/0x00261d10.cpp
// sym: _FUN_00261d10
// STATUS: equivalent (tools/equiv.py level 3: 3015 inputs, branch coverage 7/7)
// FUN_00261d10 @ 0x00261d10
// The original searches for the node's predecessor by walking from the head, but the node it removes
// is always the head (item is derived from list->head), so the search never runs and prev is always 0.
// equiv-dead: +0x1a not taken, +0x26 taken, +0x26 not taken, +0x2a taken, +0x2a not taken: node is always the head
extern "C" void FUN_00261d10(void * list)
{
    for (;;) {
        Link* node = ((List *)list)->head;
        if (node == 0)
            return;
        Item* item = (Item*)((char*)node - 4);
        if (item == 0)
            return;
        ((List *)list)->head = node->next;
        if (node->next == 0)
            ((List *)list)->tail = 0;
        FUN_00247550(((Pool*)&DAT_004e7a30), item);
    }
}

} // namespace fn_fa1df58d

// 0x00261e60 FUN_00261e60 (135 B): equivalent/0x00261e60.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_00261e60@FloatList@fn_00261e60@@QAE_NPAUOutput_261e60@2@@Z
namespace fn_00261e60 {
// STATUS: equivalent (tools/equiv.py level 3: 712 inputs, branch coverage 12/12)
// FUN_00261e60 @ 0x00261e60
struct Writer_261e60 {
    char pad00[0x24];
    int depth;
};

struct Output_261e60 {
    Writer_261e60 *writer;
};

char __cdecl FUN_00246f50(Writer_261e60 *w, const char *fmt, ...);

struct Link_261e60 {
    Link_261e60 *next;
};

struct Elem_261e60 {
    float value;
    Link_261e60 link;
};

static Elem_261e60 *ElemOf(Link_261e60 *l)
{
    return l ? (Elem_261e60 *)((char *)l - 4) : 0;
}

class FloatList {
public:
    Link_261e60 *head;
    bool FUN_00261e60(Output_261e60 *out);
};

// Writes "[\n", one "%f\n" line per element, then "]\n".
bool FloatList::FUN_00261e60(Output_261e60 *out)
{
    if (!FUN_00246f50(out->writer, "[\n"))
        return false;
    out->writer->depth++;
    for (Elem_261e60 *e = ElemOf(head); e; e = ElemOf(e->link.next)) {
        if (!FUN_00246f50(out->writer, "%f\n", (double)e->value))
            return false;
    }
    out->writer->depth--;
    return FUN_00246f50(out->writer, "]\n") != 0;
}
} // namespace fn_00261e60


// 0x00261ef0 FUN_00261ef0 (145 B): matches/0x00261ef0.cpp
// sym: ?FUN_00261ef0@Obj_261ef0@owners@@QAE_NPBD@Z
bool owners::Obj_261ef0::FUN_00261ef0(const char* name) {
    unsigned int count;
    if (!FUN_0025abd0(name, &count))
        return false;
    for (unsigned int i = 0; i < count; ++i) {
        unsigned int value;
        if (!FUN_0025ac10(name, &value))
            return false;
        int* p = (int*)FUN_00247530(&gBss_261ef0);
        if (p)
            *p = value;
        else
            p = 0;
        ++p;
        *p = 0;
        if (!mTail)
            mHead = p;
        else
            *(hulk_intptr*)mTail = (hulk_intptr)p;
        mTail = p;
    }
    return true;
}

namespace fn_fa1df58d {

// 0x00261f90 FUN_00261f90 (139 B): equivalent/0x00261f90.cpp
// sym: ?InRange@fn_fa1df58d@@YA_NPAPAULink_261f90@1@MM@Z
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 19/20, incomplete)
// FUN_00261f90 @ 0x00261f90
// true when some item's value lies in the (possibly wrapping) interval (lo, hi]
bool __cdecl InRange(Link_261f90** head, float lo, float hi) {
    Link_261f90* l = *head;
    Item_261f90* item = l ? (Item_261f90*)((char*)l - 4) : 0;
    while (item) {
        float v = item->value;
        if (lo < hi) {
            if (lo < v && hi >= v) return true;
        } else if (lo > hi) {
            if (lo < v) {
                if (hi <= v) return true;
            } else if (hi >= v) {
                return true;
            }
        }
        l = item->link.next;
        item = l ? (Item_261f90*)((char*)l - 4) : 0;
    }
    return false;
}


// 0x00262020 FUN_00262020 (8 B): matches/0x00262020.cpp
// sym: ?FUN_00262020@fn_fa1df58d@@YIXPAX@Z
void __fastcall FUN_00262020(void* p) {
    FUN_00261d10(p);
}


// 0x00262030 FUN_00262030 (6 B): matches/0x00262030.cpp
// sym: _FUN_00262030
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_00262030() {
    return &(*(int*)&DAT_004e7ac0);
}


// 0x00262090 FUN_00262090 (72 B): matches/0x00262090.cpp
// sym: ?FUN_00262090@fn_fa1df58d@@YIPAUObj_262090@1@PAU21@@Z
// data: zeroData = DAT_003f335c
Obj_262090* __fastcall FUN_00262090(Obj_262090* p) {
    p->vt = (hulk_uintptr)&vtable_262090;
    p->s.init();
    p->a = FUN_002673a0("MySeqTrack", 0);
    p->b = FUN_002673a0((const char*)&(*(int*)&DAT_003f335c), 0);
    p->c[0] &= 0xfc;
    p->flags = (p->flags & 0xfffffc01) | 1;
    return p;
}

} // namespace fn_fa1df58d
