// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f9530..0x001fa960 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "decls/encounter.h"   // (recs1, find2 G20) CEncounterGenerator
#include "gen/content.h"   // (nat2, D134) content::LoadObject's operator delete
#define TREE_TU_BEGIN namespace fn_f80593ac {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f80593ac {} using namespace fn_f80593ac;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f80593ac {
struct Key_1f9630 {
    int w[4];
};
struct Obj_1f9630 : HulkEncounterMapNode {   // (recs1) a node of the encounter map (was char pad[0x20], then the value)
};
extern "C" int FUN_001f92f0(void*, void*); /* (unb4) as defined; address taken only */
class R_1f9630 {
  public:
    Obj_1f9630* find_00230ba0(void (*)(), void*);
};
class C_1f9630 : public HulkEncounterGenerator {   // (recs1) on its record (was char pad[0xc6c], then the map)
  public:
    unsigned short target(Key_1f9630 a);
};
class Cleanup_1f9630 {
  public:
    void go_0027af50();
};
struct Key_1f9670 {
    int w[4];
};
struct Obj_1f9670 : HulkEncounterMapNode {   // (recs1) a node of the encounter map (was char pad[0x20])
};
struct Sub_1f9670 {
    hulk_intptr Find_00230ba0(int (*cb)(), void*);   // (decl1) passes as defined
};
struct Temp_1f9670 {
    void Cleanup_0027af50();
};
struct Receiver_1f9670 : HulkEncounterGenerator {   // (recs1) on its record (was char pad[0xc6c], then the map)
    bool Target(Key_1f9670 a, unsigned short v);
};
extern int Callback_001f92f0();
struct Param {
    int a;
    int b;
    void finish_0027af50();
};
struct Two_1f96b0 {
    volatile unsigned char a, b;
};
struct Temp_1f96b0 {
    int a;
    int pad0;
    unsigned char c, d;
    char pad1[6];
    short b;
    char tail[6];
    void init_0027af30(Param*);
    void finish_0027af50();
};
struct Out_1f96b0 {
    char data[8];
};
struct Mgr_1f96b0 {
    void fn_001f9530(Out_1f96b0*, Temp_1f96b0*);
};
struct Owner_1f96b0 : HulkEncounterGenerator {   // (recs1) on its record (was char pad[0xc6c], then the map)
    void target(Param x, Two_1f96b0 z, int w, short v);
};
struct Key {
    int lo, hi;
    Key() {}
    Key(const Key &other);
    Key *FUN_0027b0e0(const char *name);
    void FUN_0027af70(const Key *other);
    void FUN_0027af50();
};
struct NameEntry {
    Key key;
    char flagA;
    char flagB;
    char unused[6];

    NameEntry() {}
    NameEntry(const NameEntry &o) : key(o.key)
    {
        flagA = o.flagA;
        flagB = o.flagB;
    }
};
struct Item_1f9710 {
    int key;
    char pad04[0x24];
};
struct Sub_1f9710 {
    char pad[0x50];
};
class Table {   // (recs1) the generator's words at its record's members (decls/encounter.h; were 32-bit pads)
public:
    char pad00[HULK_ENC_PAD(title, 0x41c, 0)];
    Sub_1f9710 sub;
    Item_1f9710 items[15];
    char pad6c4[HULK_ENC_PAD(slotCount, 0x6e0, HULK_ENC_AT(title, 0x41c) + sizeof(Sub_1f9710) + 15 * sizeof(Item_1f9710))];
    int count;

    void FUN_001f96b0(NameEntry entry, int id);
};
class Factory_1f9710 {
public:
    char FUN_001fcff0(Sub_1f9710 *sub);
};
} // namespace fn_f80593ac
struct World {
    char pad[0x28];
    Factory_1f9710 *factory;
};
namespace fn_f80593ac {
extern int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
class Slot_1f9710 {   // (recs1) a CEncounter: decls/encounter.h HulkEncounter's words (was char pad00[8])
public:
    void* vftable;
    int f04;
    Table *table;
    char name[0x20];
    int pad2c;
    NameEntry entry;
    int arg3;
    int arg4;
    int f48;
    int f4c;

    void FUN_001f9710(Table *owner, const char *label, int a, int b);
};
struct Sub_1f9f80 {
    void Helper_0027af50();
};
struct Obj_1f9f80 {   // (recs1) a node of the encounter map: its links (HulkEncounterMapNode; was char pad[16]), then the key
    HulkTreeMapLinks links;
    Sub_1f9f80 sub;
};
struct V {
  public:
    virtual void _m_vf0();
    virtual void f1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void f4(void*);
};
struct B_1f9f80 : HulkEncounterMap {   // (recs1) the encounter map (was char pad[0x18], then the pool)
};
class C_1fa610 : public HulkEncounterMap {   // (recs1) the encounter map (was char pad[0x18], then the pool)
  public:
    void target();
};
bool cb_001f9f80(void*, void*); /* (unb4) as defined; address taken only */
struct This_helper {
    void helper_00230f50(void*, void*);
};
class Obj_1fa7a0 : public HulkEncounterMap {   // (recs1) the encounter map (was char pad[0x18], then the pool)
  public:
    struct V {
        virtual void f0();
        virtual void f1();
    };
    Obj_1fa7a0* target(unsigned char flag);
    void FUN_00230f50(void (*)(), Obj_1fa7a0*);
};
extern void FUN_001f9f80();
struct Name {
    char data[12];
    ~Name();
};
class Child_1fa8b0 {
public:
    virtual void v0();
    virtual void Release();
};
void FUN_001f9f80(void *p);
struct Task_1fa8b0 : HulkEncounterMap {   // (recs1) the encounter map (was char pad[0x18], then the pool)
    void FUN_00230f50(void (*callback)(void *), Task_1fa8b0 *self);
};
namespace core {
class IRefCount {
public:
    virtual ~IRefCount();
};
}
class CEncounterGenerator : public core::IRefCount {
public:
    class CEncounter {
    public:
        virtual void* v0_001f94e0(int);
        __forceinline ~CEncounter() {}
        // (recs1) HulkEncounter's words (were 32-bit pads): the key's name at +0x30
        char pad04[HULK_ENCR_PAD(key, 0x30, sizeof(void*))];
        Name name;
        char pad3c[sizeof(HulkEncounter) - HULK_ENCR_PAD(key, 0x30, 0) - sizeof(Name)];
    };
    virtual ~CEncounterGenerator();
    // (recs1) HulkEncounterGenerator's words (were 32-bit pads)
    char pad04[HULK_ENC_PAD(encounters, 0x6e8, sizeof(void*))];
    char encounterSlots[16][sizeof(HulkEncounter)];  // CEncounter objects, destroyed by hand below
    int encounterCount;
    Task_1fa8b0 *task;
};
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_001fa8b0 {
    void FUN_001fa8b0();
};

} // namespace fn_f80593ac

// 0x001f9530 FUN_001f9530 (131 B): equivalent/0x001f9530.cpp [wrapped: conflict: (void (*)())FUN_001f92f0]
// sym: ?FUN_001f9530@Registry_1f9530@fn_001f9530@@QAEPAUHandle_1f9530@2@PAU32@PBUKeyInfo@2@@Z @8105f0d7d74d @wc8449c6cf9b7 @v88c6cf299328
namespace fn_001f9530 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 4/4)
// FUN_001f9530 @ 0x001f9530
struct Id64_1f9530 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af30(const Id64_1f9530 *src);
};

// An entry description: an id followed by two flag bytes and a 16-bit value.
struct KeyInfo {
    Id64_1f9530 id;                // 0x00
    char flagA;             // 0x08
    char flagB;             // 0x09
    char pad0a[6];
    unsigned short value;   // 0x10
};

struct Node {   // (recs1) decls/encounter.h HulkEncounterMapNode's words (was char pad00[0x10] before the key)
    HulkTreeMapLinks links;
    KeyInfo info;           // 0x10
    char pad_end[0x28 - 0x10 - 0x12];
};

class Allocator {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void *vfunc_3(unsigned int size);
};

// the node's key compare (0x001f92b0) and the lookup's match (0x001f92f0: extern "C", declared above), passed as functions
unsigned int FUN_001f92b0(void* a, void* b);

struct Handle_1f9530 {
    Node *node;
    class Registry_1f9530 *owner;
};

class Registry_1f9530 : public HulkEncounterMap {   // (recs1) the encounter map (was char pad00[0x18], then the pool)
public:
    void *FUN_00230be0(void *matcher, const KeyInfo *key);
    void FUN_00230c30(Node *node, void *init, void *found);
    Handle_1f9530 *FUN_001f9530(Handle_1f9530 *out, const KeyInfo *key);
};

Handle_1f9530 *Registry_1f9530::FUN_001f9530(Handle_1f9530 *out, const KeyInfo *key)
{
    void *found = FUN_00230be0((void*)(void (*)())&FUN_001f92f0, key);
    if (found == 0) {
        out->node = 0;
        out->owner = 0;
        return out;
    }

    Node *node = (Node *)((Allocator *)pool)->vfunc_3(sizeof(HulkEncounterMapNode));   // (recs1) 0x28 on the 32-bit builds
    if (node != 0) {
        KeyInfo *copy = &node->info;
        copy->id.FUN_0027af30(&key->id);
        copy->flagA = key->flagA;
        copy->flagB = key->flagB;
        copy->value = key->value;
    }
    FUN_00230c30(node, (void*)&FUN_001f92b0, found);

    out->node = node;
    out->owner = this;
    return out;
}
} // namespace fn_001f9530

namespace fn_f80593ac {

// 0x001f9630 FUN_001f9630 (58 B): matches/0x001f9630.cpp
// sym: ?target@C_1f9630@fn_f80593ac@@QAEGUKey_1f9630@2@@Z
// a..d: the 16-byte name key passed by value (the callers' Key: 8-byte name + index bytes).
unsigned short C_1f9630::target(Key_1f9630 a) {
    Obj_1f9630* o = ((R_1f9630*)map)->find_00230ba0((void (*)())FUN_001f92f0, (void*)&a);
    if (!o) {
        ((Cleanup_1f9630*)&a)->go_0027af50();
        return 0xfffe;
    }
    unsigned short v = o->value;
    ((Cleanup_1f9630*)&a)->go_0027af50();
    return v;
}


// 0x001f9670 FUN_001f9670 (62 B): matches/0x001f9670.cpp
// sym: ?Target@Receiver_1f9670@fn_f80593ac@@QAE_NUKey_1f9670@2@G@Z
// a..d: the 16-byte name key passed by value (the callers' Key: 8-byte name + index bytes).
bool Receiver_1f9670::Target(Key_1f9670 a, unsigned short v) {
    hulk_intptr r = ((Sub_1f9670*)map)->Find_00230ba0(Callback_001f92f0, &a);
    if (!r) {
        ((Temp_1f9670*)&a)->Cleanup_0027af50();
        return false;
    }
    ((Obj_1f9670*)r)->value = v;
    ((Temp_1f9670*)&a)->Cleanup_0027af50();
    return true;
}


// 0x001f96b0 FUN_001f96b0 (92 B): matches/0x001f96b0.cpp
// sym: ?target@Owner_1f96b0@fn_f80593ac@@QAEXUParam@2@UTwo_1f96b0@2@HF@Z
// The 8-byte id, passed by value in two stack words (the original copies both with FUN_0027af30).
void Owner_1f96b0::target(Param x, Two_1f96b0 z, int w, short v) {
    Temp_1f96b0 t;
    t.init_0027af30(&x);
    t.c = z.a;
    t.d = z.b;
    t.b = v;
    Out_1f96b0 o;
    ((Mgr_1f96b0*)map)->fn_001f9530(&o, &t);
    t.finish_0027af50();
    x.finish_0027af50();
}


// 0x001f9710 FUN_001f9710 (250 B): matches/0x001f9710.cpp
// sym: ?FUN_001f9710@Slot_1f9710@fn_f80593ac@@QAEXPAVTable@2@PBDHH@Z
// FUN_001f9710 @ 0x001f9710
// equiv-map: ??0Key@@QAE@ABU0@@Z = 0x0027af30
void Slot_1f9710::FUN_001f9710(Table *owner, const char *label, int a, int b)
{
    table = owner;
    FUN_00267760(name, 0x20, "%s", label);
    arg3 = a;
    arg4 = b;
    f48 = 0;
    f4c = 0;
    entry.flagA = DAT_004dd700->factory->FUN_001fcff0(&owner->sub);
    Key tmp;
    entry.key.FUN_0027af70(tmp.FUN_0027b0e0(label));
    tmp.FUN_0027af50();
    for (int i = 0; i < table->count; i++) {
        Item_1f9710 *item = &table->items[i];
        if (item->key == -1 || item->key == -2)
            continue;
        entry.flagB = (char)i;
        table->FUN_001f96b0(entry, (short)item->key);
    }
    entry.flagB = (char)0xff;
}


// 0x001f9f80 FUN_001f9f80 (30 B): matches/0x001f9f80.cpp
// sym: ?Target@fn_f80593ac@@YA_NPAUObj_1f9f80@1@PAUB_1f9f80@1@@Z
bool Target(Obj_1f9f80* a, B_1f9f80* b) {
    a->sub.Helper_0027af50();
    ((V*)b->pool)->f4(a);
    return true;
}

} // namespace fn_f80593ac

// 0x001f9fc0 FUN_001f9fc0 (107 B): equivalent/0x001f9fc0.cpp [wrapped: conflict: Node]
// sym: ?FUN_001f9fc0@Mixer@fn_001f9fc0@@QAE_NUSlotKey_1f9fc0@2@@Z @45d653316bb5 @w0065ac87e6d1 @vc9c97597c192
namespace fn_001f9fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 2/2)
// FUN_001f9fc0 @ 0x001f9fc0
struct S8_1f9fc0 {
    int a;
    int b;
    void FUN_0027af50();
};
struct SlotKey_1f9fc0 {
    S8_1f9fc0 name;
    char flagA;
    char flagB;
    char pad[6];
};
struct Node { HulkTreeMapLinks links; S8_1f9fc0 value; };   // (recs1) HulkEncounterMapNode's words (was char pad[16])
struct Allocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void release(Node *n);
};
int FUN_001f92f0(void*, void*); /* (unb4) as defined; address taken only */
struct Container_1f9fc0 : HulkEncounterMap {   // (recs1) the encounter map (was char pad[24], then the pool)
    Node *FUN_00230ba0(void (*fn)(), SlotKey_1f9fc0 *key);
    void FUN_00230de0(Node *n);
};
class Mixer : public HulkEncounterGenerator {   // (recs1) on its record (was char pad000[0xc6c], then the map)
public:
    bool FUN_001f9fc0(SlotKey_1f9fc0 key);
};
bool Mixer::FUN_001f9fc0(SlotKey_1f9fc0 key)
{
    Container_1f9fc0 *c = (Container_1f9fc0 *)map;
    Node *n = c->FUN_00230ba0((void (*)())FUN_001f92f0, &key);
    if (n != 0) {
        c->FUN_00230de0(n);
        n->value.FUN_0027af50();
        ((Allocator *)c->pool)->release(n);
        key.name.FUN_0027af50();
        return true;
    }
    key.name.FUN_0027af50();
    return false;
}
} // namespace fn_001f9fc0


// 0x001fa040 FUN_001fa040 (370 B): equivalent/0x001fa040.cpp [wrapped: conflict: FUN_00267760]
// sym: ?FUN_001fa040@Table_1fa040@fn_001fa040@@QAEXXZ @0408d1f9b739 @w573bdc6c0c6c @ve1cb78219f00
namespace fn_001fa040 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_001fa040 @ 0x001fa040
struct Name_1fa040 {
    unsigned int lo, hi;
};
struct Tree_1fa040 {
    void FUN_00230f50(void (__cdecl *cb)(void*, void*), void* user);
};
struct Pool_1fa040 {
};
Pool_1fa040* FUN_001d4c90();
void FUN_00267760(char* dst, int n, const char* fmt, ...);
void __cdecl FUN_001f9f80(void* node, void* user);

// (recs1, find2 G20) the generator on its record (decls/encounter.h; the views were 32-bit pads, and the encounter
// slots were read 8 bytes in, so the map pointer was the last slot's +0x54)
class Table_1fa040 : public HulkEncounterGenerator {
public:
    void FUN_001fa040();
};

void Table_1fa040::FUN_001fa040()
{
    count = 0;
    firstActive = -1;
    activeCount = 0;
    ((owners::Target_27b040 *)entityName)->FUN_0027b040((hulk_uintptr)"CONSTRUCTED, BUT NOT YET NAMED");
    FUN_00267760(title, 0x20, "%s", "CONSTRUCTED, BUT NOT YET NAMED");
    f43c = 0;
    enabled = 0;
    f454 = 1;
    state = 0;
    f45c = 0;
    slotCount = 0;
    encounterCount = 0;
    for (int i = 0; i < 16; i++) {
        HulkEncounterSlot& s = slots[i];
        s.obj = 0;
        s.w[0] = -1;
        s.w[1] = -1;
        s.w[2] = 0;
        s.w[3] = 0;
        s.w[4] = 0;
        s.w[5] = 0;
        *(int*)&s.radius = 0;
        s.active = 0;
        Pool_1fa040* p = FUN_001d4c90();
        ((owners::Obj_1d1900 *)p)->FUN_001d1900((hulk_intptr)(s.tracker));
        s.tracker = -1;
    }
    for (int j = 0; j < 16; j++) {
        HulkEncounter& s = encounters[j];
        s.table = 0;
        FUN_00267760(s.name, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
        s.f40 = 0;
        s.f44 = 0;
        s.f48 = 0;
        s.f4c = 0;
        s.key.a = 0xff;
        ((owners::Target_27b040 *)(s.key.name))->FUN_0027b040((hulk_uintptr)"");
        s.key.b = 0xff;
        s.b50 = 0;
        s.b51 = 1;
        s.w52 = 0xffff;
    }
    *(int*)flags440 = 0;
    *(short*)(flags440 + 4) = 0;
    Tree_1fa040* tree = (Tree_1fa040*)map;
    tree->FUN_00230f50(FUN_001f9f80, tree);
    Pool_1fa040* pool = FUN_001d4c90();
    ((owners::Obj_1d1900 *)pool)->FUN_001d1900((hulk_intptr)f448);
    int old = f44c;
    f448 = -1;
    ((owners::Obj_1d1900 *)pool)->FUN_001d1900((hulk_intptr)old);
    f44c = -1;
}
} // namespace fn_001fa040


// 0x001fa500 FUN_001fa500 (262 B): equivalent/0x001fa500.cpp [wrapped: conflict: Node]
// sym: ?target@Object@fn_001fa500@@QAEXH@Z @1c082434cd96 @wc5985ed700da @v9b375c82a58b
namespace fn_001fa500 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001fa500 @ 0x001fa500
struct Value_1fa500 { char data[8]; void FUN_0027af30(Value_1fa500*); void FUN_0027af50(); };
struct Key_1fa500 { Value_1fa500 value; unsigned char a,b; };
struct Node { HulkTreeMapLinks links; Value_1fa500 value; };   // (recs1) HulkEncounterMapNode's words (was char pad[16])
struct Allocator { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void release(Node*); };
int FUN_001f92f0(void*, void*); /* (unb4) as defined; address taken only */
struct Container_1fa500 : HulkEncounterMap { /* (recs1) the encounter map (was char pad[24], then the pool) */ Node* FUN_00230ba0(void (*)(void), Key_1fa500*); void FUN_00230de0(Node*); };
// (recs1, find2 G20) the generator on its record (decls/encounter.h; was a view with 32-bit pads): the encounters' keys
struct Object : HulkEncounterGenerator { void FUN_001fa3a0(int); void target(int); };
void Object::target(int mode) {
 state=mode;
 if(mode==1 && enabled) {
  for(int i=0;i<encounterCount;++i) {
   for(int j=0;j<slotCount;++j) {
    encounters[i].key.b=(unsigned char)j;
    Key_1fa500 key;
    key.value.FUN_0027af30((Value_1fa500*)encounters[i].key.name);
    key.a=encounters[i].key.a;
    Container_1fa500* c=(Container_1fa500*)map;
    key.b=encounters[i].key.b;
    Node* n=c->FUN_00230ba0((void (*)())FUN_001f92f0,&key);
    if(n) { c->FUN_00230de0(n); n->value.FUN_0027af50(); ((Allocator*)c->pool)->release(n); }
    key.value.FUN_0027af50();
   }
   FUN_001fa3a0(i);
  }
 }
}
} // namespace fn_001fa500

namespace fn_f80593ac {

// 0x001fa610 FUN_001fa610 (23 B): matches/0x001fa610.cpp
// sym: ?target@C_1fa610@fn_f80593ac@@QAEXXZ
void C_1fa610::target() {
    ((This_helper*)this)->helper_00230f50((void*)(void (*)())cb_001f9f80, this);
    ((V*)pool)->f1();
}

} // namespace fn_f80593ac

// 0x001fa630 FUN_001fa630 (354 B): equivalent/0x001fa630.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CEncounterGenerator@fn_001fa630@@QAE@XZ @b1dd0f2735b1 @wb1c7f9924423 @v7dda5f65418e
inline void *operator new(size_t, void *p) { return p; }
namespace fn_001fa630 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 8/8)
// FUN_001fa630 @ 0x001fa630


extern "C" void *FUN_0008d690(unsigned int size);

class Pool_1fa630 {
public:
    virtual void AddRef();
    virtual void Release();
};

// (recs1, find2 G20) the encounter map (decls/encounter.h; was char pad0[0x18], then the pool: allocated 0x1c)
struct EncObj : HulkEncounterMap {
    void FUN_00230b60();
};

struct Tracker_1fa630 {
    void FUN_001d1900(hulk_intptr id);   // (decl1, find3) as defined (ScriptHandler.cpp: owners::Obj_1d1900::FUN_001d1900(hulk_intptr))
};

struct NameHolder_1fa630 {
    char pad[8];
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

Tracker_1fa630 *__cdecl FUN_001d4c90();
void __cdecl FUN_00267760(char *dst, int size, const char *src, ...);
void __cdecl FUN_002702a0(Pool_1fa630 **out, int a, int b, int c, int d, const char *name, int e);

// (recs1, find2 G20) the generator and its encounters on their records (decls/encounter.h), the game's vftables stored
// by address (were local polymorphic stand-ins with 32-bit pads: clang's own vftables natively)
extern "C" char DAT_00424fa4[];   // CEncounterGenerator's vftable
extern "C" char DAT_00424f04[];   // CEncounterGenerator::CEncounter's
class CEncounterGenerator : public HulkEncounterGenerator {
public:
    CEncounterGenerator();
    void FUN_0027b070();   // pure3d::Entity's constructor
    void FUN_001fa040();
};

CEncounterGenerator::CEncounterGenerator()
{
    FUN_0027b070();
    vftable = DAT_00424fa4;
    int i;
    for (i = 0; i < 16; i++) {
        HulkEncounterSlot *e = &slots[i];
        e->tracker = -1;
        e->obj = 0;
        e->w[0] = -1;
        e->w[1] = -1;
        e->w[2] = 0;
        e->w[3] = 0;
        e->w[4] = 0;
        e->w[5] = 0;
        *(int*)&e->radius = 0;
        e->active = 0;
        Tracker_1fa630 *t = FUN_001d4c90();
        t->FUN_001d1900(*(volatile int *)&e->tracker);
        e->tracker = -1;
    }
    for (i = 0; i < 16; i++) {
        HulkEncounter *c = &encounters[i];
        c->vftable = DAT_00424f04;
        ((NameHolder_1fa630 *)&c->key)->FUN_0027af00();
        c->w52 = 0;
        c->table = 0;
        FUN_00267760(c->name, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
        c->f40 = 0;
        c->f44 = 0;
        c->f48 = 0;
        c->f4c = 0;
        c->key.a = 0xff;
        ((NameHolder_1fa630 *)&c->key)->FUN_0027b040(((const char*)&DAT_003f335c));
        c->key.b = 0xff;
        c->b50 = 0;
        c->b51 = 1;
        c->w52 = 0xffff;
    }

    Pool_1fa630 *pool;
    bool held = false;
    FUN_002702a0(&pool, 0x28, 0x100, 0, 0, "encounterGenerator: Memory Map Pool", 4);
    EncObj *obj = (EncObj *)FUN_0008d690((int)sizeof(EncObj));
    if (obj) {
        Pool_1fa630 *p = pool;
        held = true;
        p->AddRef();
        obj->pool = p;
        obj->FUN_00230b60();
    } else {
        obj = 0;
    }
    map = obj;
    if (held)
        pool->Release();
    f448 = -1;
    f44c = -1;
    FUN_001fa040();
}
} // namespace fn_001fa630

namespace fn_f80593ac {

// 0x001fa7a0 FUN_001fa7a0 (44 B): matches/0x001fa7a0.cpp
// sym: ?target@Obj_1fa7a0@fn_f80593ac@@QAEPAV12@E@Z
Obj_1fa7a0* Obj_1fa7a0::target(unsigned char flag) {
    FUN_00230f50(&FUN_001f9f80, this);
    ((V*)pool)->f1();
    if (flag & 1)
        ::operator delete(this);
    return this;
}

} // namespace fn_f80593ac

// 0x001fa7d0 FUN_001fa7d0 (216 B): equivalent/0x001fa7d0.cpp [wrapped: conflict: Object]
// sym: ?FUN_001fa7d0@Object@fn_001fa7d0@@QAE_NHH@Z @2fd4ca70aaff @w278c8e953658 @v5124b64983f7
namespace fn_001fa7d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001fa7d0 @ 0x001fa7d0
struct Entry_1fa7d0 : HulkEncounter { void FUN_001f9810(int value); };
// (recs1, find2 G20) the generator on its record (decls/encounter.h; was a view with 32-bit pads)
struct Object : HulkEncounterGenerator {
 bool FUN_001f9040(void* input, void* item);   // (recs1) as defined: the source and the entry are pointers
 bool FUN_001f87e0(void* input, void* item, int* index);
 void FUN_001fa1c0(void* input, void* item);
 void FUN_001fa3a0(int index);
 bool FUN_001fa7d0(hulk_intptr input, int value);
};
bool Object::FUN_001fa7d0(hulk_intptr input, int value) {
 if (!input || state != 2) return false;
 bool result = false;
 for (int i = 0; i < count; ++i) {
  int index = -1;
  bool first = FUN_001f9040((void*)input, items[i]);
  bool second = FUN_001f87e0((void*)input, items[i], &index);
  if (first) {
   if (second) ((Entry_1fa7d0*)&encounters[index])->FUN_001f9810(value);
   else FUN_001fa1c0((void*)input, items[i]);
   result = true;
  } else if (second) FUN_001fa3a0(index);
 }
 return result;
}
} // namespace fn_001fa7d0

namespace fn_f80593ac {

// 0x001fa8b0 FUN_001fa8b0 (110 B): equivalent/0x001fa8b0.cpp
// sym: ??1CEncounterGenerator@fn_f80593ac@@UAE@XZ @e199415a263f @w4a34322ff1b5 @vd8ebf0cc9785
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001fa8b0 @ 0x001fa8b0
// equiv-map: ??1IRefCount@core@@UAE@XZ = 0x0027afd0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
CEncounterGenerator::~CEncounterGenerator()
{
    Task_1fa8b0 *t = task;
    if (t != 0) {
        t->FUN_00230f50(FUN_001f9f80, t);
        ((Child_1fa8b0*)t->pool)->Release();
        ::operator delete(t);
    }
    task = 0;
    for (int i = 15; i >= 0; i--)
        ((CEncounter *)encounterSlots[i])->~CEncounter();
}


// 0x001fa920 FUN_001fa920 (30 B): matches/0x001fa920.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f80593ac@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_001fa8b0*)(this))->FUN_001fa8b0();
    if ((flags & 1) != 0)
        ::content::LoadObject::operator delete(this);
    return this;
}

} // namespace fn_f80593ac
