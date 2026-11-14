// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ad990..0x000ae9a0 (kind game, layer game, confidence medium), dominant class CController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fac5a26d {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fac5a26d {} using namespace fn_fac5a26d;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif
namespace fn_fac5a26d {
class Item_ad990 {
  public:
    void Release_000b0db0();
};
class CController_ad990 {
  public:
    void Reset();
    char pad0[16];
    int count;
    Item_ad990** items;
    unsigned int a[17];
    unsigned int b[17];
    unsigned char pad1[12];
    unsigned int c[17];
    unsigned int d[17];
};
struct FUN {
    char pad[0x18];
    unsigned int a[17];
    unsigned int b[17];
    char gap[0x0c];
    unsigned int c[17];
    unsigned int d[17];
};
} // namespace fn_fac5a26d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_fac5a26d {
struct Data_ada90 {
    unsigned int x[0x11];
};
class Thing_ada90 {
  public:
    char pad[0x5c];
    Data_ada90 data;
    void Copy(Data_ada90* out);
};
struct Block_adad0 {
    int x[0x11];
};
class Thing_adad0 {
  public:
    char pad[0xf0];
    Block_adad0 data;
    void Copy(Block_adad0* out);
};
class Obj {
  public:
    char pad[0xa0];
    int a, b, c;
    void Clear();
};
struct Vec3_adb10 {
    int x, y, z;
};
struct Obj_adb10 {
    char pad[0xa0];
    Vec3_adb10 v;
    void Get(Vec3_adb10* out);
};
class Item_adb90 {
  public:
    void FnF_000b1c90(void*, int);
};
class C_adb90 {
  public:
    char pad[0x10];
    int count;
    Item_adb90** items;
    char more[0x88];
    void F(int);
};
struct Item_adbd0 {
    void Run_000b0e20();
};
struct Holder_adbd0 {
    char pad[0x10];
    int count;
    Item_adbd0** items;
    void Run();
};
struct Item_adc00 {
    void Apply_000b2060(int);
};
struct Owner_adc00 {
    char pad[0x10];
    int count;
    Item_adc00** items;
    void Apply(int);
};
struct Item_adc30 {
};
struct Obj_adc30 {
    char pad[0x10];
    int count;
    Item_adc30** items;
    int run();
};
struct Entry_adc60 {
 char pad0[13];
 char disabled;
 char pad1[6];
 char name[256];
};
struct Owner_adc60 {
 char pad0[16];
 int count;
 Entry_adc60 **entries;
 char pad1[0x134-0x18];
 char selected[256];
 void FUN_000adc60();
};
class Item_add70 {
  public:
    virtual void f();
    virtual void Release();
};
extern "C" void __cdecl Free(void*);
class CController_add70 {
  public:
    char pad[0x10];
    int count;
    Item_add70** items;
    void Clear();
};
extern "C" char DAT_00405d38[];
class CPhysicalController_ae090 {
  public:
    virtual void Init();
    virtual void Release();
    CPhysicalController_ae090* Ctor_000b23c0(int i);
};
class CController_ae090 {
  public:
    char pad[0x10];
    int mCount;
    CPhysicalController_ae090** mItems;
    void Clear_000add70();
    void Alloc(int n);
};
extern "C" void* FUN_0008d750(int size, int n);
extern "C" void* FUN_0008d710(int size, int n);
struct Block_ae130 {
    float v[17];
};
struct Item_ae130 {
    char pad0[0xd];
    char flag;
    void FUN_000b3510(Block_ae130 *a, Block_ae130 *b);
};
extern "C++" void __cdecl FUN_000addd0(void *, const void *);
extern "C++" void __cdecl FUN_000adf20(void *, const void *);
class Accumulator_ae130 {
public:
    char pad0[0x10];
    int count;
    Item_ae130 **items;
    Block_ae130 blockA;
    Block_ae130 blockB;
    int words[3];
    Block_ae130 blockC;
    Block_ae130 blockD;
    void FUN_000ae130();
};
struct Item_ae2f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3();
    virtual void v4();
    virtual void v5();
    virtual const char *v6();
};
struct Mgr_ae2f0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int Count();
    virtual Item_ae2f0 *Get(int i);
};
Mgr_ae2f0 *FUN_002684b0();
struct Entry_ae2f0 {
    char pad0[0xd];
    char flag;
    char pad1[6];
    char name[0x120];
    char str134[1];
    void FUN_000b2810();
};
struct CController_ae2f0 {
    char pad0[0xc];
    char flag;
    char pad1[3];
    int count;
    Entry_ae2f0 **entries;
    char pad2[0x134 - 0x18];
    char str134[0x100];
    void FUN_000ae090(int n);
    void FUN_000ae2f0(const char *key);
};
struct Item_ae4b0 { void FUN_000b2810(); };
class CController {
  public:
    virtual void m_vf0_00018b30();
    virtual void m_vf1_00018b40();
    virtual CController* vfunc_2(int);
    CController(int);
    int field4;
    int owner;
    unsigned char enabled;
    char _m_pad_d[0x3];
    int count;
    Item_ae4b0 **items;
    int block18[17];
    int block5c[17];
    int fieldA0;
    int fieldA4;
    int fieldA8;
    int blockAc[17];
    int blockF0[17];
    unsigned char field134;
    char _m_pad_135[0x3];
    void Fna_000ad990();
    void Fnb_000add70();
    void run();
    void FUN_000ae090(int);
    void second_000add70();
};
extern char hulk_at_00405d38, hulk_at_003f6098;
struct ThisCall_000ad990 {
    void FUN_000ad990();
};
void thunk_FUN_00267090(CController*);
class Entry_ae5a0;
class Item_ae5a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int Count();
    virtual Entry_ae5a0* At(int);
};
class Entry_ae5a0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual char IsValid();
    virtual void d();
    virtual void e();
    virtual int Value();
};
class CController_ae5a0 {
  public:
    char pad[0x134];
    char flag;
    void Add_000ae2f0(int);
    void Process();
};
Item_ae5a0* GetItems_002684b0();
struct CController_ae8a0 {
    void Fng_000ae2f0(int);
};
struct X_ae8a0 {
    char pad[4];
    CController_ae8a0* p;
    void f(hulk_intptr);
};
struct Item_ae8b0 {
    char pad0[0x14];
    char name[1];           // 0x14
};
struct List_ae8b0 {
    char pad0[0x10];
    int count;              // 0x10
};
class Owner_ae8b0 {
public:
    int pad0;
    List_ae8b0* list;             // 0x04
    void FUN_000ae8b0(const char* name);
};
class B_ae930 {
  public:
    void FnF_000adc00(int);
};
class A_ae930 {
  public:
    char pad[4];
    B_ae930* p4;
    int p8;
    void Set(int x);
};
class C_ae960 {
  public:
    virtual void v();
    char* ptr;
    int f();
};
struct Y_ae980 {
    void Fng_000adc60();
};
struct X_ae980 {
    char pad[4];
    Y_ae980* p;
    void f();
};
struct CController_ae990 {
    void Fng_000ae5a0();
};
struct X_ae990 {
    char pad[4];
    CController_ae990* p;
    void f();
};


// 0x000ad990 FUN_000ad990 (85 B): matches/0x000ad990.cpp
// sym: ?Reset@CController_ad990@fn_fac5a26d@@QAEXXZ
void CController_ad990::Reset() {
    int i = count;
    while (--i >= 0) {
        Item_ad990* p = items[i];
        if (p)
            p->Release_000b0db0();
    }
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    memset(d, 0, sizeof(d));
}


// 0x000ad9f0 FUN_000ad9f0 (53 B): matches/0x000ad9f0.cpp
// sym: ?FUN_000ad9f0@fn_fac5a26d@@YIXPAUFUN@1@@Z
void __fastcall FUN_000ad9f0(FUN* p) {
    memset(p->a, 0, 68);
    memset(p->b, 0, 68);
    memset(p->c, 0, 68);
    memset(p->d, 0, 68);
}

} // namespace fn_fac5a26d

// 0x000ada30 FUN_000ada30 (24 B): matches/0x000ada30.cpp
// sym: ?FUN_000ada30@C_ada30@owners@@QAEXH@Z
void owners::C_ada30::FUN_000ada30(int i) {
    if (i >= 0 && i < 13)
        a[i] = 0;
}


// 0x000ada50 FUN_000ada50 (32 B): matches/0x000ada50.cpp
// sym: ?FUN_000ada50@X_ada50@owners@@QAEXH@Z
void owners::X_ada50::FUN_000ada50(int i) {
    if (i >= 0 && i < 2) {
        a[i * 2] = 0;
        a[i * 2 + 1] = 0;
    }
}


// 0x000ada70 FUN_000ada70 (21 B): matches/0x000ada70.cpp
// sym: ?FUN_000ada70@Obj_ada70@owners@@QAEXPAX@Z
void owners::Obj_ada70::FUN_000ada70(void* out) {
    memcpy(out, data, 0x44);
}

namespace fn_fac5a26d {

// 0x000ada90 FUN_000ada90 (21 B): matches/0x000ada90.cpp
// sym: ?Copy@Thing_ada90@fn_fac5a26d@@QAEXPAUData_ada90@2@@Z
void Thing_ada90::Copy(Data_ada90* out) {
    *out = data;
}


// 0x000adad0 FUN_000adad0 (24 B): matches/0x000adad0.cpp
// sym: ?Copy@Thing_adad0@fn_fac5a26d@@QAEXPAUBlock_adad0@2@@Z
void Thing_adad0::Copy(Block_adad0* out) {
    *out = data;
}


// 0x000adaf0 FUN_000adaf0 (17 B): matches/0x000adaf0.cpp
// sym: ?Clear@Obj@fn_fac5a26d@@QAEXXZ
void Obj::Clear() {
    memset(&a, 0, 12);
}


// 0x000adb10 FUN_000adb10 (29 B): matches/0x000adb10.cpp
// sym: ?Get@Obj_adb10@fn_fac5a26d@@QAEXPAUVec3_adb10@2@@Z
void Obj_adb10::Get(Vec3_adb10* out) {
    *out = v;
}


// 0x000adb90 FUN_000adb90 (60 B): matches/0x000adb90.cpp
// sym: ?F@C_adb90@fn_fac5a26d@@QAEXH@Z
void C_adb90::F(int p) {
    int i = 0;
    if (count > 0) {
        do {
            items[i]->FnF_000b1c90((char*)this + 0xa0, p);
            ++i;
        } while (i < count);
    }
}


// 0x000adbd0 FUN_000adbd0 (38 B): matches/0x000adbd0.cpp
// sym: ?Run@Holder_adbd0@fn_fac5a26d@@QAEXXZ
void Holder_adbd0::Run() {
    for (int i = 0; i < count; ++i)
        items[i]->Run_000b0e20();
}


// 0x000adc00 FUN_000adc00 (44 B): matches/0x000adc00.cpp
// sym: ?Apply@Owner_adc00@fn_fac5a26d@@QAEXH@Z
// Same code shape as 0x000acf50 (propagated; names are from that function)
void Owner_adc00::Apply(int value) {
    int i = 0;
    if (count > 0)
        do {
            items[i]->Apply_000b2060(value);
            ++i;
        } while (i < count);
}


// 0x000adc30 FUN_000adc30 (45 B): matches/0x000adc30.cpp
// sym: ?run@Obj_adc30@fn_fac5a26d@@QAEHXZ
int Obj_adc30::run() {
    int n = count;
    int i = 0;
    if (n > 0) {
        Item_adc30** base = items;
        Item_adc30** p = base;
        do {
            if (*p != 0)
                return ((int)((owners::C_b0ef0 *)(base[i]))->FUN_000b0ef0());
            ++i;
            ++p;
        } while (i < n);
    }
    return 1;
}


// 0x000adc60 FUN_000adc60 (182 B): equivalent/0x000adc60.cpp
// sym: ?FUN_000adc60@Owner_adc60@fn_fac5a26d@@QAEXXZ @1fecee90ab77 @w6cfaf25a8e87
// STATUS: equivalent (tools/equiv.py level 3: 438 inputs, branch coverage 23/26, incomplete)
// FUN_000adc60 @ 0x000adc60
void Owner_adc60::FUN_000adc60() {
 if (selected[0] != 0 || DAT_004de7a8[0] == 0) return;
 for (int i=0; i<count; ++i) {
  Entry_adc60 *entry=entries[i];
  if (!entry) continue;
  const char *a=entry->name;
  const char *b=DAT_004de7a8;
  bool match=false;
  if (a && *a) {
   while (*a == *b) {
    if (*a == 0) { match=true; break; }
    ++a; ++b;
   }
  }
  if (match) {
   entry->disabled=0;
   char *dest=selected;
   const char *src=DAT_004de7a8;
   char ch;
   do { ch=*src++; *dest++=ch; } while(ch);
  } else entry->disabled=1;
 }
}


// 0x000add70 FUN_000add70 (87 B): matches/0x000add70.cpp
// sym: ?Clear@CController_add70@fn_fac5a26d@@QAEXXZ
void CController_add70::Clear() {
    register CController_add70* self = this;
    if (self->items != 0) {
        int i = 0;
        if (self->count > 0) {
            do {
                Item_add70** slot = self->items + i;
                Item_add70* p = *slot;
                if (p) {
                    p->Release();
                    *slot = 0;
                }
                ++i;
            } while (i < self->count);
        }
        if (self->items) {
            Free(self->items);
            self->items = 0;
        }
        self->count = 0;
    }
}

} // namespace fn_fac5a26d

// 0x000addd0 FUN_000addd0 (328 B): equivalent/0x000addd0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_000addd0 @05d03cbe311e @wb2085e3d1c0c
namespace fn_000addd0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_000addd0 @ 0x000addd0
struct Bounds_addd0 {
    float v[15];
};

union FloatBits_addd0 {
    float f;
    unsigned int u;
};

static float abs_bits(float x)
{
    FloatBits_addd0 b;
    b.f = x;
    b.u &= 0x7fffffff;
    return b.f;
}

extern "C" void FUN_000addd0(void *dst, const void *src)
{
    int i;

    for (i = 0; i < 11; i++) {
        if (((const Bounds_addd0 *)src)->v[i] > ((Bounds_addd0 *)dst)->v[i])
            ((Bounds_addd0 *)dst)->v[i] = ((const Bounds_addd0 *)src)->v[i];
    }
    for (i = 11; i < 15; i++) {
        if (abs_bits(((const Bounds_addd0 *)src)->v[i]) > abs_bits(((Bounds_addd0 *)dst)->v[i]))
            ((Bounds_addd0 *)dst)->v[i] = ((const Bounds_addd0 *)src)->v[i];
    }
}
} // namespace fn_000addd0


// 0x000adf20 FUN_000adf20 (328 B): equivalent/0x000adf20.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: _FUN_000adf20 @13710a20ed35 @w08297676931b
namespace fn_000adf20 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 26/26)
// FUN_000adf20 @ 0x000adf20
struct Bounds_adf20 {
    float v[17];
};

union FloatBits_adf20 {
    float f;
    unsigned int u;
};

static float abs_bits(float x)
{
    FloatBits_adf20 b;
    b.f = x;
    b.u &= 0x7fffffff;
    return b.f;
}

extern "C" void FUN_000adf20(void *dst, const void *src)
{
    int i;

    for (i = 0; i < 13; i++) {
        if (((const Bounds_adf20 *)src)->v[i] > ((Bounds_adf20 *)dst)->v[i])
            ((Bounds_adf20 *)dst)->v[i] = ((const Bounds_adf20 *)src)->v[i];
    }
    for (i = 13; i < 17; i++) {
        if (abs_bits(((const Bounds_adf20 *)src)->v[i]) > abs_bits(((Bounds_adf20 *)dst)->v[i]))
            ((Bounds_adf20 *)dst)->v[i] = ((const Bounds_adf20 *)src)->v[i];
    }
}
} // namespace fn_000adf20

namespace fn_fac5a26d {

// 0x000ae070 FUN_000ae070 (29 B): matches/0x000ae070.cpp
// sym: ?run@CController@fn_fac5a26d@@QAEXXZ
void CController::run() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00405d38);
    Fna_000ad990();
    Fnb_000add70();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
}


// 0x000ae090 FUN_000ae090 (160 B): matches/0x000ae090.cpp
// sym: ?Alloc@CController_ae090@fn_fac5a26d@@QAEXH@Z
void CController_ae090::Alloc(int n) {
    if (mCount)
        Clear_000add70();
    mCount = n;
    mItems = (CPhysicalController_ae090**)FUN_0008d750(n * 4, 4);
    for (int i = 0; i < n; i++) {
        mItems[i] = 0;
        void* mem = FUN_0008d710(0x4b0, 4);
        CPhysicalController_ae090* o;
        if (mem)
            o = ((CPhysicalController_ae090*)mem)->Ctor_000b23c0(i);
        else
            o = 0;
        CPhysicalController_ae090** slot = &mItems[i];
        if (o)
            o->Init();
        if (*slot)
            (*slot)->Release();
        *slot = o;
    }
}


// 0x000ae130 FUN_000ae130 (387 B): equivalent/0x000ae130.cpp
// sym: ?FUN_000ae130@Accumulator_ae130@fn_fac5a26d@@QAEXXZ @cc7edf0dc3ac @w61ab360d9a57
// STATUS: equivalent (tools/equiv.py level 3: 54 inputs, branch coverage 22/22)
// FUN_000ae130 @ 0x000ae130
void Accumulator_ae130::FUN_000ae130()
{
    int k;
    for (k = 0; k < 17; k++)
        blockA.v[k] = 0;
    for (k = 0; k < 17; k++)
        blockB.v[k] = 0;
    for (k = 0; k < 17; k++)
        blockC.v[k] = 0;
    for (k = 0; k < 17; k++)
        blockD.v[k] = 0;

    for (int i = 0; i < count; i++) {
        if (items[i] != 0) {
            Block_ae130 first;
            Block_ae130 second;
            for (k = 0; k < 17; k++)
                first.v[k] = 0;
            for (k = 0; k < 17; k++)
                second.v[k] = 0;
            items[i]->FUN_000b3510(&first, &second);
            if (items[i]->flag) {
                FUN_000addd0((Block_ae130 *)(&blockC), (Block_ae130 *)(&first));
                FUN_000adf20((Block_ae130 *)(&blockD), (Block_ae130 *)(&second));
            } else {
                FUN_000addd0((Block_ae130 *)(&blockA), (Block_ae130 *)(&first));
                FUN_000adf20((Block_ae130 *)(&blockB), (Block_ae130 *)(&second));
            }
        }
    }

    if (DAT_004e222c) {
        if (blockA.v[0] < 0.2f && blockA.v[1] < 0.2f && blockA.v[4] < 0.2f && blockA.v[6] < 0.2f)
            DAT_004e222c = 0;
        for (k = 0; k < 11; k++) {
            blockA.v[k] = 0;
            blockC.v[k] = 0;
        }
        for (k = 0; k < 13; k++) {
            blockB.v[k] = 0;
            blockC.v[k] = 0;
        }
        words[0] = 0;
        words[1] = 0;
        words[2] = 0;
    }
}


// 0x000ae2f0 FUN_000ae2f0 (443 B): equivalent/0x000ae2f0.cpp
// sym: ?FUN_000ae2f0@CController_ae2f0@fn_fac5a26d@@QAEXPBD@Z @9e6357ca27b7 @w326a8c8dea64
// STATUS: equivalent (tools/equiv.py level 3: 99 inputs, branch coverage 30/40, incomplete)
// FUN_000ae2f0 @ 0x000ae2f0
void CController_ae2f0::FUN_000ae2f0(const char *key)
{
    CController_ae2f0 *self = this;
    int n = count;
    Entry_ae2f0 **p = entries;
    Entry_ae2f0 *e = 0;
    bool found = false;
    for (int i = 0; i < n; i++, p++) {
        e = *p;
        const char *a = e->name;
        const char *b = key;
        while (*a == *b && *a != 0) {
            a++;
            b++;
        }
        if (*a == *b) {
            found = true;
            break;
        }
        if (e->name[0] == 0) {
            ((owners::Dev_b0740 *)e)->FUN_000b0740(key);
            found = true;
            break;
        }
    }
    if (found) {
        if (self->str134[0] == 0) {
            e->flag = 0;
        } else {
            const char *a = key;
            const char *b = self->str134;
            while (*a == *b && *a != 0) {
                a++;
                b++;
            }
            e->flag = (*a != *b);
        }
        return;
    }
    self->FUN_000ae090(FUN_002684b0()->Count());
    for (int i = 0; i < FUN_002684b0()->Count(); i++) {
        Entry_ae2f0 *en = self->entries[i];
        const char *arg;
        Item_ae2f0 *it = FUN_002684b0()->Get(i);
        if (it != 0 && FUN_002684b0()->Get(i)->v3() != 0)
            arg = FUN_002684b0()->Get(i)->v6();
        else
            arg = "";
        ((owners::Dev_b0740 *)en)->FUN_000b0740(arg);
        en->FUN_000b2810();
    }
}


// 0x000ae4b0 FUN_000ae4b0 (171 B): equivalent/0x000ae4b0.cpp
// sym: ??0CController@fn_fac5a26d@@QAE@H@Z @abedb48cad80 @we6bca8e893ee
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_000ae4b0 @ 0x000ae4b0
CController::CController(int arg) {
    owner = arg;
    field4 = 0;
    enabled = 1;
    count = 0;
    items = 0;
    fieldA0 = fieldA4 = fieldA8 = 0;
    for (int i=0;i<17;++i) block18[i]=0;
    for (int j=0;j<17;++j) block5c[j]=0;
    fieldA0 = fieldA4 = fieldA8 = 0;
    for (int k=0;k<17;++k) blockAc[k]=0;
    for (int l=0;l<17;++l) blockF0[l]=0;
    field134=0;
    FUN_000ae090(4);
    for (int n=0;n<count;++n) items[n]->FUN_000b2810();
}


// 0x000ae560 CController::vfunc_2 (49 B): matches/0x000ae560.cpp
// sym: ?vfunc_2@CController@fn_fac5a26d@@UAEPAV12@H@Z
CController* CController::vfunc_2(int flags) {
    *(void**)this = &hulk_at_00405d38;
    ((ThisCall_000ad990*)(this))->FUN_000ad990();
    second_000add70();
    *(void**)this = &hulk_at_003f6098;
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000ae5a0 FUN_000ae5a0 (98 B): matches/0x000ae5a0.cpp
// sym: ?Process@CController_ae5a0@fn_fac5a26d@@QAEXXZ
void CController_ae5a0::Process() {
    flag = 0;
    int i = 0;
    int n = GetItems_002684b0()->Count();
    if (n > 0) {
        do {
            Entry_ae5a0* e = GetItems_002684b0()->At(i);
            if (e && e->IsValid())
                Add_000ae2f0(e->Value());
            ++i;
            n = GetItems_002684b0()->Count();
        } while (i < n);
    }
}

// 0x000ae620 thunk_FUN_000b10d0 (5 B): not yet verified
} // namespace fn_fac5a26d

// 0x000ae640 FUN_000ae640 (25 B): matches/0x000ae640.cpp
// sym: ?FUN_000ae640@C_ae640@owners@@QAEHH@Z
hulk_intptr owners::C_ae640::FUN_000ae640(int i) {
    if (i >= 0 && i < 1)
        return *(&a + i);
    return 0;
}

namespace fn_fac5a26d {

// 0x000ae8a0 FUN_000ae8a0 (8 B): matches/0x000ae8a0.cpp
// sym: ?f@X_ae8a0@fn_fac5a26d@@QAEXH@Z
// Same code shape as 0x000244a0 (propagated; names are from that function)
void X_ae8a0::f(hulk_intptr a0) {
    p->Fng_000ae2f0(a0);
}


// 0x000ae8b0 FUN_000ae8b0 (127 B): matches/0x000ae8b0.cpp
// sym: ?FUN_000ae8b0@Owner_ae8b0@fn_fac5a26d@@QAEXPBD@Z
// FUN_000ae8b0 @ 0x000ae8b0
// Finds the list item with the given name and resets it.
void Owner_ae8b0::FUN_000ae8b0(const char* name)
{
    for (int i = 0; i < list->count; i++) {
        Item_ae8b0* item = ((Item_ae8b0 *)((owners::C_ace20 *)list)->FUN_000ace20(i));
        if (strcmp(item->name, name) == 0) {
            ((owners::Dev_b0740 *)item)->FUN_000b0740((const char *)(((float*)&DAT_003f335c)));
            return;
        }
    }
}


// 0x000ae930 FUN_000ae930 (40 B): matches/0x000ae930.cpp
// sym: ?Set@A_ae930@fn_fac5a26d@@QAEXH@Z
void A_ae930::Set(int x) {
    if (p4) {
        p4->FnF_000adc00(x);
        p8 = x;
    } else {
        p8 = x;
    }
}


// 0x000ae960 FUN_000ae960 (30 B): matches/0x000ae960.cpp
// sym: ?f@C_ae960@fn_fac5a26d@@QAEHXZ
int C_ae960::f() {
    char* q = ptr + 0x134;
    int x = -1;
    if (q[0])
        x = (signed char)q[4] - 0x30;
    return x;
}


// 0x000ae980 FUN_000ae980 (8 B): matches/0x000ae980.cpp
// sym: ?f@X_ae980@fn_fac5a26d@@QAEXXZ
// Same code shape as 0x000244a0 (propagated; names are from that function)
void X_ae980::f() {
    p->Fng_000adc60();
}


// 0x000ae990 FUN_000ae990 (8 B): matches/0x000ae990.cpp
// sym: ?f@X_ae990@fn_fac5a26d@@QAEXXZ
// Same code shape as 0x000244a0 (propagated; names are from that function)
void X_ae990::f() {
    p->Fng_000ae5a0();
}

} // namespace fn_fac5a26d
