// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001efb80..0x001f0290 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f4b77e46 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4b77e46 {} using namespace fn_f4b77e46;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_f4b77e46 {
struct Key_1efb80 {
    unsigned int lo;
    unsigned int hi;
};
struct KeyList_1efb80 {
    Key_1efb80 keys[8];
    int count;
};
struct Node {
    Node *firstChild;
    char pad04[8];
    Node *sibling;
    Key_1efb80 key;
};
class NodeTree {
public:
    char pad00[8];
    Node *root;
    Node *Find(KeyList_1efb80 *path);
};
struct CSoundCommand_PlayCuedNISEvent {
    static void* operator new(size_t, void* place) { return place; }
    virtual void method();
    int next;
    int previous;
    int eventId;
};
struct SoundQueue {
    void FUN_001ef260(CSoundCommand_PlayCuedNISEvent* command);
};
void* __cdecl FUN_0008d710(int size, int category);
} // namespace fn_f4b77e46
void* __cdecl operator new(size_t, int);
namespace fn_f4b77e46 {
class CSoundCommand_1efd00 {
  public:
    virtual void Run();
    int a;
    int b;
    int id;
    CSoundCommand_1efd00(int n) : a(0), b(0), id(n) {}
};
class CSoundCommand_StopNISEvent_1efd00 : public CSoundCommand_1efd00 {
  public:
    CSoundCommand_StopNISEvent_1efd00(int n) : CSoundCommand_1efd00(n) {}
    virtual void Run();
};
class Manager {
  public:
    void Add(CSoundCommand_1efd00*);
    void FUN_001ef260(int);
};
struct CSoundCommand_InstallMixer_1efd60 { int FUN_001ef730(int, int, int); };
void* __cdecl FUN_0008d710(unsigned int, unsigned int);
struct CSoundCommand_ReturnToDefaultMix {
    virtual void command();
    int field4;
    int field8;
    int fieldC;
    int value;
};
struct SoundManager {
    void FUN_001ef260(CSoundCommand_ReturnToDefaultMix* command);
};
typedef unsigned int uint_1efe20;
struct Key_1efe20 { uint_1efe20 a,b; void FUN_0027b0e0(const char*); void FUN_0027af50(); };
struct Entry_1efe20 { char pad[24]; float probability;  };
struct Group_1efe20 { Entry_1efe20* FUN_001ef1e0(Key_1efe20*); };
struct ThisWrap_001efe20 {
    Group_1efe20* FUN_001efb80(uint_1efe20);
    bool FUN_001efe20(uint_1efe20 group,uint_1efe20 arg,const char* name,uint_1efe20 last);
};
struct RandomState_1efe20 { uint_1efe20 a,b; };
extern "C" RandomState_1efe20* __cdecl FUN_000964d0();
struct Context { unsigned int a, b; };
struct Event_1effc0 {
 virtual void slot0();
 virtual void fire(Context*, unsigned int);
 unsigned int unused;
 Event_1effc0* next;
 float time;
};
struct List_1effc0 { char pad[16]; Event_1effc0* first; int count; };
struct Player_1effc0 {
 char pad[8];
 List_1effc0* list;
 float time;
 int completed;
 unsigned char active;
 char pad15[3];
 Context context;
 unsigned int arg;
 void FUN_001eed20();
 void FUN_001effc0(float delta);
};
class CSoundCommand_1f01a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public CSoundCommand_1f01a0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);
} // namespace fn_f4b77e46
U64 __cdecl FUN_002672f0(int, int, int);
namespace fn_f4b77e46 {
extern "C" int __cdecl FUN_002673a0(int, int);
struct CSoundCommand_1f01c0 {
    int field4, field8, fieldC;
    CSoundCommand_1f01c0(int c) : field4(0), field8(0), fieldC(c) {}
};
struct Pair {
    int low, high;
    Pair() : low(0), high(0) {}
    inline void Set(U64 v) {
        high = (int)(v >> 32);
        low = (int)v;
    }
};
struct CSoundCommand_PlayInterruptEvent : CSoundCommand_1f01c0 {
    virtual void dummy();
    Pair pair;
    int field18;
    CSoundCommand_PlayInterruptEvent(hulk_intptr a, hulk_intptr b, hulk_intptr c);
};
class CSoundCommand_1f0230 {
public:
    virtual void vfunc_0();
    int field4;
    int field8;
    int fieldC;
    CSoundCommand_1f0230(int c) : field4(0), field8(0), fieldC(c) {}
};
struct SoundId {
    U64 value;
    SoundId(int name) : value(0) { value = FUN_002672f0(name, 0, 0); }
};
class CSoundCommand_PlayTunableEvent : public CSoundCommand_1f0230 {
public:
    SoundId event;
    int tuning;
    int field1C;
    int field20;
    int field24;
    CSoundCommand_PlayTunableEvent(int name, int tuningName, int c, int d, int e, int f);
    virtual void vfunc_0();
};


// 0x001efb80 FUN_001efb80 (132 B): equivalent/0x001efb80.cpp
// sym: ?Find@NodeTree@fn_f4b77e46@@QAEPAUNode@2@PAUKeyList_1efb80@2@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3094 inputs, branch coverage 23/26, incomplete)
// FUN_001efb80 @ 0x001efb80
Node *NodeTree::Find(KeyList_1efb80 *path)
{
    if (path == 0)
        return 0;
    Node *result = root;
    Node *cur = root;
    for (int i = 0; i < path->count; i++) {
        if (cur == 0)
            return result;
        const Key_1efb80 *k = &path->keys[i];
        Node *found = cur;
        if (!(k->lo == cur->key.lo && k->hi == cur->key.hi)) {
            found = cur->firstChild;
            while (found != 0 && !(found->key.lo == k->lo && found->key.hi == k->hi))
                found = found->sibling;
        }
        if (found != 0)
            result = found;
        cur = found;
    }
    return result;
}


// 0x001efca0 FUN_001efca0 (81 B): equivalent/0x001efca0.cpp
// sym: ?FUN_001efca0@fn_f4b77e46@@YGXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_001efca0 @ 0x001efca0
void __stdcall FUN_001efca0(int eventId) {
    SoundQueue* queue = (*(SoundQueue**)&DAT_004e3710);
    if (queue) {
        void* memory = FUN_0008d710(16, 6);
        CSoundCommand_PlayCuedNISEvent* command = 0;
        if (memory) {
            command = new (memory) CSoundCommand_PlayCuedNISEvent;
            command->eventId = eventId;
            command->next = 0;
            command->previous = 0;
        }
        queue->FUN_001ef260(command);
    }
}


// 0x001efd00 FUN_001efd00 (81 B): matches/0x001efd00.cpp
// sym: ?FUN_001efd00@fn_f4b77e46@@YGXH@Z
// data: gManager = DAT_004e3710
void __stdcall FUN_001efd00(int id) {
    Manager* m = (*(Manager**)&DAT_004e3710);
    if ((*(Manager**)&DAT_004e3710)) {
        CSoundCommand_StopNISEvent_1efd00* cmd = new (6) CSoundCommand_StopNISEvent_1efd00(id);
        m->Add(cmd);
    }
}


// 0x001efd60 FUN_001efd60 (83 B): equivalent/0x001efd60.cpp
// sym: ?FUN_001efd60@fn_f4b77e46@@YGXHHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001efd60 @ 0x001efd60
void __stdcall FUN_001efd60(int a, int b, int c) { if (a != 0 && (*(Manager**)&DAT_004e3710) != 0) { Manager *manager = (*(Manager**)&DAT_004e3710); CSoundCommand_InstallMixer_1efd60 *p = (CSoundCommand_InstallMixer_1efd60*)FUN_0008d710(0x34,6); manager->FUN_001ef260(p ? p->FUN_001ef730(a,b,c) : 0); } }


// 0x001efdc0 FUN_001efdc0 (88 B): equivalent/0x001efdc0.cpp
// sym: ?FUN_001efdc0@fn_f4b77e46@@YGXHH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 4/4)
// FUN_001efdc0 @ 0x001efdc0
void __stdcall FUN_001efdc0(int value, int unused) {
    SoundManager* manager = (*(SoundManager**)&DAT_004e3710);
    if (manager) {
        CSoundCommand_ReturnToDefaultMix* command = (CSoundCommand_ReturnToDefaultMix*)FUN_0008d710(20, 6);
        if (command) {
            CSoundCommand_ReturnToDefaultMix fresh;
            *(void**)command = *(void**)&fresh;
            command->field4 = 0;
            command->field8 = 0;
            command->fieldC = 0;
            command->value = value;
        }
        manager->FUN_001ef260(command);
    }
}


// 0x001efe20 FUN_001efe20 (295 B): equivalent/0x001efe20.cpp
// sym: ?FUN_001efe20@ThisWrap_001efe20@fn_f4b77e46@@QAE_NIIPBDI@Z
// STATUS: equivalent (tools/equiv.py level 3: 19413 inputs, branch coverage 7/8, incomplete)
// FUN_001efe20 @ 0x001efe20
bool ThisWrap_001efe20::FUN_001efe20(uint_1efe20 group,uint_1efe20 arg,const char* name,uint_1efe20 last) {
 ++(*(uint_1efe20*)&DAT_004e3728);
 Group_1efe20* g=this->FUN_001efb80(group);
 if (!g) { ++(*(uint_1efe20*)&DAT_004e372c); return false; }
 Key_1efe20 key; key.FUN_0027b0e0(name);
 Entry_1efe20* e=g->FUN_001ef1e0(&key);
 if (!e) { ++(*(uint_1efe20*)&DAT_004e3730); key.FUN_0027af50(); return false; }
 RandomState_1efe20* r=FUN_000964d0();
 r->a=(r->a & 65535)*0x9069+(r->a>>16);
 r->b=(r->b & 65535)*0x4650+(r->b>>16);
 uint_1efe20 value=((r->a<<16)+(r->b & 65535))%1000;
 ++(*(uint_1efe20*)&DAT_004e3734);
 if ((double)value * (double)0.1f > e->probability) { ++(*(uint_1efe20*)&DAT_004e373c); key.FUN_0027af50(); return false; }
 ((owners::Spawner_1ef2a0 *)e)->FUN_001ef2a0((int)arg, (int)last);
 key.FUN_0027af50();
 return true;
}

} // namespace fn_f4b77e46

// 0x001eff50 FUN_001eff50 (61 B): matches/0x001eff50.cpp [wrapped: conflict: Node]
// sym: ?Dispose@Obj_1eff50@fn_001eff50@@QAEPAV12@E@Z
namespace fn_001eff50 {
class Node {
  public:
    virtual void Release(int);
    char pad[4];
    Node* next;
};
class Obj_1eff50 {
  public:
    char pad[0x10];
    Node* head;
    void Flush();
    Obj_1eff50* Dispose(unsigned char flag);
};
void destroy(Obj_1eff50* o);

Obj_1eff50* Obj_1eff50::Dispose(unsigned char flag) {
    Node* n = head;
    while (n) {
        Node* cur = n;
        n = n->next;
        cur->Release(1);
    }
    Flush();
    if (flag & 1)
        destroy(this);
    return this;
}
} // namespace fn_001eff50

namespace fn_f4b77e46 {

// 0x001effc0 FUN_001effc0 (197 B): equivalent/0x001effc0.cpp
// sym: ?FUN_001effc0@Player_1effc0@fn_f4b77e46@@QAEXM@Z
// STATUS: equivalent (tools/equiv.py level 3: 174 inputs, branch coverage 24/26, incomplete)
// FUN_001effc0 @ 0x001effc0
void Player_1effc0::FUN_001effc0(float delta) {
 if (!active || !list) return;
 float previous = time;
 time = delta + time;
 int count = list->count;
 for (int i = 0; i < count; ++i) {
  List_1effc0* current = list;
  Event_1effc0* event = 0;
  if (i >= 0 && i < current->count) {
   event = current->first;
   for (int j = 0; event && j < i; ++j) event = event->next;
  }
  if (event && event->time >= previous && event->time <= time) {
   ++(*(unsigned int*)&DAT_004e3748);
   event->fire(&context, arg);
   ++completed;
   if (completed == count) {
    active = 0;
    FUN_001eed20();
    return;
   }
  }
 }
}

} // namespace fn_f4b77e46

// 0x001f0150 FUN_001f0150 (73 B): matches/0x001f0150.cpp [wrapped: conflict: FUN_002672f0]
// sym: ??0CSoundCommand_PlaySequenceEvent@fn_001f0150@@QAE@HHH@Z
namespace fn_001f0150 {
__int64 __cdecl FUN_002672f0(int, int, int);
extern "C" int __cdecl FUN_002673a0(int, int);
class CSoundCommand_1f0150 {
  public:
    virtual void v();
    int a, b, c;
    CSoundCommand_1f0150(int z) : a(0), b(0), c(z) {}
};
struct Q {
    __int64 value;
    Q(int x) : value(0) { value = FUN_002672f0(x, 0, 0); }
};
class CSoundCommand_PlaySequenceEvent : public CSoundCommand_1f0150 {
  public:
    Q q;
    int g;
    CSoundCommand_PlaySequenceEvent(hulk_intptr x, hulk_intptr y, hulk_intptr z);
    virtual void v();
};
CSoundCommand_PlaySequenceEvent::CSoundCommand_PlaySequenceEvent(hulk_intptr x, hulk_intptr y, hulk_intptr z) : CSoundCommand_1f0150(z), q(x) {
    g = FUN_002673a0(y, 0);
}
} // namespace fn_001f0150

namespace fn_f4b77e46 {

// 0x001f01a0 CSoundCommand_PlaySequenceEvent::vfunc_0 (31 B): matches/0x001f01a0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f4b77e46@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001f01c0 FUN_001f01c0 (73 B): matches/0x001f01c0.cpp
// sym: ??0CSoundCommand_PlayInterruptEvent@fn_f4b77e46@@QAE@HHH@Z
CSoundCommand_PlayInterruptEvent::CSoundCommand_PlayInterruptEvent(hulk_intptr a, hulk_intptr b, hulk_intptr c) : CSoundCommand_1f01c0(c) {
    U64 value = FUN_002672f0(a, 0, 0);
    pair.Set(value);
    field18 = FUN_002673a0(b, 0);
}

} // namespace fn_f4b77e46

// 0x001f0210 CSoundCommand_PlayInterruptEvent::vfunc_0 (31 B): matches/0x001f0210.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_001f0210@@UAEPAV123@E@Z
namespace fn_001f0210 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class CSoundCommand_1f0210 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public CSoundCommand_1f0210 {
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
} // namespace fn_001f0210

namespace fn_f4b77e46 {

// 0x001f0230 FUN_001f0230 (94 B): matches/0x001f0230.cpp
// sym: ??0CSoundCommand_PlayTunableEvent@fn_f4b77e46@@QAE@HHHHHH@Z
CSoundCommand_PlayTunableEvent::CSoundCommand_PlayTunableEvent(int name, int tuningName, int c, int d, int e, int f)
    : CSoundCommand_1f0230(f), event(name)
{
    tuning = FUN_002673a0(tuningName, 0);
    field1C = c;
    field20 = d;
    field24 = e;
}

} // namespace fn_f4b77e46
