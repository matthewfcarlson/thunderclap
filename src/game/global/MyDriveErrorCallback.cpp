// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// cl-flags: /GX
// object 0x0008de70..0x0008ed50 (kind game, layer game, confidence high), dominant class MyDriveErrorCallback
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/script.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f294a1a9 {
#define TREE_TU_END }
namespace fn_f294a1a9 {} using namespace fn_f294a1a9;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f294a1a9 {
extern "C" char DAT_00400870[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class CFEManager_8e150 {
  public:
    void Call(const char*, int);
};
class Function_8e150 {
  public:
    virtual void f0();
    virtual void f1();
};
class Dummy_8e1d0 {
  public:
    void Call(void*);
};
class CActorManager_8e730 {
  public:
    void Method(const char*, float);
};
struct Pair_8e730 {
    const char* s;
    float f;
};
extern "C" unsigned char __cdecl Check(const void*);
class Function_8e750 {
  public:
    Function_8e750(const char*, int);
    virtual void fn();
    char pad[0xc];
    unsigned char flag;
    char pad2[7];
};
class Method1_8e750 : public Function_8e750 {
  public:
    Method1_8e750(const char* s, void* p) : Function_8e750(s, 1) {
        value = p;
        flag2 = Check(((char*)&DAT_0048e100));
        flag = Check(((char*)&DAT_0048e0f0));
    }
    virtual void fn();
    unsigned char flag2;
    char pad3[3];
    void* value;
};
class Closure1_8e750 : public Method1_8e750 {
  public:
    Closure1_8e750(const char* s, void* x, void* p);
    virtual void fn();
    void* extra;
};
class CActorManager_8e7c0 {
  public:
    void invoke(const char*);
};
extern "C" void __cdecl FUN_00292410();
struct Obj_8ecd0 {
    int a, b, c, pad, mode;
    char gap[0x0b];
    char f2;
    char f1;
    char f3;
    int x, y;
};

} // namespace fn_f294a1a9

// 0x0008de70 CPlatformManager::vfunc_0 (31 B): matches/0x0008de70.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0008de70@@UAEPAV123@E@Z
namespace fn_0008de70 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* hulk_at_004007f4[];
namespace pure3d {
class NonCopyable : public IRefCount {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = hulk_at_004007f4;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0008de70


// 0x0008e070 CSPHulkPropLoader::vfunc_2 (30 B): matches/0x0008e070.cpp
// sym: ??_GCSPHulkPropLoader@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CSPHulkPropLoader::~CSPHulkPropLoader() {}

namespace fn_f294a1a9 {

// 0x0008e090 FUN_0008e090 (66 B): matches/0x0008e090.cpp
// sym: ?FUN_0008e090@fn_f294a1a9@@YAHXZ
hulk_intptr FUN_0008e090() {
    if (DAT_004dd7e0 == 0) {
        char* p = (char*)FUN_0008d690(0xc);
        if (p != 0) {
            p[5] = 0;
            p[6] = 0;
            p[7] = 0;
            p[4] = 0;
            p[8] = 0;
            p[9] = 0;
            *(hulk_uintptr*)p = ((hulk_intptr)DAT_00400870);
        } else {
            p = 0;
        }
        DAT_004dd7e0 = p;
    }
    return (int)(hulk_intptr)DAT_004dd7e0;
}

} // namespace fn_f294a1a9

// 0x0008e130 Method2<CPlatformManager,void,const_char_*,const_char_*>::vfunc_0 (30 B): matches/0x0008e130.cpp
// sym: ??_G?$Method2@VCPlatformManager@@XPBDPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method2<CPlatformManager, void, const char *, const char *>::~Method2() {}


// 0x0008e150 Method2<CPlatformManager,void,const_char_*,const_char_*>::vfunc_2 (23 B): matches/0x0008e150.cpp
// sym: ?vfunc_2@?$Method2@VCPlatformManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x000beac0 (propagated; names are from that function)
template <> void Method2<CPlatformManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; void * p = (void *)__p1; hulk_intptr n = (hulk_intptr)__p2;

    CFEManager_8e150* m = (CFEManager_8e150*)unused;
    const char* s = *(const char**)p;
    int x = *(int*)((char*)p + 4);
    (m->*(*(void (CFEManager_8e150::**)(const char *, int))&this->f_1c))(s, x);
}
#if defined(HULK_PTR64)
template class Method2<CPlatformManager, void, const char *, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x8e130)
#endif


// 0x0008e1b0 Method1<CPlatformManager,void,const_char_*>::vfunc_0 (30 B): matches/0x0008e1b0.cpp
// sym: ??_G?$Method1@VCPlatformManager@@XPBD@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> Method1<CPlatformManager, void, const char *>::~Method1() {}


// 0x0008e1d0 Method1<CPlatformManager,void,const_char_*>::vfunc_2 (19 B): matches/0x0008e1d0.cpp
// sym: ?vfunc_2@?$Method1@VCPlatformManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ce30 (propagated; names are from that function)
template <> void Method1<CPlatformManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; void ** b = (void **)__p1; void * c = (void *)__p2;

    Dummy_8e1d0* d = (Dummy_8e1d0*)a;
    (d->*(*(void (Dummy_8e1d0::**)(void *))&this->f_1c))(*b);
}
#if defined(HULK_PTR64)
template class Method1<CPlatformManager, void, const char *>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x8e1b0)
#endif


// 0x0008e1f0 MyDriveErrorCallback::vfunc_0 (1161 B): equivalent/0x0008e1f0.cpp [wrapped: conflict: FUN_0008e090; MyControllerCallback; MyDriveErrorCallback]
// sym: ?vfunc_0@MyDriveErrorCallback@fn_0008e1f0@@UAEDIHHHH@Z @60a9a387765b @wa8a8bbdcb5dd
inline void *operator new(size_t, void *p) throw() { return p; }
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_0008e1f0 {
// STATUS: equivalent (tools/equiv.py level 3: 3130 inputs, branch coverage 92/97, incomplete)
// MyDriveErrorCallback::vfunc_0 @ 0x0008e1f0
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



struct Ctl_8e1f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float v9(int i);
};

struct Item_8e1f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual Ctl_8e1f0 *v10(const char *name);
};

struct Mgr_8e1f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3();
    virtual Item_8e1f0 *v4(int i);
};

struct Fade_8e1f0 {
    void FUN_001b8160();
    void FUN_001b8110(int ms);
};

struct Audio_8e1f0 {
    void FUN_001eb870();
    void FUN_001eb2a0(float a, int b);
    void FUN_001eb890();
};

struct Pad_8e1f0 {
    void FUN_000afe80();
};

struct Sys_8e1f0 {
    Fade_8e1f0 *FUN_00086300();
    Audio_8e1f0 *FUN_000862e0();
    Pad_8e1f0 *FUN_00086330();
};

struct World {
    char pad[0x54];
    Sys_8e1f0 *f54;
    char pad58[0x9d - 0x58];
    char b9d;
};


class MyControllerCallback {
public:
    MyControllerCallback()
    {
        b5 = 0;
        b6 = 0;
        b7 = 0;
        b4 = 0;
        b8 = 0;
        b9 = 0;
    }
    virtual void v0_0008dbb0(void*);
    char b4;
    char b5;
    char b6;
    char b7;
    char b8;
    char b9;
};


extern "C" void __cdecl FUN_001bb0b0(const char *key);
extern "C" char __cdecl FUN_0008d910(int a3);
extern "C" void __cdecl FUN_00240bb0();
extern "C" Mgr_8e1f0 *__cdecl FUN_002684b0();
extern "C" void __cdecl FUN_002684c0();
void *FUN_0008d690(unsigned int size);
MyControllerCallback *FUN_0008e090();

class MyDriveErrorCallback {
public:
    virtual char vfunc_0(unsigned int code, int a1, int a2, int a3, int a4);
    const char *f4;
    const char *f8;
    char b0c;
    char b0d;
    char b0e;
    char b0f;
};

char MyDriveErrorCallback::vfunc_0(unsigned int code, int a1, int a2, int a3, int a4)
{
    if (b0e) {
        FUN_001bb0b0(f4);
        return 1;
    }
    char result = 1;
    if (code == 0)
        b0c = 0;
    else
        b0c = 1;
    switch (code) {
    case 0:
        f8 = "No Error: Success";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_XBOX";
        result = 0;
        b0c = 0;
        break;
    case 1:
        f8 = "Error: File Not Found";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 2:
        f8 = "Error: Shell Open";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 3:
        f8 = "Error: Wrong Media";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 4:
        f8 = "Error: No Media";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 5:
        f8 = "Error: Media Not Formatted";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 6:
        f8 = "Error: Media Corrupt";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 7:
        f8 = "Error: No Free Space";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 8:
        f8 = "Error: Hardware Failure";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 9:
        f8 = "Error: Media Encoding Error";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 10:
        f8 = "Error: Media Wrong Type";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 11:
        f8 = "Error: Media Invalid";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    case 12:
        f8 = "Error: Data Corrupt";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    default:
        f8 = "Error: Unknown Reason";
        f4 = "TBS_DISC_KEEP_YOUR_GREASY_FINGERS_OFF_THE_DVD_OTHER";
        break;
    }

    if (code == 1) {
        if (DAT_004dd8e6) {
            result = 0;
            b0c = 0;
        }
        if (!FUN_0008d910(a3)) {
            result = 0;
            b0c = 0;
        }
    }

    if (b0c) {
        World *g = DAT_004dd700;
        if (g) {
            if (g->b9d && g->f54) {
                if (g->f54->FUN_00086300())
                    DAT_004dd700->f54->FUN_00086300()->FUN_001b8160();
                g = DAT_004dd700;
            }
            if (g) {
                if (g->b9d && g->f54) {
                    if (g->f54->FUN_000862e0()) {
                        if (!b0f) {
                            DAT_004dd700->f54->FUN_000862e0()->FUN_001eb870();
                            DAT_004dd700->f54->FUN_000862e0()->FUN_001eb2a0(0.016666668f, 0);
                            DAT_004dd700->f54->FUN_000862e0()->FUN_001eb2a0(0.016666668f, 0);
                            b0f = 1;
                        }
                        FUN_00240bb0();
                    }
                    g = DAT_004dd700;
                }
                if (g && g->b9d && g->f54 && g->f54->FUN_00086330())
                    DAT_004dd700->f54->FUN_00086330()->FUN_000afe80();
            }
        }
        if (!b0d)
            b0d = 1;
        FUN_001bb0b0(f4);
        return result;
    }

    if (!b0d)
        return result;
    b0d = 0;
    FUN_001bb0b0(f4);
    bool found = false;
    do {
        int n = FUN_002684b0()->v3();
        if (n > 0) {
            int i = 0;
            do {
                if (FUN_002684b0()->v4(i)) {
                    if (FUN_002684b0()->v4(i)->v3()) {
                        Item_8e1f0 *it = FUN_002684b0()->v4(i);
                        Ctl_8e1f0 *c1 = it->v10("Start");
                        Ctl_8e1f0 *c2 = it->v10("A");
                        if (c1->v9(0) > 0.2f || c2->v9(0) > 0.2f) {
                            found = true;
                            break;
                        }
                    }
                }
                i++;
            } while (i < FUN_002684b0()->v3());
        }
        (*(int*)&DAT_004dda40)++;
        FUN_002684c0();
    } while (!found);

    MyControllerCallback *c = (*(MyControllerCallback**)&DAT_004dd7e0);
    (*(char*)&DAT_004e222d) = 1;
    DAT_004e222c = 1;
    if (!c) {
        void *m = FUN_0008d690((int)sizeof(MyControllerCallback));
        if (m)
            c = new (m) MyControllerCallback;
        else
            c = 0;
        (*(MyControllerCallback**)&DAT_004dd7e0) = c;
    }
    if (c->b5) {
        World *g = DAT_004dd700;
        if (g) {
            if (g->b9d && g->f54) {
                if (g->f54->FUN_00086300()) {
                    DAT_004dd700->f54->FUN_00086300()->FUN_001b8110(500);
                }
                g = DAT_004dd700;
            }
            if (g && g->b9d && g->f54 && g->f54->FUN_000862e0()) {
                DAT_004dd700->f54->FUN_000862e0()->FUN_001eb890();
                b0f = 0;
                FUN_0008e090()->b9 = 0;
            }
        }
    }
    return result;
}
} // namespace fn_0008e1f0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x0008e6b0 FUN_0008e6b0 (89 B): matches/0x0008e6b0.cpp [wrapped: conflict: Closure2]
// sym: ??0Closure2@fn_0008e6b0@@QAE@PBDPAVOwner_8e6b0@1@P821@AEXXZ@Z
namespace fn_0008e6b0 {
// Same code shape as 0x00090eb0 (propagated; names are from that function)

extern void* hulk_at_004008a0[2];
extern void* hulk_at_004009f8[2];

// Closure2's fields (include/decls/data/script.h): Function's fields, the bound member-function pointer, the object.
class Owner_8e6b0 {};
typedef void (Owner_8e6b0::*Fn_8e6b0)();
struct FUN_001d0480 {
    FUN_001d0480(const char* a1, int b);
};
extern "C" char __cdecl FUN_001d04d0(const void* tbl);

class Closure2 : public FUN_001d0480 {
  public:
    void* vfptr;             // 0x00
    ScriptFunctionFields f;  // 0x04
    Fn_8e6b0 fn;            // 0x1c
    Owner_8e6b0* owner;     // 0x20
    Closure2(const char* a1, Owner_8e6b0* a2, Fn_8e6b0 a3);
};

Closure2::Closure2(const char* a1, Owner_8e6b0* a2, Fn_8e6b0 a3) : FUN_001d0480(a1, 2) {
    vfptr = (void*)hulk_at_004008a0;
    fn = a3;
    f.retType = FUN_001d04d0(((void**)&DAT_0048e100));
    f.argTypes[0] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    f.argTypes[1] = FUN_001d04d0(((void**)&DAT_0048e0f0));
    vfptr = (void*)hulk_at_004009f8;
    owner = a2;
}
} // namespace fn_0008e6b0


// 0x0008e730 Closure2<CPlatformManager,void,const_char_*,const_char_*>::vfunc_2 (22 B): matches/0x0008e730.cpp
// sym: ?vfunc_2@?$Closure2@VCPlatformManager@@XPBDPBD@@UAEXPAX00@Z
// Same code shape as 0x0002e6d0 (propagated; names are from that function)
template <> void Closure2<CPlatformManager, void, const char *, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; Pair_8e730 * p = (Pair_8e730 *)__p1; void * c = (void *)__p2;

    ((*(CActorManager_8e730 * *)&this->f_20)->*(*(void (CActorManager_8e730::**)(const char *, float))&this->f_1c))(p->s, p->f);
}

namespace fn_f294a1a9 {

// 0x0008e750 FUN_0008e750 (76 B): matches/0x0008e750.cpp
// sym: ??0Closure1_8e750@fn_f294a1a9@@QAE@PBDPAX1@Z
Closure1_8e750::Closure1_8e750(const char* s, void* x, void* p) : Method1_8e750(s, p) {
    extra = x;
}

} // namespace fn_f294a1a9

// 0x0008e7c0 Closure1<CPlatformManager,void,const_char_*>::vfunc_2 (18 B): matches/0x0008e7c0.cpp
// sym: ?vfunc_2@?$Closure1@VCPlatformManager@@XPBD@@UAEXPAX00@Z
// Same code shape as 0x0002ed90 (propagated; names are from that function)
template <> void Closure1<CPlatformManager, void, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * a = (void *)__p0; const char ** b = (const char **)__p1; void * c = (void *)__p2;

    ((*(CActorManager_8e7c0 * *)&this->f_20)->*(*(void (CActorManager_8e7c0::**)(const char *))&this->f_1c))(*b);
}

namespace fn_f294a1a9 {

// 0x0008ecd0 FUN_0008ecd0 (98 B): matches/0x0008ecd0.cpp
// sym: _FUN_0008ecd0
// data: gFlag_8ecd0 = DAT_004dd839, gHeight = DAT_0049ca20, gWidth = DAT_0049ca1c
extern "C" void __cdecl FUN_0008ecd0(void * p) {
    FUN_00292410();
    if ((*(unsigned char*)&DAT_004dd839)) {
        DAT_0049ca1c = 0x280;
        DAT_0049ca20 = 0x240;
    }
    ((Obj_8ecd0 *)p)->mode = 7;
    *((char*)((Obj_8ecd0 *)p) + 0x2f) = 1;
    *((char*)((Obj_8ecd0 *)p) + 0x30) = 1;
    ((Obj_8ecd0 *)p)->a = DAT_0049ca1c;
    ((Obj_8ecd0 *)p)->b = DAT_0049ca20;
    ((Obj_8ecd0 *)p)->c = 0x20;
    *((char*)((Obj_8ecd0 *)p) + 0x2c) = 0;
    ((Obj_8ecd0 *)p)->x = 0x11;
    ((Obj_8ecd0 *)p)->y = 0;
    *((char*)((Obj_8ecd0 *)p) + 0x2e) = 1;
}

} // namespace fn_f294a1a9
