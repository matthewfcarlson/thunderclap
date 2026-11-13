// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001f9530..0x001fa960 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
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
struct Obj_1f9630 {
    char pad[0x20];
    unsigned short value;
};
extern "C" int FUN_001f92f0(void*, void*); /* (unb4) as defined; address taken only */
class R_1f9630 {
  public:
    Obj_1f9630* find_00230ba0(void (*)(), void*);
};
class C_1f9630 {
  public:
    char pad[0xc6c];
    R_1f9630* field;
    unsigned short target(Key_1f9630 a);
};
class Cleanup_1f9630 {
  public:
    void go_0027af50();
};
struct Key_1f9670 {
    int w[4];
};
struct Obj_1f9670 {
    char pad[0x20];
    unsigned short value;
};
struct Sub_1f9670 {
    int Find_00230ba0(int (*cb)(), void*);
};
struct Temp_1f9670 {
    void Cleanup_0027af50();
};
struct Receiver_1f9670 {
    char pad[0xc6c];
    Sub_1f9670* sub;
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
struct Owner_1f96b0 {
    char pad[0xc6c];
    Mgr_1f96b0* mgr;
    void target(Param x, Two_1f96b0 z, int w, short v);
};
struct Key {
    int lo, hi;
    Key() throw() {}
    Key(const Key &other) throw();
    Key *FUN_0027b0e0(const char *name);
    void FUN_0027af70(const Key *other);
    void FUN_0027af50();
};
struct NameEntry {
    Key key;
    char flagA;
    char flagB;
    char unused[6];

    NameEntry() throw() {}
    NameEntry(const NameEntry &o) throw() : key(o.key)
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
class Table {
public:
    char pad00[0x41c];
    Sub_1f9710 sub;
    Item_1f9710 items[15];
    char pad6c4[0x1c];
    int count;

    void FUN_001f96b0(NameEntry entry, int id) throw();
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
class Slot_1f9710 {
public:
    char pad00[8];
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
struct Obj_1f9f80 {
    char pad[16];
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
struct B_1f9f80 {
    char pad[0x18];
    V* p;
};
class C_1fa610 {
  public:
    char pad[0x18];
    V* p;
    void target();
};
bool cb_001f9f80(void*, void*); /* (unb4) as defined; address taken only */
struct This_helper {
    void helper_00230f50(void*, void*);
};
class Obj_1fa7a0 {
  public:
    char pad[0x18];
    struct V {
        virtual void f0();
        virtual void f1();
    };
    V* member;
    Obj_1fa7a0* target(unsigned char flag);
    void FUN_00230f50(void (*)(), Obj_1fa7a0*);
};
extern void FUN_0008d330(Obj_1fa7a0*);
extern void FUN_001f9f80();
void thunk_FUN_00267090(void *p) throw();
struct Name {
    char data[12];
    ~Name() throw();
};
class Child_1fa8b0 {
public:
    virtual void v0() throw();
    virtual void Release() throw();
};
void FUN_001f9f80(void *p) throw();
struct Task_1fa8b0 {
    char pad[0x18];
    Child_1fa8b0 *child;
    void FUN_00230f50(void (*callback)(void *), Task_1fa8b0 *self) throw();
};
namespace core {
class IRefCount {
public:
    virtual ~IRefCount() throw();
};
}
class CEncounterGenerator : public core::IRefCount {
public:
    class CEncounter {
    public:
        virtual void* v0_001f94e0(int);
        __forceinline ~CEncounter() throw() {}
        char pad04[0x30 - 4];
        Name name;
        char pad3c[0x58 - 0x3c];
    };
    virtual ~CEncounterGenerator() throw();
    char pad04[0x6e8 - 4];
    char encounterSlots[16][0x58];  // CEncounter objects, destroyed by hand below
    char pad_c68[4];
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
extern void thunk_FUN_00267090(CCollisionAction*);

} // namespace fn_f80593ac

// 0x001f9530 FUN_001f9530 (131 B): equivalent/0x001f9530.cpp [wrapped: conflict: (void (*)())FUN_001f92f0]
// sym: ?FUN_001f9530@Registry_1f9530@fn_001f9530@@QAEPAUHandle_1f9530@2@PAU32@PBUKeyInfo@2@@Z @8105f0d7d74d @wc8449c6cf9b7
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

struct Node {
    char pad00[0x10];
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

class Registry_1f9530 {
public:
    char pad00[0x18];
    Allocator *allocator;   // 0x18
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

    Node *node = (Node *)allocator->vfunc_3(0x28);
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
    Obj_1f9630* o = field->find_00230ba0((void (*)())FUN_001f92f0, (void*)&a);
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
    hulk_intptr r = sub->Find_00230ba0(Callback_001f92f0, &a);
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
    mgr->fn_001f9530(&o, &t);
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
    b->p->f4(a);
    return true;
}

} // namespace fn_f80593ac

// 0x001f9fc0 FUN_001f9fc0 (107 B): equivalent/0x001f9fc0.cpp [wrapped: conflict: Node]
// sym: ?FUN_001f9fc0@Mixer@fn_001f9fc0@@QAE_NUSlotKey_1f9fc0@2@@Z @45d653316bb5 @w0065ac87e6d1
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
struct Node { char pad[16]; S8_1f9fc0 value; };
struct Allocator {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void release(Node *n);
};
int FUN_001f92f0(void*, void*); /* (unb4) as defined; address taken only */
struct Container_1f9fc0 {
    char pad[24];
    Allocator *allocator;
    Node *FUN_00230ba0(void (*fn)(), SlotKey_1f9fc0 *key);
    void FUN_00230de0(Node *n);
};
class Mixer {
public:
    char pad000[0xc6c];
    Container_1f9fc0 *container;
    bool FUN_001f9fc0(SlotKey_1f9fc0 key);
};
bool Mixer::FUN_001f9fc0(SlotKey_1f9fc0 key)
{
    Container_1f9fc0 *c = container;
    Node *n = c->FUN_00230ba0((void (*)())FUN_001f92f0, &key);
    if (n != 0) {
        c->FUN_00230de0(n);
        n->value.FUN_0027af50();
        c->allocator->release(n);
        key.name.FUN_0027af50();
        return true;
    }
    key.name.FUN_0027af50();
    return false;
}
} // namespace fn_001f9fc0


// 0x001fa040 FUN_001fa040 (370 B): equivalent/0x001fa040.cpp [wrapped: conflict: FUN_00267760]
// sym: ?FUN_001fa040@Table_1fa040@fn_001fa040@@QAEXXZ @575f6506e3d8 @wc33ab9419293
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

struct SlotA_1fa040 {
    int a0;
    int a4;
    int a8;
    int ac;
    int a10;
    int a14;
    int a18;
    int a1c;
    int a20;
    char a24;
    char pad25[3];
};
struct SlotB_1fa040 {
    int b0;
    char label[0x20];
    int pad24;
    Name_1fa040 name;
    unsigned char c30;
    unsigned char c31;
    char pad32[2];
    int pad34;
    int f38;
    int f3c;
    int f40;
    int f44;
    char f48;
    char f49;
    short f4a;
    int pad4c;
    int w50;
    Tree_1fa040* tree54;
};

class Table_1fa040 {
public:
    char pad0[8];
    Name_1fa040 name;
    char pad10[0x410 - 0x10];
    int f410;
    int f414;
    int f418;
    char title[0x20];
    int f43c;
    int f440;
    short f444;
    char pad446[2];
    int f448;
    int f44c;
    char f450;
    char pad451[3];
    int f454;
    int f458;
    int f45c;
    SlotA_1fa040 slotsA[16];
    int f6e0;
    char pad6e4[0x6f0 - 0x6e4];
    SlotB_1fa040 slotsB[16];
    void FUN_001fa040();
};

void Table_1fa040::FUN_001fa040()
{
    f410 = 0;
    f414 = -1;
    f418 = 0;
    ((owners::Target_27b040 *)&name)->FUN_0027b040((hulk_uintptr)"CONSTRUCTED, BUT NOT YET NAMED");
    FUN_00267760(title, 0x20, "%s", "CONSTRUCTED, BUT NOT YET NAMED");
    f43c = 0;
    f450 = 0;
    f454 = 1;
    f458 = 0;
    f45c = 0;
    f6e0 = 0;
    // words in the tail of the last slotB record: one is cleared here, the next is read as a Tree below
    slotsB[15].w50 = 0;
    for (int i = 0; i < 16; i++) {
        SlotA_1fa040& s = slotsA[i];
        s.a0 = 0;
        s.a4 = -1;
        s.a8 = -1;
        s.ac = 0;
        s.a10 = 0;
        s.a14 = 0;
        s.a18 = 0;
        s.a1c = 0;
        s.a24 = 0;
        Pool_1fa040* p = FUN_001d4c90();
        ((owners::Obj_1d1900 *)p)->FUN_001d1900((hulk_intptr)(s.a20));
        s.a20 = -1;
    }
    for (int j = 0; j < 16; j++) {
        SlotB_1fa040& s = slotsB[j];
        s.b0 = 0;
        FUN_00267760(s.label, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
        s.f38 = 0;
        s.f3c = 0;
        s.f40 = 0;
        s.f44 = 0;
        s.c30 = 0xff;
        ((owners::Target_27b040 *)&(s.name))->FUN_0027b040((hulk_uintptr)"");
        s.c31 = 0xff;
        s.f48 = 0;
        s.f49 = 1;
        s.f4a = -1;
    }
    f440 = 0;
    f444 = 0;
    Tree_1fa040* tree = slotsB[15].tree54;
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
// sym: ?target@Object@fn_001fa500@@QAEXH@Z @1c082434cd96 @w233a730132a7
namespace fn_001fa500 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001fa500 @ 0x001fa500
struct Value_1fa500 { char data[8]; void FUN_0027af30(Value_1fa500*); void FUN_0027af50(); };
struct Key_1fa500 { Value_1fa500 value; unsigned char a,b; };
struct Node { char pad[16]; Value_1fa500 value; };
struct Allocator { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void release(Node*); };
int FUN_001f92f0(void*, void*); /* (unb4) as defined; address taken only */
struct Container_1fa500 { char pad[24]; Allocator* allocator; Node* FUN_00230ba0(void (*)(void), Key_1fa500*); void FUN_00230de0(Node*); };
struct Record_1fa500 { Value_1fa500 value; unsigned char a,b; char pad[78]; };
struct Object { char pad0[0x450]; unsigned char enabled; char pad1[7]; int state; char pad2[0x284]; int count; char pad3[0x34]; Record_1fa500 records[15]; char pad4[0x28]; int recordCount; Container_1fa500* container; void FUN_001fa3a0(int); void target(int); };
void Object::target(int mode) {
 state=mode;
 if(mode==1 && enabled) {
  for(int i=0;i<recordCount;++i) {
   for(int j=0;j<count;++j) {
    records[i].b=(unsigned char)j;
    Key_1fa500 key;
    key.value.FUN_0027af30(&records[i].value);
    key.a=records[i].a;
    Container_1fa500* c=container;
    key.b=records[i].b;
    Node* n=c->FUN_00230ba0((void (*)())FUN_001f92f0,&key);
    if(n) { c->FUN_00230de0(n); n->value.FUN_0027af50(); c->allocator->release(n); }
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
    p->f1();
}

} // namespace fn_f80593ac

// 0x001fa630 FUN_001fa630 (354 B): equivalent/0x001fa630.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0CEncounterGenerator@fn_001fa630@@QAE@XZ @80cda8543ebc @wadecdf4a9f33
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

struct EncObj {
    char pad0[0x18];
    Pool_1fa630 *pool;
    void FUN_00230b60();
};

struct Tracker_1fa630 {
    void FUN_001d1900(int id);
};

struct NameHolder_1fa630 {
    char pad[8];
    void FUN_0027af00();
    void FUN_0027b040(const char *name);
};

Tracker_1fa630 *__cdecl FUN_001d4c90();
void __cdecl FUN_00267760(char *dst, int size, const char *src, ...);
void __cdecl FUN_002702a0(Pool_1fa630 **out, int a, int b, int c, int d, const char *name, int e);

struct ElemA {
    int f0, f4, f8, fc, f10, f14, f18, f1c, f20;
    char b24;
    char pad25[3];
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0_00038290();
    char pad04[0xc];
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

class CEncounterGenerator : public pure3d::Entity {
public:
    class CEncounter {
    public:
        CEncounter();
        virtual void* v0_001f94e0(int);
        char pad04[4];
        int f8;
        char name[0x20];
        char pad2c[4];
        NameHolder_1fa630 holder;
        char b38;
        char b39;
        char pad3a[6];
        int f40, f44, f48, f4c;
        char b50;
        char b51;
        unsigned short w52;
        char pad54[4];
    };

    CEncounterGenerator();
    virtual void v1_000382a0();
    virtual void* v2_001fc600(char);
    virtual void v3_0027afe0();
    virtual void v4_0027aff0();

    char pad10[0x448 - 0x10];
    int f448;
    int f44c;
    char pad450[0x460 - 0x450];
    ElemA elemsA[16];
    char pad6e0[8];
    char elemsB[16 * 0x58];
    char padc68[4];
    EncObj *encounter;
    void FUN_001fa040();
};

CEncounterGenerator::CEncounter::CEncounter()
{
    holder.FUN_0027af00();
    w52 = 0;
    f8 = 0;
    FUN_00267760(name, 0x20, "CONSTRUCTED, BUT NOT YET NAMED");
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    b38 = (char)0xff;
    holder.FUN_0027b040(((const char*)&DAT_003f335c));
    b39 = (char)0xff;
    b50 = 0;
    b51 = 1;
    w52 = 0xffff;
}

CEncounterGenerator::CEncounterGenerator()
{
    int i;
    for (i = 0; i < 16; i++) {
        ElemA *e = &elemsA[i];
        e->f20 = -1;
        e->f0 = 0;
        e->f4 = -1;
        e->f8 = -1;
        e->fc = 0;
        e->f10 = 0;
        e->f14 = 0;
        e->f18 = 0;
        e->f1c = 0;
        e->b24 = 0;
        Tracker_1fa630 *t = FUN_001d4c90();
        t->FUN_001d1900(*(volatile int *)&e->f20);
        e->f20 = -1;
    }
    for (i = 0; i < 16; i++)
        new (elemsB + i * 0x58) CEncounter();

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
    encounter = obj;
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
    member->f1();
    if (flag & 1)
        FUN_0008d330(this);
    return this;
}

} // namespace fn_f80593ac

// 0x001fa7d0 FUN_001fa7d0 (216 B): equivalent/0x001fa7d0.cpp [wrapped: conflict: Object]
// sym: ?FUN_001fa7d0@Object@fn_001fa7d0@@QAE_NHH@Z @2fd4ca70aaff @w278c8e953658
namespace fn_001fa7d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_001fa7d0 @ 0x001fa7d0
struct Entry_1fa7d0 { char data[0x58]; void FUN_001f9810(int value); };
struct Object {
 char pad0[0x10];
 int items[256];
 int count;
 char pad414[0x44];
 int state;
 char pad45c[0x28c];
 Entry_1fa7d0 entries[1];
 bool FUN_001f9040(int input, int item);
 bool FUN_001f87e0(int input, int item, int* index);
 void FUN_001fa1c0(int input, int item);
 void FUN_001fa3a0(int index);
 bool FUN_001fa7d0(hulk_intptr input, int value);
};
bool Object::FUN_001fa7d0(hulk_intptr input, int value) {
 if (!input || state != 2) return false;
 bool result = false;
 for (int i = 0; i < count; ++i) {
  int index = -1;
  bool first = FUN_001f9040(input, items[i]);
  bool second = FUN_001f87e0(input, items[i], &index);
  if (first) {
   if (second) entries[index].FUN_001f9810(value);
   else FUN_001fa1c0(input, items[i]);
   result = true;
  } else if (second) FUN_001fa3a0(index);
 }
 return result;
}
} // namespace fn_001fa7d0

namespace fn_f80593ac {

// 0x001fa8b0 FUN_001fa8b0 (110 B): equivalent/0x001fa8b0.cpp
// sym: ??1CEncounterGenerator@fn_f80593ac@@UAE@XZ @de66f7aa9549 @w4a436067630f
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 4/4)
// FUN_001fa8b0 @ 0x001fa8b0
// equiv-map: ??1IRefCount@core@@UAE@XZ = 0x0027afd0
// equiv-map: ??1Name@@QAE@XZ = 0x0027af50
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
CEncounterGenerator::~CEncounterGenerator() throw()
{
    Task_1fa8b0 *t = task;
    if (t != 0) {
        t->FUN_00230f50(FUN_001f9f80, t);
        t->child->Release();
        thunk_FUN_00267090(t);
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
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f80593ac
