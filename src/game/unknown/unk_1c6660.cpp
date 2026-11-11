// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c6660..0x001c6c90 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fe13ae73 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fe13ae73 {} using namespace fn_fe13ae73;
#include "game/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fe13ae73 {
struct Sub_1c6660 { char data[0xa4];  };
struct Elem_1c6660 { char flag; char pad[3]; Sub_1c6660 sub; };
struct Guard_1c6660 { char data[4]; bool FUN_001acb90(int a); };
class Pool_1c6660 {
public:
    char pad0[0x14];
    Elem_1c6660 *begin;
    Elem_1c6660 *end;
    char pad1c[0x2c - 0x1c];
    Guard_1c6660 guard;
    bool FUN_001c6660(int a);
};
struct Profiler_1c6800 {
 void FUN_0023f720(int*, const char*);
 bool FUN_0023f760(const char*, int, int);
 void FUN_0023f740();
};
struct Renderer_1c6800 {
 char pad0[0xc0];
 int option;
 void FUN_001c1330(int);
 void FUN_001c26a0(int, int, int);
};
struct Queue_1c6800 {
 char pad0[0x54c];
 int count;
 int entries[1];
};
struct Object {
  public:
    char _m_pad_0[0x8];
    unsigned char active;
    char _m_pad_9[0x3];
    int geometry;
    char _m_pad_10[0x18];
    unsigned char category;
    char _m_pad_29[0x2b];
    short index;
    char _m_pad_56[0x6];
    int data;
    void render(Renderer_1c6800*, Queue_1c6800*, int, int);
    void FUN_002a0ba0(float*,float*);
};
struct Caller_1c68c0 {
};
struct Obj_1c68c0 {
    char pad[8];
    u8 enabled;
    char pad9[7];
    int value;
    void target(Caller_1c68c0* arg);
};
class Listener_1c68e0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(float value, int arg);
};
struct Fader_1c68e0 {
    char pad00[8];
    char active;             // 0x08
    char pad09[3];
    Listener_1c68e0* listener;      // 0x0c
    char pad10[0x58 - 0x10];
    float timeLeft;          // 0x58
    void Update(float dt);
};
extern char DAT_004c5368, DAT_004c534c, DAT_004c532c;
extern Object* __cdecl FUN_00344e74(Object*,int,void*,void*,int);
struct List_1c6950 { char padding[0x10]; int capacity; int count; Object** objects; };
struct Group_1c6950 { void FUN_0029f800(Object*); };
struct Manager_1c6950 { char padding[0xc0]; Group_1c6950* normal; Group_1c6950* alternate; };
extern "C" Manager_1c6950** __cdecl FUN_001c3d90();
class C_1c6aa0 {
  public:
    char pad[0x0c];
    int value;
};
extern "C" unsigned char hulk_at_004e2388;
extern "C" unsigned int gFlagWord;
extern "C" unsigned char hulk_at_004e2370;
struct Obj_1c6ac0 {
    char pad[0x10];
    hulk_intptr value;
};
typedef unsigned int u32_1c6af0;
class Obj_1c6af0 {
  public:
    char pad[16];
    hulk_uintptr mPtr;
};
class A_1c6b50 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c6b50 {
  public:
    A_1c6b50* p;
    void run();
};
class A_1c6bd0 {
  public:
    virtual void f();
    virtual void g();
};
class B_1c6bd0 {
  public:
    A_1c6bd0* p;
    void run();
};
class Part_1c6c40 {
  public:
    void Cleanup_001c27c0();
};
class Thing_1c6c40 {
  public:
    int v;
    Part_1c6c40 part;
    Thing_1c6c40* Run(unsigned char flags);
};
void DeleteThing_0008d330(Thing_1c6c40*);


// 0x001c6660 FUN_001c6660 (153 B): equivalent/0x001c6660.cpp
// sym: ?FUN_001c6660@Pool_1c6660@fn_fe13ae73@@QAE_NH@Z
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 13/14, incomplete)
// FUN_001c6660 @ 0x001c6660
bool Pool_1c6660::FUN_001c6660(int a)
{
    hulk_uintptr n = end - begin;
    if (n == 0)
        return true;
    if (!guard.FUN_001acb90(a))
        return false;
    for (unsigned i = 0; i < n; i++) {
        Elem_1c6660 *e = &begin[i];
        if (e->flag) {
            if (((owners::C_1c27d0 *)&(e->sub))->FUN_001c27d0((float *)(hulk_uintptr)(int)a))
                return false;
        } else if (((owners::C_1c27d0 *)&(e->sub))->FUN_001c27d0((float *)(hulk_uintptr)(int)a)) {
            return true;
        }
    }
    return false;
}


// 0x001c6800 FUN_001c6800 (179 B): equivalent/0x001c6800.cpp
// sym: ?render@Object@fn_fe13ae73@@QAEXPAURenderer_1c6800@2@PAUQueue_1c6800@2@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 6/6)
// FUN_001c6800 @ 0x001c6800
void Object::render(Renderer_1c6800* renderer, Queue_1c6800* queue, int context, int argument) {
 if (!active) return;
 queue->entries[queue->count] = index;
 ++queue->count;
 (*(Profiler_1c6800**)&DAT_004dd6e8)->FUN_0023f720(&DAT_004c5328, "Rendering");
 bool enabled = (*(Profiler_1c6800**)&DAT_004dd6e8)->FUN_0023f760("Light Room Geo", 0x6c, 0);
 renderer->FUN_001c1330(enabled ? renderer->option : 0);
 (*(Profiler_1c6800**)&DAT_004dd6e8)->FUN_0023f740();
 if (geometry) {
  (*(hulk_intptr*)&DAT_004e2350) = context;
  renderer->FUN_001c26a0(geometry, argument, data);
  (*(hulk_intptr*)&DAT_004e2350) = 0;
 }
}


// 0x001c68c0 FUN_001c68c0 (27 B): matches/0x001c68c0.cpp
// sym: ?target@Obj_1c68c0@fn_fe13ae73@@QAEXPAUCaller_1c68c0@2@@Z
void Obj_1c68c0::target(Caller_1c68c0* arg) {
    if (enabled && value)
        ((owners::Target_1c16a0 *)arg)->FUN_001c16a0((void *)(hulk_uintptr)(int)value);
}


// 0x001c68e0 FUN_001c68e0 (106 B): matches/0x001c68e0.cpp
// sym: ?Update@Fader_1c68e0@fn_fe13ae73@@QAEXM@Z
// FUN_001c68e0 @ 0x001c68e0
void Fader_1c68e0::Update(float dt)
{
    if (active == 0)
        return;
    if (timeLeft > 0.0f) {
        if (DAT_004c5314 <= 0.01f) {
            timeLeft = 0.0f;
        } else {
            timeLeft = timeLeft - dt / DAT_004c5314;
            if (timeLeft < 0.0f)
                timeLeft = 0.0f;
        }
    }
    if (listener != 0)
        listener->v6(dt * 1000.0f, 0);
}


// 0x001c6950 FUN_001c6950 (327 B): equivalent/0x001c6950.cpp
// sym: ?FUN_001c6950@fn_fe13ae73@@YGXPAUList_1c6950@1@@Z
// STATUS: equivalent (tools/equiv.py level 3: 79 inputs, branch coverage 28/28)
// FUN_001c6950 @ 0x001c6950
void __stdcall FUN_001c6950(List_1c6950* list) {
 unsigned int flags=(*(unsigned int*)&DAT_004e236c);
 if (!(flags&1)) { flags|=1; (*(unsigned int*)&DAT_004e236c)=flags; DAT_004e2360=0.0f; (*(float*)&DAT_004e2364)=0.0f; (*(float*)&DAT_004e2368)=0.0f; }
 if (!(flags&2)) { flags|=2; (*(unsigned int*)&DAT_004e236c)=flags; DAT_004e2354=25.0f; (*(float*)&DAT_004e2358)=0.0f; (*(float*)&DAT_004e235c)=0.0f; }
 if (!list) return;
 for(int i=0;i<list->count;++i) {
  if(i<list->capacity) {
   Object* object=list->objects[i];
   if(object && ((int)((owners::C_2a0850 *)object)->FUN_002a0850())==0) {
    Object* first=FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c5368,0);
    Object* second=FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c532c,0);
    Object* selected=first?first:second;
    if(selected) { ((owners::Obj_2a0840 *)selected)->FUN_002a0840(1); selected->FUN_002a0ba0(&DAT_004e2360,&DAT_004e2354); }
   }
  }
 }
 for(int j=0;j<list->count;++j) {
  Object* object=j<list->capacity?list->objects[j]:0;
  Group_1c6950* group;
  if(object->category) group=(*FUN_001c3d90())->alternate;
  else group=(*FUN_001c3d90())->normal;
  group->FUN_0029f800(object);
 }
}


// 0x001c6aa0 FUN_001c6aa0 (7 B): matches/0x001c6aa0.cpp
// sym: ?target@fn_fe13ae73@@YIHPAVC_1c6aa0@1@@Z
hulk_intptr __fastcall target(C_1c6aa0* self) {
    return self->value + 0x14;
}


// 0x001c6ab0 FUN_001c6ab0 (7 B): matches/0x001c6ab0.cpp
// sym: ?FUN_001c6ab0@fn_fe13ae73@@YIHH@Z
hulk_intptr __fastcall FUN_001c6ab0(hulk_intptr p) {
    return *(int*)(p + 0xc) + 0x2c;
}


// 0x001c6ac0 FUN_001c6ac0 (38 B): matches/0x001c6ac0.cpp
// sym: @FUN_001c6ac0@8
extern "C" void* __fastcall FUN_001c6ac0(Obj_1c6ac0* self, void*) {
    if (self->value)
        return (void*)(self->value + 0x14);
    unsigned char c = hulk_at_004e2388;
    unsigned int one = 1;
    if ((one & c) == 0)
        gFlagWord |= one;
    return &hulk_at_004e2370;
}


// 0x001c6af0 FUN_001c6af0 (38 B): matches/0x001c6af0.cpp
// sym: ?target@fn_fe13ae73@@YIPADPAVObj_1c6af0@1@@Z
// data: g_buffer = DAT_004e238c, g_flag_1c6af0 = DAT_004e239c
char* __fastcall target(Obj_1c6af0* self) {
    if (self->mPtr)
        return (char*)(self->mPtr + 0x2c);
    if ((((u8*)&(*(u32_1c6af0*)&DAT_004e239c))[0] & 1) == 0)
        (*(u32_1c6af0*)&DAT_004e239c) |= 1;
    return ((char*)&DAT_004e238c);
}


// 0x001c6b50 FUN_001c6b50 (22 B): matches/0x001c6b50.cpp
// sym: ?run@B_1c6b50@fn_fe13ae73@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c6b50::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c6bd0 FUN_001c6bd0 (22 B): matches/0x001c6bd0.cpp
// sym: ?run@B_1c6bd0@fn_fe13ae73@@QAEXXZ
// Same code shape as 0x001c3d20 (propagated; names are from that function)
void B_1c6bd0::run() {
    if (p)
        p->g();
    p = 0;
}


// 0x001c6c40 FUN_001c6c40 (33 B): matches/0x001c6c40.cpp
// sym: ?Run@Thing_1c6c40@fn_fe13ae73@@QAEPAV12@E@Z
Thing_1c6c40* Thing_1c6c40::Run(unsigned char flags) {
    part.Cleanup_001c27c0();
    if (flags & 1)
        DeleteThing_0008d330(this);
    return this;
}

} // namespace fn_fe13ae73
