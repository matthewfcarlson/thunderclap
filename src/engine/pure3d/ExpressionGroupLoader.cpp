// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002aff60..0x002b0f40 (kind game, layer engine, confidence high), dominant class pure3d::ExpressionGroupLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "gen/content.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fd745641 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fd745641 {} using namespace fn_fd745641;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fd745641 {
extern "C" char DAT_0042e340[];
class ExpressionGroupLoader {
  public:
    hulk_intptr vf;
    int a;
    int b;
    int c;
    int d;
    ExpressionGroupLoader();
};
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
class Entity_2b0060 {
  public:
    Entity_2b0060();
    virtual void f0_00038290();
    char pad[0x0c];
};
class ExpressionGroup_2b0060 : public Entity_2b0060 {
  public:
    unsigned int *a, *a2;
    char pad2[8];
    unsigned int *b, *b2;
    unsigned int *c, *c2;
    ExpressionGroup_2b0060(unsigned int n);
    virtual void f1_000382a0();
};
} // namespace fn_fd745641
namespace pure3d {
class Entity_2b00f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    char pad[0x100];
};
}
namespace fn_fd745641 {
class Item_2b0100 {
  public:
    virtual void A() throw();
    virtual void B() throw();
};
extern "C" void __cdecl FreeMem(void*) throw();
template <class T> struct Vec_2b0100 {
    T* begin;
    T* end;
    T* cap;
    unsigned size() const { return end - begin; }
    T& operator[](unsigned i) { return begin[i]; }
    ~Vec_2b0100() throw() {
        if (begin)
            FreeMem(begin);
    }
};
template <int N> struct Buf_2b0100 {
    void* p;
    char pad[N - 4];
    ~Buf_2b0100() throw() {
        if (p)
            FreeMem(p);
    }
};
class ExpressionGroup_2b0100 : public pure3d::Entity {
  public:
    Vec_2b0100<Item_2b0100*> items;
    char pad2[0xc];
    Buf_2b0100<4> extra;
    virtual ~ExpressionGroup_2b0100() throw();
};
class A_2b0550 {
  public:
    virtual void f();
    virtual void g();
};
class B_2b0550 {
  public:
    A_2b0550* p;
    void run();
};
struct KeyTable_2b0870 {
    char pad0[0x10];
    int count;           // 0x10
    char pad14[4];
    float *keys;         // 0x18
};
struct TableSet {
    char pad0[0x10];
    KeyTable_2b0870 **tables;   // 0x10
};
struct Segment_2b0870 {
    char kind;           // 0x00: 1 = interpolate between two keys
    char pad1[3];
    int index;           // 0x04
    int index2;          // 0x08
    float weightLow;     // 0x0c
    float weightHigh;    // 0x10
    float scale;         // 0x14
};
class Curves_2b0870 {
public:
    char pad0[0x10];
    TableSet *set;       // 0x10
    float *values;       // 0x14
    char pad18[8];
    Segment_2b0870 *segments;   // 0x20
    Segment_2b0870 *segmentsEnd; // 0x24
    void FUN_002b0870();
};
struct Item_2b0a70 { unsigned char mode; char pad[3]; unsigned first; unsigned second; float x; float y; float z; };
struct Mapping { char pad[20]; unsigned* values; };
struct Entry_2b0a70 { Item_2b0a70* item; Mapping* mapping; };
struct List_2b0a70 { Entry_2b0a70* begin; Entry_2b0a70* end; unsigned capacity; float scale; bool FUN_002b07d0(); };
struct Output_2b0a70 { void FUN_002d0e20(unsigned id, float value); };
union FloatBits_2b0a70 { float f; unsigned bits; };
struct Sink_2b0ba0 {
    void FUN_002d0e20(void *slot, float value);
};
struct Channel {
    char pad[0x14];
    void **slots;
};
struct Rec_2b0ba0 {
    char active;
    char pad0[3];
    int slotA;
    int slotB;
    float valueA;
    float valueB;
    float valueC;
};
struct Table_2b0ba0 {
    char pad[0x10];
    Channel **channels;
};
struct Blender_2b0ba0 {
    char pad0[0x10];
    Table_2b0ba0 *table;
    char pad1[0x20 - 0x14];
    Rec_2b0ba0 *begin;
    Rec_2b0ba0 *end;

    void FUN_002b0ba0(Sink_2b0ba0 *sink);
};
struct Entry { char data[16]; };
struct Owner {
 char padding[0x2c];
 Entry* begin;
 Entry* end;
 void FUN_002b0870();
 void FUN_002b0ba0(void*);
 void FUN_002b0cd0(void*);
};
struct Other {  };
void __cdecl FUN_002b0a70(Entry*, void*);
class A_2b0d60 {
  public:
    virtual void f();
    virtual void g();
};
class B_2b0d60 {
  public:
    A_2b0d60* p;
    void run();
};
typedef unsigned int U_2b0de0;
struct Record { unsigned int value[6]; };
struct Elem_2b0e90 {
    int a;
    int b;
};
struct Vec_2b0e90 {
    Elem_2b0e90 *begin;
    Elem_2b0e90 *end;
    Vec_2b0e90 *FUN_002b0e90(const Vec_2b0e90 *src);
};
typedef unsigned int u32_2b0f20;


// 0x002aff60 FUN_002aff60 (27 B): matches/0x002aff60.cpp
// sym: ??0ExpressionGroupLoader@fn_fd745641@@QAE@XZ
ExpressionGroupLoader::ExpressionGroupLoader() {
    a = 0;
    b = 0x21001;
    c = 0;
    d = 0;
    vf = ((hulk_intptr)DAT_0042e340);
}

} // namespace fn_fd745641

// 0x002aff80 pure3d::ExpressionGroupLoader::vfunc_2 (31 B): matches/0x002aff80.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002aff80@@UAEPAV123@E@Z
namespace fn_002aff80 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2aff80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2aff80 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002aff80

namespace fn_fd745641 {

// 0x002b0060 FUN_002b0060 (121 B): matches/0x002b0060.cpp
// sym: ??0ExpressionGroup_2b0060@fn_fd745641@@QAE@I@Z
ExpressionGroup_2b0060::ExpressionGroup_2b0060(unsigned int n) {
    if (n > 0 && (a = (unsigned int*)FUN_0008d6d0(n * 4)) != 0) {
        a2 = a + n;
    } else {
        a = 0;
        a2 = 0;
    }
    b = 0;
    b2 = 0;
    if (n > 0 && (c = (unsigned int*)FUN_0008d6d0(n * 4)) != 0) {
        c2 = c + n;
    } else {
        c = 0;
        c2 = 0;
    }
}

} // namespace fn_fd745641

// 0x002b00e0 pure3d::ExpressionGroup::vfunc_3 (3 B): matches/0x002b00e0.cpp
// sym: ?vfunc_3@ExpressionGroup@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::ExpressionGroup::vfunc_3() {
    return (bool)(0);
}


// 0x002b00f0 pure3d::ExpressionGroup::vfunc_4 (3 B): matches/0x002b00f0.cpp
// sym: ?vfunc_4@ExpressionGroup@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::ExpressionGroup::vfunc_4() {
    return (void*)(this);
}

namespace fn_fd745641 {

// 0x002b0100 FUN_002b0100 (112 B): matches/0x002b0100.cpp
// sym: ??1ExpressionGroup_2b0100@fn_fd745641@@UAE@XZ
ExpressionGroup_2b0100::~ExpressionGroup_2b0100() throw() {
    for (unsigned i = 0; i < items.size(); i++) {
        if (items[i]) {
            items[i]->B();
            items[i] = 0;
        }
    }
}

} // namespace fn_fd745641

// 0x002b0170 pure3d::ExpressionGroupLoader::vfunc_5 (475 B): equivalent/0x002b0170.cpp [wrapped: conflict: ExpressionGroupLoader; content::ObjectLoader; pure3d::ExpressionLoader]
// sym: ?vfunc_5@ExpressionGroupLoader@fn_002b0170@@UAE_KPAPAUExprGroup_2b0170@2@PA_KPAUReader@2@H@Z @d085d60aa731 @w4c94131cbe2d
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002b0170 {
// STATUS: equivalent (tools/equiv.py level 3: 87 inputs, branch coverage 14/14)
// pure3d::ExpressionGroupLoader::vfunc_5 @ 0x002b0170
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Item_2b0170 {
    virtual void v0();
};

struct StrField_2b0170 {
    int a, b;
    void FUN_0027b040(const char *s);
};

struct ExprGroup_2b0170 {
    char pad0[8];
    StrField_2b0170 name;
    Item_2b0170 **items;
    char pad1[0x20 - 0x14];
    unsigned __int64 hash;
    int *vals;
    ExprGroup_2b0170 *FUN_002b0060(int count);
};

struct Stream {
    bool FUN_002647e0(void *dst, int a, int b, int c);
};

namespace content {
class ObjectLoader {
public:
    virtual void v0();
};
}

struct Reader;

namespace pure3d {
class ExpressionLoader : public content::ObjectLoader {
public:
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual unsigned __int64 v5(Item_2b0170 **out, unsigned __int64 *hash, Reader *r, int flag);
};
}

struct Reader {
    char pad0[0x280];
    int depth;
    Stream *stream;
    bool FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
    void *FUN_00266c30();
};

struct Registry_2b0170 {
    content::ObjectLoader *FUN_00265310(void *key);
};


void *FUN_00263ea0(unsigned int size);

class ExpressionGroupLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual unsigned __int64 vfunc_5(ExprGroup_2b0170 **out, unsigned __int64 *outHash, Reader *r, int flag);
};

unsigned __int64 ExpressionGroupLoader::vfunc_5(ExprGroup_2b0170 **out, unsigned __int64 *outHash, Reader *r, int flag)
{
    struct Frame {
        char pad[3];
        unsigned char len;
        union {
            int v;
            Item_2b0170 *item;
        } u;
        unsigned __int64 x;
        char buf1[0x100];
        char buf2[0x100];
    } fr;

    r->stream->FUN_002647e0(&fr.u.v, 1, 4, 1);
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n1 = fr.len;
    r->stream->FUN_002647e0(fr.buf1, n1, 1, 1);
    fr.buf1[n1] = 0;
    r->stream->FUN_002647e0(&fr.len, 1, 1, 1);
    unsigned int n2 = fr.len;
    r->stream->FUN_002647e0(fr.buf2, n2, 1, 1);
    fr.buf2[n2] = 0;
    r->stream->FUN_002647e0(&fr.u.v, 1, 4, 1);

    void *mem = FUN_00263ea0(0x38);
    int count = fr.u.v;
    ExprGroup_2b0170 *g = 0;
    if (mem)
        g = ((ExprGroup_2b0170 *)mem)->FUN_002b0060(count);
    g->name.FUN_0027b040(fr.buf1);
    g->hash = FUN_0027b020(fr.buf2);
    for (int i = 0; i < count; i++) {
        r->stream->FUN_002647e0(&fr.u.v, 1, 4, 1);
        g->vals[i] = fr.u.v;
    }

    if (r->FUN_002669f0()) {
        unsigned int off = 0;
        do {
            if (r->FUN_00266a30() == 0x21000) {
                // MSVC evaluates the argument before loading the registry
                void *loaderKey = r->FUN_00266c30();
                pure3d::ExpressionLoader *el = dynamic_cast<pure3d::ExpressionLoader *>((*(Registry_2b0170**)&DAT_00527c58)->FUN_00265310(loaderKey));
                if (el != 0) {
                    fr.u.item = 0;
                    el->v5(&fr.u.item, &fr.x, r, 0);
                    fr.u.item->v0();
                    *(Item_2b0170 **)((char *)g->items + off) = fr.u.item;
                    off += 4;
                }
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }
    *out = g;
    unsigned __int64 h = FUN_002672f0(fr.buf1, 0, 0);
    *outHash = h;
    return h;
}
} // namespace fn_002b0170
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x002b0350 pure3d::ExpressionGroup::vfunc_2 (30 B): matches/0x002b0350.cpp
// sym: ??_GExpressionGroup@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::ExpressionGroup::~ExpressionGroup() {}

namespace fn_fd745641 {

// 0x002b0550 FUN_002b0550 (22 B): matches/0x002b0550.cpp
// sym: ?run@B_2b0550@fn_fd745641@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_2b0550::run() {
    if (p)
        p->g();
    p = 0;
}

} // namespace fn_fd745641

// 0x002b07d0 FUN_002b07d0 (78 B): equivalent/0x002b07d0.cpp [wrapped: code differs from its standalone build]
// sym: ?FUN_002b07d0@Holder@fn_002b07d0@@QAE_NXZ @90a4016af869 @w9522312ed1b6
namespace fn_002b07d0 {
// STATUS: equivalent (tools/equiv.py level 3: 637 inputs, branch coverage 6/6)
// FUN_002b07d0 @ 0x002b07d0
struct Item { char pad[0x14]; float value; }; struct Entry { Item* item; int other; }; struct Holder { Entry* begin; Entry* end; int unused; float reciprocal; bool FUN_002b07d0(); }; bool Holder::FUN_002b07d0() { float sum = 0.0f; hulk_intptr count = ((hulk_intptr)end - (hulk_intptr)begin) >> 3; if (count == 0) return false; Entry* it = begin; do { sum += it->item->value; ++it; --count; } while (count != 0); if (sum < 0.01f) return false; reciprocal = 1.0f / sum; return true; }
} // namespace fn_002b07d0

namespace fn_fd745641 {

// 0x002b0870 FUN_002b0870 (436 B): equivalent/0x002b0870.cpp
// sym: ?FUN_002b0870@Curves_2b0870@fn_fd745641@@QAEXXZ @8ffb0de07afb @wb6b8998dcb6b
// STATUS: equivalent (tools/equiv.py level 3: 12 inputs, branch coverage 18/20, incomplete)
// FUN_002b0870 @ 0x002b0870
void Curves_2b0870::FUN_002b0870()
{
    if ((segmentsEnd - segments) == 0)
        return;

    unsigned int i = 0;
    int byteOffset = 0;
    do {
        KeyTable_2b0870 *tbl = set->tables[i];
        Segment_2b0870 *seg = (Segment_2b0870 *)((char *)segments + byteOffset);
        float x = values[i];
        int last = tbl->count - 1;

        if (last == 0) {
            seg->kind = 0;
            seg->index = 0;
            seg->scale = (float)fabs(x / tbl->keys[0]);
        } else {
            float *keys = tbl->keys;
            int k = -1;
            if (x > keys[0]) {
                for (;;) {
                    k++;
                    if (k == last)
                        break;
                    if (!(x > keys[k + 1]))
                        break;
                }
            }
            if (k == -1) {
                seg->kind = 0;
                seg->index = 0;
                seg->scale = (float)fabs(x / tbl->keys[0]);
            } else if (k == last) {
                seg->kind = 0;
                seg->index = last;
                seg->scale = (float)fabs(x / tbl->keys[last]);
            } else {
                float a = keys[k];
                float b = keys[k + 1];
                if (a * b < 0.0f) {
                    int neg = (x < 0.0f) ? 1 : 0;
                    int pick = (k + neg == 0) ? 1 : 0;
                    seg->index = pick;
                    seg->kind = 0;
                    seg->scale = (float)fabs(x / tbl->keys[pick]);
                } else {
                    seg->index = k;
                    seg->kind = 1;
                    seg->index2 = k + 1;
                    seg->scale = 1.0f;
                    seg->weightLow = 1.0f - (x - a) / (b - a);
                    seg->weightHigh = (x - a) / (b - a);
                }
            }
        }
        byteOffset += 0x18;
        i++;
    } while (i < (unsigned int)(segmentsEnd - segments));
}


// 0x002b0a70 FUN_002b0a70 (293 B): equivalent/0x002b0a70.cpp
// sym: ?target@fn_fd745641@@YAXPAUList_2b0a70@1@PAUOutput_2b0a70@1@@Z @0624c8160ba2 @w042d9483ba53
// STATUS: equivalent (tools/equiv.py level 3: 42 inputs, branch coverage 14/14)
// FUN_002b0a70 @ 0x002b0a70
void __cdecl target(List_2b0a70* list, Output_2b0a70* output) {
 if (!list->FUN_002b07d0()) return;
 Entry_2b0a70* entries = list->begin;
 unsigned count = (unsigned)(list->end - entries);
 for (unsigned i=0; i<count; ++i) {
  Item_2b0a70* item = entries[i].item;
  FloatBits_2b0a70 value, magnitude;
  if (item->mode) {
   value.f = item->x * list->scale;
   magnitude.f = value.f; magnitude.bits &= 0x7fffffff;
   if (!(magnitude.f < 0.01f)) output->FUN_002d0e20(entries[i].mapping->values[item->first], value.f);
   value.f = item->y * list->scale;
   magnitude.f = value.f; magnitude.bits &= 0x7fffffff;
   if (!(magnitude.f < 0.01f)) output->FUN_002d0e20(entries[i].mapping->values[item->second], value.f);
  } else {
   magnitude.f = item->z; magnitude.bits &= 0x7fffffff;
   value.f = item->z * (magnitude.f * list->scale);
   magnitude.f = value.f; magnitude.bits &= 0x7fffffff;
   if (!(magnitude.f < 0.01f)) output->FUN_002d0e20(entries[i].mapping->values[item->first], value.f);
  }
  entries = list->begin;
  count = (unsigned)(list->end - entries);
 }
}


// 0x002b0ba0 FUN_002b0ba0 (301 B): equivalent/0x002b0ba0.cpp
// sym: ?FUN_002b0ba0@Blender_2b0ba0@fn_fd745641@@QAEXPAUSink_2b0ba0@2@@Z @180c9936ae5c @w6b75d7beab96
// STATUS: equivalent (tools/equiv.py level 3: 24 inputs, branch coverage 12/12)
// FUN_002b0ba0 @ 0x002b0ba0
void Blender_2b0ba0::FUN_002b0ba0(Sink_2b0ba0 *sink)
{
    for (unsigned i = 0; i < (unsigned)(end - begin); i++) {
        Channel *ch = table->channels[i];
        Rec_2b0ba0 *r = &begin[i];
        if (r->active) {
            float v = r->valueA;
            if (!((float)fabs(v) < 0.01f))
                sink->FUN_002d0e20(ch->slots[r->slotA], v);
            v = r->valueB;
            if (!((float)fabs(v) < 0.01f))
                sink->FUN_002d0e20(ch->slots[r->slotB], v);
        } else {
            float v = r->valueC;
            if (!((float)fabs(v) < 0.01f))
                sink->FUN_002d0e20(ch->slots[r->slotA], v);
        }
    }
}


// 0x002b0cd0 FUN_002b0cd0 (87 B): equivalent/0x002b0cd0.cpp
// sym: ?FUN_002b0cd0@Owner@fn_fd745641@@QAEXPAX@Z @577de1f840f7 @w397ca382f064
// STATUS: equivalent (tools/equiv.py level 3: 2247 inputs, branch coverage 4/4)
// FUN_002b0cd0 @ 0x002b0cd0
void Owner::FUN_002b0cd0(void* arg) {
 FUN_002b0870();
 ((owners::X_2d0c80 *)(((Other*)arg)))->FUN_002d0c80();
 FUN_002b0ba0(arg);
 unsigned int i = 0;
 if (((int)((char*)end - (char*)begin) >> 4) != 0) {
  do {
   FUN_002b0a70((Entry*)((char*)begin + i * 16), arg);
   ++i;
  } while (i < (unsigned int)((int)((char*)end - (char*)begin) >> 4));
 }
}


// 0x002b0d60 FUN_002b0d60 (22 B): matches/0x002b0d60.cpp
// sym: ?run@B_2b0d60@fn_fd745641@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_2b0d60::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x002b0de0 FUN_002b0de0 (46 B): matches/0x002b0de0.cpp
// sym: ?FUN_002b0de0@fn_fd745641@@YAPAIPAII0@Z
U_2b0de0* __cdecl FUN_002b0de0(U_2b0de0* dst, unsigned int count, U_2b0de0* src) {
    if (count) {
        for (; count; --count) {
            if (dst) {
                dst[0] = src[0];
                dst[1] = src[1];
            }
            dst += 2;
        }
        return dst;
    }
    return dst;
}


// 0x002b0e10 FUN_002b0e10 (40 B): matches/0x002b0e10.cpp
// sym: ?copyWords@fn_fd745641@@YAPAHPAHHPBH@Z
// Same code shape as 0x002ab530 (propagated; names are from that function)
int* copyWords(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}


// 0x002b0e40 FUN_002b0e40 (78 B): equivalent/0x002b0e40.cpp
// sym: _FUN_002b0e40 @8cbb3fca80e7 @wdc3110b3f03f
// STATUS: equivalent (tools/equiv.py level 3: 121 inputs, branch coverage 6/6)
// FUN_002b0e40 @ 0x002b0e40
extern "C" Record* __cdecl FUN_002b0e40(Record* destination, int count, const Record* source)
{
    if (count == 0) return destination;
    do {
        if (destination != 0) {
            destination->value[0] = source->value[0];
            destination->value[1] = source->value[1];
            destination->value[2] = source->value[2];
            destination->value[3] = source->value[3];
            destination->value[4] = source->value[4];
            destination->value[5] = source->value[5];
        }
        ++destination;
        --count;
    } while (count != 0);
    return destination;
}


// 0x002b0e90 FUN_002b0e90 (116 B): equivalent/0x002b0e90.cpp
// sym: ?FUN_002b0e90@Vec_2b0e90@fn_fd745641@@QAEPAU12@PBU12@@Z @1bfde5b849ad @w932d798a6b2f
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002b0e90 @ 0x002b0e90
Vec_2b0e90 *Vec_2b0e90::FUN_002b0e90(const Vec_2b0e90 *src)
{
    hulk_intptr n = src->end - src->begin;
    if (n != 0) {
        Elem_2b0e90 *dst = (Elem_2b0e90 *)FUN_0008d6d0(n * sizeof(Elem_2b0e90));
        begin = dst;
        if (dst != 0) {
            end = dst + n;
            const Elem_2b0e90 *s = src->begin;
            for (hulk_intptr k = src->end - s; k != 0; k--) {
                if (dst != 0) {
                    dst->a = s->a;
                    dst->b = s->b;
                }
                s++;
                dst++;
            }
            return this;
        }
    }
    begin = 0;
    end = 0;
    return this;
}

} // namespace fn_fd745641

// 0x002b0f20 content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup>::vfunc_0 (30 B): matches/0x002b0f20.cpp
// sym: ?vfunc_0@?$DynamicCaster@VExpressionGroup@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    Cast((hulk_uintptr)p, 0, &type_refcount, &type_animation, 0);
}

