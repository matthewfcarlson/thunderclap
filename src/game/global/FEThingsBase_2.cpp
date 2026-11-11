// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000ee9b0..0x000f0f70 (kind game, layer game, confidence high), dominant class FEThingsBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f196c51b {
#define TREE_TU_END }
namespace fn_f196c51b {} using namespace fn_f196c51b;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f196c51b {
class Ref {
  public:
    virtual void f0();
    virtual void Release();
};
inline void clearRef(Ref*& p) {
    Ref* q = p;
    if (q) {
        q->Release();
        p = 0;
    }
}
struct FEContainer_nv_ef120 {
    void helper_000e4ec0(int);
};
struct ThisCall_000e4ec0 {
    void FUN_000e4ec0(int);
};
struct Obj_ef160 {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void call(int);
};
class FEContainer_ef3e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
};
extern void* hulk_at_0040c774[];
class Ref_ef400 {
  public:
    virtual void F0();
    virtual void Release();
};
class Del_ef400 {
  public:
    virtual void D(int);
};
class FEContainer_ef400 {
  public:
    void* vptr;
    void Fin_000eeac0();
};
class FEScreenBase_ef400 : public FEContainer_ef400 {
  public:
    char p[0x98c];
    Ref_ef400* m990;
    Ref_ef400* a[4];
    Ref_ef400* b[4];
    Ref_ef400* c[4];
    Ref_ef400* d[6];
    void* hvptr;
    char pad[4];
    Del_ef400* e[32];
    ~FEScreenBase_ef400() throw();
};
extern void* hulk_at_0040c84c[];
class Ref_ef820 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEContainer_ef820 {
  public:
    void* vptr;
    void Fin_000eeac0();
};
void Free_0008d330(void*) throw();
struct Sub_ef820 {
    char c;
};
void __fastcall SubFini(Sub_ef820*) throw();
void __fastcall SubFini2(Sub_ef820*) throw();
void __fastcall SubFini3(Sub_ef820*) throw();
class FEDialog_ef820 : public FEContainer_ef820 {
  public:
    char p9a4[2464];
    Ref_ef820* m9a4;
    ~FEDialog_ef820() throw();
};
class FEContainer_ef8b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
};
extern void* hulk_at_0040c924[];
class Ref_ef8f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class FEScreenBase_ef8f0 {
  public:
    void* vptr;
    void Fin_000ef400();
};
struct Sub_ef8f0 {
    char c;
};
void __fastcall SubFini(Sub_ef8f0*) throw();
void __fastcall SubFini2(Sub_ef8f0*) throw();
void __fastcall SubFini3(Sub_ef8f0*) throw();
class FEMenuBase_ef8f0 : public FEScreenBase_ef8f0 {
  public:
    char p990[2444];
    Ref_ef8f0* m990;
    ~FEMenuBase_ef8f0() throw();
};
extern void* hulk_at_0040ca04[];
class Ref_ef920 {
  public:
    virtual void F0();
    virtual void Release();
};
class Del_ef920 {
  public:
    virtual void D(int);
};
struct A_ef920 {
    void Fin_000df700() throw();
};
struct B_ef920 {
    void Fin_000f8bd0() throw();
};
class FEThingsBase_ef920 {
  public:
    void* vptr;
    A_ef920* m4;
    B_ef920* m8;
    Del_ef920* a[64];
    char pp20c[256];
    Del_ef920* b[256];
    Del_ef920* c[1024];
    void* d[64];
    char pp17fc[240];
    Ref_ef920* m17fc;
    char pp1818[24];
    Ref_ef920* m1818;
    char pp1854[56];
    Ref_ef920* e[2];
    char pp1a5c[512];
    Ref_ef920* f[2];
    char pp1c64[512];
    Ref_ef920* g[2];
    Ref_ef920* h[2];
    char pp2078[1028];
    void* hvptr;
    char pp2080[4];
    Del_ef920* ii[32];
    ~FEThingsBase_ef920() throw();
};
struct ThisWrap_000efc80 {
    void* FUN_000e7620(void*);
    void* FUN_000efc80(void* arg);
};
struct Obj_efc80 {
    char pad[0x9ac];
    void* value;
};
extern int __cdecl FUN_0008d690(int);
class Helper_efda0 {
  public:
    int call_000ef180(FEThingsBase*, int);
};
class Helper_efdd0 {
  public:
    int forwarder_000ef7c0(FEThingsBase*, int);
};
extern int __cdecl lookup_0008d690(int);
extern void* __cdecl FUN_0008d690(unsigned int);
class Helper_efe00 {
  public:
    int call_000ecd70(int);
};
typedef unsigned int uint_efe20;
extern void* __cdecl FUN_0008d690(uint_efe20);
class TextTable_efe20 {
  public:
    uint_efe20 run_000ed820(uint_efe20);
};
extern void* __cdecl allocThing_0008d690(unsigned int);
class Thing_efe40 {
  public:
    int init_000edf60(int);
};
class Thing_efe60 {
  public:
    int init_000e9ec0(int);
};
extern void* __cdecl alloc_0008d690(int);
extern void* __cdecl GetThing_0008d690(int);
struct Helper_efe80 {
    int DoThing_000ebb90(void*, int);
};
class Param_f0590 {
public:
    float FUN_000fad30();
    __int64 FUN_000faeb0();
    bool FUN_000f9e90();
};
class Args_f0590 {
public:
    virtual void v0();
    virtual unsigned GetKey();
};
struct FEThingsBase_nv_f0590 {
    void FUN_000e0360(float x, float y, float z);
    int FUN_000e7ec0(__int64 id, Param_f0590 *p);
    int FUN_000e7f10(__int64 id, Param_f0590 *p);
    void FUN_000e0300(float f, int a, int b);
    void FUN_000e03c0(float x, float y, int a, int b, int c);
    void FUN_000e7d90(Param_f0590 *p, int c);
    void FUN_000e7c30(Param_f0590 *p, int c);
    void FUN_000e7cd0(Param_f0590 *p, int c);
    void FUN_000e7b90(Param_f0590 *p, int c);
};
class Param_f07b0 {
public:
    float FUN_000fad30();
    unsigned FUN_000faeb0();
    bool FUN_000f9e90();
};
class Args_f07b0 {
public:
    virtual void v0();
    virtual unsigned GetKey();
};
struct Target_f07b0 {
    char pad0[0x141];
    char flag141;
    char flag142;
    char pad143;
    char flag144;
    char pad145[0x14c - 0x145];
    unsigned color;
};
struct FEThingsBase_nv_f07b0 {
    void FUN_000eff20(Param_f07b0 *p, int b, Target_f07b0 *t, int mode);
};
extern "C" void __cdecl FUN_000fb1c0(int);
struct Context { unsigned int entries[512]; unsigned int extra[10]; void FUN_000f9d20(); };
struct Res_f0b90 {
    virtual void v0();
    virtual void v1();
};
struct Obj_f0b90 {
    virtual ~Obj_f0b90();
    virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7();
    virtual const char *v8();
    char pad[0x858 - 4];
    char name[1];           // 0x858
};
struct Pair_f0b90 {
    Res_f0b90 *res[2];
};
struct Mgr_f0b90 {
    char pad0[0xc];
    Obj_f0b90 *objs[0x40];                // 0xc
    char pad10c[0x20c - 0x10c];
    Obj_f0b90 *objs2[0x100];              // 0x20c
    char pad60c[0x160c - 0x60c];
    void *bufs[0x40];               // 0x160c
    char curName[0x175c - 0x170c];  // 0x170c
    Obj_f0b90 *cur;                       // 0x175c
    char pad1760[0x1854 - 0x1760];
    Res_f0b90 *rA[2];                     // 0x1854
    char nameA[2][0x100];           // 0x185c
    Res_f0b90 *rB[2];                     // 0x1a5c
    char nameB[2][0x100];           // 0x1a64
    Res_f0b90 *rC[2];                     // 0x1c64
    char padC[8];
    char nameC[2][0x100];           // 0x1c74
    void FUN_000f0b90(const char *name);
};
extern void __cdecl thunk_FUN_00267090(void *p);

} // namespace fn_f196c51b

// 0x000ee9b0 FEContainer::vfunc_50 (261 B): equivalent/0x000ee9b0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_50@FEContainer@fn_000ee9b0@@QAEXPBDI@Z @7444f5c503eb @w8d200303fdba
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000ee9b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 15/16, incomplete)
// FEContainer::vfunc_50 @ 0x000ee9b0
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
extern "C" char* __cdecl strchr(const char*, int);
#endif

extern "C" void __cdecl FUN_000f6d70(const char*, unsigned int);
extern "C" void __cdecl FUN_000f69e0(void*, unsigned int);
struct Lookup_ee9b0 { unsigned int FUN_0027b200(unsigned __int64); };
struct Info_ee9b0 { char pad[8]; Lookup_ee9b0* lookup; };
struct Entry_ee9b0 { unsigned int unused; unsigned int key; void* value; };
struct Entries_ee9b0 { char pad[0x3c]; Entry_ee9b0* begin; Entry_ee9b0* end; };
struct Child_ee9b0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual Info_ee9b0* v11();
 char pad[0x40]; Entries_ee9b0* entries;
};
struct FEContainer { char pad[0x28]; Child_ee9b0* children[8]; void vfunc_50(const char* name, unsigned int arg); };
void FEContainer::vfunc_50(const char* name, unsigned int arg) {
 if (strchr(name, '.')) { FUN_000f6d70(name,arg); return; }
 unsigned __int64 hash=FUN_0027b020(name);
 unsigned int key=0xffff;
 int i=0;
 for (;i<8;++i) {
  Child_ee9b0* child=children[i];
  if (!child) break;
  Info_ee9b0* info=child->v11();
  key=info->lookup->FUN_0027b200(hash);
  if(key!=0xffff) break;
 }
 Entries_ee9b0* list=children[i]->entries;
 Entry_ee9b0* start=list->begin;
 unsigned char count=(unsigned char)(((int)((char*)list->end-(char*)start))/12);
 for(int n=0;n<count;++n) {
  Entry_ee9b0* entry=&start[(unsigned char)n];
  if(entry->key==key) {
   if(entry->value) FUN_000f69e0(entry->value,arg);
   return;
  }
 }
}
} // namespace fn_000ee9b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000eeac0 FUN_000eeac0 (134 B): matches/0x000eeac0.cpp [wrapped: conflict: FEContainer]
// sym: ?Clear@FEContainer@fn_000eeac0@@QAEXXZ
namespace fn_000eeac0 {
extern "C" char DAT_0040c244[];
class FEItem {
  public:
    virtual void A();
    virtual void B();
};
class FEItem2 {
  public:
    virtual void A();
    virtual void B();
    virtual void C(int);
};
extern void __cdecl FreeThing_0008d330(void*);
class FEContainer {
  public:
    virtual void V();
    char p[0x24];
    FEItem* a[8];
    int x;
    void* b[0x80];
    char r[0x200];
    FEItem2* c[0x80];
    char s[0x204];
    int y;
    void Clear();
};
void FEContainer::Clear() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0040c244);
    for (int i = 0; i < 8; i++) {
        if (a[i]) {
            a[i]->B();
            a[i] = 0;
        }
    }
    for (int j = 0; j < 128; j++) {
        if (b[j]) {
            FreeThing_0008d330(b[j]);
            b[j] = 0;
        }
    }
    for (int k = 0; k < 128; k++) {
        if (c[k]) {
            c[k]->C(1);
            c[k] = 0;
        }
    }
    x = 0;
    y = 0;
}
} // namespace fn_000eeac0


// 0x000eeb50 FEThingsBase::vfunc_65 (71 B): matches/0x000eeb50.cpp
// sym: ?vfunc_65@FEThingsBase@@UAEXXZ
void FEThingsBase::vfunc_65() {
    if ((*(Ref**)&DAT_004de954)) {
        (*(Ref**)&DAT_004de954)->Release();
        (*(Ref**)&DAT_004de954) = 0;
    }
    Ref* p = (*(Ref * *)&this->f_17fc);
    if (p) {
        clearRef((*(Ref * *)&this->f_17fc));
        (*(Ref * *)&this->f_17fc) = 0;
    }
}


// 0x000eeba0 FEContainer::vfunc_25 (113 B): matches/0x000eeba0.cpp [wrapped: conflict: FEContainer]
// sym: ?Target@FEContainer@fn_000eeba0@@UAEPAUItem_eeba0@2@PAU32@0@Z
namespace fn_000eeba0 {
struct Blk_eeba0 {
    int x[10];
};
struct Item_eeba0 {
    char pad[0x118];
    Blk_eeba0 blk;
    void Prep_000e2940(Item_eeba0*);
};
struct Mgr_eeba0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual Item_eeba0* Get(Item_eeba0*);
    Item_eeba0* Find_000e74a0(Item_eeba0*);
};
class FEContainer {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void s24(Item_eeba0*, int);
    virtual Item_eeba0* Target(Item_eeba0*, Item_eeba0*);
    virtual void b26();
    virtual void b27();
    virtual void b28();
    virtual void b29();
    virtual void b30();
    virtual void b31();
    virtual void b32();
    virtual void b33();
    virtual void b34();
    virtual void b35();
    virtual void b36();
    virtual void b37();
    virtual void b38();
    virtual void b39();
    virtual void b40();
    virtual void b41();
    virtual Item_eeba0* Lookup(Item_eeba0*);
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual Item_eeba0* Make(int, int);
    Mgr_eeba0* mgr;
};

Item_eeba0* FEContainer::Target(Item_eeba0* a, Item_eeba0* id) {
    Item_eeba0* res = mgr->Get(a);
    if (id) {
        Item_eeba0* it = Lookup(id);
        if (it || (it = mgr->Find_000e74a0(id))) {
            res->Prep_000e2940(it);
            res->blk = it->blk;
        }
    }
    s24(res, (hulk_intptr)a);
    return res;
}
} // namespace fn_000eeba0


// 0x000eec20 FEContainer::vfunc_26 (84 B): matches/0x000eec20.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_26@FEContainer@fn_000eec20@@UAEHHH@Z
namespace fn_000eec20 {
class Obj_eec20 {
  public:
    void Use_000e3ac0(int);
};
class Child_eec20 {
  public:
    virtual void x0();
    virtual void x1();
    virtual void x2();
    virtual void x3();
    virtual void x4();
    virtual void x5();
    virtual void x6();
    virtual void x7();
    virtual void x8();
    virtual void x9();
    virtual void x10();
    virtual void x11();
    virtual void x12();
    virtual void x13();
    virtual void x14();
    virtual void x15();
    virtual void x16();
    virtual void x17();
    virtual void x18();
    virtual void x19();
    virtual void x20();
    virtual void x21();
    virtual void x22();
    virtual void x23();
    virtual void x24();
    virtual void x25();
    virtual void x26();
    virtual void x27();
    virtual void x28();
    virtual void x29();
    virtual void x30();
    virtual void x31();
    virtual void x32();
    virtual void x33();
    virtual void x34();
    virtual void x35();
    virtual void x36();
    virtual void x37();
    virtual void x38();
    virtual void x39();
    virtual void x40();
    virtual void x41();
    virtual void x42();
    virtual void x43();
    virtual void x44();
    virtual void x45();
    virtual void x46();
    virtual void x47();
    virtual void x48();
    virtual void x49();
    virtual void x50();
    virtual void x51();
    virtual void x52();
    virtual Obj_eec20* get(int);
    int Find_000e74e0(int);
};
class FEContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24(Obj_eec20*, int);
    virtual void f25();
    virtual int vfunc_26(int, int);
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual int f43(int);
    Child_eec20* c;
};
int FEContainer::vfunc_26(int a, int b) {
    Obj_eec20* r = c->get(a);
    f24(r, a);
    if (b) {
        int t = f43(b);
        if (!t)
            t = c->Find_000e74e0(b);
        if (t)
            r->Use_000e3ac0(t);
    }
    return (hulk_intptr)r;
}
} // namespace fn_000eec20


// 0x000eec80 FEContainer::vfunc_27 (84 B): matches/0x000eec80.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_27@FEContainer@fn_000eec80@@QAEHHH@Z
namespace fn_000eec80 {
class Obj_eec80 {
  public:
    void apply_000e3c70(int);
};
class Child_eec80 {
  public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual void c53();
    virtual Obj_eec80* get(int);
    int fallback_000e7520(int);
};
class FEContainer {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24(int, int);
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual int a44(int);
    Child_eec80* child;
    hulk_intptr vfunc_27(int x, int y);
};
hulk_intptr FEContainer::vfunc_27(int x, int y) {
    Obj_eec80* o = child->get(x);
    a24((hulk_intptr)o, x);
    if (y) {
        int q = a44(y);
        if (!q)
            q = child->fallback_000e7520(y);
        if (q)
            o->apply_000e3c70(q);
    }
    return (hulk_intptr)o;
}
} // namespace fn_000eec80


// 0x000eece0 FEContainer::vfunc_28 (84 B): matches/0x000eece0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_28@FEContainer@fn_000eece0@@UAEHHH@Z
namespace fn_000eece0 {
class Child_eece0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual int f55(int);
    int fallback_000e7560(int);
};
class Result_eece0 {
  public:
    int apply_000e3f20(int);
};
class FEContainer {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24(int, int);
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual int vfunc_28(int, int);
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual int a45(int);
    virtual void a46();
    virtual void a47();
    virtual void a48();
    virtual void a49();
    virtual void a50();
    virtual void a51();
    virtual void a52();
    Child_eece0* child;
};
int FEContainer::vfunc_28(int a, int b) {
    hulk_intptr r = child->f55(a);
    a24(r, a);
    if (b) {
        int v = a45(b);
        if (!v)
            v = child->fallback_000e7560(b);
        if (v) {
            Result_eece0* res = (Result_eece0*)r;
            res->apply_000e3f20(v);
        }
    }
    return r;
}
} // namespace fn_000eece0


// 0x000eed40 FEContainer::vfunc_29 (105 B): equivalent/0x000eed40.cpp [wrapped: conflict: FEContainer]
// sym: ?v29@FEContainer@fn_000eed40@@UAEPAUItem_eed40@2@PBD0@Z @1fe417d5b9bc @w295e2d5aa635
namespace fn_000eed40 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FEContainer::vfunc_29 @ 0x000eed40
extern char DAT_0049dba4[];
extern char DAT_0049f48c[];
void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

struct Item_eed40 {
    void FUN_000e2940(void* other);
};

class Owner_eed40 {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual Item_eed40* v56(const char* name);
    void* FUN_000e7260(const char* name);
};

class FEContainer {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23(Item_eed40* item, const char* name);
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual Item_eed40* v29(const char* a1, const char* a2);
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void* v38(const char* name);
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    Owner_eed40* owner;
};

Item_eed40* FEContainer::v29(const char* a1, const char* a2)
{
    Item_eed40* item = owner->v56(a1);
    v23(item, a1);
    if (a2) {
        void* found = v38(a2);
        if (!found) {
            found = FUN_00344e74(owner->FUN_000e7260(a2), 0, DAT_0049dba4, DAT_0049f48c, 0);
        }
        if (found)
            item->FUN_000e2940(found);
    }
    return item;
}
} // namespace fn_000eed40


// 0x000eedb0 FEContainer::vfunc_33 (84 B): matches/0x000eedb0.cpp [wrapped: conflict: FEContainer]
// sym: ?v33@FEContainer@fn_000eedb0@@UAEHHH@Z
namespace fn_000eedb0 {
class FEObj {
  public:
    void Fn_000e2ec0(int);
};
class FEChild_eedb0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual FEObj* f57(int);
    int Fng_000e7460(int);
};
class FEContainer {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int, int);
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual int v33(int, int);
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int v40(int);
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    FEChild_eedb0* child;
};
int FEContainer::v33(int a, int b) {
    FEObj* r = child->f57(a);
    v24((hulk_intptr)r, a);
    if (b) {
        int x = v40(b);
        if (!x)
            x = child->Fng_000e7460(b);
        if (x)
            r->Fn_000e2ec0(x);
    }
    return (hulk_intptr)r;
}
} // namespace fn_000eedb0


// 0x000eee10 FEContainer::vfunc_30 (84 B): matches/0x000eee10.cpp [wrapped: macros]
// sym: ?f30@FEContainer@fn_000eee10@@UAEHHH@Z
namespace fn_000eee10 {
class Widget {
  public:
#define V(n) virtual int v##n();
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
                V(53) V(54) V(55) V(56) V(57) virtual int get(int);
    int Fnh_000e75a0(int);
    void h2_000ebe00(int);
};
class FEContainer {
  public:
#define F(n) virtual int f##n();
    F(0)
    F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8) F(9) F(10) F(11) F(12) F(13) F(14) F(15) F(16) F(17) F(18) F(19)
        F(20) F(21) F(22) F(23) virtual int f24(int, int);
    F(25) F(26) F(27) F(28) F(29) virtual int f30(int, int);
    F(31) F(32) F(33) F(34) F(35) F(36) F(37) F(38) F(39) F(40) virtual int f41(int);
    F(42) F(43) F(44) F(45) F(46) F(47) F(48) F(49) F(50) F(51) F(52) Widget* child;
};
int FEContainer::f30(int b, int a) {
    hulk_intptr x = child->get(b);
    f24(x, b);
    if (a) {
        int y = f41(a);
        if (!y)
            y = child->Fnh_000e75a0(a);
        if (y)
            ((Widget*)x)->h2_000ebe00(y);
    }
    return x;
}
} // namespace fn_000eee10
#undef F
#undef V


// 0x000eee70 FEContainer::vfunc_31 (84 B): matches/0x000eee70.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_31@FEContainer@fn_000eee70@@UAEPAVItem@2@HH@Z
namespace fn_000eee70 {
class Item {
  public:
    void Add_000ebe00(int);
};
class Provider {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual Item* Get(int);
    int Find_000e75a0(int);
};
class FEContainer {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(Item*, int);
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual Item* vfunc_31(int, int);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual int v41(int);
    Provider* prov;
};
Item* FEContainer::vfunc_31(int a, int b) {
    Item* p = prov->Get(a);
    v24(p, a);
    if (b) {
        int x = v41(b);
        if (!x)
            x = prov->Find_000e75a0(b);
        if (x)
            p->Add_000ebe00(x);
    }
    return p;
}
} // namespace fn_000eee70


// 0x000eeed0 FEContainer::vfunc_32 (84 B): matches/0x000eeed0.cpp [wrapped: macros]
// sym: ?f32@FEContainer@fn_000eeed0@@UAEPAVObj@2@HH@Z
namespace fn_000eeed0 {
#define V(n) virtual void f##n();
class Obj {
  public:
    void Attach_000e2940(Obj* o);
};
class Child {
  public:
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49) V(50) V(51) V(52)
                V(53) V(54) V(55) V(56) V(57) V(58) V(59) virtual Obj* f60(int);
    Obj* Fng_000e75e0(int);
};
class FEContainer {
  public:
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) virtual void f23(Obj*, int);
    V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) virtual Obj* f32(int, int);
    V(33) V(34) V(35) V(36) V(37) V(38) V(39) V(40) V(41) V(42) V(43) V(44) V(45) virtual Obj* f46(int);
    V(47) V(48) V(49) V(50) V(51) V(52) Child* child;
};
Obj* FEContainer::f32(int a, int b) {
    Obj* r = child->f60(a);
    f23(r, a);
    if (b) {
        Obj* q = f46(b);
        if (!q)
            q = child->Fng_000e75e0(b);
        if (q)
            r->Attach_000e2940(q);
    }
    return r;
}
} // namespace fn_000eeed0
#undef V


// 0x000eef30 FEContainer::vfunc_10 (255 B): equivalent/0x000eef30.cpp [wrapped: conflict: DAT_004de948; FEContainer]
// sym: ?vfunc_10@FEContainer@fn_000eef30@@UAEXXZ @124c3a5f360e @w65a271288a26
namespace fn_000eef30 {
// STATUS: equivalent (tools/equiv.py level 3: 19853 inputs, branch coverage 14/14)
// FEContainer::vfunc_10 @ 0x000eef30

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double __cdecl sin(double);
#endif

struct Item_eef30 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};
extern float (__cdecl *DAT_004de948)();
class FEContainer {
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
    virtual void vfunc_10();
    char pad[0x4c - 4];
    Item_eef30* groupA[0x80];
    char gap[0x64c - 0x24c];
    Item_eef30* groupB[0x80];
    char pad2[0x96c - 0x84c];
    float pulse;
    float pad3;
    float phase;
};
void FEContainer::vfunc_10() {
    for (int i = 0; i < 0x80; i++) {
        if (!groupA[i])
            break;
        groupA[i]->v1();
    }
    for (int i = 0; i < 0x80; i++) {
        if (!groupB[i])
            break;
        groupB[i]->v2();
    }
    double t = DAT_004de948() // t stays unrounded in an x87 register
         * 6.2831855f + phase;
    pulse = (sin(t) + 1.0f) * 0.5f;
    phase = t - (float)(int)(t * 0.15915494f) * 6.2831855f;
    volatile float *ph = &phase; // the original compares and reloads the rounded member
    if (*ph >= 0.0f && *ph <= 6.2831855f) {
        phase = *ph;
    } else if (*ph > 6.2831855f) {
        phase = 6.2831855f;
    } else {
        phase = 0.0f;
    }
}
} // namespace fn_000eef30


// 0x000ef100 FEContainer::vfunc_4 (25 B): matches/0x000ef100.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_4@FEContainer@fn_000ef100@@UAEXXZ
namespace fn_000ef100 {
class FEContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void vfunc_4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48(int);
    char* child;
};
struct ThisCall_000e4ec0 {
    void FUN_000e4ec0(int);
};
void FEContainer::vfunc_4() {
    ((ThisCall_000e4ec0*)(this))->FUN_000e4ec0(7);
    ((FEContainer*)child)->f48(6);
}
} // namespace fn_000ef100


// 0x000ef120 FEContainer::vfunc_6 (55 B): matches/0x000ef120.cpp
// sym: ?vfunc_6@FEContainer@@UAEXXZ
void FEContainer::vfunc_6() {
    ((FEContainer_nv_ef120*)this)->helper_000e4ec0(8);
    int state = *(int*)((char*)(*(void * *)&this->f_04) + 0x17f8);
    if (state == 0)
        ((FEContainer_nv_ef120*)this)->helper_000e4ec0(0xc);
    state = *(int*)((char*)(*(void * *)&this->f_04) + 0x17f8);
    if (state == 1)
        ((FEContainer_nv_ef120*)this)->helper_000e4ec0(0xd);
}


// 0x000ef160 FEContainer::vfunc_7 (25 B): matches/0x000ef160.cpp
// sym: ?vfunc_7@FEContainer@@UAEXXZ
void FEContainer::vfunc_7() {
    ((ThisCall_000e4ec0*)(this))->FUN_000e4ec0(9);
    ((Obj_ef160*)*(void**)((char*)this + 4))->call(6);
}


// 0x000ef180 FUN_000ef180 (584 B): equivalent/0x000ef180.cpp [wrapped: conflict: FEAnimationHolder; FEScreenBase]
// sym: ??0FEScreenBase@fn_000ef180@@QAE@PAUScreenSource@1@H@Z @5ece06e44d0f @w8bdaf6e2ffa6
namespace fn_000ef180 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_000ef180 @ 0x000ef180
struct ScreenSource {
    char pad00[0x180c];
    int f180c;
    int f1810;
    int f1814;
    char pad1818[0x1840 - 0x1818];
    int quad[4];                // 0x1840
    int f1850;
};

union Quad_ef180 {
    int w[4];
    char bytes[16];
};

class __declspec(novtable) FEContainer_ef180 {
public:
    FEContainer_ef180(ScreenSource* src, int arg) { FUN_000e4510(src, arg); }
    virtual void v0();
    int f04;
    char pad08[0x990 - 8];
    void FUN_000e4510(ScreenSource* src, int arg);
};

class FEAnimationHolder {
public:
    FEAnimationHolder() {}
    virtual void v0_000e1d70();
};

class FEScreenBase : public FEContainer_ef180 {
public:
    FEScreenBase(ScreenSource* src, hulk_intptr arg);
    virtual void v1();

    int f990;  // 0x990
    int a994[4];  // 0x994
    int a9a4[4];  // 0x9a4
    int a9b4[4];  // 0x9b4
    int a9c4[6];  // 0x9c4
    FEAnimationHolder holder;  // 0x9dc
    int f9e0;  // 0x9e0
    int a9e4[0x20];  // 0x9e4
    char fa64;  // 0xa64
    char pada65[0x3];
    int fa68;  // 0xa68
    int fa6c;  // 0xa6c
    int fa70;  // 0xa70
    int fa74;  // 0xa74
    int fa78;  // 0xa78
    int fa7c;  // 0xa7c
    int fa80;  // 0xa80
    int fa84;  // 0xa84
    int fa88;  // 0xa88
    int fa8c;  // 0xa8c
    int fa90;  // 0xa90
    int fa94;  // 0xa94
    int fa98;  // 0xa98
    int fa9c;  // 0xa9c
    int faa0;  // 0xaa0
    Quad_ef180 quad;  // 0xaa4
    int fab4;  // 0xab4
    char fab8;  // 0xab8
    char fab9;  // 0xab9
    char padaba[0x2];
    int aabc[0x20];  // 0xabc
    int fb3c;  // 0xb3c
    char fb40;  // 0xb40
    char padb41[0x3f];
    char fb80;  // 0xb80
    char padb81[0x3f];
    char fbc0;  // 0xbc0
    char fbc1;  // 0xbc1
    char fbc2;  // 0xbc2
};

FEScreenBase::FEScreenBase(ScreenSource* src, hulk_intptr arg) : FEContainer_ef180(src, arg)
{
    int i;
    for (i = 0; i < 0x20; i++)
        a9e4[i] = 0;
    f9e0 = 0;
    quad.bytes[12] = 0;
    fb3c = 0;
    fab8 = 1;
    for (i = 0; i < 0x20; i++)
        aabc[i] = 0;
    f990 = 0;
    fa70 = 0;
    fa6c = 0;
    fa68 = 0;
    fa74 = 0;
    for (i = 0; i < 4; i++)
        a9b4[i] = 0;
    for (i = 0; i < 6; i++)
        a9c4[i] = 0;
    for (i = 0; i < 4; i++)
        a9a4[i] = 0;
    for (i = 0; i < 4; i++)
        a994[i] = 0;
    fa64 = 0;
    fa78 = 0;
    fa7c = 0;
    fa80 = src->f180c;
    fa84 = src->f180c;
    fa88 = src->f180c;
    fa8c = src->f180c;
    fa90 = src->f1810;
    fa94 = src->f1814;
    fa98 = 0;
    fa9c = 0;
    faa0 = 0;
    quad.w[0] = src->quad[0];
    quad.w[1] = src->quad[1];
    quad.w[2] = src->quad[2];
    quad.w[3] = src->quad[3];
    int tail = src->f1850;
    int self04 = f04;
    fb40 = 0;
    fb80 = 0;
    fbc1 = 0;
    fbc2 = 0;
    fab4 = tail;
    f9e0 = self04;
    fbc0 = 1;
    fab9 = 1;
}
} // namespace fn_000ef180


// 0x000ef3d0 FEScreenBase::vfunc_8 (4 B): matches/0x000ef3d0.cpp
// sym: ?vfunc_8@FEScreenBase@@UAEPAXXZ
// Same code shape as 0x000e45c0 (propagated; names are from that function)
void* FEScreenBase::vfunc_8() {
    return (void*)((FEScreenBase*)((char*)this + 8));
}


// 0x000ef3e0 FEScreenBase::vfunc_35 (7 B): matches/0x000ef3e0.cpp
// sym: ?vfunc_35@FEScreenBase@@UAEHXZ
int FEScreenBase::vfunc_35() {
    return *(int*)((char*)this + 0x990);
}


// 0x000ef3f0 FEScreenBase::vfunc_34 (4 B): matches/0x000ef3f0.cpp
// sym: ?vfunc_34@FEScreenBase@@UAEHXZ
// Same code shape as 0x00086370 (propagated; names are from that function)
int FEScreenBase::vfunc_34() {
    return (*(int *)&this->f_48);
}

namespace fn_f196c51b {

// 0x000ef400 FUN_000ef400 (228 B): matches/0x000ef400.cpp
// sym: ??1FEScreenBase_ef400@fn_f196c51b@@QAE@XZ
FEScreenBase_ef400::~FEScreenBase_ef400() throw() {
    *(void* volatile*)&vptr = hulk_at_0040c774;
    Ref_ef400* t = *(Ref_ef400* volatile*)&m990;
    if (t) {
        t->Release();
        m990 = 0;
    }
    for (int i = 0; i < 4; i++)
        if (a[i]) {
            a[i]->Release();
            a[i] = 0;
        }
    for (int i = 0; i < 4; i++)
        if (b[i]) {
            b[i]->Release();
            b[i] = 0;
        }
    for (int i = 0; i < 4; i++)
        if (c[i]) {
            c[i]->Release();
            c[i] = 0;
        }
    for (int i = 0; i < 6; i++)
        if (d[i]) {
            d[i]->Release();
            d[i] = 0;
        }
    hvptr = g_vftable2;
    _ReadWriteBarrier();
    for (int i = 0; i < 32; i++)
        if (e[i]) {
            e[i]->D(1);
            e[i] = 0;
        }
    Fin_000eeac0();
}

} // namespace fn_f196c51b

// 0x000ef4f0 FEScreenBase::vfunc_10 (284 B): equivalent/0x000ef4f0.cpp [wrapped: conflict: DAT_0052c2a4; FEContainer; FEScreenBase]
// sym: ?vfunc_10@FEScreenBase@fn_000ef4f0@@UAEXXZ @d468415ac3e1 @w638e01f082c3
namespace fn_000ef4f0 {
// STATUS: equivalent (tools/equiv.py level 3: 2976 inputs, branch coverage 14/14)
// FEScreenBase::vfunc_10 @ 0x000ef4f0
struct ScreenItem {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(float value, int arg);
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
};
struct CameraLike {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5(float angle, float scale);
};
struct Clock_ef4f0 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual float vf16();
};
struct Widget_ef4f0 {
    void FUN_000dff70();
};
extern Clock_ef4f0* DAT_0052c2a4;
extern float (__stdcall *DAT_004de948)();
extern "C" void __cdecl FUN_0009f790(void* obj, float t, float* a, float* b);
extern "C" void __cdecl FUN_000f61e0(CameraLike* cam);

class FEContainer {
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
    virtual void vfunc_10();
    char pad[0x98c - 4];
};
class FEScreenBase : public FEContainer {
public:
    void* camData;
    CameraLike* camera;
    char pad994[0x9a4 - 0x994];
    ScreenItem* groupA[4];
    char pad9b4[0x9c4 - 0x9b4];
    ScreenItem* groupB[6];
    Widget_ef4f0 widget;
    char pad9dd[0xab8 - 0x9dd];
    bool active;
    ScreenItem* items[0x20];
    int itemCount;
    virtual void vfunc_10();
};
void FEScreenBase::vfunc_10() {
    if (!active)
        return;
    float a, b;
    FUN_0009f790(camData, DAT_0052c2a4->vf16(), &a, &b);
    camera->vf5(a * 0.017453292f, 1.0f);
    widget.FUN_000dff70();
    FUN_000f61e0(camera);
    for (int i = 0; i < 4; i++) {
        if (!groupA[i])
            break;
        groupA[i]->vf6(DAT_004de948() * 1000.0f, 0);
    }
    for (int i = 0; i < 6; i++) {
        if (!groupB[i])
            break;
        groupB[i]->vf6(DAT_004de948() * 1000.0f, 0);
    }
    FEContainer::vfunc_10();
    for (int i = 0; i < itemCount; i++)
        items[i]->vf10();
}
} // namespace fn_000ef4f0


// 0x000ef610 FUN_000ef610 (206 B): equivalent/0x000ef610.cpp [wrapped: conflict: DAT_004de948]
// sym: ?target@Object@fn_000ef610@@QAE_NXZ @463826dba464 @w916d6c0436b8
namespace fn_000ef610 {
// STATUS: equivalent (tools/equiv.py level 3: 2985 inputs, branch coverage 20/20)
// FUN_000ef610 @ 0x000ef610
struct TimerState { int state; bool FUN_000fb4b0(float dt); };
struct Entry_ef610 { char pad[0xe0]; TimerState timer; };
struct Context { char pad[0x17f8]; int flag; };
extern float (__fastcall *DAT_004de948)(void*);
struct Object {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
 virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
 virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
 virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
 virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual Context* context();
 char pad0[0x448]; Entry_ef610* entries[128]; char pad1[0x42c]; int mode; float elapsed; float limit1False,limit1True,limit2False,limit2True;
 void FUN_000e54d0(); bool target();
};
bool Object::target() {
 volatile union { unsigned int word; unsigned char bytes[4]; } ready;
 ready.word=(hulk_uintptr)this;
 ready.bytes[3]=1;
 void* timerContext=this;
 for(int i=0;i<128;++i) {
  Entry_ef610* entry=entries[i]; if(!entry) break;
  if(entry->timer.state==2) {
   float dt=DAT_004de948(timerContext);
   if(entry->timer.FUN_000fb4b0(dt)) ready.bytes[3]=0;
   timerContext=&entry->timer;
  }
 }
 hulk_intptr flag=context()->flag;
 if(mode==1 || mode==2) {
  float limit=mode==1 ? (flag ? limit1True:limit1False) : (flag ? limit2True:limit2False);
  if(ready.bytes[3] && limit<=elapsed) { FUN_000e54d0(); return false; }
 }
 elapsed=DAT_004de948((void*)flag)+elapsed;
 return true;
}
} // namespace fn_000ef610


// 0x000ef6e0 FEScreenBase::vfunc_14 (214 B): equivalent/0x000ef6e0.cpp [wrapped: conflict: FEScreenBase]
// sym: ?vfunc_14@FEScreenBase@fn_000ef6e0@@QAEXXZ @215fa313fe19 @w1c745ef1039c
namespace fn_000ef6e0 {
// STATUS: equivalent (tools/equiv.py level 3: 2992 inputs, branch coverage 12/12)
// FEScreenBase::vfunc_14 @ 0x000ef6e0
struct Settings_ef6e0 {
 char pad0[0x20]; unsigned value; char pad24[0xc]; unsigned z; unsigned x; float y; char pad3c[0x80]; unsigned char enabled;
};
struct Manager_ef6e0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(); virtual void slot9();
 virtual void slot10(); virtual void slot11(); virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15(); virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
 virtual void slot20(); virtual void slot21(); virtual void slot22(); virtual void slot23(); virtual void slot24(); virtual void slot25(); virtual void slot26(); virtual void slot27(); virtual void slot28(); virtual void slot29();
 virtual void slot30(); virtual void slot31(); virtual void slot32(); virtual void slot33(); virtual void slot34(); virtual void slot35(); virtual void slot36(); virtual void slot37(); virtual void slot38(); virtual void slot39();
 virtual void slot40(unsigned); virtual void slot41(); virtual void slot42(unsigned); virtual Settings_ef6e0* slot43();
 char pad[0x1850]; unsigned items[2];
};
struct Widget_ef6e0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7(); virtual void slot8(int); virtual void slot9(); virtual void slot10(int);
};
struct FEScreenBase {
 virtual void vfunc_0();
 Manager_ef6e0* manager;
 char pad8[0x40]; Widget_ef6e0* widget;
 char pad4c[0x944]; unsigned primary; unsigned items[4];
 char pad9a4[0x100]; unsigned x; float y; unsigned z; unsigned char enabled; char padab1[3]; unsigned value;
 void FUN_000e4640();
 void vfunc_14();
};
void FEScreenBase::vfunc_14() {
 manager->slot40(primary);
 manager->slot41();
 Manager_ef6e0* saved = manager;
 for(int i=0;i<2;++i) { unsigned item = saved->items[i]; if(item) saved->slot42(item); }
 for(int j=0;j<4;++j) { unsigned item = items[j]; if(item) manager->slot42(item); }
 Settings_ef6e0* settings = manager->slot43();
 settings->enabled = enabled;
 if(enabled) { unsigned savedX = x; settings->y = y; settings->x = savedX; settings->z = z; }
 settings->value = value;
 FUN_000e4640();
 if(widget) { widget->slot8(0); widget->slot10(2); }
}
} // namespace fn_000ef6e0


// 0x000ef7c0 FUN_000ef7c0 (93 B): matches/0x000ef7c0.cpp [wrapped: conflict: FEDialog]
// sym: ??0FEDialog@fn_000ef7c0@@QAE@HH@Z
namespace fn_000ef7c0 {
extern "C" void _ReadWriteBarrier();
class FEContainer_ef7c0 {
  public:
    FEContainer_ef7c0(int a, int b);
    virtual void v0();
    char pad[0x98c - 4];
};
struct Init1_ef7c0 {
    int m98c, m990, m994, m998, m99c, m9a0;
    Init1_ef7c0() {
        m98c = 0;
        m990 = 0;
        m994 = 0;
        m998 = 0;
        m99c = 0;
        m9a0 = 0;
    }
};
class FEDialog : public FEContainer_ef7c0, public Init1_ef7c0 {
  public:
    FEDialog(int a, int b);
    virtual void v0();
    int m9a4;
    char m9a8;
    char pad9a9[3];
    int m9ac;
};
FEDialog::FEDialog(int a, int b) : FEContainer_ef7c0(a, b) {
    _ReadWriteBarrier();
    m9a8 = 1;
    m9ac = 3;
    _ReadWriteBarrier();
    m9a4 = 0;
}
} // namespace fn_000ef7c0

namespace fn_f196c51b {

// 0x000ef820 FUN_000ef820 (42 B): matches/0x000ef820.cpp
// sym: ??1FEDialog_ef820@fn_f196c51b@@QAE@XZ
FEDialog_ef820::~FEDialog_ef820() throw() {
    vptr = hulk_at_0040c84c;
    _ReadWriteBarrier();
    if (m9a4) {
        m9a4->Release();
        m9a4 = 0;
    }
    Fin_000eeac0();
}

} // namespace fn_f196c51b

// 0x000ef850 FEDialog::vfunc_10 (16 B): matches/0x000ef850.cpp [wrapped: conflict: FEContainer; FEDialog]
// sym: ?vfunc_10@FEDialog@fn_000ef850@@UAEXXZ
namespace fn_000ef850 {
class FEContainer {
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
    virtual void vfunc_10();
    char pad[0x9a8 - 4];
};
class FEDialog : public FEContainer {
  public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void vfunc_10();
};
void FEDialog::vfunc_10() {
    if (*((char*)this + 0x9a8))
        FEContainer::vfunc_10();
}
} // namespace fn_000ef850


// 0x000ef890 FEMenuBase::vfunc_8 (4 B): matches/0x000ef890.cpp
// sym: ?vfunc_8@FEMenuBase@@UAEPAXXZ
// Same code shape as 0x000e45c0 (propagated; names are from that function)
void* FEMenuBase::vfunc_8() {
    return (void*)((FEMenuBase*)((char*)this + 8));
}


// 0x000ef8a0 FEMenuBase::vfunc_34 (4 B): matches/0x000ef8a0.cpp
// sym: ?vfunc_34@FEMenuBase@@UAEHXZ
// Same code shape as 0x00086370 (propagated; names are from that function)
int FEMenuBase::vfunc_34() {
    return (*(int *)&this->f_48);
}


// 0x000ef8b0 FEMenuBase::vfunc_35 (7 B): matches/0x000ef8b0.cpp
// sym: ?vfunc_35@FEMenuBase@@UAEHXZ
// Same code shape as 0x000ef3e0 (propagated; names are from that function)
int FEMenuBase::vfunc_35() {
    return *(int*)((char*)this + 0x990);
}


// 0x000ef8c0 FEMenuBase::vfunc_54 (46 B): matches/0x000ef8c0.cpp [wrapped: conflict: FEMenuBase]
// sym: ?v54@FEMenuBase@fn_000ef8c0@@UAEXPAX@Z
namespace fn_000ef8c0 {
class FEMenuBase {
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
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(void*);
    char pad[0x990 - 4];
    void* volatile mObj;
};
class Obj_ef8c0 {
  public:
    virtual void f0();
    virtual void f1();
};
void FEMenuBase::v54(void* p) {
    Obj_ef8c0* old = (Obj_ef8c0*)mObj;
    if (old) {
        old->f1();
        mObj = 0;
    }
    mObj = p;
    ((Obj_ef8c0*)p)->f0();
}
} // namespace fn_000ef8c0

namespace fn_f196c51b {

// 0x000ef8f0 FUN_000ef8f0 (42 B): matches/0x000ef8f0.cpp
// sym: ??1FEMenuBase_ef8f0@fn_f196c51b@@QAE@XZ
FEMenuBase_ef8f0::~FEMenuBase_ef8f0() throw() {
    vptr = hulk_at_0040c924;
    _ReadWriteBarrier();
    if (m990) {
        m990->Release();
        m990 = 0;
    }
    Fin_000ef400();
}


// 0x000ef920 FUN_000ef920 (425 B): matches/0x000ef920.cpp
// sym: ??1FEThingsBase_ef920@fn_f196c51b@@QAE@XZ
// data: g_ref_ef920 = DAT_004de954
FEThingsBase_ef920::~FEThingsBase_ef920() throw() {
    vptr = hulk_at_0040ca04;
    for (int i = 0; i < 64; i++)
        if (a[i]) {
            a[i]->D(1);
            a[i] = 0;
        }
    for (int i = 0; i < 256; i++)
        if (b[i]) {
            b[i]->D(1);
            b[i] = 0;
        }
    for (int i = 0; i < 1024; i++)
        if (c[i]) {
            c[i]->D(1);
            c[i] = 0;
        }
    for (int i = 0; i < 64; i++)
        if (d[i]) {
            Free_0008d330(d[i]);
            d[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (e[i]) {
            e[i]->Release();
            e[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (f[i]) {
            f[i]->Release();
            f[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (g[i]) {
            g[i]->Release();
            g[i] = 0;
        }
    for (int i = 0; i < 2; i++)
        if (h[i]) {
            h[i]->Release();
            h[i] = 0;
        }
    {
        A_ef920* t = m4;
        if (t) {
            t->Fin_000df700();
            Free_0008d330(t);
            m4 = 0;
        }
    }
    {
        B_ef920* t = m8;
        if (t) {
            t->Fin_000f8bd0();
            Free_0008d330(t);
            m8 = 0;
        }
    }
    if (m17fc) {
        m17fc->Release();
        m17fc = 0;
    }
    if (m1818) {
        m1818->Release();
        m1818 = 0;
    }
    if ((*(Ref_ef920**)&DAT_004de954)) {
        (*(Ref_ef920**)&DAT_004de954)->Release();
        (*(Ref_ef920**)&DAT_004de954) = 0;
    }
    hvptr = g_vftable2;
    for (int j = 0; j < 32; j++)
        if (ii[j]) {
            ii[j]->D(1);
            ii[j] = 0;
        }
}

} // namespace fn_f196c51b

// 0x000efad0 FEThingsBase::vfunc_49 (3 B): matches/0x000efad0.cpp
// sym: ?vfunc_49@FEThingsBase@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FEThingsBase::vfunc_49(hulk_intptr a) {
    (void)a;
}


// 0x000efae0 FEThingsBase::vfunc_48 (3 B): matches/0x000efae0.cpp
// sym: ?vfunc_48@FEThingsBase@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void FEThingsBase::vfunc_48(int a) {
    (void)a;
}


// 0x000efaf0 FEThingsBase::vfunc_4 (388 B): equivalent/0x000efaf0.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_4@FEThingsBase@fn_000efaf0@@UAEXXZ @87290f87a0c2 @w86e2d7951bf6
namespace fn_000efaf0 {
// STATUS: equivalent (tools/equiv.py level 3: 26 inputs, branch coverage 36/36)
// FEThingsBase::vfunc_4 @ 0x000efaf0
struct Owned_efaf0 {
    virtual ~Owned_efaf0();
};
struct Released {
    virtual void vfn0();
    virtual void vfn1();
};
class FEThingsBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad0[0x8];
    Owned_efaf0 *objsA[0x40];       // 0xc
    Owned_efaf0 *objsB[0x40];       // 0x10c
    Owned_efaf0 *objsC[0x100];      // 0x20c
    Owned_efaf0 *objsD[0x400];      // 0x60c
    char pad1[0x170c - 0x160c];
    char flag170c;
    char pad2[0x175c - 0x170d];
    int f175c;
    int f1760;
    char pad3[4];
    int f1768;
    int f176c;
    int tab1770[16];
    int f17b0;
    int tab17b4[16];
    int f17f4;
    char pad4[0x1830 - 0x17f8];
    int f1830;
    char pad5[0x1854 - 0x1834];
    Released *resA[2];        // 0x1854
    char pad6[0x1a5c - 0x185c];
    Released *resB[2];        // 0x1a5c
    char pad7[0x1c64 - 0x1a64];
    Released *resC[2];        // 0x1c64
    Released *resD[2];        // 0x1c6c
    char pad8[0x2080 - 0x1c74];
    int slots2080[0x20];
    int f2100;
    char flag2104;
};

void FEThingsBase::vfunc_4()
{
    int i;
    f175c = 0;
    f1768 = 0;
    f1760 = 0;
    for (i = 0; i < 16; i++) tab1770[i] = 0;
    f17b0 = -1;
    for (i = 0; i < 16; i++) tab17b4[i] = 0;
    f17f4 = -1;
    f176c = 0;
    f1830 = 0;
    for (i = 0; i < 0x20 && slots2080[i] != 0; i++) slots2080[i] = 0;
    flag170c = 0;
    for (i = 0; i < 0x40; i++) {
        if (objsA[i]) { delete objsA[i]; objsA[i] = 0; }
    }
    for (i = 0; i < 0x40; i++) {
        if (objsB[i]) { delete objsB[i]; objsB[i] = 0; }
    }
    for (i = 0; i < 0x100; i++) {
        if (objsC[i]) { delete objsC[i]; objsC[i] = 0; }
    }
    for (i = 0; i < 0x400; i++) {
        if (objsD[i]) { delete objsD[i]; objsD[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resA[i]) { resA[i]->vfn1(); resA[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resB[i]) { resB[i]->vfn1(); resB[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resC[i]) { resC[i]->vfn1(); resC[i] = 0; }
    }
    for (i = 0; i < 2; i++) {
        if (resD[i]) { resD[i]->vfn1(); resD[i] = 0; }
    }
    f2100 = 0;
    flag2104 = 0;
}
} // namespace fn_000efaf0

namespace fn_f196c51b {

// 0x000efc80 FUN_000efc80 (19 B): matches/0x000efc80.cpp
// sym: ?FUN_000efc80@ThisWrap_000efc80@fn_f196c51b@@QAEPAXPAX@Z
void* ThisWrap_000efc80::FUN_000efc80(void* arg) {
    return ((Obj_efc80*)this->FUN_000e7620(arg))->value;
}

} // namespace fn_f196c51b

// 0x000efca0 FUN_000efca0 (253 B): equivalent/0x000efca0.cpp [wrapped: conflict: FEMenuBase]
// sym: ?FUN_000efca0@Manager_efca0@fn_000efca0@@QAEPAUFEMenuBase@2@PBDH@Z @4951452272b5 @w8879a4a3e16d
namespace fn_000efca0 {
// STATUS: equivalent (tools/equiv.py level 3: 2995 inputs, branch coverage 24/24)
// FUN_000efca0 @ 0x000efca0
void* __cdecl FUN_0008d690(unsigned int);
struct Manager_efca0;
struct FEMenuBase {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4_000ef100(); virtual void v5_000ef030(); virtual void v6_000ef120(); virtual void v7_000ef160(); virtual const char* v8_000ef890();
 virtual void v9_000e4c30(); virtual void v10_000ef4f0(); virtual void v11_000e5220(); virtual void v12(); virtual void v13(); virtual void v14_000ef6e0(); virtual void v15_000e5600(); virtual void v16(); virtual void v17_000e45d0(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34_000ef8a0(); virtual void v35_000ef8b0(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51_000e45f0(); virtual void v52(); virtual void v53(); virtual void v54(int);
 char pad[0x98c]; int field990; char tail[0x230];
 void FUN_000ef180(Manager_efca0*,const char*);
};
struct Manager_efca0 { char pad[0x20c]; FEMenuBase* menus[256]; FEMenuBase* FUN_000efca0(const char*,int); };
FEMenuBase* Manager_efca0::FUN_000efca0(const char* name,int arg) {
 FEMenuBase* found=0;
 for(int i=0;i<256;++i) {
  if(menus[i]) {
   const char* s=menus[i]->v8_000ef890(); const char* p=name;
   while(*p==*s && *p) { ++p; ++s; }
   if(*p==*s) { found=menus[i]; break; }
  }
 }
 if(found) return found;
 int slot=0; while(slot<256 && menus[slot]) ++slot;
 if(slot==256) return found;
 found=(FEMenuBase*)FUN_0008d690((int)sizeof(FEMenuBase));
 if(found) {
 found->FUN_000ef180(this,name);
 found->FEMenuBase::FEMenuBase();
 found->field990=0;
 }
 menus[slot]=found;
 if(found) found->v54(arg);
 return found;
}
} // namespace fn_000efca0


// 0x000efda0 FEThingsBase::vfunc_50 (43 B): matches/0x000efda0.cpp
// sym: ?vfunc_50@FEThingsBase@@UAEHHH@Z
int FEThingsBase::vfunc_50(int a, int b) {
    hulk_intptr x = FUN_0008d690(0xbc4);
    if (x)
        return ((Helper_efda0*)x)->call_000ef180(this, b);
    return 0;
}


// 0x000efdd0 FEThingsBase::vfunc_51 (43 B): matches/0x000efdd0.cpp
// sym: ?vfunc_51@FEThingsBase@@UAEHHH@Z
int FEThingsBase::vfunc_51(int a, int b) {
    hulk_intptr x = lookup_0008d690(0x9b0);
    if (x)
        return ((Helper_efdd0*)x)->forwarder_000ef7c0(this, b);
    return 0;
}


// 0x000efe00 FEThingsBase::vfunc_53 (29 B): matches/0x000efe00.cpp
// sym: ?vfunc_53@FEThingsBase@@UAEHH@Z
int FEThingsBase::vfunc_53(int x) {
    Helper_efe00* p = (Helper_efe00*)FUN_0008d690(0x980);
    if (p)
        return p->call_000ecd70(x);
    return 0;
}


// 0x000efe20 FEThingsBase::vfunc_54 (29 B): matches/0x000efe20.cpp
// sym: ?vfunc_54@FEThingsBase@@UAEHH@Z
int FEThingsBase::vfunc_54(int __p0) { uint_efe20 a = (uint_efe20)__p0;

    TextTable_efe20* p = (TextTable_efe20*)FUN_0008d690(0x4990);
    if (p)
        return (int)(p->run_000ed820(a));
    return (int)(0);
}


// 0x000efe40 FEThingsBase::vfunc_55 (29 B): matches/0x000efe40.cpp
// sym: ?vfunc_55@FEThingsBase@@UAEHH@Z
int FEThingsBase::vfunc_55(int x) {
    Thing_efe40* p = (Thing_efe40*)allocThing_0008d690(0x2b0);
    if (p)
        return p->init_000edf60(x);
    return 0;
}


// 0x000efe60 FEThingsBase::vfunc_57 (29 B): matches/0x000efe60.cpp
// sym: ?vfunc_57@FEThingsBase@@UAEHH@Z
int FEThingsBase::vfunc_57(int x) {
    Thing_efe60* p = (Thing_efe60*)alloc_0008d690(0x1f8);
    if (p)
        return p->init_000e9ec0(x);
    return 0;
}


// 0x000efe80 FEThingsBase::vfunc_58 (39 B): matches/0x000efe80.cpp
// sym: ?vfunc_58@FEThingsBase@@UAEHPAX@Z
int FEThingsBase::vfunc_58(void* __p0) { void * p = (void *)__p0;

    void* q = GetThing_0008d690(0x1da8);
    if (q)
        return ((Helper_efe80*)q)->DoThing_000ebb90(p, 0);
    return 0;
}


// 0x000efee0 FEThingsBase::vfunc_60 (60 B): matches/0x000efee0.cpp [wrapped: conflict: FEThingsBase; MapThing]
// sym: ?vfunc_60@FEThingsBase@fn_000efee0@@UAEPAUMapThing@2@PAX@Z
namespace fn_000efee0 {
extern "C" char DAT_0040c5c4[];
extern void* alloc_0008d690(hulk_uintptr);
struct MapThing {
    hulk_uintptr vf;
    char pad[0x114];
    int value;
    void init_000e2860(void*);
};
struct FEThingsBase {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad();
    virtual void ae();
    virtual void af();
    virtual void ag();
    virtual void ah();
    virtual void ai();
    virtual void aj();
    virtual void ak();
    virtual void al();
    virtual void am();
    virtual void an();
    virtual void ao();
    virtual void ap();
    virtual void aq();
    virtual void ar();
    virtual void as();
    virtual void at();
    virtual void au();
    virtual void av();
    virtual void aw();
    virtual void ax();
    virtual void ay();
    virtual void az();
    virtual void ba();
    virtual void bb();
    virtual void bc();
    virtual void bd();
    virtual void be();
    virtual void bf();
    virtual void bg();
    virtual void bh();
    virtual void bi();
    virtual void bj();
    virtual void bk();
    virtual void bl();
    virtual void bm();
    virtual void bn();
    virtual void bo();
    virtual void bp();
    virtual void bq();
    virtual void br();
    virtual void bs();
    virtual void bt();
    virtual void bu();
    virtual void bv();
    virtual void bw();
    virtual void bx();
    virtual void by();
    virtual void bz();
    virtual void ca();
    virtual void cb();
    virtual void cc();
    virtual void cd();
    virtual void ce();
    virtual void cf();
    virtual void cg();
    virtual void ch();
    virtual void ci();
    virtual void cj();
    virtual void ck();
    virtual void cl();
    virtual void cm();
    virtual void cn();
    virtual void co();
    virtual void cp();
    virtual void cq();
    virtual void cr();
    virtual void cs();
    virtual void ct();
    virtual void cu();
    virtual void cv();
    virtual void cw();
    virtual void cx();
    virtual void cy();
    virtual void cz();
    virtual void da();
    virtual void db();
    virtual void dc();
    virtual void dd();
    virtual void de();
    virtual void df();
    virtual void dg();
    virtual void dh();
    virtual void di();
    virtual void dj();
    virtual void dk();
    virtual void dl();
    virtual void dm();
    virtual void dn();
    virtual void doo();
    virtual void dp();
    virtual void dq();
    virtual void dr();
    virtual void ds();
    virtual void dt();
    virtual void du();
    virtual void dv();
    virtual void dw();
    virtual void dx();
    virtual void dy();
    virtual void dz();
    virtual void ea();
    virtual void eb();
    virtual void ec();
    virtual void ed();
    virtual void ee();
    virtual void ef();
    virtual void eg();
    virtual void eh();
    virtual void ei();
    virtual void ej();
    virtual void ek();
    virtual void el();
    virtual void em();
    virtual void en();
    virtual void eo();
    virtual void ep();
    virtual void eq();
    virtual void er();
    virtual void es();
    virtual void et();
    virtual void eu();
    virtual void ev();
    virtual void ew();
    virtual void ex();
    virtual void ey();
    virtual void ez();
    virtual void fa();
    virtual void fb();
    virtual void fc();
    virtual void fd();
    virtual void fe();
    virtual void ff();
    virtual void fg();
    virtual void fh();
    virtual void fi();
    virtual void fj();
    virtual void fk();
    virtual void fl();
    virtual void fm();
    virtual void fn();
    virtual void fo();
    virtual void fp();
    virtual void fq();
    virtual void fr();
    virtual void fs();
    virtual void ft();
    virtual void fu();
    virtual void fv();
    virtual void fw();
    virtual void fx();
    virtual void fy();
    virtual void fz();
    virtual void ga();
    virtual void gb();
    virtual void gc();
    virtual void gd();
    virtual void ge();
    virtual void gf();
    virtual void gg();
    virtual void gh();
    virtual void gi();
    virtual void gj();
    virtual void gk();
    virtual void gl();
    virtual void gm();
    virtual void gn();
    virtual void go();
    virtual void gp();
    virtual void gq();
    virtual void gr();
    virtual void gs();
    virtual void gt();
    virtual void gu();
    virtual void gv();
    virtual void gw();
    virtual void gx();
    virtual void gy();
    virtual void gz();
    virtual void ha();
    virtual void hb();
    virtual void hc();
    virtual void hd();
    virtual void he();
    virtual void hf();
    virtual void hg();
    virtual void hh();
    virtual void hi();
    virtual void hj();
    virtual void hk();
    virtual void hl();
    virtual void hm();
    virtual void hn();
    virtual void ho();
    virtual void hp();
    virtual void hq();
    virtual void hr();
    virtual void hs();
    virtual void ht();
    virtual void hu();
    virtual void hv();
    virtual void hw();
    virtual void hx();
    virtual void hy();
    virtual void hz();
    virtual void ia();
    virtual void ib();
    virtual void ic();
    virtual void id();
    virtual void ie();
    virtual void iff();
    virtual void ig();
    virtual void ih();
    virtual void ii();
    virtual void ij();
    virtual void ik();
    virtual void il();
    virtual void im();
    virtual void in();
    virtual void io();
    virtual void ip();
    virtual void iq();
    virtual void ir();
    virtual void is();
    virtual void it();
    virtual void iu();
    virtual void iv();
    virtual void iw();
    virtual void ix();
    virtual void iy();
    virtual void iz();
    virtual void ja();
    virtual void jb();
    virtual void jc();
    virtual void jd();
    virtual void je();
    virtual void jf();
    virtual void jg();
    virtual void jh();
    virtual void ji();
    virtual void jj();
    virtual void jk();
    virtual void jl();
    virtual void jm();
    virtual void jn();
    virtual void jo();
    virtual void jp();
    virtual void jq();
    virtual void jr();
    virtual void js();
    virtual void jt();
    virtual void ju();
    virtual void jv();
    virtual void jw();
    virtual void jx();
    virtual void jy();
    virtual void jz();
    virtual void ka();
    virtual void kb();
    virtual void kc();
    virtual void kd();
    virtual void ke();
    virtual void kf();
    virtual void kg();
    virtual void kh();
    virtual void ki();
    virtual void kj();
    virtual void kk();
    virtual void kl();
    virtual void km();
    virtual void kn();
    virtual void ko();
    virtual void kp();
    virtual void kq();
    virtual void kr();
    virtual void ks();
    virtual void kt();
    virtual void ku();
    virtual void kv();
    virtual void kw();
    virtual void kx();
    virtual void ky();
    virtual void kz();
    virtual void la();
    virtual void lb();
    virtual void lc();
    virtual void ld();
    virtual void le();
    virtual void lf();
    virtual void lg();
    virtual void lh();
    virtual void li();
    virtual void lj();
    virtual void lk();
    virtual void ll();
    virtual void lm();
    virtual void ln();
    virtual void lo();
    virtual void lp();
    virtual void lq();
    virtual void lr();
    virtual void ls();
    virtual void lt();
    virtual void lu();
    virtual void lv();
    virtual void lw();
    virtual void lx();
    virtual void ly();
    virtual void lz();
    virtual void ma();
    virtual void mb();
    virtual void mc();
    virtual void md();
    virtual void me();
    virtual void mf();
    virtual void mg();
    virtual void mh();
    virtual void mi();
    virtual void mj();
    virtual void mk();
    virtual void ml();
    virtual void mm();
    virtual void mn();
    virtual void mo();
    virtual void mp();
    virtual void mq();
    virtual void mr();
    virtual void ms();
    virtual void mt();
    virtual void mu();
    virtual void mv();
    virtual void mw();
    virtual void mx();
    virtual void my();
    virtual void mz();
    virtual void na();
    virtual void nb();
    virtual void nc();
    virtual void nd();
    virtual void ne();
    virtual void nf();
    virtual void ng();
    virtual void nh();
    virtual void ni();
    virtual void nj();
    virtual void nk();
    virtual void nl();
    virtual void nm();
    virtual void nn();
    virtual void no();
    virtual void np();
    virtual void nq();
    virtual void nr();
    virtual void ns();
    virtual void nt();
    virtual void nu();
    virtual void nv();
    virtual void nw();
    virtual void nx();
    virtual void ny();
    virtual void nz();
    virtual void oa();
    virtual void ob();
    virtual void oc();
    virtual void od();
    virtual void oe();
    virtual void of();
    virtual void og();
    virtual void oh();
    virtual void oi();
    virtual void oj();
    virtual void ok();
    virtual void ol();
    virtual void om();
    virtual void on();
    virtual void oo();
    virtual void op();
    virtual void oq();
    virtual void or ();
    virtual void os();
    virtual void ot();
    virtual void ou();
    virtual void ov();
    virtual void ow();
    virtual void ox();
    virtual void oy();
    virtual void oz();
    virtual void pa();
    virtual void pb();
    virtual void pc();
    virtual void pd();
    virtual void pe();
    virtual void pf();
    virtual void pg();
    virtual void ph();
    virtual void pi();
    virtual void pj();
    virtual void pk();
    virtual void pl();
    virtual void pm();
    virtual void pn();
    virtual void po();
    virtual void pp();
    virtual void pq();
    virtual void pr();
    virtual void ps();
    virtual void pt();
    virtual void pu();
    virtual void pv();
    virtual void pw();
    virtual void px();
    virtual void py();
    virtual void pz();
    virtual void qa();
    virtual void qb();
    virtual void qc();
    virtual void qd();
    virtual void qe();
    virtual void qf();
    virtual void qg();
    virtual void qh();
    virtual void qi();
    virtual void qj();
    virtual void qk();
    virtual void ql();
    virtual void qm();
    virtual void qn();
    virtual void qo();
    virtual void qp();
    virtual void qq();
    virtual void qr();
    virtual void qs();
    virtual void qt();
    virtual void qu();
    virtual void qv();
    virtual void qw();
    virtual void qx();
    virtual void qy();
    virtual void qz();
    virtual void ra();
    virtual void rb();
    virtual void rc();
    virtual void rd();
    virtual void re();
    virtual void rf();
    virtual void rg();
    virtual void rh();
    virtual void ri();
    virtual void rj();
    virtual void rk();
    virtual void rl();
    virtual void rm();
    virtual void rn();
    virtual void ro();
    virtual void rp();
    virtual void rq();
    virtual void rr();
    virtual void rs();
    virtual void rt();
    virtual void ru();
    virtual void rv();
    virtual void rw();
    virtual void rx();
    virtual void ry();
    virtual void rz();
    virtual void sa();
    virtual void sb();
    virtual void sc();
    virtual void sd();
    virtual void se();
    virtual void sf();
    virtual void sg();
    virtual void sh();
    virtual void si();
    virtual void sj();
    virtual void sk();
    virtual void sl();
    virtual void sm();
    virtual void sn();
    virtual void so();
    virtual void sp();
    virtual void sq();
    virtual void sr();
    virtual void ss();
    virtual void st();
    virtual void su();
    virtual void sv();
    virtual void sw();
    virtual void sx();
    virtual void sy();
    virtual void sz();
    virtual void ta();
    virtual void tb();
    virtual void tc();
    virtual void td();
    virtual void te();
    virtual void tf();
    virtual void tg();
    virtual void th();
    virtual void ti();
    virtual void tj();
    virtual void tk();
    virtual void tl();
    virtual void tm();
    virtual void tn();
    virtual void to();
    virtual void tp();
    virtual void tq();
    virtual void tr();
    virtual void ts();
    virtual void tt();
    virtual void tu();
    virtual void tv();
    virtual void tw();
    virtual void tx();
    virtual void ty();
    virtual void tz();
    virtual void ua();
    virtual void ub();
    virtual void uc();
    virtual void ud();
    virtual void ue();
    virtual void uf();
    virtual void ug();
    virtual void uh();
    virtual void ui();
    virtual void uj();
    virtual void uk();
    virtual void ul();
    virtual void um();
    virtual void un();
    virtual void uo();
    virtual void up();
    virtual void uq();
    virtual void ur();
    virtual void us();
    virtual void ut();
    virtual void uu();
    virtual void uv();
    virtual void uw();
    virtual void ux();
    virtual void uy();
    virtual void uz();
    virtual void va();
    virtual void vb();
    virtual void vc();
    virtual void vd();
    virtual void ve();
    virtual void vf();
    virtual void vg();
    virtual void vh();
    virtual void vi();
    virtual void vj();
    virtual void vk();
    virtual void vl();
    virtual void vm();
    virtual void vn();
    virtual void vo();
    virtual void vp();
    virtual void vq();
    virtual void vr();
    virtual void vs();
    virtual void vt();
    virtual void vu();
    virtual void vv();
    virtual void vw();
    virtual void vx();
    virtual void vy();
    virtual void vz();
    virtual void wa();
    virtual void wb();
    virtual void wc();
    virtual void wd();
    virtual void we();
    virtual void wf();
    virtual void wg();
    virtual void wh();
    virtual void wi();
    virtual void wj();
    virtual void wk();
    virtual void wl();
    virtual void wm();
    virtual void wn();
    virtual void wo();
    virtual void wp();
    virtual void wq();
    virtual void wr();
    virtual void ws();
    virtual void wt();
    virtual void wu();
    virtual void wv();
    virtual void ww();
    virtual void wx();
    virtual void wy();
    virtual void wz();
    virtual void xa();
    virtual void xb();
    virtual void xc();
    virtual void xd();
    virtual void xe();
    virtual void xf();
    virtual void xg();
    virtual void xh();
    virtual void xi();
    virtual void xj();
    virtual void xk();
    virtual void xl();
    virtual void xm();
    virtual void xn();
    virtual void xo();
    virtual void xp();
    virtual void xq();
    virtual void xr();
    virtual void xs();
    virtual void xt();
    virtual void xu();
    virtual void xv();
    virtual void xw();
    virtual void xx();
    virtual void xy();
    virtual void xz();
    virtual void ya();
    virtual void yb();
    virtual void yc();
    virtual void yd();
    virtual void ye();
    virtual void yf();
    virtual void yg();
    virtual void yh();
    virtual void yi();
    virtual void yj();
    virtual void yk();
    virtual void yl();
    virtual void ym();
    virtual void yn();
    virtual void yo();
    virtual void yp();
    virtual void yq();
    virtual void yr();
    virtual void ys();
    virtual void yt();
    virtual void yu();
    virtual void yv();
    virtual void yw();
    virtual void yx();
    virtual void yy();
    virtual void yz();
    virtual void za();
    virtual void zb();
    virtual void zc();
    virtual void zd();
    virtual void ze();
    virtual void zf();
    virtual void zg();
    virtual void zh();
    virtual void zi();
    virtual void zj();
    virtual void zk();
    virtual void zl();
    virtual void zm();
    virtual void zn();
    virtual void zo();
    virtual void zp();
    virtual void zq();
    virtual void zr();
    virtual void zs();
    virtual void zt();
    virtual void zu();
    virtual void zv();
    virtual void zw();
    virtual void zx();
    virtual void zy();
    virtual void zz();
    virtual MapThing* vfunc_60(void*);
};
MapThing* FEThingsBase::vfunc_60(void* p) {
    MapThing* q = (MapThing*)alloc_0008d690(0x120);
    if (q) {
        q->init_000e2860(p);
        q->vf = ((hulk_intptr)DAT_0040c5c4);
        q->value = -1;
        return q;
    }
    return 0;
}
} // namespace fn_000efee0


// 0x000eff20 FUN_000eff20 (1634 B): equivalent/0x000eff20.cpp [wrapped: conflict: FEDoBackScreen; FEDoWait]
// sym: ?FUN_000eff20@Builder@fn_000eff20@@QAEXTSlot1@2@PAUParent_eff20@2@PAUSink_eff20@2@H@Z @4ee1d137d589 @wfbda8658b162
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_000eff20 {
// STATUS: equivalent (tools/equiv.py level 3: 3110 inputs, branch coverage 125/126, incomplete)
// FUN_000eff20 @ 0x000eff20
// equiv-map: ??_R0?AVCScriptToken@DollyScript@@@8 = 0x004a13e4
// equiv-map: ??_R0?AVCTokenString@DollyScript@@@8 = 0x004a140c
// equiv-map: ??_R0?AVCTokenFloat@DollyScript@@@8 = 0x004a13bc

void *FUN_0008d690(unsigned int size);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *__cdecl strncpy(char *, const char *, unsigned int);
#endif

void *__cdecl FUN_000f6610(const char *s);

namespace DollyScript {
class CScriptToken {
public:
    virtual void t0();
    virtual unsigned int GetType();
};
class CTokenString : public CScriptToken {
public:
    char pad04[0xc];
    const char *str;
};
class CTokenFloat : public CScriptToken {
public:
    char pad04[0xc];
    unsigned int value;
};
}

struct Parser_eff20 {
    float FUN_000fad30();
    unsigned int FUN_000faeb0();
    const char *FUN_000fad90();
    void FUN_000fa0a0();
    void FUN_000fa0b0(void *state);
    void FUN_000fa100(void *state);
    DollyScript::CScriptToken *FUN_000fb150();
};

class Callback_eff20 {
public:
    virtual void a();
    virtual void b();
};

class __declspec(novtable) FEDoAction_eff20 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    int type;
    int id1;
    int id2;
    void *parent;
    char name[0x20];
    FEDoAction_eff20(void *p)
    {
        id1 = -1;
        id2 = -1;
        parent = p;
        name[0] = 0;
    }
};

class FEDoWait : public FEDoAction_eff20 {
public:
    float limit;
    float elapsed;
    Callback_eff20 *callback;
    unsigned char done;
    FEDoWait(void *p, float lim) : FEDoAction_eff20(p)
    {
        limit = lim;
        callback = 0;
        elapsed = 0;
        done = 1;
    }
};

class FEDoBackScreen : public FEDoAction_eff20 {
public:
    unsigned char b34;
    unsigned char b35;
    FEDoBackScreen(void *p, unsigned char b, unsigned char c) : FEDoAction_eff20(p)
    {
        b34 = b;
        b35 = c;
    }
    FEDoBackScreen *FUN_000e1cf0(void *p, unsigned char b, unsigned char c);
};

struct FEDoSound_eff20 : FEDoAction_eff20 {
    char padA[0x54 - 0x34];
    FEDoSound_eff20 *FUN_000e1970(void *p, const char *s);
};
struct FEDoPopDialog_eff20 : FEDoAction_eff20 {
    char padB[0x34 - 0x34];
    FEDoPopDialog_eff20 *FUN_000e1c40(void *p);
};
struct FEDoBackMenu_eff20 : FEDoAction_eff20 {
    char padC[0x34 - 0x34];
    FEDoBackMenu_eff20 *FUN_000e1c60(void *p);
};
struct FEDoMenu_eff20 : FEDoAction_eff20 {
    char padE[0x54 - 0x34];
    FEDoMenu_eff20 *FUN_000e1b30(void *p, const char *s);
};
struct FEDoScreen_eff20 : FEDoAction_eff20 {
    char padF[0x54 - 0x34];
    FEDoScreen_eff20 *FUN_000e1c90(void *p, const char *s);
};
struct FEDoPushDialog_eff20 : FEDoAction_eff20 {
    char padG[0x1b8 - 0x34];
    FEDoPushDialog_eff20 *FUN_000e1b90(void *p, const char *a, const char *b, const char *c, const char *d, const char *e, int mode);
};
struct FEDoFunction_eff20 : FEDoAction_eff20 {
    char padS[0x3c - 0x34];
    int *items;
    FEDoFunction_eff20 *FUN_000e19d0(void *p, const char *name, int count);
};
struct FEDoAnimation_eff20 : FEDoAction_eff20 {
    char padH[0x40 - 0x34];
    unsigned int f40;
    char pad44[4];
    unsigned int f48;
    unsigned int f4c;
    char pad50;
    unsigned char b51;
    FEDoAnimation_eff20 *FUN_000e8a90(void *p, const char *s);
    void FUN_000e8650(unsigned int v);
    void FUN_000e86a0(unsigned int v);
};

class Owner_eff20 {
public:
    virtual void o0();
};
struct Parent_eff20 {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void Add(FEDoAction_eff20 *c);
};
struct Sink_eff20 {
    void FUN_000e2c60(FEDoAction_eff20 *c);
};

union Slot1 {
    Parser_eff20 *p;
    float f;
    unsigned char b;
    FEDoAction_eff20 *cmd;
    const char *s;
};

struct Frame_eff20 {
    hulk_uintptr off; // 0x10
    FEDoWait *objA;   // 0x14
    int id1;          // 0x18
    int id2;          // 0x1c
    const char *name; // 0x20
    void *self;       // 0x24
    const char *v1;   // 0x28
    unsigned int state[5]; // 0x2c
};

class Builder {
public:
    void FUN_000e76a0(FEDoAction_eff20 *c);
    void FUN_000eff20(Slot1 a1, Parent_eff20 *a2, Sink_eff20 *a3, int a4);
};

void Builder::FUN_000eff20(Slot1 a1, Parent_eff20 *a2, Sink_eff20 *a3, int a4)
{
    Frame_eff20 f;
    Parser_eff20 *p = a1.p;
    FEDoAction_eff20 *cmd = 0;
    int type = a4;
    f.self = this;
    f.objA = 0;
    f.id1 = 0;
    f.id2 = 0;
    f.name = "";
    Parent_eff20 *parent = a2;
    if (type == 4) {
        f.id1 = (int)p->FUN_000fad30();
        f.id2 = (int)p->FUN_000fad30();
    }
    int h = (int)p->FUN_000faeb0();
    if (h == (int)0xb07efca4) {
        f.name = p->FUN_000fad90();
        h = (int)p->FUN_000faeb0();
    }
    if (h == (int)0x9043fffb) {
        a1.f = p->FUN_000fad30();
        void *mem = FUN_0008d690(sizeof(FEDoWait));
        FEDoWait *w = 0;
        parent = a2;
        if (mem != 0)
            w = new (mem) FEDoWait(parent, a1.f);
        f.objA = w;
        w->type = type;
        h = (int)p->FUN_000faeb0();
    } else {
        parent = a2;
    }
    a1.b = 0;
    switch (h) {
    case (int)0x99d29fa1: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoSound_eff20));
        if (mem != 0)
            cmd = ((FEDoSound_eff20 *)mem)->FUN_000e1970(parent, s);
        cmd->type = type;
        break;
    }
    case (int)0x8df5383d: {
        void *mem = FUN_0008d690(sizeof(FEDoPopDialog_eff20));
        if (mem != 0)
            cmd = ((FEDoPopDialog_eff20 *)mem)->FUN_000e1c40(parent);
        cmd->type = type;
        break;
    }
    case (int)0xbe65b9e4: {
        void *mem = FUN_0008d690(sizeof(FEDoBackMenu_eff20));
        if (mem != 0)
            cmd = ((FEDoBackMenu_eff20 *)mem)->FUN_000e1c60(parent);
        cmd->type = type;
        break;
    }
    case (int)0x46667bbc: {
        const char *nm = p->FUN_000fad90();
        if (nm == 0)
            p->FUN_000fa0a0();
        p->FUN_000fa0b0(f.state);
        int count = 0;
        if (p->FUN_000fb150() != 0) {
            do {
                count++;
            } while (p->FUN_000fb150() != 0);
        }
        void *mem = FUN_0008d690(sizeof(FEDoFunction_eff20));
        FEDoFunction_eff20 *seq = 0;
        if (mem != 0)
            seq = ((FEDoFunction_eff20 *)mem)->FUN_000e19d0(a2, nm, count);
        a1.cmd = seq;
        cmd = a1.cmd;
        p->FUN_000fa100(f.state);
        DollyScript::CScriptToken *t = p->FUN_000fb150();
        if (t != 0) {
            f.off = 0;
            do {
                DollyScript::CTokenString *ts = dynamic_cast<DollyScript::CTokenString *>(t);
                if (ts == 0)
                    p->FUN_000fa0a0();
                const char *str = ts->str;
                if (str == 0)
                    str = "";
                FEDoFunction_eff20 *s2 = (FEDoFunction_eff20 *)a1.cmd;
                if (s2->items != 0)
                    *(hulk_intptr *)((char *)((FEDoFunction_eff20 *)a1.cmd)->items + f.off) = (hulk_intptr)FUN_000f6610(str);
                f.off += 4;
                t = p->FUN_000fb150();
            } while (t != 0);
        }
        ((FEDoFunction_eff20 *)a1.cmd)->type = type;
        break;
    }
    case (int)0x22989fa8:
        a1.b = 1;
    case (int)0xbabb057a: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoAnimation_eff20));
        FEDoAnimation_eff20 *ch = 0;
        if (mem != 0)
            ch = ((FEDoAnimation_eff20 *)mem)->FUN_000e8a90(parent, s);
        ch->b51 = a1.b;
        ch->type = type;
        DollyScript::CScriptToken *t = p->FUN_000fb150();
        if (t != 0) {
            if (t->GetType() == 0xdfc23ba3) {
                ch->f40 = 0x3f800000;
            } else {
                DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
                if (tf == 0)
                    p->FUN_000fa0a0();
                ch->FUN_000e8650(tf->value);
            }
        }
        t = p->FUN_000fb150();
        if (t != 0) {
            DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
            if (tf == 0)
                p->FUN_000fa0a0();
            ch->FUN_000e86a0(tf->value);
        }
        t = p->FUN_000fb150();
        if (t != 0) {
            DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
            if (tf == 0)
                p->FUN_000fa0a0();
            ch->f48 = tf->value;
        }
        t = p->FUN_000fb150();
        if (t != 0) {
            DollyScript::CTokenFloat *tf = dynamic_cast<DollyScript::CTokenFloat *>(t);
            if (tf == 0)
                p->FUN_000fa0a0();
            ch->f4c = tf->value;
        }
        cmd = ch;
        break;
    }
    case (int)0x4f1ef819: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoScreen_eff20));
        if (mem != 0)
            cmd = ((FEDoScreen_eff20 *)mem)->FUN_000e1c90(parent, s);
        cmd->type = type;
        break;
    }
    case (int)0x5bbae3fc: {
        const char *s = p->FUN_000fad90();
        if (s == 0)
            p->FUN_000fa0a0();
        void *mem = FUN_0008d690(sizeof(FEDoMenu_eff20));
        if (mem != 0)
            cmd = ((FEDoMenu_eff20 *)mem)->FUN_000e1b30(parent, s);
        cmd->type = type;
        break;
    }
    case (int)0x5e245a31: {
        void *mem = FUN_0008d690(sizeof(FEDoBackScreen));
        if (mem != 0)
            cmd = ((FEDoBackScreen *)mem)->FUN_000e1cf0(parent, 0, 0);
        cmd->type = type;
        break;
    }
    case (int)0x70fab569: {
        void *mem = FUN_0008d690(sizeof(FEDoBackScreen));
        if (mem != 0)
            cmd = ((FEDoBackScreen *)mem)->FUN_000e1cf0(parent, 1, 0);
        cmd->type = type;
        break;
    }
    case (int)0x6ea9b311: {
        void *mem = FUN_0008d690(sizeof(FEDoBackScreen));
        if (mem != 0)
            cmd = new (mem) FEDoBackScreen(parent, 0, 1);
        cmd->type = type;
        break;
    }
    case (int)0x6a10e620: {
        f.v1 = p->FUN_000fad90();
        if (f.v1 == 0)
            p->FUN_000fa0a0();
        const char *v2 = p->FUN_000fad90();
        f.off = (hulk_uintptr)v2;
        if (v2 == 0)
            p->FUN_000fa0a0();
        a1.s = p->FUN_000fad90();
        if (a1.s == 0)
            p->FUN_000fa0a0();
        const char *v4 = p->FUN_000fad90();
        if (v4 == 0)
            p->FUN_000fa0a0();
        const char *v5 = p->FUN_000fad90();
        if (v5 == 0)
            p->FUN_000fa0a0();
        int mode = 0;
        unsigned int mh = p->FUN_000faeb0();
        if (mh == 0xce85a963)
            mode = 0;
        else if (mh == 0x320490b3)
            mode = 1;
        else if (mh == 0x5ebd3822)
            mode = 2;
        void *mem = FUN_0008d690(sizeof(FEDoPushDialog_eff20));
        FEDoPushDialog_eff20 *g = 0;
        if (mem != 0)
            g = ((FEDoPushDialog_eff20 *)mem)->FUN_000e1b90(a2, f.v1, (const char *)f.off, a1.s, v4, v5, mode);
        g->type = a4;
        cmd = g;
        break;
    }
    default:
        p->FUN_000fa0a0();
        break;
    }
    if (a4 == 4) {
        cmd->id1 = f.id1;
        cmd->id2 = f.id2;
    }
    if (cmd != 0) {
        cmd->v3();
        strncpy(cmd->name, f.name, 0x20);
        FEDoWait *w = f.objA;
        if (w != 0) {
            w->callback = (Callback_eff20 *)cmd;
            this->FUN_000e76a0(cmd);
            cmd = w;
        }
        this->FUN_000e76a0(cmd);
        a2->Add(cmd);
        if (a3 != 0)
            a3->FUN_000e2c60(cmd);
    }
}
} // namespace fn_000eff20


// 0x000f0590 FEThingsBase::vfunc_34 (533 B): equivalent/0x000f0590.cpp
// sym: ?vfunc_34@FEThingsBase@@UAE_NHHH@Z @f5d6312a0d17 @we81b5154d8f3
// STATUS: equivalent (tools/equiv.py level 3: 3014 inputs, branch coverage 22/22)
// FEThingsBase::vfunc_34 @ 0x000f0590
bool FEThingsBase::vfunc_34(hulk_intptr __p0, hulk_intptr __p1, int c) { Param_f0590 * p = (Param_f0590 *)__p0; Args_f0590 * a = (Args_f0590 *)__p1;

    switch (a->GetKey()) {
    case 0x9cf1366a: {
        float x = p->FUN_000fad30();
        float y = p->FUN_000fad30();
        float z = p->FUN_000fad30();
        ((FEThingsBase_nv_f0590*)this)->FUN_000e0360(x, y, z);
        return true;
    }
    case 0x81467d1e: {
        float f = p->FUN_000fad30();
        int ra = ((FEThingsBase_nv_f0590*)this)->FUN_000e7ec0(p->FUN_000faeb0(), p);
        int rb = 2;
        if (p->FUN_000f9e90())
            rb = ((FEThingsBase_nv_f0590*)this)->FUN_000e7f10(p->FUN_000faeb0(), p);
        ((FEThingsBase_nv_f0590*)this)->FUN_000e0300(f, ra, rb);
        return true;
    }
    case 0xdc18a191: {
        float x = p->FUN_000fad30();
        float y = p->FUN_000fad30();
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        ((FEThingsBase_nv_f0590*)this)->FUN_000e03c0(x, y, c1, c2, c3);
        return true;
    }
    case 0x0d2b530a: {
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        (*(unsigned int *)&this->f_1850) = (((0xffffff00u | c1) << 8 | c2) << 8) | c3;
        return true;
    }
    case 0x257960fb:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7d90(p, c);
        return true;
    case 0x3d3d4c3b:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7c30(p, c);
        return true;
    case 0x3e24edbf:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7cd0(p, c);
        return true;
    case 0x5772e4d0:
        ((FEThingsBase_nv_f0590*)this)->FUN_000e7b90(p, c);
        return true;
    }
    return false;
}


// 0x000f07b0 FEThingsBase::vfunc_36 (401 B): equivalent/0x000f07b0.cpp
// sym: ?vfunc_36@FEThingsBase@@UAE_NHHHH@Z @7e5aff9765d4 @we049a392a844
// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 31/32, incomplete)
// FEThingsBase::vfunc_36 @ 0x000f07b0
bool FEThingsBase::vfunc_36(hulk_intptr __p0, int b, hulk_intptr __p2, hulk_intptr __p3) { Param_f07b0 * p = (Param_f07b0 *)__p0; Target_f07b0 * t = (Target_f07b0 *)__p2; Args_f07b0 * a = (Args_f07b0 *)__p3;

    switch (a->GetKey()) {
    case 0x800e8237:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 0);
        return true;
    case 0x04605ef2:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 1);
        return true;
    case 0xfe1d4671:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 2);
        return true;
    case 0x67b8aefc:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 3);
        return true;
    case 0xeb227e7b:
        ((FEThingsBase_nv_f07b0*)this)->FUN_000eff20(p, b, t, 4);
        return true;
    case 0xfb26aca4:
        t->flag144 = p->FUN_000faeb0() != 0xa3c653f9;
        return true;
    case 0x700e422a:
        t->flag141 = p->FUN_000faeb0() != 0x457e63d9;
        return true;
    case 0x79bbec03:
        t->flag142 = p->FUN_000faeb0() != 0xa3c653f9;
        return true;
    case 0x5d7d2382: {
        int c1 = (int)p->FUN_000fad30();
        int c2 = (int)p->FUN_000fad30();
        int c3 = (int)p->FUN_000fad30();
        int alpha = 0xff;
        if (p->FUN_000f9e90())
            alpha = (int)p->FUN_000fad30();
        t->color = (((alpha << 8 | c1) << 8 | c2) << 8) | c3;
        return true;
    }
    }
    return false;
}


// 0x000f0950 FUN_000f0950 (479 B): equivalent/0x000f0950.cpp [wrapped: conflict: FEThingsBase]
// sym: ?FUN_000f0950@FEThingsBase@fn_000f0950@@QAEXPAVParam@2@HPAVEntity@2@PAVArgs@2@@Z @e7f3da04ae7a @w3b85e0da18f5
namespace fn_000f0950 {
// STATUS: equivalent (tools/equiv.py level 3: 20027 inputs, branch coverage 26/26)
// FUN_000f0950 @ 0x000f0950
// equiv-map: ?FUN_000f0950@FEThingsBase@@QAEXPAVParam@@HPAVEntity@@PAVArgs@@@Z = 0x000f0950
extern int __cdecl FUN_0034483c();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl memcmp(const void *a, const void *b, unsigned n);
#endif


class Args {
public:
    virtual void v0();
    virtual int GetType();
};

class Param {
public:
    float FUN_000fad30();
    char *FUN_000fad90();
    char FUN_000f9e90();
    char FUN_000f9ef0();
    void FUN_000f9f30();
    char FUN_000f9e50();
    void FUN_000f9fb0();
    void FUN_000fa0a0();
    int FUN_000fb110();
};

class Obj_f0950 {
public:
    char pad0[0xab8];
    char flag;
    void FUN_000e4610(char *s);
};

class FEThingsBase;

class Entity {
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
    virtual void v15();
    virtual void v16(char *s);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual int v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53(char *s);
    char pad4[0x854 - 4];
    int result;
    char pad858[0x9dc - 0x858];
    char field9dc[4];
    void FUN_000e55e0(Obj_f0950 *o);
};

class Dummy {};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, int, Entity *, Args *);
        hulk_intptr mC;
        Entity *mD;
    };

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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual char v34(Param *p, Args *a, ParseFunctor *f);
    virtual void v35();
    virtual void v36();
    virtual char v37(Param *p, Entity *d, Args *a);
    virtual void v38();
    virtual char v39(Param *p, char *q, Args *a);
    char pad[0x2105 - 4];
    char buf2105[1];

    Obj_f0950 *FUN_000efca0(char *s, int v);
    void FUN_000e8070(Param *p, int z, Obj_f0950 *o, int v);
    void FUN_000f0950(Param *param, int c, Entity *d, Args *args);
};

void FEThingsBase::FUN_000f0950(Param *param, int c, Entity *d, Args *args)
{
    int type = args->GetType();
    if (type == 0x16082730) {
        char *name = param->FUN_000fad90();
        Obj_f0950 *o = FUN_000efca0(name, d->v35());
        o->FUN_000e4610(buf2105);
        if (param->FUN_000f9e90()) {
            const char *hideText = param->FUN_000fad90();
            // the original compares inline (repe cmpsb), byte by byte
            int hideDiff = 0;
            for (int hk = 0; hk < 5 && hideDiff == 0; hk++)
                hideDiff = (int)(unsigned char)hideText[hk] - (int)(unsigned char)"hide"[hk];
            if (hideDiff == 0)
                o->flag = 0;
        }
        d->FUN_000e55e0(o);
        if (!param->FUN_000f9ef0())
            param->FUN_000fa0a0();
        param->FUN_000f9f30();
        while (param->FUN_000f9e50())
            FUN_000e8070(param, 0, o, param->FUN_000fb110());
        param->FUN_000f9fb0();
        return;
    }
    if (type == 0x887d4b38) {
        d->v16(param->FUN_000fad90());
        return;
    }
    if (type == 0x16b6f665) {
        d->v53(param->FUN_000fad90());
        return;
    }
    if (type == 0x3752e43c) {
        d->result = (int)(__int64)param->FUN_000fad30();
        return;
    }
    if (v39(param, d->field9dc, args))
        return;
    if (v37(param, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000f0950;
    f.mC = c;
    f.mD = d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
} // namespace fn_000f0950

namespace fn_f196c51b {

// 0x000f0b30 FUN_000f0b30 (93 B): equivalent/0x000f0b30.cpp
// sym: ?FUN_000f0b30@fn_f196c51b@@YGXH@Z @5477fa004833 @w826daa5c30cb
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000f0b30 @ 0x000f0b30
void __stdcall FUN_000f0b30(int value)
{
    Context context = {0};
    FUN_000fb1c0(value);
    context.FUN_000f9d20();
}


// 0x000f0b90 FUN_000f0b90 (714 B): equivalent/0x000f0b90.cpp
// sym: ?FUN_000f0b90@Mgr_f0b90@fn_f196c51b@@QAEXPBD@Z @a3d68c208720 @w8a1cbeb3c48a
// STATUS: equivalent (tools/equiv.py level 3: 98 inputs, branch coverage 84/92, incomplete)
// FUN_000f0b90 @ 0x000f0b90
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d330
void Mgr_f0b90::FUN_000f0b90(const char *name)
{
    if (name == 0)
        return;
    for (int i = 0; i < 0x40; i++) {
        Obj_f0b90 *o = objs[i];
        if (o != 0 && strcmp(o->name, name) == 0) {
            if (strcmp(o->v8(), curName) == 0)
                curName[0] = 0;
            if (cur == objs[i])
                cur = 0;
            if (objs[i] != 0) {
                delete objs[i];
                objs[i] = 0;
            }
        }
    }
    for (int i = 0; i < 0x100; i++) {
        Obj_f0b90 *o = objs2[i];
        if (o != 0 && strcmp(o->name, name) == 0) {
            delete o;
            objs2[i] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(nameA[i], name) == 0 && rA[i] != 0) {
            rA[i]->v1();
            rA[i] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(nameB[i], name) == 0 && rB[i] != 0) {
            rB[i]->v1();
            rB[i] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (strcmp(nameC[i], name) == 0 && rC[i] != 0) {
            rC[i]->v1();
            rC[i] = 0;
        }
    }
    for (int i = 0; i < 0x40; i++) {
        if (bufs[i] != 0) {
            thunk_FUN_00267090(bufs[i]);
            bufs[i] = 0;
        }
    }
}

} // namespace fn_f196c51b

// 0x000f0e60 FEThingsBase::vfunc_7 (255 B): equivalent/0x000f0e60.cpp [wrapped: conflict: DAT_004de94c; FEThingsBase]
// sym: ?vfunc_7@FEThingsBase@fn_000f0e60@@UAE_NXZ @459326f3dc21 @w68f11f6632d6
namespace fn_000f0e60 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 26/26)
// FEThingsBase::vfunc_7 @ 0x000f0e60
struct Timer { void FUN_000dff70(); };
struct Widget_f0e60 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3(); virtual void slot4(); virtual void slot5(); virtual void update(float, int);
 virtual void slot7(); virtual void slot8(); virtual void slot9(); virtual void tick();
 bool FUN_000ef610(); void FUN_000e5440(int);
};
extern float (__stdcall *DAT_004de948)();
extern unsigned DAT_004de94c;
struct FEThingsBase {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual bool vfunc_7();
 virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20();
 char pad0[0x175c-4]; Widget_f0e60* child; int blocked; int unused[2]; int state;
 char pad1[0x1818-0x1770]; Widget_f0e60* animation;
 char pad2[0x1a5c-0x181c]; Widget_f0e60* extras[2];
 char pad3[0x2074-0x1a64]; bool enabled; char pad4[3]; Timer timer;
 char pad5[0x2218-0x2079]; Widget_f0e60* other;
};
bool FEThingsBase::vfunc_7() {
 if(blocked) return false;
 timer.FUN_000dff70(); ++DAT_004de94c;
 if(animation) animation->update(DAT_004de948()*1000.0f, 0);
 if(enabled) for(int i=0;i<2;++i) if(extras[i]) extras[i]->update(DAT_004de948()*1000.0f, 0);
 if(other) other->tick();
 if(child) child->tick();
 if(state==2) { if(!child || !child->FUN_000ef610()) vfunc_20(); }
 else if(state==1 && child && !child->FUN_000ef610()) {state=0; child->FUN_000e5440(0);}
 return true;
}
} // namespace fn_000f0e60

