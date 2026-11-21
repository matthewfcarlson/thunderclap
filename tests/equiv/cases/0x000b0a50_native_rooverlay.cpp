// (integ9, rooverlay) 0x000b0a50 under --wine: input 1550's directed patch steered `walk->count` through b, which the
// input points into the original's .rdata (rdata_ptrs), and so rewrote the literals "YAxis"/"XAxis" (0x00405f98,
// 0x00405fa0) the original's strcmp reads, while ours reads its own copies: call #57 went elsewhere. No real input writes
// a literal (as rowrite): in Wine mode a directed input never patches the original's .rdata. _off: EQUIV_OFF=rooverlay.
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b0440..0x000b0f20 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "gen/global.h"   // (allocsize1)
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/records.h"
#include "decls/data/script.h"
#include "gen/owners.h"
#include "game/script_bind.h"
#define TREE_TU_BEGIN namespace fn_f3cf613f {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3cf613f {} using namespace fn_f3cf613f;
#include "game/unknown.h"
#include "decls/managers.h"

// ---- declarations shared by the functions below
namespace fn_f3cf613f {
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)
} // namespace fn_f3cf613f
inline void* operator new(hulk_uintptr, void* p) throw() { return p; }
namespace fn_f3cf613f {
class CHapticControllerManager { public: float FUN_dummy(); };
extern "C" char DAT_00405eb8[];   // Method0<CHapticControllerManager,void>'s vftable
extern "C" char DAT_00405ee8[];   // Closure0<CHapticControllerManager,void>'s vftable
struct Registry_b0440 {
    void FUN_001d3b70(const char*, void*);
    void FUN_000b0440(const char* name, CHapticControllerManager* owner, void (CHapticControllerManager::*fn)());
};
class A_b06e0 {
  public:
    int m0;
    int m4;
    A_b06e0();
};
struct Obj_b0710 {
    void* a;   // (nat2, D134) a block's end and the block, freed with operator delete
    void* b;
    void Clear();
};
extern "C" int FUN_00096670(const char*, const char*, int);
class Obj_b0810 {
  public:
    char pad[0x110];
    struct E {
        int count;
        hulk_intptr base;
    } e[11];
    char* get(int a, int b);
};
struct C_b0850 {
    int data[100];
    int* Get(int, int, int);
};
struct Item {
    int count;
    int* value;
};
struct Entry_b0930 {
    int count;
    void* ptr;
};
class Obj_b0930 {
  public:
    char pad[0x290];
    Entry_b0930 entries[13];
    void* Get(int a, int b);
};
class C_b0970 {
  public:
    struct E {
        int count;
        void* ptr;
    };
    char pad[0x2f8];
    E entries[6];
    void* f(int x, int y, int z);
};
extern "C" unsigned char* FUN_000b09c0(int a, hulk_intptr b);
struct Entry_b09c0 {
    int count;
    hulk_uintptr ptr;
};
struct Entry {
    int count;
    float* value;
};
struct Elem_b0a50 {
    char data[0x20];
};
class Control_b0a50 {
public:
    virtual void AddRef();
    virtual void Release();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual const char *vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10(float lo, float hi);
};
class Factory_b0a50 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual Control_b0a50 *vfunc_10(Elem_b0a50 *e);
};
struct Rec_b0a50 {
    int count;
    Elem_b0a50 *items;
};
struct Row_b0a50 {
    Control_b0a50 *ctl[2][3];
    int flag[2][3];
};
struct Resource_b0cf0 {
 virtual void slot0();
 virtual void release();
};
struct Record_b0cf0 { Resource_b0cf0* resources[6]; char padding[24]; };
struct Group_b0cf0 { Resource_b0cf0* resources[4]; };
class Owner_b0db0 {
  public:
    virtual void A();
    virtual void Release();
};
class Obj_b0db0 {
  public:
    char pad0[0x10];
    Owner_b0db0* p;
    void Run();
};
void cleanup_000b0cf0(int, int, void*, void*, void*);
struct Button_b0e20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void apply(void* data);
};
struct Container_b0e20 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int count(const char* name);
    virtual Button_b0e20* get(const char* name, int index);
};
struct Object {
    char pad0[0x10];
    Container_b0e20* container;
    char pad14[0x40];
    int state;
    char pad58[0x450];
    void** data;
    void FUN_000b0e20();
};


// 0x000b0440 FUN_000b0440 (109 B): matches/0x000b0440.cpp
// sym: ?FUN_000b0440@Registry_b0440@fn_f3cf613f@@QAEXPBDPAVCHapticControllerManager@2@P832@AEXXZ@Z
// (script1) byte-matched since its Closure0 is include/game/script_bind.h's record (was equivalent)
// FUN_000b0440 @ 0x000b0440
// FUN_000b0440 @ 0x000b0440  (generated by work/closure/gen.py)
void Registry_b0440::FUN_000b0440(const char* name, CHapticControllerManager* owner, void (CHapticControllerManager::*fn)()) {
    // (script1) the record Closure0 of include/game/script_bind.h: the game's vftables by address
    typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod0<CHapticControllerManager, void>, CHapticControllerManager> Built_t;
    HULK_SIZE32(Built_t, 0x24);
    Built_t* c = new Built_t(name, owner, fn, DAT_00405eb8, DAT_00405ee8);
    FUN_001d3b70(name, c);
}

} // namespace fn_f3cf613f

// 0x000b0500 FUN_000b0500 (440 B): equivalent/0x000b0500.cpp [wrapped: conflict: Closure0; Method0]
// sym: ??0CHapticControllerManager@fn_000b0500@@QAE@PAVSource_b0500@1@@Z @efef6eacfb67 @w82588783fb58 @v31f683454723
namespace fn_000b0500 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_000b0500 @ 0x000b0500
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

class CHapticControllerManager;


// (script1) the bound functions are records of include/game/script_bind.h; the game's vftables by address
extern "C" char DAT_00405ea8[];   // Method4<CHapticControllerManager,void,int,float,float,float>
extern "C" char DAT_00405eb8[];   // Method0<CHapticControllerManager,void>
extern "C" char DAT_00405ec8[];   // Method1<CHapticControllerManager,void,bool>
extern "C" char DAT_00405ed8[];   // Closure4<CHapticControllerManager,void,int,float,float,float>
extern "C" char DAT_00405ee8[];   // Closure0<CHapticControllerManager,void>
extern "C" char DAT_00405ef8[];   // Closure1<CHapticControllerManager,void,bool>

struct Registry_b0500 {
    void FUN_001d3b70(const char* name, void* closure);
};
extern "C" Registry_b0500* FUN_001d4c90();
extern "C" void* __cdecl FUN_0008d690(unsigned int);   // (decl1) as defined (unk_08ceb0.cpp)

class Source_b0500 {
  public:
    void* FUN_000ae640(int index);
};

class IDevice_b0500 {
  public:
    virtual void init();
    virtual void release();
};

class CHapticController_b0500 : public IDevice_b0500 {
  public:
    CHapticController_b0500* FUN_000afbf0(void* source);
    void FUN_000afb80(char flag);   // (script1) as defined (unk_0af420.cpp; `int` did not bind natively)
};

class CHapticControllerManager {
  public:
    CHapticControllerManager(Source_b0500* source);
    virtual void* v0_000b0060(char);
    char field_04;
    unsigned char field_05;
    char pad_06[2];
    IDevice_b0500* device;

    void FUN_000afea0(int, float, float, float);
    void FUN_000afe80();
    void FUN_000afe10(int);   // (script1) as defined (unk_0afdf0.cpp), bound below as the Lua function's (bool)
};
HULK_MGR_SAME(CHapticControllerManager, HulkHapticControllerManager);   // (x64t9-mgr) include/decls/managers.h

CHapticControllerManager::CHapticControllerManager(Source_b0500* source) {
    field_04 = 0;
    field_05 = 1;
    device = 0;

    CHapticController_b0500* dev = (CHapticController_b0500*)FUN_0008d690((int)sizeof(::CHapticController));   // (allocsize1) gen's record
    if (dev != 0)
        dev = dev->FUN_000afbf0(source->FUN_000ae640(0));
    if (dev != 0)
        dev->init();
    if (device != 0)
        device->release();
    device = dev;
    dev->FUN_000afb80(field_05);

    typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod4<CHapticControllerManager, void, int, float, float, float>,
                                       CHapticControllerManager> Closure4_t;
    typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod0<CHapticControllerManager, void>, CHapticControllerManager> Closure0_t;
    typedef hulk_script::ScriptClosure<hulk_script::ScriptMethod1<CHapticControllerManager, void, bool>, CHapticControllerManager>
        Closure1_t;
    HULK_SIZE32(Closure4_t, 0x24);
    HULK_SIZE32(Closure0_t, 0x24);
    HULK_SIZE32(Closure1_t, 0x24);
    Registry_b0500* reg = FUN_001d4c90();

    Closure4_t* playRumble = new Closure4_t("hcm_PlayRumble", this, &CHapticControllerManager::FUN_000afea0, DAT_00405ea8, DAT_00405ed8);
    reg->FUN_001d3b70("hcm_PlayRumble", playRumble);

    Closure0_t* resetRumble = new Closure0_t("hcm_ResetRumble", this, &CHapticControllerManager::FUN_000afe80, DAT_00405eb8, DAT_00405ee8);
    reg->FUN_001d3b70("hcm_ResetRumble", resetRumble);

    Closure1_t* enableRumble = new Closure1_t("hcm_EnableRumble", this, reinterpret_cast<void (CHapticControllerManager::*)(bool)>(&CHapticControllerManager::FUN_000afe10), DAT_00405ec8, DAT_00405ef8);
    reg->FUN_001d3b70("hcm_EnableRumble", enableRumble);
}
} // namespace fn_000b0500
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f3cf613f {

// 0x000b06e0 FUN_000b06e0 (16 B): matches/0x000b06e0.cpp
// sym: ??0A_b06e0@fn_f3cf613f@@QAE@XZ
A_b06e0::A_b06e0() {
    m0 = 0;
    m4 = 0;
}


// 0x000b0710 FUN_000b0710 (34 B): matches/0x000b0710.cpp
// sym: ?Clear@Obj_b0710@fn_f3cf613f@@QAEXXZ
void Obj_b0710::Clear() {
    if (b) {
        ::operator delete(b);
        a = 0;
        b = 0;
    }
}

} // namespace fn_f3cf613f

// 0x000b0740 FUN_000b0740 (110 B): matches/0x000b0740.cpp
// sym: ?FUN_000b0740@Dev_b0740@owners@@QAEXPBD@Z
void owners::Dev_b0740::FUN_000b0740(const char* s) {
    sprintf(name, "%s", s);
    if (name[0] == 0) {
        type = 3;
        return;
    }
    if (FUN_00096670(name, "Keyboard", 8) == 0) {
        type = 1;
        return;
    }
    type = (FUN_00096670(name, "Mouse", 5) != 0) ? 0 : 2;
}


// 0x000b07b0 FUN_000b07b0 (15 B): matches/0x000b07b0.cpp
// sym: ?FUN_000b07b0@Object_b07b0@owners@@QAEEH@Z
unsigned char owners::Object_b07b0::FUN_000b07b0(int x) {
    value = x;
    return 1;
}


// 0x000b07c0 FUN_000b07c0 (15 B): matches/0x000b07c0.cpp
// sym: ?FUN_000b07c0@Obj_b07c0@owners@@QAEEH@Z
unsigned char owners::Obj_b07c0::FUN_000b07c0(int x) {
    value = x;
    return 1;
}


// 0x000b07d0 FUN_000b07d0 (15 B): matches/0x000b07d0.cpp
// sym: ?FUN_000b07d0@Target_b07d0@owners@@QAE_NH@Z
bool owners::Target_b07d0::FUN_000b07d0(int x) {
    value = x;
    return true;
}


// 0x000b07e0 FUN_000b07e0 (15 B): matches/0x000b07e0.cpp
// sym: ?FUN_000b07e0@Target_b07e0@owners@@QAE_NI@Z
bool owners::Target_b07e0::FUN_000b07e0(unsigned int x) {
    value = x;
    return true;
}


// 0x000b07f0 FUN_000b07f0 (15 B): matches/0x000b07f0.cpp
// sym: ?FUN_000b07f0@Target_b07f0@owners@@QAEEH@Z
unsigned char owners::Target_b07f0::FUN_000b07f0(int x) {
    value = x;
    return 1;
}


// 0x000b0800 FUN_000b0800 (15 B): matches/0x000b0800.cpp
// sym: ?FUN_000b0800@Target_b0800@owners@@QAE_NH@Z
bool owners::Target_b0800::FUN_000b0800(int x) {
    value = x;
    return true;
}

namespace fn_f3cf613f {

// 0x000b0810 FUN_000b0810 (64 B): matches/0x000b0810.cpp
// sym: ?get@Obj_b0810@fn_f3cf613f@@QAEPADHH@Z
// data: zero_b0810 = DAT_003f335c
char* Obj_b0810::get(int a, int b) {
    if (a < 0 || a >= 11)
        return ((char*)&DAT_003f335c);
    if (b >= 0 && b < e[a].count)
        return (char*)e[a].base + b * 32;
    return ((char*)&DAT_003f335c);
}


// 0x000b0850 FUN_000b0850 (73 B): matches/0x000b0850.cpp
// sym: ?Get@C_b0850@fn_f3cf613f@@QAEPAHHHH@Z
int* C_b0850::Get(int x, int y, int z) {
    if (x >= 0 && x < 2 && y >= 0 && y < 2 && z >= 0 && z < 3) {
        int* p = data + (z + (y + 15 + x * 2) * 3) * 2;
        if (p[0] > 0)
            return (int*)p[1];
    }
    return ((int*)&DAT_003f335c);
}


// 0x000b08a0 FUN_000b08a0 (49 B): matches/0x000b08a0.cpp
// sym: _FUN_000b08a0
// data: gBases = DAT_004ddb14, gCounts = DAT_004ddb10
// (dg1) the lists by records.h's ControllerNameList (was 32-bit word offsets)
extern "C" {
void* FUN_000b08a0(int index, int item) {
    if (index >= 0 && index < 11 && item >= 0 && item < DAT_004ddb10[index].count)
        return DAT_004ddb10[index].data + item * 32;
    return (void*)((hulk_intptr)((char*)&DAT_003f335c));
}
}


// 0x000b08e0 FUN_000b08e0 (69 B): matches/0x000b08e0.cpp
// sym: ?FUN_000b08e0@fn_f3cf613f@@YAPAHHHH@Z
// data: gItems = DAT_004ddb68, gZero = DAT_003f335c
int* __cdecl FUN_000b08e0(int a, int b, int c) {
    if (a >= 0 && a < 2 && b >= 0 && b < 2 && c >= 0 && c < 3) {
        Item* p = &((Item*)&DAT_004ddb68)[(a * 2 + b) * 3 + c];
        if (p->count > 0)
            return p->value;
    }
    return ((int*)&DAT_003f335c);
}


// 0x000b0930 FUN_000b0930 (64 B): matches/0x000b0930.cpp
// sym: ?Get@Obj_b0930@fn_f3cf613f@@QAEPAXHH@Z
// data: zeroValue_b0930 = DAT_003f335c
void* Obj_b0930::Get(int a, int b) {
    if (a < 0 || a >= 13)
        return ((float*)&DAT_003f335c);
    if (b >= 0 && b < entries[a].count)
        return (char*)entries[a].ptr + b * 32;
    return ((float*)&DAT_003f335c);
}


// 0x000b0970 FUN_000b0970 (76 B): matches/0x000b0970.cpp
// sym: ?f@C_b0970@fn_f3cf613f@@QAEPAXHHH@Z
void* C_b0970::f(int x, int y, int z) {
    if (x < 0 || x >= 2)
        return (void*)((hulk_intptr)((char*)&DAT_003f335c));
    if (y < 0 || y >= 2)
        return (void*)((hulk_intptr)((char*)&DAT_003f335c));
    if (z < 0 || z >= 3)
        return (void*)((hulk_intptr)((char*)&DAT_003f335c));
    E* p = &entries[z + (y + x * 2) * 3];
    if (p->count <= 0)
        return (void*)((hulk_intptr)((char*)&DAT_003f335c));
    return p->ptr;
}


// 0x000b09c0 FUN_000b09c0 (49 B): matches/0x000b09c0.cpp
// sym: _FUN_000b09c0
unsigned char* FUN_000b09c0(int a, hulk_intptr b) {
    if (a >= 0 && a < 13 && b >= 0 && b < ((Entry_b09c0*)&DAT_004dda48)[a].count)
        return (unsigned char*)(((Entry_b09c0*)&DAT_004dda48)[a].ptr + (b << 5));
    return ((unsigned char*)&DAT_003f335c);
}


// 0x000b0a00 FUN_000b0a00 (69 B): matches/0x000b0a00.cpp
// sym: ?FUN_000b0a00@fn_f3cf613f@@YAPAMHHH@Z
// data: entries = DAT_004ddab0, zero = DAT_003f335c
float* __cdecl FUN_000b0a00(int x, int y, int z) {
    if (x < 0 || x >= 2 || y < 0 || y >= 2 || z < 0 || z >= 3)
        return ((float*)&DAT_003f335c);
    Entry* p = &((Entry*)&DAT_004ddab0)[(x * 2 + y) * 3 + z];
    if (p->count <= 0)
        return ((float*)&DAT_003f335c);
    return p->value;
}


// 0x000b0a50 FUN_000b0a50 (671 B): equivalent/0x000b0a50.cpp
// sym: ?FUN_000b0a50@fn_f3cf613f@@YAXPAVFactory_b0a50@1@HHPAURec_b0a50@1@11PAPAPAVControl_b0a50@1@PAURow_b0a50@1@PAPAV41@@Z @540864a12ca7 @waa4bab2cf77d @vdfcdbe11829e
// STATUS: equivalent (tools/equiv.py level 3: 36 inputs, branch coverage 49/50, incomplete)
// FUN_000b0a50 @ 0x000b0a50
void FUN_000b0a50(Factory_b0a50 *factory, int na, int nb, Rec_b0a50 *a, Rec_b0a50 *b, Rec_b0a50 *c, Control_b0a50 ***outA, Row_b0a50 *outB, Control_b0a50 **outC)
{
    int i;
    int k;
    int m;
    int e;

    for (i = 0; i < na; i++) {
        Rec_b0a50 *rec = &a[i];
        int cnt = rec->count;
        for (int j = 0; j < cnt; j++) {
            Elem_b0a50 *p;
            if (j >= 0 && j < rec->count)
                p = &rec->items[j];
            else
                p = ((Elem_b0a50*)&DAT_003f335c);
            Control_b0a50 *ctl = factory->vfunc_10(p);
            if (ctl) {
                ctl->vfunc_10(0.0f, 1.0f);
                ctl->AddRef();
                if (outA[i][j])
                    outA[i][j]->Release();
                outA[i][j] = ctl;
            }
        }
    }

    Rec_b0a50 *walk = b;
    for (k = 0; k < nb; k++) {
        for (m = 0; m < 2; m++) {
            for (e = 0; e < 3; e++) {
                Elem_b0a50 *p = (walk->count > 0) ? walk->items : ((Elem_b0a50*)&DAT_003f335c);
                Control_b0a50 *ctl = factory->vfunc_10(p);
                if (ctl) {
                    const char *name = ctl->vfunc_4();
                    if (strcmp(name, "XAxis") == 0 || strcmp(name, "YAxis") == 0 ||
                        strcmp(name, "ZAxis") == 0 || strcmp(name, "RzAxis") == 0) {
                        ctl->vfunc_10(-1.0f, 1.0f);
                        outB[k].flag[m][e] = 0;
                    } else if (strcmp(name, "Button") == 0 || strcmp(name, "AnalogButton") == 0) {
                        ctl->vfunc_10(0.0f, 1.0f);
                        outB[k].flag[m][e] = 1;
                    } else {
                        outB[k].flag[m][e] = 1;
                    }
                    ctl->AddRef();
                    if (outB[k].ctl[m][e])
                        outB[k].ctl[m][e]->Release();
                    outB[k].ctl[m][e] = ctl;
                }
                walk++;
            }
        }
    }

    Elem_b0a50 *p = (c->count > 0) ? c->items : ((Elem_b0a50*)&DAT_003f335c);
    Control_b0a50 *ctl = factory->vfunc_10(p);
    if (ctl) {
        ctl->vfunc_10(0.0f, 1.0f);
        if (outC) {
            ctl->AddRef();
            if (*outC)
                (*outC)->Release();
            *outC = ctl;
        }
    }
}


// 0x000b0cf0 FUN_000b0cf0 (191 B): equivalent/0x000b0cf0.cpp
// sym: ?FUN_000b0cf0@fn_f3cf613f@@YAXHHPAPAUGroup_b0cf0@1@PAURecord_b0cf0@1@PAPAUResource_b0cf0@1@@Z @9cb2620bfc0b @w771e694eaf72 @v9853581e2bd9
// STATUS: equivalent (tools/equiv.py level 3: 50 inputs, branch coverage 22/22)
// FUN_000b0cf0 @ 0x000b0cf0
void __cdecl FUN_000b0cf0(int groupCount, int recordCount, Group_b0cf0** groups, Record_b0cf0* records, Resource_b0cf0** single)
{
 if (single && *single) { (*single)->release(); *single = 0; }
 if (recordCount > 0) {
  for (int i = recordCount - 1; i >= 0; --i) {
   for (int j = 5; j >= 0; --j) {
    if (records[i].resources[j]) {
     records[i].resources[j]->release();
     records[i].resources[j] = 0;
    }
   }
  }
 }
 if (groupCount > 0) {
  for (int i = groupCount - 1; i >= 0; --i) {
   for (int j = 3; j >= 0; --j) {
    if (groups[i]->resources[j]) {
     groups[i]->resources[j]->release();
     groups[i]->resources[j] = 0;
    }
   }
  }
 }
}


// 0x000b0db0 FUN_000b0db0 (94 B): matches/0x000b0db0.cpp
// sym: ?Run@Obj_b0db0@fn_f3cf613f@@QAEXXZ
void Obj_b0db0::Run() {
    if (p) {
        cleanup_000b0cf0(0xd, 2, (char*)this + 0x3e4, (char*)this + 0x418, (char*)this + 0x488);
        cleanup_000b0cf0(0xb, 2, (char*)this + 0x358, (char*)this + 0x384, (char*)this + 0x48c);
        if (p) {
            p->Release();
            p = 0;
        }
    }
}


// 0x000b0e20 FUN_000b0e20 (201 B): matches/0x000b0e20.cpp
// sym: ?FUN_000b0e20@Object@fn_f3cf613f@@QAEXXZ
void Object::FUN_000b0e20() {
    if (state == 2 || !container || !data)
        return;
    int n = container->count("Button");
    for (int i = 0; i < n; ++i) {
        Button_b0e20* button = container->get("Button", i);
        if (button && data[i])
            button->apply(data[i]);
    }
    if (data) {
        for (int i = 0; i < n; ++i) {
            if (data[i]) {
                ::operator delete(data[i]);
                data[i] = 0;
            }
        }
    }
    if (data) {
        ::operator delete(data);
        data = 0;
    }
}

} // namespace fn_f3cf613f

// 0x000b0ef0 FUN_000b0ef0 (7 B): matches/0x000b0ef0.cpp
// sym: ?FUN_000b0ef0@C_b0ef0@owners@@QAEIXZ
unsigned int owners::C_b0ef0::FUN_000b0ef0() {
    return value;
}

