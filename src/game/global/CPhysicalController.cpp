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
void __cdecl ReleaseThing_0008d330(uint);
struct Obj_b0ff0 {
    uint a;
    uint b;
    void Clear();
};
void __cdecl thunk_FUN_00267090(void *p);
void *__cdecl FUN_0008d750(int size, int align);
extern "C" int __cdecl FUN_00267760(char *buf, int size, const char *fmt, ...);
extern void Ensure(int);
extern void Copy_00267830(void*, const void*, unsigned int);
struct Elem {
    int n;
    char* p;
};
class Obj {
  public:
    char pad[12];
    char flag;
    char pad2[0x103];
    Elem elems[11];
    bool Set(int index, const void* src, int slot);
};
struct Resource_b1aa0 { virtual void AddRef(); };
struct Manager_b1aa0 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual Resource_b1aa0* Find(const char*); };
extern "C" Manager_b1aa0* __cdecl FUN_002684b0();
extern void __cdecl FUN_000b0a50(Resource_b1aa0*, int, int, void*, void*, void*, void*, void*, void*);
struct Object {
 char pad0[12]; unsigned char dirty; char padD[3]; Resource_b1aa0* resource; char name[252];
 char a110[0x58]; char a168[0x128]; char a290[0x68]; char a2f8[0x60]; char a358[0x2c]; char a384[0x60]; char a3e4[0x34]; char a418[0x60]; char a478[8]; char a480[8]; char a488[4]; char a48c[4];
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
union Cell_b30c0 {
    Item_b30c0 *item;
    int mode;
};
union FS_b30c0 {
    float f;
    unsigned int u;
};
class Blender_b30c0 {
public:
    char pad000[0x54];
    int mode;                        // 0x54
    char pad58[0x490 - 0x58];
    float lo;                        // 0x490
    float hi;                        // 0x494
    float lo2;                       // 0x498
    float hi2;                       // 0x49c

    void FUN_000b30c0(int groups, int pairs, int *counts, Item_b30c0 ***items, Cell_b30c0 *cells, Item_b30c0 *single,
                       float *out1, float *out2, float *out3);
};
static __forceinline hulk_freg Normalise(const Blender_b30c0 *b, float v)
{
    if (v < b->lo)
        return 0.0f;
    if (v > b->hi)
        return 1.0f;
    return (v - b->lo) / (b->hi - b->lo);
}
static __forceinline hulk_freg Ratio(const Blender_b30c0 *b, float a, float range)
{
    if (a < b->lo2)
        return 0.0f;
    if (!(a < b->hi2))
        return 1.0f / a;
    return ((a - b->lo2) / range) / a;
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
struct Param2 {
    char pad[0x2C];
    void* field_2C;
    char pad2[0xC];
    int field_3C;
    int field_40;
};
struct Param3 {
    char pad[0x34];
    void* field_34;
};
struct Out_b3510 {
    int a;
    int b;
};
class ThisClass {
    char pad0[0x10];

  public:
    void* field_10;
    char pad1[0xFC];
    void* field_110;
    char pad2[0x17C];
    void* field_290;
    char pad3[0xC4];
    void* field_358;
    char pad4[0x28];
    void* field_384;
    char pad5[0x5C];
    void* field_3E4;
    char pad6[0x30];
    void* field_418;
    char pad7[0x6C];
    void* field_488;
    void* field_48C;

    void Func(Param2* p2, Param3* p3);
    void FUN_000b30c0(int, int, void*, void*, void*, void*, void*, void*, Out_b3510*);
};


// 0x000b0ff0 FUN_000b0ff0 (34 B): matches/0x000b0ff0.cpp
// sym: ?Clear@Obj_b0ff0@fn_f3919bbe@@QAEXXZ
// Same code shape as 0x000b0710 (propagated; names are from that function)
void Obj_b0ff0::Clear() {
    if (b) {
        ReleaseThing_0008d330(b);
        a = 0;
        b = 0;
    }
}

} // namespace fn_f3919bbe

// 0x000b1020 FUN_000b1020 (117 B): equivalent/0x000b1020.cpp
// sym: ?FUN_000b1020@StringTable_b1020@owners@@QAEXH@Z @4c8b617bc477 @w84a6c5202619
// STATUS: equivalent (tools/equiv.py level 3: 1429 inputs, branch coverage 11/12, incomplete)
// FUN_000b1020 @ 0x000b1020
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void owners::StringTable_b1020::FUN_000b1020(int n)
{
    if (count == n)
        return;
    if (data != 0) {
        thunk_FUN_00267090(data);
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
    SET((*(Names*)&DAT_004ddb10), "A");
    SET((*(Names*)&DAT_004ddb18), "B");
    SET((*(Names*)&DAT_004ddb20), "X");
    SET((*(Names*)&DAT_004ddb28), "Y");
    SET((*(Names*)&DAT_004ddb30), "Start");
    SET((*(Names*)&DAT_004ddb38), "Back");
    SET((*(Names*)&DAT_004ddb40), "Back");
    SET((*(Names*)&DAT_004ddb48), "LeftTrigger");
    SET((*(Names*)&DAT_004ddb50), "RightTrigger");
    SET((*(Names*)&DAT_004ddb58), "Black");
    SET((*(Names*)&DAT_004ddb60), "White");
    SET((*(Names*)&DAT_004ddb68), "LeftStickX");
    SET((*(Names*)&DAT_004ddb70), "DPadRight");
    SET((*(Names*)&DAT_004ddb78), "DPadLeft");
    SET((*(Names*)&DAT_004ddb80), "LeftStickY");
    SET((*(Names*)&DAT_004ddb88), "DPadUp");
    SET((*(Names*)&DAT_004ddb90), "DPadDown");
    SET((*(Names*)&DAT_004ddb98), "RightStickX");
    SET((*(Names*)&DAT_004ddba0), "");
    SET((*(Names*)&DAT_004ddba8), "");
    SET((*(Names*)&DAT_004ddbb0), "RightStickY");
    SET((*(Names*)&DAT_004ddbb8), "");
    SET((*(Names*)&DAT_004ddbc0), "");
    SET((*(Names*)&DAT_004dda48), "X");
    SET((*(Names*)&DAT_004dda50), "Y");
    SET((*(Names*)&DAT_004dda58), "B");
    SET((*(Names*)&DAT_004dda60), "A");
    (*(Names*)&DAT_004dda68).FUN_000b1020(2);
    SET((*(Names*)&DAT_004dda68), "Black");
    if ((*(Names*)&DAT_004dda68).count <= 0)
        (*(Names*)&DAT_004dda68).FUN_000b1020(1);
    FUN_00267830((*(Names*)&DAT_004dda68).data + 32, "White", 32);
    SET((*(Names*)&DAT_004dda70), "RightTrigger");
    SET((*(Names*)&DAT_004dda78), "LeftTrigger");
    SET((*(Names*)&DAT_004dda80), "Start");
    SET((*(Names*)&DAT_004dda88), "Back");
    SET((*(Names*)&DAT_004dda90), "LeftThumb");
    SET((*(Names*)&DAT_004dda98), "RightThumb");
    SET((*(Names*)&DAT_004ddaa0), "LeftJoystick");
    SET((*(Names*)&DAT_004ddaa8), "RightJoystick");
    SET((*(Names*)&DAT_004ddab0), "LeftStickX");
    if (!DAT_0049caae) {
        SET((*(Names*)&DAT_004ddab8), "DPadRight");
        SET((*(Names*)&DAT_004ddac0), "DPadLeft");
    }
    SET((*(Names*)&DAT_004ddac8), "LeftStickY");
    if (!DAT_0049caae) {
        SET((*(Names*)&DAT_004ddad0), "DPadUp");
        SET((*(Names*)&DAT_004ddad8), "DPadDown");
    }
    SET((*(Names*)&DAT_004ddae0), "RightStickX");
    SET((*(Names*)&DAT_004ddae8), "");
    SET((*(Names*)&DAT_004ddaf0), "");
    SET((*(Names*)&DAT_004ddaf8), "RightStickY");
    SET((*(Names*)&DAT_004ddb00), "");
    SET((*(Names*)&DAT_004ddb08), "");
}
} // namespace fn_000b10d0
#undef SET

namespace fn_f3919bbe {

// 0x000b1920 FUN_000b1920 (83 B): matches/0x000b1920.cpp
// sym: ?Set@Obj@fn_f3919bbe@@QAE_NHPBXH@Z
bool Obj::Set(int index, const void* src, int slot) {
    if (index < 0 || index >= 11)
        return false;
    Elem* e = &elems[index];
    if (e->n <= 0)
        ((owners::StringTable_b1020 *)e)->FUN_000b1020(1);
    CopyBytes(e->p + slot * 32, src, 32);
    flag = 1;
    return true;
}

} // namespace fn_f3919bbe

// 0x000b1980 FUN_000b1980 (83 B): matches/0x000b1980.cpp [wrapped: merged class would differ: Grid: field cells: Field(+0x78 Cell [100] cells) vs Field(+0x78 Cell [100] cells)]
// sym: ?Put@Grid@fn_000b1980@@QAEDHHHH@Z
namespace fn_000b1980 {
class Cell {
  public:
    char pad[8];
};
class Grid {
  public:
    char pad[12];
    char dirty;
    char pad2[107];
    Cell cells[100];
    char Put(int x, int y, int z, int v);
};
char Grid::Put(int x, int y, int z, int v) {
    if (x < 0 || x >= 2 || y < 0 || y >= 2 || z < 0 || z >= 3)
        return 0;
    ((owners::Target_b10a0 *)&(cells[(z + 3 * (y + 2 * x + 10))]))->FUN_000b10a0(0, (const void *)(hulk_uintptr)(int)v);
    dirty = 1;
    return 1;
}
} // namespace fn_000b1980


// 0x000b19e0 FUN_000b19e0 (83 B): matches/0x000b19e0.cpp [wrapped: conflict: Obj]
// sym: ?Copy@Obj@fn_000b19e0@@QAE_NHPBXH@Z
namespace fn_000b19e0 {
extern "C++" __declspec(nothrow) void CopyBytes_00267830(void*, const void*, unsigned int);
struct Elem {
    int count;
    char* data;
};
class Obj {
  public:
    char pad[12];
    unsigned char changed;
    char pad2[0x290 - 13];
    Elem elems[13];
    bool Copy(int index, const void* src, int slot);
};
bool Obj::Copy(int index, const void* src, int slot) {
    if (index < 0 || index >= 13)
        return false;
    Elem* e = &elems[index];
    if (e->count <= 0)
        ((owners::StringTable_b1020 *)e)->FUN_000b1020(1);
    CopyBytes_00267830(e->data + slot * 32, src, 32);
    changed = 1;
    return true;
}
} // namespace fn_000b19e0


// 0x000b1a40 FUN_000b1a40 (86 B): matches/0x000b1a40.cpp [wrapped: merged class would differ: Obj: field cells: Field(+0x2f8 Cell [12] cells) vs Field(+0x2f8 Cell [12] cells)]
// sym: ?Fn@Obj@fn_000b1a40@@QAE_NHHHH@Z
namespace fn_000b1a40 {
struct Cell {
    char pad[8];
};
class Obj {
  public:
    char pad[0xc];
    char flag;
    char rest[0x2f8 - 0xd];
    Cell cells[12];
    bool Fn(int a, int b, int c, int d);
};
bool Obj::Fn(int a, int b, int c, int d) {
    if (a < 0 || a >= 2 || b < 0 || b >= 2 || c < 0 || c >= 3)
        return false;
    ((owners::Target_b10a0 *)&(cells[(a * 2 + b) * 3 + c]))->FUN_000b10a0(0, (const void *)(hulk_uintptr)(int)d);
    flag = 1;
    return true;
}
} // namespace fn_000b1a40

namespace fn_f3919bbe {

// 0x000b1aa0 FUN_000b1aa0 (230 B): equivalent/0x000b1aa0.cpp
// sym: ?Update@Object@fn_f3919bbe@@QAEXXZ @f68ff6a6b6d9 @w14b8e1cb58a6
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000b1aa0 @ 0x000b1aa0
void Object::Update() {
 if (dirty) { FUN_000b0db0(); dirty=0; }
 Manager_b1aa0* manager=FUN_002684b0();
 if (!manager) return;
 Resource_b1aa0* found=0;
 if (name[0]!=0) found=manager->Find(name);
 if (!found) { FUN_000b0db0(); return; }
 if (found==resource) return;
 if (resource) FUN_000b0db0();
 resource=found;
 found->AddRef();
 FUN_000b0a50(resource,11,2,a110,a168,a480,a358,a384,a48c);
 FUN_000b0a50(resource,13,2,a290,a2f8,a478,a3e4,a418,a488);
}

} // namespace fn_f3919bbe

// 0x000b1b90 FUN_000b1b90 (256 B): equivalent/0x000b1b90.cpp [wrapped: conflict: Object]
// sym: ?FUN_000b1b90@Object@fn_000b1b90@@QAEXPAUResult_b1b90@2@@Z @67e7a3c0d8a5 @wc4a8ffcc7f3b
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
struct Object {
 char pad0[0x10]; Collection_b1b90* collection; char pad1[0x40]; int state; char pad2[0x438]; float low; float high;
 void FUN_000b1b90(Result_b1b90* result);
};
void Object::FUN_000b1b90(Result_b1b90* result) {
 if(state==2 || !collection) return;
 result->value=0.0f;
 int n=collection->count("Button");
 Item_b1b90* selected=0;
 float ratio=0.0f;
 for(int i=0;i<n;++i) {
  Item_b1b90* item=collection->get("Button",i);
  if(!item) ratio=0.0f;
  else {
   float value=item->value(0);
   if(value<low) ratio=0.0f;
   else if(value>high) ratio=1.0f;
   else ratio=(value-low)/(high-low);
  }
  union { float f; unsigned int u; } magnitude;
  magnitude.f=ratio; magnitude.u &= 0x7fffffff;
  if(!(magnitude.f<=1e-05f)) { selected=item; break; }
 }
 result->value=ratio;
 result->item=selected;
 result->state=state;
}
} // namespace fn_000b1b90


// 0x000b1c90 FUN_000b1c90 (286 B): equivalent/0x000b1c90.cpp [wrapped: conflict: sControllerInputPointCallback]
// sym: ?FUN_000b1c90@Controller_b1c90@fn_000b1c90@@QAEXPAUState_b1c90@2@H@Z @8465ce0bb9e4 @w35ef5301bb18
inline void* operator new(size_t, void* p) { return p; }
namespace fn_000b1c90 {
// STATUS: equivalent (tools/equiv.py level 3: 1691 inputs, branch coverage 22/22)
// FUN_000b1c90 @ 0x000b1c90
extern "C" void* __cdecl FUN_0008d710(unsigned size, int alignment);
void* __cdecl FUN_0008d750(unsigned size, int alignment);
void __cdecl FUN_0008d330(void*);

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
struct Controller_b1c90 {
 char pad0[0x10]; Device_b1c90* device;
 char pad1[0x40]; int id;
 char pad2[0x450]; sControllerInputPointCallback** callbacks;
 void FUN_000b1c90(State_b1c90*, int);
};
void Controller_b1c90::FUN_000b1c90(State_b1c90* state, int requested) {
 if (id != requested || !device) return;
 state->first = 0;
 state->last = 0;
 int n = device->count("Button");
 if (callbacks) {
  for (int i=0; i<n; ++i) {
   if (callbacks[i]) {
    FUN_0008d330(callbacks[i]);
    callbacks[i] = 0;
   }
  }
 }
 if (callbacks) {
  FUN_0008d330(callbacks);
  callbacks = 0;
 }
 callbacks = (sControllerInputPointCallback**)FUN_0008d750((unsigned)n*4,4);
 for (int i=0; i<n; ++i) {
  Point_b1c90* p = device->point("Button",i);
  if (p) {
   void* storage = FUN_0008d710(16,4);
   sControllerInputPointCallback* c = 0;
   if (storage) {
    c = new(storage) sControllerInputPointCallback;
    c->point = p;
    c->controller = this;
    c->state = state;
   }
   callbacks[i] = c;
   p->attach(callbacks[i],0);
  }
 }
}
} // namespace fn_000b1c90


// 0x000b1db0 FUN_000b1db0 (688 B): equivalent/0x000b1db0.cpp [wrapped: conflict: CPhysicalController; DAT_003f335c]
// sym: ?FUN_000b1db0@CPhysicalController@fn_000b1db0@@QAEXXZ @e86fcf59f4e3 @w1ee6bc5e63c8
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

class CPhysicalController {
public:
    virtual void f0();
    char pad4[0x54];
    Str srcA[11];   // 0x58
    Str srcB[12];   // 0xb0
    Str dstA[11];   // 0x110
    Str dstB[12];   // 0x168
    Str srcC[13];   // 0x1c8
    Str srcD[12];   // 0x230
    Str dstC[13];   // 0x290
    Str dstD[12];   // 0x2f8

    void FUN_000b1db0();
};

void CPhysicalController::FUN_000b1db0()
{
    Str *srcs[4];
    Str *dsts[4];
    int counts[4];
    srcs[0] = srcA; dsts[0] = dstA; counts[0] = 11;
    srcs[1] = srcB; dsts[1] = dstB; counts[1] = 12;
    srcs[2] = srcC; dsts[2] = dstC; counts[2] = 13;
    srcs[3] = srcD; dsts[3] = dstD; counts[3] = 12;
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
// sym: ?FUN_000b2060@Mapper_b2060@fn_000b2060@@QAEXH@Z @69c4d7084ab8 @w2723768a27db
namespace fn_000b2060 {
// STATUS: equivalent (tools/equiv.py level 3: 114 inputs, branch coverage 40/40)
// FUN_000b2060 @ 0x000b2060
struct Str_b2060 {
    int cap;
    char *buf;
};

extern void __cdecl FUN_00267830(char *dst, const char *src, int n);

class Mapper_b2060 {
public:
    char pad0[0xc];
    char dirty;             // 0xc
    char pad0d[0x290 - 0xd];
    Str_b2060 btnA;               // 0x290
    Str_b2060 btnB;               // 0x298
    Str_b2060 btnC;               // 0x2a0
    Str_b2060 btnD;               // 0x2a8
    char pad2b0[8];
    Str_b2060 trigR;              // 0x2b8
    Str_b2060 trigL;              // 0x2c0
    char pad2c8[0x4ac - 0x2c8];
    int mode;               // 0x4ac
    void assign(Str_b2060 *s, const char *v);
    void FUN_000b2060(int newMode);
};

void Mapper_b2060::assign(Str_b2060 *s, const char *v)
{
    if (!(s->cap > 0))
        ((owners::StringTable_b1020 *)s)->FUN_000b1020(1);
    FUN_00267830(s->buf, v, 0x20);
    dirty = 1;
}

void Mapper_b2060::FUN_000b2060(int newMode)
{
    if (newMode == mode)
        return;
    mode = newMode;
    if (newMode == 1) {
        assign(&btnA, "X");
        assign(&btnB, "Y");
        assign(&btnC, "B");
        assign(&btnD, "A");
        assign(&trigR, "RightTrigger");
        assign(&trigL, "LeftTrigger");
    } else if (newMode == 2) {
        assign(&btnA, "X");
        assign(&btnB, "Y");
        assign(&btnC, "B");
        assign(&btnD, "A");
        assign(&trigR, "LeftTrigger");
        assign(&trigL, "RightTrigger");
    } else if (newMode == 3) {
        assign(&btnA, "A");
        assign(&btnB, "Y");
        assign(&btnC, "X");
        assign(&btnD, "B");
        assign(&trigR, "RightTrigger");
        assign(&trigL, "LeftTrigger");
    }
}
} // namespace fn_000b2060


// 0x000b23c0 FUN_000b23c0 (625 B): equivalent/0x000b23c0.cpp [wrapped: conflict: CPhysicalController]
// sym: ??0CPhysicalController@fn_000b23c0@@QAE@H@Z @bb79a5ae023d @w6e1c7b9e2a86
namespace fn_000b23c0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 28/28)
// FUN_000b23c0 @ 0x000b23c0
extern "C" int __cdecl _sprintf(char *, const char *, ...);
void __cdecl FUN_00267830(char *dst, const char *src, int n);
void *__cdecl FUN_0008d750(int size, int align);

struct Cell_b23c0 {
    int a;
    int b;
    void FUN_000b06e0();
};

void __stdcall FUN_00011520(void *arr, unsigned int size, int count, void (Cell_b23c0::*ctor)());

struct Node {
    int a, b, c, d;
};

struct Str_b23c0 {
    int cap;
    char *text;
    void FUN_000b1020(int n);
};

struct Words6_b23c0 {
    int v[6];
    int rest[6];
};

class CPhysicalController {
public:
    virtual void f0_00018b30();
    int field4;
    int field8;
    bool enabled;
    bool flagD;
    char padE[2];
    int field10;
    char name[0x40];
    int field54;
    int zeroA[22];
    Cell_b23c0 cellsA[2][6];
    int zeroB[22];
    Cell_b23c0 cellsB[2][6];
    int zeroC[26];
    Cell_b23c0 cellsC[2][6];
    int zeroD[26];
    Cell_b23c0 cellsD[2][6];
    Node *nodesA[11];
    Words6_b23c0 blocksA[2];
    Node *nodesB[13];
    Words6_b23c0 blocksB[2];
    Str_b23c0 str478;
    Str_b23c0 str480;
    int field488;
    int field48c;
    int pad490[6];
    int field4a8;
    int field4ac;

    CPhysicalController(int arg);
};

CPhysicalController::CPhysicalController(int arg)
{
    field8 = arg;
    field4 = 0;
    enabled = true;
    flagD = false;
    field10 = 0;
    field54 = 3;
    int i;
    int j;
    for (i = 0; i < 22; i++)
        zeroA[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsA[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 22; i++)
        zeroB[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsB[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 26; i++)
        zeroC[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsC[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    for (i = 0; i < 26; i++)
        zeroD[i] = 0;
    for (j = 0; j < 2; j++)
        FUN_00011520(cellsD[j], 8, 6, &Cell_b23c0::FUN_000b06e0);
    str478.cap = 0;
    str478.text = 0;
    str480.cap = 0;
    str480.text = 0;
    field488 = 0;
    field48c = 0;
    field4a8 = 0;
    field4ac = 1;
    _sprintf(name, "%s", "");
    for (i = 0; i < 11; i++) {
        nodesA[i] = 0;
        nodesA[i] = (Node *)FUN_0008d750(0x10, 4);
        nodesA[i]->a = 0;
        nodesA[i]->b = 0;
        nodesA[i]->c = 0;
        nodesA[i]->d = 0;
    }
    for (i = 0; i < 13; i++) {
        nodesB[i] = 0;
        nodesB[i] = (Node *)FUN_0008d750(0x10, 4);
        nodesB[i]->a = 0;
        nodesB[i]->b = 0;
        nodesB[i]->c = 0;
        nodesB[i]->d = 0;
    }
    for (j = 0; j < 2; j++)
        for (i = 0; i < 6; i++)
            blocksA[j].v[i] = 0;
    for (j = 0; j < 2; j++)
        for (i = 0; i < 6; i++)
            blocksB[j].v[i] = 0;
    field488 = 0;
    field48c = 0;
    if (str478.cap <= 0)
        str478.FUN_000b1020(1);
    FUN_00267830(str478.text, "", 0x20);
    if (str480.cap <= 0)
        str480.FUN_000b1020(1);
    FUN_00267830(str480.text, "", 0x20);
}
} // namespace fn_000b23c0


// 0x000b2640 FUN_000b2640 (454 B): equivalent/0x000b2640.cpp [wrapped: conflict: CPhysicalController; FUN_0008d330; core::IRefCount]
// sym: ??1CPhysicalController@fn_000b2640@@QAE@XZ @8a3d026cac48 @w4b788b7002eb
namespace fn_000b2640 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 36/36)
// FUN_000b2640 @ 0x000b2640
__declspec(nothrow) void __cdecl FUN_0008d330(void*);
__declspec(nothrow) void __stdcall FUN_000b0ff0(void*);
__declspec(nothrow) void __stdcall FUN_00013420(void*, int, int, void (__stdcall *)(void*));
namespace core { struct IRefCount { virtual void slot0(); ~IRefCount() {} }; }
struct Buffer_b2640 { unsigned count; void* data; };
struct Block_b2640 { Buffer_b2640 entries[6]; };
struct CPhysicalController : core::IRefCount {
 virtual void slot0();
 char pad[0x58-4];
 Buffer_b2640 first[11]; Block_b2640 firstBlocks[2];
 Buffer_b2640 second[11]; Block_b2640 secondBlocks[2];
 Buffer_b2640 third[13]; Block_b2640 thirdBlocks[2];
 Buffer_b2640 fourth[13]; Block_b2640 fourthBlocks[2];
 void* fifth[11]; char gap[0x60]; void* sixth[13];
 char tail[0x60]; Buffer_b2640 extraA, extraB;
 __declspec(nothrow) void FUN_000b0db0(); ~CPhysicalController();
};
CPhysicalController::~CPhysicalController() {
 FUN_000b0db0(); int i;
 for(i=0;i<11;++i) if(fifth[i]) { FUN_0008d330(fifth[i]); fifth[i]=0; }
 for(i=0;i<13;++i) if(sixth[i]) { FUN_0008d330(sixth[i]); sixth[i]=0; }
 if(extraB.data) { FUN_0008d330(extraB.data); extraB.count=0; extraB.data=0; }
 if(extraA.data) { FUN_0008d330(extraA.data); extraA.count=0; extraA.data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&fourthBlocks[i],8,6,FUN_000b0ff0);
 for(i=12;i>=0;--i) if(fourth[i].data) { FUN_0008d330(fourth[i].data); fourth[i].count=0; fourth[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&thirdBlocks[i],8,6,FUN_000b0ff0);
 for(i=12;i>=0;--i) if(third[i].data) { FUN_0008d330(third[i].data); third[i].count=0; third[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&secondBlocks[i],8,6,FUN_000b0ff0);
 for(i=10;i>=0;--i) if(second[i].data) { FUN_0008d330(second[i].data); second[i].count=0; second[i].data=0; }
 for(i=1;i>=0;--i) FUN_00013420(&firstBlocks[i],8,6,FUN_000b0ff0);
 for(i=10;i>=0;--i) if(first[i].data) { FUN_0008d330(first[i].data); first[i].count=0; first[i].data=0; }
}
} // namespace fn_000b2640


// 0x000b2810 FUN_000b2810 (2209 B): equivalent/0x000b2810.cpp [wrapped: conflict: FUN_00267830]
// sym: ?FUN_000b2810@Pad_b2810@fn_000b2810@@QAEXXZ @11c08f27a541 @w3bd3af6630b2
namespace fn_000b2810 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 102/102)
// FUN_000b2810 @ 0x000b2810

extern "C" char *__cdecl FUN_00267830(char *dst, const char *src, int n);

struct Arr_b2810 {
    int cap;
    char *data;
};

class Pad_b2810 {
public:
    char pad0[0xc - 0x0];
    char b0c;
    char padd[0x58 - 0xd];
    Arr_b2810 a58;
    Arr_b2810 a60;
    Arr_b2810 a68;
    Arr_b2810 a70;
    Arr_b2810 a78;
    Arr_b2810 a80;
    Arr_b2810 a88;
    Arr_b2810 a90;
    Arr_b2810 a98;
    Arr_b2810 aa0;
    Arr_b2810 aa8;
    Arr_b2810 ab0;
    Arr_b2810 ab8;
    Arr_b2810 ac0;
    Arr_b2810 ac8;
    Arr_b2810 ad0;
    Arr_b2810 ad8;
    Arr_b2810 ae0;
    Arr_b2810 ae8;
    Arr_b2810 af0;
    Arr_b2810 af8;
    Arr_b2810 a100;
    Arr_b2810 a108;
    char pad110[0x1c8 - 0x110];
    Arr_b2810 a1c8;
    Arr_b2810 a1d0;
    Arr_b2810 a1d8;
    Arr_b2810 a1e0;
    Arr_b2810 a1e8;
    Arr_b2810 a1f0;
    Arr_b2810 a1f8;
    Arr_b2810 a200;
    Arr_b2810 a208;
    Arr_b2810 a210;
    Arr_b2810 a218;
    Arr_b2810 a220;
    Arr_b2810 a228;
    Arr_b2810 a230;
    Arr_b2810 a238;
    Arr_b2810 a240;
    Arr_b2810 a248;
    Arr_b2810 a250;
    Arr_b2810 a258;
    Arr_b2810 a260;
    Arr_b2810 a268;
    Arr_b2810 a270;
    Arr_b2810 a278;
    Arr_b2810 a280;
    Arr_b2810 a288;
    char pad290[0x490 - 0x290];
    float f490;
    float f494;
    float f498;
    float f49c;
    float f4a0;
    float f4a4;
    void FUN_000b1db0();
    void FUN_000b2810();
};

void Pad_b2810::FUN_000b2810()
{
    b0c = 1;
    f490 = 0.2f;
    f494 = 0.8f;
    f498 = 0.35f;
    f49c = 0.8f;
    f4a0 = 0.8f;
    f4a4 = 1.0f;
    if (!(a58.cap > 0))
        ((owners::StringTable_b1020 *)&a58)->FUN_000b1020(1);
    FUN_00267830(a58.data, "A", 0x20);
    if (!(a60.cap > 0))
        ((owners::StringTable_b1020 *)&a60)->FUN_000b1020(1);
    FUN_00267830(a60.data, "B", 0x20);
    if (!(a68.cap > 0))
        ((owners::StringTable_b1020 *)&a68)->FUN_000b1020(1);
    FUN_00267830(a68.data, "X", 0x20);
    if (!(a70.cap > 0))
        ((owners::StringTable_b1020 *)&a70)->FUN_000b1020(1);
    FUN_00267830(a70.data, "Y", 0x20);
    if (!(a78.cap > 0))
        ((owners::StringTable_b1020 *)&a78)->FUN_000b1020(1);
    FUN_00267830(a78.data, "Start", 0x20);
    if (!(a80.cap > 0))
        ((owners::StringTable_b1020 *)&a80)->FUN_000b1020(1);
    FUN_00267830(a80.data, "Back", 0x20);
    if (!(a88.cap > 0))
        ((owners::StringTable_b1020 *)&a88)->FUN_000b1020(1);
    FUN_00267830(a88.data, "Back", 0x20);
    if (!(a90.cap > 0))
        ((owners::StringTable_b1020 *)&a90)->FUN_000b1020(1);
    FUN_00267830(a90.data, "LeftTrigger", 0x20);
    if (!(a98.cap > 0))
        ((owners::StringTable_b1020 *)&a98)->FUN_000b1020(1);
    FUN_00267830(a98.data, "RightTrigger", 0x20);
    if (!(aa0.cap > 0))
        ((owners::StringTable_b1020 *)&aa0)->FUN_000b1020(1);
    FUN_00267830(aa0.data, "Black", 0x20);
    if (!(aa8.cap > 0))
        ((owners::StringTable_b1020 *)&aa8)->FUN_000b1020(1);
    FUN_00267830(aa8.data, "White", 0x20);
    if (!(ab0.cap > 0))
        ((owners::StringTable_b1020 *)&ab0)->FUN_000b1020(1);
    FUN_00267830(ab0.data, "LeftStickX", 0x20);
    if (!(ab8.cap > 0))
        ((owners::StringTable_b1020 *)&ab8)->FUN_000b1020(1);
    FUN_00267830(ab8.data, "DPadRight", 0x20);
    if (!(ac0.cap > 0))
        ((owners::StringTable_b1020 *)&ac0)->FUN_000b1020(1);
    FUN_00267830(ac0.data, "DPadLeft", 0x20);
    if (!(ac8.cap > 0))
        ((owners::StringTable_b1020 *)&ac8)->FUN_000b1020(1);
    FUN_00267830(ac8.data, "LeftStickY", 0x20);
    if (!(ad0.cap > 0))
        ((owners::StringTable_b1020 *)&ad0)->FUN_000b1020(1);
    FUN_00267830(ad0.data, "DPadUp", 0x20);
    if (!(ad8.cap > 0))
        ((owners::StringTable_b1020 *)&ad8)->FUN_000b1020(1);
    FUN_00267830(ad8.data, "DPadDown", 0x20);
    if (!(ae0.cap > 0))
        ((owners::StringTable_b1020 *)&ae0)->FUN_000b1020(1);
    FUN_00267830(ae0.data, "RightStickX", 0x20);
    if (!(ae8.cap > 0))
        ((owners::StringTable_b1020 *)&ae8)->FUN_000b1020(1);
    FUN_00267830(ae8.data, "", 0x20);
    if (!(af0.cap > 0))
        ((owners::StringTable_b1020 *)&af0)->FUN_000b1020(1);
    FUN_00267830(af0.data, "", 0x20);
    if (!(af8.cap > 0))
        ((owners::StringTable_b1020 *)&af8)->FUN_000b1020(1);
    FUN_00267830(af8.data, "RightStickY", 0x20);
    if (!(a100.cap > 0))
        ((owners::StringTable_b1020 *)&a100)->FUN_000b1020(1);
    FUN_00267830(a100.data, "", 0x20);
    if (!(a108.cap > 0))
        ((owners::StringTable_b1020 *)&a108)->FUN_000b1020(1);
    FUN_00267830(a108.data, "", 0x20);
    if (!(a1c8.cap > 0))
        ((owners::StringTable_b1020 *)&a1c8)->FUN_000b1020(1);
    FUN_00267830(a1c8.data, "X", 0x20);
    if (!(a1d0.cap > 0))
        ((owners::StringTable_b1020 *)&a1d0)->FUN_000b1020(1);
    FUN_00267830(a1d0.data, "Y", 0x20);
    if (!(a1d8.cap > 0))
        ((owners::StringTable_b1020 *)&a1d8)->FUN_000b1020(1);
    FUN_00267830(a1d8.data, "B", 0x20);
    if (!(a1e0.cap > 0))
        ((owners::StringTable_b1020 *)&a1e0)->FUN_000b1020(1);
    FUN_00267830(a1e0.data, "A", 0x20);
    ((owners::StringTable_b1020 *)&a1e8)->FUN_000b1020(2);
    if (!(a1e8.cap > 0))
        ((owners::StringTable_b1020 *)&a1e8)->FUN_000b1020(1);
    FUN_00267830(a1e8.data, "Black", 0x20);
    if (!(a1e8.cap > 0))
        ((owners::StringTable_b1020 *)&a1e8)->FUN_000b1020(1);
    FUN_00267830(a1e8.data + 0x20, "White", 0x20);
    if (!(a1f0.cap > 0))
        ((owners::StringTable_b1020 *)&a1f0)->FUN_000b1020(1);
    FUN_00267830(a1f0.data, "RightTrigger", 0x20);
    if (!(a1f8.cap > 0))
        ((owners::StringTable_b1020 *)&a1f8)->FUN_000b1020(1);
    FUN_00267830(a1f8.data, "LeftTrigger", 0x20);
    if (!(a200.cap > 0))
        ((owners::StringTable_b1020 *)&a200)->FUN_000b1020(1);
    FUN_00267830(a200.data, "Start", 0x20);
    if (!(a208.cap > 0))
        ((owners::StringTable_b1020 *)&a208)->FUN_000b1020(1);
    FUN_00267830(a208.data, "Back", 0x20);
    if (!(a210.cap > 0))
        ((owners::StringTable_b1020 *)&a210)->FUN_000b1020(1);
    FUN_00267830(a210.data, "LeftThumb", 0x20);
    if (!(a218.cap > 0))
        ((owners::StringTable_b1020 *)&a218)->FUN_000b1020(1);
    FUN_00267830(a218.data, "RightThumb", 0x20);
    if (!(a220.cap > 0))
        ((owners::StringTable_b1020 *)&a220)->FUN_000b1020(1);
    FUN_00267830(a220.data, "LeftJoystick", 0x20);
    if (!(a228.cap > 0))
        ((owners::StringTable_b1020 *)&a228)->FUN_000b1020(1);
    FUN_00267830(a228.data, "RightJoystick", 0x20);
    if (!(a230.cap > 0))
        ((owners::StringTable_b1020 *)&a230)->FUN_000b1020(1);
    FUN_00267830(a230.data, "LeftStickX", 0x20);
    if (!(*(char*)&DAT_0049caae)) {
        if (!(a238.cap > 0))
            ((owners::StringTable_b1020 *)&a238)->FUN_000b1020(1);
        FUN_00267830(a238.data, "DPadRight", 0x20);
        if (!(a240.cap > 0))
            ((owners::StringTable_b1020 *)&a240)->FUN_000b1020(1);
        FUN_00267830(a240.data, "DPadLeft", 0x20);
    }
    if (!(a248.cap > 0))
        ((owners::StringTable_b1020 *)&a248)->FUN_000b1020(1);
    FUN_00267830(a248.data, "LeftStickY", 0x20);
    if (!(*(char*)&DAT_0049caae)) {
        if (!(a250.cap > 0))
            ((owners::StringTable_b1020 *)&a250)->FUN_000b1020(1);
        FUN_00267830(a250.data, "DPadUp", 0x20);
        if (!(a258.cap > 0))
            ((owners::StringTable_b1020 *)&a258)->FUN_000b1020(1);
        FUN_00267830(a258.data, "DPadDown", 0x20);
    }
    if (!(a260.cap > 0))
        ((owners::StringTable_b1020 *)&a260)->FUN_000b1020(1);
    FUN_00267830(a260.data, "RightStickX", 0x20);
    if (!(a268.cap > 0))
        ((owners::StringTable_b1020 *)&a268)->FUN_000b1020(1);
    FUN_00267830(a268.data, "", 0x20);
    if (!(a270.cap > 0))
        ((owners::StringTable_b1020 *)&a270)->FUN_000b1020(1);
    FUN_00267830(a270.data, "", 0x20);
    if (!(a278.cap > 0))
        ((owners::StringTable_b1020 *)&a278)->FUN_000b1020(1);
    FUN_00267830(a278.data, "RightStickY", 0x20);
    if (!(a280.cap > 0))
        ((owners::StringTable_b1020 *)&a280)->FUN_000b1020(1);
    FUN_00267830(a280.data, "", 0x20);
    if (!(a288.cap > 0))
        ((owners::StringTable_b1020 *)&a288)->FUN_000b1020(1);
    FUN_00267830(a288.data, "", 0x20);
    FUN_000b1db0();
}
} // namespace fn_000b2810

namespace fn_f3919bbe {

// 0x000b30c0 FUN_000b30c0 (1099 B): equivalent/0x000b30c0.cpp
// sym: ?FUN_000b30c0@Blender_b30c0@fn_f3919bbe@@QAEXHHPAHPAPAPAVItem_b30c0@2@PATCell_b30c0@2@PAV32@PAM44@Z @e4b63039c60e @w868be669f875
// STATUS: equivalent (tools/equiv.py level 3: 117 inputs, branch coverage 77/78, incomplete; Wine build 117 inputs, 77/78)
// FUN_000b30c0 @ 0x000b30c0
void Blender_b30c0::FUN_000b30c0(int groups, int pairs, int *counts, Item_b30c0 ***items, Cell_b30c0 *cells, Item_b30c0 *single,
                            float *out1, float *out2, float *out3)
{
    int i;
    for (i = 0; i < groups; i++) {
        float t = 0.0f;
        int n = counts[i * 2];
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

    if (mode == 2 && out3 != 0) {
        for (int p = 0; p < pairs; p++) {
            for (int e = 0; e < 2; e++) {
                float acc = 0.0f;
                for (int k = 0; k < 3; k++) {
                    Item_b30c0 *it = cells[p * 12 + e * 3 + k].item;
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
                    Item_b30c0 *it = cells[p * 12 + e * 3 + k].item;
                    if (it != 0) {
                        float w = it->v9(0);
                        int m = cells[p * 12 + 6 + e * 3 + k].mode;
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

    float range = hi2 - lo2;
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
    if (field_10) {
        Out_b3510 out = {0, 0};
        FUN_000b30c0(0xB, 2, (void*)&field_110, (void*)&field_358, (void*)&field_384, field_48C, p2,
                     (void*)&p2->field_2C, &out);
        p2->field_3C = out.a;
        p2->field_40 = out.b;
        FUN_000b30c0(0xD, 2, (void*)&field_290, (void*)&field_3E4, (void*)&field_418, field_488, p3,
                     (void*)&p3->field_34, 0);
    }
}

} // namespace fn_f3919bbe

// 0x000b35b0 CPhysicalController::vfunc_2 (30 B): matches/0x000b35b0.cpp
// sym: ??_GCPhysicalController@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CPhysicalController::~CPhysicalController() {}

