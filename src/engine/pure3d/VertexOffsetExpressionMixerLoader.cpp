// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002b0f40..0x002b1870 (kind game, layer engine, confidence high), dominant class pure3d::VertexOffsetExpressionMixerLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f8d4917d {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f8d4917d {} using namespace fn_f8d4917d;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f8d4917d {
extern int hulk_at_0042e39c;
class VertexOffsetExpressionMixerLoader {
  public:
    hulk_intptr m0;
    int m4;
    int m8;
    int mC;
    int m10;
    VertexOffsetExpressionMixerLoader();
};
extern void* Alloc_0008d6d0(unsigned int);
void* __cdecl FUN_0008d6d0(unsigned size);
extern "C" void __cdecl FUN_002b0e40(void* data, unsigned count, int value);
struct Pair { unsigned a; unsigned b; };
struct Thing {  void FUN_002b1120(unsigned value); };
class C {
  public:
    void target(int);
};
struct State { unsigned int values[6]; };
struct Handler {
    void FUN_002b1160(unsigned int value);
};
typedef unsigned char byte_2b1200;
void __cdecl FUN_0008d340(void*);
void __cdecl FUN_0008d330(void*);
class Thing_2b1200 {
  public:
    void* mValue;
    Thing_2b1200* Destroy(byte_2b1200 flags);
};
struct Pair_2b1230 { int a; int b; };
struct Rec24_2b1230 { char d[24]; };
struct PairRef { Rec24_2b1230 *p; int v; };
struct OutVec {
    PairRef *data;
};
struct Table_2b1230 { char pad[0x10]; char *values; };
struct Target_2b1230 {
    char pad0[0x10];
    Table_2b1230 *table;
    char pad1[0x20 - 0x14];
    Rec24_2b1230 *base;
    void FUN_002b1230(OutVec *out, int n, int *idxs, int off);
};
struct Item {
    char pad[12];
    int value;
    void FUN_002b0e90(Item* source);
};
typedef unsigned int u32_2b1390;
extern void __cdecl releaseThing_0008d340(u32_2b1390);
struct Entry_2b1390 {
    u32_2b1390 value;
    char pad[12];
};
struct Obj_2b13c0 {
    int a;
    int b;
};
class V {
  public:
    virtual void a() throw();
    virtual void b() throw();
};
extern void __cdecl FUN_002b1390(void*, void*) throw();
extern void __cdecl thunk_FUN_00267090(void*) throw();
template <class T> struct Ref_2b1400 {
    T* p;
    ~Ref_2b1400() throw() {
        if (p)
            p->b();
        p = 0;
    }
};
template <int N> struct Buf_2b1400 {
    void* p;
    char pad[N - 4];
    ~Buf_2b1400() throw() {
        if (p)
            thunk_FUN_00267090(p);
    }
};
struct Range_2b1400 {
    void* b;
    void* e;
    ~Range_2b1400() throw() {
        if (b) {
            FUN_002b1390(b, e);
            thunk_FUN_00267090(b);
        }
    }
};
class VertexOffsetExpressionMixer_2b1400 : public pure3d::Entity {
  public:
    Ref_2b1400<V> m10;
    Buf_2b1400<0xc> m14;
    Buf_2b1400<0xc> m20;
    Range_2b1400 m2c;
    virtual ~VertexOffsetExpressionMixer_2b1400() throw();
};
} // namespace fn_f8d4917d
namespace pure3d {
class Entity_2b1470 {
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

namespace fn_f8d4917d {

// 0x002b0f40 FUN_002b0f40 (27 B): matches/0x002b0f40.cpp
// sym: ??0VertexOffsetExpressionMixerLoader@fn_f8d4917d@@QAE@XZ
VertexOffsetExpressionMixerLoader::VertexOffsetExpressionMixerLoader() {
    m4 = 0;
    m8 = 0x21002;
    mC = 0;
    m10 = 0;
    m0 = (hulk_intptr)&hulk_at_0042e39c;
}

} // namespace fn_f8d4917d

// 0x002b0f60 pure3d::VertexOffsetExpressionMixerLoader::vfunc_2 (31 B): matches/0x002b0f60.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002b0f60@@UAEPAV123@E@Z
namespace fn_002b0f60 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class SimpleChunkHandler_2b0f60 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_003f6098[];
namespace pure3d {
class NonCopyable : public SimpleChunkHandler_2b0f60 {
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
} // namespace fn_002b0f60


// 0x002b0fb0 FUN_002b0fb0 (95 B): matches/0x002b0fb0.cpp
// sym: ?FUN_002b0fb0@Buffer_2b0fb0@owners@@QAE_NIPAX@Z
bool owners::Buffer_2b0fb0::FUN_002b0fb0(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        begin = (int*)Alloc_0008d6d0(count * 8);
        if (begin != 0) {
            end = (int*)((char*)begin + count * 8);
            Init(begin, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002b1010 FUN_002b1010 (95 B): matches/0x002b1010.cpp
// sym: ?FUN_002b1010@Buffer_2b1010@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2b1010::FUN_002b1010(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            Init(p, count, arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002b1070 FUN_002b1070 (94 B): equivalent/0x002b1070.cpp
// sym: ?FUN_002b1070@Buffer_2b1070@owners@@QAE_NIH@Z @45ffaba623c5 @w884a6d38e63d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_002b1070 @ 0x002b1070
bool owners::Buffer_2b1070::FUN_002b1070(unsigned count, hulk_intptr value) {
    if (begin) return false;
    if (count) {
        void* p = FUN_0008d6d0(count * 24);
        begin = p;
        if (p) {
            end = (char*)p + count * 24;
            FUN_002b0e40(p, count, ((int)value));
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}

namespace fn_f8d4917d {

// 0x002b1120 FUN_002b1120 (32 B): equivalent/0x002b1120.cpp
// sym: ?FUN_002b1120@Thing@fn_f8d4917d@@QAEXI@Z @341ae72c23ea @wda6383f56023
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b1120 @ 0x002b1120
void Thing::FUN_002b1120(unsigned value) {
    Pair result = {0, 0};
    ((owners::Buffer_2b0fb0 *)this)->FUN_002b0fb0((unsigned int)value, (Pair *)(&result));
}


// 0x002b1140 FUN_002b1140 (27 B): matches/0x002b1140.cpp
// sym: ?target@C@fn_f8d4917d@@QAEXH@Z
void C::target(int x) {
    int y = 0;
    ((owners::Buffer_2b1010 *)this)->FUN_002b1010((unsigned int)x, &y);
}


// 0x002b1160 FUN_002b1160 (48 B): equivalent/0x002b1160.cpp
// sym: ?FUN_002b1160@Handler@fn_f8d4917d@@QAEXI@Z @9a383474294a @we7cd4859f654
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_002b1160 @ 0x002b1160
void Handler::FUN_002b1160(unsigned int value) {
    State state = {{0, 0, 0, 0, 0, 0}};
    ((owners::Buffer_2b1070 *)this)->FUN_002b1070((unsigned)value, (hulk_intptr)(State *)(&state));
}


// 0x002b1200 FUN_002b1200 (40 B): matches/0x002b1200.cpp
// sym: ?Destroy@Thing_2b1200@fn_f8d4917d@@QAEPAV12@E@Z
Thing_2b1200* Thing_2b1200::Destroy(byte_2b1200 flags) {
    if (mValue != 0)
        FUN_0008d340(mValue);
    if ((flags & 1) != 0)
        FUN_0008d330(this);
    return this;
}


// 0x002b1230 FUN_002b1230 (109 B): equivalent/0x002b1230.cpp
// sym: ?FUN_002b1230@Target_2b1230@fn_f8d4917d@@QAEXPAUOutVec@2@HPAHH@Z @d97bb966b712 @w25345b2cc9d0
// STATUS: equivalent (tools/equiv.py level 3: 198 inputs, branch coverage 4/4)
// FUN_002b1230 @ 0x002b1230
void Target_2b1230::FUN_002b1230(OutVec *out, int n, int *idxs, int off)
{
    Pair_2b1230 zero;
    zero.a = 0;
    zero.b = 0;
    ((owners::Buffer_2b0fb0 *)out)->FUN_002b0fb0((unsigned int)n, (Pair_2b1230 *)(&zero));
    for (int i = 0; i < n; i++) {
        out->data[i].p = base + idxs[i];
        out->data[i].v = *(int *)(table->values + (off << 2) + i * 4);
    }
}


// 0x002b12d0 FUN_002b12d0 (56 B): matches/0x002b12d0.cpp
// sym: ?FUN_002b12d0@fn_f8d4917d@@YAPAUItem@1@PAU21@I0@Z
Item* __cdecl FUN_002b12d0(Item* destination, unsigned int count, Item* source) {
    while (count) {
        if (destination) {
            destination->FUN_002b0e90(source);
            destination->value = source->value;
        }
        destination = (Item*)((char*)destination + sizeof(Item));
        --count;
    }
    return destination;
}

} // namespace fn_f8d4917d

// 0x002b1330 FUN_002b1330 (93 B): matches/0x002b1330.cpp [wrapped: conflict: Alloc; Init]
// sym: ?Create@Buffer_2b1330@fn_002b1330@@QAEDIPAX@Z
namespace fn_002b1330 {
struct E_2b1330 {
    char b[16];
};
extern "C++" __declspec(nothrow) void* __cdecl Alloc_0008d6d0(unsigned int);
extern "C++" __declspec(nothrow) void __cdecl Init_002b12d0(void*, unsigned int, void*);
class Buffer_2b1330 {
  public:
    E_2b1330* data;
    E_2b1330* end;
    char Create(unsigned int count, void* arg);
};
char Buffer_2b1330::Create(unsigned int count, void* arg) {
    if (data)
        return 0;
    if (count > 0) {
        data = (E_2b1330*)Alloc_0008d6d0(count * sizeof(E_2b1330));
        if (data) {
            end = data + count;
            Init_002b12d0(data, count, arg);
            return 1;
        }
    }
    data = 0;
    end = 0;
    return 0;
}
} // namespace fn_002b1330

namespace fn_f8d4917d {

// 0x002b1390 FUN_002b1390 (41 B): matches/0x002b1390.cpp
// sym: ?FUN_002b1390@fn_f8d4917d@@YAXPAUEntry_2b1390@1@0@Z
void __cdecl FUN_002b1390(Entry_2b1390* begin, Entry_2b1390* end) {
    for (; begin != end; ++begin) {
        if (begin->value != 0)
            releaseThing_0008d340(begin->value);
    }
}


// 0x002b13c0 FUN_002b13c0 (32 B): matches/0x002b13c0.cpp
// sym: ?target@fn_f8d4917d@@YIXPAUObj_2b13c0@1@@Z
// Same code shape as 0x002907f0 (propagated; names are from that function)
void __fastcall target(Obj_2b13c0* self) {
    if (self->a) {
        f(self->a, self->b);
        g(self->a);
    }
}


// 0x002b1400 FUN_002b1400 (97 B): matches/0x002b1400.cpp
// sym: ??1VertexOffsetExpressionMixer_2b1400@fn_f8d4917d@@UAE@XZ
VertexOffsetExpressionMixer_2b1400::~VertexOffsetExpressionMixer_2b1400() throw() {}

} // namespace fn_f8d4917d

// 0x002b1470 pure3d::VertexOffsetExpressionMixer::vfunc_4 (3 B): matches/0x002b1470.cpp
// sym: ?vfunc_4@VertexOffsetExpressionMixer@pure3d@@UAEPAXXZ
// Same code shape as 0x002a1130 (propagated; names are from that function)
 // namespace pure3d
void* pure3d::VertexOffsetExpressionMixer::vfunc_4() {
    return (void*)(this);
}


// 0x002b1480 pure3d::VertexOffsetExpressionMixer::vfunc_3 (3 B): matches/0x002b1480.cpp
// sym: ?vfunc_3@VertexOffsetExpressionMixer@pure3d@@UAE_NXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
bool pure3d::VertexOffsetExpressionMixer::vfunc_3() {
    return (bool)(0);
}


// 0x002b15d0 FUN_002b15d0 (162 B): equivalent/0x002b15d0.cpp [wrapped: conflict: pure3d::VertexOffsetExpressionMixer]
// sym: ??0VertexOffsetExpressionMixer@pure3d@fn_002b15d0@@QAE@PAUSource_2b15d0@2@@Z @445f668103cb @w38fa9a32788f
namespace fn_002b15d0 {
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 8/8)
// FUN_002b15d0 @ 0x002b15d0
// pure3d::VertexOffsetExpressionMixer::VertexOffsetExpressionMixer @ 0x002b15d0
struct Source_2b15d0 {
    virtual void AddRef();
    virtual void Release();
    char pad04[0xc];
    int *first;
    int *last;
};

struct FUN_0027b070 {
    FUN_0027b070() throw();
    virtual void v0_00038290();
    char pad04[0xc];
};

struct IntVector_2b15d0 {
    int *first;
    int *last;
    void FUN_002b1010(hulk_uintptr count, int *value);
};

namespace pure3d {
class VertexOffsetExpressionMixer : public FUN_0027b070 {
public:
    Source_2b15d0 *source;
    IntVector_2b15d0 weights;
    char pad1c[4];
    int f20;
    int f24;
    char pad28[4];
    int f2c;
    int f30;
    VertexOffsetExpressionMixer(Source_2b15d0 *s);
    void FUN_002b1490();
    virtual void v1_000382a0();
};
}

pure3d::VertexOffsetExpressionMixer::VertexOffsetExpressionMixer(Source_2b15d0 *s)
{
    source = 0;
    weights.first = 0;
    weights.last = 0;
    f20 = 0;
    f24 = 0;
    f2c = 0;
    f30 = 0;
    if (s)
        s->AddRef();
    if (source)
        source->Release();
    source = s;
    int zero = 0;
    weights.FUN_002b1010(s->last - s->first, &zero);
    for (int i = 0; i < weights.last - weights.first; i++)
        weights.first[i] = 0;
    FUN_002b1490();
}
} // namespace fn_002b15d0


// 0x002b1680 pure3d::VertexOffsetExpressionMixer::vfunc_2 (30 B): matches/0x002b1680.cpp
// sym: ??_GVertexOffsetExpressionMixer@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::VertexOffsetExpressionMixer::~VertexOffsetExpressionMixer() {}


// 0x002b16a0 pure3d::VertexOffsetExpressionMixerLoader::vfunc_5 (456 B): equivalent/0x002b16a0.cpp [wrapped: conflict: VertexOffsetExpressionMixerLoader; content::LoadInventory::DynamicCaster; content::LoadInventory::DynamicCasterBase]
// sym: ?vfunc_5@VertexOffsetExpressionMixerLoader@fn_002b16a0@@UAEXPAPAUVertexOffsetExpressionMixer_2b16a0@2@PA_KPAUStream@2@PAVLoadContext_2b16a0@2@@Z @7dfef58b414d @wdc6e80082b31
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_002b16a0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// pure3d::VertexOffsetExpressionMixerLoader::vfunc_5 @ 0x002b16a0
void *__cdecl FUN_00263ea0(unsigned int size);
extern "C" unsigned __int64 __cdecl FUN_0027b020(const char *s);
extern "C" unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
extern "C" void __cdecl FUN_0028fcc0(const char *fmt, ...);


namespace pure3d { class ExpressionGroup_2b16a0; class PolySkin_2b16a0; }

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

struct Name_2b16a0 {
    char data[8];
};

struct ExprGroup;

struct VertexOffsetExpressionMixer_2b16a0 {
    char pad0[8];
    Name_2b16a0 name;
    char pad10[0x38 - 0x10];
    VertexOffsetExpressionMixer_2b16a0 *FUN_002b15d0(ExprGroup *group);
};

struct SkinHolder_2b16a0 {
    void FUN_002a9ea0(VertexOffsetExpressionMixer_2b16a0 *mixer);
};

struct Skin_2b16a0 {
    char pad0[0x6c];
    SkinHolder_2b16a0 *holder;
};

class LoadContext_2b16a0 {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void *lookup(content::LoadInventory::DynamicCasterBase *caster, unsigned __int64 id);
};

struct Reader {
};

struct Stream {
    char pad0[0x284];
    Reader *reader;
};

struct Frame_2b16a0 {
    char pad[3];
    unsigned char len;       // 0x0f
    int cell;                // 0x10, reused as the caster object
    char mixerName[0x100];   // 0x14
    char groupName[0x100];   // 0x114
    char skinName[0x100];    // 0x214
};

class VertexOffsetExpressionMixerLoader {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5(VertexOffsetExpressionMixer_2b16a0 **out, unsigned __int64 *outId, Stream *s, LoadContext_2b16a0 *ctx);
};

void VertexOffsetExpressionMixerLoader::vfunc_5(VertexOffsetExpressionMixer_2b16a0 **out, unsigned __int64 *outId, Stream *s, LoadContext_2b16a0 *ctx)
{
    Frame_2b16a0 f;
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.mixerName), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.mixerName[f.len] = 0;

    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.cell), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.skinName), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.skinName[f.len] = 0;

    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(&f.len), (hulk_intptr)1, 1, (hulk_intptr)1);
    ((owners::X_2647e0 *)(s->reader))->FUN_002647e0((hulk_intptr)(f.groupName), (hulk_intptr)(f.len), 1, (hulk_intptr)1);
    f.groupName[f.len] = 0;

    unsigned __int64 groupId = FUN_0027b020(f.groupName);
    content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup_2b16a0> *groupCaster =
        new (&f.cell) content::LoadInventory::DynamicCaster<pure3d::ExpressionGroup_2b16a0>();
    ExprGroup *group = (ExprGroup *)ctx->lookup(groupCaster, groupId);
    if (group == 0)
        FUN_0028fcc0("Warning : can't find expression group '%s' for mixer '%s'\n", f.groupName, f.mixerName);

    void *mem = FUN_00263ea0(0x38);
    VertexOffsetExpressionMixer_2b16a0 *mixer = 0;
    if (mem)
        mixer = static_cast<VertexOffsetExpressionMixer_2b16a0 *>(mem)->FUN_002b15d0(group);
    ((owners::Target_27b040 *)&(mixer->name))->FUN_0027b040((hulk_uintptr)(f.mixerName));

    unsigned __int64 skinId = FUN_0027b020(f.skinName);
    content::LoadInventory::DynamicCaster<pure3d::PolySkin_2b16a0> *skinCaster =
        new (&f.cell) content::LoadInventory::DynamicCaster<pure3d::PolySkin_2b16a0>();
    Skin_2b16a0 *skin = (Skin_2b16a0 *)ctx->lookup(skinCaster, skinId);
    if (skin && skin->holder)
        skin->holder->FUN_002a9ea0(mixer);

    *out = mixer;
    *outId = FUN_002672f0(f.mixerName, 0);
}
} // namespace fn_002b16a0

