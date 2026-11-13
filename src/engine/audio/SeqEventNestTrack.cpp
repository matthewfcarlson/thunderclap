// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0024e520..0x0024e920 (kind game, layer engine, confidence high), dominant class audio::SeqEventNestTrack
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "gen/audio.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f724be52 {
#define TREE_TU_END }
namespace fn_f724be52 {} using namespace fn_f724be52;
#include "engine/audio.h"

// ---- declarations shared by the functions below
namespace fn_f724be52 {
struct Inner_24e550 {
};
class SeqEvent_24e550 {
  public:
    SeqEvent_24e550();
    virtual void g();
};
class SeqEventNestTrack_24e550 : public SeqEvent_24e550 {
  public:
    SeqEventNestTrack_24e550();
    virtual void g();
    char pad[4];
    Inner_24e550 in;
};
class pddiObject_24e580 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_24e580 : public pddiObject_24e580 {};
class pddiBaseShader_24e580 : public pddiShader_24e580 {
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
class d3dShader_24e580 : public pddiBaseShader_24e580 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
} // namespace fn_f724be52
namespace audio {
class SeqEventNestTrack_24e590 : public ::audio::SeqEvent {
  public:
    virtual int vfunc_0(void*);
    char pad[4];
};
}
namespace fn_f724be52 {
extern "C" bool __cdecl FUN_0025bce0(void*, void*);
typedef void* X_24e5e0;
X_24e5e0 __cdecl WrapThing_002673a0(X_24e5e0, int);
extern "C" X_24e5e0 __fastcall FUN_0023fb00(void*);
struct Obj_24e5e0 {
    X_24e5e0 value;
    X_24e5e0 Run(void*);
};
extern "C" unsigned char __cdecl Check1(int, hulk_intptr, ...);
extern "C" unsigned char __cdecl Validate1_0025bcb0(hulk_intptr, int);
extern "C" unsigned char __cdecl Final1_00246f50(hulk_intptr, hulk_intptr, ...);
extern int hulk_at_00422518;
extern void FUN_00247530(void*);
typedef unsigned int u32_24e6f0;
extern void* __cdecl Acquire_00247530(void*);
extern int hulk_at_00429884;
class NameObj_24e6f0 {
  public:
};
class NestTrack_24e6f0 {
  public:
    hulk_uintptr vf;
    char pad[4];
    NameObj_24e6f0 name;
    void init_0025fd00();
};
class SeqEventNestTrack_24e730 {
  public:
    void Fnb_0025fd10();
};
struct Stm_24e760 {
    char pad[0x24];
    int depth;
};
class SeqEvent {
  public:
    virtual void _m_vf0();
    virtual bool v1(Stm_24e760**);
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual SeqEvent* f4(unsigned int);
    virtual void _m_vf5();
};
extern bool Match_00246f50(Stm_24e760*, const char*, ...);
extern bool ReadTrack_0024e600(Stm_24e760**, const char*, void*);
struct Key {
    char data[12];
    Key() throw();
    ~Key() throw();
    unsigned int FUN_0023fb00() throw();
};
struct Event_24e870;
struct Handler_24e870 {
    virtual void v0();
    virtual void v1();
    virtual void v2(Event_24e870 *e);
};
struct Node {
    Node *left;
    Node *right;
    char pad08[0x10];
    Handler_24e870 handler;
    char pad1c[0x34 - 0x1c];
    unsigned int key;
};
struct Index_24e870 {
    char pad00[0x28];
    Node *root;
    char nil[1];
};
struct Context {
    char pad00[0x5c];
    char tree[1];
};
struct Event_24e870 {
    char pad00[0x3c];
    Context *ctx;
};
class SeqEventNestTrack : public SeqEvent {
  public:
    virtual SeqEventNestTrack* f4(unsigned int);
    char _m_pad_4[0x4];
    char name[1];
    char _m_pad_9[0x3];
    int vfunc_1(Stm_24e760**);
    void FUN_0024e870(Event_24e870 *e) throw();
};
extern "C" void FUN_00247550(void*, SeqEventNestTrack*);
extern "C" void __cdecl FUN_002613b0(void *tree, Key *key, void *name) throw();
extern "C" Index_24e870 *__cdecl FUN_00247810(Context *c) throw();
unsigned int __cdecl FUN_002673a0(unsigned int v, int flags) throw();

// 0x0024e520 audio::SeqEventNestTrackType::vfunc_0 (5 B): not yet verified
// 0x0024e530 audio::SeqEventNestTrackType::vfunc_1 (5 B): not yet verified

// 0x0024e540 FUN_0024e540 (6 B): matches/0x0024e540.cpp
// sym: _FUN_0024e540
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024e540() {
    return &(*(int*)&DAT_004e6698);
}


// 0x0024e550 FUN_0024e550 (33 B): matches/0x0024e550.cpp
// sym: ??0SeqEventNestTrack_24e550@fn_f724be52@@QAE@XZ
SeqEventNestTrack_24e550::SeqEventNestTrack_24e550() {
    ((owners::String_23fc40 *)&in)->FUN_0023fc40("MySeqTrack", (hulk_intptr)2);
}

} // namespace fn_f724be52

// 0x0024e580 audio::SeqEvent::vfunc_5 (6 B): matches/0x0024e580.cpp
// sym: ?vfunc_5@SeqEvent@audio@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int audio::SeqEvent::vfunc_5() {
    return 1;
}


// 0x0024e590 audio::SeqEventNestTrack::vfunc_0 (52 B): matches/0x0024e590.cpp
// sym: ?vfunc_0@SeqEventNestTrack_24e590@audio@@UAEHPAX@Z
int audio::SeqEventNestTrack_24e590::vfunc_0(void* param) {
    if ((unsigned char)::audio::SeqEvent::vfunc_0(param)) {
        if (FUN_0025bce0(param, (char*)this + 8))
            return 1;
    }
    return 0;
}

namespace fn_f724be52 {

// 0x0024e5d0 audio::SeqEventNestTrack::vfunc_3 (6 B): matches/0x0024e5d0.cpp
// sym: _FUN_0024e5d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_0024e5d0() {
    return &(*(int*)&DAT_004e6698);
}


// 0x0024e5e0 FUN_0024e5e0 (31 B): matches/0x0024e5e0.cpp
// sym: ?Run@Obj_24e5e0@fn_f724be52@@QAEPAXPAX@Z
X_24e5e0 Obj_24e5e0::Run(void* arg) {
    X_24e5e0 temp = FUN_0023fb00(arg);
    value = WrapThing_002673a0(temp, 0);
    return this;
}


// 0x0024e600 FUN_0024e600 (70 B): matches/0x0024e600.cpp
// sym: ?Target@fn_f724be52@@YAEPAHHH@Z
unsigned char Target(int* p, int a, int b) {
    int v = *p;
    unsigned char r = Check1(v, ((hulk_intptr)((char*)&DAT_004298a8)), a);
    if (r) {
        r = Validate1_0025bcb0((hulk_intptr)p, b);
        if (r) {
            p = (int*)*(hulk_intptr*)p;
            return Final1_00246f50((hulk_intptr)p, (hulk_intptr)&hulk_at_00422518);
        }
    }
    return 0;
}


// 0x0024e660 FUN_0024e660 (13 B): matches/0x0024e660.cpp
// sym: ?FUN_0024e660@fn_f724be52@@YAXPAX@Z
// data: hulk_at_004e6698 = DAT_004e6698
void FUN_0024e660(void* x) {
    x = (void*)((hulk_intptr)DAT_004e6698);
    FUN_00247530(x);
}

} // namespace fn_f724be52

// 0x0024e670 FUN_0024e670 (86 B): matches/0x0024e670.cpp [wrapped: conflict: audio::SeqEventNestTrackType]
// sym: ?FUN_0024e670@SeqEventNestTrackType@audio@fn_0024e670@@QAEPAU123@XZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0024e670 {
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

struct Field {
    char space[12];
    Field* FUN_0023fc40(const char*, int);
    void FUN_00240060();
};
namespace audio {
struct SeqEventNestTrackType {
    void** vtable;
    void FUN_002605e0(Field*, __int64*, int, int);
    SeqEventNestTrackType* FUN_0024e670();
};
} // namespace audio
extern void* DAT_004298b0[];
audio::SeqEventNestTrackType* audio::SeqEventNestTrackType::FUN_0024e670() {
    HULK_SIZE32(AudioSeqEventNestTrack, 0x14);
    __int64 id = FUN_002672f0("SeqEventNestTrack", 0, 0);
    Field field;
    FUN_002605e0(field.FUN_0023fc40("Nest", 0), &id, (int)sizeof(AudioSeqEventNestTrack), (int)__alignof(AudioSeqEventNestTrack));
    field.FUN_00240060();
    vtable = DAT_004298b0;
    return this;
}
} // namespace fn_0024e670
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0024e6d0 audio::SeqEventNestTrackType::vfunc_2 (30 B): matches/0x0024e6d0.cpp
// sym: ??_GSeqEventNestTrackType@audio@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
audio::SeqEventNestTrackType::~SeqEventNestTrackType() {}


// 0x0024e6f0 audio::SeqEventNestTrackType::vfunc_3 (56 B): matches/0x0024e6f0.cpp
// sym: ?vfunc_3@SeqEventNestTrackType@audio@@UAEPAXXZ
// data: gName_24e6f0 = DAT_0042989c, gPool_24e6f0 = DAT_004e6698
void* audio::SeqEventNestTrackType::vfunc_3() {
    NestTrack_24e6f0* p = (NestTrack_24e6f0*)Acquire_00247530(((char*)&DAT_004e6698));
    if (p) {
        p->init_0025fd00();
        p->vf = (hulk_uintptr)&hulk_at_00429884;
        ((owners::String_23fc40 *)&(p->name))->FUN_0023fc40(DAT_0042989c, (hulk_intptr)2);
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_f724be52 {

// 0x0024e730 audio::SeqEventNestTrack::vfunc_4 (45 B): matches/0x0024e730.cpp
// sym: ?f4@SeqEventNestTrack@fn_f724be52@@UAEPAV12@I@Z
SeqEventNestTrack* SeqEventNestTrack::f4(unsigned int param) {
    ((owners::Str_240060 *)(((SeqEventNestTrack_24e730*)((char*)&this->name))))->FUN_00240060();
    ((SeqEventNestTrack_24e730*)this)->Fnb_0025fd10();
    if (param & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e6698), this);
    return this;
}


// 0x0024e760 audio::SeqEventNestTrack::vfunc_1 (111 B): matches/0x0024e760.cpp
// sym: ?vfunc_1@SeqEventNestTrack@fn_f724be52@@QAEHPAPAUStm_24e760@2@@Z
// data: sClose = DAT_004298dc, sName = DAT_004298e0, sOpen = DAT_004298f4
int SeqEventNestTrack::vfunc_1(Stm_24e760** p) {
    if (SeqEvent::v1(p)) {
        if (Match_00246f50(*p, DAT_004298f4)) {
            (*p)->depth++;
            if (ReadTrack_0024e600(p, DAT_004298e0, (char*)&this->name)) {
                (*p)->depth--;
                Stm_24e760* s = *p;
                if (Match_00246f50(s, DAT_004298dc))
                    return 1;
            }
        }
    }
    return 0;
}


// 0x0024e870 audio::SeqEventNestTrack::vfunc_2 (156 B): equivalent/0x0024e870.cpp
// sym: ?FUN_0024e870@SeqEventNestTrack@fn_f724be52@@QAEXPAUEvent_24e870@2@@Z @622861a86459 @w5aa5f19fef95
// STATUS: equivalent (tools/equiv.py level 3: 782 inputs, branch coverage 10/10)
// audio::SeqEventNestTrack::vfunc_2 @ 0x0024e870
// audio::SeqEventNestTrack::vfunc_2: find the nested event for a key and forward to it
// equiv-map: ??0Key@@QAE@XZ = 0x0023fac0
// equiv-map: ??1Key@@QAE@XZ = 0x00240060
void SeqEventNestTrack::FUN_0024e870(Event_24e870 *e) throw()
{
    Key key;
    FUN_002613b0(e->ctx->tree, &key, name);
    Index_24e870 *index = FUN_00247810(e->ctx);
    unsigned int id = FUN_002673a0(key.FUN_0023fb00(), 0);
    Node *node = index->root;
    while (node != (Node *)index->nil) {
        if (id < node->key) {
            node = node->left;
        } else if (id <= node->key) {
            Node *hit = (Node *)((char *)node - 4);
            if (hit != 0)
                (&node->handler)->v2(e);
            break;
        } else {
            node = node->right;
        }
    }
}

} // namespace fn_f724be52
