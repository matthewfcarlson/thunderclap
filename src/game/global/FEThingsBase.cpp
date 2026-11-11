// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e4330..0x000e8490 (kind game, layer game, confidence high), dominant class FEThingsBase
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f26f242d {
#define TREE_TU_END }
namespace fn_f26f242d {} using namespace fn_f26f242d;
#include "game/global.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f26f242d {
struct X_e45f0 {
    int pad;
    unsigned int value;
};
struct Obj_e46b0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(unsigned int, int);
};
struct Factory_e46b0 {
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
    virtual Obj_e46b0* make(const char*, int);
};
struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
    virtual void f9(int);
    virtual void f10(int);
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
};
class Child_e4d20 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
    virtual void f9();
    virtual void f10(int);
};
struct FEContainer_nv_e4d20 {
    void helper_000e4640();
};
class Child_e4d50 {
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
    virtual void f9(int);
    virtual void f10(int);
};
class Inner_e4da0 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual bool f6(int, int);
};
class Child_e4dd0 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual bool f7(int, int);
};
class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual char check(int, int, int, int);
};
struct Slot_e50d0 { char pad[0xab8]; char flag; };
struct Target_e50d0 {
    char pad0[0xabc];
    Slot_e50d0 *slots[(0xb3c - 0xabc) / 4];
    int count;
    void FUN_000e50d0(int idx, char val);
};
class Menu_e5170 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *GetName();
    char pad04[0xab8 - 4];
    char enabled;
    char padab9[3];
    Menu_e5170 *children[32];
    int childCount;
    void FUN_000e5170(const char *name, int value);
};
struct Item_e5330 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void update(); };
struct Link_e5330 { void FUN_000fb640(void*, void*, unsigned int); };
struct Entry_e5330 { char prefix[0xb0]; Link_e5330* links[12]; char data[4]; };
struct Owner_e5330 { char pad[0x17f8]; unsigned int index; };
struct Target_e5330 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void finishOne(); virtual void finishTwo();
 Owner_e5330* owner; char pad0[0x44]; Item_e5330* items[128]; char pad1[0x200]; Entry_e5330* entries[128]; char pad2[0x42c]; unsigned int mode;
 void run();
};
struct State_e54d0 {
    int value;
    void action_000fb420();
};
struct Obj_e54d0 {
    char pad[0xe0];
    State_e54d0 state;
};
struct Host_e54d0 {
    char pad[0x44c];
    Obj_e54d0* entries[0x80];
};
} // namespace fn_f26f242d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strncpy(char*, const char*, unsigned int);
#endif
namespace fn_f26f242d {
class Child_e5600 {
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
    virtual void f9(int);
    virtual void f10(int);
};
extern "C" int __cdecl FUN_000f6660(int value, int modulus);
class Element_e5c20 {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual char onKey(int key, int arg);
    virtual void e8();
    virtual void e9();
    virtual void onCancel(int flag);
    virtual void e11();
    virtual void e12();
    virtual void e13();
    virtual void e14();
    virtual void e15();
    virtual void e16();
    virtual void e17();
    virtual void e18();
    virtual char canFocus();
};
class Object_e5e30 {
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
    virtual int f35();
};
class FEContainer_e5e30 {
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
    virtual int a35();
};
struct Interface {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8(int);
    virtual void slot9();
    virtual void slot10(int);
};
struct Holder {
    char pad[0x14];
    Interface *object;
};
class Owner {
  public:
    char _m_pad_0[0x4];
    int v;
    char _m_pad_8[0x40];
    Interface *active;
    char _m_pad_4c[0x600];
    Item* items[128];
    char _m_pad_84c[0x14c];
    Holder *holders[3];
    void run(int x);
    void FUN_000e5f00(unsigned int index);
};
class Probe_e5f70 {
  public:
    short* Find_000f83f0(int, int);
};
class Item_e5f70 {
    char pad[0x14];

  public:
    int id;
    char pad2[0x5c];
    unsigned char f74;
    char pad3[0xcc];
    unsigned char f141;
};
class Manager_e5f70 {
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
    virtual int get();
};
class Owner_e5f70 {
    char pad[4];

  public:
    Manager_e5f70* mgr;
    char pad2[0x40];
    int selected;
    char pad3[0x94c];
    Item_e5f70* items[3];
    char pad4[4];
    unsigned char done;
    void Update();
};
class Child_e6280 {
  public:
    virtual int f0();
    virtual bool f1(int, int);
};
class Obj_e62e0 {
  public:
    virtual void f0();
    virtual bool f1(int, int);
    virtual bool f2(int, int);
};
class Other_e6340 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2x();
    virtual bool f3(int, int);
};
class Sub_e63a0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void a(int);
    virtual void v9();
    virtual void b(int);
};
class Mgr_e63a0 {
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
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void h0();
    virtual void h1();
    virtual void h2();
    virtual void h3();
    virtual void h4();
    virtual void h5();
    virtual void h6();
    virtual Sub_e63a0* get();
};
struct Inner_e63a0 {
    char p[0x175c];
    Mgr_e63a0* mgr;
};
struct Obj_e63a0 {
    char p[4];
    Inner_e63a0* in;
    char q[0x9a0];
    char flag;
    char r[3];
    int val;
};
class C_e63a0 {
  public:
    void Fn();
    char p[0x2218];
    Obj_e63a0* cur;
    int saved;
};
class Item_e6410 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual const char* GetName();
};
class Container_e6410 {
  public:
    char pad[0x20c];
    Item_e6410* mItems[256];
    Item_e6410* Find(const char* name);
};
class Obj_e6490 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char* Name();
};
class Table_e6490 {
  public:
    char pad[0xc];
    Obj_e6490* mItems[64];
    Obj_e6490* Find(const char* name);
};
struct Item_e6530 {
    char pad[0x18];
    char name[1];
};
struct FEThingsBase_e6530 {
    char pad[0x160c];
    Item_e6530* items[64];
    Item_e6530* Find(const char* s);
};
class X_e65b0 {
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
    virtual void call(int);
    char pad[0x1854 - 4];
    int vals[2];
    void clear();
};
typedef unsigned int u32_e65e0;
extern void* __cdecl allocThing_0008d690(u32_e65e0);
class Thing_e65e0 {
  public:
    u32_e65e0 initialize_000df690();
};
extern "C" int __cdecl FUN_0008d690(int);
class Helper_e6600 {
  public:
};
struct Entry_e6620 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual const char* name();
};
extern "C" void __cdecl FUN_000dfcc0(char*, int, const char*, ...);
struct Manager_e6620 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual Entry_e6620* create(Manager_e6620*, const char*);
 char pad[8]; Entry_e6620* entries[64]; char gap[0x170c-0x10c]; char label[40];
 Entry_e6620* FUN_000e6620(const char*);
};
struct Entry_e66f0 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual const char* name();
};
struct Manager_e66f0 {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
 virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
 virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
 virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
 virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
 virtual Entry_e66f0* create(Manager_e66f0*, const char*);
 char padding[0x108];
 Entry_e66f0* entries[64];
 Entry_e66f0* FUN_000e66f0(const char* key);
};
struct Entry_e67b0 {
 char padding[0x18];
 char name[0x20];
};
void* __cdecl FUN_0008d690(unsigned int size);
struct Registry_e67b0 {
 char padding[0x160c];
 Entry_e67b0* entries[64];
 Entry_e67b0* findOrCreate(const char* name);
};
class Item_e6930 {
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
    virtual void Activate();   // slot 14
    virtual void Deactivate(); // slot 15
};
class Source_e6930 {
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
    virtual int GetValue();    // slot 35
};
class Item_e6a00 {
  public:
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
};
class Sub_e6b30 {
  public:
    void run_000e5440(int);
};
class Obj_e6b80 {
  public:
    void Helper_000e5440(int);
};
class Obj_e6be0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char* Name();
};
class FEThingsBase_e6be0 {
  public:
    char pad[0xc];
    Obj_e6be0* mItems[64];
    Obj_e6be0* Find(const char* name);
};
class Sub_e6f60 {
  public:
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
};
class Obj_e6f60 {
  public:
    void run_000363d0();
};
struct Manager_e6f60 {
    char pad[0x20];
    void* obj;
};
extern Manager_e6f60* hulk_at_004dd700;
} // namespace fn_f26f242d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned int);
#endif
namespace fn_f26f242d {
struct TD {
    void* vf;
};
extern TD hulk_at_0049dba4, hulk_at_0049f4f0, hulk_at_0049f4d8;
extern "C" void* __cdecl FUN_00344e74(void*, int, TD*, TD*, int);
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int DAT_0049dba4, DAT_0049f4f0, DAT_004a1274;
class Named_e7620 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char* GetName();
};
class Registry_e7620 {
public:
    char pad0[0x10c];
    Named_e7620* entries[0x40];
    Named_e7620* FUN_000e7620(const char* name);
};
class Callback_e7b90 {
  public:
    virtual void Invoke(class Manager_e7b90* mgr, int result) = 0;
};
class Manager_e7b90 {
  public:
    bool IsActive_000f9e90();
    int GetValueBits_000faeb0();
    bool CheckFlag_000f9ef0();
    void Action1_000f9f30();
    int Action2();
    void Cleanup_000f9fb0();
    void AltCleanup_000fa0a0();
};
class Callback_e7c30 {
  public:
    virtual void Invoke(class Manager_e7c30* mgr, int result) = 0;
};
class Manager_e7c30 {
  public:
    bool IsActive_000f9e90();
    int GetValueBits_000faeb0();
    bool CheckFlag_000f9ef0();
    void Action1_000f9f30();
    int Action2();
    void Cleanup_000f9fb0();
    void AltCleanup_000fa0a0();
};
class Arg_e7cd0 {
  public:
    char F90_000f9e90();
    unsigned int FAB_000faeb0();
    char FEF_000f9ef0();
    void F30_000f9f30();
    char F50_000f9e50();
    unsigned int FB1();
    void FFB_000f9fb0();
    void FA0_000fa0a0();
};
class Out_e7cd0 {
  public:
    virtual void Fn(Arg_e7cd0*, unsigned int);
};
class FEThingsBase_e7cd0 {
  public:
    char pad[0x2220];
    char flag;
    void Target(Arg_e7cd0*, Out_e7cd0*);
};
struct LanguageInfo { char pad[0x10c]; unsigned language; };
struct Reader {
 bool FUN_000f9e90();
 const char* FUN_000fad90();
 bool FUN_000f9ef0();
 void FUN_000f9f30();
 int FUN_000fb110();
 void FUN_000fa0a0();
 void FUN_000f9fb0();
};
struct Handler_e7d90 { virtual void process(Reader*, int); };
} // namespace fn_f26f242d
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strncmp(const char*, const char*, unsigned);
#endif
namespace fn_f26f242d {
struct FEThingsBase_e7d90 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual LanguageInfo* info();
 void target(Reader* reader, Handler_e7d90* handler);
};
class Other {
  public:
    void FnF_000fa0a0();
};
class FEThingsBase_e7ec0 {
  public:
    int Lookup(int a, int b, Other* c);
};
class X_e7f10 {
  public:
    int fallback_000fa0a0();
};
class M_e8420 {
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
    virtual void start(int);
    virtual void end(int);
};
class Item_e8420 {
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
    virtual void run();
};
struct Holder_e8420 {
    M_e8420* m;
    void exec_00293da0(float, float, float);
};

} // namespace fn_f26f242d

// 0x000e4330 FEContainer::vfunc_47 (143 B): equivalent/0x000e4330.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_47@FEContainer@fn_000e4330@@QAEXPBDPAUFound_e4330@2@@Z @fefd5f586511 @w53f770dd66a3
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000e4330 {
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 7/9, incomplete)
// FEContainer::vfunc_47 @ 0x000e4330
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
extern "C" char *__cdecl strchr(const char *, int);
#endif


union Id64_e4330 {
    unsigned __int64 value;
    unsigned int word[2];
};

class Sub_e4330 {
public:
    unsigned int FUN_002843a0(unsigned int lo, unsigned int hi);
};

class Child_e4330 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Sub_e4330 *Resolve();      // slot 11
};

struct Found_e4330 {
    Sub_e4330 *sub;                // 0x00
    int pad04;
    unsigned int idLo;       // 0x08
    unsigned int idHi;       // 0x0c
};

extern "C" void __cdecl FUN_000f6cb0(const char *name, Found_e4330 *out);

class FEContainer {
public:
    virtual void v0();
    char pad04[0x24];
    Child_e4330 *children[8];      // 0x28
    void vfunc_47(const char *name, Found_e4330 *out);
};

void FEContainer::vfunc_47(const char *name, Found_e4330 *out) {
    if (strchr(name, '.') != 0) {
        FUN_000f6cb0(name, out);
        return;
    }
    Id64_e4330 id;
    id.value = FUN_0027b020(name);
    unsigned int index = 0;
    int i = 0;
    for (; i < 8; i++) {
        Child_e4330 *child = children[i];
        if (child == 0)
            return;
        index = child->Resolve()->FUN_002843a0(id.word[0], id.word[1]);
        if (index != 0xffff)
            break;
    }
    if (index == 0xffff)
        return;
    out->sub = children[i]->Resolve();
    out->idLo = id.word[0];
    out->idHi = id.word[1];
}
} // namespace fn_000e4330
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000e43c0 FEContainer::vfunc_48 (171 B): equivalent/0x000e43c0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_48@FEContainer@fn_000e43c0@@QAEXPBDPAUResult_e43c0@2@@Z @9493a40315f2 @wba070f37e5f1
namespace fn_000e43c0 {
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 7/9, incomplete)
// FEContainer::vfunc_48 @ 0x000e43c0
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

struct Result_e43c0 { unsigned a,b,c; };
extern "C" char* __cdecl _strchr(const char*,int);
extern "C" void __cdecl FUN_000f6d10(const char*,Result_e43c0*);
struct Dictionary { int FUN_0027b200(unsigned __int64); };
struct Data_e43c0 { char pad[8]; Dictionary* dictionary; void FUN_002848b0(int,int,Result_e43c0*); };
struct Child_e43c0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual Data_e43c0* v11();
};
struct FEContainer {
 virtual void vfunc_0();
 char pad[0x24]; Child_e43c0* children[8];
 void vfunc_48(const char*,Result_e43c0*);
};
void FEContainer::vfunc_48(const char* name,Result_e43c0* out) {
 if (_strchr(name,'.')) { FUN_000f6d10(name,out); return; }
 unsigned __int64 key=FUN_0027b020(name);
 for(int i=0;i<8;++i) {
  if(!children[i]) break;
  int index=children[i]->v11()->dictionary->FUN_0027b200(key);
  if(index!=0xffff) {
   children[i]->v11()->FUN_002848b0(index,0,out);
   return;
  }
 }
 out->a=0; out->b=0; out->c=0;
}
} // namespace fn_000e43c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000e4470 FEContainer::vfunc_49 (146 B): equivalent/0x000e4470.cpp [wrapped: conflict: FEContainer; FUN_0027b020]
// sym: ?vfunc_49@FEContainer@fn_000e4470@@UAEHPBDPAUArg_e4470@2@@Z @4096d104870d @wff94e100fe24
namespace fn_000e4470 {
// STATUS: equivalent (tools/equiv.py level 3: 3025 inputs, branch coverage 7/9, incomplete)
// FEContainer::vfunc_49 @ 0x000e4470

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *strchr(const char *s, int c);
#endif


struct Arg_e4470 {
    int FUN_0022b980();
};

struct Table_e4470 {
    int FUN_0027b200(unsigned int lo, unsigned int hi);
};

struct Thing_e4470 {
    char pad0[8];
    Table_e4470 *table;           // 0x8
    int FUN_00284860(int index, int zero, Arg_e4470 *arg);
};

class Child_e4470 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual Thing_e4470 *GetThing();      // slot 11
};

union Hash_e4470 {
    unsigned __int64 q;
    unsigned int w[2];
};
Hash_e4470 FUN_0027b020(const char *s);

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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual int vfunc_49(const char *name, Arg_e4470 *arg);

    char pad4[0x28 - 4];
    Child_e4470 *children[8];     // 0x28
};

int FEContainer::vfunc_49(const char *name, Arg_e4470 *arg)
{
    char *dot = strchr(name, '.');
    if (dot != 0)
        return (hulk_intptr)dot;

    Hash_e4470 id;
    id.q = FUN_0027b020(name).q;
    for (int i = 0; i < 8; i++) {
        if (children[i] == 0)
            break;
        int index = children[i]->GetThing()->table->FUN_0027b200(id.w[0], id.w[1]);
        if (index != 0xffff)
            return children[i]->GetThing()->FUN_00284860(index, 0, arg);
    }
    return arg->FUN_0022b980();
}
} // namespace fn_000e4470


// 0x000e4510 FUN_000e4510 (171 B): equivalent/0x000e4510.cpp [wrapped: conflict: FEContainer]
// sym: ??0FEContainer@fn_000e4510@@QAE@IPBD@Z @2ad7de3e9b31 @w2b57569433b6
namespace fn_000e4510 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000e4510 @ 0x000e4510

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif

struct CGlowDisplayEffect_e4510 { char data[28]; void FUN_000dee10(); };
struct CDropShadowDisplayEffect_e4510 { void FUN_000dee40(); };
struct FEContainer {
 virtual void slot0();
 unsigned int owner;
 char name[32];
 unsigned int values[8];
 unsigned int count;
 unsigned int first[128];
 char untouched[512];
 unsigned int second[128];
 unsigned int third[128];
 float scale;
 unsigned int state;
 int index;
 unsigned char flag;
 char padding[255];
 CGlowDisplayEffect_e4510 a;
 float factor;
 CDropShadowDisplayEffect_e4510 b;
 FEContainer(unsigned int, const char*);
};
FEContainer::FEContainer(unsigned int id, const char* text) {
 index = -1;
 a.FUN_000dee10();
 b.FUN_000dee40();
 owner = id;
 strncpy(name, text, 32);
 for (int i=0;i<8;++i) values[i]=0;
 for (int j=0;j<128;++j) first[j]=0;
 for (int k=0;k<128;++k) second[k]=0;
 for (int l=0;l<128;++l) third[l]=0;
 count=0;
 state=0;
 flag=0;
 scale=1.0f;
 factor=1.0f;
}
} // namespace fn_000e4510


// 0x000e45c0 FEContainer::vfunc_8 (4 B): matches/0x000e45c0.cpp
// sym: ?vfunc_8@FEContainer@@UAEPAXXZ
void* FEContainer::vfunc_8() {
    return (void*)((FEContainer*)((char*)this + 8));
}


// 0x000e45d0 FEContainer::vfunc_17 (7 B): matches/0x000e45d0.cpp
// sym: ?vfunc_17@FEContainer@@UAEIXZ
unsigned int FEContainer::vfunc_17() {
    return *(unsigned int*)((char*)this + 0x850);
}


// 0x000e45e0 FEContainer::vfunc_34 (4 B): matches/0x000e45e0.cpp
// sym: ?vfunc_34@FEContainer@@UAEHXZ
// Same code shape as 0x00086370 (propagated; names are from that function)
int FEContainer::vfunc_34() {
    return (*(int *)&this->f_48);
}

namespace fn_f26f242d {

// 0x000e45f0 FEContainer::vfunc_51 (4 B): matches/0x000e45f0.cpp
// sym: ?FUN_000e45f0@fn_f26f242d@@YIIPAUX_e45f0@1@@Z
// Same code shape as 0x00086270 (propagated; names are from that function)
unsigned int __fastcall FUN_000e45f0(X_e45f0* p) {
    return p->value;
}

} // namespace fn_f26f242d

// 0x000e4610 FUN_000e4610 (29 B): equivalent/0x000e4610.cpp
// sym: ?FUN_000e4610@Object_e4610@owners@@QAEXPBD@Z @80971cc66834 @w387c2cc84ebf
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 2/2)
// FUN_000e4610 @ 0x000e4610
void owners::Object_e4610::FUN_000e4610(const char *source) { char *destination = text; char c; do { c = *source++; *destination++ = c; } while (c != 0); }


// 0x000e4640 FUN_000e4640 (110 B): equivalent/0x000e4640.cpp [wrapped: conflict: FEContainer; FEObject]
// sym: ?FUN_000e4640@FEContainer@fn_000e4640@@QAEXXZ @4687ab4ec5c2 @wd20a1b76bef4
namespace fn_000e4640 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// FUN_000e4640 @ 0x000e4640
class FEObject {
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
    virtual char vfunc_19();
};

class FEContainer {
public:
    virtual void v0();
    char pad04[0x48 - 4];
    FEObject *focus;
    FEObject *items[128];
    void FUN_000e4640();
};

void FEContainer::FUN_000e4640()
{
    for (int i = 0; i < 128; i++) {
        FEObject *obj = items[i];
        if (obj != 0 && focus == obj && !obj->vfunc_19())
            focus = 0;
    }
    if (focus != 0)
        return;
    for (int i = 0; i < 128; i++) {
        if (items[i] != 0 && items[i]->vfunc_19()) {
            focus = items[i];
            return;
        }
    }
}
} // namespace fn_000e4640


// 0x000e46b0 FEThingsBase::vfunc_66 (63 B): matches/0x000e46b0.cpp
// sym: ?vfunc_66@FEThingsBase@@UAEXXZ
// data: glob_e46b0 = DAT_0052c2a0
void FEThingsBase::vfunc_66() {
    if (!(*(Obj_e46b0 * *)&this->f_17fc)) {
        (*(Obj_e46b0 * *)&this->f_17fc) = (*(Factory_e46b0**)&DAT_0052c2a0)->make("simple", 0);
        (*(Obj_e46b0 * *)&this->f_17fc)->a();
        (*(Obj_e46b0 * *)&this->f_17fc)->g(0x444d4c42, 1);
    }
}


// 0x000e46f0 FEContainer::vfunc_36 (83 B): matches/0x000e46f0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_36@FEContainer@fn_000e46f0@@UAEIH@Z
namespace fn_000e46f0 {
typedef unsigned int u32_e46f0;
typedef unsigned long long u64_e46f0;
extern u64_e46f0 GetKey_0027b020(int);
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
    virtual u32_e46f0 vfunc_36(int);
    char pad[0x48];
};
u32_e46f0 FEContainer::vfunc_36(int x) {
    FEContainer* self = this;
    int i = 0;
    u32_e46f0* p = (u32_e46f0*)((char*)this + 0x4c);
    while (i < 128) {
        hulk_uintptr v = *p;
        if (!v)
            return 0;
        u64_e46f0 k = GetKey_0027b020(x);
        if ((u32_e46f0)k == *(u32_e46f0*)(v + 0x10) && (u32_e46f0)(k >> 32) == *(u32_e46f0*)(v + 0x14))
            return *(u32_e46f0*)((char*)self + 0x4c + i * 4);
        ++i;
        ++p;
    }
    return 0;
}
} // namespace fn_000e46f0


// 0x000e4750 FEContainer::vfunc_37 (95 B): matches/0x000e4750.cpp [wrapped: conflict: FEContainer]
// sym: ?f37@FEContainer@fn_000e4750@@UAEPAXI@Z
namespace fn_000e4750 {
typedef unsigned int u32_e4750;
typedef unsigned long long u64_e4750;
u64_e4750 FUN_0027b020(u32_e4750);
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
    virtual void* f37(u32_e4750);
    char pad[0x44c - 4];
    void* items[128];
};
void* FEContainer::f37(u32_e4750 key) {
    for (int i = 0; i < 128; i++) {
        void* p = items[i];
        if (!p)
            return 0;
        u64_e4750 k = FUN_0027b020(key);
        if ((u32_e4750)k == *(u32_e4750*)((char*)p + 0x88) && (u32_e4750)(k >> 32) == *(u32_e4750*)((char*)p + 0x8c))
            return items[i];
    }
    return 0;
}
} // namespace fn_000e4750


// 0x000e47b0 FEContainer::vfunc_38 (39 B): matches/0x000e47b0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_38@FEContainer@fn_000e47b0@@UAEXH@Z
namespace fn_000e47b0 {
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
    virtual void* v37(int);
    virtual void vfunc_38(int);
};
extern int typeA, hulk_at_0049f48c;
void FEContainer::vfunc_38(int n) {
    __RTDynamicCast(v37(n), 0, &typeA, &hulk_at_0049f48c, 0);
}
} // namespace fn_000e47b0


// 0x000e47e0 FEContainer::vfunc_39 (39 B): matches/0x000e47e0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_39@FEContainer@fn_000e47e0@@UAEXH@Z
namespace fn_000e47e0 {
extern int a, b;
extern "C++" __declspec(nothrow) void __cdecl sink(int, int, int*, int*, int);
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
    virtual int f37(int);
    virtual void f38();
    virtual void vfunc_39(int);
};
void FEContainer::vfunc_39(int x) {
    sink(f37(x), 0, &a, &b, 0);
}
} // namespace fn_000e47e0


// 0x000e4810 FEContainer::vfunc_40 (39 B): matches/0x000e4810.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_40@FEContainer@fn_000e4810@@UAEXH@Z
namespace fn_000e4810 {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void* vfunc_39(int);
    virtual void vfunc_40(int);
};
extern int a, b;
extern "C++" __declspec(nothrow) void __cdecl fun(void*, int, const void*, const void*, int);
void FEContainer::vfunc_40(int x) {
    fun(vfunc_39(x), 0, &a, &b, 0);
}
} // namespace fn_000e4810


// 0x000e4840 FEContainer::vfunc_42 (39 B): matches/0x000e4840.cpp [wrapped: conflict: FEContainer]
// sym: ?f42@FEContainer@fn_000e4840@@UAEXH@Z
namespace fn_000e4840 {
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
    virtual void* f39(int);
    virtual void f40();
    virtual void f41();
    virtual void f42(int);
};
extern char DAT_0049f4a4[], DAT_0049f4f0[];
extern "C++" __declspec(nothrow) void FUN_00344e74(void*, int, char*, char*, int);
void FEContainer::f42(int x) {
    FUN_00344e74(f39(x), 0, DAT_0049f4f0, DAT_0049f4a4, 0);
}
} // namespace fn_000e4840


// 0x000e4870 FEContainer::vfunc_43 (39 B): matches/0x000e4870.cpp [wrapped: conflict: FEContainer; FUN_00344e74]
// sym: ?vfunc_43@FEContainer@fn_000e4870@@UAEXH@Z
namespace fn_000e4870 {
struct FEContainer {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual int vfunc_39(int);
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43(int);
};
extern int DAT_0049f4f0, DAT_0049f470;
extern "C++" __declspec(nothrow) void FUN_00344e74(hulk_intptr, int, int*, int*, int);
void FEContainer::vfunc_43(int x) {
    FUN_00344e74(vfunc_39(x), 0, &DAT_0049f4f0, &DAT_0049f470, 0);
}
} // namespace fn_000e4870


// 0x000e48a0 FEContainer::vfunc_44 (39 B): matches/0x000e48a0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_44@FEContainer@fn_000e48a0@@UAEXPAX@Z
namespace fn_000e48a0 {
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
    virtual int f39(void*);
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void vfunc_44(void*);
};
extern int a, hulk_at_004a1274;
void FEContainer::vfunc_44(void* x) {
    __RTDynamicCast((void*)(hulk_uintptr)(f39(x)), 0, (void*)(&a), (void*)(&hulk_at_004a1274), 0);
}
} // namespace fn_000e48a0


// 0x000e48d0 FEContainer::vfunc_45 (39 B): matches/0x000e48d0.cpp [wrapped: conflict: DAT_0049f4f0; FEContainer]
// sym: ?vfunc_45@FEContainer@fn_000e48d0@@UAEXPAX@Z
namespace fn_000e48d0 {
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
    virtual void* v39(void*);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void vfunc_45(void*);
};
extern int DAT_0049f454;
extern int DAT_0049f4f0;
extern "C++" __declspec(nothrow) void FUN_00344e74(void*, int, int*, int*, int);
void FEContainer::vfunc_45(void* p) {
    FUN_00344e74(v39(p), 0, &DAT_0049f4f0, &DAT_0049f454, 0);
}
} // namespace fn_000e48d0


// 0x000e4900 FEContainer::vfunc_41 (39 B): matches/0x000e4900.cpp [wrapped: macros]
// sym: ?vfunc_41@FEContainer@fn_000e4900@@UAEXPAX@Z
namespace fn_000e4900 {
extern int gOne, hulk_at_0049dbbc;
class FEContainer {
  public:
#define V(n) virtual void vfunc_##n();
    V(0)
    V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
        V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30) V(31) V(32) V(33) V(34) V(35) V(36)
            V(37) V(38) virtual int vfunc_39(void*);
    virtual void vfunc_40();
    virtual void vfunc_41(void*);
};
void FEContainer::vfunc_41(void* p) {
    __RTDynamicCast((void*)(hulk_uintptr)(vfunc_39(p)), 0, (void*)(&gOne), (void*)(&hulk_at_0049dbbc), 0);
}
} // namespace fn_000e4900
#undef V


// 0x000e4930 FEContainer::vfunc_46 (39 B): matches/0x000e4930.cpp [wrapped: conflict: FEContainer]
// sym: ?v46@FEContainer@fn_000e4930@@UAEXH@Z
namespace fn_000e4930 {
extern int hulk_at_0049f4c0, g2;
extern "C++" __declspec(nothrow) void f(int, int, int*, int*, int);
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
    virtual int v39(int);
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46(int);
};
void FEContainer::v46(int x) {
    f(v39(x), 0, &g2, &hulk_at_0049f4c0, 0);
}
} // namespace fn_000e4930


// 0x000e4960 FEContainer::vfunc_20 (92 B): matches/0x000e4960.cpp
// sym: ?vfunc_20@FEContainer@@UAEXH@Z
void FEContainer::vfunc_20(int value) {
    int i = 0;
    int* p = &(*(int (*)[128])&this->f_64c)[1];
    do {
        if (p[-1] == 0)
            break;
        if (p[0] == 0) {
            ++i;
            break;
        }
        if (p[1] == 0) {
            i += 2;
            break;
        }
        if (p[2] == 0) {
            i += 3;
            break;
        }
        i += 4;
        p += 4;
    } while (i < 0x80);
    if (i != 0x80)
        (*(int (*)[128])&this->f_64c)[i] = value;
}


// 0x000e49c0 FEContainer::vfunc_21 (34 B): matches/0x000e49c0.cpp
// sym: ?vfunc_21@FEContainer@@UAEXH@Z
void FEContainer::vfunc_21(int param) {
    if (param != 0 && this->f_850 < 0x80) {
        (*(int (*)[128])&this->f_4c)[this->f_850] = param;
        ++this->f_850;
    }
}


// 0x000e4a40 FEContainer::vfunc_23 (267 B): equivalent/0x000e4a40.cpp [wrapped: conflict: FEContainer; FELayout; FEObject; FUN_0027b020 (+1)]
// sym: ?vfunc_23@FEContainer@fn_000e4a40@@UAEPAVFEObject@2@PAV32@PBD@Z @421f6603cc88 @wbfb056619a8e
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_000e4a40 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 22/22)
// FEContainer::vfunc_23 @ 0x000e4a40
// equiv-map: ??0FELayout@@QAE@PAVFEContainer@@PBD@Z = 0x000e1f10
// FEContainer::vfunc_23 (0x000e4a40); identical code is FEScreenBase::vfunc_23 (0x000e4fc0).
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int size);


struct Key { unsigned int lo; unsigned int hi; };
extern "C" Key __cdecl FUN_0027b020(const char* s);

class FEContainer;
class FEObject;

struct Owner {
    char pad0[0x1800];
    int v1800;
    int v1804;
    int v1808;
};

class FELayout {
public:
    FELayout(FEContainer* parent, const char* name) throw();
    virtual void f0_000e1ff0();
    virtual void f1_000e2000();
    virtual void f2_000e2010();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11_000e21d0();
    virtual void f12_000e21c0();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void AttachObject_000e2130(FEObject* obj);
    virtual bool IsPrimary();
    virtual void f20_000e1fa0();
    char pad04[4];
    FEContainer* parent;
    char pad0c[4];
    unsigned int keyLo;
    unsigned int keyHi;
    char pad18[0x38 - 0x18];
    int sizeInfo;
    char pad3c[4];
};

class SingleLayout : public FELayout {
public:
    SingleLayout(FEContainer* p, const char* n) throw() : FELayout(p, n) { field44 = 0; mLayout = 0; }
    virtual void vfunc_0();
    virtual void vfunc_1_000e20b0();
    virtual void vfunc_2();
    FELayout* mLayout;
    int field44;
};

class FEObject {
public:
    char pad0[0x14];
    FELayout* layout;
    char pad18[0x6c - 0x18];
    int f6c;
    int f70;
    char pad74[0xa8 - 0x74];
    Owner* ownerRef;
};

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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void AddLayout(FELayout* layout);
    virtual void vfunc_22();
    virtual FEObject* vfunc_23(FEObject* obj, const char* name);

    Owner* owner;
    char pad08[0x48 - 0x08];
    FELayout* primary;
    FELayout* layouts[0x80];
    char pad24c[0x200];
    FEObject* children[0x80];
};

FEObject* FEContainer::vfunc_23(FEObject* obj, const char* name)
{
    if (obj == 0)
        return 0;

    FELayout* layout = 0;
    for (int i = 0; i < 0x80; i++) {
        FELayout* l = layouts[i];
        if (l == 0)
            break;
        Key key = FUN_0027b020(name);
        if (key.lo == l->keyLo && key.hi == l->keyHi) {
            layout = layouts[i];
            break;
        }
    }

    if (layout == 0) {
        void* mem = FUN_0008d690((int)sizeof(SingleLayout));
        if (mem)
            layout = new (mem) SingleLayout(this, name);
        AddLayout(layout);
    }

    layout->sizeInfo = owner->v1800;
    obj->layout = layout;
    obj->ownerRef = (Owner*)layout->parent->owner;

    for (int j = 0; j < 0x80; j++) {
        if (children[j] == 0) {
            children[j] = obj;
            break;
        }
    }

    obj->f6c = owner->v1804;
    obj->f70 = owner->v1808;
    layout->AttachObject_000e2130(obj);
    if (primary == 0 && layout->IsPrimary())
        primary = layout;
    return obj;
}
} // namespace fn_000e4a40


// 0x000e4b50 FEContainer::vfunc_24 (22 B): matches/0x000e4b50.cpp
// sym: ?vfunc_24@FEContainer@@UAEIII@Z
unsigned int FEContainer::vfunc_24(unsigned int a, unsigned int b) {
    vfunc_23(a, b);
    return a;
}


// 0x000e4b70 FEContainer::vfunc_12 (83 B): matches/0x000e4b70.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_12@FEContainer@fn_000e4b70@@UAEXH@Z
namespace fn_000e4b70 {
class FEChild {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void Notify(int arg);
};

class FEAnimChild {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void Notify(int arg);
};

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
    virtual void vfunc_11();
    virtual void vfunc_12(int arg);
    char pad4[0x4c - 4];
    FEChild* children[0x100];
    FEAnimChild* anims[0x80];
};

void FEContainer::vfunc_12(int arg)
{
    // both tables are packed: a null entry ends the list
    for (int i = 0; i < 0x80; i++) {
        if (!children[i])
            break;
        children[i]->Notify(arg);
    }
    for (int i = 0; i < 0x80; i++) {
        if (!anims[i])
            break;
        anims[i]->Notify(arg);
    }
}
} // namespace fn_000e4b70


// 0x000e4bd0 FEContainer::vfunc_13 (83 B): matches/0x000e4bd0.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_13@FEContainer@fn_000e4bd0@@UAEXH@Z
namespace fn_000e4bd0 {
class ChildA {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(int);
};
class ChildB {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7(int);
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
    virtual void vfunc_13(int);
    char pad[0x4c - 4];
    ChildA* a[0x80];
    char pad2[0x44c - 0x4c - 0x200];
    ChildB* b[0x80];
};
void FEContainer::vfunc_13(int x) {
    int i = 0;
    for (; i < 0x80; ++i) {
        if (!a[i])
            break;
        a[i]->f4(x);
    }
    i = 0;
    for (; i < 0x80; ++i) {
        if (!b[i])
            break;
        b[i]->f7(x);
    }
}
} // namespace fn_000e4bd0


// 0x000e4c30 FEContainer::vfunc_9 (81 B): matches/0x000e4c30.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_9@FEContainer@fn_000e4c30@@UAEXXZ
namespace fn_000e4c30 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __cdecl qsort(void*, unsigned int, unsigned int, int(__cdecl*)(const void*, const void*));
#endif

extern "C" int __cdecl FUN_000e1e90(const void*, const void*);
class Item {
  public:
    virtual void fn();
};
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
    char pad[0x4c - 4];
    Item* items[128];
    Item* sorted[128];
};
void FEContainer::vfunc_9() {
    int i = 0;
    do {
        if (!items[i])
            break;
        items[i]->fn();
        ++i;
    } while (i < 128);
    for (int j = 0; j < 128; ++j)
        sorted[j] = items[j];
    qsort(sorted, 128, 4, FUN_000e1e90);
}
} // namespace fn_000e4c30


// 0x000e4c90 FEContainer::vfunc_11 (44 B): matches/0x000e4c90.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_11@FEContainer@fn_000e4c90@@UAEXXZ
namespace fn_000e4c90 {
class Obj_e4c90 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
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
    virtual void vfunc_11();
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
    char pad[0x24c - sizeof(void*)];
    Obj_e4c90* items[0x80];
};
void FEContainer::vfunc_11() {
    for (int i = 0; i < 0x80; ++i) {
        if (!items[i])
            return;
        items[i]->f2();
    }
}
} // namespace fn_000e4c90


// 0x000e4cc0 FEContainer::vfunc_52 (94 B): matches/0x000e4cc0.cpp
// sym: ?vfunc_52@FEContainer@@UAEXPAXH@Z
// data: globalx = DAT_004de94c
void FEContainer::vfunc_52(void* __p0, int y) { void * x = (void *)__p0;

    if ((*(V * *)&this->f_48) != x) {
        if ((*(V * *)&this->f_48)) {
            (*(V * *)&this->f_48)->f10(3);
            (*(V * *)&this->f_48)->f9(y);
            (*(V * *)&this->f_04)->f48(2);
        }
        (*(V * *)&this->f_48) = (V*)x;
        if (x) {
            ((V*)x)->f8(y);
            (*(V * *)&this->f_48)->f10(2);
        }
        DAT_004de94c = 0;
    }
}


// 0x000e4d20 FEContainer::vfunc_14 (36 B): matches/0x000e4d20.cpp
// sym: ?vfunc_14@FEContainer@@UAEXXZ
void FEContainer::vfunc_14() {
    ((FEContainer_nv_e4d20*)this)->helper_000e4640();
    if ((*(Child_e4d20 * *)&this->f_48)) {
        (*(Child_e4d20 * *)&this->f_48)->f8(0);
        (*(Child_e4d20 * *)&this->f_48)->f10(2);
    }
}


// 0x000e4d50 FEContainer::vfunc_15 (31 B): matches/0x000e4d50.cpp
// sym: ?vfunc_15@FEContainer@@UAEXXZ
void FEContainer::vfunc_15() {
    if ((*(Child_e4d50 * *)&this->f_48)) {
        (*(Child_e4d50 * *)&this->f_48)->f10(3);
        (*(Child_e4d50 * *)&this->f_48)->f9(0);
    }
}


// 0x000e4d70 FEContainer::vfunc_1 (42 B): matches/0x000e4d70.cpp [wrapped: conflict: FEContainer]
// sym: ?vfunc_1@FEContainer@fn_000e4d70@@UAEDHH@Z
namespace fn_000e4d70 {
class Child {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual char f5(int, int);
};
class FEContainer {
  public:
    virtual void f0();
    virtual char vfunc_1(int a, int b);
    char pad[0x44];
    Child* child;
    char pad2[0x808];
    int id;
};
char FEContainer::vfunc_1(int a, int b) {
    if ((id == -1 || id == b) && child)
        return child->f5(a, b);
    return 0;
}
} // namespace fn_000e4d70


// 0x000e4da0 FEContainer::vfunc_2 (42 B): matches/0x000e4da0.cpp
// sym: ?vfunc_2@FEContainer@@UAE_NHH@Z
bool FEContainer::vfunc_2(int a, int b) {
    if ((this->f_854 == -1 || this->f_854 == b) && (*(Inner_e4da0 * *)&this->f_48) != 0)
        return (*(Inner_e4da0 * *)&this->f_48)->f6(a, b);
    return false;
}


// 0x000e4dd0 FEContainer::vfunc_3 (42 B): matches/0x000e4dd0.cpp
// sym: ?vfunc_3@FEContainer@@UAE_NHH@Z
bool FEContainer::vfunc_3(int a, int b) {
    if (this->f_854 == -1 || this->f_854 == b) {
        if ((*(Child_e4dd0 * *)&this->f_48) != 0)
            return (*(Child_e4dd0 * *)&this->f_48)->f7(a, b);
    }
    return false;
}


// 0x000e4e00 FEContainer::vfunc_18 (106 B): matches/0x000e4e00.cpp
// sym: ?vfunc_18@FEContainer@@UAEXHH@Z
void FEContainer::vfunc_18(int item, int index) {
    if (!item)
        return;
    if (index >= 128)
        return;
    int found = 0;
    int* p = (*(int (*)[128])&this->f_4c) + 1;
    while (found < 128) {
        if (p[-1] == item)
            break;
        if (p[0] == item) {
            ++found;
            break;
        }
        if (p[1] == item) {
            found += 2;
            break;
        }
        if (p[2] == item) {
            found += 3;
            break;
        }
        found += 4;
        p += 4;
    }
    if (found >= 128)
        return;
    int tmp = (*(int (*)[128])&this->f_4c)[index];
    (*(int (*)[128])&this->f_4c)[index] = item;
    (*(int (*)[128])&this->f_4c)[found] = tmp;
}


// 0x000e4e70 FEContainer::vfunc_19 (79 B): matches/0x000e4e70.cpp
// sym: ?vfunc_19@FEContainer@@UAEXH@Z
void FEContainer::vfunc_19(int p) {
    if (p) {
        int i = 0;
        int* q = (int*)((char*)this + 0x50);
        do {
            if (q[-1] == p)
                break;
            if (q[0] == p) {
                i += 1;
                break;
            }
            if (q[1] == p) {
                i += 2;
                break;
            }
            if (q[2] == p) {
                i += 3;
                break;
            }
            i += 4;
            q += 4;
        } while (i < 0x80);
        if (i < 0x80)
            *(int*)((char*)this + 0x48) = p;
    }
}

namespace fn_f26f242d {

// 0x000e4ec0 FUN_000e4ec0 (70 B): matches/0x000e4ec0.cpp
// sym: ?run@Owner@fn_f26f242d@@QAEXH@Z
void Owner::run(int x) {
    for (int i = 0; i < 128; ++i) {
        if (!items[i])
            return;
        if (items[i]->check(x, v, -1, -1))
            items[i]->f1();
    }
}

} // namespace fn_f26f242d

// 0x000e4f40 FEScreenBase::vfunc_21 (34 B): matches/0x000e4f40.cpp
// sym: ?vfunc_21@FEScreenBase@@UAEXH@Z
// Same code shape as 0x000e49c0 (propagated; names are from that function)
void FEScreenBase::vfunc_21(int param) {
    if (param != 0 && this->f_850 < 0x80) {
        (*(int (*)[128])&this->f_4c)[this->f_850] = param;
        ++this->f_850;
    }
}


// 0x000e4fc0 FEScreenBase::vfunc_23 (267 B): equivalent/0x000e4fc0.cpp [wrapped: conflict: FELayout; FEObject; FUN_0027b020; SingleLayout]
// sym: ?vfunc_23@FEScreenBase_e4fc0@fn_000e4fc0@@UAEPAVFEObject@2@PAV32@PBD@Z @eed950ed4b9b @w55c305797278
namespace fn_000e4fc0 {
// STATUS: equivalent (tools/equiv.py level 3: 19965 inputs, branch coverage 22/22)
// FEScreenBase::vfunc_23 @ 0x000e4fc0
// equiv-map: ??0FELayout@@QAE@PAVFEContainer@@PBD@Z = 0x000e1f10
// FEContainer::vfunc_23 (0x000e4a40); identical code is FEScreenBase::vfunc_23 (0x000e4fc0).
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int size);


struct Key { unsigned int lo; unsigned int hi; };
extern "C++" __declspec(nothrow) Key __cdecl FUN_0027b020(const char* s);

class FEScreenBase_e4fc0;
class FEObject;

struct Owner {
    char pad0[0x1800];
    int v1800;
    int v1804;
    int v1808;
};

class FELayout {
public:
    FELayout(FEScreenBase_e4fc0* parent, const char* name) throw();
    virtual void f0_000e1ff0();
    virtual void f1_000e2000();
    virtual void f2_000e2010();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11_000e21d0();
    virtual void f12_000e21c0();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void AttachObject_000e2130(FEObject* obj);
    virtual bool IsPrimary();
    virtual void f20_000e1fa0();
    char pad04[4];
    FEScreenBase_e4fc0* parent;
    char pad0c[4];
    unsigned int keyLo;
    unsigned int keyHi;
    char pad18[0x38 - 0x18];
    int sizeInfo;
    char pad3c[4];
};

class SingleLayout : public FELayout {
public:
    SingleLayout(FEScreenBase_e4fc0* p, const char* n) throw() : FELayout(p, n) { field44 = 0; mLayout = 0; }
    virtual void vfunc_0();
    virtual void vfunc_1_000e20b0();
    virtual void vfunc_2();
    FELayout* mLayout;
    int field44;
};

class FEObject {
public:
    char pad0[0x14];
    FELayout* layout;
    char pad18[0x6c - 0x18];
    int f6c;
    int f70;
    char pad74[0xa8 - 0x74];
    Owner* ownerRef;
};

class FEScreenBase_e4fc0 {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void AddLayout(FELayout* layout);
    virtual void vfunc_22();
    virtual FEObject* vfunc_23(FEObject* obj, const char* name);

    Owner* owner;
    char pad08[0x48 - 0x08];
    FELayout* primary;
    FELayout* layouts[0x80];
    char pad24c[0x200];
    FEObject* children[0x80];
};

FEObject* FEScreenBase_e4fc0::vfunc_23(FEObject* obj, const char* name)
{
    if (obj == 0)
        return 0;

    FELayout* layout = 0;
    for (int i = 0; i < 0x80; i++) {
        FELayout* l = layouts[i];
        if (l == 0)
            break;
        Key key = FUN_0027b020(name);
        if (key.lo == l->keyLo && key.hi == l->keyHi) {
            layout = layouts[i];
            break;
        }
    }

    if (layout == 0) {
        void* mem = FUN_0008d690((int)sizeof(SingleLayout));
        if (mem)
            layout = new (mem) SingleLayout(this, name);
        AddLayout(layout);
    }

    layout->sizeInfo = owner->v1800;
    obj->layout = layout;
    obj->ownerRef = (Owner*)layout->parent->owner;

    for (int j = 0; j < 0x80; j++) {
        if (children[j] == 0) {
            children[j] = obj;
            break;
        }
    }

    obj->f6c = owner->v1804;
    obj->f70 = owner->v1808;
    layout->AttachObject_000e2130(obj);
    if (primary == 0 && layout->IsPrimary())
        primary = layout;
    return obj;
}
} // namespace fn_000e4fc0

namespace fn_f26f242d {

// 0x000e50d0 FUN_000e50d0 (107 B): matches/0x000e50d0.cpp
// sym: ?FUN_000e50d0@Target_e50d0@fn_f26f242d@@QAEXHD@Z
// FUN_000e50d0 @ 0x000e50d0
void Target_e50d0::FUN_000e50d0(int idx, char val)
{
    if (idx >= 0 && idx < count) {
        slots[idx]->flag = val;
        return;
    }
    if (idx == -1) {
        for (int i = 0; i < count; i++)
            slots[i]->flag = val;
    }
}


// 0x000e5170 FUN_000e5170 (161 B): matches/0x000e5170.cpp
// sym: ?FUN_000e5170@Menu_e5170@fn_f26f242d@@QAEXPBDH@Z
// FUN_000e5170 @ 0x000e5170
// FUN_000e5170 @ 0x000e5170: sets the enabled flag of the first menu entry with the given name, searching children recursively
void Menu_e5170::FUN_000e5170(const char *name, int value)
{
    for (int i = 0; i < childCount; i++) {
        if (strcmp(children[i]->GetName(), name) != 0) {
            children[i]->FUN_000e5170(name, value);
        } else {
            children[i]->enabled = (char)value;
            return;
        }
    }
}

} // namespace fn_f26f242d

// 0x000e5220 FEScreenBase::vfunc_11 (265 B): matches/0x000e5220.cpp [wrapped: conflict: FEScreenBase]
// sym: ?vfunc_11@FEScreenBase@fn_000e5220@@UAEXXZ
namespace fn_000e5220 {

struct Node {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int, int);
    virtual void v9();
    virtual void v10();
    virtual void v11();
};
struct Renderer_e5220 {
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
    virtual void v15(int);
    virtual void v16(int);
};
struct Context {
    Renderer_e5220* renderer;
    void FUN_00293d00(void*);
};
struct FEScreenBase {
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
    virtual void vfunc_11();
    char pad04[0x24c - 4];
    Node* items[128];
    char pad44c[0x9a4 - 0x44c];
    Node* groupA[4];
    char pad9b4[0x10];
    Node* groupB[6];
    char pad9dc[8];
    Node* groupC[32];
    char pada64[0x34];
    char state[0x20];
    unsigned char enabled;
    unsigned char visible;
    char padaba[2];
    Node* children[32];
    int childCount;
};
void FEScreenBase::vfunc_11() {
    if (!enabled || !visible)
        return;
    (*(Context**)&DAT_0052c2ac)->renderer->v15(0);
    (*(Context**)&DAT_0052c2ac)->FUN_00293d00(state);
    for (int i = 0; i < 4; ++i)
        if (groupA[i])
            groupA[i]->v8(0, 0);
    for (int j = 0; j < 6; ++j)
        if (groupB[j])
            groupB[j]->v8(0, 0);
    for (int k = 0; k < 32 && groupC[k]; ++k)
        groupC[k]->v3();
    for (int m = 0; m < 128 && items[m]; ++m)
        items[m]->v2();
    (*(Context**)&DAT_0052c2ac)->renderer->v16(0);
    for (int n = 0; n < childCount; ++n)
        children[n]->v11();
}
} // namespace fn_000e5220

namespace fn_f26f242d {

// 0x000e5330 FUN_000e5330 (171 B): equivalent/0x000e5330.cpp
// sym: ?run@Target_e5330@fn_f26f242d@@QAEXXZ @c5167e9cd3ed @w89a4f727823c
// STATUS: equivalent (tools/equiv.py level 3: 2998 inputs, branch coverage 22/22)
// FUN_000e5330 @ 0x000e5330
void Target_e5330::run() {
 for (int i=0;i<128;++i) { Item_e5330* p=items[i]; if(!p) break; p->update(); }
 if(mode==1 || mode==2) {
  for(int i=0;i<128;++i) {
   Entry_e5330* p=entries[i]; if(!p) break;
   unsigned int m=mode;
   if(m) { Link_e5330* link=p->links[owner->index+m*4]; if(link) link->FUN_000fb640(p->data,p,(m & 0xffffff00u) | (m==1 ? 1u:0u)); }
  }
 }
 if(mode==2) finishTwo();
 if(mode==1) finishOne();
}

} // namespace fn_f26f242d

// 0x000e53e0 FUN_000e53e0 (81 B): matches/0x000e53e0.cpp [wrapped: conflict: Owner]
// sym: ?Run@Owner@fn_000e53e0@@QAEXH@Z
namespace fn_000e53e0 {
class Item {
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
    virtual void Action();
};
class Owner {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void First();
    virtual void f5();
    virtual void f6();
    virtual void Second();
    char pad[0x48];
    Item* items[128];
    void Run(int mode);
};
void Owner::Run(int mode) {
    for (int i = 0; i < 128; ++i) {
        if (!items[i])
            break;
        items[i]->Action();
    }
    if (mode == 1) {
        First();
        return;
    }
    if (mode == 2)
        Second();
}
} // namespace fn_000e53e0


// 0x000e5440 FUN_000e5440 (144 B): matches/0x000e5440.cpp
// sym: ?FUN_000e5440@Fader_e5440@owners@@QAEXH@Z
// FUN_000e5440 @ 0x000e5440
void owners::Fader_e5440::FUN_000e5440(int newState) {
    int old = state;
    state = newState;
    switch (newState) {
    case 0:
        level = 0;
        output = base * 0.0f;
        if (old != 0)
            FUN_000e53e0(old);
        break;
    case 1:
        level = 1.0f;
        output = base;
        stateTime = 0;
        if (old != 1)
            FUN_000e5330();
        break;
    case 2:
        level = 0;
        stateTime = 0;
        output = base * 0.0f;
        if (old != 2)
            FUN_000e5330();
        break;
    }
}

namespace fn_f26f242d {

// 0x000e54d0 FUN_000e54d0 (53 B): matches/0x000e54d0.cpp
// sym: ?FUN_000e54d0@fn_f26f242d@@YIXPAUHost_e54d0@1@@Z
void __fastcall FUN_000e54d0(Host_e54d0* self) {
    int i = 0;
    Obj_e54d0** p = self->entries;
    do {
        Obj_e54d0* o = *p;
        if (!o)
            return;
        State_e54d0* s = &o->state;
        if (s->value == 3)
            s->action_000fb420();
        ++i;
        ++p;
    } while (i < 0x80);
}

} // namespace fn_f26f242d

// 0x000e5510 FUN_000e5510 (39 B): matches/0x000e5510.cpp
// sym: ?FUN_000e5510@C_e5510@owners@@QAEXPBD@Z
void owners::C_e5510::FUN_000e5510(const char* p) {
    if (p)
        strncpy((char*)this + 0xb40, p, 0x40);
    else
        *((char*)this + 0xb40) = 0;
}


// 0x000e5540 FUN_000e5540 (39 B): matches/0x000e5540.cpp
// sym: ?FUN_000e5540@C_e5540@owners@@QAEXPBD@Z
void owners::C_e5540::FUN_000e5540(const char* p) {
    if (p)
        strncpy((char*)this + 0xb80, p, 0x40);
    else
        *((char*)this + 0xb80) = 0;
}


// 0x000e5570 FUN_000e5570 (63 B): matches/0x000e5570.cpp
// sym: ?FUN_000e5570@C_e5570@owners@@QAEXIIIII@Z
void owners::C_e5570::FUN_000e5570(unsigned x, unsigned y, unsigned z, unsigned q, unsigned r) {
    a = x;
    b = y;
    flag = 1;
    c = ((z | 0xffffff00) << 8 | q) << 8 | r;
}


// 0x000e55b0 FUN_000e55b0 (36 B): matches/0x000e55b0.cpp
// sym: ?FUN_000e55b0@X_e55b0@owners@@QAEXIII@Z
void owners::X_e55b0::FUN_000e55b0(unsigned int a, unsigned int b, unsigned int c) {
    value = ((a | 0xffffff00) << 8 | b) << 8 | c;
}


// 0x000e55e0 FUN_000e55e0 (31 B): matches/0x000e55e0.cpp
// sym: ?FUN_000e55e0@C_e55e0@owners@@QAEXH@Z
void owners::C_e55e0::FUN_000e55e0(hulk_intptr value) {
    if (count < 0x20) {
        values[count] = ((int)value);
        ++count;
    }
}


// 0x000e5600 FEScreenBase::vfunc_15 (31 B): matches/0x000e5600.cpp
// sym: ?vfunc_15@FEScreenBase@@UAEXXZ
// Same code shape as 0x000e4d50 (propagated; names are from that function)
void FEScreenBase::vfunc_15() {
    if ((*(Child_e5600 * *)&this->f_48)) {
        (*(Child_e5600 * *)&this->f_48)->f10(3);
        (*(Child_e5600 * *)&this->f_48)->f9(0);
    }
}


// 0x000e5620 FEScreenBase::vfunc_1 (116 B): equivalent/0x000e5620.cpp [wrapped: conflict: FEScreenBase]
// sym: ?vfunc_1@FEScreenBase@fn_000e5620@@UAE_NHH@Z @194090829422 @wdda11d6ca4d1
namespace fn_000e5620 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 10/10)
// FEScreenBase::vfunc_1 @ 0x000e5620
class FEWidget_e5620 {
public:
    virtual void v0();
    virtual void Event(int a, int b);
};

class FEOverlay {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual bool Event(int a, int b);
};

class FEScreenBase {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int a, int b);
    char pad04[0x48 - 0x4];
    FEOverlay *overlay;
    char pad4c[0xa78 - 0x4c];
    void *blocker;
    char pad7c[0xab8 - 0xa7c];
    unsigned char active;
    char padb9[3];
    FEWidget_e5620 *kids[32];
    int kidCount;
};

bool FEScreenBase::vfunc_1(int a, int b)
{
    if (!active || blocker != 0)
        return false;
    for (int i = 0; i < kidCount; i++)
        kids[i]->Event(a, b);
    if (overlay == 0)
        return false;
    return overlay->Event(a, b);
}
} // namespace fn_000e5620


// 0x000e56a0 FEScreenBase::vfunc_2 (110 B): equivalent/0x000e56a0.cpp [wrapped: conflict: FEScreenBase]
// sym: ?vfunc_2@FEScreenBase@fn_000e56a0@@UAEDHH@Z @aade3906339e @w0f4cdf2b9dd9
namespace fn_000e56a0 {
// STATUS: equivalent (tools/equiv.py level 3: 655 inputs, branch coverage 8/8)
// FEScreenBase::vfunc_2 @ 0x000e56a0
class FEChild_e56a0 {
public:
    virtual void v0();
    virtual void v1();
    virtual char vfunc_2(int a, int b);
};

class FEFocus {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual char vfunc_6(int a, int b);
};

class FEScreenBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual char vfunc_2(int a, int b);
    char pad04[0x48 - 4];
    FEFocus *focus;
    char pad4c[0xab8 - 0x4c];
    char active;
    FEChild_e56a0 *children[32];
    int numChildren;
};

char FEScreenBase::vfunc_2(int a, int b)
{
    if (!active)
        return 0;
    for (int i = 0; i < numChildren; i++)
        children[i]->vfunc_2(a, b);
    if (focus == 0)
        return 0;
    return focus->vfunc_6(a, b);
}
} // namespace fn_000e56a0


// 0x000e5710 FEScreenBase::vfunc_3 (1097 B): equivalent/0x000e5710.cpp [wrapped: conflict: FELayout; FEScreenBase; SingleLayout]
// sym: ?vfunc_3@FEScreenBase@fn_000e5710@@UAEDHTArg2_e5710@2@@Z @e3481a02da1f @w6c27b4eb0090
namespace fn_000e5710 {
// STATUS: equivalent (tools/equiv.py level 3: 20177 inputs, branch coverage 125/133, incomplete)
// FEScreenBase::vfunc_3 @ 0x000e5710
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
extern "C" int memcmp(const void *, const void *, unsigned int);
#endif

// MSVC 7.1 expands memcmp against a string literal inline (repe cmpsb); so does this.
static inline int memcmp_lit(const char *a, const char *b, unsigned n)
{
    for (; n != 0; n--, a++, b++)
        if (*a != *b)
            return (unsigned char)*a - (unsigned char)*b;
    return 0;
}
extern "C" int __cdecl FUN_000f6660(int value, int modulus);

class FELayout {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(int key, int arg);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual char v7(int key, int arg);
    virtual void v8();
    virtual void v9();
    virtual void v10(int flag);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual char v19();
};
class SingleLayout : public FELayout {
  public:
    virtual void v20();
    virtual void v21();
    virtual char v22();
};

class Child_e5710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(int key, int arg);
};

class Names_e5710 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *v8();
};

class Parent_e5710 {
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
    virtual void v16(const char *s);
    virtual void v17();
    virtual void v18(const char *s);
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    char pad[0x175c - 4];
    Names_e5710 *names;
};

struct State_e5710 {
    char FUN_000b4f20();
    char FUN_000b8c90();
};
struct Sub_e5710 {
    State_e5710 *FUN_00086280();
    int *FUN_00086270();
};
struct World {
    char pad[0x54];
    Sub_e5710 *sub;
};

union Arg2_e5710 {
    int arg;
    char flag;
};

class FEScreenBase {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual char vfunc_3(int key, Arg2_e5710 a2);
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48();
    virtual void vfunc_49();
    virtual void vfunc_50();
    virtual void vfunc_51();
    virtual void setWidget(FELayout *w, int dir);
    Parent_e5710 *parent;
    char pad08[0x48 - 0x8];
    FELayout *focus;
    FELayout *widgets[0x80];
    char pad24c[0xa64 - 0x24c];
    char field_a64;
    char padA65[0xa78 - 0xa65];
    int field_a78;
    char padA7c[0xab8 - 0xa7c];
    char enabled;
    char padAB9[3];
    Child_e5710 *kids[0x20];
    int kidCount;
    char text_b40[0x40];
    char text_b80[0x40];
};

char FEScreenBase::vfunc_3(int key, Arg2_e5710 a2)
{
    if (!enabled)
        return 0;
    if (field_a78)
        return 0;
    for (int k = 0; k < kidCount; k++) {
        if (kids[k]->v3(key, a2.arg))
            break;
    }
    if (!field_a64) {
        if (key == 0xa) {
            if (focus)
                focus->v10(1);
            State_e5710 *s = DAT_004dd700->sub->FUN_00086280();
            if (!(s->FUN_000b4f20() && s->FUN_000b8c90()))
                parent->v21();
            return 1;
        }
        if (key == 0xb) {
            if (memcmp_lit(parent->names->v8(), "side_mission_fail", 0x12) != 0 &&
                memcmp_lit(parent->names->v8(), "story_mission_fail", 0x13) != 0 &&
                memcmp_lit(parent->names->v8(), "side_mission_success", 0x15) != 0 &&
                memcmp_lit(parent->names->v8(), "story_mission_success", 0x16) != 0 &&
                *DAT_004dd700->sub->FUN_00086270() == 6) {
                if (focus)
                    focus->v10(1);
                parent->v23();
                return 1;
            }
        }
    }
    if (focus) {
        if (focus->v7(key, a2.arg))
            return 1;
    }
    if (key == 0xa) {
        if (focus)
            focus->v10(1);
        parent->v21();
        return 1;
    }
    if (key == 0xc) {
        if (memcmp_lit(text_b40, "", 1) != 0) {
            parent->v16(text_b40);
            return 1;
        }
    } else if (key == 0xd) {
        if (memcmp_lit(text_b80, "", 1) != 0) {
            parent->v18(text_b80);
            return 1;
        }
    }
    if ((*(char*)&DAT_004de950)) {
        if (key == 8 && focus) {
            focus->v10(0);
            return 1;
        }
    } else if (key == 0xb || key == 8) {
        (*(char*)&DAT_004de950) = 1;
        if (focus) {
            focus->v10(0);
            return 1;
        }
    }

    int cur = 0;
    if (key == 0 || key == 4 || key == 2 || key == 6) {
        for (int i = 0; i < 0x80; i++) {
            FELayout *w = widgets[i];
            if (w && w->v19() && widgets[i] == focus) {
                cur = i;
                break;
            }
        }
    }

    switch (key) {
    case 0:
    case 6: {
        a2.flag = 0;
        if (widgets[cur]) {
            SingleLayout *sl = dynamic_cast<SingleLayout *>(widgets[cur]);
            if (sl)
                a2.flag = sl->v22();
        }
        if (key == 6) {
            if (!a2.flag)
                return 0;
        } else if (key == 0) {
            if (a2.flag)
                return 0;
        }
        int i = FUN_000f6660(cur - 1, 0x80);
        while (i != cur) {
            FELayout *w = widgets[i];
            if (w && w->v19()) {
                setWidget(widgets[i], 1);
                return 1;
            }
            i = FUN_000f6660(i - 1, 0x80);
        }
        setWidget(widgets[cur], 1);
        return 1;
    }
    case 2:
    case 4: {
        a2.flag = 0;
        if (widgets[cur]) {
            SingleLayout *sl = dynamic_cast<SingleLayout *>(widgets[cur]);
            if (sl)
                a2.flag = sl->v22();
        }
        if (key == 2) {
            if (!a2.flag)
                return 0;
        } else if (key == 4) {
            if (a2.flag)
                return 0;
        }
        int i = (cur + 1) % 0x80;
        while (i != cur) {
            FELayout *w = widgets[i];
            if (w && w->v19()) {
                setWidget(widgets[i], 2);
                return 1;
            }
            i = (i + 1) % 0x80;
        }
        setWidget(widgets[cur], 2);
        return 1;
    }
    default:
        return 0;
    }
}
} // namespace fn_000e5710
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000e5b70 FEDialog::vfunc_1 (131 B): equivalent/0x000e5b70.cpp [wrapped: conflict: FEDialog]
// sym: ?vfunc_1@FEDialog@fn_000e5b70@@UAE_NHH@Z @e5aa001cfd88 @w54ad9ffb2e62
namespace fn_000e5b70 {
// STATUS: equivalent (tools/equiv.py level 3: 3026 inputs, branch coverage 15/16, incomplete)
// FEDialog::vfunc_1 @ 0x000e5b70
class Widget_e5b70 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int msg, int arg);
};

struct Button_e5b70 {
    char pad00[0x14];
    Widget_e5b70 *widget;         // 0x14
};

class FEDialog {
public:
    virtual void vfunc_0();
    virtual bool vfunc_1(int msg, int arg);
    char pad04[0x44];
    Widget_e5b70 *focus;          // 0x48
    char pad4c[0x998 - 0x4c];
    Button_e5b70 *button0;        // 0x998
    Button_e5b70 *button1;        // 0x99c
    Button_e5b70 *button2;        // 0x9a0
    char pad9a4[4];
    char active;            // 0x9a8
    char pad9a9[3];
    int selected;           // 0x9ac
};

bool FEDialog::vfunc_1(int msg, int arg)
{
    if (!active)
        return false;

    Widget_e5b70 *w = focus;
    if (w == 0)
        return false;

    if (msg == 8 || msg == 0xb) {
        if (w == button0->widget)
            selected = 0;
        else if (w == button1->widget)
            selected = 1;
        else if (w == button2->widget)
            selected = 2;
    }
    return w->vfunc_5(msg, arg);
}
} // namespace fn_000e5b70


// 0x000e5c00 FEDialog::vfunc_2 (29 B): matches/0x000e5c00.cpp [wrapped: conflict: FEContainer; FEDialog]
// sym: ?vfunc_2@FEDialog@fn_000e5c00@@UAE_NHH@Z
namespace fn_000e5c00 {
class FEContainer {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual bool f6(int, int);
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
class FEDialog : public FEContainer {
  public:
    char pad[0x48 - sizeof(FEContainer)];
    void* obj;
    char pad2[0x9a8 - 0x4c];
    unsigned char flag;
    virtual void a();
    virtual void b();
    virtual bool vfunc_2(int, int);
};
bool FEDialog::vfunc_2(int x, int y) {
    if (flag && obj)
        return ((FEContainer*)obj)->f6(x, y);
    return false;
}
} // namespace fn_000e5c00


// 0x000e5c20 FEDialog::vfunc_3 (413 B): equivalent/0x000e5c20.cpp
// sym: ?vfunc_3@FEDialog@@UAE_NHH@Z @e85a0faf0886 @w38714f1609e1
// STATUS: equivalent (tools/equiv.py level 3: 128 inputs, branch coverage 52/57, incomplete)
// FEDialog::vfunc_3 @ 0x000e5c20
bool FEDialog::vfunc_3(int key, int arg) {
    if (!(*(char *)&this->f_9a8))
        return (bool)(0);
    if ((*(Element_e5c20 * *)&this->f_48)) {
        if ((*(Element_e5c20 * *)&this->f_48)->onKey(key, arg))
            return (bool)(1);
    }
    if (key == 8 || key == 0xb) {
        if ((*(Element_e5c20 * *)&this->f_48))
            (*(Element_e5c20 * *)&this->f_48)->onCancel(0);
    }

    int cur = 0;
    if (key == 0 || key == 4 || key == 2 || key == 6) {
        for (int i = 0; i < 0x80; i++) {
            Element_e5c20 *c = (*(Element_e5c20 * (*)[128])&this->f_4c)[i];
            if (c && c->canFocus() && (*(Element_e5c20 * (*)[128])&this->f_4c)[i] == (*(Element_e5c20 * *)&this->f_48)) {
                cur = i;
                break;
            }
        }
    }

    switch (key) {
    case 0:
    case 6: {
        int i = FUN_000f6660(cur - 1, 0x80);
        while (i != cur) {
            Element_e5c20 *c = (*(Element_e5c20 * (*)[128])&this->f_4c)[i];
            if (c && c->canFocus()) {
                vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[i], 1);
                return (bool)(1);
            }
            i = FUN_000f6660(i - 1, 0x80);
        }
        vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[cur], 1);
        return (bool)(1);
    }
    case 2:
    case 4: {
        int i = (cur + 1) % 0x80;
        while (i != cur) {
            Element_e5c20 *c = (*(Element_e5c20 * (*)[128])&this->f_4c)[i];
            if (c && c->canFocus()) {
                vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[i], 2);
                return (bool)(1);
            }
            i = (i + 1) % 0x80;
        }
        vfunc_52((*(Element_e5c20 * (*)[128])&this->f_4c)[cur], 2);
        return (bool)(1);
    }
    default:
        return (bool)(0);
    }
}


// 0x000e5e30 FEDialog::vfunc_35 (24 B): matches/0x000e5e30.cpp
// sym: ?vfunc_35@FEDialog@@UAEHXZ
int FEDialog::vfunc_35() {
    Object_e5e30* p = *(Object_e5e30**)((char*)(*(void * *)&this->f_04) + 0x175c);
    if (p)
        return p->f35();
    return 0;
}


// 0x000e5e50 FEDialog::vfunc_11 (76 B): matches/0x000e5e50.cpp [wrapped: conflict: FEDialog]
// sym: ?vfunc_11@FEDialog@fn_000e5e50@@UAEXXZ
namespace fn_000e5e50 {
class Item {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int, int);
};
class FEDialog {
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
    virtual void vfunc_11();
    char pad[0x24c - 4];
    Item* items[0x80];
    char pad2[0x9a4 - 0x24c - 0x200];
    Item* current;
    char active;
};
void FEDialog::vfunc_11() {
    if (active) {
        if (current)
            current->f8(0, 0);
        for (int i = 0; i < 0x80; ++i) {
            if (!items[i])
                return;
            items[i]->f2();
        }
    }
}
} // namespace fn_000e5e50

namespace fn_f26f242d {

// 0x000e5f00 FUN_000e5f00 (84 B): equivalent/0x000e5f00.cpp
// sym: ?FUN_000e5f00@Owner@fn_f26f242d@@QAEXI@Z @2494c56289b1 @wd4a40936f1e1
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_000e5f00 @ 0x000e5f00
void Owner::FUN_000e5f00(unsigned int index) {
    if (index == 3) {
        active = 0;
        return;
    }
    Holder *selected = index < 3 ? holders[index] : (Holder *)0;
    active = selected->object;
    active->slot8(0);
    active->slot10(2);
}


// 0x000e5f70 FUN_000e5f70 (151 B): matches/0x000e5f70.cpp
// sym: ?Update@Owner_e5f70@fn_f26f242d@@QAEXXZ
void Owner_e5f70::Update() {
    Item_e5f70* a[3];
    a[0] = items[0];
    a[1] = items[1];
    a[2] = items[2];
    int i = 0;
    do {
        Item_e5f70* p = a[i];
        if (p) {
            short* q = ((Probe_e5f70*)((char*)p + 0x18))->Find_000f83f0(mgr->get(), 0);
            if (q && *q) {
                p->f141 = 1;
                p->f74 = 1;
                if (!selected)
                    selected = p->id;
            } else {
                p->f141 = 0;
                p->f74 = 0;
                _ReadWriteBarrier();
                if (selected == p->id)
                    selected = 0;
            }
        }
        i++;
    } while (i < 3);
    done = 1;
}

} // namespace fn_f26f242d

// 0x000e6050 FEMenuBase::vfunc_3 (489 B): equivalent/0x000e6050.cpp [wrapped: conflict: FEMenuBase]
// sym: ?vfunc_3@FEMenuBase@fn_000e6050@@UAEDHH@Z @5f6c259457fd @wc7fa11d05ef2
namespace fn_000e6050 {
// STATUS: equivalent (tools/equiv.py level 3: 171 inputs, branch coverage 51/62, incomplete)
// FEMenuBase::vfunc_3 @ 0x000e6050
class Widget_e6050 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char v3(int a1, int a2);
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual char v7(int a1, int a2);
    virtual void v8();
    virtual void v9();
    virtual void v10(int x);
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual char v19();
};

class Ref_e6050 {
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
    virtual void v48(int x);
};

extern "C" int __cdecl FUN_000f6660(int a, int b);

class FEMenuBase {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual char vfunc_3(int a1, int a2);
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
    virtual void v52(Widget_e6050 *w, int mode);
    Ref_e6050 *ref;
    char pad8[0x40];
    Widget_e6050 *current;
    Widget_e6050 *items[0x80];
    char pad24c[0x854 - 0x24c];
    int owner;
    char pad858[0xab8 - 0x858];
    char active;
    char padab9[3];
    Widget_e6050 *children[0x20];
    int childCount;

    void FUN_000e4ec0(int x);
};

char FEMenuBase::vfunc_3(int a1, int a2)
{
    if (!active)
        return 0;
    if (owner != -1 && owner != a2)
        return 0;
    for (int i = 0; i < childCount; i++) {
        if (children[i]->v3(a1, a2))
            break;
    }
    if (a1 == 8) {
        if (!current)
            return 0;
        current->v10(0);
        ref->v48(0);
        return 1;
    }
    if (a1 == 0xb)
        FUN_000e4ec0(5);
    if (!current)
        return 0;
    if (current->v7(a1, a2))
        return 1;
    int sel = 0;
    if (a1 == 0 || a1 == 4) {
        for (int i = 0; i < 0x80; i++) {
            if (items[i] && items[i]->v19() && items[i] == current) {
                sel = i;
                break;
            }
        }
    }
    if (a1 == 0) {
        int i = FUN_000f6660(sel - 1, 0x80);
        while (i != sel) {
            if (items[i] && items[i]->v19()) {
                v52(items[i], 1);
                if (i != sel)
                    return 1;
                break;
            }
            i = FUN_000f6660(i - 1, 0x80);
        }
        v52(items[sel], 1);
        return 1;
    }
    if (a1 == 4) {
        int i = (sel + 1) % 0x80;
        if (i != sel) {
            while (i != sel) {
                if (items[i] && items[i]->v19()) {
                    v52(items[i], 2);
                    if (i != sel)
                        return 1;
                    break;
                }
                i = (i + 1) % 0x80;
            }
        }
        v52(items[sel], 2);
        return 1;
    }
    return 0;
}
} // namespace fn_000e6050


// 0x000e6240 FUN_000e6240 (30 B): matches/0x000e6240.cpp [wrapped: conflict: CAction; CCollisionAction]
// sym: ?vfunc_2@CCollisionAction@fn_000e6240@@UAEPAV12@E@Z
namespace fn_000e6240 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
struct ThisCall_000df700 {
    void FUN_000df700();
};
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    ((ThisCall_000df700*)(this))->FUN_000df700();
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000e6240


// 0x000e6260 FUN_000e6260 (30 B): matches/0x000e6260.cpp [wrapped: conflict: CAction; CCollisionAction]
// sym: ?vfunc_2@CCollisionAction@fn_000e6260@@UAEPAV12@E@Z
namespace fn_000e6260 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void __fastcall FUN_000f8bd0(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_000f8bd0((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000e6260


// 0x000e6280 FEThingsBase::vfunc_0 (88 B): matches/0x000e6280.cpp
// sym: ?vfunc_0@FEThingsBase@@UAE_NHH@Z
bool FEThingsBase::vfunc_0(int x, int index) {
    char* p = (char*)this;
    if (p[index + 0x2100])
        return true;
    if ((*(Child_e6280 * *)&this->f_2218))
        return (*(Child_e6280 * *)&this->f_2218)->f1(x, index);
    if ((*(Child_e6280 * *)&this->f_1760))
        return (*(Child_e6280 * *)&this->f_1760)->f1(x, index);
    if ((*(Child_e6280 * *)&this->f_175c))
        return (*(Child_e6280 * *)&this->f_175c)->f1(x, index);
    return false;
}


// 0x000e62e0 FEThingsBase::vfunc_1 (88 B): matches/0x000e62e0.cpp
// sym: ?vfunc_1@FEThingsBase@@UAE_NHH@Z
bool FEThingsBase::vfunc_1(int a, int index) {
    if (*((unsigned char*)this + index + 0x2100))
        return true;
    if ((*(Obj_e62e0 * *)&this->f_2218))
        return (*(Obj_e62e0 * *)&this->f_2218)->f2(a, index);
    if ((*(Obj_e62e0 * *)&this->f_1760))
        return (*(Obj_e62e0 * *)&this->f_1760)->f2(a, index);
    if ((*(Obj_e62e0 * *)&this->f_175c))
        return (*(Obj_e62e0 * *)&this->f_175c)->f2(a, index);
    return false;
}


// 0x000e6340 FEThingsBase::vfunc_2 (88 B): matches/0x000e6340.cpp
// sym: ?vfunc_2@FEThingsBase@@UAE_NHH@Z
bool FEThingsBase::vfunc_2(int x, int index) {
    if (*((char*)this + 0x2100 + index))
        return true;
    if ((*(Other_e6340 * *)&this->f_2218))
        return (*(Other_e6340 * *)&this->f_2218)->f3(x, index);
    if ((*(Other_e6340 * *)&this->f_1760))
        return (*(Other_e6340 * *)&this->f_1760)->f3(x, index);
    if ((*(Other_e6340 * *)&this->f_175c))
        return (*(Other_e6340 * *)&this->f_175c)->f3(x, index);
    return false;
}

namespace fn_f26f242d {

// 0x000e63a0 FUN_000e63a0 (97 B): matches/0x000e63a0.cpp
// sym: ?Fn@C_e63a0@fn_f26f242d@@QAEXXZ
void C_e63a0::Fn() {
    Obj_e63a0* o = cur;
    if (o) {
        o->flag = 0;
        Mgr_e63a0* m = o->in->mgr;
        if (m) {
            Sub_e63a0* s = m->get();
            if (s) {
                s->a(0);
                s->b(2);
            }
        }
        saved = cur->val;
        cur = 0;
    }
}


// 0x000e6410 FUN_000e6410 (124 B): matches/0x000e6410.cpp
// sym: ?Find@Container_e6410@fn_f26f242d@@QAEPAVItem_e6410@2@PBD@Z
Item_e6410* Container_e6410::Find(const char* name) {
    for (int i = 0; i < 256; i++) {
        if (mItems[i]) {
            if (strcmp(name, mItems[i]->GetName()) == 0)
                return mItems[i];
        }
    }
    return 0;
}


// 0x000e6490 FUN_000e6490 (115 B): matches/0x000e6490.cpp
// sym: ?Find@Table_e6490@fn_f26f242d@@QAEPAVObj_e6490@2@PBD@Z
Obj_e6490* Table_e6490::Find(const char* name) {
    for (int i = 0; i < 64; i++) {
        if (mItems[i] != 0 && strcmp(name, mItems[i]->Name()) == 0)
            return mItems[i];
    }
    return 0;
}


// 0x000e6530 FUN_000e6530 (116 B): matches/0x000e6530.cpp
// sym: ?Find@FEThingsBase_e6530@fn_f26f242d@@QAEPAUItem_e6530@2@PBD@Z
Item_e6530* FEThingsBase_e6530::Find(const char* s) {
    for (int i = 0; i < 64; i++) {
        if (items[i] && strcmp(items[i]->name, s) == 0)
            return items[i];
    }
    return 0;
}


// 0x000e65b0 FUN_000e65b0 (43 B): matches/0x000e65b0.cpp
// sym: ?clear@X_e65b0@fn_f26f242d@@QAEXXZ
void X_e65b0::clear() {
    int* p = vals;
    int n = 2;
    do {
        if (*p)
            call(*p);
        ++p;
        --n;
    } while (n);
}

} // namespace fn_f26f242d

// 0x000e65e0 FEThingsBase::vfunc_61 (32 B): matches/0x000e65e0.cpp
// sym: ?vfunc_61@FEThingsBase@@UAEHH@Z
int FEThingsBase::vfunc_61(int __p0) {
    Thing_e65e0* p = (Thing_e65e0*)allocThing_0008d690(0x800);
    if (p)
        return (int)(p->initialize_000df690());
    return (int)(0);
}


// 0x000e6600 FEThingsBase::vfunc_62 (29 B): matches/0x000e6600.cpp
// sym: ?vfunc_62@FEThingsBase@@UAEHH@Z
int FEThingsBase::vfunc_62(int a) {
    hulk_intptr x = FUN_0008d690(0x204);
    if (x)
        return ((int)(hulk_uintptr)((owners::Obj_f8bb0 *)(((Helper_e6600*)x)))->FUN_000f8bb0((hulk_intptr)a));
    return 0;
}

namespace fn_f26f242d {

// 0x000e6620 FUN_000e6620 (208 B): equivalent/0x000e6620.cpp
// sym: ?FUN_000e6620@Manager_e6620@fn_f26f242d@@QAEPAUEntry_e6620@2@PBD@Z @91f159098ea8 @wdcbd3fa947d5
// STATUS: equivalent (tools/equiv.py level 3: 2999 inputs, branch coverage 22/22)
// FUN_000e6620 @ 0x000e6620
Entry_e6620* Manager_e6620::FUN_000e6620(const char* text) {
 Entry_e6620* result = 0;
 for(int i=0;i<64;++i) {
  if(entries[i]) {
   const char* b=entries[i]->name();
   const char* a=text;
   while(*a == *b) { if(*a == 0) break; ++a; ++b; }
   if(*a == *b) { result=entries[i]; break; }
  }
 }
 if(result) return result;
 for(int j=0;j<64;++j) {
  if(!entries[j]) {
   result=create(this,text);
   entries[j]=result;
   if(!label[0]) FUN_000dfcc0(label,40,"%s",text);
   break;
  }
 }
 return result;
}


// 0x000e66f0 FUN_000e66f0 (182 B): equivalent/0x000e66f0.cpp
// sym: ?FUN_000e66f0@Manager_e66f0@fn_f26f242d@@QAEPAUEntry_e66f0@2@PBD@Z @a5227e208b83 @wc51f4a6bb166
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_000e66f0 @ 0x000e66f0
Entry_e66f0* Manager_e66f0::FUN_000e66f0(const char* key) {
 Entry_e66f0* result = 0;
 for (int i=0;i<64;++i) {
  if (entries[i]) {
   const char* b=entries[i]->name();
   const char* a=key;
   while (*a == *b && *a) { ++a; ++b; }
   if (*a == *b) {
    result=entries[i];
    break;
   }
  }
 }
 if (result) return result;
 for (int j=0;j<64;++j) {
  if (!entries[j]) {
   result=create(this,key);
   entries[j]=result;
   break;
  }
 }
 return result;
}


// 0x000e67b0 FUN_000e67b0 (194 B): equivalent/0x000e67b0.cpp
// sym: ?findOrCreate@Registry_e67b0@fn_f26f242d@@QAEPAUEntry_e67b0@2@PBD@Z @6eaf4dce4807 @we6387582266b
// STATUS: equivalent (tools/equiv.py level 3: 3022 inputs, branch coverage 21/22, incomplete)
// FUN_000e67b0 @ 0x000e67b0
Entry_e67b0* Registry_e67b0::findOrCreate(const char* name) {
 for (int i = 0; i < 64; ++i) {
  Entry_e67b0* entry = entries[i];
  if (entry) {
   const unsigned char* a = (const unsigned char*)name;
   const unsigned char* b = (const unsigned char*)entry->name;
   while (*a == *b && *a) { ++a; ++b; }
   if (*a == *b) return entries[i];
  }
 }
 for (int slot = 0; slot < 64; ++slot) {
  if (!entries[slot]) {
   Entry_e67b0* memory = (Entry_e67b0*)FUN_0008d690((int)sizeof(Entry_e67b0));
   Entry_e67b0* result = memory ? ((Entry_e67b0 *)((owners::Thing_fb470 *)memory)->FUN_000fb470(name)) : 0;
   entries[slot] = result;
   return result;
  }
 }
 return 0;
}

} // namespace fn_f26f242d

// 0x000e6880 FEThingsBase::vfunc_29 (161 B): matches/0x000e6880.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_29@FEThingsBase@fn_000e6880@@UAEXPBD@Z
namespace fn_000e6880 {
// FEThingsBase::vfunc_29 @ 0x000e6880
// FEThingsBase::vfunc_29 @ 0x000e6880: selects the thing whose name matches, then refreshes the screen

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl strcmp(const char *, const char *);
#endif


class Thing_e6880 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual const char *GetName();
};

class FEThingsBase {
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
    virtual void vfunc_29(const char *name);
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
    virtual void Refresh(int mode);
    char pad04[0x20c - 4];
    Thing_e6880 *things[256];
    char pad60c[0x1830 - 0x60c];
    int f1830;
    float f1834;
    int f1838;
    Thing_e6880 *selected;
};

void FEThingsBase::vfunc_29(const char *name)
{
    selected = 0;
    for (int i = 0; i < 256; i++) {
        if (things[i] == 0)
            continue;
        if (strcmp(name, things[i]->GetName()) == 0) {
            selected = things[i];
            break;
        }
    }
    Refresh(4);
    f1830 = 2;
    f1838 = 0;
    f1834 = 1.0f;
}
} // namespace fn_000e6880


// 0x000e6930 FEThingsBase::vfunc_30 (112 B): matches/0x000e6930.cpp
// sym: ?vfunc_30@FEThingsBase@@UAEXXZ
// FEThingsBase::vfunc_30 @ 0x000e6930
void FEThingsBase::vfunc_30() {
    if ((*(Item_e6930 * *)&this->f_1760) != 0)
        (*(Item_e6930 * *)&this->f_1760)->Deactivate();
    (*(Item_e6930 * *)&this->f_1760) = (*(Item_e6930 * *)&this->f_183c);
    (*(Item_e6930 * *)&this->f_183c) = 0;
    if ((*(Item_e6930 * *)&this->f_1760) != 0) {
        (*(Item_e6930 * *)&this->f_1760)->Activate();
    } else if ((*(Source_e6930 * *)&this->f_175c) != 0) {
        vfunc_40((*(Source_e6930 * *)&this->f_175c)->GetValue());
    }
    this->f_1838 = 0;
    this->f_1834 = 0;
    this->f_1830 = 1;
    DAT_004de94c = 0;
}


// 0x000e69a0 FEThingsBase::vfunc_31 (82 B): matches/0x000e69a0.cpp
// sym: ?vfunc_31@FEThingsBase@@UAEXXZ
void FEThingsBase::vfunc_31() {
    vfunc_48(1);
    --this->f_17f4;
    if (this->f_17f4 < 0)
        this->f_183c = 0;
    else
        this->f_183c = (*(int (*)[16])&this->f_17b4)[this->f_17f4];
    this->f_1830 = 2;
    this->f_1838 = 0;
    this->f_1834 = 0x3f800000;
}


// 0x000e6a00 FEThingsBase::vfunc_32 (89 B): matches/0x000e6a00.cpp
// sym: ?vfunc_32@FEThingsBase@@UAEXXZ
void FEThingsBase::vfunc_32() {
    while (this->f_17f4 > 1) {
        ((Item_e6a00*)(*(void * *)&this->f_1760))->p();
        vfunc_48(1);
        --this->f_17f4;
        (*(void * *)&this->f_1760) = (*(void * (*)[16])&this->f_17b4)[this->f_17f4];
        ((Item_e6a00*)(*(void * *)&this->f_1760))->o();
    }
    vfunc_31();
}


// 0x000e6ab0 FEThingsBase::vfunc_15 (124 B): matches/0x000e6ab0.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_15@FEThingsBase@fn_000e6ab0@@UAEXPAUThing_e6ab0@2@@Z
namespace fn_000e6ab0 {
// FEThingsBase::vfunc_15 @ 0x000e6ab0
struct Thing_e6ab0 {
    void FUN_000e5440(int mode);
};


class FEThingsBase {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15(Thing_e6ab0 *thing);
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25(Thing_e6ab0 *thing);
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void vfunc_40();
    virtual void vfunc_41();
    virtual void vfunc_42();
    virtual void vfunc_43();
    virtual void vfunc_44();
    virtual void vfunc_45();
    virtual void vfunc_46();
    virtual void vfunc_47();
    virtual void vfunc_48(int mode);

    char pad04[0x175c - 4];
    Thing_e6ab0 *current;        // +0x175c
    char pad1760[8];
    Thing_e6ab0 *pending;        // +0x1768
    int mode;              // +0x176c
    char pad1770[0x17b0 - 0x1770];
    int state;             // +0x17b0
    char pad17b4[0x17f8 - 0x17b4];
    int f17f8;
};

void FEThingsBase::vfunc_15(Thing_e6ab0 *thing) {
    if (thing == current) {
        return;
    }
    if (state == 0xf) {
        vfunc_48(7);
        return;
    }
    pending = thing;
    if (thing == 0) {
        return;
    }
    vfunc_25(thing);
    if (state > 0) {
        vfunc_48(4);
    }
    Thing_e6ab0 *old = current;
    f17f8 = 0;
    mode = 2;
    if (old != 0) {
        old->FUN_000e5440(2);
    }
}
} // namespace fn_000e6ab0


// 0x000e6b30 FEThingsBase::vfunc_17 (74 B): matches/0x000e6b30.cpp
// sym: ?vfunc_17@FEThingsBase@@UAEXH@Z
void FEThingsBase::vfunc_17(int p) {
    if (p != (*(int *)&this->f_175c)) {
        this->f_1768 = p;
        if (p) {
            vfunc_27(p);
            this->f_17f8 = 2;
            this->f_176c = 2;
            if ((*(int *)&this->f_175c))
                ((Sub_e6b30*)(*(hulk_intptr *)&this->f_175c))->run_000e5440(2);
        }
    }
}


// 0x000e6b80 FEThingsBase::vfunc_19 (81 B): matches/0x000e6b80.cpp
// sym: ?vfunc_19@FEThingsBase@@UAEXH@Z
void FEThingsBase::vfunc_19(hulk_intptr x) {
    if ((Obj_e6b80*)x != (*(Obj_e6b80 * *)&this->f_175c)) {
        this->f_1768 = x;
        if (x) {
            vfunc_27(x);
            this->f_17f8 = 3;
            this->f_176c = 2;
            if ((*(Obj_e6b80 * *)&this->f_175c))
                (*(Obj_e6b80 * *)&this->f_175c)->Helper_000e5440(2);
        }
    }
}

namespace fn_f26f242d {

// 0x000e6be0 FEThingsBase::vfunc_3 (115 B): matches/0x000e6be0.cpp
// sym: ?Find@FEThingsBase_e6be0@fn_f26f242d@@QAEPAVObj_e6be0@2@PBD@Z
Obj_e6be0* FEThingsBase_e6be0::Find(const char* name) {
    for (int i = 0; i < 64; i++) {
        if (mItems[i] != 0 && strcmp(name, mItems[i]->Name()) == 0)
            return mItems[i];
    }
    return 0;
}

} // namespace fn_f26f242d

// 0x000e6c60 FEThingsBase::vfunc_14 (31 B): matches/0x000e6c60.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_14@FEThingsBase@fn_000e6c60@@UAEXH@Z
namespace fn_000e6c60 {
class FEThingsBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(int);
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
    virtual void vfunc_14(int);
    virtual void vfunc_15(int);
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
};
void FEThingsBase::vfunc_14(int x) {
    int r = f3(x);
    if (r)
        vfunc_15(r);
}
} // namespace fn_000e6c60


// 0x000e6c80 FEThingsBase::vfunc_16 (31 B): matches/0x000e6c80.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_16@FEThingsBase@fn_000e6c80@@UAEXH@Z
namespace fn_000e6c80 {
class FEThingsBase {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int);
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
    virtual void vfunc_16(int);
    virtual void v17(int);
};
void FEThingsBase::vfunc_16(int x) {
    int r = v3(x);
    if (r)
        v17(r);
}
} // namespace fn_000e6c80


// 0x000e6ca0 FEThingsBase::vfunc_18 (31 B): matches/0x000e6ca0.cpp [wrapped: conflict: FEThingsBase]
// sym: ?f18@FEThingsBase@fn_000e6ca0@@UAEXH@Z
namespace fn_000e6ca0 {
class FEThingsBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(int);
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
    virtual void f18(int);
    virtual void f19(int);
};
void FEThingsBase::f18(int x) {
    int r = f3(x);
    if (r)
        f19(r);
}
} // namespace fn_000e6ca0


// 0x000e6cc0 FEThingsBase::vfunc_20 (218 B): equivalent/0x000e6cc0.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_20@FEThingsBase@fn_000e6cc0@@UAEXXZ @048429802a66 @wa7948c233598
namespace fn_000e6cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 10/10)
// FEThingsBase::vfunc_20 @ 0x000e6cc0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
#endif

struct Thing_e6cc0 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual const char* v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 char pad[0xa74-4]; int state; void* resource; char pad2[0xa90-0xa7c]; float value; char pad3[12]; float result;
 void FUN_000e53e0(void*); void FUN_000e5440(int);
};
struct FEThingsBase {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18(); virtual void vfunc_19(); virtual void vfunc_20(); virtual void vfunc_21(); virtual void vfunc_22(); virtual void vfunc_23(); virtual void vfunc_24(); virtual void vfunc_25(); virtual void vfunc_26(); virtual void vfunc_27(); virtual void vfunc_28(); virtual void vfunc_29(); virtual void vfunc_30(); virtual void vfunc_31(); virtual void vfunc_32(); virtual void vfunc_33(); virtual void vfunc_34(); virtual void vfunc_35(); virtual void vfunc_36(); virtual void vfunc_37(); virtual void vfunc_38(); virtual void vfunc_39(); virtual void slot40(); virtual void slot41(); virtual void slot42(); virtual void slot43(); virtual void slot44(); virtual void slot45(); virtual void slot46(); virtual void vfunc_47(); virtual void vfunc_48(int);
 char pad[0x1734-4]; char name[40]; Thing_e6cc0* current; char pad2[8]; Thing_e6cc0* pending; int active;
};
void FEThingsBase::vfunc_20() {
 if(current) {
 current->v15();
 Thing_e6cc0* t=current;
 void* r=t->resource;
 t->resource=0; t->state=0; t->result=t->value*0.0f;
 if(r) t->FUN_000e53e0(r);
 }
 if(!pending) { vfunc_48(1); vfunc_47(); }
 if(current) { const char* s=current->v8(); strncpy(name,s,40); } else name[0]=0;
 current=pending; pending=0;
 if(current) { current->v14(); active=1; current->FUN_000e5440(1); } else active=0;
 DAT_004de94c=0;
}
} // namespace fn_000e6cc0


// 0x000e6e90 FEThingsBase::vfunc_22 (207 B): matches/0x000e6e90.cpp [wrapped: conflict: FEThingsBase; World]
// sym: ?vfunc_22@FEThingsBase@fn_000e6e90@@UAEXXZ
namespace fn_000e6e90 {
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

struct Child_e6e90 {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    void FUN_000e5440(int);
};
struct Action {
    void FUN_000363d0();
};
struct Context {
    char pad[0x124];
    Action* action;
};
struct World {
    char pad[0x20];
    Context* context;
};
struct FEThingsBase {
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
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    virtual void vfunc_37();
    virtual void vfunc_38();
    virtual void vfunc_39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void vfunc_47();
    virtual void vfunc_48(int);
    char pad0[0x175c - 4];
    Child_e6e90* child;
    char pad1[8];
    int selected;
    int mode;
    int history[16];
    int index;
    char pad2[0x17f8 - 0x17b4];
    int active;
    char pad3[0x2104 - 0x17fc];
    unsigned char enabled;
};
void FEThingsBase::vfunc_22() {
    if (index < 0 || (!enabled && index == 0)) {
        vfunc_48(7);
        return;
    }
    vfunc_48(1);
    --index;
    selected = index >= 0 ? history[index] : 0;
    active = 1;
    mode = 2;
    if (child) {
        child->s15();
        child->FUN_000e5440(mode);
    }
    (*(unsigned char*)&DAT_004e222c) = 1;
    if (DAT_004dd700->context && DAT_004dd700->context->action && (*(unsigned char*)&DAT_004e2518)) {
        (*(unsigned char*)&DAT_004e2518) = 0;
        DAT_004dd700->context->action->FUN_000363d0();
    }
}
} // namespace fn_000e6e90
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000e6f60 FEThingsBase::vfunc_23 (180 B): matches/0x000e6f60.cpp
// sym: ?vfunc_23@FEThingsBase@@UAEXXZ
// data: gByte = DAT_004e222c, gFlag_e6f60 = DAT_004e2518
void FEThingsBase::vfunc_23() {
    if (this->f_17b0 < 0 || (this->f_2104 == 0 && this->f_17b0 == 0)) {
        vfunc_48(7);
        return;
    }
    *(int*)((char*)this + 0x1768) = 0;
    *(int*)((char*)this + 0x17f8) = 1;
    *(int*)((char*)this + 0x176c) = 2;
    if (*(Sub_e6f60**)((char*)this + 0x175c)) {
        (*(Sub_e6f60**)((char*)this + 0x175c))->p();
        ((owners::Fader_e5440 *)((*(Sub_e6f60**)((char*)this + 0x175c))))->FUN_000e5440(*(int*)((char*)this + 0x176c));
    }
    vfunc_24();
    Manager_e6f60* m = hulk_at_004dd700;
    DAT_004e222c = 1;
    if (m->obj && *(void**)((char*)m->obj + 0x124) && (*(char*)&DAT_004e2518)) {
        (*(char*)&DAT_004e2518) = 0;
        ((Obj_e6f60*)*(void**)((char*)m->obj + 0x124))->run_000363d0();
    }
}


// 0x000e7020 FEThingsBase::vfunc_24 (30 B): matches/0x000e7020.cpp
// sym: ?vfunc_24@FEThingsBase@@UAEXXZ
void FEThingsBase::vfunc_24() {
    memset((char*)this + 0x1770, 0, 0x40);
    *(unsigned int*)((char*)this + 0x17b0) = 0xffffffff;
}


// 0x000e7040 FEThingsBase::vfunc_26 (31 B): matches/0x000e7040.cpp [wrapped: conflict: FEThingsBase]
// sym: ?f26@FEThingsBase@fn_000e7040@@UAEXH@Z
namespace fn_000e7040 {
class FEThingsBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(int);
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
    virtual void f25(int);
    virtual void f26(int);
};
void FEThingsBase::f26(int x) {
    int r = f3(x);
    if (r)
        f25(r);
}
} // namespace fn_000e7040


// 0x000e7060 FEThingsBase::vfunc_25 (36 B): matches/0x000e7060.cpp
// sym: ?vfunc_25@FEThingsBase@@UAEXH@Z
void FEThingsBase::vfunc_25(int param) {
    if (param != 0 && this->f_17b0 < 15) {
        int i = ++this->f_17b0;
        (*(int (*)[16])&this->f_1770)[i] = param;
    }
}


// 0x000e7090 FEThingsBase::vfunc_28 (31 B): matches/0x000e7090.cpp [wrapped: conflict: FEThingsBase]
// sym: ?f28@FEThingsBase@fn_000e7090@@UAEXH@Z
namespace fn_000e7090 {
class FEThingsBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int f3(int);
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
    virtual void f27(int);
    virtual void f28(int);
};
void FEThingsBase::f28(int a) {
    int v = f3(a);
    if (v)
        f27(v);
}
} // namespace fn_000e7090


// 0x000e70b0 FEThingsBase::vfunc_27 (24 B): matches/0x000e70b0.cpp
// sym: ?vfunc_27@FEThingsBase@@UAEXH@Z
void FEThingsBase::vfunc_27(int param) {
    if (param)
        (*(int (*)[16])&this->f_1770)[this->f_17b0] = param;
}


// 0x000e7460 FUN_000e7460 (59 B): matches/0x000e7460.cpp
// sym: ?FUN_000e7460@ThisWrap_000e7460@owners@@QAEPAXPAX@Z
void* owners::ThisWrap_000e7460::FUN_000e7460(void* p) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(p), 0, &hulk_at_0049dba4, &hulk_at_0049f4f0, 0), 0, &hulk_at_0049f4f0,
                 &hulk_at_0049f4d8, 0);
}


// 0x000e7520 FUN_000e7520 (59 B): matches/0x000e7520.cpp
// sym: ?FUN_000e7520@ThisWrap_000e7520@owners@@QAEHH@Z
hulk_intptr owners::ThisWrap_000e7520::FUN_000e7520(int x) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(x), 0, (hulk_intptr)&DAT_0049dba4, (hulk_intptr)&DAT_0049f4f0, 0), 0, (hulk_intptr)&DAT_0049f4f0, (hulk_intptr)&DAT_004a1274, 0);
}

namespace fn_f26f242d {

// 0x000e7620 FUN_000e7620 (121 B): equivalent/0x000e7620.cpp
// sym: ?FUN_000e7620@Registry_e7620@fn_f26f242d@@QAEPAVNamed_e7620@2@PBD@Z @b3127a3b5bcb @w0d93eb660f80
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000e7620 @ 0x000e7620
Named_e7620* Registry_e7620::FUN_000e7620(const char* name) {
    for (int i = 0; i < 0x40; i++) {
        Named_e7620* e = entries[i];
        if (e && strcmp(name, e->GetName()) == 0)
            return entries[i];
    }
    return 0;
}

} // namespace fn_f26f242d

// 0x000e76a0 FUN_000e76a0 (92 B): matches/0x000e76a0.cpp
// sym: ?FUN_000e76a0@Obj_e76a0@owners@@QAEXH@Z
void owners::Obj_e76a0::FUN_000e76a0(hulk_intptr value) {
    int i = 0;
    do {
        if (entries[i - 1] == 0)
            break;
        if (entries[i] == 0) {
            i++;
            break;
        }
        if (entries[i + 1] == 0) {
            i += 2;
            break;
        }
        if (entries[i + 2] == 0) {
            i += 3;
            break;
        }
        i += 4;
    } while (i < 0x400);
    if (i != 0x400)
        entries[i - 1] = ((int)value);
}


// 0x000e7700 FEThingsBase::vfunc_33 (102 B): equivalent/0x000e7700.cpp [wrapped: conflict: FEThingsBase]
// sym: ?FUN_000e7700@FEThingsBase@fn_000e7700@@UAEDPAVSource_e7700@2@PAVOther_e7700@2@@Z @d2f20f013b31 @wb37646ab2375
namespace fn_000e7700 {
// STATUS: equivalent (tools/equiv.py level 3: 3011 inputs, branch coverage 4/4)
// FEThingsBase::vfunc_33 @ 0x000e7700
class Thing_e7700 {
  public:
    void* FUN_000f7240(unsigned __int64 id);
};
class Other_e7700 {
  public:
    void FUN_000f8500(void* a, Thing_e7700* b, int c);
    void FUN_000f7a10(void* a, int b);
};
class Source_e7700 {
  public:
    virtual void v0();
    virtual unsigned __int64 GetId();
    char pad04[0xc];
    void* child;
};
class FEThingsBase {
  public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32();
    virtual char FUN_000e7700(Source_e7700* s, Other_e7700* o);
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41();
    virtual void v42(); virtual void v43();
    virtual Thing_e7700* Lookup();
};
char FEThingsBase::FUN_000e7700(Source_e7700* s, Other_e7700* o) {
    if (s->GetId() == 2) {
        void* child = s->child;
        o->FUN_000f8500(child, Lookup(), 1);
        return 1;
    }
    unsigned __int64 id = s->GetId();
    o->FUN_000f7a10(Lookup()->FUN_000f7240(id), 0);
    return 1;
}
} // namespace fn_000e7700


// 0x000e7770 FUN_000e7770 (439 B): equivalent/0x000e7770.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?FUN_000e7770@FEThingsBase@fn_000e7770@@QAEXPAVParam@2@PAVSource_e7770@2@PAXPAVArgs_e7770@2@@Z @91c3f4af8efa @wecfe1eaa90c0
namespace fn_000e7770 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 14/14)
// FUN_000e7770 @ 0x000e7770
extern char DAT_0049f4f0[];
extern char DAT_0049f4a4[];
extern void* __cdecl FUN_00344e74(void* obj, int vfDelta, char* srcType, char* dstType, int isRef);

class Param {
public:
    float FUN_000fad30();
    hulk_intptr FUN_000fad90();
    int FUN_000faeb0();
    char FUN_000f9e90();
    void FUN_000fa0a0();
};

class Args_e7770 {
public:
    virtual void v0();
    virtual int GetType();
};

struct Vec3_e7770 {
    float x, y, z;
};

class Source_e7770 {
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
    virtual void GetVec3(int key, Vec3_e7770* out);
    virtual void v49();
    virtual void GetFloat(int key, float* out);
};


struct Sink_e7770 {
    char pad00[0x150];
    int color150;
    char pad154[4];
    int color158;
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase* mObj;
        void (FEThingsBase::*mFn)(Param* param, Source_e7770* c, void* d, Args_e7770* args);
        Source_e7770* mC;
        void* mD;
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
    virtual char v34(Param* p, Args_e7770* a, ParseFunctor* f);
    virtual char v35(Param* p, Source_e7770* c, void* d, Args_e7770* a);
    virtual char v36(Param* p, Source_e7770* c, void* d, Args_e7770* a);

    void FUN_000e7770(Param* param, Source_e7770* c, void* d, Args_e7770* args);
};

struct Frame_e7770 {
    FEThingsBase::ParseFunctor f;
};

static int ParseColor(Param *param)
{
    int r = (int)param->FUN_000fad30();
    int g = (int)param->FUN_000fad30();
    int b = (int)param->FUN_000fad30();
    int a = 0xff;
    if (param->FUN_000f9e90())
        a = (int)param->FUN_000fad30();
    return (((a << 8 | r) << 8 | g) << 8) | b;
}

void FEThingsBase::FUN_000e7770(Param* param, Source_e7770* c, void* d, Args_e7770* args)
{
    Frame_e7770 fr;
    Sink_e7770* sink = (Sink_e7770*)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_0049f4a4, 0);
    int type = args->GetType();
    if (type == 0x8ebfb676) {
        sink->color158 = ParseColor(param);
        return;
    }
    if (type == 0x1c69411d) {
        sink->color150 = ParseColor(param);
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    fr.f.mObj = this;
    fr.f.mFn = &FEThingsBase::FUN_000e7770;
    fr.f.mC = c;
    fr.f.mD = d;
    if (v34(param, args, &fr.f))
        return;
    param->FUN_000fa0a0();
}
} // namespace fn_000e7770


// 0x000e7930 FUN_000e7930 (404 B): equivalent/0x000e7930.cpp [wrapped: conflict: DAT_0049f4f0; FEThingsBase; FUN_00344e74]
// sym: ?Parse@FEThingsBase@fn_000e7930@@QAEXPAVParam@2@HPAXPAVArgs_e7930@2@@Z @dad722531ce1 @w981d24c74916
namespace fn_000e7930 {
// STATUS: equivalent (tools/equiv.py level 3: 119 inputs, branch coverage 24/24)
// FUN_000e7930 @ 0x000e7930
extern char DAT_0049f4f0[];
extern char DAT_004a128c[];
extern void *__cdecl FUN_00344e74(void *obj, int vfDelta, char *srcType, char *dstType, int isRef);

class Param {
public:
    char FUN_000f9e90();
    char *FUN_000fad90();
    int FUN_000faeb0();
    void FUN_000fa0a0();
};

class Args_e7930 {
public:
    virtual void v0();
    virtual int GetType();
};

class Sink_e7930 {
public:
    void FUN_000e2f80(char *s);
    char pad0[0x1d58];
    int count;
    char pad1[0x1da8 - 0x1d5c];
    char flag;
    char names[128][64];
};

class FEThingsBase {
public:
    class ParseFunctor {
    public:
        virtual void vfunc_0_000e02d0(int a, int b);
        FEThingsBase *mObj;
        void (FEThingsBase::*mFn)(Param *, int, void *, Args_e7930 *);
        hulk_intptr mC;
        hulk_intptr mD;
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
    virtual char v34(Param *p, Args_e7930 *a, ParseFunctor *f);
    virtual char v35(Param *p, int x, void *y, Args_e7930 *a);
    virtual char v36(Param *p, int x, void *y, Args_e7930 *a);

    void FUN_000e7930(Param *param, int c, void *d, Args_e7930 *args);
    void Parse(Param *param, int c, void *d, Args_e7930 *args);
};

void FEThingsBase::Parse(Param *param, int c, void *d, Args_e7930 *args)
{
    Sink_e7930 *sink = (Sink_e7930 *)FUN_00344e74(d, 0, DAT_0049f4f0, DAT_004a128c, 0);
    int type = args->GetType();
    if (type == 0xe10f2442) {
        sink->FUN_000e2f80(param->FUN_000fad90());
        return;
    }
    if (type == 0x1babae77) {
        int kind = param->FUN_000faeb0();
        if (kind == 0x2f97d561) {
            sink->flag = 0;
        } else if (kind == 0x612213a0) {
            sink->flag = 1;
        } else {
            param->FUN_000fa0a0();
        }
        return;
    }
    if (type == 0x76744a71) {
        while (param->FUN_000f9e90()) {
            const char *s = param->FUN_000fad90();
            if (sink->count < 0x80) {
                char *dst = sink->names[sink->count];
                char ch;
                do {
                    ch = *s++;
                    *dst++ = ch;
                } while (ch != 0);
                sink->count++;
            }
        }
        return;
    }
    if (v35(param, c, d, args))
        return;
    if (v36(param, c, d, args))
        return;
    ParseFunctor f;
    f.mObj = this;
    f.mFn = &FEThingsBase::FUN_000e7930;
    f.mC = c;
    f.mD = (hulk_intptr)d;
    if (v34(param, args, &f))
        return;
    param->FUN_000fa0a0();
}
} // namespace fn_000e7930


// 0x000e7ad0 FUN_000e7ad0 (181 B): equivalent/0x000e7ad0.cpp [wrapped: conflict: DAT_0049dba4; FEThingsBase]
// sym: ?FUN_000e7ad0@FEThingsBase@fn_000e7ad0@@QAEXPAUReader@2@PAX1PAUItem_e7ad0@2@@Z @f2e2e4275c2f @w1a8390f72496
namespace fn_000e7ad0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000e7ad0 @ 0x000e7ad0
extern int DAT_0049dba4;
extern int DAT_0049f4c0;
extern void* __cdecl FUN_00344e74(void*, int, void*, void*, int);
struct Reader { void FUN_000fa0a0(); bool FUN_000f9e90(); };
struct Item_e7ad0 { virtual void slot0(); virtual unsigned int type(); };
struct FEThingsBase {
 struct ParseFunctor {
  virtual void invoke();
  FEThingsBase* owner;
  void (FEThingsBase::*method)(Reader*,void*,void*,Item_e7ad0*);
  void* context;
  void* object;
 };
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
 virtual bool parse(Reader*,Item_e7ad0*,ParseFunctor*);
 virtual bool direct(Reader*,void*,void*,Item_e7ad0*);
 void FUN_000e7ad0(Reader*,void*,void*,Item_e7ad0*);
};
void FEThingsBase::FUN_000e7ad0(Reader* reader, void* context, void* object, Item_e7ad0* item) {
 FUN_00344e74(object,0,&DAT_0049dba4,&DAT_0049f4c0,0);
 if(item->type()==0x76744a71) { while(reader->FUN_000f9e90()) {} }
 else if(!direct(reader,context,object,item)) {
  ParseFunctor callback;
  callback.owner=this;
  callback.method=&FEThingsBase::FUN_000e7ad0;
  callback.context=context;
  callback.object=object;
  if(!parse(reader,item,&callback)) reader->FUN_000fa0a0();
 }
}
} // namespace fn_000e7ad0

namespace fn_f26f242d {

// 0x000e7b90 FUN_000e7b90 (148 B): matches/0x000e7b90.cpp
// sym: ?ProcessManager@fn_f26f242d@@YGXPAVManager_e7b90@1@PAVCallback_e7b90@1@@Z
// data: g_GlobalFloatBits_004a0fec = DAT_004a0fec
void __stdcall ProcessManager(Manager_e7b90* mgr, Callback_e7b90* cb) {
    bool flag = false;

    while (mgr->IsActive_000f9e90()) {
        int val = mgr->GetValueBits_000faeb0();
        if (val == DAT_004a0fec)
            flag = true;
    }

    if (!mgr->CheckFlag_000f9ef0())
        return;

    mgr->Action1_000f9f30();

    while (((owners::ThisWrap_000f9e50 *)mgr)->FUN_000f9e50()) {
        int result = mgr->Action2();
        if (flag) {
            if (cb) {
                cb->Invoke(mgr, result);
            } else {
                mgr->AltCleanup_000fa0a0();
                break;
            }
        }
    }
    mgr->Cleanup_000f9fb0();
}


// 0x000e7c30 FUN_000e7c30 (148 B): matches/0x000e7c30.cpp
// sym: ?ProcessManager@fn_f26f242d@@YGXPAVManager_e7c30@1@PAVCallback_e7c30@1@@Z
// data: g_GlobalFloatBits = DAT_004a0ff0
void __stdcall ProcessManager(Manager_e7c30* mgr, Callback_e7c30* cb) {
    bool flag = false;

    while (mgr->IsActive_000f9e90()) {
        int val = mgr->GetValueBits_000faeb0();
        if (val == (*(int*)&DAT_004a0ff0))
            flag = true;
    }

    if (!mgr->CheckFlag_000f9ef0())
        return;

    mgr->Action1_000f9f30();

    while (((owners::ThisWrap_000f9e50 *)mgr)->FUN_000f9e50()) {
        int result = mgr->Action2();
        if (flag) {
            if (cb) {
                cb->Invoke(mgr, result);
            } else {
                mgr->AltCleanup_000fa0a0();
                break;
            }
        }
    }
    mgr->Cleanup_000f9fb0();
}


// 0x000e7cd0 FUN_000e7cd0 (179 B): matches/0x000e7cd0.cpp
// sym: ?Target@FEThingsBase_e7cd0@fn_f26f242d@@QAEXPAVArg_e7cd0@2@PAVOut_e7cd0@2@@Z
void FEThingsBase_e7cd0::Target(Arg_e7cd0* arg, Out_e7cd0* out) {
    bool b = false;
    char c = arg->F90_000f9e90();
    while (c) {
        unsigned int x = arg->FAB_000faeb0();
        if (x == 0x27a5e803) {
            if (flag)
                b = true;
        } else if (x == 0x46ddcbb4 && !flag)
            b = true;
        c = arg->F90_000f9e90();
    }
    if (arg->FEF_000f9ef0()) {
        arg->F30_000f9f30();
        if (arg->F50_000f9e50()) {
            do {
                unsigned int v = arg->FB1();
                if (b) {
                    if (!out) {
                        arg->FA0_000fa0a0();
                        break;
                    }
                    out->Fn(arg, v);
                }
            } while (arg->F50_000f9e50());
        }
        arg->FFB_000f9fb0();
    }
}


// 0x000e7d90 FUN_000e7d90 (227 B): equivalent/0x000e7d90.cpp
// sym: ?target@FEThingsBase_e7d90@fn_f26f242d@@QAEXPAUReader@2@PAUHandler_e7d90@2@@Z @8c44a22ec0f1 @w392d9d4b4c5c
// STATUS: equivalent (tools/equiv.py level 3: 16742 inputs, branch coverage 24/24)
// FUN_000e7d90 @ 0x000e7d90
void FEThingsBase_e7d90::target(Reader* reader, Handler_e7d90* handler) {
 bool match=false;
 const char* language;
 switch(info()->language) {
 case 1: language="fr"; break;
 case 2: language="it"; break;
 case 3: language="jp"; break;
 case 4: language="es"; break;
 case 5: language="uk"; break;
 default: language="en"; break;
 }
 while(reader->FUN_000f9e90()) {
 if(strncmp(reader->FUN_000fad90(),language,2)==0) match=true;
 }
 if(reader->FUN_000f9ef0()) {
 reader->FUN_000f9f30();
 while(((owners::ThisWrap_000f9e50 *)reader)->FUN_000f9e50()) {
 int value=reader->FUN_000fb110();
 if(match) {
 if(!handler) { reader->FUN_000fa0a0(); break; }
 handler->process(reader,value);
 }
 }
 reader->FUN_000f9fb0();
 }
}

} // namespace fn_f26f242d

// 0x000e7e90 FEThingsBase::vfunc_38 (45 B): matches/0x000e7e90.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_38@FEThingsBase@fn_000e7e90@@UAEXPAV12@0@Z
namespace fn_000e7e90 {
class FEThingsBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(float);
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
    virtual void vfunc_38(FEThingsBase*, FEThingsBase*);
    bool test_000f9e90();
    float value_000fad30();
};
void FEThingsBase::vfunc_38(FEThingsBase* obj, FEThingsBase* p) {
    if (obj->test_000f9e90()) {
        float x = obj->value_000fad30();
        p->f4(x);
    }
}
} // namespace fn_000e7e90

namespace fn_f26f242d {

// 0x000e7ec0 FUN_000e7ec0 (67 B): matches/0x000e7ec0.cpp
// sym: ?Lookup@FEThingsBase_e7ec0@fn_f26f242d@@QAEHHHPAVOther@2@@Z
int FEThingsBase_e7ec0::Lookup(int a, int b, Other* c) {
    int result = 0;
    switch (a) {
    case 0xce85a963:
        result = 0;
        break;
    case 0x5ebd3822:
        result = 2;
        break;
    case 0x7e52767b:
        result = 1;
        break;
    default:
        c->FnF_000fa0a0();
        break;
    }
    return result;
}


// 0x000e7f10 FUN_000e7f10 (73 B): matches/0x000e7f10.cpp
// sym: ?target@fn_f26f242d@@YGHHHPAVX_e7f10@1@@Z
int __stdcall target(hulk_intptr a, hulk_intptr b, X_e7f10* c) {
    int r = 2;
    switch (a) {
    case 0x1517370d:
        r = 3;
        break;
    case 0x39761bad:
        r = 1;
        break;
    case 0x7e52767b:
        r = 2;
        break;
    default:
        c->fallback_000fa0a0();
        break;
    }
    return r;
}

} // namespace fn_f26f242d

// 0x000e7f60 FUN_000e7f60 (257 B): equivalent/0x000e7f60.cpp [wrapped: conflict: FEThingsBase]
// sym: ?FUN_000e7f60@FEThingsBase@fn_000e7f60@@QAEXPAUReader@2@PAXPAUValues_e7f60@2@PAUTag_e7f60@2@@Z @36e97fc12c7c @w077ea027ca44
namespace fn_000e7f60 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_000e7f60 @ 0x000e7f60
struct Reader { float FUN_000fad30(); void FUN_000fa0a0(); };
struct Tag_e7f60 { virtual void slot0(); virtual int type(); };
struct Values_e7f60 { float a,b,x,y,z,w; };
struct FEThingsBase {
 struct ParseFunctor;
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual bool parse(Reader*,Tag_e7f60*,ParseFunctor*);
 void FUN_000e7f60(Reader*,void*,Values_e7f60*,Tag_e7f60*);
 struct ParseFunctor {
 virtual void invoke();
 FEThingsBase* owner;
 void (FEThingsBase::*callback)(Reader*,void*,Values_e7f60*,Tag_e7f60*);
 int adjustment;
 Values_e7f60* output;
 };
};
void FEThingsBase::FUN_000e7f60(Reader* reader,void*,Values_e7f60* output,Tag_e7f60* tag) {
 int id=tag->type();
 if(id==(int)0xba2c5954) output->w=reader->FUN_000fad30();
 else if(id==(int)0x946d8562) { float x=reader->FUN_000fad30(); float y=reader->FUN_000fad30(); float z=reader->FUN_000fad30(); output->z=z; output->x=x; output->y=y; }
 else if(id==(int)0xca6fda24) output->b=reader->FUN_000fad30();
 else if(id==0x61e45775) output->a=reader->FUN_000fad30();
 else { ParseFunctor f; f.owner=this; f.callback=&FEThingsBase::FUN_000e7f60; f.adjustment=0; f.output=output; if(!parse(reader,tag,&f)) reader->FUN_000fa0a0(); }
}
} // namespace fn_000e7f60


// 0x000e8070 FUN_000e8070 (260 B): equivalent/0x000e8070.cpp [wrapped: conflict: FEThingsBase]
// sym: ?FUN_000e8070@FEThingsBase@fn_000e8070@@QAEXPAUInput_e8070@2@IPAUObject@2@PAUToken_e8070@2@@Z @f993420dff25 @w653d17ea6cc2
namespace fn_000e8070 {
// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 12/12)
// FUN_000e8070 @ 0x000e8070
// FUN_000e8070 @ 0x000e8070
struct Input_e8070 { void FUN_000fa0a0(); float FUN_000fad30(); unsigned int FUN_000fad90(); };
struct Token_e8070 { virtual void slot0(); virtual unsigned int slot1(); };
struct Object;
struct FEThingsBase {
 struct ParseFunctor {
  virtual void invoke();
  FEThingsBase* owner;
  void (FEThingsBase::*function)(Input_e8070*, unsigned int, Object*, Token_e8070*);
  unsigned int context;
  Object* object;
 };
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33();
 virtual bool s34(Input_e8070*,Token_e8070*,ParseFunctor*);
 virtual void s35(); virtual void s36();
 virtual bool s37(Input_e8070*,Object*,Token_e8070*);
 virtual void s38();
 virtual bool s39(Input_e8070*,void*,Token_e8070*);
 void FUN_000e8070(Input_e8070*,unsigned int,Object*,Token_e8070*);
};
struct Object {
 virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(unsigned int);
 virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(unsigned int);
 char pad[0x850]; unsigned int stamp; char pad2[0x184]; unsigned int sub;
};
void FEThingsBase::FUN_000e8070(Input_e8070* input,unsigned int context,Object* object,Token_e8070* token) {
 unsigned int kind=token->slot1();
 if(kind==0x887d4b38) { object->s16(input->FUN_000fad90()); }
 else if(kind==0x16b6f665) { object->s53(input->FUN_000fad90()); }
 else if(kind==0x3752e43c) { object->stamp=(int)input->FUN_000fad30(); }
 else if(!s39(input,&object->sub,token) && !s37(input,object,token)) {
 ParseFunctor functor; functor.owner=this; functor.function=&FEThingsBase::FUN_000e8070; functor.context=context; functor.object=object;
 if(!s34(input,token,&functor)) input->FUN_000fa0a0();
 }
}
} // namespace fn_000e8070


// 0x000e8180 FUN_000e8180 (194 B): equivalent/0x000e8180.cpp [wrapped: conflict: FEThingsBase]
// sym: ?FUN_000e8180@FEThingsBase@fn_000e8180@@QAEXPAUItem_e8180@2@IPAUNode@2@1@Z @7e39eb7c1257 @w92695e8c69f0
namespace fn_000e8180 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 8/8)
// FUN_000e8180 @ 0x000e8180
struct Item_e8180 { void FUN_000fa0a0(); unsigned int FUN_000fad90(); };
struct Node {
 virtual void v0(); virtual unsigned int v1();
 virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
 virtual void v16(unsigned int);
 virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39(); virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43(); virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47(); virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51(); virtual void v52(); virtual void v53(unsigned int);
};
struct FEThingsBase {
 struct ParseFunctor {
 virtual void invoke();
 FEThingsBase* owner;
 void (FEThingsBase::*callback)(Item_e8180*, unsigned int, Node*, Node*);
 unsigned int second;
 Node* third;
 };
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
 virtual bool v34(Item_e8180*,Node*,ParseFunctor*);
 virtual void v35(); virtual void v36();
 virtual bool v37(Item_e8180*,Node*,Node*);
 void FUN_000e8180(Item_e8180*,unsigned int,Node*,Node*);
};
void FEThingsBase::FUN_000e8180(Item_e8180* item,unsigned int second,Node* third,Node* fourth) {
 unsigned int kind=fourth->v1();
 if(kind==0x887d4b38) { third->v16(item->FUN_000fad90()); }
 else if(kind==0x16b6f665) { third->v53(item->FUN_000fad90()); }
 else if(!v37(item,third,fourth)) {
 ParseFunctor f;
 f.owner=this;
 f.callback=&FEThingsBase::FUN_000e8180;
 f.second=second;
 f.third=third;
 if(!v34(item,fourth,&f)) item->FUN_000fa0a0();
 }
}
} // namespace fn_000e8180


// 0x000e8250 FUN_000e8250 (30 B): matches/0x000e8250.cpp [wrapped: conflict: CAction; CCollisionAction]
// sym: ?vfunc_2@CCollisionAction@fn_000e8250@@UAEPAV12@E@Z
namespace fn_000e8250 {
// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class CCollisionAction : public CAction {
  public:
    CCollisionAction* vfunc_2(unsigned char);
};
extern void __fastcall FUN_000f9a80(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_000f9a80((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000e8250


// 0x000e8270 FEThingsBase::vfunc_11 (76 B): matches/0x000e8270.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_11@FEThingsBase@fn_000e8270@@UAEXPAX@Z
namespace fn_000e8270 {
class Inv_e8270 {
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
    virtual void call(void*);
};
class FEThingsBase {
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
    virtual void vfunc_11(void*);
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
    char pad0[8];
    Inv_e8270* b[0x40];
    char pad1[0x20c - 0x10c];
    Inv_e8270* a[0x100];
};
void FEThingsBase::vfunc_11(void* x) {
    for (int i = 0; i < 0x100; i++)
        if (a[i])
            a[i]->call(x);
    for (int j = 0; j < 0x40; j++)
        if (b[j])
            b[j]->call(x);
}
} // namespace fn_000e8270


// 0x000e82c0 FEThingsBase::vfunc_12 (76 B): matches/0x000e82c0.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_12@FEThingsBase@fn_000e82c0@@QAEXH@Z
namespace fn_000e82c0 {
class FEThingsBase {
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
    virtual void v13(int);
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
    char pad[8];
    void* b[0x40];
    char gap[0x100];
    void* a[0x100];
    void vfunc_12(int);
};
void FEThingsBase::vfunc_12(int x) {
    for (int i = 0; i < 0x100; ++i)
        if (a[i])
            ((FEThingsBase*)a[i])->v13(x);
    for (int j = 0; j < 0x40; ++j)
        if (b[j])
            ((FEThingsBase*)b[j])->v13(x);
}
} // namespace fn_000e82c0


// 0x000e8310 FEThingsBase::vfunc_6 (103 B): matches/0x000e8310.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_6@FEThingsBase@fn_000e8310@@UAEXXZ
namespace fn_000e8310 {
// FEThingsBase::vfunc_6 @ 0x000e8310
// Releases every object held in the three widget tables.
class FEWidget_e8310 {
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
    virtual void Release();
};

class FEThingsBase {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    char pad04[8];
    FEWidget_e8310 *first[0x40];
    FEWidget_e8310 *second[0x40];
    FEWidget_e8310 *big[0x100];
};

void FEThingsBase::vfunc_6()
{
    for (int i = 0; i < 0x100; i++) {
        if (big[i])
            big[i]->Release();
    }
    for (int i = 0; i < 0x40; i++) {
        if (first[i])
            first[i]->Release();
    }
    for (int i = 0; i < 0x40; i++) {
        if (second[i])
            second[i]->Release();
    }
}
} // namespace fn_000e8310


// 0x000e8380 FEThingsBase::vfunc_5 (23 B): matches/0x000e8380.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_5@FEThingsBase@fn_000e8380@@UAEXXZ
namespace fn_000e8380 {
class FEThingsBase {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void vfunc_5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14(void*);
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
    char pad[0x1708];
    unsigned char field;
};
void FEThingsBase::vfunc_5() {
    if (field)
        f14(&field);
}
} // namespace fn_000e8380


// 0x000e83a0 FEThingsBase::vfunc_8 (126 B): matches/0x000e83a0.cpp [wrapped: conflict: FEThingsBase]
// sym: ?vfunc_8@FEThingsBase@fn_000e83a0@@UAEXXZ
namespace fn_000e83a0 {
// FEThingsBase::vfunc_8 @ 0x000e83a0
class Widget_e83a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8(int a, int b);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
};

class FEThingsBase {
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
    char pad04[0x175c - 4];
    Widget_e83a0* header;         // 0x175c
    char pad1760[0x1a5c - 0x1760];
    Widget_e83a0* arrows[2];      // 0x1a5c
    char pad1a64[0x2074 - 0x1a64];
    char arrowsVisible;     // 0x2074
    char pad2075[0x2080 - 0x2075];
    Widget_e83a0* items[32];      // 0x2080
    char pad2100[0x2218 - 0x2100];
    Widget_e83a0* footer;         // 0x2218
};

void FEThingsBase::vfunc_8()
{
    // the item list is terminated by the first empty slot
    for (int i = 0; i < 32 && items[i]; i++)
        items[i]->vfunc_3();
    if (arrowsVisible) {
        for (int i = 0; i < 2; i++) {
            if (arrows[i])
                arrows[i]->vfunc_8(0, 0);
        }
    }
    if (header)
        header->vfunc_11();
    if (footer)
        footer->vfunc_11();
}
} // namespace fn_000e83a0


// 0x000e8420 FEThingsBase::vfunc_10 (99 B): matches/0x000e8420.cpp
// sym: ?vfunc_10@FEThingsBase@@UAEXXZ
// data: gHolder_e8420 = DAT_0052c2ac
void FEThingsBase::vfunc_10() {
    if ((*(Item_e8420 * *)&this->f_1760)) {
        if (this->f_1830) {
            (*(Holder_e8420**)&DAT_0052c2ac)->m->start(0);
            (*(Holder_e8420**)&DAT_0052c2ac)->exec_00293da0((*(float *)&this->f_1834), (*(float *)&this->f_1834), (*(float *)&this->f_1834));
        }
        (*(Item_e8420 * *)&this->f_1760)->run();
        if (this->f_1830)
            (*(Holder_e8420**)&DAT_0052c2ac)->m->end(0);
    }
}

