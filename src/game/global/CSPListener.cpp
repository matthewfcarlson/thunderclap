// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x001d7b80..0x001db770 (kind game, layer game, confidence medium), dominant class CSPListener
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c60317 {
#define TREE_TU_END }
namespace fn_f9c60317 {} using namespace fn_f9c60317;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9c60317 {
struct Vec3_1d7b80 {
    float x, y, z;
};
struct Key_1d7b80 {
    unsigned int lo;
    unsigned int hi;
};
struct Flags_1d7b80 {
    char pad00[0x68];
    unsigned char b68;
    unsigned char b69;
};
struct State_1d7b80 {
    char pad00[8];
    void *owner;              // 0x08
    int mode;                 // 0x0c
    char pad10[0x74 - 0x10];
    Flags_1d7b80 *flags;             // 0x74
};
struct Xform_1d7b80 {
    char pad00[0x30];
    Vec3_1d7b80 pos;                 // 0x30
};
class Part_1d7b80 {
public:
    char pad00[0x10];
    State_1d7b80 *state;             // 0x10
};
class Locator {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual Vec3_1d7b80 *l4();
};
struct Matched {
    char pad00[8];
    unsigned int lo;          // 0x08
    unsigned int hi;          // 0x0c
};
struct Recorder {
    void FUN_00066a10(Key_1d7b80 *key);
};
struct Listener_1d7b80;   // (declared here for the next declaration)
} // namespace fn_f9c60317
struct World {
    char pad00[0xc];
    struct Listener_1d7b80 *listener; // 0x0c
};
namespace fn_f9c60317 {
class Actor_1d7b80;
struct Listener_1d7b80 {
    void FUN_001dc170(Actor_1d7b80 *a, int flag);
};
Recorder *__stdcall FUN_000678d0();
class Actor_1d7b80 {
public:
    char pad000[8];
    Key_1d7b80 key;                  // 0x08
    char pad10[0xa0 - 0x10];
    Part_1d7b80 *part;               // 0xa0
    char pada4[0xb0 - 0xa4];
    unsigned char hasHook;    // 0xb0
    char padb1[0xec - 0xb1];
    Matched *match;           // 0xec
    int fF0;
    int fF4;
    unsigned char fF8;
    char padF9[3];
    int fFC;
    char pad100[0x11c - 0x100];
    Locator *locator;         // 0x11c
    char pad120[0x164 - 0x120];
    Vec3_1d7b80 posA;                // 0x164
    Vec3_1d7b80 posB;                // 0x170
    Vec3_1d7b80 posC;                // 0x17c
    Vec3_1d7b80 posD;                // 0x188
    char pad194[0x1a0 - 0x194];
    unsigned char fired;      // 0x1a0

    void FUN_0027de50(int a, Actor_1d7b80 *b);
    void FUN_001d7b80(int a, int b);
};
struct Source_1d7e70 {
};
class Sink_1d7e70 {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34();
    virtual void SetValue(float f);
};
struct Mid_1d7e70 {
    char pad[0x70];
    Sink_1d7e70* sink;
};
struct Owner_1d7e70 {
    char pad[0x10];
    Mid_1d7e70* mid;
};
class Obj_1d7e70 {
  public:
    char pad00[0x40];
    unsigned int key;
    char pad44[0xa0 - 0x44];
    Owner_1d7e70* owner;
    char padA4[0xec - 0xa4];
    Source_1d7e70* source;
    void FUN_001d7e70();
};
struct Owner_1d7ff0;
struct Slots_1d7ff0 {
 void FUN_0003acf0(int,int,int,int,int,int);
};
struct Link_1d7ff0 { char pad[8]; Slots_1d7ff0* slots; int kind; };
struct Resource_1d7ff0 { char pad[16]; void* identity; };
struct Flag_1d7ff0 { char pad[0xa8]; unsigned char enabled; };
struct Disposable { virtual void unused(); virtual void release(); };
struct Manager_1d7ff0 { void FUN_0027ffb0(void*); };
Manager_1d7ff0* __cdecl FUN_0027f250();
struct Context {
 char pad[0x328]; void* selected;
 char pad2[0x78]; void* active;
 void FUN_0003a9d0(int);
 void FUN_0003ffa0(int,int);
};
struct Root_1d7ff0 { char pad[12]; Context* context; };
Root_1d7ff0* __cdecl FUN_001b6580();
struct Owner_1d7ff0 {
 char p0[0xa0]; Resource_1d7ff0* resource;
 char p1[0x58]; int state;
 char p2[0x14]; Link_1d7ff0* link;
 char p3[4]; Flag_1d7ff0* flag;
 char p4[0xbc]; Disposable* disposable;
 char p5[0xd]; unsigned char marked;
 void FUN_001d7ee0(int);
 void target();
};
class Item_1d8100 {
  public:
    virtual void A();
    virtual void B();
    int Get();
    void Act_0003ee70(int);
};
struct Box_1d8100 {
    char pad[0x10];
    int value;
};
struct State_1d8100 : Item_1d8100 {
    char pad[4];
    Item_1d8100* ptr;
    int state;
};
struct Manager_1d8100 {
    char pad[0xa0];
    Box_1d8100* box;
    char pad2[0x140];
    State_1d8100* item;
    void Run();
};
struct Vec_1d81b0 {
    unsigned x, y, z;
};
struct Pose {
    char pad[0x30];
    Vec_1d81b0 pos;
};
struct Child_1d81b0 {
    char pad[0xc0];
    unsigned x, y, z;
    void FUN_002f5a20(unsigned arg);
};
struct Body_1d81b0 {
    char pad[0x5c];
    unsigned x, y, z;
    char gap[8];
    Child_1d81b0* child;
};
struct Object {
    char pad[0x10];
    Body_1d81b0* body;
};
struct Gate_1d81b0 {
    bool FUN_001d4ef0();
};
struct Provider_1d81b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec_1d81b0* v4();
};
struct Target_1d81b0 {
    char pad0[0xa0];
    Object* object;
    char pad1[0x48];
    Gate_1d81b0* gate;
    char pad2[0x24];
    unsigned state;
    char pad3[4];
    Provider_1d81b0* provider;
    char pad4[0x68];
    Vec_1d81b0 position;
    char pad5[0x9c];
    float value;
    void FUN_001d7ee0(unsigned);
    void FUN_001d7510();
    bool run(unsigned arg, bool reset);
};
class Base_1d82a0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1d82a0 {
  public:
    char pad[0x21c];
    Base_1d82a0* ptr;
    void Do_001d8100();
};
struct Node {
    char pad[0x6c];
    int field6c;
};
struct Holder_1d82d0 {
    char pad[0x10];
    Node* node;
};
class Manager_1d82d0 {
  public:
    int Find_00079800(void*);
    void Use_0007ba60(int);
};
struct Root_1d82d0 {
    char pad[0x4c];
    Manager_1d82d0* manager;
};
extern Root_1d82d0* hulk_at_004dd700;
class Obj_1d82d0 {
  public:
    char pad0[0xa0];
    Holder_1d82d0* holder;
    char padA4[0xa8];
    unsigned char active;
    void Prepare_001d7510();
    int Run();
};
class Item_1d8c70 {
  public:
    virtual void First();
    char pad[4];
    class Child_1d8c70* mChild;
    int mState;
};
class Child_1d8c70 {
  public:
    void Run_0003ee70(int);
};
class Old_1d8c70 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1d8c70 {
    char pad0[0xa0];
    void* mAtA0;
    char pad1[0x140];
    Item_1d8c70* mItem;

  public:
    void Prep_001d8100();
    void Set(Item_1d8c70* p);
};
struct CSPListener_1db200 {
    int pad;
    void* vf;
    CSPListener_1db200* f(unsigned char flags);
};


// 0x001d7b80 FUN_001d7b80 (463 B): equivalent/0x001d7b80.cpp
// sym: ?FUN_001d7b80@Actor_1d7b80@fn_f9c60317@@QAEXHH@Z @e745b4d0a158 @w87a67b0e2bd2
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 38/38)
// FUN_001d7b80 @ 0x001d7b80
void Actor_1d7b80::FUN_001d7b80(int a, int b)
{
    fFC = 0;
    if (part) {
        State_1d7b80 *st = part->state;
        if (st) {
            st->mode = 5;
            st->owner = this;
            Flags_1d7b80 *fl = st->flags;
            if (fl) {
                fl->b69 = 0;
                fl->b68 = 0;
            }
        }
    }
    if (hasHook)
        FUN_0027de50(5, this);

    const Vec3_1d7b80 *src;
    if (part)
        src = &((Xform_1d7b80 *)((owners::C_2fc6f0 *)part)->FUN_002fc6f0())->pos;
    else
        src = locator->l4();
    posB = *src;
    posA = posB;

    if (part)
        src = &((Xform_1d7b80 *)((owners::C_2fc6f0 *)part)->FUN_002fc6f0())->pos;
    else
        src = locator->l4();
    posC = *src;

    if (part)
        src = &((Xform_1d7b80 *)((owners::C_2fc6f0 *)part)->FUN_002fc6f0())->pos;
    else
        src = locator->l4();
    posD = *src;

    Matched *m = match;
    fF0 = 0;
    fF4 = 0;
    fF8 = 0;
    if (m) {
        if (m->lo == (*(Key_1d7b80*)&DAT_004e2530).lo && m->hi == (*(Key_1d7b80*)&DAT_004e2530).hi) {
            if (key.lo == (*(Key_1d7b80*)&DAT_004e2528).lo && key.hi == (*(Key_1d7b80*)&DAT_004e2528).hi)
                return;
            if (key.lo == (*(Key_1d7b80*)&DAT_004e2550).lo && key.hi == (*(Key_1d7b80*)&DAT_004e2550).hi)
                return;
            if (key.lo == (*(Key_1d7b80*)&DAT_004e2558).lo && key.hi == (*(Key_1d7b80*)&DAT_004e2558).hi)
                return;
            if (key.lo == (*(Key_1d7b80*)&DAT_004e2520).lo && key.hi == (*(Key_1d7b80*)&DAT_004e2520).hi)
                return;
            Key_1d7b80 k;
            k.lo = key.lo;
            k.hi = key.hi;
            FUN_000678d0()->FUN_00066a10(&k);
            fired = 1;
            Listener_1d7b80 *l = DAT_004dd700->listener;
            if (l)
                l->FUN_001dc170(this, 1);
        }
    }
}

} // namespace fn_f9c60317

// 0x001d7d50 FUN_001d7d50 (274 B): equivalent/0x001d7d50.cpp [wrapped: conflict: World]
// sym: ?target@Object@fn_001d7d50@@QAE_NXZ @c09b498b0aa4 @w9623ff005e59
namespace fn_001d7d50 {
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 32/32)
// FUN_001d7d50 @ 0x001d7d50
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

struct Gate_1d7d50 { bool FUN_000242d0(int); }; struct Mode_1d7d50 { bool FUN_000997a0(); }; struct World { char p[8]; Mode_1d7d50* mode; char q[20]; Gate_1d7d50* gate; }; 
struct State_1d7d50 { char p[8]; int id; int type; };
struct Resource_1d7d50 { virtual void dummy(); virtual void release(); void FUN_0001b4f0(); };
struct Flag_1d7d50 { char p[24]; unsigned char active; }; struct Link_1d7d50 { char p[32]; Flag_1d7d50* flag; }; struct Related_1d7d50 { char p[116]; Link_1d7d50* link; };
struct Counter_1d7d50 { int FUN_001d5c70(int); };
struct Object { char a[64]; int current; char b[168]; Counter_1d7d50* counter; char c[12]; int pending; char d[8]; int count; char e[4]; unsigned char enabled; char f[3]; State_1d7d50* state; char g[28]; Resource_1d7d50* resource;
 void FUN_0027d4f0(int);  bool target(); };
bool Object::target() {
 if (state && state->type == 1 && DAT_004dd700->gate->FUN_000242d0(state->id) && !DAT_004dd700->mode->FUN_000997a0()) return false;
 if (pending || !enabled || count > 0) return false;
 int previous = current;
 FUN_0027d4f0(13);
 int next = current;
 count = counter->FUN_001d5c70(next);
 enabled = count > 0;
 if (next == -1) return false;
 if (next != previous) {
 Resource_1d7d50* saved = resource;
 if (saved && ((Related_1d7d50 *)((owners::C_1d72e0 *)this)->FUN_001d72e0()) && ((Related_1d7d50 *)((owners::C_1d72e0 *)this)->FUN_001d72e0())->link && !((Related_1d7d50 *)((owners::C_1d72e0 *)this)->FUN_001d72e0())->link->flag->active) {
 saved->FUN_0001b4f0();
 if (resource) resource->release();
 resource = 0;
 }
 if (state) FUN_0027d4f0(5);
 }
 return true;
}
} // namespace fn_001d7d50
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9c60317 {

// 0x001d7e70 FUN_001d7e70 (102 B): equivalent/0x001d7e70.cpp
// sym: ?FUN_001d7e70@Obj_1d7e70@fn_f9c60317@@QAEXXZ @c8e10b5c642d @w8077c7c4720d
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_001d7e70 @ 0x001d7e70
void Obj_1d7e70::FUN_001d7e70() {
    if (owner == 0)
        return;
    if (owner->mid == 0)
        return;
    if (owner->mid->sink == 0)
        return;
    if (((owners::Target_1d4ea0 *)source)->FUN_001d4ea0((int)key) > 0.0f) {
        Sink_1d7e70* sink = owner->mid->sink;
        sink->SetValue(((owners::Target_1d4ea0 *)source)->FUN_001d4ea0((int)key));
    }
}

} // namespace fn_f9c60317

// 0x001d7ee0 FUN_001d7ee0 (266 B): equivalent/0x001d7ee0.cpp [wrapped: conflict: Object]
// sym: ?target@Object@fn_001d7ee0@@QAEXPAURef_1d7ee0@2@@Z @717d03826bc6 @w9d7191df5fed
namespace fn_001d7ee0 {
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 31/32, incomplete)
// FUN_001d7ee0 @ 0x001d7ee0
struct Ref_1d7ee0 { virtual void retain(); virtual void release(); };
struct State_1d7ee0 {  };
struct Display_1d7ee0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void enable(int); virtual void v4(); virtual void v5(); virtual void v6(); virtual void refresh(); void FUN_002ef8b0(int); };
struct Holder_1d7ee0 { char pad[16]; Display_1d7ee0* display; };
struct Object { char pad0[0xa0]; Holder_1d7ee0* holder; char pad1[0x48]; State_1d7ee0* state; char pad2[0x24]; Ref_1d7ee0* current;
void FUN_001d71e0(Ref_1d7ee0*); void FUN_001d7510(); void FUN_0027d4f0(int); void target(Ref_1d7ee0*);
};
void Object::target(Ref_1d7ee0* incoming) {
 if(current==incoming) return;
 if(current) { current->release(); current=0; }
 int mode=((owners::C_1d4de0 *)state)->FUN_001d4de0();
 if(incoming) {
 FUN_001d71e0((mode==8 || mode==9)?0:incoming);
 incoming->retain();
 if(current) current->release();
 current=incoming;
 if(holder && holder->display) { Display_1d7ee0* d=holder->display; d->FUN_002ef8b0(0); d->refresh(); }
 if(holder && holder->display) holder->display->enable(1);
 FUN_0027d4f0(5);
 } else {
 FUN_001d7510();
 if(holder && holder->display) {
 holder->display->enable(1);
 if(mode==8 || mode==9) { Display_1d7ee0* d=holder ? holder->display : 0; d->refresh(); }
 }
 }
}
} // namespace fn_001d7ee0

namespace fn_f9c60317 {

// 0x001d7ff0 FUN_001d7ff0 (272 B): equivalent/0x001d7ff0.cpp
// sym: ?target@Owner_1d7ff0@fn_f9c60317@@QAEXXZ @9e8165b64d66 @wf43d92e00116
// STATUS: equivalent (tools/equiv.py level 3: 2975 inputs, branch coverage 26/26)
// FUN_001d7ff0 @ 0x001d7ff0
void Owner_1d7ff0::target() {
 if (link) {
  if (link->kind == 1) {
   Slots_1d7ff0* slots = link->slots;
   for (int i=0;i<8;++i) {
    if (((Owner_1d7ff0 *)((owners::C_35ef0 *)slots)->FUN_00035ef0((hulk_intptr)i))==this) {
     slots->FUN_0003acf0(i,0,-1,0,0,0);
     if(marked) {
      Manager_1d7ff0* manager=FUN_0027f250();
      void* entry=((void *)((owners::C_36c60 *)slots)->FUN_00036c60((unsigned int)(i+20)));
      manager->FUN_0027ffb0(entry);
      marked=0;
     }
    }
   }
  }
  FUN_001d7ee0(0);
 }
 Context* context=FUN_001b6580()->context;
 if(context) {
  if(context->active==(resource ? resource->identity : 0)) context->FUN_0003a9d0(0);
  if(context->selected==(resource ? resource->identity : 0)) context->FUN_0003ffa0(0,0);
 }
 if(state!=3) state=2;
 if(flag) flag->enabled=0;
 if(disposable) disposable->release();
 disposable=0;
}


// 0x001d8100 FUN_001d8100 (94 B): matches/0x001d8100.cpp
// sym: ?Run@Manager_1d8100@fn_f9c60317@@QAEXXZ
void Manager_1d8100::Run() {
    State_1d8100* s = item;
    if (s && s->state == 1) {
        Item_1d8100* p = s->ptr;
        if (p) {
            int v = box ? box->value : 0;
            if (p->Get() == v)
                p->Act_0003ee70(0);
        }
    }
    if (item) {
        item->B();
        item = 0;
    }
}

} // namespace fn_f9c60317

// 0x001d8160 FUN_001d8160 (70 B): matches/0x001d8160.cpp [wrapped: conflict: physics::PhysicsObject; physics::SimulatedObject]
// sym: ?FUN_001d8160@Owner@fn_001d8160@@QAEMXZ
namespace fn_001d8160 {
namespace physics {
class SimulatedObject {
  public:
    virtual void s00();
};
class PhysicsObject : public SimulatedObject {
  public:
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual float s36();
};
}  // namespace physics
struct Inner {
    char pad[0x70];
    physics::SimulatedObject* object;
    inline physics::PhysicsObject* cast() { return dynamic_cast<physics::PhysicsObject*>(object); }
};
struct Middle {
    char pad[0x10];
    Inner* inner;
};
struct Owner {
    char pad[0xa0];
    Middle* middle;
    float FUN_001d8160();
};
float Owner::FUN_001d8160() {
    if (middle && middle->inner && middle->inner->object) {
        physics::PhysicsObject* result = middle->inner->cast();
        if (result)
            return result->s36();
    }
    return 1.0f;
}
} // namespace fn_001d8160

namespace fn_f9c60317 {

// 0x001d81b0 FUN_001d81b0 (232 B): matches/0x001d81b0.cpp
// sym: ?run@Target_1d81b0@fn_f9c60317@@QAE_NI_N@Z
bool Target_1d81b0::run(unsigned arg, bool reset) {
    if (!gate->FUN_001d4ef0())
        return false;
    if (state)
        FUN_001d7ee0(0);
    FUN_001d7510();
    Vec_1d81b0* p = object ? &((Pose *)((owners::C_2fc6f0 *)object)->FUN_002fc6f0())->pos : provider->v4();
    position.x = p->x;
    position.y = p->y;
    position.z = p->z;
    if (reset) {
        Body_1d81b0* b = object ? object->body : 0;
        b->z = 0;
        b->y = 0;
        b->x = 0;
        b = object ? object->body : 0;
        Child_1d81b0* c = b->child;
        if (c) {
            c->z = 0;
            c->y = 0;
            c->x = 0;
        }
    }
    Body_1d81b0* b = object ? object->body : 0;
    if (b->child)
        b->child->FUN_002f5a20(arg);
    value = -1.0f;
    return true;
}


// 0x001d82a0 FUN_001d82a0 (35 B): matches/0x001d82a0.cpp
// sym: ?target@fn_f9c60317@@YIXPAVObj_1d82a0@1@@Z
void __fastcall target(Obj_1d82a0* self) {
    self->Do_001d8100();
    if (self->ptr) {
        self->ptr->B();
        self->ptr = 0;
    }
}


// 0x001d82d0 FUN_001d82d0 (114 B): matches/0x001d82d0.cpp
// sym: ?Run@Obj_1d82d0@fn_f9c60317@@QAEHXZ
int Obj_1d82d0::Run() {
    if (!active)
        return -1;
    hulk_intptr x;
    if (holder)
        x = (hulk_intptr)holder->node;
    else
        x = 0;
    if (*(int*)(x + 0x6c))
        return -1;
    Prepare_001d7510();
    Manager_1d82d0* m = hulk_at_004dd700->manager;
    void* q = (char*)this + 8;
    if (!((owners::C_79950 *)m)->FUN_00079950((hulk_intptr)q))
        return -1;
    int r = m->Find_00079800(q);
    if (r != -1)
        m->Use_0007ba60(r);
    return r;
}

} // namespace fn_f9c60317

// 0x001d8350 FUN_001d8350 (856 B): equivalent/0x001d8350.cpp [wrapped: conflict: World]
// sym: ?FUN_001d8350@Collector_1d8350@fn_001d8350@@QAEXPAUFighter_1d8350@2@@Z @f3b3ac5ce2af @wbe523fb5cbc3
namespace fn_001d8350 {
// STATUS: equivalent (tools/equiv.py level 3: 3070 inputs, branch coverage 60/60; --wine 714 inputs)
// FUN_001d8350 @ 0x001d8350
// equiv-map: ??0Id64@@QAE@ABU0@@Z = 0x0027af30
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

struct V3_1d8350 {
    float x, y, z;
    hulk_freg FUN_000259c0();
    void FUN_0022d180();
};

struct Id64 {
    unsigned int lo, hi;
    Id64(const Id64 &src);
};

struct Event_1d8350 {
    char data[0x28];
    void FUN_001ca540(Id64 self, Id64 other, int id);
};

struct Id64Raw_1d8350 {
    unsigned int lo, hi;
};

struct Voice_1d8350 {
    void FUN_00092540(int kind, Id64Raw_1d8350 id, int z);
    char FUN_00092dc0(int v);
    char FUN_00092940(int v);
};

struct Sound_1d8350 {
    void FUN_00090720(const char *name, int flag);
};

struct Singleton_4dd6ec {
    char pad0[0x3c];
    Voice_1d8350 *f3c;
    char pad40[8];
    Sound_1d8350 *f48;
    Voice_1d8350 *FUN_00086340();
    Sound_1d8350 *FUN_00086370();
};

struct Sender {
    void FUN_001cbc20(Event_1d8350 *e);
};

struct World {
    char pad0[0x30];
    Sender *f30;
    char pad34[0x54 - 0x34];
    Singleton_4dd6ec *f54;
};

struct Fighter_1d8350 {
    char pad0[0x10];
    int *f10;
    char pad14[0x1b0c - 0x14];
    float f1b0c;
    char FUN_000373a0(int state);
    void FUN_000352b0(V3_1d8350 *out);
};

struct Owner_1d8350 {
    char pad0[8];
    Id64 id8;
};

extern "C" V3_1d8350 *__cdecl FUN_00083e00(V3_1d8350 *out, V3_1d8350 *a, float s);

class Collector_1d8350 {
public:
    char pad0[8];
    Id64 id8;              // 8
    char pad10[0xec - 0x10];
    Owner_1d8350 *owner;          // 0xec
    float f0;              // 0xf0
    float f4;              // 0xf4
    char bf8;
    char padf9[3];
    int fc;                // 0xfc
    char pad100[0x144 - 0x100];
    char b144;
    char pad145[0x150 - 0x145];
    int state;             // 0x150
    float f154;

    V3_1d8350 *FUN_001d6b40();
    void FUN_001d7810(V3_1d8350 v);
    void FUN_0027d4f0(int v);
    void FUN_001d8350(Fighter_1d8350 *a);
};

struct Frame_1d8350 {
    V3_1d8350 pc;                 // 0xc
    V3_1d8350 d;                  // 0x18
    V3_1d8350 tmp;                // 0x24
    V3_1d8350 v1;                 // 0x30
    V3_1d8350 out;                // 0x3c
    Event_1d8350 ev;              // 0x48
};

void Collector_1d8350::FUN_001d8350(Fighter_1d8350 *a)
{
    Frame_1d8350 f;
    if (a == 0)
        return;
    if (a->f1b0c <= 0.0f)
        return;
    if (b144) {
        if (f154 < 0.5f)
            return;
    }
    if (fc == 2 || fc == 3)
        return;
    if (bf8)
        return;
    if (!a->FUN_000373a0(state))
        return;
    a->FUN_000352b0(&f.v1);
    V3_1d8350 *p = FUN_001d6b40();
    f.pc.x = p->x;
    f.pc.y = p->y;
    f.pc.z = p->z;
    f.d.x = f.v1.x - f.pc.x;
    f.d.y = f.v1.y - f.pc.y;
    f.d.z = f.v1.z - f.pc.z;
    float len = f.d.FUN_000259c0();
    int st = state;
    if (st == 1 || st == 2 || st == 3 || st == 4 || st == 0xb || st == 0xc || st == 0xd) {
        if (len > 1.0f) {
            if (f0 < 1.0f)
                f0 = 0.05f;
            double t = f4 + 0.2f;
            f4 = t;
            f0 = t + f0;
            if (f0 > len)
                f0 = len;
            f.d.FUN_0022d180();
            V3_1d8350 *res = FUN_00083e00(&f.out, &f.d, f0);
            V3_1d8350 r;
            r.x = f.pc.x + res->x;
            r.y = f.pc.y + res->y;
            r.z = f.pc.z + res->z;
            FUN_001d7810(r);
            return;
        }
    }
    if ((unsigned int)st > 0xd)
        return;
    int kind = 1;
    if (st == 0)
        kind = 0;
    else if (st == 7)
        kind = 2;
    else if (st == 0xc || st == 0xd)
        kind = 3;
    if (kind == 0) {
        f4 = 0;
        f0 = 0;
        return;
    }
    if (kind == 3) {
        Id64 c5(id8);
        DAT_004dd6ec->FUN_00086340()->FUN_00092540(5, *(Id64Raw_1d8350 *)&c5, 0);
        DAT_004dd6ec->FUN_00086370()->FUN_00090720("smashcollect", 1);
    } else if (kind == 2) {
        Id64 c4(id8);
        DAT_004dd6ec->FUN_00086340()->FUN_00092540(4, *(Id64Raw_1d8350 *)&c4, 0);
        (*(char*)&DAT_004e2518) = 1;
    }
    FUN_0027d4f0(10);
    int s = state;
    bf8 = 1;
    if (s != 10 && s != 7)
        DAT_004dd6ec->FUN_00086370()->FUN_00090720("prop_collectables", 1);

    Sender *snd = DAT_004dd700->f30;
    if (snd == 0)
        return;
    int fid = *a->f10;
    f.ev.FUN_001ca540(id8, owner->id8, fid);
    int s2 = state;
    if (s2 == 1 || s2 == 2 || s2 == 3 || s2 == 4) {
        Voice_1d8350 *v = DAT_004dd700->f54->FUN_00086340();
        if (!v->FUN_00092dc0(0x15)) {
            v = DAT_004dd700->f54->FUN_00086340();
            if (v->FUN_00092940(0x15))
                snd->FUN_001cbc20(&f.ev);
        }
    }
    snd->FUN_001cbc20(&f.ev);
}
} // namespace fn_001d8350
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d86d0 FUN_001d86d0 (1431 B): equivalent/0x001d86d0.cpp [wrapped: conflict: World]
// sym: ?F@Thing_1d86d0@fn_001d86d0@@QAEXPAUV3_1d86d0@2@PAX@Z @0e16365b516d @w98a8b54c5eb5
namespace fn_001d86d0 {
// STATUS: equivalent (tools/equiv.py level 3: 3081 inputs, branch coverage 61/62, incomplete)
// FUN_001d86d0 @ 0x001d86d0
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct V3_1d86d0 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_000111f0();
    hulk_freg FUN_00018990();
};

struct SymMatrix {
    char data[0x1c];
    void FUN_002fca90();
    void FUN_002fcaa0();
};

struct Mat4_1d86d0 {
    float m[16];
    void FUN_0022cdb0();
    void FUN_0022c3b0(V3_1d86d0 *in, V3_1d86d0 *out);
};

struct Obj70_1d86d0;

struct ObjC_1d86d0 {
    char pad0[0x5c];
    V3_1d86d0 v5c;
    char pad68[0x84 - 0x68];
    char b84;
};

struct Obj70_1d86d0 {
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
    virtual void v17(void *a, V3_1d86d0 *v, int i, int j, int k);
    virtual void v18(void *a, V3_1d86d0 *v, SymMatrix *g, int i, int j, int k);
    virtual void v19(int i, int j, int k);
    virtual void v20(void *a, SymMatrix *g, int i, int j, int k);
    char pad04[0x10 - 4];
    ObjC_1d86d0 *p10;
    char pad14[0x98 - 0x14];
    float f98, f9c, fa0;
    void FUN_0016fc60(V3_1d86d0 *out);
};

struct ObjB_1d86d0 {
    char pad0[0x50];
    V3_1d86d0 v50;
    V3_1d86d0 v5c;
    char pad68[0x70 - 0x68];
    Obj70_1d86d0 *p70;
};

struct ObjA_1d86d0 {
    char pad0[0x10];
    ObjB_1d86d0 *p10;
};

struct Link_1d86d0 {
    unsigned __int64 FUN_001d4f70();
    char FUN_001d4e40();
};

struct Req_1d86d0 {
    void FUN_00083320(V3_1d86d0 *a, V3_1d86d0 *b, int c, int d, V3_1d86d0 *e, int f);
};
struct Hub4c_1d86d0 {
    Req_1d86d0 *FUN_0007ad00(void *p);
};
struct World {
    char pad0[0x4c];
    Hub4c_1d86d0 *p4c;
};


float FUN_00083d90(float *p);

class Thing_1d86d0 {
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Mat4_1d86d0 *v15();
    char pad04[4];
    char sub8[1];
    char pad9[0xa0 - 9];
    ObjA_1d86d0 *pA0;
    char pada4[0xec - 0xa4];
    Link_1d86d0 *link;
    char padf0[0x14d - 0xf0];
    char b14d;
    char pad14e[0x188 - 0x14e];
    V3_1d86d0 v188;
    char pad194[0x25c - 0x194];
    V3_1d86d0 v25c;
    float f268;
    void FUN_001d7510();
    V3_1d86d0 *FUN_001d6b40();
    void F(V3_1d86d0 *v, void *arg2);
};

void Thing_1d86d0::F(V3_1d86d0 *vin, void *arg2)
{
    struct Frame {
        float N;
        V3_1d86d0 V;
        V3_1d86d0 R;
        V3_1d86d0 P1;
        V3_1d86d0 SV1;
        V3_1d86d0 SV2;
        V3_1d86d0 S48;
        SymMatrix G2;
        SymMatrix G1;
        Mat4_1d86d0 M;
    } fr;
    SymMatrix &G1 = fr.G1;
    V3_1d86d0 &V = fr.V;
    v25c.x = vin->x;
    v25c.y = vin->y;
    v25c.z = vin->z;
    f268 = 0;
    if (b14d) {
        Req_1d86d0 *r = DAT_004dd700->p4c->FUN_0007ad00(sub8);
        if (r) {
            fr.R.x = 0; fr.R.y = 0; fr.R.z = 0;
            r->FUN_00083320(&fr.R, &fr.R, 0, 1, &fr.R, 0);
        }
    }
    if (!pA0 || !pA0->p10 || !pA0->p10->p70)
        return;
    V.x = vin->x;
    V.y = vin->y;
    V.z = vin->z;
    float &N = fr.N;
    N = V.FUN_0022d110();
    if (N < 0.01f)
        return;
    FUN_001d7510();
    V3_1d86d0 *pos = FUN_001d6b40();
    v188.x = pos->x;
    v188.y = pos->y;
    v188.z = pos->z;
    unsigned __int64 id = link->FUN_001d4f70();
    *(volatile unsigned int *)&fr.P1.y = (unsigned int)(id >> 32);
    bool match = id == (*(unsigned __int64*)&DAT_004dc0c0) || id == (*(unsigned __int64*)&DAT_004dc098) || id == (*(unsigned __int64*)&DAT_004dc078);
    if (match) {
        if (V.y > 0.4f && V.y < 0.97f) {
            V.y = 0;
            hulk_freg l = V.FUN_000111f0();   // the original divides by the unrounded st0 (fdivr on the call result)
            V.y = 0.4f;
            double k = sqrt((double)0.84f / (double)l);
            V.x = V.x * k;
            V.z = V.z * k;
            V.FUN_0022d110();
            N = N * 1.5f;
        } else if (!(V.y >= 0.97f)) {
            N = N + N;
        } else {
            N = N * 0.7f;
        }
    }
    ObjB_1d86d0 *B = pA0->p10;
    Obj70_1d86d0 *o70 = B->p70;
    void *a2 = arg2;
    V3_1d86d0 &SV1 = fr.SV1;
    V3_1d86d0 &SV2 = fr.SV2;
    SV1 = B->v50;
    SV2 = B->v5c;
    o70->v17(a2, &V, 0, -1, -1);
    G1.FUN_002fca90();
    o70->v20(a2, &G1, 0, -1, -1);
    V.x = V.x * N;
    V.y = V.y * N;
    V.z = V.z * N;
    o70->v18(a2, &V, &G1, 0, -1, -1);
    o70->v19(1, -1, -1);
    v25c.x = V.x;
    v25c.y = V.y;
    v25c.z = V.z;
    V3_1d86d0 &TV = fr.R;
    TV = o70->p10->v5c;
    if (!o70->p10->b84) {
        V3_1d86d0 &S48 = fr.S48;
        o70->FUN_0016fc60(&S48);
        ObjB_1d86d0 *b2 = pA0->p10;
        b2->v50.x = SV1.x;
        b2->v50.z = SV1.z;
        b2->v50.y = SV1.y;
        ObjB_1d86d0 *b3 = pA0->p10;
        b3->v5c.x = SV2.x;
        b3->v5c.z = SV2.z;
        b3->v5c.y = SV2.y;
        o70->v17(&S48, &V, 0, -1, -1);
        SymMatrix &G2 = fr.G2;
        G2.FUN_002fca90();
        o70->v20(&S48, &G2, 0, -1, -1);
        o70->v18(&S48, &V, &G2, 0, -1, -1);
        o70->v19(1, -1, -1);
        match = id == (*(unsigned __int64*)&DAT_004dc0c0) || id == (*(unsigned __int64*)&DAT_004dc098) || id == (*(unsigned __int64*)&DAT_004dc078);
        if (match && TV.FUN_000111f0() > 0.1f) {
            Mat4_1d86d0 &M = fr.M;
            M = *v15();
            M.FUN_0022cdb0();
            V3_1d86d0 &P1 = fr.P1;
            M.FUN_0022c3b0(&TV, &P1);
            union { float f; unsigned int u; } t;
            t.f = P1.x;
            t.u &= 0x7fffffff;
            if (t.f >= 0.1f) {
                float sgn = FUN_00083d90(&P1.x);
                TV.x = 0.1f;
                if (!(sgn > 0.0f))
                    TV.x = -0.1f;
            }
            t.f = P1.z;
            t.u &= 0x7fffffff;
            if (t.f >= 0.1f) {
                float sgn = FUN_00083d90(&P1.z);
                TV.z = 0.1f;
                if (!(sgn > 0.0f))
                    TV.z = -0.1f;
            }
            P1.y = P1.y * 3.0f;
            v15()->FUN_0022c3b0(&P1, &TV);
        }
        ObjB_1d86d0 *b4 = pA0->p10;
        b4->v5c.x = TV.x;
        b4->v5c.y = TV.y;
        b4->v5c.z = TV.z;
        G2.FUN_002fcaa0();
    }
    if (link->FUN_001d4e40()) {
        unsigned __int64 id2 = link->FUN_001d4f70();
        if (id2 != (*(unsigned __int64*)&DAT_004e2548)) {
            V3_1d86d0 *bv = &pA0->p10->v50;
            if (bv->FUN_00018990() > 50.0f) {
                bv->FUN_0022d110();
                bv->x = bv->x * 50.0f;
                bv->y = bv->y * 50.0f;
                bv->z = bv->z * 50.0f;
            }
        }
    }
    G1.FUN_002fcaa0();
}
} // namespace fn_001d86d0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9c60317 {

// 0x001d8c70 FUN_001d8c70 (85 B): matches/0x001d8c70.cpp
// sym: ?Set@Obj_1d8c70@fn_f9c60317@@QAEXPAVItem_1d8c70@2@@Z
void Obj_1d8c70::Set(Item_1d8c70* p) {
    Prep_001d8100();
    if (p != 0 && p->mState == 1 && p->mChild != 0) {
        void* q = mAtA0;
        p->mChild->Run_0003ee70(q ? *(int*)((char*)q + 0x10) : 0);
        p->First();
        Old_1d8c70* o = (Old_1d8c70*)mItem;
        if (o)
            o->B();
        mItem = p;
    }
}

} // namespace fn_f9c60317

// 0x001d8cd0 FUN_001d8cd0 (192 B): equivalent/0x001d8cd0.cpp [wrapped: conflict: World]
// sym: ?FUN_001d8cd0@Object@fn_001d8cd0@@QAEXXZ @de0e3d8b8f56 @wa1dc620e52b7
namespace fn_001d8cd0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_001d8cd0 @ 0x001d8cd0
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

struct Resource_1d8cd0 { virtual void slot0(); virtual void release(); };
struct Manager_1d8cd0 { void FUN_00029c00(unsigned int handle); };
struct World { char pad[0x20]; Manager_1d8cd0* manager; };
struct Handle_1d8cd0 { char pad[0x10]; unsigned int value; };
struct Object {
 char pad0[0xa0]; Handle_1d8cd0* handle;
 char pad1[0x1fc-0xa4];
 Resource_1d8cd0* resource1;
 unsigned int x200, x204, x208, x20c, x210, x214, x218;
 Resource_1d8cd0* resource2;
 unsigned int x220, x224, x228, x22c, x230, x234;
 Resource_1d8cd0* resource3;
 void FUN_001d8100();
 void FUN_001d8cd0();
};
void Object::FUN_001d8cd0() {
 if (DAT_004dd700 && DAT_004dd700->manager) {
  DAT_004dd700->manager->FUN_00029c00(handle ? handle->value : 0);
 }
 if(resource1) { resource1->release(); resource1=0; }
 x208=0; x204=0; x200=0;
 x214=0; x210=0; x20c=0; x218=0;
 FUN_001d8100();
 if(resource2) { resource2->release(); resource2=0; }
 x220=0; x224=0; x228=0; x22c=0; x234=0;
 if(resource3) { resource3->release(); resource3=0; }
}
} // namespace fn_001d8cd0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d8d90 FUN_001d8d90 (255 B): matches/0x001d8d90.cpp [wrapped: conflict: Object; World]
// sym: ?FUN_001d8d90@Object@fn_001d8d90@@QAEXE@Z
namespace fn_001d8d90 {
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

struct Bounds_1d8d90 {
    unsigned int values[4];
};
struct Descriptor_1d8d90 {
    unsigned int kind;
    Bounds_1d8d90 bounds;
    char rest[12];
    void FUN_00067e20();
    void FUN_000679c0();
};
struct Manager_1d8d90 {
    unsigned int FUN_00067ba0();
    void FUN_00067c80(unsigned int);
    void FUN_00067c30(unsigned int, Descriptor_1d8d90*);
};
struct Subsystem_1d8d90 {
    char pad[8];
    Manager_1d8d90* manager;
};
struct World {
    char pad[32];
    Subsystem_1d8d90* subsystem;
};
struct Inner_1d8d90 {
    char pad[16];
    unsigned int* value;
};
struct Link_1d8d90 {
    char pad[8];
    Inner_1d8d90* inner;
    unsigned int type;
};
struct Component_1d8d90 {
};
struct Object {
    char pad0[0x118];
    Link_1d8d90* link;
    char pad1[0xad];
    unsigned char active;
    char pad2[2];
    unsigned int handle;
    char pad3[0x70];
    Component_1d8d90 component;
    void FUN_001d8cd0();
    void FUN_001d71e0(int);
    unsigned char FUN_001d7360(Bounds_1d8d90*);
    void FUN_001d8d90(unsigned char enabled);
};
void Object::FUN_001d8d90(unsigned char enabled) {
    if (enabled == active)
        return;
    active = enabled;
    if (!enabled) {
        if (handle) {
            DAT_004dd700->subsystem->manager->FUN_00067c80(handle);
            handle = 0;
        }
        FUN_001d8cd0();
        ((owners::Target_27b040 *)&component)->FUN_0027b040((hulk_uintptr)0);
        FUN_001d71e0(0);
        return;
    }
    Bounds_1d8d90 bounds;
    if (FUN_001d7360(&bounds)) {
        Manager_1d8d90* manager = DAT_004dd700->subsystem->manager;
        handle = manager->FUN_00067ba0();
        Descriptor_1d8d90 descriptor;
        descriptor.FUN_00067e20();
        descriptor.bounds = bounds;
        if (link && link->type == 1 && link->inner)
            descriptor.kind = *link->inner->value;
        manager->FUN_00067c30(handle, &descriptor);
        descriptor.FUN_000679c0();
    }
}
} // namespace fn_001d8d90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d8e90 FUN_001d8e90 (291 B): matches/0x001d8e90.cpp [wrapped: conflict: CSPHulkPropInstance; FUN_001b6580; World]
// sym: ??1CSPHulkPropInstance@fn_001d8e90@@QAE@XZ
namespace fn_001d8e90 {
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

struct Resource_1d8e90 {
    virtual void slot0();
    virtual void release();
};
struct Controller_1d8e90 {
    char pad0[8];
    unsigned int field8, fieldC;
    char pad10[0x74];
    unsigned char active;
    void FUN_002fd8a0(int);
};
struct Link_1d8e90 {
    char pad[0x10];
    Controller_1d8e90* controller;
};
struct Manager_1d8e90 {
    void FUN_00067c80(void*);
};
struct Subsystem_1d8e90 {
    char pad[8];
    Manager_1d8e90* manager;
};
struct World {
    char pad[0x20];
    Subsystem_1d8e90* subsystem;
};
struct Handle_1d8e90 {
    void FUN_0027af50();
    char bytes[12];
};
struct CSPHulkPropInstance;
struct A_1d8e90 {
    void FUN_001b4540(CSPHulkPropInstance*);
};
struct B_1d8e90 {
    void FUN_001c3b80(void*);
};
struct CSPHulkPropInstance;
A_1d8e90* __stdcall FUN_001b6580();
B_1d8e90* FUN_001c3d90();  // 0-argument singleton getter
struct CSPHulkPropInstance {
    virtual void slot0_00038290();
    virtual void slot1_000382a0();
    char pad4[0x9c];
    Link_1d8e90* link;
    char padA4[0x70];
    Resource_1d8e90* r114;
    Resource_1d8e90* r118;
    Resource_1d8e90* r11c;
    Resource_1d8e90* r120;
    char pad124[0x10];
    Resource_1d8e90* r134;
    char pad138[0x94];
    void* r1cc;
    char pad1d0[12];
    Resource_1d8e90* r1dc;
    char pad1e0[0x60];
    Handle_1d8e90 handle;
    Resource_1d8e90* r24c;
    void FUN_001d8cd0();
    void FUN_001d8100();
    void FUN_0027e2d0();
    ~CSPHulkPropInstance();
};
CSPHulkPropInstance::~CSPHulkPropInstance() {
    FUN_001d8cd0();
    if (r24c) {
        r24c->release();
        r24c = 0;
    }
    if (r1cc) {
        DAT_004dd700->subsystem->manager->FUN_00067c80(r1cc);
        r1cc = 0;
    }
    FUN_001d8100();
    if (r120) {
        r120->release();
        r120 = 0;
    }
    if (r134) {
        r134->release();
        r134 = 0;
    }
    if (link && link->controller) {
        Controller_1d8e90* c = link->controller;
        bool active = c->active != 0;
        c->fieldC = 0;
        c->field8 = 0;
        if (active)
            c->FUN_002fd8a0(0);
    }
    FUN_001b6580()->FUN_001b4540(this);
    FUN_001c3d90()->FUN_001c3b80((char*)this + 8);
    if (r11c) {
        r11c->release();
        r11c = 0;
    }
    if (r118) {
        r118->release();
        r118 = 0;
    }
    if (r114) {
        r114->release();
        r114 = 0;
    }
    if (r1dc)
        r1dc->release();
    r1dc = 0;
    handle.FUN_0027af50();
    FUN_0027e2d0();
}
} // namespace fn_001d8e90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001d8fc0 FUN_001d8fc0 (4982 B): equivalent/0x001d8fc0.cpp [wrapped: conflict: CSPHulkPropInstance; DAT_004dd700; FUN_001c3d90; FUN_0027b020 (+2)]
// sym: ?FUN_001d8fc0@CSPHulkPropInstance@fn_001d8fc0@@QAEXM@Z @35fb518564bd @w28c8499f42af
namespace fn_001d8fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3086 inputs, branch coverage 255/270, incomplete; Wine build 3081 inputs, 265/270)
// FUN_001d8fc0 @ 0x001d8fc0
// CSPHulkPropInstance per-frame update (FUN_001d8fc0): steering of the prop's velocity vectors,
// ground/water level crossings, StateProp event keys.


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sqrt(double);
#endif


struct Vec3_1d8fc0 {
    float x, y, z;
    hulk_freg FUN_0022d110();          // normalize in place, returns the old length
    void FUN_00011140(float s);
};

struct Matrix {
    float m0, m1, m2, m3;
    float m4, m5, m6, m7;
    float m8, m9, m10, m11;
    Vec3_1d8fc0 t;
    float m15;
    void FUN_0022b980();           // identity
    void FUN_0022ba70(float ang);
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
    void FUN_0022c3b0(const Vec3_1d8fc0 *in, Vec3_1d8fc0 *out);
    void FUN_0022be40(const Vec3_1d8fc0 *v);
};

struct Key64 {
    unsigned int lo;
    unsigned int hi;
};

struct Bounds_1d8fc0 {
    float x, y, z, w;
};

struct Descriptor_1d8fc0 {
    unsigned int kind;
    Bounds_1d8fc0 bounds;
    char rest[12];
    struct Desc0;
    void FUN_00067e60(const void *src);
    void FUN_000679c0();
};

struct Mgr_1d8fc0 {
    void *FUN_00067ad0(int h);
    void FUN_00067c30(int h, Descriptor_1d8fc0 *d);
    void FUN_00067c80(int h);
};

struct Sink_1d8fc0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(const Vec3_1d8fc0 *from, Vec3_1d8fc0 *out, int mode);
};

struct Ctl_1d8fc0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(int a);
    virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual bool v11();
    virtual void v12();
    virtual void v13();
    char pad4[0x10 - 4];
    Sink_1d8fc0 *p10;
    char pad14[0x72 - 0x14];
    unsigned char b72;
    char pad73[0x98 - 0x73];
    Vec3_1d8fc0 v98;
    void FUN_002f5a20(const Vec3_1d8fc0 *v);
    void FUN_0016fc90(Vec3_1d8fc0 *out);
};

struct P20 {
    char pad0[0x34];
    float f34;
};

struct Sub74_1d8fc0 {
    char pad0[0x20];
    P20 *p20;
    char pad24[0x50 - 0x24];
    unsigned char b50;
    char pad51[0x72 - 0x51];
    unsigned char b72;
};

struct Entity {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void v7();
    char pad4[0x50 - 4];
    Vec3_1d8fc0 v50;
    Vec3_1d8fc0 v5c;
    char pad68[0x70 - 0x68];
    Ctl_1d8fc0 *p70;
    Sub74_1d8fc0 *p74;
    void FUN_002ef8b0(int a);
};

struct Holder_1d8fc0 {
    char pad0[0x10];
    Entity *p10;
    Matrix *FUN_002fc6f0();
};

struct Hit8 {
    char pad0[0x148];
    int i148;
};

struct Hit_1d8fc0 {
    char pad0[8];
    Hit8 *p8;
    int type;
    char pad10[0x74 - 0x10];
    Sub74_1d8fc0 *p74;
};

struct PosProvider {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual Vec3_1d8fc0 *v4();
};

struct StateObj_1d8fc0 {
    bool FUN_001d4e50();
    int FUN_001d4de0();
    int FUN_001d5e80(int a);
    bool FUN_001d4e40();
};

struct Rng_1d8fc0 {
    hulk_freg FUN_00078780();
};

struct Singleton_1d8fc0 {
    bool FUN_001c3c90();
    Vec3_1d8fc0 *FUN_001c39d0();
    void FUN_001c3ca0(int on);
};

struct Elem_1d8fc0 {
    Vec3_1d8fc0 v0;
    char pad0c[0x28 - 0x0c];
    unsigned int lo28;
    unsigned int hi2c;
    char pad30[0x40 - 0x30];
    unsigned int lo40;
    unsigned int hi44;
    char pad48[0x50 - 0x48];
    float f50;
    char pad54[0x58 - 0x54];
};

struct ObjList_1d8fc0 {
    char pad0[0x44];
    int count;
    Elem_1d8fc0 *elems;
};

struct ObjArr {
    char pad0[0x1c];
    ObjList_1d8fc0 **arr;
};

struct Item24 {
    Vec3_1d8fc0 v;
    int i0c;
    char pad10[0x24 - 0x10];
};

struct Waypoints {
    virtual void v0();
    virtual void v1();
    char pad4[0x14 - 4];
    int i14;
    Item24 *FUN_00106160(int i);
};

struct Obj24c {
    virtual void v0();
    virtual void v1();
    char pad4[0xc - 4];
    int i0c;
};

struct Obj21c {
    virtual void v0();
    virtual void v1();
};

struct Layer54 {
    int FUN_00204200(float x, float y, float z);
    bool FUN_00204440(int idx);
};

struct Mid54 {
    Layer54 *FUN_000862a0();
};

struct Fx_1d8fc0 {
    void FUN_00283a40(const unsigned int *key, const Matrix *m, float a, float b);
};

struct Fx34_1d8fc0 {
    void FUN_001ec060(void *inst, const char *s);
};

struct Fx10;

struct Root24 {
    char pad0[0x18];
    float f18;
    char pad1c[0x20 - 0x1c];
    unsigned int lo20;
    unsigned int hi24;
    char c28[1];
};

struct Q20 {
    char pad0[8];
    Mgr_1d8fc0 *p8;
    void FUN_00029bb0(Entity *e, Obj21c *o, float f);
};

struct Root10 {
    void FUN_001b4620(Vec3_1d8fc0 v, int idx, Entity *e, Obj24c *o);
};

class CSPHulkPropInstance;

struct Root0c {
    CSPHulkPropInstance *FUN_001e47e0(CSPHulkPropInstance *inst, Elem_1d8fc0 *el);
};

struct Root_1d8fc0 {
    char pad0[0xc];
    Root0c *p0c;
    Root10 *p10;
    char pad14[0x20 - 0x14];
    Q20 *p20;
    Root24 *p24;
    char pad28[0x34 - 0x28];
    Fx34_1d8fc0 *p34;
    char pad38[0x54 - 0x38];
    Mid54 *p54;
};

struct Key2_1d8fc0 {
    unsigned int lo;
    unsigned int hi;
};

namespace pure3d {
namespace prop {
class StateProp {
public:
    virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3();
    virtual void vfunc_4(); virtual void vfunc_5();
    virtual void vfunc_6(float dt, int a);
    virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10();
    virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14();
    virtual Matrix *vfunc_15();
};
}
}

struct Obj72e0 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(const Matrix *m, int a);
    char pad4[0x40 - 4];
    Vec3_1d8fc0 v40;
};

extern hulk_freg FUN_00224f10(const Vec3_1d8fc0 *v);
extern hulk_freg FUN_00224fc0(float a, float b);
extern float FUN_00083d90(const float *p);
extern void FUN_00224d70(float ang, Vec3_1d8fc0 *v);
extern "C" void FUN_00224db0(Matrix *out, const Vec3_1d8fc0 *from, const Vec3_1d8fc0 *to);
extern "C++" __declspec(nothrow) bool FUN_00018960(float a, float b, float eps);
extern "C++" __declspec(nothrow) Key64 FUN_0027b020(const char *s);
extern "C" Rng_1d8fc0 *FUN_000964d0();
extern Singleton_1d8fc0 *FUN_001c3d90();
extern Fx_1d8fc0 *FUN_0027f250();
extern "C" int FUN_00098190(float a, float b, int c, int d, Obj21c *e, float f, Vec3_1d8fc0 *g, Vec3_1d8fc0 *h, int i,
                        int j, int k, int l);
extern "C" bool FUN_00202560(const Vec3_1d8fc0 *a, float b, int c, Vec3_1d8fc0 *d, Bounds_1d8fc0 *e, Vec3_1d8fc0 *f, Hit_1d8fc0 **g, int h);



#define DAT_004dd700 (*(Root_1d8fc0 * *)&::DAT_004dd700)


// The original keeps these in fixed stack words and hands pointers to them to callees (the checker
// compares what lies around them), and re-uses the same words for different values over time.
struct Frame_1d8fc0 {
    float f140;             // E-0x140: sec, later the heading a1, later the water level wl
    union {
        float f13c;         // E-0x13c: flag / ff / l / a3
        unsigned int u13c;
    };
    char p138[3];
    bool A3;                // E-0x135
    float f134;             // E-0x134: l2, secCopy, sc
    Vec3_1d8fc0 v130;              // E-0x130: scratch vector
    Vec3_1d8fc0 dir;               // E-0x124
    union {
        float f118;         // E-0x118
        Sub74_1d8fc0 *s74;
    };
    char p114[3];
    unsigned char sv;       // E-0x111
    union {
        float f110;         // E-0x110
        Hit_1d8fc0 *hitObj;
        int count;
    };
    Vec3_1d8fc0 v10c;              // E-0x10c
    union {
        float f100;         // E-0x100
        ObjList_1d8fc0 *o;
        Root24 *r24;
    };
    char pfc[3];
    bool A5;                // E-0xf9
    Vec3_1d8fc0 v0f8;              // E-0xf8
    Bounds_1d8fc0 b0ec;            // E-0xec
    float f0dc;             // E-0xdc
    Vec3_1d8fc0 v0d8;              // E-0xd8
    Matrix mcc;             // E-0xcc
    Vec3_1d8fc0 v08c;              // E-0x8c
    Matrix m80;             // E-0x80
    Matrix m40;             // E-0x40
};

class CSPHulkPropInstance : public pure3d::prop::StateProp {
public:
    char pad4[0x40 - 4];
    int i40;
    float f44;
    char pad48[0x98 - 0x48];
    ObjArr *p98;
    char pad9c[0xa0 - 0x9c];
    Holder_1d8fc0 *pa0;
    char pada4[0xec - 0xa4];
    StateObj_1d8fc0 *pec;
    char padf0[0x111 - 0xf0];
    unsigned char b111;
    char pad112[0x114 - 0x112];
    int i114;
    char pad118[0x11c - 0x118];
    PosProvider *p11c;
    Waypoints *p120;
    int i124;
    float f128;
    unsigned char b12c;
    char pad12d[0x154 - 0x12d];
    float f154;
    Vec3_1d8fc0 v158;
    char pad164[0x1c8 - 0x164];
    unsigned char b1c8;
    unsigned char b1c9;
    char pad1ca[0x1cc - 0x1ca];
    int h1cc;
    char pad1d0[0x200 - 0x1d0];
    Vec3_1d8fc0 v200;
    Vec3_1d8fc0 v20c;
    float f218;
    Obj21c *p21c;
    int i220;
    char pad224[0x248 - 0x224];
    int i248;
    Obj24c *p24c;
    char pad250[0x258 - 0x250];
    Entity *p258;
    float f25c, f260, f264, f268;
    unsigned char b26c;
    char pad26d[0x270 - 0x26d];
    float f270;

    void FUN_001d8fc0(float dt);

    void FUN_001d69f0(Vec3_1d8fc0 *out);
    void FUN_001d82a0();
    void FUN_001d8cd0();
    void FUN_001d8d90(int on);
    void FUN_001d71e0(int a);
    bool FUN_001d7360(Bounds_1d8fc0 *b);
    Obj72e0 *FUN_001d72e0();
    void FUN_001d7d50();
    float FUN_001d8160();
    void FUN_001d6b60(Matrix m, float s);

    Entity *GetEntity() { return pa0 ? pa0->p10 : 0; }
    const Vec3_1d8fc0 *GetPos()
    {
        if (pa0)
            return &pa0->FUN_002fc6f0()->t;
        return p11c->v4();
    }
};

void CSPHulkPropInstance::FUN_001d8fc0(float dt)
{
    Frame_1d8fc0 F;
    float &sec = F.f140;

    // x87: the original stores the step with fst and adds the register copy (unrounded) to the clock
    hulk_freg step = dt * 0.001f;
    sec = step;
    f154 = f154 + step;
    b111 = 0;
    if (f270 > 0.0f) {
        if (pa0) {
            Entity *e = pa0->p10;
            if (e) {
                Ctl_1d8fc0 *c = e->p70;
                if (c) {
                    if (c->v11())
                        GetEntity()->p70->v13();
                }
            }
        }
        f270 = f270 - sec;
    }

    b1c8 = 0;
    if (pa0) {
        Entity *e = pa0->p10;
        if (e) {
            Ctl_1d8fc0 *c = e->p70;
            if (c) {
                if (!c->v11()) {
                    if (FUN_000964d0()->FUN_00078780() < 0.005f)
                        GetEntity()->p70->v10();
                }
            }
        }
    }

    if (pec->FUN_001d4e50()) {
        bool b = FUN_001c3d90()->FUN_001c3c90();
        if (!b || b26c) {
            F.v130 = *FUN_001c3d90()->FUN_001c39d0();
            const Vec3_1d8fc0 *p = GetPos();
            float dx = F.v130.x - p->x;
            float dy = F.v130.y - p->y;
            float dz = F.v130.z - p->z;
            bool nearP = (dx * dx + dy * dy + dz * dz) <= 6400.0f;
            if (!b) {
                if (nearP) {
                    b26c = 1;
                    FUN_001c3d90()->FUN_001c3ca0(1);
                }
            } else if (!nearP) {
                FUN_001c3d90()->FUN_001c3ca0(0);
                b26c = 0;
            }
        }
    }

    if (b1c9) {
        F.A5 = pec->FUN_001d4de0() == 5;
        F.A3 = pec->FUN_001d5e80(i40) == 3;
        bool A2 = pec->FUN_001d5e80(i40) == 2;
        Ctl_1d8fc0 *ctl = GetEntity()->p70;

        if (f218 > 0.0f) {
            F.dir = v200;
            f218 = f218 - sqrt(v200.x * v200.x + v200.y * v200.y + v200.z * v200.z) * sec;   // x87: root unrounded
            F.f134 = F.dir.FUN_0022d110();          // l2
            if (p21c != 0) {
                F.v130.x = 0.0f;
                F.v130.y = 0.0f;
                F.v130.z = 0.0f;
                if (ctl)
                    F.v130 = ctl->v98;
                else
                    FUN_001d69f0(&F.v130);
                F.f13c = 0.0f;
                if (A2)
                    F.f13c = 1.0f;
                if (FUN_00098190(sec, F.f134, i220, 0, p21c, F.f13c, &F.v130, &F.dir, 0, 0, 0, 1)) {
                    v200 = F.dir;
                    v200.x = F.f134 * v200.x;
                    v200.y = F.f134 * v200.y;
                    v200.z = F.f134 * v200.z;
                    DAT_004dd700->p20->FUN_00029bb0(GetEntity(), p21c, f218);
                } else {
                    FUN_001d82a0();
                }
            }

            if (F.A3) {
                F.v0d8.x = 0.0f;
                F.v0d8.y = 0.0f;
                F.v0d8.z = 0.0f;
                if (ctl)
                    F.v0d8 = ctl->v98;
                else
                    FUN_001d69f0(&F.v0d8);
                F.f13c = 0.0f;
                F.s74 = 0;
                if (pa0) {
                    Entity *e = pa0->p10;
                    if (e) {
                        F.s74 = e->p74;
                        if (F.s74) {
                            P20 *q = F.s74->p20;
                            if (q)
                                F.f13c = q->f34;
                        }
                    }
                }
                F.sv = 1;
                if (F.s74) {
                    F.sv = F.s74->b72;
                    F.s74->b72 = 0;
                }
                F.v0f8.x = F.v0d8.x;
                F.v0f8.y = F.v0d8.y + 0.5f;
                F.v0f8.z = F.v0d8.z;
                F.hitObj = 0;
                if (FUN_00202560(&F.v0f8, F.f13c + 1.0f, 1, &F.v10c, &F.b0ec, &F.v130, &F.hitObj, 0)) {
                    if (F.hitObj) {
                        switch (F.hitObj->type) {
                        case 1:
                        case 6:
                        case 7:
                            F.v10c = F.v130;
                            break;
                        case 5: {
                            Hit8 *h8 = F.hitObj->p8;
                            if (h8) {
                                if (h8->i148 != 0)
                                    F.v10c = F.v130;
                                else if (!F.hitObj->p74->b50)
                                    F.v10c = F.v130;
                            }
                            break;
                        }
                        default:
                            break;
                        }
                    }
                    F.f100 = F.v0d8.y - F.v10c.y;
                    bool done = false;
                    if (F.f100 < F.f13c + 0.5f) {
                        F.f0dc = v200.FUN_0022d110();
                        v200.y = F.dir.y;
                        v200.x = F.dir.x;
                        v200.z = F.dir.z;
                        v200.y = 0.0f;
                        v200.FUN_0022d110();
                        v200.FUN_00011140(F.f0dc);
                        if (F.f100 < F.f13c && ctl) {
                            ctl->v6(0);
                            ctl->FUN_0016fc90(&F.v08c);
                            v200.y = F.v08c.y * 0.25f;
                            v200.FUN_0022d110();
                            v200.FUN_00011140(F.f0dc);
                            done = true;
                        }
                    }
                    if (!done) {
                        if (p21c == 0)
                            i248 = 1;
                    }
                } else {
                    F.A3 = false;
                }
                if (F.s74)
                    F.s74->b72 = F.sv;
            }

            if (i248 <= 0) {
                if (F.A5) {
                    if (!(DAT_004e263c & 1)) {
                        DAT_004e263c |= 1;
                        (*(Vec3_1d8fc0*)&DAT_004e2630).x = 0.0f;
                        (*(Vec3_1d8fc0*)&DAT_004e2630).y = -1.0f;
                        (*(Vec3_1d8fc0*)&DAT_004e2630).z = 0.0f;
                    }
                    if (F.f134 > 0.0f) {
                        F.m80.FUN_0022b980();
                        if (!FUN_00018960(F.dir.y, (*(Vec3_1d8fc0*)&DAT_004e2630).y, 1e-05f))
                            FUN_00224db0(&F.m80, ((Vec3_1d8fc0*)&DAT_004e2630), &F.dir);
                        v20c.z = dt * v20c.x * 0.001f + v20c.z;
                        F.m40.FUN_0022b980();
                        F.m40.FUN_0022ba70(v20c.z);
                        F.mcc.FUN_0022b980();
                        F.mcc.FUN_0022ca90(&F.m40, &F.m80);
                        F.mcc.t = FUN_001d72e0()->v40;
                        FUN_001d72e0()->v6(&F.mcc, 0);
                    }
                } else {
                    Entity *e = GetEntity();
                    e->v5c.x = v20c.x;
                    e->v5c.y = v20c.y;
                    e->v5c.z = v20c.z;
                }
                if (ctl) {
                    ctl->v6(0);
                    ctl->FUN_002f5a20(&v200);
                }
            } else {
                if (F.A3) {
                    ctl->v6(0);
                    ctl->p10->v8(&ctl->v98, &F.v0f8, -1);
                    F.f13c = v200.FUN_0022d110();
                    v200.y = F.v0f8.y;
                    v200.x = F.v0f8.x;
                    v200.z = F.v0f8.z;
                    v200.FUN_0022d110();
                    v200.x = F.f13c * v200.x;
                    v200.y = F.f13c * v200.y;
                    v200.z = F.f13c * v200.z;

                    Vec3_1d8fc0 *s = &v20c;
                    F.f13c = (float)sqrt(s->x * s->x + s->y * s->y + s->z * s->z);
                    Entity *e = GetEntity();
                    s->x = e->v5c.x;
                    s->y = e->v5c.y;
                    s->z = e->v5c.z;
                    s->FUN_0022d110();
                    s->x = F.f13c * s->x;
                    s->y = F.f13c * s->y;
                    s->z = F.f13c * s->z;
                }
            }

            i248 = i248 - 1;
            if (!F.A3 && p21c == 0)
                FUN_001d8cd0();
        }

        {
            Entity *e = GetEntity();
            if (e->v50.x * e->v50.x + e->v50.y * e->v50.y + e->v50.z * e->v50.z < 25.0f) {
                FUN_001d8d90(0);
                FUN_001d71e0(0);
            }
        }
    }

    if (h1cc != 0) {
        Mgr_1d8fc0 *mgr = DAT_004dd700->p20->p8;
        void *d0 = mgr->FUN_00067ad0(h1cc);
        if (d0) {
            if (FUN_001d7360(&F.b0ec)) {
                Descriptor_1d8fc0 &desc = (Descriptor_1d8fc0 &)F.mcc;
                desc.FUN_00067e60(d0);
                Entity *e = GetEntity();
                if (e) {
                    F.v130 = e->v50;
                    // the returned length stays unrounded on the x87 stack (no float local)
                    F.b0ec.w = (F.v130.FUN_0022d110() * dt * 0.001f + F.b0ec.w) * 4.0f;
                    // the original multiplies by the stored (float-rounded) w, not the x87 register
                    volatile float *rw = &F.b0ec.w;
                    F.v130.z = F.v130.z * *rw;
                    F.b0ec.x = F.b0ec.x + F.v130.x * *rw;
                    F.b0ec.y = F.b0ec.y + F.v130.y * *rw;
                    F.b0ec.z = F.b0ec.z + F.v130.z;
                }
                desc.bounds = F.b0ec;
                mgr->FUN_00067c30(h1cc, &desc);
                desc.FUN_000679c0();
            } else {
                mgr->FUN_00067c80(h1cc);
                h1cc = 0;
            }
        } else {
            h1cc = 0;
        }
    }

    if (p120) {
        if (i124 >= 0 && i124 < p120->i14) {
            Entity *e = GetEntity();
            if (e) {
                e->FUN_002ef8b0(0);
                e->v7();
            }
            F.f134 = sec;
            Item24 *item = p120->FUN_00106160(i124);
            F.dir = *GetPos();
            float tz = item->v.z - F.dir.z;
            float ty = item->v.y - F.dir.y;
            float tx = item->v.x - F.dir.x;
            F.v0f8.x = tx;
            F.v0f8.y = ty;
            F.v0f8.z = tz;
            if (F.v0f8.FUN_0022d110() <= 0.5f)
                i124 = item->i0c;
            F.v10c.y = 0.0f;
            if (b12c) {
                F.v10c.x = -1.0f;
                F.v10c.z = 0.0f;
            } else {
                F.v10c.x = 0.0f;
                F.v10c.z = -1.0f;
            }
            vfunc_15()->FUN_0022c3b0(&F.v10c, &F.v130);
            F.f140 = FUN_00224f10(&F.v130);
            F.f118 = FUN_00224f10(&F.v0f8);
            F.f110 = F.f134 * 3.0f;
            F.f100 = FUN_00224fc0(F.f140, F.f118);
            F.f13c = F.f100;
            F.u13c &= 0x7fffffff;
            if (F.f13c <= F.f110)
                F.f140 = F.f118;
            else
                F.f140 = FUN_00083d90(&F.f100) * F.f110 + F.f140;
            F.v130 = (*(Vec3_1d8fc0*)&DAT_004c6068);
            FUN_00224d70(F.f140, &F.v130);
            hulk_freg step = F.f134 * f128;
            F.f118 = -1.5707964f;
            F.dir.x = F.v130.x * step + F.dir.x;
            F.dir.y = F.v130.y * step + F.dir.y;
            F.dir.z = F.v130.z * step + F.dir.z;
            if (!b12c)
                F.f118 = 0.0f;
            F.mcc.FUN_0022b980();
            F.mcc.FUN_0022ba70(F.f118 + F.f140);
            F.mcc.FUN_0022be40(&F.dir);
            FUN_001d6b60(F.mcc, F.f134);
        } else {
            p120->v1();
            p120 = 0;
            f128 = 10.0f;
            i124 = 0;
            b12c = 1;
        }
    }

    if (p24c) {
        if (p24c->i0c == 0) {
            p24c->v1();
            p24c = 0;
        }
    }

    int old40 = i40;
    F.f118 = f44;
    pure3d::prop::StateProp::vfunc_6(dt, 0);
    int new40 = i40;
    F.f0dc = f44;
    if (new40 != old40)
        F.f118 = 0.0f;
    FUN_001d7d50();
    if (new40 != -1) {
        F.o = p98->arr[i40];
        F.count = F.o->count;
        if (F.count > 0) {
            int off = 0;
            do {
                Elem_1d8fc0 *el = (Elem_1d8fc0 *)((char *)F.o->elems + off);
                if (!(DAT_004e263c & 2)) {
                    DAT_004e263c |= 2;
                    Key64 k = FUN_0027b020("StateProp");
                    DAT_004e2628 = k.lo;
                    DAT_004e262c = k.hi;
                }
                if (!(DAT_004e263c & 4)) {
                    DAT_004e263c |= 4;
                    Key64 k = FUN_0027b020("Explosion");
                    DAT_004e2620 = k.lo;
                    DAT_004e2624 = k.hi;
                }
                if (!(el->f50 < F.f118) && el->f50 < F.f0dc) {
                    if (el->lo40 == DAT_004e2628 && el->hi44 == DAT_004e262c) {
                        Root_1d8fc0 *g = DAT_004dd700;
                        if (g) {
                            Root0c *m = g->p0c;
                            if (m) {
                                CSPHulkPropInstance *r = m->FUN_001e47e0(this, el);
                                if (r)
                                    p258 = r->GetEntity();
                            }
                        }
                    } else if (el->lo40 == DAT_004e2620 && el->hi44 == DAT_004e2624) {
                        F.dir = el->v0;
                        vfunc_15()->FUN_0022c3b0(&F.dir, &F.dir);
                        const Vec3_1d8fc0 *pp = GetPos();
                        F.dir.x = F.dir.x + pp->x;
                        F.dir.y = F.dir.y + pp->y;
                        F.dir.z = F.dir.z + pp->z;
                        int idx = 0;
                        while (idx < 6) {
                            if (el->lo28 == ((Key2_1d8fc0*)&DAT_004e25a0)[idx].lo && el->hi2c == ((Key2_1d8fc0*)&DAT_004e25a0)[idx].hi)
                                break;
                            idx++;
                        }
                        Obj24c *ob = 0;
                        if (p24c && p24c->i0c == 1)
                            ob = p24c;
                        DAT_004dd700->p10->FUN_001b4620(F.dir, idx, GetEntity(), ob);
                    }
                }
                off += 0x58;
                F.count--;
            } while (F.count != 0);
        }
    }

    // water level crossing
    const Vec3_1d8fc0 *ppos = GetPos();
    F.v10c.z = ppos->z;
    F.v10c.y = ppos->y;
    float posX = ppos->x;
    Root_1d8fc0 *g = DAT_004dd700;
    F.f140 = g->p24->f18;                    // water level wl
    F.r24 = g->p24;
    bool cross;
    if (F.v10c.y <= F.f140 && v158.y > F.f140)
        cross = true;
    else
        cross = (F.v10c.y >= F.f140) && (v158.y < F.f140);
    if (cross) {
        Layer54 *lay = g->p54->FUN_000862a0();
        int r = lay->FUN_00204200(posX, F.v10c.y, F.v10c.z);
        if (r < 0 || lay->FUN_00204440(r)) {
            Root24 *r24 = F.r24;
            if ((r24->lo20 | r24->hi24) != 0) {
                Fx_1d8fc0 *fx = FUN_0027f250();
                F.mcc.FUN_0022b980();
                const Vec3_1d8fc0 *p2 = GetPos();
                F.mcc.t.x = p2->x;
                F.mcc.t.y = p2->y;
                F.mcc.t.z = p2->z;
                F.mcc.t.y = F.f140;
                F.f134 = FUN_001d8160() * 0.01f;
                if (!(F.f134 < 0.5f)) {
                    if (!(F.f134 <= 10.0f))
                        F.f134 = 10.0f;
                } else {
                    F.f134 = 0.5f;
                }
                fx->FUN_00283a40(&r24->lo20, &F.mcc, -1.0f, F.f134);
            }
            if (r24->c28[0] != 0)
                g->p34->FUN_001ec060(this, r24->c28);
            if (F.v10c.y <= F.f140) {
                if (i114 == 0) {
                    Ctl_1d8fc0 *c2 = GetEntity()->p70;
                    if (c2) {
                        c2->v6(0);
                        c2->p10->v8(&c2->v98, &F.v130, -1);
                        F.v130.x = F.v130.x * 0.25f;
                        F.v130.y = F.v130.y * 0.25f;
                        F.v130.z = F.v130.z * 0.25f;
                        c2->FUN_002f5a20(&F.v130);
                        Entity *e2 = GetEntity();
                        e2->v5c.x = e2->v5c.x * 0.25f;
                        e2->v5c.y = e2->v5c.y * 0.25f;
                        e2->v5c.z = e2->v5c.z * 0.25f;
                        if (f218 > 0.0f) {
                            f218 = f218 * 0.25f;
                            v200.x = v200.x * 0.25f;
                            v200.y = v200.y * 0.25f;
                            v200.z = v200.z * 0.25f;
                            v20c.x = v20c.x * 0.25f;
                            v20c.y = v20c.y * 0.25f;
                            v20c.z = v20c.z * 0.25f;
                        }
                    }
                }
            }
        }
    }

    if (F.v10c.y < F.f140) {
        if (pa0 && pa0->p10) {
            if (!pec->FUN_001d4e40()) {
                Ctl_1d8fc0 *c3 = GetEntity()->p70;
                if (c3) {
                    c3->v6(0);
                    c3->p10->v8(&c3->v98, &F.v0f8, -1);
                    if (F.v0f8.y < -10.0f) {
                        F.v0f8.y = -10.0f;
                        c3->FUN_002f5a20(&F.v0f8);
                    }
                }
            }
        }
    }

    const Vec3_1d8fc0 *pf = GetPos();
    v158.x = pf->x;
    v158.y = pf->y;
    v158.z = pf->z;
    if (f268 > 0.5f) {
        f264 = 0.0f;
        f260 = 0.0f;
        f25c = 0.0f;
        f268 = 0.0f;
    }
    f268 = dt + f268;
}
} // namespace fn_001d8fc0
#undef DAT_004dd700


// 0x001da350 FUN_001da350 (490 B): equivalent/0x001da350.cpp [wrapped: conflict: World]
// sym: ?FUN_001da350@Entity@fn_001da350@@QAEDPAVRefCounted_1da350@2@PAURaw3_1da350@2@1I0IIIIII0I@Z @8ddc4c546240 @w7bb8ccdc3c1d
namespace fn_001da350 {
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 32/32)
// FUN_001da350 @ 0x001da350
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

class RefCounted_1da350 {
public:
    virtual void addRef();
    virtual void release();
};

struct Raw3_1da350 {
    unsigned a, b, c;
};

struct Xform_1da350 {
    char pad[0x30];
    Raw3_1da350 pos;
};

class PosSource_1da350 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Raw3_1da350 *getPos();
};

struct Inner70 {
    void FUN_002f5a20(Raw3_1da350 *p);
};

struct Mid10_1da350 {
    char pad[0x70];
    Inner70 *p70;
};

struct HolderA0 {
    char pad[0x10];
    Mid10_1da350 *p10;
};

struct Reg124_1da350 {
    char pad[0x12c];
    RefCounted_1da350 *key;
};

struct Reg20_1da350 {
    char pad[0x124];
    Reg124_1da350 *p124;
    void FUN_00029b50(unsigned a, hulk_uintptr b, unsigned c);
};

struct World {
    char pad[0x20];
    Reg20_1da350 *p20;
};


struct Sub240_1da350 {
    char pad[8];
    void FUN_0027af70(unsigned a);
};

struct Ready_1da350 {
    char FUN_001d4ef0();
};

class Entity {
public:
    char pad00[0xa0];
    HolderA0 *holder;        // 0xa0
    char pada4[0xec - 0xa4];
    Ready_1da350 *ready;            // 0xec
    char padf0[0x114 - 0xf0];
    int f114;
    char pad118[4];
    PosSource_1da350 *posSource;    // 0x11c
    char pad120[0x188 - 0x120];
    Raw3_1da350 pos;                // 0x188
    char pad194[0x1fc - 0x194];
    RefCounted_1da350 *rc1fc;
    Raw3_1da350 v200;
    Raw3_1da350 v20c;
    unsigned f218;
    RefCounted_1da350 *rc21c;
    Raw3_1da350 v220;
    Raw3_1da350 v22c;
    RefCounted_1da350 *rc238;
    char pad23c[4];
    Sub240_1da350 sub240;
    unsigned f248;

    void FUN_001d7ee0(int a);
    void FUN_001d6e10(RefCounted_1da350 *a);
    void FUN_001d7510();
    void FUN_001d8d90(int a);

    char FUN_001da350(RefCounted_1da350 *a1, Raw3_1da350 *a2, Raw3_1da350 *a3, unsigned a4, RefCounted_1da350 *a5,
                      unsigned a6, unsigned a7, unsigned a8, unsigned a9, unsigned a10,
                      unsigned a11, RefCounted_1da350 *a12, unsigned a13);
};

char Entity::FUN_001da350(RefCounted_1da350 *a1, Raw3_1da350 *a2, Raw3_1da350 *a3, unsigned a4, RefCounted_1da350 *a5,
                          unsigned a6, unsigned a7, unsigned a8, unsigned a9, unsigned a10,
                          unsigned a11, RefCounted_1da350 *a12, unsigned a13)
{
    char ok = ready->FUN_001d4ef0();
    if (!ok)
        return ok;

    if (f114 != 0)
        FUN_001d7ee0(0);
    FUN_001d6e10(a1);
    FUN_001d7510();

    Raw3_1da350 *p;
    if (holder != 0)
        p = &((Xform_1da350 *)((owners::C_2fc6f0 *)holder)->FUN_002fc6f0())->pos;
    else
        p = posSource->getPos();
    pos = *p;

    Mid10_1da350 *mid = holder ? holder->p10 : 0;
    Inner70 *in70 = mid->p70;
    if (in70 != 0)
        in70->FUN_002f5a20(a2);
    FUN_001d8d90(1);

    if (a1 != 0)
        a1->addRef();
    if (rc1fc != 0)
        rc1fc->release();
    rc1fc = a1;
    v200 = *a2;
    v20c = *a3;
    f218 = a4;
    if (a5 != 0)
        a5->addRef();
    if (rc21c != 0)
        rc21c->release();
    rc21c = a5;
    v220.a = a6;
    v220.b = a7;
    v220.c = a8;
    v22c.a = a9;
    v22c.b = a10;
    v22c.c = a11;
    if (a12 != 0)
        a12->addRef();
    if (rc238 != 0)
        rc238->release();
    rc238 = a12;
    sub240.FUN_0027af70(a13);
    f248 = 0;

    if (rc21c != 0 && DAT_004dd700 != 0) {
        Reg20_1da350 *r20 = DAT_004dd700->p20;
        if (r20 != 0) {
            Reg124_1da350 *r = r20->p124;
            if (r != 0 && r->key == a1)
                r20->FUN_00029b50(((unsigned)((owners::C_1d72e0 *)this)->FUN_001d72e0()), (hulk_uintptr)rc21c, f218);
        }
    }
    return 1;
}
} // namespace fn_001da350
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001da540 FUN_001da540 (2961 B): equivalent/0x001da540.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_001da540@Entity@fn_001da540@@QAEHPAURef_1da540@2@PAUV3_1da540@2@1M@Z @be9ff124b40f @w123957620070
namespace fn_001da540 {
// STATUS: equivalent (tools/equiv.py level 3: 20147 inputs, branch coverage 155/162, incomplete)
// FUN_001da540 @ 0x001da540
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

extern "C" int __cdecl FUN_0034483c();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sqrt(double);
#endif


static float AbsF(float v)
{
    union { float f; unsigned int u; } c;
    c.f = v;
    c.u &= 0x7fffffff;
    return c.f;
}

struct V3_1da540 {
    float x, y, z;
    hulk_freg FUN_0022d110();
    hulk_freg FUN_00018990();
};

struct RefObj_1da540 {
    virtual void AddRef();
    virtual void Release();
};


struct Entity;
struct Actor_1da540;

struct Ref_1da540 : RefObj_1da540 {
    int pad4;
    union {
        Entity *ent;
        Actor_1da540 *act;
    };
    int type;
    char pad10[0x70 - 0x10];
    int f70;
};

struct Sub_1da540 : RefObj_1da540 {
    char pad[0x68];
    int f6c;
};

struct Request {
    hulk_intptr r00;
    int r04;
    V3_1da540 target;                 // 0x08
    char pad14[4];
    V3_1da540 aim;                    // 0x18
    char pad24[4];
    V3_1da540 dir;                    // 0x28
    char pad34[4];
    V3_1da540 vel;                    // 0x38
    char pad44[0x4c - 0x44];
    RefObj_1da540 *f4c;
    RefObj_1da540 *f50;
    float f54;
    char pad58[0x60 - 0x58];
    RefObj_1da540 *f60;
    char pad64[0x78 - 0x64];
    float f78;
    float f7c;
    float f80;
    char pad84[0xb0 - 0x84];
    void FUN_00059820();
    void FUN_00059300();
};

struct CFightParamsCollision_1da540 : RefObj_1da540 {
    CFightParamsCollision_1da540 *FUN_000598e0(void *a, Request *req);
    void FUN_00059790(Sub_1da540 *s);
};

struct Handle_1da540 {
    char FUN_00231ad0(void *sink, CFightParamsCollision_1da540 *job, int n);
};

struct Queue_1da540 {
    virtual void q0(); virtual void q1(); virtual void q2(); virtual void q3();
    virtual void q4(); virtual void q5(); virtual void q6(); virtual void q7();
    virtual Handle_1da540 *Submit(CFightParamsCollision_1da540 *job, int n);
};

struct Ctrl_1da540 {
    char pad0[0x14];
    int f14;
};

struct Hit_1da540 {
    char pad0[0x40];
    V3_1da540 f40;
};

struct Owner3 {
    void *a;
    Ref_1da540 *b;
    int c;
};

struct Pusher_1da540 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(V3_1da540 *pos, V3_1da540 *out, int n);
};

struct Obj70_1da540 {
    char pad0[0x10];
    Pusher_1da540 *f10;
    char pad14[0x98 - 0x14];
    V3_1da540 v98;
};

struct Mid10_1da540 {
    char pad0[0x70];
    Obj70_1da540 *f70;
};

struct Holder_1da540 {
    char pad0[0x10];
    Mid10_1da540 *f10;
};

struct Actor_1da540 {
    char pad0[0x10];
    void **f10;
    char pad14[0xdc - 0x14];
    int fdc;
    char pade0[0x11c - 0xe0];
    Ctrl_1da540 *f11c;
    char pad120[0x12c - 0x120];
    RefObj_1da540 *f12c;
    char pad130[0x3a4 - 0x130];
    int f3a4;
    char FUN_000360f0();
    void FUN_0003a9d0(Sub_1da540 *s);
    void FUN_000350c0(V3_1da540 *out);
    void FUN_00043ae0(Ref_1da540 *a1, V3_1da540 *a2, float a3, float a4, float a5, int a6, int a7, int a8, Sub_1da540 *a9);
    Hit_1da540 *FUN_00039c60(V3_1da540 *pos, V3_1da540 *dir, float a3, float a4, int a5, Owner3 *o, int a7);
};

struct Ready_1da540 {
    int FUN_001d5e80(int v);
    unsigned __int64 FUN_001d4f70();
};

struct Mover_1da540 {
    void FUN_00083320(V3_1da540 *a, V3_1da540 *b, float c, char airborne, V3_1da540 *e, char forced);
};

struct Ray_1da540 {
    char FUN_00201e00(V3_1da540 *a, V3_1da540 *b, int c, V3_1da540 *d, V3_1da540 *e, int f, int g);
};

struct Sink30 {
    void FUN_001cbd10(const char *s);
};

struct Fx34_1da540;

struct Reqs {
};

struct World {
    char pad0[0x24];
    Ray_1da540 *p24;
    char pad28[0x30 - 0x28];
    Sink30 *p30;
    Fx34_1da540 *p34;
    char pad38[0x4c - 0x38];
    Reqs *p4c;
};

struct Sub1a4_1da540 {
    char FUN_001b6e90(Ref_1da540 *a);
};

struct Sub240_1da540 {
    char pad[8];
};

class Entity;

struct Fx34_1da540 {
    void FUN_001ebd80(Entity *e, const char *name, float v, int z);
};

extern "C" int __cdecl FUN_00266da0(hulk_intptr mode);
extern "C" void *__cdecl FUN_0008d690(unsigned int size);
void __cdecl FUN_00018810(RefObj_1da540 **slot, RefObj_1da540 *obj);
void __cdecl FUN_00224d70(float ang, V3_1da540 *v);
extern "C" void __cdecl FUN_00096b50(Ref_1da540 *a1, V3_1da540 *out, int *count);
extern "C" int __cdecl FUN_00097a30(float a1, float a2, float a3, void *a4, float a5, V3_1da540 *a6, float a7, V3_1da540 *a8, int a9, int a10, int a11, int a12);

class Entity {
public:
    char pad000[0x40];
    int f40;
    char pad44[0xa0 - 0x44];
    Holder_1da540 *f0a0;
    char pad0a4[0xb0 - 0xa4];
    char b0b0;
    char pad0b1[0xec - 0xb1];
    Ready_1da540 *ready;
    char pad0f0[0x110 - 0xf0];
    char b110;
    char pad111[3];
    Ref_1da540 *f114;
    Ref_1da540 *f118;
    char pad11c[0x148 - 0x11c];
    Actor_1da540 *f148;
    char pad14c[1];
    char b14d;
    char pad14e[0x1a4 - 0x14e];
    Sub1a4_1da540 s1a4;
    char pad1a5[0x1c9 - 0x1a5];
    char b1c9;
    char pad1ca[0x1fc - 0x1ca];
    Ref_1da540 *f1fc;
    V3_1da540 v200;
    V3_1da540 v20c;
    float f218;
    Ref_1da540 *f21c;
    float f220;
    int f224;
    float f228;
    float f22c;
    float f230;
    float f234;
    Queue_1da540 *p238;
    char pad23c[4];
    Sub240_1da540 s240;
    int f248;

    void FUN_001d82d0();
    void FUN_001d6ec0(int a, Ref_1da540 *b, int c);
    int FUN_001d73f0();
    char FUN_001d7300();
    void FUN_001d86d0(V3_1da540 *v, V3_1da540 *w);
    void FUN_001d66b0(V3_1da540 *a, V3_1da540 *b);
    void FUN_001d8100();
    void FUN_001d8c70(Hit_1da540 *h);
    void FUN_001d8cd0();
    void FUN_001d8d90(int a);
    void FUN_001d71e0(int a);
    char FUN_001da350(Ref_1da540 *a1, V3_1da540 *a2, V3_1da540 *a3, float a4, void *a5, float a6, int a7, float a8, float a9,
                      float a10, float a11, Queue_1da540 *a12, Sub240_1da540 *a13);
    int FUN_001da540(Ref_1da540 *a1, V3_1da540 *a2, V3_1da540 *a3, float a4);
};

struct Frame_1da540 {
    char pad0[2];
    char b12;
    char b13;
    union { Actor_1da540 *p14; float F; } u14;
    V3_1da540 v;
    char pad14[3];
    char flagA;
    union { int saved; int cntOut; float flagF; } u18;
    char pad1c[3];
    char flagB;
    V3_1da540 v2;
    V3_1da540 w;
    V3_1da540 pos;
    Sub1a4_1da540 *volatile sp;
    Owner3 own;
    union {
        Request req;
        struct { char pad[0x98]; V3_1da540 t0; V3_1da540 t1; } t;
    } rq;
    V3_1da540 t2;
};

int Entity::FUN_001da540(Ref_1da540 *a1, V3_1da540 *a2, V3_1da540 *a3, float a4)
{
    Frame_1da540 f;
    if (s1a4.FUN_001b6e90(a1))
        return 1;

    f.b12 = 0;
    f.b13 = 1;
    f.u14.p14 = 0;

    if (a1 != 0) {
        Ref_1da540 *r = f21c;
        if (r && r->type == 5 && a1->type == 1) {
            Ref_1da540 *k = (Ref_1da540 *)r->ent->f114;
            if (k) {
                Actor_1da540 *aa = a1->act;
                if (aa && (Ref_1da540 *)aa->f12c == k)
                    a1 = r;
            }
        }

        Actor_1da540 *tgt = 0;
        if (a1->type == 5) {
            Entity *o = a1->ent;
            if (o) {
                f.u14.p14 = o->f148;
                if (f.u14.p14) {
                    tgt = f.u14.p14;
                } else {
                    if (o->f114 == f1fc)
                        return 1;
                    if (o->b1c9 && o->f1fc == f1fc)
                        return 1;
                    o->FUN_001d82d0();
                    if (f230 > 0.0f)
                        o->FUN_001d6ec0((int)(__int64)f230, f1fc, 0);
                    int lvl = o->FUN_001d73f0();
                    if (lvl <= -10)
                        f.b13 = 0;
                    if (!o->b0b0 && (a1->f70 != 0 || (b110 && lvl <= -10))) {
                        f.b12 = 0;
                    } else {
                        f.b12 = 1;
                        f.b13 = 1;
                    }
                    if (o->b14d && ((Sub_1da540 *)((owners::C_1d72e0 *)o)->FUN_001d72e0())->f6c == 0) {
                        Mover_1da540 *m = ((Mover_1da540 *)((owners::Obj_7ad00 *)(DAT_004dd700->p4c))->FUN_0007ad00((hulk_intptr)((char *)o + 8)));
                        if (m) {
                            f.v = v200;
                            f.v.FUN_0022d110();
                            f.v.x = f.v.x * f22c;
                            f.v.y = f.v.y * f22c;
                            f.v.z = f.v.z * f22c;
                            m->FUN_00083320(a2, a3, a4, 1, &f.v, 0);
                        }
                    } else if (f22c > 0.0f && o->FUN_001d7300() && o->f114 == 0) {
                        f.v = v200;
                        f.v.FUN_0022d110();
                        f.v.x = f.v.x * f22c;
                        f.v.y = f.v.y * f22c;
                        f.v.z = f.v.z * f22c;
                        o->FUN_001d86d0(&f.v, a2);
                        if (o->ready->FUN_001d4f70() == (*(unsigned __int64*)&DAT_004e2548))
                            DAT_004dd700->p30->FUN_001cbd10("golf_stroke");
                    }
                }
            }
        } else if (a1->type == 1) {
            f.u14.p14 = a1->act;
            tgt = f.u14.p14;
        }

        if (tgt) {
            f.u18.saved = FUN_00266da0(0xd);
            int mode = tgt->f11c->f14;
            f.b12 = (mode == 3 || mode == 2);
            f.b13 = (mode != 0);
            if (!tgt->FUN_000360f0()) {
                Handle_1da540 *slot = 0;
                if (p238) {
                    if (tgt->f3a4 == 0)
                        tgt->FUN_0003a9d0(((Sub_1da540 *)((owners::C_1d72e0 *)this)->FUN_001d72e0()));
                    f.rq.req.FUN_00059820();
                    f.rq.req.target = *a2;
                    f.rq.req.aim = *a3;
                    f.rq.req.dir = v200;
                    f.rq.req.f54 = f234;
                    f.rq.req.f7c = f228;
                    f.rq.req.f78 = f230;
                    f.rq.req.vel = v200;
                    f.rq.req.f80 = 1.0f;
                    f.rq.req.vel.FUN_0022d110();
                    f.rq.req.vel.x = f.rq.req.vel.x * f22c;
                    f.rq.req.vel.y = f.rq.req.vel.y * f22c;
                    f.rq.req.vel.z = f.rq.req.vel.z * f22c;
                    FUN_00018810(&f.rq.req.f60, ((Sub_1da540 *)((owners::C_1d72e0 *)this)->FUN_001d72e0()));
                    if (f1fc)
                        FUN_00018810(&f.rq.req.f4c, f1fc);
                    FUN_00018810(&f.rq.req.f50, tgt->f12c);
                    CFightParamsCollision_1da540 *job = (CFightParamsCollision_1da540 *)FUN_0008d690(0xb0);
                    if (job)
                        job = job->FUN_000598e0(*tgt->f10, &f.rq.req);
                    job->AddRef();
                    job->FUN_00059790(((Sub_1da540 *)((owners::C_1d72e0 *)this)->FUN_001d72e0()));
                    slot = p238->Submit(job, 0);
                    if (slot)
                        slot->FUN_00231ad0(&tgt->fdc, job, -1);
                    job->Release();
                    f.rq.req.FUN_00059300();
                }
                if (!slot) {
                    if (f1fc != a1 && f118 != a1) {
                        f.w.x = 0.0f;
                        f.w.y = 0.0f;
                        f.w.z = 0.0f;
                        tgt->FUN_000350c0(&f.w);
                        ((owners::Vec3_11160 *)&(f.w))->FUN_00011160(-1.0f, (const owners::Vec3_11160 *)(V3_1da540 *)(&v200));
                        tgt->FUN_00043ae0(f1fc, &f.w, f22c + 90.0f, f234, f230, 0, 0, 1, ((Sub_1da540 *)((owners::C_1d72e0 *)this)->FUN_001d72e0()));
                    }
                }
            }
            FUN_00266da0(f.u18.saved);
        }
    }

    FUN_001d66b0(a2, a3);
    DAT_004dd700->p34->FUN_001ebd80(this, "impact_big", 100.0f, 0);
    f.sp = &s1a4;
    ((owners::Thing_1b6e60 *)(f.sp))->FUN_001b6e60((hulk_intptr)(Ref_1da540 *)a1);
    int kind = ((owners::C_1d4de0 *)ready)->FUN_001d4de0();
    int k = ready->FUN_001d5e80(f40);
    char bl = (kind == 5);
    f.flagA = (k == 3);
    f.flagB = (k == 2);
    if (f.flagA && a1 == f21c) {
        FUN_001d8100();
        if (f21c) {
            f21c->Release();
            f21c = 0;
        }
    }

    if (f228 < 0.8f || !bl) {
        int k2 = ready->FUN_001d5e80(f40);
        float m = 1.0f;
        if (k2 == 3)
            m = 0.01f;
        if (k2 == 2)
            m = m * 0.025f;
        bl = f.b13;
        m = m * f230;
        if (!bl) {
            if (f.u14.p14)
                m = m * 0.25f;
            else
                m = m * 0.1f;
        }
        int n = (int)(__int64)m;
        if (n > 0)
            FUN_001d6ec0(n, f1fc, 0);
    } else {
        bl = f.b13;
    }

    Actor_1da540 *victim = 0;
    if (f1fc && f1fc->type == 1)
        victim = f1fc->act;
    int cnt = f224;
    if (cnt > 0 && victim) {
        if (bl || f.u14.p14 || f.b12) {
            f224 = cnt - 1;
            f.pos.x = 0.0f;
            f.pos.y = 0.0f;
            f.pos.z = 0.0f;
            Mid10_1da540 *m10 = f0a0 ? f0a0->f10 : 0;
            Obj70_1da540 *o70 = m10->f70;
            f.pos = o70->v98;
            f.w.x = 0.0f;
            f.w.y = 0.0f;
            f.w.z = 0.0f;
            o70->f10->v8(&o70->v98, &f.w, -1);
            f.v.x = f.w.x;
            f.v.y = f.w.y;
            f.v.z = f.w.z;
            if (AbsF(f.w.y) < 1.0f)
                f.v.y = 0.0f;
            f.v.FUN_0022d110();
            if (v20c.y < 0.0f)
                FUN_00224d70(0.78539818525314331f, &f.v);
            else
                FUN_00224d70(-0.78539818525314331f, &f.v);
            if (f224 > 0) {
                f.u18.cntOut = 0;
                FUN_00096b50(a1, &f.rq.t.t0, &f.u18.cntOut);
                int c = (f.u18.cntOut < 100) ? 0 : 100;
                f.own.a = f0a0 ? f0a0->f10 : 0;
                f.own.b = a1;
                f.own.c = 0;
                Hit_1da540 *hit = victim->FUN_00039c60(&f.pos, &f.v, 3.14159274f, 50.0f, c, &f.own, 0);
                if (hit) {
                    f.v2.x = f.v.x;
                    f.v2.y = f.v.y;
                    f.v2.z = f.v.z;
                    f.u14.F = v200.FUN_00018990();
                    if (FUN_00097a30(f.u14.F, f220, -1.0f, hit, 1.0f, &f.pos, 0, &f.v2, 0, 0, 0, 1)) {
                        if (!DAT_004dd700->p24->FUN_00201e00(&f.pos, &hit->f40, 1, &f.rq.t.t1, &f.t2, 0, 0)) {
                            FUN_001d8c70(hit);
                            f.v2.x = f.v2.x * f.u14.F;
                            f.v2.y = f.v2.y * f.u14.F;
                            f.v2.z = f.v2.z * f.u14.F;
                            FUN_001da350(f1fc, &f.v2, &v20c, 50.0f, hit, f220, f224, f228, f22c, f230,
                                         f234, p238, &s240);
                            return 1;
                        }
                    }
                }
            }
            f.v2.x = f.v.x;
            f.v2.y = f.v.y;
            f.v2.z = f.v.z;
            f.u14.F = (float)sqrt(v200.x * v200.x + v200.y * v200.y + v200.z * v200.z);
            f.u18.flagF = f.flagB ? 1.0f : 0.0f;
            FUN_00097a30(f.u14.F, f220, -1.0f, f1fc, f.u18.flagF, &f.pos, 0.52359879016876221f, &f.v2,
                         0, 0, 0, 1);
            f.v2.x = f.v2.x * f.u14.F;
            f.v2.y = f.v2.y * f.u14.F;
            f.v2.z = f.v2.z * f.u14.F;
            FUN_001da350(f1fc, &f.v2, &v20c, 100.0f, f1fc, f220 * 3.0f, 1, f228, f22c, f230, f234, p238,
                         &s240);
            FUN_001d71e0(0);
            ((owners::C_1b6de0 *)(f.sp))->FUN_001b6de0((hulk_intptr)(Ref_1da540 *)f1fc);
            return 1;
        }
    }

    if (!(f218 <= 0.0f) && f.flagA) {
        if (!f.b12)
            return 1;
        f248 = 1;
        return 0;
    }
    if (cnt > 0 && !bl && !f.b12 && !f.u14.p14)
        return 1;
    FUN_001d8cd0();
    if (bl) {
        FUN_001d8d90(0);
        FUN_001d71e0(0);
    }
    return 0;
}
} // namespace fn_001da540
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001db0e0 CSPHulkPropInstance::vfunc_2 (30 B): matches/0x001db0e0.cpp
// sym: ??_GCSPHulkPropInstance@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CSPHulkPropInstance::~CSPHulkPropInstance() {}


// 0x001db1c0 FUN_001db1c0 (39 B): matches/0x001db1c0.cpp [wrapped: conflict: CSPListener]
// sym: ??0CSPListener@fn_001db1c0@@QAE@PAX@Z
namespace fn_001db1c0 {
extern "C" char DAT_003f6308[];
extern "C" char DAT_00423114[];
extern "C" char DAT_00423124[];
// (x64t8) the words as the original lays them out: CSPListener's vftable (its first base), pure3d::NonCopyable (the
// second base: its vftable and its reference count, packed natively as gen's NonCopyable is) and the parameter. The
// vftable pointers are pointers (were stored through a 32-bit `volatile unsigned*` view, cut natively).
HULK_REFCOUNT_PACK
struct NonCopyable_1db1c0 {
    void* volatile vptr;
    volatile int refs;
};
HULK_REFCOUNT_PACK_END
class CSPListener {
  public:
    void* volatile vptr;
    NonCopyable_1db1c0 nc;
    void* volatile param;
    CSPListener(void*);
};
CSPListener::CSPListener(void* p) {
    nc.vptr = (void*)DAT_003f6308;
    nc.refs = 0;
    vptr = (void*)DAT_00423124;
    nc.vptr = (void*)DAT_00423114;
    param = p;
}
} // namespace fn_001db1c0


// 0x001db1f0 CSPListener::vfunc_2_adj4 (8 B): equivalent/0x001db1f0.cpp [wrapped: conflict: CSPListener]
// sym: ?vfunc_2_adj4@CSPListener@fn_001db1f0@@QAEXH@Z @4167a0db4318 @w3a16cd148c31
namespace fn_001db1f0 {
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 0/0)
// CSPListener::vfunc_2_adj4 @ 0x001db1f0
struct CSPListener {
    void FUN_001db200(int a);
    void vfunc_2_adj4(int a);
};
void CSPListener::vfunc_2_adj4(int a) {
    ((CSPListener*)((char*)this - sizeof(void*)))->FUN_001db200(a);   // (x64t8) the second base follows the first's vftable pointer
}
} // namespace fn_001db1f0

namespace fn_f9c60317 {

// 0x001db200 FUN_001db200 (42 B): matches/0x001db200.cpp
// sym: ?f@CSPListener_1db200@fn_f9c60317@@QAEPAU12@E@Z
CSPListener_1db200* CSPListener_1db200::f(unsigned char flags) {
    CSPListener_1db200* self = this;
    volatile void** p;
    if (self)
        p = (volatile void**)((char*)self + sizeof(void*));   // (x64t8) the second base (NonCopyable), after the first vftable pointer
    else
        p = 0;
    *p = (void*)((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        thunk(self);
    return self;
}

} // namespace fn_f9c60317
