// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000c6a90..0x000c7280 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcfef481 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcfef481 {} using namespace fn_fcfef481;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fcfef481 {
struct Box_c6a90 { float x0, y0, z0, x1, y1, z1; };
struct Shape_c6a90 { char pad[0x14]; Box_c6a90 box; };
struct Size { unsigned x, y, z; };
union FloatBits_c6a90 { float f; unsigned u; };
class DynamicCaster {
  public:
    virtual void f();
};
class Obj {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(DynamicCaster*, __int64);
    hulk_intptr Fn(const char*);
};
extern "C" __int64 __cdecl Find(const char*, int, int);
} // namespace fn_fcfef481
inline void *operator new(size_t, void *p) { return p; }
unsigned __int64 __cdecl FUN_002672f0(const char *name, int a, int b);
unsigned __int64 __cdecl FUN_0027b020(const char *name);
namespace fn_fcfef481 {
namespace content { namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
namespace content { namespace LoadInventory {
template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
} }
struct Sub;
struct Resource {
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Sub *v11();
};
struct Loader {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Resource *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned __int64 key);
};
struct Result {
    Sub *sub;
    int pad4;
    unsigned __int64 key;
};
namespace pure3d {
class CompositeDrawable_c6bc0;
}
struct Sub_c6bc0 {
    int FUN_002843a0(unsigned __int64 key);
};
struct Resource_c6bc0 {
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Sub_c6bc0 *v11();
};
struct Loader_c6bc0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Resource_c6bc0 *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_c6bc0> *caster, unsigned __int64 key);
};
struct Index_c6c40 {
    int FUN_0027b200(unsigned __int64 key);
};
struct Info_c6c40 {
    char pad00[8];
    Index_c6c40 *index;
};
struct Entry_c6c40 {
    int unused;
    int key;
    int value;
};
struct EntryList_c6c40 {
    char pad00[0x3c];
    Entry_c6c40 *begin;
    Entry_c6c40 *end;
};
struct Resource_c6c40 {
    virtual void AddRef();
    virtual void Release();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual Info_c6c40 *v11();
    char pad04[0x40];
    EntryList_c6c40 *list;
};
struct Loader_c6c40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Resource_c6c40 *v3(content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *caster, unsigned __int64 key);
};
extern void __cdecl FUN_000c6a90(int found, int value);
struct Name_c6f20 {
    int lo, hi;
    Name_c6f20 *FUN_0027af00();
    void FUN_0027af70(const Name_c6f20 *src);
    void FUN_0027af50();
};
struct Slot_c6f20 {
    int kind;       // -1 when free
    int a;
    int b;
    int c;
    Name_c6f20 name;
    int value;
    int pad1c;
};
class SlotTable_c6f20 {
public:
    int FUN_000c6f20(int kind, int a, int b, int c);

    char pad0[0x60];
    Slot_c6f20 slots[16];
};
struct ResourceName_c6fe0 {
 unsigned int first, second;
 void FUN_0027af50();
 void FUN_0027af70(ResourceName_c6fe0* source);
};
extern "C" void __cdecl FUN_00096e50(ResourceName_c6fe0* result, const char* name);
struct Lookup_c6fe0 { int FUN_00024280(unsigned int first, unsigned int second); };
struct Loader_c6fe0 { bool FUN_001dd7b0(ResourceName_c6fe0* name); };
} // namespace fn_fcfef481
struct World { char pad0[12]; Loader_c6fe0* loader; char pad1[16]; Lookup_c6fe0* lookup; };
namespace fn_fcfef481 {
struct Entry_c6fe0 {
 int id;
 unsigned int state, count, flags;
 ResourceName_c6fe0 name;
 unsigned int extra;
 unsigned int reserved;
};
struct Manager_c6fe0 {
 char pad[0x60];
 Entry_c6fe0 entries[16];
 int FUN_000c6fe0(int id, const char* name);
};
struct Name_c70c0 {
    int lo, hi;
    Name_c70c0 *FUN_0027af00();
    void FUN_0027af70(const Name_c70c0 *src);
    void FUN_0027af50();
};
struct Slot_c70c0 {
    int kind;       // -1 when free
    int a;
    int b;
    int c;
    Name_c70c0 name;
    int value;
    int pad1c;
};
class SlotTable_c70c0 {
public:
    int FUN_000c70c0(int value);

    char pad0[0x60];
    Slot_c70c0 slots[16];
};
struct Temporary {
    char data[8];
    unsigned int FUN_0027af00();
    void FUN_0027af50();
};
struct ItemValue {
    void FUN_0027af70(unsigned int value);
    int unused;
};
struct Record {
    int status;
    int first;
    int second;
    int third;
    ItemValue value;
    int reserved;
    int fourth;
    int padding;
};
struct Manager {
    char padding[0x60];
    Record records[17];
    void FUN_000c7140(int index);
};


// 0x000c6a90 FUN_000c6a90 (138 B): equivalent/0x000c6a90.cpp
// sym: ?BoxExtent@fn_fcfef481@@YAXPAUShape_c6a90@1@PAUSize@1@@Z @f7738c8519ea @wea93c15ec795
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000c6a90 @ 0x000c6a90
void BoxExtent(Shape_c6a90* s, Size* out) {
    if (!s) return;
    Box_c6a90 b = s->box;
    FloatBits_c6a90 d;
    d.f = b.x1 - b.x0; out->x = d.u & 0x7fffffff;
    d.f = b.y1 - b.y0; out->y = d.u & 0x7fffffff;
    d.f = b.z1 - b.z0; out->z = d.u & 0x7fffffff;
}


// 0x000c6b20 FUN_000c6b20 (50 B): matches/0x000c6b20.cpp
// sym: ?Fn@Obj@fn_fcfef481@@QAEHPBD@Z
hulk_intptr Obj::Fn(const char* name) {
    DynamicCaster caster;
    return v3(&caster, Find(name, 0, 0));
}


// 0x000c6b60 FUN_000c6b60 (89 B): equivalent/0x000c6b60.cpp
// sym: _FUN_000c6b60 @36c38c02fce0 @w3d4bd4b6c7a5
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 2/2)
// FUN_000c6b60 @ 0x000c6b60
extern "C" void FUN_000c6b60(const char *name, const char *subName, Result *out)
{
    Loader *loader = (*(Loader**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    // the original loads the loader's vptr before FUN_002672f0 and the slot after it
    typedef Resource *(__fastcall *V3Fn)(Loader*, int, content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *, unsigned __int64);
    void **vtable = *(void ***)loader;
    unsigned __int64 id64 = FUN_002672f0(name, 0, 0);
    Resource *res = ((V3Fn)vtable[3])(loader, 0, &caster, id64);
    if (res) {
        out->sub = res->v11();
        out->key = FUN_0027b020(subName);
    }
}


// 0x000c6bc0 FUN_000c6bc0 (123 B): equivalent/0x000c6bc0.cpp
// sym: _FUN_000c6bc0 @1080b414f18a @w5488879caff0
// STATUS: equivalent (tools/equiv.py level 3: 20014 inputs, branch coverage 2/2)
// FUN_000c6bc0 @ 0x000c6bc0
extern "C" void FUN_000c6bc0(const char *name, const char *sub, int value)
{
    Loader_c6bc0 *loader = (*(Loader_c6bc0**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_c6bc0> caster;
    // the original loads the loader's vptr before FUN_002672f0 and the slot after it
    typedef Resource_c6bc0 *(__fastcall *V3Fn)(Loader_c6bc0*, int, content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable_c6bc0> *, unsigned __int64);
    void **vtable = *(void ***)loader;
    unsigned __int64 id64 = FUN_002672f0(name, 0, 0);
    Resource_c6bc0 *res = ((V3Fn)vtable[3])(loader, 0, &caster, id64);
    if (res) {
        res->AddRef();
        unsigned __int64 subKey = FUN_0027b020(sub);
        int id = res->v11()->FUN_002843a0(subKey);
        ((owners::Obj_2848b0 *)(res->v11()))->FUN_002848b0((hulk_intptr)id, 0, (int *)(hulk_uintptr)(int)value);
        res->Release();
    }
}


// 0x000c6c40 FUN_000c6c40 (233 B): equivalent/0x000c6c40.cpp
// sym: _FUN_000c6c40 @c68c6a4a0b74 @wf0c4aa08b18e
// STATUS: equivalent (tools/equiv.py level 3: 20018 inputs, branch coverage 8/8)
// FUN_000c6c40 @ 0x000c6c40
extern "C" void FUN_000c6c40(const char *name, const char *key, int value)
{
    Loader_c6c40 *loader = (*(Loader_c6c40**)&DAT_004dd9cc);
    content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> caster;
    // the original loads the loader's vptr before FUN_002672f0 and the slot after it
    typedef Resource_c6c40 *(__fastcall *V3Fn)(Loader_c6c40*, int, content::LoadInventory::DynamicCaster<pure3d::CompositeDrawable> *, unsigned __int64);
    void **vtable = *(void ***)loader;
    unsigned __int64 id64 = FUN_002672f0(name, 0, 0);
    Resource_c6c40 *res = ((V3Fn)vtable[3])(loader, 0, &caster, id64);
    if (res) {
        res->AddRef();
        Index_c6c40 *index = res->v11()->index;
        int id = index->FUN_0027b200(FUN_0027b020(key));
        EntryList_c6c40 *list = res->list;
        int found = 0;
        for (int i = 0; i < (unsigned char)(list->end - list->begin); i++) {
            Entry_c6c40 *e = &list->begin[(unsigned char)i];
            if (e->key == id) {
                found = e->value;
                break;
            }
        }
        FUN_000c6a90(found, value);
        res->Release();
    }
}

} // namespace fn_fcfef481

// 0x000c6eb0 FUN_000c6eb0 (37 B): matches/0x000c6eb0.cpp [wrapped: conflict: Obj]
// sym: ??0Obj@fn_000c6eb0@@QAE@XZ
namespace fn_000c6eb0 {
struct First {
    int a;
    First() : a(-1) {}
};
struct Rest {
    int b, c, d;
    Rest() : b(0), c(0), d(0) {}
};
struct Sub {
    Sub();
    char pad[8];
};
struct Obj {
    Obj();
    First first;
    Rest rest;
    Sub sub;
    int tail;
};
Obj::Obj() : tail(0) {}
} // namespace fn_000c6eb0

namespace fn_fcfef481 {

// 0x000c6f20 FUN_000c6f20 (124 B): equivalent/0x000c6f20.cpp
// sym: ?FUN_000c6f20@SlotTable_c6f20@fn_fcfef481@@QAEHHHHH@Z @a8fecade7cd3 @we0108de6c37a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c6f20 @ 0x000c6f20
// Claims the first free slot with the given kind and parameters and returns its index, or -1 when full.
int SlotTable_c6f20::FUN_000c6f20(int kind, int a, int b, int c) {
    for (int i = 0; i < 16; i++) {
        if (slots[i].kind == -1) {
            Slot_c6f20 *slot = &slots[i];
            slots[i].kind = kind;
            Name_c6f20 empty;
            slot->name.FUN_0027af70(empty.FUN_0027af00());
            empty.FUN_0027af50();
            slot->c = c;
            slot->a = a;
            slot->b = b;
            slot->value = 0;
            return i;
        }
    }
    return -1;
}

} // namespace fn_fcfef481

// 0x000c6fa0 FUN_000c6fa0 (55 B): matches/0x000c6fa0.cpp
// sym: ?FUN_000c6fa0@C_c6fa0@owners@@QAEXHHHH@Z
void owners::C_c6fa0::FUN_000c6fa0(int index, int a, int b, int c) {
    if (index >= 0 && index <= 16 && *((int*)this + (index + 3) * 8) != -1) {
        int* p = (int*)((char*)this + index * 32 + 100);
        p[0] = a;
        p[1] = b;
        p[2] = c;
    }
}

namespace fn_fcfef481 {

// 0x000c6fe0 FUN_000c6fe0 (215 B): equivalent/0x000c6fe0.cpp
// sym: ?FUN_000c6fe0@Manager_c6fe0@fn_fcfef481@@QAEHHPBD@Z @74fc454ca7d6 @we1c71826ec79
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000c6fe0 @ 0x000c6fe0
int Manager_c6fe0::FUN_000c6fe0(int id, const char* name) {
 ResourceName_c6fe0 key;
 FUN_00096e50(&key, name);
 if (!DAT_004dd700->lookup->FUN_00024280(key.first, key.second) &&
     !DAT_004dd700->loader->FUN_001dd7b0(&key)) {
  key.FUN_0027af50();
  return -1;
 }
 for (int i = 0; i < 16; ++i) {
  if (entries[i].id == -1) {
   entries[i].id = id;
   entries[i].name.FUN_0027af70(&key);
   entries[i].state = 0;
   entries[i].count = 0;
   entries[i].flags = 0;
   entries[i].extra = 0;
   key.FUN_0027af50();
   return i;
  }
 }
 key.FUN_0027af50();
 return -1;
}


// 0x000c70c0 FUN_000c70c0 (124 B): equivalent/0x000c70c0.cpp
// sym: ?FUN_000c70c0@SlotTable_c70c0@fn_fcfef481@@QAEHH@Z @820a9ce7f8ed @w373fe97909bc
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000c70c0 @ 0x000c70c0
// Claims the first free slot as kind 5 and returns its index, or -1 when full.
int SlotTable_c70c0::FUN_000c70c0(int value) {
    for (int i = 0; i < 16; i++) {
        if (slots[i].kind == -1) {
            Slot_c70c0 *slot = &slots[i];
            slots[i].kind = 5;
            Name_c70c0 empty;
            slot->name.FUN_0027af70(empty.FUN_0027af00());
            empty.FUN_0027af50();
            slot->a = 0;
            slot->b = 0;
            slot->c = 0;
            slot->value = value;
            return i;
        }
    }
    return -1;
}


// 0x000c7140 FUN_000c7140 (92 B): equivalent/0x000c7140.cpp
// sym: ?FUN_000c7140@Manager@fn_fcfef481@@QAEXH@Z @f0c789bf313a @w5b9e312c5743
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000c7140 @ 0x000c7140
void Manager::FUN_000c7140(int index) {
    if (index >= 0 && index <= 16 && records[index].status != -1) {
        Temporary temporary;
        records[index].status = -1;
        unsigned int value = temporary.FUN_0027af00();
        records[index].value.FUN_0027af70(value);
        temporary.FUN_0027af50();
        records[index].first = 0;
        records[index].second = 0;
        records[index].third = 0;
        records[index].fourth = 0;
    }
}

} // namespace fn_fcfef481

// 0x000c71a0 FUN_000c71a0 (182 B): equivalent/0x000c71a0.cpp [wrapped: conflict: World]
// sym: ?FUN_000c71a0@Owner_c71a0@fn_000c71a0@@QAE_NIPAUVector@2@@Z @9009ec4964d8 @w1427302ab678
namespace fn_000c71a0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000c71a0 @ 0x000c71a0
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

struct Vector { unsigned int x, y, z; };
struct Handle_c71a0 { unsigned int low, high; };
struct Object {
 char pad[0x1b0c];
 float value;
 void FUN_000350c0(Vector* out);
};
struct Lookup_c71a0 { Object* FUN_00024280(unsigned int low, unsigned int high); };
struct Service_c71a0 {
 bool FUN_001dd7b0(Handle_c71a0* handle);
 bool FUN_001dd660(Handle_c71a0* handle, Vector* out);
 int FUN_001e3410(Handle_c71a0* handle);
};
struct World { char pad0[0xc]; Service_c71a0* service; char pad1[0x10]; Lookup_c71a0* lookup; };
struct Entry_c71a0 { Vector position; Handle_c71a0 handle; char pad[12]; };
struct Owner_c71a0 { char pad[0x64]; Entry_c71a0 entries[1]; bool FUN_000c71a0(unsigned int index, Vector* out); };
bool Owner_c71a0::FUN_000c71a0(unsigned int index, Vector* out) {
 Entry_c71a0& e = entries[index];
 unsigned int low = e.handle.low, high = e.handle.high;
 World* manager = DAT_004dd700;
 Service_c71a0* service = manager->service;
 if ((low | high) == 0) {
 out->x = e.position.x;
 out->y = e.position.y;
 out->z = e.position.z;
 return true;
 }
 Object* object = manager->lookup->FUN_00024280(low, high);
 if (object) {
 if (object->value <= 0.0f) return false;
 object->FUN_000350c0(out);
 return true;
 }
 if (!service->FUN_001dd7b0(&e.handle)) return false;
 if (!service->FUN_001dd660(&e.handle, out)) return false;
 return service->FUN_001e3410(&e.handle) > 0;
}
} // namespace fn_000c71a0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

