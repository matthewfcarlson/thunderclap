// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000b0ff0..0x000b35d0 (kind game, layer game, confidence medium), dominant class CPhysicalController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3919bbe {
#define TREE_TU_END }
namespace fn_f3919bbe {} using namespace fn_f3919bbe;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f3919bbe {
struct Obj_b0ff0 {
    void* a;   // (nat2, D134) a block's end and the block, freed with operator delete
    void* b;
    void Clear();
};
void *__cdecl FUN_0008d750(hulk_intptr size, int align);   // (gfx1) as defined (unk_08ceb0.cpp): the size is pointer-sized
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
extern void Ensure(int);
extern void Copy_00267830(void*, const void*, unsigned int);
// (gfx6, C15) the controller views on gen's record (its native layout)
class Obj : public ::CPhysicalController {
  public:
    bool Set(int index, const void* src, int slot);
};
struct Resource_b1aa0 { virtual void AddRef(); };
struct Manager_b1aa0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Resource_b1aa0* Find(const char*); };
extern "C" Manager_b1aa0* __cdecl FUN_002684b0();
extern void __cdecl FUN_000b0a50(Resource_b1aa0*, int, int, void*, void*, void*, void*, void*, void*);
struct Object : public ::CPhysicalController {
 void FUN_000b0db0(); void Update();
};
class Item_b30c0 {
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
    virtual float v9(int mode);
};
union FS_b30c0 {
    float f;
    unsigned int u;
};
class Blender_b30c0 : public ::CPhysicalController {
public:
    // (gfx6, C15) mode f_54, the ranges f_490 / f_494 and f_498 / f_49c; a group's count is its names' (f_110 /
    // f_290), its items the points (f_358 / f_3e4), the pairs the axes (f_384 / f_418)
    void FUN_000b30c0(int groups, int pairs, Names *counts, Item_b30c0 ***items, Axes *cells, Item_b30c0 *single,
                       float *out1, float *out2, float *out3);
};
static __forceinline hulk_freg Normalise(const Blender_b30c0 *b, float v)
{
    if (v < b->f_490)
        return 0.0f;
    if (v > b->f_494)
        return 1.0f;
    return (v - b->f_490) / (b->f_494 - b->f_490);
}
static __forceinline hulk_freg Ratio(const Blender_b30c0 *b, float a, float range)
{
    if (a < b->f_498)
        return 0.0f;
    if (!(a < b->f_49c))
        return 1.0f / a;
    return ((a - b->f_498) / range) / a;
}
static __forceinline hulk_freg PickRatio(const Blender_b30c0 *b, float ax, float ay, float range)
{
    float m = 0.0f;
    hulk_freg r1 = 0.0f;
    if (ax > 0.0f) {
        m = ax;
        r1 = Ratio(b, ax, range);
    }
    if (ay > m)
        return Ratio(b, ay, range);
    return r1;
}
struct Param2 {   // (gfx6) 0x000b30c0's outputs: 11 floats, a stick pair's 4 at 0x2c, then the trigger pair's words
    char pad[0x2C];
    float field_2C[4];
    int field_3C;
    int field_40;
};
struct Param3 {   // 13 floats, then a pair's 4
    char pad[0x34];
    float field_34[4];
};
struct Out_b3510 {
    int a;
    int b;
};
class ThisClass : public ::CPhysicalController {
  public:
    void Func(Param2* p2, Param3* p3);
    void FUN_000b30c0(int, int, void*, void*, void*, void*, void*, void*, Out_b3510*);
};


// 0x000b0ff0 FUN_000b0ff0 (34 B): matches/0x000b0ff0.cpp
// sym: ?Clear@Obj_b0ff0@fn_f3919bbe@@QAEXXZ
// Same code shape as 0x000b0710 (propagated; names are from that function)
void Obj_b0ff0::Clear() {
    if (b) {
        ::operator delete(b);
        a = 0;
        b = 0;
    }
}

} // namespace fn_f3919bbe

// 0x000b1020 FUN_000b1020 (117 B): equivalent/0x000b1020.cpp
// sym: ?FUN_000b1020@StringTable_b1020@owners@@QAEXH@Z @2612cca3b1f7 @wc9fe643d1c04 @v96f8c2f5b412
// STATUS: equivalent (tools/equiv.py level 3: 1429 inputs, branch coverage 11/12, incomplete)
// FUN_000b1020 @ 0x000b1020
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void owners::StringTable_b1020::FUN_000b1020(int n)
{
    if (count == n)
        return;
    if (data != 0) {
        ::operator delete(data);
        count = 0;
        data = 0;
    }
    count = n;
    data = (char (*)[32])FUN_0008d750(n << 5, 4);
    for (int i = 0; i < count; i++)
        FUN_00267760(data[i], 0x20, "");
}


// 0x000b10a0 FUN_000b10a0 (47 B): matches/0x000b10a0.cpp
// sym: ?FUN_000b10a0@Target_b10a0@owners@@QAEXHPBX@Z
void owners::Target_b10a0::FUN_000b10a0(int index, const void* source) {
    if (count <= 0)
        Check(1);
    Copy_00267830(data + index * 32, source, 32);
}


// 0x000b10d0 FUN_000b10d0 (2124 B): matches/0x000b10d0.cpp [wrapped: macros]
// sym: ?FUN_000b10d0@fn_000b10d0@@YAXXZ
namespace fn_000b10d0 {

struct Names {
    int count;
    char* data;
    void FUN_000b1020(int);
};
extern char* __cdecl FUN_00267830(char*, const char*, unsigned);
#define SET(g, s)                                                                                            \
    if (g.count <= 0)                                                                                        \
        g.FUN_000b1020(1);                                                                                   \
    FUN_00267830(g.data, s, 32)
void __cdecl FUN_000b10d0() {
    SET((*(Names*)&DAT_004ddb10[0]), "A");
    SET((*(Names*)&DAT_004ddb10[1]), "B");
    SET((*(Names*)&DAT_004ddb10[2]), "X");
    SET((*(Names*)&DAT_004ddb10[3]), "Y");
    SET((*(Names*)&DAT_004ddb10[4]), "Start");
    SET((*(Names*)&DAT_004ddb10[5]), "Back");
    SET((*(Names*)&DAT_004ddb10[6]), "Back");
    SET((*(Names*)&DAT_004ddb10[7]), "LeftTrigger");
    SET((*(Names*)&DAT_004ddb10[8]), "RightTrigger");
    SET((*(Names*)&DAT_004ddb10[9]), "Black");
    SET((*(Names*)&DAT_004ddb10[10]), "White");
    SET((*(Names*)&DAT_004ddb68[0]), "LeftStickX");
    SET((*(Names*)&DAT_004ddb68[1]), "DPadRight");
    SET((*(Names*)&DAT_004ddb68[2]), "DPadLeft");
    SET((*(Names*)&DAT_004ddb68[3]), "LeftStickY");
    SET((*(Names*)&DAT_004ddb68[4]), "DPadUp");
    SET((*(Names*)&DAT_004ddb68[5]), "DPadDown");
    SET((*(Names*)&DAT_004ddb68[6]), "RightStickX");
    SET((*(Names*)&DAT_004ddb68[7]), "");
    SET((*(Names*)&DAT_004ddb68[8]), "");
    SET((*(Names*)&DAT_004ddb68[9]), "RightStickY");
    SET((*(Names*)&DAT_004ddb68[10]), "");
    SET((*(Names*)&DAT_004ddb68[11]), "");
    SET((*(Names*)&DAT_004dda48[0]), "X");
    SET((*(Names*)&DAT_004dda48[1]), "Y");
    SET((*(Names*)&DAT_004dda48[2]), "B");
    SET((*(Names*)&DAT_004dda48[3]), "A");
    (*(Names*)&DAT_004dda48[4]).FUN_000b1020(2);
    SET((*(Names*)&DAT_004dda48[4]), "Black");
    if ((*(Names*)&DAT_004dda48[4]).count <= 0)
        (*(Names*)&DAT_004dda48[4]).FUN_000b1020(1);
    FUN_00267830((*(Names*)&DAT_004dda48[4]).data + 32, "White", 32);
    SET((*(Names*)&DAT_004dda48[5]), "RightTrigger");
    SET((*(Names*)&DAT_004dda48[6]), "LeftTrigger");
    SET((*(Names*)&DAT_004dda48[7]), "Start");
    SET((*(Names*)&DAT_004dda48[8]), "Back");
    SET((*(Names*)&DAT_004dda48[9]), "LeftThumb");
    SET((*(Names*)&DAT_004dda48[10]), "RightThumb");
    SET((*(Names*)&DAT_004dda48[11]), "LeftJoystick");
    SET((*(Names*)&DAT_004dda48[12]), "RightJoystick");
    SET((*(Names*)&DAT_004ddab0[0]), "LeftStickX");
    if (!DAT_0049caae) {
        SET((*(Names*)&DAT_004ddab0[1]), "DPadRight");
        SET((*(Names*)&DAT_004ddab0[2]), "DPadLeft");
    }
    SET((*(Names*)&DAT_004ddab0[3]), "LeftStickY");
    if (!DAT_0049caae) {
        SET((*(Names*)&DAT_004ddab0[4]), "DPadUp");
        SET((*(Names*)&DAT_004ddab0[5]), "DPadDown");
    }
    SET((*(Names*)&DAT_004ddab0[6]), "RightStickX");
    SET((*(Names*)&DAT_004ddab0[7]), "");
    SET((*(Names*)&DAT_004ddab0[8]), "");
    SET((*(Names*)&DAT_004ddab0[9]), "RightStickY");
    SET((*(Names*)&DAT_004ddab0[10]), "");
    SET((*(Names*)&DAT_004ddab0[11]), "");
}
} // namespace fn_000b10d0
#undef SET

namespace fn_f3919bbe {

// 0x000b1920 FUN_000b1920 (83 B): matches/0x000b1920.cpp
// sym: ?Set@Obj@fn_f3919bbe@@QAE_NHPBXH@Z
bool Obj::Set(int index, const void* src, int slot) {
    if (index < 0 || index >= 11)
        return false;
    Names* e = &f_110[index];
    if (e->count <= 0)
        ((owners::StringTable_b1020 *)e)->FUN_000b1020(1);
    CopyBytes(e->data + slot * 32, src, 32);
    f_0c = 1;
    return true;
}

} // namespace fn_f3919bbe

// 0x000b1980 FUN_000b1980 (83 B): matches/0x000b1980.cpp [wrapped: merged class would differ: Grid: field cells: Field(+0x78 Cell [100] cells) vs Field(+0x78 Cell [100] cells)]
// sym: ?Put@Grid@fn_000b1980@@QAEDHHHH@Z
namespace fn_000b1980 {
class Grid : public ::CPhysicalController {   // (gfx6, C15) the button pairs f_168 [2][2][3]
  public:
    char Put(int x, int y, int z, int v);
};
char Grid::Put(int x, int y, int z, int v) {
    if (x < 0 || x >= 2 || y < 0 || y >= 2 || z < 0 || z >= 3)
        return 0;
    ((owners::Target_b10a0 *)&f_168[z + 3 * (y + 2 * x)])->FUN_000b10a0(0, (const void *)(hulk_uintptr)(int)v);
    f_0c = 1;
    return 1;
}
} // namespace fn_000b1980


// 0x000b19e0 FUN_000b19e0 (83 B): matches/0x000b19e0.cpp [wrapped: conflict: Obj]
// sym: ?Copy@Obj@fn_000b19e0@@QAE_NHPBXH@Z
namespace fn_000b19e0 {
extern "C++" __declspec(nothrow) void CopyBytes_00267830(void*, const void*, unsigned int);
class Obj : public ::CPhysicalController {   // (gfx6, C15) the stick names f_290
  public:
    bool Copy(int index, const void* src, int slot);
};
bool Obj::Copy(int index, const void* src, int slot) {
    if (index < 0 || index >= 13)
        return false;
    Names* e = &f_290[index];
    if (e->count <= 0)
        ((owners::StringTable_b1020 *)e)->FUN_000b1020(1);
    CopyBytes_00267830(e->data + slot * 32, src, 32);
    f_0c = 1;
    return true;
}
} // namespace fn_000b19e0


// 0x000b1a40 FUN_000b1a40 (86 B): matches/0x000b1a40.cpp [wrapped: merged class would differ: Obj: field cells: Field(+0x2f8 Cell [12] cells) vs Field(+0x2f8 Cell [12] cells)]
// sym: ?Fn@Obj@fn_000b1a40@@QAE_NHHHH@Z
namespace fn_000b1a40 {
class Obj : public ::CPhysicalController {   // (gfx6, C15) the stick pairs f_2f8 [2][2][3]
  public:
    bool Fn(int a, int b, int c, int d);
};
bool Obj::Fn(int a, int b, int c, int d) {
    if (a < 0 || a >= 2 || b < 0 || b >= 2 || c < 0 || c >= 3)
        return false;
    ((owners::Target_b10a0 *)&f_2f8[(a * 2 + b) * 3 + c])->FUN_000b10a0(0, (const void *)(hulk_uintptr)(int)d);
    f_0c = 1;
    return true;
}
} // namespace fn_000b1a40

namespace fn_f3919bbe {

// 0x000b1aa0 FUN_000b1aa0 (230 B): equivalent/0x000b1aa0.cpp
// sym: ?Update@Object@fn_f3919bbe@@QAEXXZ @f68ff6a6b6d9 @w14b8e1cb58a6 @v7e4774c7903a
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000b1aa0 @ 0x000b1aa0
void Object::Update() {
 if (f_0c) { FUN_000b0db0(); f_0c=0; }
 Manager_b1aa0* manager=FUN_002684b0();
 if (!manager) return;
 Resource_b1aa0* found=0;
 if (f_14[0]!=0) found=manager->Find(f_14);
 if (!found) { FUN_000b0db0(); return; }
 if (found==(Resource_b1aa0*)f_10) return;
 if (f_10) FUN_000b0db0();
 f_10=found;
 found->AddRef();
 FUN_000b0a50((Resource_b1aa0*)f_10,11,2,f_110,f_168,&f_480,f_358,f_384,&f_48c);
 FUN_000b0a50((Resource_b1aa0*)f_10,13,2,f_290,f_2f8,&f_478,f_3e4,f_418,&f_488);
}

} // namespace fn_f3919bbe

// 0x000b1b90 FUN_000b1b90 (256 B): equivalent/0x000b1b90.cpp [wrapped: conflict: Object]
// sym: ?FUN_000b1b90@Object@fn_000b1b90@@QAEXPAUResult_b1b90@2@@Z @67e7a3c0d8a5 @w6733cdd81dbe @vc4710609911d
namespace fn_000b1b90 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000b1b90 @ 0x000b1b90
struct Item_b1b90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual float value(int);
};
struct Collection_b1b90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual int count(const char*); virtual Item_b1b90* get(const char*,int);
};
struct Result_b1b90 { float value; int state; Item_b1b90* item; };
struct Object : public ::CPhysicalController {   // (gfx6, C15) the device f_10, the state f_54, the range f_490 / f_494
 Collection_b1b90* collection() { return (Collection_b1b90*)f_10; }
 void FUN_000b1b90(Result_b1b90* result);
};
void Object::FUN_000b1b90(Result_b1b90* result) {
 if(f_54==2 || !f_10) return;
 result->value=0.0f;
 int n=collection()->count("Button");
 Item_b1b90* selected=0;
 float ratio=0.0f;
 for(int i=0;i<n;++i) {
  Item_b1b90* item=collection()->get("Button",i);
  if(!item) ratio=0.0f;
  else {
   float value=item->value(0);
   if(value<f_490) ratio=0.0f;
   else if(value>f_494) ratio=1.0f;
   else ratio=(value-f_490)/(f_494-f_490);
  }
  union { float f; unsigned int u; } magnitude;
  magnitude.f=ratio; magnitude.u &= 0x7fffffff;
  if(!(magnitude.f<=1e-05f)) { selected=item; break; }
 }
 result->value=ratio;
 result->item=selected;
 result->state=f_54;
}
} // namespace fn_000b1b90


// 0x000b1c90 FUN_000b1c90 (286 B): equivalent/0x000b1c90.cpp [wrapped: conflict: sControllerInputPointCallback]
// sym: ?FUN_000b1c90@Controller_b1c90@fn_000b1c90@@QAEXPAUState_b1c90@2@H@Z @e0b81059dd09 @wdcb9fc5360cd @v53c2857d8b19
inline void* operator new(size_t, void* p) { return p; }
namespace fn_000b1c90 {
// STATUS: equivalent (tools/equiv.py level 3: 1691 inputs, branch coverage 22/22)
// FUN_000b1c90 @ 0x000b1c90
extern "C" void* __cdecl FUN_0008d710(unsigned size, int alignment);
extern "C" void* __cdecl FUN_0008d750(hulk_intptr size, int heap);   // (sweep-allocsize) as defined (unk_08ceb0.cpp): the C++ spelling did not bind natively

struct Controller_b1c90;
struct State_b1c90 { int first; int middle; int last; };
struct sControllerInputPointCallback;
struct Point_b1c90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6();
 virtual void attach(sControllerInputPointCallback*, int);
};
struct Device_b1c90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
 virtual int count(const char*);
 virtual Point_b1c90* point(const char*, int);
};
struct sControllerInputPointCallback {
 virtual void callback_000b0f20(int, float);
 Point_b1c90* point;
 Controller_b1c90* controller;
 State_b1c90* state;
};
struct Controller_b1c90 : public ::CPhysicalController {   // (gfx6, C15) the device f_10, the id f_54, the callbacks f_4a8
 Device_b1c90* device() { return (Device_b1c90*)f_10; }
 sControllerInputPointCallback**& callbacks() { return *(sControllerInputPointCallback***)&f_4a8; }
 void FUN_000b1c90(State_b1c90*, int);
};
void Controller_b1c90::FUN_000b1c90(State_b1c90* state, int requested) {
 if (f_54 != requested || !f_10) return;
 state->first = 0;
 state->last = 0;
 int n = device()->count("Button");
 if (callbacks()) {
  for (int i=0; i<n; ++i) {
   if (callbacks()[i]) {
    ::operator delete(callbacks()[i]);
    callbacks()[i] = 0;
   }
  }
 }
 if (callbacks()) {
  ::operator delete(callbacks());
  callbacks() = 0;
 }
 callbacks() = (sControllerInputPointCallback**)FUN_0008d750((unsigned)n*sizeof(sControllerInputPointCallback*),4);
 for (int i=0; i<n; ++i) {
  Point_b1c90* p = device()->point("Button",i);
  if (p) {
   void* storage = FUN_0008d710(sizeof(sControllerInputPointCallback),4);
   sControllerInputPointCallback* c = 0;
   if (storage) {
    c = new(storage) sControllerInputPointCallback;
    c->point = p;
    c->controller = this;
    c->state = state;
   }
   callbacks()[i] = c;
   p->attach(callbacks()[i],0);
  }
 }
}
} // namespace fn_000b1c90


// 0x000b1db0 FUN_000b1db0 (688 B): equivalent/0x000b1db0.cpp [wrapped: conflict: CPhysicalController; DAT_003f335c]
// sym: ?FUN_000b1db0@Controller_b1db0@fn_000b1db0@@QAEXXZ @e86fcf59f4e3 @w1ee6bc5e63c8 @vecf73a2b1f56
namespace fn_000b1db0 {
// STATUS: equivalent (tools/equiv.py level 3: 219 inputs, branch coverage 52/56, incomplete)
// FUN_000b1db0 @ 0x000b1db0
extern float DAT_003f335c;
void __cdecl FUN_00267830(char *dst, const char *src, int n);

struct Str {
    int count;
    char *data;
    void FUN_000b1020(int n);
};

class Controller_b1db0 : public ::CPhysicalController {   // (gfx6, C15) gen's record: Str is its Names
public:
    void FUN_000b1db0();
};

void Controller_b1db0::FUN_000b1db0()
{
    Str *srcs[4];
    Str *dsts[4];
    int counts[4];
    srcs[0] = (Str *)f_58; dsts[0] = (Str *)f_110; counts[0] = 11;
    srcs[1] = (Str *)f_b0; dsts[1] = (Str *)f_168; counts[1] = 12;
    srcs[2] = (Str *)f_1c8; dsts[2] = (Str *)f_290; counts[2] = 13;
    srcs[3] = (Str *)f_230; dsts[3] = (Str *)f_2f8; counts[3] = 12;
    for (int g = 0; g < 4; g++) {
        Str *s = srcs[g];
        Str *d = dsts[g];
        for (int k = 0; k < counts[g]; k++, s++, d++) {
            int n = s->count;
            d->FUN_000b1020(n);
            int off = 0;
            for (int i = 0; i < n; i++, off += 0x20) {
                const char *from;
                if (off >= 0 && i < s->count)
                    from = s->data + off;
                else
                    from = (const char *)&DAT_003f335c;
                if (d->count <= 0)
                    d->FUN_000b1020(1);
                FUN_00267830(d->data + off, from, 0x20);
            }
        }
    }
}
} // namespace fn_000b1db0


// 0x000b2060 FUN_000b2060 (733 B): equivalent/0x000b2060.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_000b2060@Mapper_b2060@fn_000b2060@@QAEXH@Z @69c4d7084ab8 @wa98f63587aa4 @vf643fff0332b
namespace fn_000b2060 {
// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 40/40)
// FUN_000b2060 @ 0x000b2060
struct Str_b2060 {
    int cap;
    char *buf;
};

extern void __cdecl FUN_00267830(char *dst, const char *src, int n);

class Mapper_b2060 : public ::CPhysicalController {   // (gfx6, C15) the stick names f_290 (the buttons 0..3, the
public:                                                // triggers 5 and 6), the mode f_4ac
    void assign(Str_b2060 *s, const char *v);
    void FUN_000b2060(int newMode);
};

void Mapper_b2060::assign(Str_b2060 *s, const char *v)
{
    if (!(s->cap > 0))
        ((owners::StringTable_b1020 *)s)->FUN_000b1020(1);
    FUN_00267830(s->buf, v, 0x20);
    f_0c = 1;
}

void Mapper_b2060::FUN_000b2060(int newMode)
{
    if (newMode == f_4ac)
        return;
    f_4ac = newMode;
    if (newMode == 1) {
        assign((Str_b2060 *)&f_290[0], "X");
        assign((Str_b2060 *)&f_290[1], "Y");
        assign((Str_b2060 *)&f_290[2], "B");
        assign((Str_b2060 *)&f_290[3], "A");
        assign((Str_b2060 *)&f_290[5], "RightTrigger");
        assign((Str_b2060 *)&f_290[6], "LeftTrigger");
    } else if (newMode == 2) {
        assign((Str_b2060 *)&f_290[0], "X");
        assign((Str_b2060 *)&f_290[1], "Y");
        assign((Str_b2060 *)&f_290[2], "B");
        assign((Str_b2060 *)&f_290[3], "A");
        assign((Str_b2060 *)&f_290[5], "LeftTrigger");
        assign((Str_b2060 *)&f_290[6], "RightTrigger");
    } else if (newMode == 3) {
        assign((Str_b2060 *)&f_290[0], "A");
        assign((Str_b2060 *)&f_290[1], "Y");
        assign((Str_b2060 *)&f_290[2], "X");
        assign((Str_b2060 *)&f_290[3], "B");
        assign((Str_b2060 *)&f_290[5], "RightTrigger");
        assign((Str_b2060 *)&f_290[6], "LeftTrigger");
    }
}
} // namespace fn_000b2060


// 0x000b23c0 FUN_000b23c0 (625 B): equivalent/0x000b23c0.cpp [wrapped: conflict: CPhysicalController]
// sym: ?Construct@Controller_b23c0@fn_000b23c0@@QAEPAV12@H@Z @6ba154cf619b @w31754a5916bb @v9d5a3e265e67
namespace fn_000b23c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_000b23c0 @ 0x000b23c0
extern "C" int __cdecl _sprintf(char *, const char *, ...);
void __cdecl FUN_00267830(char *dst, const char *src, int n);
extern "C" void* __cdecl FUN_0008d750(hulk_intptr size, int heap);   // (sweep-allocsize) as defined (unk_08ceb0.cpp): the C++ spelling did not bind natively

// (gfx6, C15) gen's record, whose words the constructor writes: an explicit function storing the game's vftable by
// address (a local polymorphic view's own vftable is the 64-bit link's stub). The name lists' cells are constructed by
// 0x000b06e0 ({count, data}: sizeof is pointer-sized natively), the 4-point nodes allocated by their native size.
extern "C" char DAT_00406088[];   // CPhysicalController's vftable

struct Cell_b23c0 {
    int a;
    char *b;
    void FUN_000b06e0();
};

void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Cell_b23c0::*ctor)());

struct Str_b23c0 {
    int cap;
    char *text;
    void FUN_000b1020(int n);
};

class Controller_b23c0 : public ::CPhysicalController {
public:
    Controller_b23c0 *Construct(int arg);
};

Controller_b23c0 *Controller_b23c0::Construct(int arg)
{
    f_08 = arg;
    f_04 = 0;
    *(void **)this = DAT_00406088;
    f_0c = 1;
    f_0d = 0;
    f_10 = 0;
    f_54 = 3;
    int i;
    int j;
    for (i = 0; i < 11; i++) {
        f_58[i].count = 0;
        f_58[i].data = 0;
    }
    for (j = 0; j < 2; j++)
        FUN_00011520(&f_b0[j * 6], sizeof(Cell_b23c0), 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 11; i++) {
        f_110[i].count = 0;
        f_110[i].data = 0;
    }
    for (j = 0; j < 2; j++)
        FUN_00011520(&f_168[j * 6], sizeof(Cell_b23c0), 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 13; i++) {
        f_1c8[i].count = 0;
        f_1c8[i].data = 0;
    }
    for (j = 0; j < 2; j++)
        FUN_00011520(&f_230[j * 6], sizeof(Cell_b23c0), 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 13; i++) {
        f_290[i].count = 0;
        f_290[i].data = 0;
    }
    for (j = 0; j < 2; j++)
        FUN_00011520(&f_2f8[j * 6], sizeof(Cell_b23c0), 6, &Cell_b23c0::FUN_000b06e0);
    f_478.count = 0;
    f_478.data = 0;
    f_480.count = 0;
    f_480.data = 0;
    f_488 = 0;
    f_48c = 0;
    f_4a8 = 0;
    f_4ac = 1;
    _sprintf(f_14, "%s", "");
    for (i = 0; i < 11; i++) {
        f_358[i] = 0;
        f_358[i] = (void **)FUN_0008d750(4 * sizeof(void *), 4);
        f_358[i][0] = 0;
        f_358[i][1] = 0;
        f_358[i][2] = 0;
        f_358[i][3] = 0;
    }
    for (i = 0; i < 13; i++) {
        f_3e4[i] = 0;
        f_3e4[i] = (void **)FUN_0008d750(4 * sizeof(void *), 4);
        f_3e4[i][0] = 0;
        f_3e4[i][1] = 0;
        f_3e4[i][2] = 0;
        f_3e4[i][3] = 0;
    }
    for (j = 0; j < 2; j++)
        for (i = 0; i < 6; i++)
            (&f_384[j].point[0][0])[i] = 0;
    for (j = 0; j < 2; j++)
        for (i = 0; i < 6; i++)
            (&f_418[j].point[0][0])[i] = 0;
    f_488 = 0;
    f_48c = 0;
    if (f_478.count <= 0)
        ((Str_b23c0 *)&f_478)->FUN_000b1020(1);
    FUN_00267830(f_478.data, "", 0x20);
    if (f_480.count <= 0)
        ((Str_b23c0 *)&f_480)->FUN_000b1020(1);
    FUN_00267830(f_480.data, "", 0x20);
    return this;
}
} // namespace fn_000b23c0


// 0x000b2640 FUN_000b2640 (454 B): equivalent/0x000b2640.cpp [wrapped: conflict: CPhysicalController; FUN_0008d330; core::IRefCount]
// sym: ?Destroy@Controller_b2640@fn_000b2640@@QAEXXZ @660b69db95fe @w890f570c4b70 @ve9c021455724
namespace fn_000b2640 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_000b2640 @ 0x000b2640
__declspec(nothrow) void __stdcall FUN_000b0ff0(void*);
__declspec(nothrow) void __stdcall FUN_00013420(void*, int, int, void (__stdcall *)(void*));
// (gfx6, C15) gen's record; an explicit function storing the game's vftables by address (CPhysicalController's,
// then core::IRefCount's at the end), the cells' destructor 0x000b0ff0 by their native size
extern "C" char DAT_00406088[];   // CPhysicalController's vftable
struct Buffer_b2640 { unsigned count; void* data; };
struct Controller_b2640 : public ::CPhysicalController {
 __declspec(nothrow) void FUN_000b0db0(); void Destroy();
};
void Controller_b2640::Destroy() {
 *(void**)this = DAT_00406088;
 FUN_000b0db0(); int i;
 for(i=0;i<11;++i) if(f_358[i]) { ::operator delete(f_358[i]); f_358[i]=0; }
 for(i=0;i<13;++i) if(f_3e4[i]) { ::operator delete(f_3e4[i]); f_3e4[i]=0; }
 if(f_480.data) { ::operator delete(f_480.data); f_480.count=0; f_480.data=0; }
 if(f_478.data) { ::operator delete(f_478.data); f_478.count=0; f_478.data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&f_2f8[i*6],sizeof(Buffer_b2640),6,FUN_000b0ff0);
 for(i=12;i>=0;--i) if(f_290[i].data) { ::operator delete(f_290[i].data); f_290[i].count=0; f_290[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&f_230[i*6],sizeof(Buffer_b2640),6,FUN_000b0ff0);
 for(i=12;i>=0;--i) if(f_1c8[i].data) { ::operator delete(f_1c8[i].data); f_1c8[i].count=0; f_1c8[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&f_168[i*6],sizeof(Buffer_b2640),6,FUN_000b0ff0);
 for(i=10;i>=0;--i) if(f_110[i].data) { ::operator delete(f_110[i].data); f_110[i].count=0; f_110[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&f_b0[i*6],sizeof(Buffer_b2640),6,FUN_000b0ff0);
 for(i=10;i>=0;--i) if(f_58[i].data) { ::operator delete(f_58[i].data); f_58[i].count=0; f_58[i].data=0; }
 *(void**)this = DAT_003f6098;
}
} // namespace fn_000b2640


// 0x000b2810 FUN_000b2810 (2209 B): equivalent/0x000b2810.cpp [wrapped: conflict: FUN_00267830]
// sym: ?FUN_000b2810@Pad_b2810@fn_000b2810@@QAEXXZ @11c08f27a541 @w6cc0851fec2d @vb9cab3477f47
namespace fn_000b2810 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 102/102)
// FUN_000b2810 @ 0x000b2810

extern "C" char *__cdecl FUN_00267830(char *dst, const char *src, int n);

class Pad_b2810 : public ::CPhysicalController {   // (gfx6, C15) the name lists f_58 / f_b0 (buttons) and f_1c8 /
public:                                             // f_230 (sticks), the dead zones f_490..f_4a4
    void FUN_000b1db0();
    void FUN_000b2810();
};

void Pad_b2810::FUN_000b2810()
{
    f_0c = 1;
    f_490 = 0.2f;
    f_494 = 0.8f;
    f_498 = 0.35f;
    f_49c = 0.8f;
    f_4a0 = 0.8f;
    f_4a4 = 1.0f;
    if (!(f_58[0].count > 0))
        ((owners::StringTable_b1020 *)&f_58[0])->FUN_000b1020(1);
    FUN_00267830(f_58[0].data, "A", 0x20);
    if (!(f_58[1].count > 0))
        ((owners::StringTable_b1020 *)&f_58[1])->FUN_000b1020(1);
    FUN_00267830(f_58[1].data, "B", 0x20);
    if (!(f_58[2].count > 0))
        ((owners::StringTable_b1020 *)&f_58[2])->FUN_000b1020(1);
    FUN_00267830(f_58[2].data, "X", 0x20);
    if (!(f_58[3].count > 0))
        ((owners::StringTable_b1020 *)&f_58[3])->FUN_000b1020(1);
    FUN_00267830(f_58[3].data, "Y", 0x20);
    if (!(f_58[4].count > 0))
        ((owners::StringTable_b1020 *)&f_58[4])->FUN_000b1020(1);
    FUN_00267830(f_58[4].data, "Start", 0x20);
    if (!(f_58[5].count > 0))
        ((owners::StringTable_b1020 *)&f_58[5])->FUN_000b1020(1);
    FUN_00267830(f_58[5].data, "Back", 0x20);
    if (!(f_58[6].count > 0))
        ((owners::StringTable_b1020 *)&f_58[6])->FUN_000b1020(1);
    FUN_00267830(f_58[6].data, "Back", 0x20);
    if (!(f_58[7].count > 0))
        ((owners::StringTable_b1020 *)&f_58[7])->FUN_000b1020(1);
    FUN_00267830(f_58[7].data, "LeftTrigger", 0x20);
    if (!(f_58[8].count > 0))
        ((owners::StringTable_b1020 *)&f_58[8])->FUN_000b1020(1);
    FUN_00267830(f_58[8].data, "RightTrigger", 0x20);
    if (!(f_58[9].count > 0))
        ((owners::StringTable_b1020 *)&f_58[9])->FUN_000b1020(1);
    FUN_00267830(f_58[9].data, "Black", 0x20);
    if (!(f_58[10].count > 0))
        ((owners::StringTable_b1020 *)&f_58[10])->FUN_000b1020(1);
    FUN_00267830(f_58[10].data, "White", 0x20);
    if (!(f_b0[0].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[0])->FUN_000b1020(1);
    FUN_00267830(f_b0[0].data, "LeftStickX", 0x20);
    if (!(f_b0[1].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[1])->FUN_000b1020(1);
    FUN_00267830(f_b0[1].data, "DPadRight", 0x20);
    if (!(f_b0[2].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[2])->FUN_000b1020(1);
    FUN_00267830(f_b0[2].data, "DPadLeft", 0x20);
    if (!(f_b0[3].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[3])->FUN_000b1020(1);
    FUN_00267830(f_b0[3].data, "LeftStickY", 0x20);
    if (!(f_b0[4].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[4])->FUN_000b1020(1);
    FUN_00267830(f_b0[4].data, "DPadUp", 0x20);
    if (!(f_b0[5].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[5])->FUN_000b1020(1);
    FUN_00267830(f_b0[5].data, "DPadDown", 0x20);
    if (!(f_b0[6].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[6])->FUN_000b1020(1);
    FUN_00267830(f_b0[6].data, "RightStickX", 0x20);
    if (!(f_b0[7].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[7])->FUN_000b1020(1);
    FUN_00267830(f_b0[7].data, "", 0x20);
    if (!(f_b0[8].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[8])->FUN_000b1020(1);
    FUN_00267830(f_b0[8].data, "", 0x20);
    if (!(f_b0[9].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[9])->FUN_000b1020(1);
    FUN_00267830(f_b0[9].data, "RightStickY", 0x20);
    if (!(f_b0[10].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[10])->FUN_000b1020(1);
    FUN_00267830(f_b0[10].data, "", 0x20);
    if (!(f_b0[11].count > 0))
        ((owners::StringTable_b1020 *)&f_b0[11])->FUN_000b1020(1);
    FUN_00267830(f_b0[11].data, "", 0x20);
    if (!(f_1c8[0].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[0])->FUN_000b1020(1);
    FUN_00267830(f_1c8[0].data, "X", 0x20);
    if (!(f_1c8[1].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[1])->FUN_000b1020(1);
    FUN_00267830(f_1c8[1].data, "Y", 0x20);
    if (!(f_1c8[2].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[2])->FUN_000b1020(1);
    FUN_00267830(f_1c8[2].data, "B", 0x20);
    if (!(f_1c8[3].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[3])->FUN_000b1020(1);
    FUN_00267830(f_1c8[3].data, "A", 0x20);
    ((owners::StringTable_b1020 *)&f_1c8[4])->FUN_000b1020(2);
    if (!(f_1c8[4].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[4])->FUN_000b1020(1);
    FUN_00267830(f_1c8[4].data, "Black", 0x20);
    if (!(f_1c8[4].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[4])->FUN_000b1020(1);
    FUN_00267830(f_1c8[4].data + 0x20, "White", 0x20);
    if (!(f_1c8[5].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[5])->FUN_000b1020(1);
    FUN_00267830(f_1c8[5].data, "RightTrigger", 0x20);
    if (!(f_1c8[6].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[6])->FUN_000b1020(1);
    FUN_00267830(f_1c8[6].data, "LeftTrigger", 0x20);
    if (!(f_1c8[7].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[7])->FUN_000b1020(1);
    FUN_00267830(f_1c8[7].data, "Start", 0x20);
    if (!(f_1c8[8].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[8])->FUN_000b1020(1);
    FUN_00267830(f_1c8[8].data, "Back", 0x20);
    if (!(f_1c8[9].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[9])->FUN_000b1020(1);
    FUN_00267830(f_1c8[9].data, "LeftThumb", 0x20);
    if (!(f_1c8[10].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[10])->FUN_000b1020(1);
    FUN_00267830(f_1c8[10].data, "RightThumb", 0x20);
    if (!(f_1c8[11].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[11])->FUN_000b1020(1);
    FUN_00267830(f_1c8[11].data, "LeftJoystick", 0x20);
    if (!(f_1c8[12].count > 0))
        ((owners::StringTable_b1020 *)&f_1c8[12])->FUN_000b1020(1);
    FUN_00267830(f_1c8[12].data, "RightJoystick", 0x20);
    if (!(f_230[0].count > 0))
        ((owners::StringTable_b1020 *)&f_230[0])->FUN_000b1020(1);
    FUN_00267830(f_230[0].data, "LeftStickX", 0x20);
    if (!(*(char*)&DAT_0049caae)) {
        if (!(f_230[1].count > 0))
            ((owners::StringTable_b1020 *)&f_230[1])->FUN_000b1020(1);
        FUN_00267830(f_230[1].data, "DPadRight", 0x20);
        if (!(f_230[2].count > 0))
            ((owners::StringTable_b1020 *)&f_230[2])->FUN_000b1020(1);
        FUN_00267830(f_230[2].data, "DPadLeft", 0x20);
    }
    if (!(f_230[3].count > 0))
        ((owners::StringTable_b1020 *)&f_230[3])->FUN_000b1020(1);
    FUN_00267830(f_230[3].data, "LeftStickY", 0x20);
    if (!(*(char*)&DAT_0049caae)) {
        if (!(f_230[4].count > 0))
            ((owners::StringTable_b1020 *)&f_230[4])->FUN_000b1020(1);
        FUN_00267830(f_230[4].data, "DPadUp", 0x20);
        if (!(f_230[5].count > 0))
            ((owners::StringTable_b1020 *)&f_230[5])->FUN_000b1020(1);
        FUN_00267830(f_230[5].data, "DPadDown", 0x20);
    }
    if (!(f_230[6].count > 0))
        ((owners::StringTable_b1020 *)&f_230[6])->FUN_000b1020(1);
    FUN_00267830(f_230[6].data, "RightStickX", 0x20);
    if (!(f_230[7].count > 0))
        ((owners::StringTable_b1020 *)&f_230[7])->FUN_000b1020(1);
    FUN_00267830(f_230[7].data, "", 0x20);
    if (!(f_230[8].count > 0))
        ((owners::StringTable_b1020 *)&f_230[8])->FUN_000b1020(1);
    FUN_00267830(f_230[8].data, "", 0x20);
    if (!(f_230[9].count > 0))
        ((owners::StringTable_b1020 *)&f_230[9])->FUN_000b1020(1);
    FUN_00267830(f_230[9].data, "RightStickY", 0x20);
    if (!(f_230[10].count > 0))
        ((owners::StringTable_b1020 *)&f_230[10])->FUN_000b1020(1);
    FUN_00267830(f_230[10].data, "", 0x20);
    if (!(f_230[11].count > 0))
        ((owners::StringTable_b1020 *)&f_230[11])->FUN_000b1020(1);
    FUN_00267830(f_230[11].data, "", 0x20);
    FUN_000b1db0();
}
} // namespace fn_000b2810

namespace fn_f3919bbe {

// 0x000b30c0 FUN_000b30c0 (1099 B): equivalent/0x000b30c0.cpp
// sym: ?FUN_000b30c0@Blender_b30c0@fn_f3919bbe@@QAEXHHPAUNames@CPhysicalController@@PAPAPAVItem_b30c0@2@PAUAxes@4@PAV52@PAM44@Z @e4b63039c60e @wf7449a67c741 @v8ded9668fe9e
// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 77/78, incomplete; Wine build 117 inputs, 77/78)
// FUN_000b30c0 @ 0x000b30c0
void Blender_b30c0::FUN_000b30c0(int groups, int pairs, Names *counts, Item_b30c0 ***items, Axes *cells, Item_b30c0 *single,
                            float *out1, float *out2, float *out3)
{
    int i;
    for (i = 0; i < groups; i++) {
        float t = 0.0f;
        int n = counts[i].count;
        for (int j = 0; j < n; j++) {
            Item_b30c0 *it = items[i][j];
            if (it == 0) {
                t = 0.0f;
            } else {
                float v = it->v9(0);
                t = Normalise(this, v);
            }
            FS_b30c0 ad;
            ad.f = t;
            ad.u &= 0x7fffffff;
            if (!(ad.f <= 1e-5f))
                break;
        }
        out1[i] = t;
    }

    float t6;
    if (single == 0) {
        t6 = 0.0f;
    } else {
        float v = single->v9(0);
        t6 = Normalise(this, v);
    }
    float scale = 1.0f;
    FS_b30c0 a6;
    a6.f = t6;
    a6.u &= 0x7fffffff;
    if (!(a6.f <= 1e-5f))
        scale = 0.5f;

    if (f_54 == 2 && out3 != 0) {
        for (int p = 0; p < pairs; p++) {
            for (int e = 0; e < 2; e++) {
                float acc = 0.0f;
                for (int k = 0; k < 3; k++) {
                    Item_b30c0 *it = (Item_b30c0 *)cells[p].point[e][k];
                    if (it != 0)
                        acc = it->v9(0) + acc;
                }
                if (p == 0) {
                    if (e == 0)
                        out3[0] = acc;
                    else if (e == 1)
                        out3[1] = acc;
                }
            }
        }
        return;
    }

    {
        float *dst = out2;
        for (int p = 0; p < pairs; p++) {
            for (int e = 0; e < 2; e++) {
                float sum = 0.0f;
                for (int k = 0; k < 3; k++) {
                    Item_b30c0 *it = (Item_b30c0 *)cells[p].point[e][k];
                    if (it != 0) {
                        float w = it->v9(0);
                        int m = cells[p].button[e][k];
                        if (m == 0)
                            sum = w * ((float*)&DAT_00406094)[k] + sum;
                        else if (m == 1)
                            sum = Normalise(this, w) * ((float*)&DAT_00406094)[k] + sum;
                    }
                }
                *dst = sum;
                dst++;
            }
        }
    }

    float range = f_49c - f_498;
    for (int p = 0; p < pairs; p++) {
        float *xy = out2 + p * 2;
        FS_b30c0 ax;
        ax.f = xy[0];
        ax.u &= 0x7fffffff;
        FS_b30c0 ay;
        ay.f = xy[1];
        ay.u &= 0x7fffffff;
        // x87: the original computes the ratio once and keeps it unrounded in st(1) for both products
        hulk_freg r = PickRatio(this, ax.f, ay.f, range);
        xy[0] = scale * r * xy[0];
        xy[1] = r * xy[1] * scale;
    }
}


// 0x000b3510 FUN_000b3510 (159 B): matches/0x000b3510.cpp
// sym: ?Func@ThisClass@fn_f3919bbe@@QAEXPAUParam2@2@PAUParam3@2@@Z
void ThisClass::Func(Param2* p2, Param3* p3) {
    if (f_10) {
        Out_b3510 out = {0, 0};
        FUN_000b30c0(0xB, 2, (void*)f_110, (void*)f_358, (void*)f_384, f_48c, p2,
                     (void*)p2->field_2C, &out);
        p2->field_3C = out.a;
        p2->field_40 = out.b;
        FUN_000b30c0(0xD, 2, (void*)f_290, (void*)f_3e4, (void*)f_418, f_488, p3,
                     (void*)p3->field_34, 0);
    }
}

} // namespace fn_f3919bbe

// 0x000b35b0 CPhysicalController::vfunc_2 (30 B): matches/0x000b35b0.cpp
// sym: ?vfunc_2@CPhysicalController_b35b0@fn_000b35b0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `CPhysicalController::~CPhysicalController() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x000b2640, then (flags & 1) operator delete.
namespace fn_000b35b0 {
struct CPhysicalController_b35b0 {
    void FUN_000b2640();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* CPhysicalController_b35b0::vfunc_2(unsigned int flags) {
    FUN_000b2640();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_000b35b0
// (x64t21) the destructor itself, which other objects' code references:
CPhysicalController::~CPhysicalController() {}

