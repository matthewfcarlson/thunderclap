// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a3e70..0x002a5060 (kind game, layer engine, confidence high), dominant class pure3d::DrawableContainer
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/content.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f6d01fd6 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f6d01fd6 {} using namespace fn_f6d01fd6;
namespace fn_f6d01fd6 { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f6d01fd6 {
class pddiObject_2a3e70 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_2a3e70 : public pddiObject_2a3e70 {};
class pddiBaseShader_2a3e70 : public pddiShader_2a3e70 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_2a3e70 : public pddiBaseShader_2a3e70 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
extern int vftable_2a3e80;
class RenderObjectLoader {
  public:
    hulk_intptr pad;
    int mValue;
    RenderObjectLoader();
};
extern void* IRefCount_vftable_2a3e90;
class Item_2a4060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Do(int, int);
};
class Owner_2a4060 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Finish();
};
class Container_2a4060 {
  public:
    Owner_2a4060* owner;
    Item_2a4060** begin;
    Item_2a4060** end;
    void Clear();
};
struct Obj_2a40d0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};
struct Grp {
    int m0;
    Obj_2a40d0** b;
    Obj_2a40d0** e;
    int mc;
};
struct Item_2a4150 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual bool slot22();
};
struct Group_2a4150 {
    unsigned unknown;
    Item_2a4150** begin;
    Item_2a4150** end;
    unsigned capacity;
};
struct Child_2a4350 {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void Fn23();
};
struct Group_2a4350 {
    int pad;
    Child_2a4350** begin;
    Child_2a4350** end;
    int pad2;
};
struct Entry { int *object; char padding[12]; };
struct Owner { char padding[0x48]; Entry *begin; Entry *end; int FUN_002a43c0(int key1, int key2); };
} // namespace fn_f6d01fd6
namespace pure3d {
struct Child {
    int a;
    int* first;
    int* last;
    int b;
};
}
namespace pure3d {
struct Entry_2a4440 { char padding[8]; int key1; int key2; };
}
namespace pure3d {
struct Group_2a4440 { int unused; Entry_2a4440** begin; Entry_2a4440** end; Entry_2a4440** capacity; };
}
namespace fn_f6d01fd6 {
class Item_2a4500 {
  public:
    virtual void First();
    virtual void Release();
};
struct Slot_2a4500 {
    Item_2a4500* item;
    char pad[12];
};
class DrawableContainer_2a4500 {
  public:
    char pad[0x48];
    Slot_2a4500* slots;
    void Set(int index, Item_2a4500* item);
};
struct V3_2a4570 { float x, y, z; };
struct Sphere_2a4570 { float x, y, z, r; };
struct Box_2a4570 {
    V3_2a4570 min;
    V3_2a4570 max;
    Sphere_2a4570* FUN_000a8890(Sphere_2a4570* out);
};
union Temp_2a4570 {
    Box_2a4570 box;
    Sphere_2a4570 sphere;
};
class Child_2a4570 {
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
    virtual void v10();
    char pad[0x14 - 4];
    Box_2a4570 box;
};
struct Slot_2a4570 {
    Child_2a4570* child;
    char pad[12];
};
class A_2a46d0 {
  public:
    virtual void F();
    virtual void G();
};
void *FUN_0008d6d0(unsigned int size);
struct IntVector_2a4760 {
    int *first;
    int *last;
    IntVector_2a4760(const IntVector_2a4760 &other) throw();
};
typedef unsigned int u32_2a47d0;
void __cdecl thunk_FUN_00267090(u32_2a47d0);
struct X_2a47d0 {
    u32_2a47d0 a;
    u32_2a47d0 b;
    void f();
};
extern void* Alloc(hulk_uintptr);
extern "C" int * __cdecl FUN_002a4730(int *, int, const int *);
class Buffer_2a4800 {
  public:
    int* begin;
    int* end;
    bool Create(unsigned int count, void* arg);
};
class Item_2a4890 {
  public:
    virtual void f0();
    virtual void Release();
};
extern void Free(void*);
class Container_2a4890 {
  public:
    Item_2a4890* first;
    Item_2a4890** begin;
    Item_2a4890** end;
    void Clear();
};
struct ThisCall_002a4890 {
    void FUN_002a4890();
};
extern void thunk_FUN_00267090(CCollisionAction*);
struct Element_2a4a50 { virtual void unused(); virtual void release(); };
struct Array_2a4a50 { unsigned int unknown; Element_2a4a50** begin; Element_2a4a50** end; };
extern "C" void __cdecl FUN_0008d340(void*);
struct Object { virtual void retain(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void attach(unsigned value); };
struct Uid_2a4b00 { unsigned lo, hi; };
struct Factory_2a4b00 { virtual void retain(); virtual void release(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void create(Object** out, Uid_2a4b00* id, Reader* reader, unsigned arg); };
struct Source_2a4b00 {  };
struct Reader { char pad[0x284]; Source_2a4b00* source; bool FUN_002669f0(); unsigned FUN_00266a30(); void FUN_00266be0(); };
struct Collection_2a4b00 { unsigned owner; Object** begin; Object** end; };
struct Manager_2a4b00 {  };
extern unsigned DAT_004ce770, DAT_0049c7dc;
extern Factory_2a4b00* __cdecl FUN_00344e74(void*, unsigned, unsigned*, unsigned*, unsigned);
struct Target_2a4b00 { void FUN_002a4a50(Collection_2a4b00*, unsigned); void work(Collection_2a4b00* collection, Reader* reader, hulk_uintptr arg); };
struct Sub {
    char pad[12];
    void Copy(Sub*);
};
struct Elem {
    int x;
    Sub sub;
};
extern "C" void* alloc(hulk_uintptr) throw();
struct E_2a4cb0 {
    int a, b, c, d;
};
struct Buffer_2a4cb0 {
    E_2a4cb0* begin;
    E_2a4cb0* end;
    Buffer_2a4cb0* target(unsigned int count, int unused);
};
typedef unsigned int u32_2a4da0;
struct Item_2a4da0 {
    void Destroy();
};
extern void __cdecl ReleaseBlock(void*);
struct Container_2a4da0 {
    Item_2a4da0* begin;
    Item_2a4da0* end;
};
extern "C" char DAT_0042d90c[];
class DrawableContainer_2a4e10 {
  public:
    void Base();
    void Second(unsigned int, unsigned int*);
};
class DrawableContainer {
  public:
    void* vftable;
    char pad[0x3c];
    unsigned int half;
    void* owner;
    void* Init(unsigned int arg);
};

} // namespace fn_f6d01fd6

// 0x002a3e70 pure3d::DrawableContainer::vfunc_5 (6 B): matches/0x002a3e70.cpp
// sym: ?vfunc_5@DrawableContainer@pure3d@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int pure3d::DrawableContainer::vfunc_5() {
    return 1;
}

namespace fn_f6d01fd6 {

// 0x002a3e80 FUN_002a3e80 (16 B): matches/0x002a3e80.cpp
// sym: ??0RenderObjectLoader@fn_f6d01fd6@@QAE@XZ
RenderObjectLoader::RenderObjectLoader() {
    mValue = 0;
    this->pad = (hulk_intptr)&vftable_2a3e80;
}


// 0x002a3e90 FUN_002a3e90 (7 B): matches/0x002a3e90.cpp
// sym: ?FUN_002a3e90@fn_f6d01fd6@@YIXPAX@Z
// Same code shape as 0x001b6820 (propagated; names are from that function)
void __fastcall FUN_002a3e90(void* self) {
    *(void**)self = &IRefCount_vftable_2a3e90;
}


// 0x002a4060 FUN_002a4060 (54 B): matches/0x002a4060.cpp
// sym: ?Clear@Container_2a4060@fn_f6d01fd6@@QAEXXZ
void Container_2a4060::Clear() {
    int n = ((int)((char*)end - (char*)begin)) >> 2;
    for (unsigned int i = 0; i < (unsigned int)n; ++i) {
        Item_2a4060* p = begin[i];
        if (p)
            p->Do(0, 1);
    }
    owner->Finish();
}

} // namespace fn_f6d01fd6

// 0x002a40d0 pure3d::DrawableContainer::vfunc_6 (114 B): matches/0x002a40d0.cpp
// sym: ?vfunc_6@DrawableContainer@pure3d@@UAEXHH@Z
void pure3d::DrawableContainer::vfunc_6(int a, int b) {
    hulk_uintptr n = (*(Grp * *)&this->f_4c) - (*(Grp * *)&this->f_48);
    for (unsigned i = 0; i < n; i++) {
        Grp* g = &(*(Grp * *)&this->f_48)[i];
        hulk_uintptr m = g->e - g->b;
        for (unsigned j = 0; j < m; j++) {
            Obj_2a40d0* o = g->b[j];
            if (o)
                o->v6(a, b);
        }
    }
}


// 0x002a4150 pure3d::DrawableContainer::vfunc_7 (136 B): matches/0x002a4150.cpp
// sym: ?vfunc_7@DrawableContainer@pure3d@@UAEDXZ
 // namespace pure3d
char pure3d::DrawableContainer::vfunc_7() {
    unsigned count = (unsigned)(((hulk_intptr)(*(Group_2a4150 * *)&this->f_4c) - (hulk_intptr)(*(Group_2a4150 * *)&this->f_48)) >> 4);
    for (unsigned i = 0; i < count; ++i) {
        Group_2a4150* group = (*(Group_2a4150 * *)&this->f_48) + i;
        unsigned items = (unsigned)(((hulk_intptr)group->end - (hulk_intptr)group->begin) >> 2);
        for (unsigned j = 0; j < items; ++j) {
            Item_2a4150* item = group->begin[j];
            if (item && !item->slot22())
                return (char)(false);
        }
    }
    return (char)(true);
}


// 0x002a41e0 FUN_002a41e0 (368 B): equivalent/0x002a41e0.cpp [wrapped: macros]
// sym: ?FUN_002a41e0@Group_2a41e0@fn_002a41e0@@QAEXPAVParent_2a41e0@2@H@Z @8ed859dccd65 @w8d920481ec05
namespace fn_002a41e0 {
// STATUS: equivalent (tools/equiv.py level 3: 19720 inputs, branch coverage 24/24)
// FUN_002a41e0 @ 0x002a41e0
class Owner_2a41e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int v7();
    virtual void v8(int a);
};
class Child_2a41e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a, int b);
};
class Source_2a41e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int a);
    virtual int v4(int a);
};
struct Entry_2a41e0 {
    Owner_2a41e0* owner;
    Child_2a41e0** begin;
    Child_2a41e0** end;
    Child_2a41e0** cap;
};
#if defined(__clang__)
typedef int (__fastcall *Fn0)(void*, int);
typedef void (__fastcall *Fn1)(void*, int, int);
typedef int (__fastcall *Fn1r)(void*, int, int);
#endif
class Group_2a41e0;
class Parent_2a41e0 {
public:
    void FUN_0029b750(Group_2a41e0* g, int zero, int arg);
};
class Group_2a41e0 {
public:
    char pad0[0x10];
    Source_2a41e0* source;
    char pad14[0x48 - 0x14];
    Entry_2a41e0* entries;
    Entry_2a41e0* entriesEnd;
    void FUN_002a41e0(Parent_2a41e0* parent, int arg);
};

void Group_2a41e0::FUN_002a41e0(Parent_2a41e0* parent, int arg)
{
    if (parent != 0) {
        parent->FUN_0029b750(this, 0, arg);
        return;
    }
    unsigned int count = (unsigned int)(entriesEnd - entries);
    if (source != 0) {
        for (unsigned int k = 0; k < count; k++) {
            Owner_2a41e0* o = entries[k].owner;
#if defined(__clang__)
            {
                // the original loads both vptrs before the first call and reads the slots after it
                void** ovt = *(void***)o;
                Source_2a41e0* s = source;
                void** svt = *(void***)s;
                int a = ((Fn0)ovt[7])(o, 0);
                int b = ((Fn1r)svt[3])(s, 0, a);
                ((Fn1)ovt[8])(o, 0, b);
            }
#else
            o->v8(source->v3(o->v7()));
#endif
            Entry_2a41e0* e = &entries[k];
            unsigned int n = (unsigned int)(e->end - e->begin);
            for (unsigned int i = 0; i < n; i++) {
                Child_2a41e0* c = e->begin[i];
                if (c != 0)
                    c->v6(0, 1);
            }
            e->owner->v6();
#if defined(__clang__)
            {
                // the original loads both vptrs before the first call and reads the slots after it
                void** ovt = *(void***)o;
                Source_2a41e0* s = source;
                void** svt = *(void***)s;
                int a = ((Fn0)ovt[7])(o, 0);
                int b = ((Fn1r)svt[4])(s, 0, a);
                ((Fn1)ovt[8])(o, 0, b);
            }
#else
            o->v8(source->v4(o->v7()));
#endif
        }
    } else {
        for (unsigned int k = 0; k < count; k++) {
            Entry_2a41e0* e = &entries[k];
            unsigned int n = (unsigned int)(e->end - e->begin);
            for (unsigned int i = 0; i < n; i++) {
                Child_2a41e0* c = e->begin[i];
                if (c != 0)
                    c->v6(0, 1);
            }
            e->owner->v6();
        }
    }
}
} // namespace fn_002a41e0


// 0x002a4350 pure3d::DrawableContainer::vfunc_9 (102 B): matches/0x002a4350.cpp
// sym: ?vfunc_9@DrawableContainer@pure3d@@UAEXXZ
void pure3d::DrawableContainer::vfunc_9() {
    hulk_uintptr n = (*(Group_2a4350 * *)&this->f_4c) - (*(Group_2a4350 * *)&this->f_48);
    for (unsigned i = 0; i < n; i++) {
        Group_2a4350* g = &(*(Group_2a4350 * *)&this->f_48)[i];
        hulk_uintptr m = g->end - g->begin;
        for (unsigned j = 0; j < m; j++) {
            Child_2a4350* c = g->begin[j];
            if (c)
                c->Fn23();
        }
    }
}

namespace fn_f6d01fd6 {

// 0x002a43c0 FUN_002a43c0 (66 B): equivalent/0x002a43c0.cpp
// sym: ?FUN_002a43c0@Owner@fn_f6d01fd6@@QAEHHH@Z @44e023cf8ebe @w79837a905970
// STATUS: equivalent (tools/equiv.py level 3: 763 inputs, branch coverage 8/8)
// FUN_002a43c0 @ 0x002a43c0
int Owner::FUN_002a43c0(int key1, int key2) { unsigned count = (unsigned)(end - begin); for (unsigned i = 0; i < count; ++i) { int *object = begin[i].object; if (object[2] == key1 && object[3] == key2) return i; } return -1; }

} // namespace fn_f6d01fd6

// 0x002a4410 pure3d::DrawableContainer::vfunc_16 (41 B): matches/0x002a4410.cpp
// sym: ?vfunc_16@DrawableContainer@pure3d@@UAEHXZ
 // namespace pure3d
int pure3d::DrawableContainer::vfunc_16() {
    int total = 0;
    hulk_uintptr count = ((*(Child * *)&this->f_4c) - (*(Child * *)&this->f_48));
    for (unsigned i = 0; i < count; ++i)
        total += (int)((*(Child * *)&this->f_48)[i].last - (*(Child * *)&this->f_48)[i].first);
    return total;
}


// 0x002a4440 pure3d::DrawableContainer::vfunc_17 (111 B): equivalent/0x002a4440.cpp
// sym: ?vfunc_17@DrawableContainer@pure3d@@UAEPAXHH@Z @45f561c15947 @w1c2af3e11f7c
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 12/12)
// pure3d::DrawableContainer::vfunc_17 @ 0x002a4440
void* pure3d::DrawableContainer::vfunc_17(int key1, int key2) {
 unsigned count = (unsigned)((*(Group_2a4440 * *)&this->f_4c) - (*(Group_2a4440 * *)&this->f_48));
 Group_2a4440* group = (*(Group_2a4440 * *)&this->f_48);
 for (unsigned i=0;i<count;++i,++group) {
  Entry_2a4440** entries = group->begin;
  unsigned size = (unsigned)(group->end - entries);
  for(unsigned j=0;j<size;++j) {
   Entry_2a4440* entry = entries[j];
   if(entry->key1 == key1 && entry->key2 == key2) return (void*)(entry);
  }
 }
 return (void*)(0);
}


// 0x002a44b0 pure3d::DrawableContainer::vfunc_18 (78 B): equivalent/0x002a44b0.cpp [wrapped: conflict: pure3d::DrawableContainer]
// sym: ?vfunc_18@DrawableContainer@pure3d@fn_002a44b0@@QAEPAXI@Z @1e9e158f1645 @wfefff2c7c4a3
namespace fn_002a44b0 {
// STATUS: equivalent (tools/equiv.py level 3: 632 inputs, branch coverage 6/6)
// pure3d::DrawableContainer::vfunc_18 @ 0x002a44b0
namespace pure3d {
struct DrawableContainer {
    char pad[0x48];
    struct Group { unsigned unknown; void **begin; void **end; unsigned spare; };
    Group *groupsBegin;
    Group *groupsEnd;
    void *vfunc_18(unsigned index);
};
void *DrawableContainer::vfunc_18(unsigned index) {
    unsigned groupCount = (unsigned)(((hulk_intptr)groupsEnd - (hulk_intptr)groupsBegin) >> 4);
    Group *group = groupsBegin;
    for (unsigned i = 0; i < groupCount; ++i, ++group) {
        unsigned count = (unsigned)(((hulk_intptr)group->end - (hulk_intptr)group->begin) >> 2);
        if (index < count) return group->begin[index];
        index -= count;
    }
    return 0;
}
}
} // namespace fn_002a44b0

namespace fn_f6d01fd6 {

// 0x002a4500 FUN_002a4500 (46 B): matches/0x002a4500.cpp
// sym: ?Set@DrawableContainer_2a4500@fn_f6d01fd6@@QAEXHPAVItem_2a4500@2@@Z
void DrawableContainer_2a4500::Set(int index, Item_2a4500* item) {
    Slot_2a4500* s = slots + index;
    if (item)
        item->First();
    Item_2a4500* old = s->item;
    if (old)
        old->Release();
    s->item = item;
}

} // namespace fn_f6d01fd6

// 0x002a4570 pure3d::DrawableContainer::vfunc_12 (314 B): equivalent/0x002a4570.cpp
// sym: ?vfunc_12@DrawableContainer@pure3d@@UAEXXZ @235dfcee9e2c @w8f5fba1868bf
// STATUS: equivalent (tools/equiv.py level 3: 8 inputs, branch coverage 6/6)
// pure3d::DrawableContainer::vfunc_12 @ 0x002a4570
void pure3d::DrawableContainer::vfunc_12() {
    unsigned int count = (unsigned int)((*(Slot_2a4570 * *)&this->f_4c) - (*(Slot_2a4570 * *)&this->f_48));
    Temp_2a4570 t;
    if (count == 0) {
        (*(Box_2a4570 *)&this->f_14).min.x = 0;
        (*(Box_2a4570 *)&this->f_14).min.y = 0;
        (*(Box_2a4570 *)&this->f_14).min.z = 0;
        (*(Box_2a4570 *)&this->f_14).max.x = 1.0f;
        (*(Box_2a4570 *)&this->f_14).max.y = 1.0f;
        (*(Box_2a4570 *)&this->f_14).max.z = 1.0f;
    } else {
        Child_2a4570* first = (*(Slot_2a4570 * *)&this->f_48)[0].child;
        first->v10();
        t.box = first->box;
        (*(Box_2a4570 *)&this->f_14) = t.box;
        for (unsigned int i = 1; i < count; i++) {
            Child_2a4570* c = (*(Slot_2a4570 * *)&this->f_48)[i].child;
            c->v10();
            t.box = c->box;
            ((owners::V_a87f0 *)&((*(Box_2a4570 *)&this->f_14)))->FUN_000a87f0((owners::V_a87f0 *)(V3_2a4570 *)(&t.box.min));
            ((owners::V_a87f0 *)&((*(Box_2a4570 *)&this->f_14)))->FUN_000a87f0((owners::V_a87f0 *)(V3_2a4570 *)(&t.box.max));
        }
    }
    Sphere_2a4570* s = (*(Box_2a4570 *)&this->f_14).FUN_000a8890(&t.sphere);
    (*(Sphere_2a4570 *)&this->f_2c) = *s;
}


// 0x002a46b0 pure3d::RenderObjectLoader::vfunc_2 (31 B): matches/0x002a46b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002a46b0@@UAEPAV123@E@Z
namespace fn_002a46b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2a46b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public NonCopyable_2a46b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002a46b0

namespace fn_f6d01fd6 {

// 0x002a46d0 FUN_002a46d0 (38 B): matches/0x002a46d0.cpp
// sym: ?FUN_002a46d0@fn_f6d01fd6@@YGXPAPAVA_2a46d0@1@PAV21@@Z
void __stdcall FUN_002a46d0(A_2a46d0** slot, A_2a46d0* object) {
    if (object)
        object->F();
    if (*slot)
        (*slot)->G();
    *slot = object;
}


// 0x002a4730 FUN_002a4730 (40 B): matches/0x002a4730.cpp
// sym: _FUN_002a4730
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002a4730(int* dst, int count, const int* src) {
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


// 0x002a4760 FUN_002a4760 (110 B): equivalent/0x002a4760.cpp
// sym: ??0IntVector_2a4760@fn_f6d01fd6@@QAE@ABU01@@Z @e6af28e42022 @w28f00e00918c
// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 9/10, incomplete)
// FUN_002a4760 @ 0x002a4760
IntVector_2a4760::IntVector_2a4760(const IntVector_2a4760 &other) throw()
{
    hulk_intptr count = other.last - other.first;
    if (count != 0) {
        first = (int *)FUN_0008d6d0(count * 4);
        if (first != 0) {
            last = first + count;
            int *dst = first;
            const int *src = other.first;
            for (count = other.last - src; count != 0; count--) {
                if (dst != 0)
                    *dst = *src;
                src++;
                dst++;
            }
            return;
        }
    }
    first = 0;
    last = 0;
}


// 0x002a47d0 FUN_002a47d0 (33 B): matches/0x002a47d0.cpp
// sym: ?f@X_2a47d0@fn_f6d01fd6@@QAEXXZ
void X_2a47d0::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}


// 0x002a4800 FUN_002a4800 (95 B): matches/0x002a4800.cpp
// sym: ?Create@Buffer_2a4800@fn_f6d01fd6@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool Buffer_2a4800::Create(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002a4730((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002a4890 FUN_002a4890 (89 B): matches/0x002a4890.cpp
// sym: ?Clear@Container_2a4890@fn_f6d01fd6@@QAEXXZ
void Container_2a4890::Clear() {
    if (first) {
        first->Release();
        first = 0;
    }
    unsigned int n = (unsigned int)(((char*)end - (char*)begin) >> 2);
    unsigned int i = 0;
    if (n <= 0) {
    } else
        do {
            Item_2a4890** q = begin + i;
            if (*q) {
                (*q)->Release();
                *q = 0;
            }
            ++i;
        } while (i < n);
    if (begin)
        Free(begin);
}


// 0x002a4950 FUN_002a4950 (30 B): matches/0x002a4950.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f6d01fd6@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_002a4890*)(this))->FUN_002a4890();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x002a4a50 FUN_002a4a50 (171 B): equivalent/0x002a4a50.cpp
// sym: ?resizeArray@fn_f6d01fd6@@YGXPAUArray_2a4a50@1@I@Z @b8b3b96c2b6b @w4100c333ea1e
// STATUS: equivalent (tools/equiv.py level 3: 52 inputs, branch coverage 16/18, incomplete)
// FUN_002a4a50 @ 0x002a4a50
void __stdcall resizeArray(Array_2a4a50* a, unsigned int count) {
    unsigned int i=count;
    while(i < (unsigned int)(a->end-a->begin)) {
        Element_2a4a50** slot=a->begin+i;
        if(*slot) { (*slot)->release(); *slot=0; }
        ++i;
    }
    if(a->begin) FUN_0008d340(a->begin);
    a->begin=0;
    a->end=0;
    if(count) {
        Element_2a4a50** p=(Element_2a4a50 **)FUN_0008d6d0(count * sizeof(Element_2a4a50 *));
        a->begin=p;
        if(p) {
            a->end=(Element_2a4a50**)((char*)p+count*4);
            for(unsigned int j=0;j<count;++j,++p) if(p) *p=0;
            return;
        }
    }
    a->begin=0;
    a->end=0;
}


// 0x002a4b00 FUN_002a4b00 (297 B): equivalent/0x002a4b00.cpp
// sym: ?work@Target_2a4b00@fn_f6d01fd6@@QAEXPAUCollection_2a4b00@2@PAUReader@2@I@Z @3a96aa0c2ef8 @w817dac3703af
// STATUS: equivalent (tools/equiv.py level 3: 16697 inputs, branch coverage 10/10)
// FUN_002a4b00 @ 0x002a4b00
void Target_2a4b00::work(Collection_2a4b00* collection, Reader* reader, hulk_uintptr arg) {
 unsigned count;
 ((owners::X_2647e0 *)(reader->source))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 4, (hulk_intptr)1);
 unsigned size = (unsigned)(collection->end - collection->begin);
 ((owners::X_2647e0 *)(reader->source))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 4, (hulk_intptr)1);
 FUN_002a4a50(collection,count+size);
 Factory_2a4b00* factory = FUN_00344e74(((void *)((owners::Obj_265310 *)((*(Manager_2a4b00**)&DAT_00527c58)))->FUN_00265310((hulk_intptr)0x121201)),0,&DAT_0049c7dc,&DAT_004ce770,0);
 factory->retain();
 if(reader->FUN_002669f0()) {
 unsigned offset=size;
 do {
 if(reader->FUN_00266a30()==0x121201) {
 Object* object=0; Uid_2a4b00 id;
 factory->create(&object,&id,reader,arg);
 Object** slot=collection->begin+offset;
 Object* saved=object;
 if(object) object->retain();
 if(*slot) (*slot)->release();
 *slot=saved;
 object->attach(collection->owner);
 ++offset;
 }
 reader->FUN_00266be0();
 } while(reader->FUN_002669f0());
 }
 factory->release();
}


// 0x002a4c60 FUN_002a4c60 (58 B): matches/0x002a4c60.cpp
// sym: ?FUN_002a4c60@fn_f6d01fd6@@YAPAUElem@1@PAU21@H0@Z
Elem* __cdecl FUN_002a4c60(Elem* dst, int n, Elem* src) {
    if (n != 0) {
        int i = n;
        do {
            if (dst) {
                dst->x = src->x;
                dst->sub.Copy(&src->sub);
            }
            ++dst;
        } while (--i);
    }
    return dst;
}


// 0x002a4cb0 FUN_002a4cb0 (88 B): matches/0x002a4cb0.cpp
// sym: ?target@Buffer_2a4cb0@fn_f6d01fd6@@QAEPAU12@IH@Z
Buffer_2a4cb0* Buffer_2a4cb0::target(unsigned int count, int unused) {
    if (count > 0) {
        begin = (E_2a4cb0*)alloc(count * 16);
        if (begin != 0) {
            E_2a4cb0* e = begin + count;
            end = e;
            for (E_2a4cb0* p = begin; p != e; ++p) {
                if (p != 0) {
                    p->a = 0;
                    p->b = 0;
                    p->c = 0;
                }
            }
            _ReadWriteBarrier();
            return this;
        }
    }
    begin = 0;
    end = 0;
    return this;
}

} // namespace fn_f6d01fd6

// 0x002a4d10 FUN_002a4d10 (93 B): matches/0x002a4d10.cpp [wrapped: conflict: Alloc]
// sym: ?Create@Buffer_2a4d10@fn_002a4d10@@QAEDIPAX@Z
namespace fn_002a4d10 {
struct E_2a4d10 {
    char b[16];
};
extern "C++" __declspec(nothrow) void* __cdecl Alloc(hulk_uintptr);
extern "C++" __declspec(nothrow) void __cdecl Init(void*, unsigned int, void*);
class Buffer_2a4d10 {
  public:
    E_2a4d10* data;
    E_2a4d10* end;
    char Create(unsigned int count, void* arg);
};
char Buffer_2a4d10::Create(unsigned int count, void* arg) {
    if (data)
        return 0;
    if (count > 0) {
        data = (E_2a4d10*)Alloc(count * sizeof(E_2a4d10));
        if (data) {
            end = data + count;
            Init(data, count, arg);
            return 1;
        }
    }
    data = 0;
    end = 0;
    return 0;
}
} // namespace fn_002a4d10

namespace fn_f6d01fd6 {

// 0x002a4da0 FUN_002a4da0 (47 B): matches/0x002a4da0.cpp
// sym: ?Target@fn_f6d01fd6@@YIXPAUContainer_2a4da0@1@@Z
void __fastcall Target(Container_2a4da0* self) {
    Item_2a4da0* p = self->begin;
    if (p) {
        Item_2a4da0* end = self->end;
        for (; p != end; p = (Item_2a4da0*)((char*)p + 16))
            p->Destroy();
        ReleaseBlock(self->begin);
    }
}


// 0x002a4e10 FUN_002a4e10 (48 B): matches/0x002a4e10.cpp
// sym: ?Init@DrawableContainer@fn_f6d01fd6@@QAEPAXI@Z
void* DrawableContainer::Init(unsigned int arg) {
    ((DrawableContainer_2a4e10*)this)->Base();
    vftable = (void*)((hulk_intptr)DAT_0042d90c);
    half = 0x3f000000;
    ((DrawableContainer_2a4e10*)((char*)this + 0x48))->Second(arg, &arg);
    owner = this;
    return this;
}

} // namespace fn_f6d01fd6

// 0x002a4e40 FUN_002a4e40 (428 B): equivalent/0x002a4e40.cpp [wrapped: conflict: pure3d::DrawableContainer]
// sym: ??0DrawableContainer@pure3d@fn_002a4e40@@QAE@ABV012@@Z @f03d2da46880 @w9c94e0195a47
namespace fn_002a4e40 {
// STATUS: equivalent (tools/equiv.py level 3: 157 inputs, branch coverage 22/24, incomplete)
// FUN_002a4e40 @ 0x002a4e40
extern "C++" __declspec(nothrow) void *__cdecl FUN_0008d6d0(unsigned int size);

class Drawable {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual Drawable *Clone();
    virtual void SetParent(Drawable *parent);
};

struct Elem_2a4e40 {
    Drawable *obj;
    Drawable **begin;
    Drawable **end;
    int pad;
    void FUN_002a4890();
};

struct ElemVec_2a4e40 {
    Elem_2a4e40 *begin;
    Elem_2a4e40 *end;
    bool FUN_002a4d10(hulk_uintptr count, Elem_2a4e40 *fill);
};

class __declspec(novtable) DrawableHierarchy_2a4e40 {
public:
    virtual void b0_00038290();
    char pad04[0x3c];
    void FUN_002a3530(const DrawableHierarchy_2a4e40 *src);
    DrawableHierarchy_2a4e40(const DrawableHierarchy_2a4e40 &src) { FUN_002a3530(&src); }
};

namespace pure3d {
class DrawableContainer : public DrawableHierarchy_2a4e40 {
public:
    virtual void vfunc_1_000382a0();
    virtual void vfunc_2();
    virtual void vfunc_3() HULK_PURE64;
    int f40;
    DrawableContainer *self;   // 0x44
    ElemVec_2a4e40 elems;             // 0x48
    DrawableContainer(const DrawableContainer &src);
};
}

pure3d::DrawableContainer::DrawableContainer(const DrawableContainer &src)
    : DrawableHierarchy_2a4e40(src)
{
    f40 = src.f40;
    elems.begin = 0;
    elems.end = 0;

    Elem_2a4e40 fill;
    fill.obj = 0;
    fill.begin = 0;
    fill.end = 0;
    elems.FUN_002a4d10(src.elems.end - src.elems.begin, &fill);
    fill.FUN_002a4890();
    self = this;

    hulk_uintptr count = src.elems.end - src.elems.begin;
    if (count != 0) {
        unsigned int offset = 0;
        do {
            Drawable *clone = ((Elem_2a4e40 *)((char *)src.elems.begin + offset))->obj->Clone();
            Elem_2a4e40 *dst = (Elem_2a4e40 *)((char *)elems.begin + offset);
            if (clone != 0)
                clone->AddRef();
            if (dst->obj != 0)
                dst->obj->Release();
            dst->obj = clone;

            Elem_2a4e40 *se = (Elem_2a4e40 *)((char *)src.elems.begin + offset);
            hulk_uintptr m = se->end - se->begin;
            if (m != 0) {
                Elem_2a4e40 *de = (Elem_2a4e40 *)((char *)elems.begin + offset);
                if (de->begin == 0) {
                    Drawable **p = (Drawable **)FUN_0008d6d0(m * sizeof(Drawable *));
                    de->begin = p;
                    if (p == 0) {
                        de->begin = 0;
                        de->end = 0;
                    } else {
                        de->end = p + m;
                        for (unsigned int k = 0; k < m; k++)
                            p[k] = 0;
                    }
                }
                for (unsigned int j = 0; j < m; j++) {
                    Drawable *c2 = ((Elem_2a4e40 *)((char *)src.elems.begin + offset))->begin[j]->Clone();
                    c2->SetParent(clone);
                    Drawable **slot = &((Elem_2a4e40 *)((char *)elems.begin + offset))->begin[j];
                    c2->AddRef();
                    if (*slot != 0)
                        (*slot)->Release();
                    *slot = c2;
                }
            }
            offset += 0x10;
            count--;
        } while (count != 0);
    }
}
} // namespace fn_002a4e40


// 0x002a4ff0 FUN_002a4ff0 (68 B): matches/0x002a4ff0.cpp [wrapped: conflict: DrawableContainer]
// sym: ??1DrawableContainer@fn_002a4ff0@@UAE@XZ
namespace fn_002a4ff0 {
struct E_2a4ff0 {
    char d[0x10];
    ~E_2a4ff0() throw();
};
extern "C++" __declspec(nothrow) void __cdecl myfree(void*) throw();
template <class T> struct Vec_2a4ff0 {
    T* mBegin;
    T* mEnd;
    ~Vec_2a4ff0() throw() {
        T* p = mBegin;
        if (p) {
            T* e = mEnd;
            while (p != e) {
                p->~T();
                ++p;
            }
            myfree(mBegin);
        }
    }
};
struct DrawableHierarchy_2a4ff0 {
    virtual ~DrawableHierarchy_2a4ff0() throw();
};
class DrawableContainer : public DrawableHierarchy_2a4ff0 {
  public:
    virtual ~DrawableContainer() throw();
    virtual void Update_000382a0();
    char pad[0x44];
    Vec_2a4ff0<E_2a4ff0> items;
};
DrawableContainer::~DrawableContainer() throw() {}
} // namespace fn_002a4ff0


// 0x002a5040 pure3d::DrawableContainer::vfunc_2 (30 B): matches/0x002a5040.cpp
// sym: ??_GDrawableContainer@pure3d@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
pure3d::DrawableContainer::~DrawableContainer() {}

