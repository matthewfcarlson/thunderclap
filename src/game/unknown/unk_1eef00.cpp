// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001eef00..0x001ef410 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fcd387f7 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fcd387f7 {} using namespace fn_fcd387f7;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fcd387f7 {
class Helper_1eef00 {
  public:
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
struct ThisCall_001f1c80 {
    void FUN_001f1c80();
};
extern void thunk_FUN_00267090(CCollisionAction*);
struct A_1eef70 {
    void First();
};
struct B_1eef70 {
    void Second();
};
struct Obj_1eef70 {
    A_1eef70* a;
    B_1eef70* b;
    void Target();
};
class A_1eef90 {
  public:
};
extern "C" A_1eef90* __cdecl FUN_001d4c90();
struct Sub {  };
struct Entry {
    char pad0[8];
    int field8;
    int fieldC;
    int field10;
    unsigned char active;
    char pad15[3];
    Sub sub;
    char pad19[7];
    float field20;
    int field24;
};
struct Owner {
    char pad[12];
    Entry *entries;
    Entry* FUN_001eefc0();
};
struct Key_1ef180 {
    __int64 value;
};
struct Node {
    __int64 value;
    int pad;
    Node* next;
    Node* Find(Key_1ef180*, char);
};
struct Table_1ef180 {
    Node* parents;
    Node* entries;
    Node* Find(Key_1ef180*, char);
};
struct Rng;
extern "C" Rng* FUN_000964d0();
class Pool_1ef2a0 {
public:
    class Emitter_1ef2a0* FUN_001eefc0();
};
class Emitter_1ef2a0 {
public:
    void FUN_001eed50(owners::Spawner_1ef2a0* owner, int a, int b, int flags);
};
class E_1ef350 {
  public:
    void F();
};
struct Item_1ef370 {
    char pad[8];
};
class C_1ef370 {
  public:
    Item_1ef370 items[8];
    int count;
    void f(hulk_intptr);
};
struct Item_1ef390 {
    void Add(int, int);
};
struct Owner_1ef390 {
    char pad[0x40];
    int count;
    void Add(int a, int b);
};
struct Entry_1ef3c0 {
    char pad[8];
    void Init(void*);
};
struct Helper_1ef3c0 {
    void Finish();
};

} // namespace fn_fcd387f7

// 0x001eef00 FUN_001eef00 (67 B): matches/0x001eef00.cpp
// sym: ?FUN_001eef00@Obj_1eef00@owners@@QAEXXZ
void owners::Obj_1eef00::FUN_001eef00() {
    int i = 0;
    do {
        char* a = data + i;
        *(int*)(a + 8) = 0;
        *(int*)(a + 12) = 0;
        *(int*)(a + 16) = 0;
        a[20] = 0;
        *(float*)(a + 32) = 100.0f;
        *(int*)(a + 36) = 0;
        ((owners::Target_27b040 *)(((Helper_1eef00*)(a + 24))))->FUN_0027b040((hulk_uintptr)0);
        i += 40;
    } while (i < 4000);
}

namespace fn_fcd387f7 {

// 0x001eef50 FUN_001eef50 (30 B): matches/0x001eef50.cpp
// sym: ?vfunc_2@CCollisionAction@fn_fcd387f7@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_001f1c80*)(this))->FUN_001f1c80();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001eef70 FUN_001eef70 (19 B): matches/0x001eef70.cpp
// sym: ?Target@Obj_1eef70@fn_fcd387f7@@QAEXXZ
void Obj_1eef70::Target() {
    a->First();
    b->Second();
}


// 0x001eef90 FUN_001eef90 (22 B): matches/0x001eef90.cpp
// sym: ?target@fn_fcd387f7@@YGXPAX@Z
void __stdcall target(void* p) {
    A_1eef90* a = FUN_001d4c90();
    ((owners::Object_1d3600 *)a)->FUN_001d3600((const char *)p, 0);
}


// 0x001eefc0 FUN_001eefc0 (77 B): equivalent/0x001eefc0.cpp
// sym: ?FUN_001eefc0@Owner@fn_fcd387f7@@QAEPAUEntry@2@XZ
// STATUS: equivalent (tools/equiv.py level 3: 2983 inputs, branch coverage 6/6)
// FUN_001eefc0 @ 0x001eefc0
Entry* Owner::FUN_001eefc0() {
    Entry *entry = entries;
    for (int index = 0; index < 100; ++index) {
        if (entry && !entry->active) {
            entry->field8 = 0;
            entry->fieldC = 0;
            entry->field10 = 0;
            entry->active = 0;
            entry->field20 = 100.0f;
            entry->field24 = 0;
            ((owners::Target_27b040 *)&(entry->sub))->FUN_0027b040((hulk_uintptr)0);
            return entry;
        }
        Entry *previous = entry;
        entry = (Entry*)((char*)entry + 0x28);
        if (index == 99) return previous;
    }
    return entry;
}


// 0x001ef180 FUN_001ef180 (93 B): matches/0x001ef180.cpp
// sym: ?Find@Table_1ef180@fn_fcd387f7@@QAEPAUNode@2@PAUKey_1ef180@2@D@Z
Node* Table_1ef180::Find(Key_1ef180* key, char recurse) {
    Node* p = parents;
    Node* n = entries;
    Node* result = 0;
    while (n) {
        if (n->value == key->value)
            return n;
        n = n->next;
    }
    if (recurse) {
        while (p && !result) {
            result = p->Find(key, 1);
            p = p->next;
        }
    }
    return result;
}

} // namespace fn_fcd387f7

// 0x001ef1e0 FUN_001ef1e0 (58 B): matches/0x001ef1e0.cpp [wrapped: conflict: Node]
// sym: ?FUN_001ef1e0@Node@fn_001ef1e0@@QAEPAUEntry@2@PBUKey@2@@Z
namespace fn_001ef1e0 {
struct Key {
    int first;
    int second;
};
struct Entry {
    int first;
    int second;
    char pad[4];
    Entry* next;
};
struct Node {
    char pad[4];
    Entry* entries;
    Node* next;
    Entry* FUN_001ef1e0(const Key* key);
};
Entry* Node::FUN_001ef1e0(const Key* key) {
    Node* node = this;
    for (;;) {
        Entry* entry = node->entries;
        if (entry) {
            __int64 value = *(__int64*)key;
            do {
                if (*(__int64*)entry == value)
                    return entry;
                entry = entry->next;
            } while (entry);
        }
        Node* n = node->next;
        if (!n)
            return 0;
        node = n;
    }
}
} // namespace fn_001ef1e0


// 0x001ef220 FUN_001ef220 (40 B): matches/0x001ef220.cpp [wrapped: conflict: Node]
// sym: ?target@fn_001ef220@@YIXPAVOwner_1ef220@1@@Z
namespace fn_001ef220 {
class Node {
  public:
    virtual void Release(int);
    char pad[4];
    Node* next;
};
class Owner_1ef220 {
  public:
    char pad[0x10];
    Node* head;
    void Finish();
};
void __fastcall target(Owner_1ef220* self) {
    Node* n = self->head;
    while (n) {
        Node* c = n;
        n = c->next;
        c->Release(1);
    }
    self->Finish();
}
} // namespace fn_001ef220


// 0x001ef260 FUN_001ef260 (64 B): matches/0x001ef260.cpp [wrapped: conflict: Node]
// sym: ?Add@Owner_1ef260@fn_001ef260@@QAEXPAUNode@2@@Z
namespace fn_001ef260 {
class Owner_1ef260;
struct Node {
    int a;
    Owner_1ef260* owner;
    Node* next;
};
class Owner_1ef260 {
  public:
    char pad[0x10];
    Node* head;
    int count;
    void Add(Node* n);
};
void Owner_1ef260::Add(Node* n) {
    if (n) {
        n->next = 0;
        n->owner = this;
        ++count;
        Node* p = head;
        if (!p) {
            head = n;
            return;
        }
        while (p->next)
            p = p->next;
        p->next = n;
    }
}
} // namespace fn_001ef260


// 0x001ef2a0 FUN_001ef2a0 (114 B): equivalent/0x001ef2a0.cpp
// sym: ?FUN_001ef2a0@Spawner_1ef2a0@owners@@QAEXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001ef2a0 @ 0x001ef2a0
       // function-local static
   // its init guard
void owners::Spawner_1ef2a0::FUN_001ef2a0(int a, int b)
{
    DAT_004e3740++;
    if (count < 1)
        return;
    if ((DAT_004e375c & 1) == 0) {
        DAT_004e375c |= 1;
        (*(Rng**)&DAT_004e3758) = FUN_000964d0();
    }
    Emitter_1ef2a0* e = (*(Pool_1ef2a0**)&DAT_004e370c)->FUN_001eefc0();
    if (e == 0) {
        DAT_004e3718++;
        return;
    }
    DAT_004e3744++;
    e->FUN_001eed50(this, a, b, 0);
}


// 0x001ef320 FUN_001ef320 (42 B): matches/0x001ef320.cpp
// sym: ?FUN_001ef320@Obj_1ef320@owners@@QAEPAU12@XZ
owners::Obj_1ef320* owners::Obj_1ef320::FUN_001ef320() {
    owners::Obj_1ef320* p = this;
    for (int i = 0; i < 8; ++i) {
        p->Init();
        p = (owners::Obj_1ef320*)((char*)p + 8);
    }
    field = 0;
    return this;
}


// 0x001ef350 FUN_001ef350 (32 B): matches/0x001ef350.cpp
// sym: ?FUN_001ef350@C_1ef350@owners@@QAEXXZ
void owners::C_1ef350::FUN_001ef350() {
    E_1ef350* p = (E_1ef350*)((char*)this + 0x40);
    int n = 8;
    do {
        p = (E_1ef350*)((char*)p - 8);
        p->F();
        --n;
    } while (n != 0);
}

namespace fn_fcd387f7 {

// 0x001ef370 FUN_001ef370 (31 B): matches/0x001ef370.cpp
// sym: ?f@C_1ef370@fn_fcd387f7@@QAEXH@Z
void C_1ef370::f(hulk_intptr x) {
    if (count < 8) {
        ((owners::Target_27b040 *)&(items[count]))->FUN_0027b040((hulk_uintptr)x);
        ++count;
    }
}


// 0x001ef390 FUN_001ef390 (36 B): matches/0x001ef390.cpp
// sym: ?Add@Owner_1ef390@fn_fcd387f7@@QAEXHH@Z
void Owner_1ef390::Add(int a, int b) {
    if (count < 8) {
        Item_1ef390* item = (Item_1ef390*)((char*)this + count * 8);
        item->Add(a, b);
        ++count;
    }
}

} // namespace fn_fcd387f7

// 0x001ef3c0 FUN_001ef3c0 (40 B): matches/0x001ef3c0.cpp
// sym: ?FUN_001ef3c0@Owner_1ef3c0@owners@@QAEXPAX0@Z
void owners::Owner_1ef3c0::FUN_001ef3c0(void* a, void* b) {
    if (count < 8) {
        ((Entry_1ef3c0*)((char*)this + count * 8))->Init(&a);
        ++count;
    }
    ((Helper_1ef3c0*)&a)->Finish();
}

