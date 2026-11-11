// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027b570..0x0027ca80 (kind game, layer engine, confidence high), dominant class pure3d::SkeletonLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f8d8f61c {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f8d8f61c {} using namespace fn_f8d8f61c;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f8d8f61c {
extern void __cdecl FUN_0008d340(void*);
struct ResourceInfo {
 char pad0[16];
 unsigned int count;
 char pad1[48];
 char* begin;
 char* end;
};
struct Owner_27b570 {
 ResourceInfo* info;
 void* buffer;
 void** entries;
 unsigned int extraCount;
 void** extras;
 void** records;
 void cleanup();
};
struct ThisCall_0027b570 {
    void FUN_0027b570();
};
extern void thunk_FUN_00267090(CCollisionAction*);
struct Record_27b670 {
    int vptr;
    int pad4;
    unsigned int keyLo;     // 0x8
    unsigned int keyHi;     // 0xc
    int pad10[2];
};
class RecordTable_27b670 {
public:
    char pad0[0x34];
    Record_27b670 *begin;          // 0x34
    Record_27b670 *end;            // 0x38

    Record_27b670 *FUN_0027b670(unsigned int keyLo, unsigned int keyHi);
};
struct Entry_27b710 {
    char pad0[8];
    unsigned int a;
    unsigned int b;
    char pad10[0x28 - 0x10];
};
struct Table_27b710 {
    char pad0[0x44];
    Entry_27b710* begin;
    Entry_27b710* end;
    Entry_27b710* Find(unsigned int a, unsigned int b);
};
extern "C" char DAT_0042c1cc[];
class SkeletonLoader {
  public:
    void* vf;
    int a;
    int b;
    int c;
    int d;
    unsigned char e;
    SkeletonLoader();
};
class Item_27ba70 {
  public:
    virtual void release(int);
    int x;
    int a, b, c;
    int tail;
};
class List_27ba70 {
  public:
    Item_27ba70* begin;
    Item_27ba70* end;
    void erase(Item_27ba70*, Item_27ba70*);
};
typedef unsigned int u32_27bb30;
struct Partition {
    hulk_uintptr vptr;
    u32_27bb30 pad;
    u32_27bb30 a;
    u32_27bb30 b;
    u32_27bb30 c;
    u32_27bb30 pad2;
};
struct Source_27bb30 {
    char pad[8];
    u32_27bb30 a;
    u32_27bb30 b;
    u32_27bb30 c;
};
extern void* hulk_at_0042c204[];
void Free_0008d330(void*) throw();
void Free2_0008d340(void*) throw();
struct E28 {
    virtual ~E28();
    char p[0x24];
};
struct E18 {
    virtual ~E18();
    char p[0x14];
};
struct M2c {
    void Fin_0027b570() throw();
};
class Entity_27bc90 {
  public:
    void* vptr;
    ~Entity_27bc90() throw();
};
class Skeleton_27bc90 : public Entity_27bc90 {
  public:
    char pad[0x2c - 4];
    M2c* m2c;
    void* m30;
    E18* m34;
    E18* m38;
    char pad2[0x44 - 0x3c];
    E28* m44;
    E28* m48;
    ~Skeleton_27bc90() throw();
};
} // namespace fn_f8d8f61c
namespace pure3d {
class Entity_27bd60 {
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
namespace fn_f8d8f61c {
struct Elem_27bd70 {
    char data[0x18];
};
class ElemVector {
public:
    Elem_27bd70 *first;             // 0x00
    Elem_27bd70 *last;              // 0x04
    Elem_27bd70 *capEnd;            // 0x08
    void FUN_0027ba70(Elem_27bd70 *from, Elem_27bd70 *to);
    void FUN_0027bad0(Elem_27bd70 *at, hulk_intptr count);
    void FUN_0027bd70(unsigned int newSize, hulk_intptr fill);
};
void __cdecl FUN_0027bb30(Elem_27bd70 *at, hulk_intptr count, int fill);
void* __cdecl FUN_0008d6d0(unsigned int size);
void __cdecl FUN_0027bc30(void* data, unsigned int count, int value);
struct Partition_27beb0 {
    virtual void unused();
    char pad[12];
    int value;
    Partition_27beb0() : value(0) {}
};
struct Limb : Partition_27beb0 {
    char extra[20];
    virtual void other();
};
struct Wrapper {
    void FUN_0027beb0(void* arg);
};
struct Stream_27c720 {
};
struct Reader_27c720 {
    char pad[0x284];
    Stream_27c720* stream;
    char FUN_002669f0();
    int FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
};
struct NameField_27c720 {
};
struct Skeleton_27c720 {
    char pad0[8];
    NameField_27c720 name;
    char pad9[0x18 - 9];
    char* matrices;
    char pad1c[8];
    unsigned __int64* hashes;
    unsigned short* parents;
    Skeleton_27c720* FUN_0027bee0(int nJoints, int a, int b);
    void FUN_0027b270();
};
void* FUN_00263ea0(unsigned int size);
void FUN_0028fcc0(const char* fmt, const char* name);
struct Frame_27c720 {
    char pad0[3];
    unsigned char len;
    int w10;
    int w14;
    int w18;
    int w1c;
    int w20;
    int w24;
    int w28;
    int w2c;
    char name[0x100];
    char jointName[0x100];
};


// 0x0027b570 FUN_0027b570 (220 B): equivalent/0x0027b570.cpp
// sym: ?cleanup@Owner_27b570@fn_f8d8f61c@@QAEXXZ @089098bc3486 @w06f77d5b9f04
// STATUS: equivalent (tools/equiv.py level 3: 148 inputs, branch coverage 14/14)
// FUN_0027b570 @ 0x0027b570
void Owner_27b570::cleanup() {
 if (!info) return;
 unsigned int i;
 for (i=0; i<info->count; ++i) FUN_0008d340(entries[i]);
 for (i=0; i<extraCount; ++i) FUN_0008d340(extras[i]);
 for (i=0; i<(unsigned int)((int)(info->end-info->begin)/40); ++i) FUN_0008d340(records[i]);
 FUN_0008d340(buffer);
 FUN_0008d340(entries);
 FUN_0008d340(extras);
 FUN_0008d340(records);
}


// 0x0027b650 FUN_0027b650 (30 B): matches/0x0027b650.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f8d8f61c@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_0027b570*)(this))->FUN_0027b570();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x0027b670 FUN_0027b670 (147 B): equivalent/0x0027b670.cpp
// sym: ?FUN_0027b670@RecordTable_27b670@fn_f8d8f61c@@QAEPAURecord_27b670@2@II@Z @381005c18e94 @wf177df6d1ed6
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 14/14)
// FUN_0027b670 @ 0x0027b670
Record_27b670 *RecordTable_27b670::FUN_0027b670(unsigned int keyLo, unsigned int keyHi)
{
    if ((keyLo | keyHi) == 0)
        return ((Record_27b670*)&DAT_004ce400);
    if (keyLo == (*(unsigned int*)&DAT_004ce408) && keyHi == (*(unsigned int*)&DAT_004ce40c))
        return ((Record_27b670*)&DAT_004ce400);

    Record_27b670 *first = begin;
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        if (first[i].keyLo == keyLo && first[i].keyHi == keyHi)
            return &first[i];
    }
    return 0;
}


// 0x0027b710 FUN_0027b710 (118 B): equivalent/0x0027b710.cpp
// sym: ?Find@Table_27b710@fn_f8d8f61c@@QAEPAUEntry_27b710@2@II@Z @da972b32830c @wdea6a72ae01c
// STATUS: equivalent (tools/equiv.py level 3: 55 inputs, branch coverage 8/8)
// FUN_0027b710 @ 0x0027b710
Entry_27b710* Table_27b710::Find(unsigned int a, unsigned int b) {
    Entry_27b710* first = begin;
    for (unsigned int i = 0; i < (unsigned int)(end - begin); ++i) {
        Entry_27b710* e = &first[i];
        if (e->a == a && e->b == b)
            return e;
    }
    return 0;
}

} // namespace fn_f8d8f61c

// 0x0027b8f0 FUN_0027b8f0 (138 B): equivalent/0x0027b8f0.cpp [wrapped: conflict: FUN_0008d6d0]
// sym: _FUN_0027b8f0 @cc24da305039 @w28913b71a714
namespace fn_0027b8f0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 3/4, incomplete)
// FUN_0027b8f0 @ 0x0027b8f0
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

struct Bitset { unsigned int bits; unsigned int words[17]; };
extern "C++" __declspec(nothrow) Bitset* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void FUN_0027b8f0(){
  if ((*(unsigned int*)&DAT_0052c288) == 0) {
    long long hash = FUN_002672f0("root", 0, 0);
    (*(unsigned int*)&DAT_004ce408) = (unsigned int)hash;
    (*(unsigned int*)&DAT_004ce40c) = (unsigned int)(hash >> 32);
    Bitset* b = FUN_0008d6d0((int)sizeof(Bitset));
    b->bits = 0x201;
    for (int i = 0; i < 17; i++) b->words[i] = 0;
    (*(Bitset**)&DAT_004ce410) = b;
    unsigned int n = (b->bits + 0x1f) >> 5;
    for (unsigned int i = 0; i < n; i++) b->words[i] = 0xffffffff;
  }
  (*(unsigned int*)&DAT_0052c288)++;
}
} // namespace fn_0027b8f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f8d8f61c {

// 0x0027b980 FUN_0027b980 (31 B): matches/0x0027b980.cpp
// sym: ??0SkeletonLoader@fn_f8d8f61c@@QAE@XZ
SkeletonLoader::SkeletonLoader() {
    a = 0;
    b = 0x23000;
    c = 0;
    d = 0;
    vf = (void*)((hulk_intptr)DAT_0042c1cc);
    e = 1;
}

} // namespace fn_f8d8f61c

// 0x0027b9a0 pure3d::SkeletonLoader::vfunc_2 (31 B): matches/0x0027b9a0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0027b9a0@@UAEPAV123@E@Z
namespace fn_0027b9a0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_27b9a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_27b9a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0027b9a0


// 0x0027b9e0 pure3d::LegacySkeletonLoader::vfunc_2 (31 B): matches/0x0027b9e0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0027b9e0@@UAEPAV123@E@Z
namespace fn_0027b9e0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_27b9e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_27b9e0 {
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
} // namespace fn_0027b9e0

namespace fn_f8d8f61c {

// 0x0027ba70 FUN_0027ba70 (96 B): matches/0x0027ba70.cpp
// sym: ?erase@List_27ba70@fn_f8d8f61c@@QAEXPAVItem_27ba70@2@0@Z
void List_27ba70::erase(Item_27ba70* first, Item_27ba70* last) {
    Item_27ba70* e = end;
    if (last != e) {
        hulk_intptr delta = (char*)last - (char*)first;
        do {
            first->a = *(int*)((char*)first + delta + 8);
            first->b = *(int*)((char*)first + delta + 12);
            first->c = last->c;
            ++first;
            ++last;
        } while (last != e);
    }
    Item_27ba70* old = end;
    for (Item_27ba70* p = first; p != old; ++p)
        p->release(0);
    end = first;
}

} // namespace fn_f8d8f61c

// 0x0027bad0 FUN_0027bad0 (82 B): matches/0x0027bad0.cpp [wrapped: compile error in a shared declaration (C2039)]
// sym: ?Resize@Owner_27bad0@fn_0027bad0@@QAEXPAVPartition@2@H@Z
inline void* operator new(size_t, void* p) {
    return p;
}
namespace fn_0027bad0 {

class Partition {
  public:
    Partition() {}
    virtual void Destroy(int);
    char pad4[4];
    int a;
    int b;
    int c;
    int d;
};
class Owner_27bad0 {
  public:
    char pad0[4];
    Partition* mEnd;
    void Resize(Partition* stop, int count);
};
void Owner_27bad0::Resize(Partition* stop, int count) {
    Partition* src = mEnd;
    Partition* dst = src + count;
    mEnd = dst;
    if (src != stop) {
        do {
            src = src - 1;
            dst = dst - 1;
            if (dst) {
                new (dst) Partition();
                dst->a = src->a;
                dst->b = src->b;
                dst->c = src->c;
            }
            src->Destroy(0);
        } while (src != stop);
    }
}
} // namespace fn_0027bad0

namespace fn_f8d8f61c {

// 0x0027bb30 FUN_0027bb30 (60 B): matches/0x0027bb30.cpp
// sym: ?f@fn_f8d8f61c@@YAPAUPartition@1@PAU21@HPAUSource_27bb30@1@@Z
Partition* f(Partition* out, int count, Source_27bb30* src) {
    while (count != 0) {
        if (out) {
            out->vptr = ((hulk_intptr)DAT_0042c1b4);
            out->a = src->a;
            out->b = src->b;
            out->c = src->c;
        }
        out = (Partition*)((char*)out + 0x18);
        --count;
    }
    return out;
}

} // namespace fn_f8d8f61c

// 0x0027bc30 FUN_0027bc30 (84 B): matches/0x0027bc30.cpp [wrapped: compile error in a shared declaration (C2039)]
// sym: ?FUN_0027bc30@fn_0027bc30@@YAPAVLimb@1@PAV21@HPBV21@@Z
namespace fn_0027bc30 {
class Partition {
  public:
    virtual void f();
    int a;
    int x, y, z;
    Partition(const Partition& p) : x(p.x), y(p.y), z(p.z) {}
};
class Limb : public Partition {
  public:
    virtual void f();
    int b;
    int u, v, w;
    int tail;
    Limb(const Limb& p) : Partition(p), u(p.u), v(p.v), w(p.w) {}
};
Limb* __cdecl FUN_0027bc30(Limb* dest, int count, const Limb* src) {
    if (count) {
        int n = count;
        do {
            if (dest)
                dest->Limb::Limb(*src);
            ++dest;
        } while (--n);
        return dest;
    }
    return dest;
}
} // namespace fn_0027bc30

namespace fn_f8d8f61c {

// 0x0027bc90 FUN_0027bc90 (177 B): matches/0x0027bc90.cpp
// sym: ??1Skeleton_27bc90@fn_f8d8f61c@@QAE@XZ
// data: g_cnt = DAT_0052c288, g_shared = DAT_004ce410
Skeleton_27bc90::~Skeleton_27bc90() throw() {
    vptr = hulk_at_0042c204;
    if (--(*(int*)&DAT_0052c288) == 0) {
        if (DAT_004ce410)
            Free_0008d330(DAT_004ce410);
        DAT_004ce410 = 0;
    }
    Free2_0008d340(m30);
    M2c* p = m2c;
    if (p) {
        p->Fin_0027b570();
        Free_0008d330(p);
    }
    E28* s = m44;
    if (s) {
        E28* e = m48;
        for (; s != e; s++)
            s->~E28();
        Free2_0008d340(m44);
    }
    E18* u = m38;
    E18* t = m34;
    for (; t != u; t++)
        t->~E18();
    E18* b = m34;
    m38 = b;
    if (b)
        Free2_0008d340(b);
}

} // namespace fn_f8d8f61c

// 0x0027bd50 pure3d::Skeleton::vfunc_3 (3 B): matches/0x0027bd50.cpp
// sym: ?vfunc_3@Skeleton@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::Skeleton::vfunc_3() {
    return (bool)(0);
}


// 0x0027bd60 pure3d::Skeleton::vfunc_4 (3 B): matches/0x0027bd60.cpp
// sym: ?vfunc_4@Skeleton@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::Skeleton::vfunc_4() {
    return (void*)(this);
}

namespace fn_f8d8f61c {

// 0x0027bd70 FUN_0027bd70 (143 B): equivalent/0x0027bd70.cpp
// sym: ?FUN_0027bd70@ElemVector@fn_f8d8f61c@@QAEXIH@Z @3766d0b96756 @wfd2f3b71f8c5
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_0027bd70 @ 0x0027bd70
void ElemVector::FUN_0027bd70(unsigned int newSize, hulk_intptr fill) {
    if (first == 0)
        ((owners::Buffer_27b3b0 *)this)->FUN_0027b3b0((int)newSize);
    Elem_27bd70 *end = last;
    Elem_27bd70 *begin = first;
    hulk_uintptr size = end - begin;
    if (newSize > size) {
        hulk_intptr extra = newSize - size;
        if (end + extra <= capEnd) {
            FUN_0027bad0(end, extra);
            FUN_0027bb30(end, extra, fill);
        }
    } else if (newSize < size) {
        FUN_0027ba70(begin + newSize, end);
    }
}

} // namespace fn_f8d8f61c

// 0x0027be00 FUN_0027be00 (94 B): equivalent/0x0027be00.cpp
// sym: ?FUN_0027be00@Buffer_27be00@owners@@QAE_NIH@Z @c6af926935b5 @w601ec501dc35
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_0027be00 @ 0x0027be00
bool owners::Buffer_27be00::FUN_0027be00(hulk_uintptr count, hulk_intptr value) { if (begin) return false; if (((unsigned int)count)) { void* data = FUN_0008d6d0(((unsigned int)count) * 40); begin = data; if (data) { end = (char*)data + ((unsigned int)count) * 40; FUN_0027bc30(data, ((unsigned int)count), ((int)value)); return true; } } begin = 0; end = 0; return false; }


// 0x0027be60 pure3d::Skeleton::vfunc_2 (30 B): matches/0x0027be60.cpp
// sym: ??_GSkeleton@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::Skeleton::~Skeleton() {}


// 0x0027be80 FUN_0027be80 (39 B): matches/0x0027be80.cpp [wrapped: conflict: pure3d::Skeleton]
// sym: ?FUN_0027be80@Handler@fn_0027be80@@QAEXH@Z
namespace fn_0027be80 {
namespace pure3d {
struct Skeleton {
    struct Partition {
        virtual void Destroy();
        char reserved[12];
        int value;
        char tail[4];
    };
};
} // namespace pure3d
struct Handler {
    void FUN_0027bd70(int, pure3d::Skeleton::Partition*);
    void FUN_0027be80(int);
};
void Handler::FUN_0027be80(int arg) {
    pure3d::Skeleton::Partition partition;
    partition.value = 0;
    FUN_0027bd70(arg, &partition);
}
} // namespace fn_0027be80

namespace fn_f8d8f61c {

// 0x0027beb0 FUN_0027beb0 (39 B): matches/0x0027beb0.cpp
// sym: ?FUN_0027beb0@Wrapper@fn_f8d8f61c@@QAEXPAX@Z
void Wrapper::FUN_0027beb0(void* arg) {
    Limb limb;
    ((owners::Buffer_27be00 *)this)->FUN_0027be00((hulk_uintptr)arg, (hulk_intptr)(Limb *)(&limb));
}

} // namespace fn_f8d8f61c

// 0x0027bee0 FUN_0027bee0 (408 B): equivalent/0x0027bee0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0Skeleton@pure3d@fn_0027bee0@@QAE@HII@Z @9b362a7058d6 @w739f066288ef
namespace fn_0027bee0 {
// STATUS: equivalent (tools/equiv.py level 3: 9 inputs, branch coverage 15/16, incomplete)
// FUN_0027bee0 @ 0x0027bee0
extern "C++" __declspec(nothrow) void *__cdecl FUN_0008d6d0(unsigned int size);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void *memset(void *dst, int c, unsigned int n);
#endif

extern "C++" __declspec(nothrow) void __cdecl FUN_0027b8f0(void);

struct Name_27bee0 {
    char data[8];
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void e0_00038290();
    char pad4[4];
    Name_27bee0 name;
    void FUN_0027b070();
    Entity() throw() { FUN_0027b070(); }
};

class Skeleton : public Entity {
public:
    class Partition {
    public:
        virtual void p0();
        char pad4[0xc];
        unsigned int *bits;
        char pad14[4];
        Partition() throw() { bits = 0; }
    };

    class Limb {
    public:
        virtual void l0();
        char pad4[0xc];
        unsigned int *bits;
        char pad14[0x28 - 0x14];
        Limb() throw() { bits = 0; }
    };

    struct PartitionArray {
        Partition *begin;
        Partition *end;
        char *cap;
        void FUN_0027bd70(unsigned int n, Partition *proto);
    };

    struct LimbArray {
        Limb *begin;
        Limb *end;
        char *cap;
        void FUN_0027be00(unsigned int n, Limb *proto);
    };

    virtual void s1_000382a0();
    virtual void s2();
    virtual void s3_0027bd50();
    virtual void s4_0027bd60();

    int count;
    char *weights;
    char *positions;
    char *rotations;
    char *scales;
    char *flags;
    char *marks;
    int field2c;
    char *storage;
    PartitionArray partitions;
    char pad40[4];
    LimbArray limbs;

    Skeleton(int n, unsigned int numPartitions, unsigned int numLimbs) throw();
};
}

static unsigned int *NewBitSet(int bitCount)
{
    unsigned int words = ((unsigned int)bitCount + 0x1f) >> 5;
    unsigned int *bits = (unsigned int *)FUN_0008d6d0(words * 4 + 4);
    bits[0] = bitCount;
    if (words != 0)
        memset(bits + 1, 0, words * 4);
    return bits;
}

pure3d::Skeleton::Skeleton(int n, unsigned int numPartitions, unsigned int numLimbs) throw()
{
    partitions.begin = 0;
    partitions.end = 0;
    partitions.cap = 0;
    limbs.begin = 0;
    limbs.end = 0;
    count = n;

    unsigned int reserve = numPartitions + 5;
    if (reserve != 0) {
        unsigned int bytes = reserve * sizeof(Partition);
        Partition *mem = (Partition *)FUN_0008d6d0(bytes);
        partitions.begin = mem;
        if (mem != 0) {
            partitions.cap = (char *)mem + bytes;
            partitions.end = mem;
        } else {
            partitions.end = 0;
            partitions.cap = 0;
        }
    }

    {
        Partition partitionProto;
        partitions.FUN_0027bd70(numPartitions, &partitionProto);
    }
    {
        Limb limbProto;
        limbs.FUN_0027be00(numLimbs, &limbProto);
    }

    field2c = 0;
    char *mem = (char *)FUN_0008d6d0(count * 0xda);
    storage = mem;
    positions = mem;
    rotations = mem + count * 64;
    scales = rotations + count * 64;
    weights = scales + count * 64;
    flags = weights + count * 16;
    marks = flags + count * 8;

    for (unsigned int i = 0; i < numPartitions; i++)
        partitions.begin[i].bits = NewBitSet(count);
    for (unsigned int i = 0; i < numLimbs; i++)
        limbs.begin[i].bits = NewBitSet(count);
    FUN_0027b8f0();
}
} // namespace fn_0027bee0


// 0x0027c080 FUN_0027c080 (180 B): equivalent/0x0027c080.cpp [wrapped: conflict: pure3d::Skeleton]
// sym: ?target@Object@fn_0027c080@@QAEPAUPartition@Skeleton@pure3d@2@II@Z @f5de5fecf235 @w68178d5ddb86
namespace fn_0027c080 {
// STATUS: equivalent (tools/equiv.py level 3: 151 inputs, branch coverage 4/4)
// FUN_0027c080 @ 0x0027c080
namespace pure3d {
struct Skeleton {
 struct Partition {
  virtual void slot0();
  unsigned int reserved;
  unsigned int key;
  unsigned int value;
  unsigned int* bits;
  unsigned int extra;
 };
};
}
struct PartitionList {
 pure3d::Skeleton::Partition* begin;
 pure3d::Skeleton::Partition* end;
 pure3d::Skeleton::Partition* capacity;
 void FUN_0027bd70(hulk_intptr count, const pure3d::Skeleton::Partition* initial);
};
extern void* __cdecl FUN_0008d6d0(unsigned int size);
struct Object {
 char pad0[0x10];
 unsigned int bitCount;
 char pad14[0x20];
 PartitionList partitions;
 int FUN_0027b670(unsigned int key, unsigned int value);
 pure3d::Skeleton::Partition* target(unsigned int key, unsigned int value);
};
pure3d::Skeleton::Partition* Object::target(unsigned int key, unsigned int value) {
 if (FUN_0027b670(key,value)) return 0;
 hulk_intptr index = partitions.end - partitions.begin;
 pure3d::Skeleton::Partition initial;
 initial.bits = 0;
 partitions.FUN_0027bd70(index+1, &initial);
 partitions.begin[index].key = key;
 partitions.begin[index].value = value;
 unsigned int count = bitCount;
 unsigned int words = (count+31) >> 5;
 unsigned int* bits = (unsigned int*)FUN_0008d6d0(words*4+4);
 bits[0] = count;
 for(unsigned int i=0;i<words;++i) bits[i+1]=0;
 partitions.begin[index].bits = bits;
 return partitions.begin+index;
}
} // namespace fn_0027c080


// 0x0027c140 pure3d::SkeletonLoader::vfunc_5 (1491 B): equivalent/0x0027c140.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?F@SkeletonLoader@fn_0027c140@@QAEXPAPAUSkeleton@2@PA_KPAULoader_27c140@2@H@Z @6aa61d28780e @w340a48b7c9b5
namespace fn_0027c140 {
// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 48/48)
// pure3d::SkeletonLoader::vfunc_5 @ 0x0027c140
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
// equiv-conv: FUN_0027b340 eax
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

void *thunk_FUN_0008d690(unsigned int size);
extern "C" void *FUN_0008d690(unsigned int size);
void *FUN_0008d6d0(unsigned int size);
extern "C++" __declspec(nothrow) int __cdecl FUN_0028fcc0(const char *fmt, ...);
extern "C" unsigned int FUN_0027b340(const char *s);

struct Name8_27c140 {
};

struct Stream {
};

struct Loader_27c140 {
    char pad0[0x284];
    Stream *stream;
    char FUN_002669f0();
    void FUN_00266a30();
    int FUN_00266c30();
    void FUN_00266be0();
    void FUN_000f9600(char *buf);
};

struct Elem_27c140 {
    char pad0[8];
    unsigned int idLo;
    unsigned int idHi;
    int *arr10;
    int f14;
    int f18;
    int f1c;
    int f20;
};

struct Info_27c140 {
    void *skel;
    unsigned int f4;
    char **names8;
    unsigned int fc;
    char **names10;
    char **names14;
};

struct Skeleton {
    char pad0[8];
    Name8_27c140 name;
    char pad9[0x18 - 9];
    char *mats;
    char pad1c[0x24 - 0x1c];
    char *ids;
    char *parents;
    Info_27c140 *info;
    char pad30[4];
    char *arrA;
    char pad38[0x44 - 0x38];
    char *arrB;
    Skeleton *FUN_0027bee0(int a, int b, int c);
    void FUN_0027b270();
};

class SkeletonLoader {
public:
    char pad0[0x14];
    char b14;
    void F(Skeleton **out, unsigned __int64 *outId, Loader_27c140 *ld, int unused);
};

static char *DupStr(const char *src)
{
    const char *p = src;
    while (*p)
        p++;
    unsigned int n = (unsigned int)(p - src) + 1;
    char *dst = (char *)FUN_0008d6d0(n);
    char *d = dst;
    const char *q = src;
    char c;
    do {
        c = *q++;
        *d++ = c;
    } while (c);
    return dst;
}

void SkeletonLoader::F(Skeleton **out, unsigned __int64 *outId, Loader_27c140 *ld, int unused)
{
    struct Frame {
        char pad0c[2];
        unsigned char len1;
        unsigned char len2;
        int v10, v14, v18, v1c, v20, v24, v28, v2c, v30, v34, v38, v3c, v40, v44, v48, v4c, v50, v54;
        char N[0x100];
        char N2[0x100];
        char N3[0x100];
        char N4[0x100];
    } fr;

    ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.len1), (hulk_intptr)1, 1, (hulk_intptr)1);
    int len = fr.len1;
    ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(fr.N), (hulk_intptr)len, 1, (hulk_intptr)1);
    fr.N[len] = 0;
    ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v38), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v1c), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v10), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v18), (hulk_intptr)1, 4, (hulk_intptr)1);
    unsigned int nJoints = fr.v1c;
    if (nJoints < 1) {
        FUN_0028fcc0("SkeletonLoader - skipping skeleton: '%s' because nJoints out of range: %d\n", fr.N, nJoints);
        return;
    }
    Skeleton *raw = (Skeleton *)thunk_FUN_0008d690(0x50);
    Skeleton *sk = 0;
    if (raw)
        sk = raw->FUN_0027bee0(nJoints, fr.v10, fr.v18);
    fr.v24 = (hulk_intptr)sk;
    ((owners::Target_27b040 *)&(sk->name))->FUN_0027b040((hulk_uintptr)(fr.N));
    Info_27c140 *sp = 0;
    fr.v14 = 0;
    if (b14) {
        Info_27c140 *p = (Info_27c140 *)FUN_0008d690((int)sizeof(Info_27c140));
        if (p) {
            p->f4 = 0;
            p->names8 = 0;
            p->fc = 0;
            p->names10 = 0;
            p->names14 = 0;
            sp = p;
            p->skel = sk;
            fr.v14 = (hulk_intptr)sp;
        }
        sp->f4 = FUN_0027b340(fr.N);
        sp->names8 = (char **)FUN_0008d6d0(nJoints * sizeof(char *));
        unsigned int b2 = fr.v10;
        if (b2 != 0) {
            sp->fc = b2;
            sp->names10 = (char **)FUN_0008d6d0(b2 * sizeof(char *));
        }
        unsigned int b3 = fr.v18;
        if (b3 != 0)
            sp->names14 = (char **)FUN_0008d6d0(b3 * sizeof(char *));
        sk->info = sp;
        sp = 0;
    }
    if (ld->FUN_002669f0()) {
        fr.v10 = 0;
        fr.v18 = 0;
        fr.v1c = 0;
        fr.v20 = 0;
        fr.v28 = 0;
        fr.v2c = 0;
        fr.v34 = 0;
        fr.v30 = 0;
        do {
            ld->FUN_00266a30();
            if (ld->FUN_00266c30() == 0x23001) {
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.len1), (hulk_intptr)1, 1, (hulk_intptr)1);
                int n = fr.len1;
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(fr.N2), (hulk_intptr)n, 1, (hulk_intptr)1);
                fr.N2[n] = 0;
                unsigned __int64 h = FUN_002672f0(fr.N2, 0, 0);
                char *ids = sk->ids;
                *(unsigned int *)(ids + fr.v30) = (unsigned int)h;
                *(unsigned int *)(ids + fr.v30 + 4) = (unsigned int)(h >> 32);
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v44), (hulk_intptr)1, 4, (hulk_intptr)1);
                *(unsigned short *)(sk->parents + fr.v34) = (unsigned short)fr.v44;
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(sk->mats + fr.v2c), (hulk_intptr)0x10, 4, (hulk_intptr)1);
                Info_27c140 *s2 = (Info_27c140 *)fr.v14;
                if (s2) {
                    char *dup = DupStr(fr.N2);
                    *(char **)((char *)s2->names8 + fr.v28) = dup;
                }
                fr.v30 += 8;
                fr.v34 += 2;
                fr.v2c += 0x40;
                fr.v28 += 4;
            } else if (ld->FUN_00266c30() == 0x23002) {
                Elem_27c140 *e = (Elem_27c140 *)(sk->arrA + fr.v20);
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.len2), (hulk_intptr)1, 1, (hulk_intptr)1);
                int n = fr.len2;
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(fr.N3), (hulk_intptr)n, 1, (hulk_intptr)1);
                fr.N3[n] = 0;
                unsigned __int64 h = FUN_002672f0(fr.N3, 0, 0);
                e->idLo = (unsigned int)h;
                e->idHi = (unsigned int)(h >> 32);
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v3c), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int cnt = fr.v3c;
                if (cnt != 0) {
                    unsigned int j = 0;
                    do {
                        ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v4c), (hulk_intptr)1, 4, (hulk_intptr)1);
                        e->arr10[j + 1] = fr.v4c;
                        j++;
                    } while (j < cnt);
                }
                Info_27c140 *s2 = (Info_27c140 *)fr.v14;
                if (s2) {
                    char *dup = DupStr(fr.N3);
                    *(char **)((char *)s2->names10 + fr.v1c) = dup;
                }
                fr.v20 += 0x18;
                fr.v1c += 4;
            } else if (ld->FUN_00266c30() == 0x23003) {
                Elem_27c140 *e = (Elem_27c140 *)(sk->arrB + fr.v18);
                ld->FUN_000f9600(fr.N4);
                unsigned __int64 h = FUN_002672f0(fr.N4, 0, 0);
                e->idLo = (unsigned int)h;
                e->idHi = (unsigned int)(h >> 32);
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v48), (hulk_intptr)1, 4, (hulk_intptr)1);
                e->f18 = fr.v48;
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v50), (hulk_intptr)1, 4, (hulk_intptr)1);
                e->f1c = fr.v50;
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v54), (hulk_intptr)1, 4, (hulk_intptr)1);
                e->f20 = fr.v54;
                ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v40), (hulk_intptr)1, 4, (hulk_intptr)1);
                unsigned int cnt = fr.v40;
                if (cnt != 0) {
                    unsigned int j = 0;
                    do {
                        ((owners::X_2647e0 *)(ld->stream))->FUN_002647e0((hulk_intptr)(&fr.v38), (hulk_intptr)1, 4, (hulk_intptr)1);
                        e->arr10[j + 1] = fr.v38;
                        j++;
                    } while (j < cnt);
                }
                Info_27c140 *s2 = (Info_27c140 *)fr.v14;
                if (s2) {
                    char *dup = DupStr(fr.N4);
                    *(char **)((char *)s2->names14 + fr.v10) = dup;
                }
                fr.v18 += 0x28;
                fr.v10 += 4;
            } else {
                FUN_0028fcc0("SkeletonLoader - skipping unknown subchunk: '0x%X'\n", ld->FUN_00266c30());
            }
            ld->FUN_00266be0();
        } while (ld->FUN_002669f0());
    }
    sk->FUN_0027b270();
    *out = sk;
    *outId = FUN_002672f0(fr.N, 0, 0);
}
} // namespace fn_0027c140
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0027c720 pure3d::LegacySkeletonLoader::vfunc_5 (599 B): equivalent/0x0027c720.cpp
// sym: ?vfunc_5@LegacySkeletonLoader@pure3d@@UAEXPAX00H@Z @6ee8553bea12 @w12be7a9ed471
// STATUS: equivalent (tools/equiv.py level 3: 68 inputs, branch coverage 10/10)
// pure3d::LegacySkeletonLoader::vfunc_5 @ 0x0027c720
void pure3d::LegacySkeletonLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr unused) { Skeleton_27c720 ** out = (Skeleton_27c720 **)__p0; unsigned long long * outId = (unsigned long long *)__p1; Reader_27c720 * r = (Reader_27c720 *)__p2;

    Frame_27c720 f;

    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
    unsigned int n = f.len;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.name), (hulk_intptr)n, 1, (hulk_intptr)1));
    f.name[n] = 0;
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w18), (hulk_intptr)1, 4, (hulk_intptr)1));
    ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w10), (hulk_intptr)1, 4, (hulk_intptr)1));
    int nJoints = f.w10;
    if (nJoints < 1)
        FUN_0028fcc0("LegacySkeletonLoader - skipping skeleton: '%s' because nJoints < 1\n", f.name);

    void* mem = FUN_00263ea0(0x50);
    Skeleton_27c720* skel = 0;
    if (mem)
        skel = ((Skeleton_27c720*)mem)->FUN_0027bee0(nJoints, 0, 0);
    ((owners::Target_27b040 *)&(skel->name))->FUN_0027b040((hulk_uintptr)(f.name));

    if (r->FUN_002669f0()) {
        f.w10 = 0;
        f.w14 = 0;
        int off8 = 0;
        do {
            r->FUN_00266a30();
            if (r->FUN_00266c30() == 0x4501) {
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1));
                unsigned int m = f.len;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(f.jointName), (hulk_intptr)m, 1, (hulk_intptr)1));
                f.jointName[m] = 0;
                skel->hashes[off8 / 8] = FUN_002672f0(f.jointName, 0, 0);
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w18), (hulk_intptr)1, 4, (hulk_intptr)1));
                *(unsigned short*)((char*)skel->parents + f.w10) = (unsigned short)f.w18;
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w2c), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w1c), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w28), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w20), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.w24), (hulk_intptr)1, 4, (hulk_intptr)1));
                ((char)((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(skel->matrices + f.w14), (hulk_intptr)0x10, 4, (hulk_intptr)1));
                off8 += 8;
                f.w10 += 2;
                f.w14 += 0x40;
            }
            r->FUN_00266be0();
        } while (r->FUN_002669f0());
    }

    skel->FUN_0027b270();
    *out = skel;
    *outId = FUN_002672f0(f.name, 0, 0);
}

