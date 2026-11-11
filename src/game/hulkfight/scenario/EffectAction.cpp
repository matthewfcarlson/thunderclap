// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1ed0..0x001aace0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::EffectAction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/unknown.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "decls/data/game/hulkfight/motion.h"
#include "decls/data/game/hulkfight/scenario.h"
#include "decls/data/game/unknown.h"
#include "gen/content.h"
#include "gen/fight.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc5dbd2a {
#define TREE_TU_END }
namespace fn_fc5dbd2a {} using namespace fn_fc5dbd2a;
#include "game/hulkfight/scenario.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_fc5dbd2a {
class Obj_1a1f00 {
  public:
    char pad[0xc];
    int mValue;
    char SetCompare_001a1f00(int x);
};
struct Obj_1a1f10 {
    char pad[0x10];
    int mValue;
    char SetOldState_001a1f10(int x);
};
class A_1a1f20 {
  public:
    char pad[0xc];
    int m;
    bool SetCompare_001a1f20(int v);
};
class X_1a1f30 {
  public:
    char m[0x10];
    int value;
    bool SetNewState_001a1f30(int x);
};
struct O_1a1f40 {
  public:
    int m0;
    int m4;
    int m8;
    int mC;
    char f(int x);
};
struct Obj_1a1f70 {
    char pad[16];
};
struct Vec3_1a2020 {
    int x, y, z;
};
class Obj_1a2020 {
  public:
    char pad[0x38];
    int v38, v3c, v40;
    bool Set(Vec3_1a2020* v);
};
struct Angles { float x,y,z; };
class Sub_1a20c0 {
  public:
    void* Get();
};
class Obj_1a20c0 {
  public:
    char pad[0x58];
    Sub_1a20c0 sub;
    void* Get();
};
class Obj_1a20f0 {
  public:
    char pad[12];
    int mField;
    bool Set(int v);
};
class Obj_1a2100 {
  public:
    char m[0x10];
    char Fn(int);
};
class Obj_1a2120 {
  public:
    char pad[0x14];
    int mField;
    bool Set(int x);
};
class Target_1a2140 {
  public:
    char pad[0x18];
    int mValue;
    bool Set(int v);
};
class Obj_1a2160 {
  public:
    char Set(int x);
    char mPad[0x1c];
};
class Base_1a2180 {
  public:
    Base_1a2180() {}
    virtual ~Base_1a2180() {}
};
class Obj_1a2180 {
  public:
    char pad[0x20];
    int mValue;
    bool Set(int v);
};
class Obj_1a21b0 {
  public:
    char pad[0x28];
    char m28;
    char Set(int v);
};
class C_1a2200 {
  public:
    char Set(char);
    char pad[0x30];
    char m30;
};
class O_1a2220 {
  public:
    char Fn(int a);

  private:
    char pad[0x34];
    int m34;
};
class Obj_1a2240 {
  public:
    char pad[0x38];
    int m38;
    bool Set(int value);
};
class Obj_1a2260 {
  public:
    char pad[0x3c];
    int m3c;
    bool Set(int x);
};
class C_1a2280 {
  public:
    char pad[0x40];
    int value;
    unsigned char Set(int arg);
};
class Obj_1a22a0 {
  public:
    bool Set(int x);
};
class O_1a22c0 {
  public:
    char f(int x);
    char pad[0x48];
};
class C_1a22e0 {
  public:
    char pad[0x50];
    unsigned char m50;
    bool SetX(unsigned char x);
};
class O_1a2300 {
  public:
    char pad[0x51];
    char m51;
    char Set(char c);
};
class O_1a2320 {
  public:
    char pad[0x52];
    unsigned char m;
    unsigned char Fn(unsigned char x);
};
struct X_1a2340 {
    char pad[0x54];
    int m54;
    char Set(int v);
};
class C_1a2360 {
  public:
    char m[0x58];
    char f(unsigned char x);
};
class Obj_1a2380 {
  public:
    char pad[0x59];
    char m59;
    char Set(unsigned char c);
};
class Obj_1a23c0 {
  public:
    char pad[0x64];
    int m64;
    char Set(int v);
};
class Obj_1a23e0 {
  public:
    char pad[0x68];
    char m68;
    char Set(char v);
};
class A_1a2400 {
  public:
    virtual void V();
    char pad[101];
    char m69;
    char Fn(char x);
};
class Obj_1a2440 {
  public:
    char pad[0x74];
    int mValue;
    bool Set(int x);
};
class O_1a2460 {
  public:
    char m[0x78];
    char f(char v);
};
class Obj_1a2480 {
  public:
    char pad[0x79];
    char m79;
    char Set(char c);
};
class X_1a24e0 {
  public:
    char pad[0x88];
    char value;
    char Set(char c);
};
struct X_1a2500 {
    char pad[0x89];
    char m;
    char Set(char c);
};
class Target_1a2540 {
  public:
    char pad[0x94];
    int m94;
    bool Set(int value);
};
class A_1a2560 {
  public:
    char pad[0x98];
    unsigned char value;
    unsigned char Set(unsigned char v);
};
class Obj_1a2580 {
  public:
    char pad[0x99];
    char m99;
    bool Set(char c);
};
class Obj_1a2590 {
  public:
    int Get();
    char pad[0x9c];
    int m9c;
};
class A_1a25c0 {
  public:
    char pad[0xa4];
    int value;
    bool Set(int v);
};
class X_1a25e0 {
  public:
    char m[0xa8];
    char F(char c);
};
class X_1a2600 {
  public:
    char m[0xa9];
    char f;
    bool Set(char c);
};
class Obj_1a2630 {
  public:
    char pad[0xb4];
    int value;
};
class Obj_1a2640 {
  public:
    char pad[0xb4];
    int m;
    bool Set(int x);
};
class Obj_1a2660 {
  public:
    char pad[0xb8];
    unsigned char field;
    char Set(unsigned char v);
};
class Obj_1a2680 {
  public:
    char m[0xb9];
    char Set(char x);
};
struct Obj_1a26c0 {
    char pad[0xc4];
    int value;
    char Set(int x);
};
class X_1a26d0 {
  public:
    char pad[0xc8];
    unsigned char value;
    unsigned char Get();
};
class Obj_1a26e0 {
  public:
    char pad[0xc8];
    unsigned char mFlag;
    unsigned char SetFlag(unsigned char v);
};
class X_1a2700 {
  public:
    char pad[0xc9];
    char value;
    X_1a2700() {}
    char Fn(char b);
};
class Obj_1a2740 {
  public:
    char pad[0xd4];
    int value;
    bool Set(int x);
};
class C_1a2760 {
  public:
    char pad[0xd8];
    unsigned char mFlag;
    unsigned char SetFlag(unsigned char b);
};
class Obj_1a2780 {
  public:
    char pad[0xd9];
    char m;
    char Fn(char x);
};
struct A_1a2790 {
    char pad[0xdc];
    int value;
};
class Obj_1a27c0 {
  public:
    char pad[0xe4];
    int value;
    char Set(int x);
};
class X_1a27e0 {
  public:
    char pad[0xe8];
    char m;
    char Set(char c);
};
class O_1a2800 {
  public:
    char m[0xe9];
    char Fn(char x);
};
class Obj_1a2830 {
  public:
    char pad[0xf4];
    int mVal;
    int FUN_001a2830();
};
class X_1a2840 {
  public:
    char pad[0xf4];
    int mF4;
    bool Set(int);
};
class Obj_1a2860 {
  public:
    char Set(char x);
    char pad[0xf8];
};
class Obj_1a2880 {
  public:
    char pad[0xf9];
    char mVal;
    bool Set(char c);
};
class Obj_1a28c0 {
  public:
    char pad[0x104];
    int mValue;
    bool Set(int value);
};
class Obj_1a28d0 {
  public:
    char pad[0x108];
    unsigned char Get();
};
class Obj_1a28e0 {
  public:
    char pad[0x108];
    char flag;
    char SetFlag(char b);
};
struct Obj_1a2900 {
    char pad[0x109];
    unsigned char value;
    char Set(unsigned char v);
};
class Obj_1a2940 {
  public:
    char pad[0x114];
    int mVal;
    char Set(int x);
};
class Obj_1a2960 {
  public:
    char pad[0x118];
    char value;
    char Fn(char v);
};
struct Obj_1a2970 {
    char pad[0x119];
    unsigned char Get();
};
class X_1a2980 {
  public:
    char pad[0x119];
    unsigned char m;
    unsigned char Set(unsigned char v);
};
class Obj_1a29c0 {
  public:
    char pad[0x124];
    int mVal;
    char Set(int v);
};
struct Sub_1a29e0 {
    char m128;
};
class Obj_1a29e0 {
  public:
    char pad[0x128];
    Sub_1a29e0 m;
    char Fn(char c);
};
class Obj_1a2a00 {
  public:
    char pad[0x129];
    unsigned char value;
    unsigned char Set(unsigned char v);
};
class A_1a2a30 {
  public:
    char pad[0x134];
    int value;
    int Get();
};
class Obj_1a2a40 {
  public:
    char pad[0x134];
    int m134;
    char FUN_001a2a40(int);
};
class Obj_1a2a60 {
  public:
    char pad[0x138];
    char mVal;
    char Set(char v);
};
class Obj_1a2a80 {
  public:
    char F(char value);
    char m[0x139];
};
class A_1a2ac0 {
  public:
    char pad[0x144];
    int m;
    bool Set(int x);
};
class X_1a2ae0 {
  public:
    char pad[0x148];
    char m148;
    char f4(unsigned char v);
};
class X_1a2b00 {
  public:
    char m[0x149];
    char SetB(unsigned char b);
};
class Obj_1a2b30 {
  public:
    char pad[0x154];
    int value;
    int Get();
};
class Obj_1a2b40 {
  public:
    char pad[0x154];
    int m154;
    char Set(int v);
};
class Obj_1a2b60 {
  public:
    char pad[0x158];
    char value;
    unsigned char Fn(unsigned char x);
};
class Obj_1a2b80 {
  public:
    char Set(unsigned char value);
    char pad[0x159];
    char m159;
};
class Obj_1a2bc0 {
  public:
    char m[0x164];
    char Set(int v);
};
class Obj_1a2be0 {
  public:
    char pad[0x168];
    char m;
    char Set(unsigned char v);
};
class C_1a2c00 {
  public:
    char pad[0x169];
    unsigned char mValue;
    bool Set(unsigned char value);
};
class Obj_1a2c40 {
  public:
    char pad[0x174];
    int m174;
    bool Set(int v);
};
class O_1a2c60 {
  public:
    char pad[0x178];
    char m178;
    char Set(char c);
};
class O_1a2c80 {
  public:
    char pad[0x179];
    char m;
    char Set(char v);
};
class Obj_1a2cc0 {
  public:
    char pad[0x184];
    int mValue;
    bool Set(int v);
};
class Obj_1a2d00 {
  public:
    char pad[0x189];
    char m189;
    char Target(char v);
};
class Obj_1a2d20 {
  public:
    char pad[0x190];
    int value;
    int FUN_001a2d20();
};
class T_1a2d40 {
  public:
    char Pad[0x194];
    int Value;
    bool Set(int x);
};
extern int* hulk_at_004e1708;
class CCondition_1a2d70 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1710;
class CCondition_1a2dd0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0041c4f0[];
struct Sub_1a2e00 {
    void Fin_0027af50() throw();
};
class Condition_1a2e00 {
  public:
    void* vptr;
    ~Condition_1a2e00() throw();
};
class Event_StringCondition_1a2e00 : public Condition_1a2e00 {
  public:
    char pad[0x10 - 4];
    Sub_1a2e00 sub;
    ~Event_StringCondition_1a2e00() throw();
};
extern int* hulk_at_004e1718;
class CCondition_1a2e40 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1720;
class CCondition_1a2ea0 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1728;
class CCondition_1a2f10 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1730;
class CCondition_1a2f80 {
  public:
    virtual int vfunc_0(int);
};
extern int* hulk_at_004e1738;
class CCondition_1a2fe0 {
  public:
    virtual int vfunc_0(int);
};
class Condition_1a2ff0 {
  public:
    Condition_1a2ff0(int);
    virtual void f();
};
class Part {
  public:
    Part();
};
class Event_PropTypeCondition : public Condition_1a2ff0 {
    char pad[12];
    Part part;

  public:
    Event_PropTypeCondition();
    virtual void f();
};
extern void* hulk_at_0041c590[];
class Str_1a3010 {
  public:
    void Init_0027af50();
};
class Condition_1a3010 {
  public:
    void* vptr;
    char pad[12];
    Str_1a3010 s;
    void Fin_002345b0();
};
class Event_PropTypeCondition_1a3010 : public Condition_1a3010 {
  public:
    ~Event_PropTypeCondition_1a3010();
};
extern int* hulk_at_004e1740;
class CCondition_1a3050 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0041c5b0[];
struct Sub_1a3080 {
    void Fin_0027af50();
};
class Condition_1a3080 {
  public:
    void* vptr;
    void Fin_002345b0();
};
class Event_PropStateNameCondition_1a3080 : public Condition_1a3080 {
  public:
    char pad[0xc];
    Sub_1a3080 sub;
    void f();
};
extern int* hulk_at_004e1748;
class CCondition_1a30c0 {
  public:
    virtual int vfunc_0(int);
};
extern void* hulk_at_0041c5d0[];
struct Sub_1a30f0 {
    void Fin_0027af50() throw();
};
class Condition_1a30f0 {
  public:
    void* vptr;
    ~Condition_1a30f0() throw();
};
class Event_PropNameCondition_1a30f0 : public Condition_1a30f0 {
  public:
    char pad[0x10 - 4];
    Sub_1a30f0 sub;
    ~Event_PropNameCondition_1a30f0() throw();
};
extern int* hulk_at_004e1750;
class CCondition_1a3130 {
  public:
    virtual int vfunc_0(int);
};
struct Param_1a31c0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1a31c0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
extern int* hulk_at_004e1758;
class CCondition_1a3230 {
  public:
    virtual int vfunc_0(int);
};
struct Param_1a34e0 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct Track_1a34e0 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
int __cdecl FUN_0008d340(void *);
void *__cdecl FUN_0008d6d0(unsigned int);
struct Item { char pad[0x4c]; char* text; hulk_intptr FUN_001a3750(const char* value); };
} // namespace fn_fc5dbd2a
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif
namespace fn_fc5dbd2a {
class Obj_1a3990 {
public:
    char pad[0x80];
    char* name;
    bool SetName(const char* s);
};
extern "C" void __cdecl release(void*);
extern "C" char* __cdecl allocate(hulk_uintptr);
class Obj_1a3a70 {
    char pad[0x90];
    char* text;

  public:
    char Set(const char* s);
};
class Obj_001a3b50 {
public:
    char pad[0xa0];
    char* name;
    bool SetName(const char* s);
};
extern "C" void __cdecl Free(void*);
extern "C" void* __cdecl Alloc(hulk_uintptr);
class Obj_1a3bc0 {
    char pad[0xac];
    char* s;

  public:
    char Set(const char* p);
};
struct Holder { char pad[0xb0]; char *text; hulk_intptr FUN_001a3c30(const char *source); };
extern "C" void freeMem_0008d340(void*);
class Obj_1a3df0 {
    char pad[0xd0];
    char* text;

  public:
    char SetText(const char* s);
};
inline void copy(char* d, const char* s) {
    char c;
    do {
        c = *s;
        s++;
        *d = c;
        d++;
    } while (c);
}
class Obj_1a3e60 {
    char pad[0xdc];
    char* str;

  public:
    char Set(char* s);
};
class Obj_1a3f40 {
    char pad[0xec];
    char* str;

  public:
    unsigned char Set(const char* s);
};
extern "C" void* __cdecl alloc(hulk_uintptr);
class Obj_1a4020 {
    char pad[0xfc];
    char* text;

  public:
    bool set(const char* s);
};
extern "C" void freeBuf_0008d340(void*);
extern "C" void* allocBuf_0008d6d0(hulk_uintptr);
class X_1a41e0 {
    char pad[0x11c];
    char* str;

  public:
    unsigned char Set(const char* s);
};
class Obj_1a4250 {
    char pad[0x120];
    char* str;

  public:
    unsigned char Set(const char* s);
};
inline void Copy(char* dst, const char* src) {
    char c;
    do {
        c = *src;
        ++src;
        *dst = c;
        ++dst;
    } while (c);
}
class Obj_1a42c0 {
    char pad[0x12c];
    char* str;

  public:
    unsigned char Set(const char* s);
};
class Obj_001a4330 {
public:
    char pad[0x130];
    char* name;
    bool SetName(const char* s);
};
class Obj_1a43a0 {
    char pad[0x13c];
    char* text;

  public:
    unsigned char Set(char* s);
};
class Obj_001a4410 {
public:
    char pad[0x140];
    char* name;
    bool SetName(const char* s);
};
class Obj_1a44f0 {
    char pad[0x150];
    char* text;

  public:
    unsigned char Set(const char* s);
};
extern "C" void __cdecl FreeMem_0008d340(void*);
class Obj_1a45d0 {
    char pad[0x160];
    char* name;

  public:
    unsigned char SetName(const char* s);
};
class Obj_1a4990 {
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
    virtual void Call(int, int, int, int);
};
class Holder_1a4990 {
  public:
    virtual ~Holder_1a4990();
    char pad[0x10];
    Obj_1a4990* second;
    char rest[0x10];
    int* Run();
};
typedef unsigned int u32_1a4a10;
struct Inner_1a4a10 {
    void run_001cb770(hulk_uintptr);
};
struct GlobalObj_1a4a10 {
    char pad[0x30];
    Inner_1a4a10* inner;
};
extern GlobalObj_1a4a10* hulk_at_004dd700;
extern int hulk_at_00494b44, hulk_at_004c13d0;
extern hulk_intptr FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
struct Result_1a4ac0 {
    int pad;
    int type;
    char gap[0x20];
    int state;
};
struct Obj_1a4ac0 {
    Result_1a4ac0* get_001d03c0();
};
extern char DAT_00494b44;
extern char DAT_004c13d0;
void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct ScenarioEvent {
    char pad[4];
    int kind;
    char rest[16];
    int stateName;
};
struct ScenarioParams {
    ScenarioEvent* FUN_001d03c0();
};
struct Event_LocomotionStateNameCondition {
    void* vtable;
    char pad[8];
    int comparison;
    int name;
    unsigned int vfunc_6(int unused0, void* params, int unused2);
};
struct Entry_1a4cb0 {
    const char *name;
    char pad[12];
};
struct Table_1a4cb0 {
    char pad0[0x60];
    Entry_1a4cb0 entries[20];
};
static inline hulk_uintptr strlen_inline(const char *s)
{
    const char *p = s;
    while (*p)
        p++;
    return p - s;
}
struct Entry_1a4e40 {
    const char *name;
    int pad[3];
};
struct Table_1a4e40 {
    char pad0[0x5c];
    Entry_1a4e40 entries[20];
};
struct Entry_1a4fd0 { char reserved[9]; unsigned char value; char trailing[6]; };
struct State_1a4fd0 { char reserved[0x50]; Entry_1a4fd0 entries[20]; };
struct Entry_1a5110 { unsigned char value; char padding[15]; };
struct State_1a5110 { char padding[0x58]; Entry_1a5110 entries[20]; };
class Checker_1a5290 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21();
    virtual bool v22();
};
class Readiness {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual bool v7();
};
struct Resource_1a5290 {
    bool FUN_00222a00(int arg);
};
struct Info_1a5290 {
    char pad0[0x4c];
    const char *name;
};
struct Slot_1a5290 {
    char used;
    char pad1[3];
    int arg;
    Resource_1a5290 *resource;
    char pad0c[0x18 - 0xc];
};
class Loader_1a5290 {
public:
    char pad00[0x1c];
    Info_1a5290 *info;
    char pad20[4];
    Checker_1a5290 *checker;
    char pad28[4];
    Slot_1a5290 slots[20];
    char pad_end[0x210 - 0x2c - 20 * 0x18];
    Readiness *ready;
    bool FUN_001a5290();
};
struct Entry_1a5340 { unsigned int value; char padding[12]; };
struct Data_1a5340 { char padding[0x64]; Entry_1a5340 entries[20]; };
struct Vec3_1a55d0 {
    float x, y, z;
};
struct Matrix {
    float m[16];
    void FUN_0022b980();
};
struct Node {
  public:
    char _m_pad_0[0x8];
    __int64 k;
    char _m_pad_10[0xc0];
    Vec3_1a55d0 position;
    Vec3_1a55d0 direction;
    Vec3_1a55d0 up;
    void FUN_00293ac0(const Vec3_1a55d0*);
};
struct Settings_1a55d0 {
    char pad[0x2c];
    float angle;
};
struct Object {
  public:
    char _m_pad_0[0x1c];
    union { Data_1a5340* data; Settings_1a55d0* settings; };
    char _m_pad_20[0x4];
    char *text;
    void* node;
    char _m_pad_2c[0x30];
    char* name;
    unsigned char FUN_001a36f0(const char *value);
    hulk_intptr FUN_001a37b0(const char* text);
    unsigned int FUN_001a5340(unsigned int index);
    void FUN_001a54a0(Vec3_1a55d0*, float*);
    void FUN_001a55d0();
};
extern char DAT_0049e11c;
extern char DAT_004a0a40;
struct Obj_1a5700 {
    void M1_00222f40(void*);
    void M2_00223fa0();
    void M3_00223060();
};
struct Other_1a5700 {
    void Call_0003be00();
};
extern const float gScale_1a5750;
class Animation {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Play(float, int);
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
    virtual char Ready();
};
class NISAnimationAction {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual char vfunc_5(float, float);
    char pad[0x20];
    Animation* first;
    char pad2[0x1e8];
    Animation* second;
    void F1_001a55d0();
    void F2_001a5700(float);
    char F3_001a5290();
};
struct Entry_1a57d0 {
    Node* n0;
    int p4, p8;
    Node* n1;
    int val;
    int p14;
};
class Obj_1a57d0 {
  public:
    char pad[0x30];
    Entry_1a57d0 e[20];
    int Find(__int64 k);
};
struct Matrix_1a5840 {
 unsigned int data[16];
 void FUN_0022b980();
};
struct Source_1a5840 {
 char pad[0x1c];
 Matrix_1a5840* matrices;
 unsigned int FUN_002843a0(unsigned int a, unsigned int b);
};
struct Transform_1a5840 {
 virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
 virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
 virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
 virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
 virtual void slot16(); virtual Matrix_1a5840* slot17();
};
class Ref {
  public:
    virtual void AddRef();
    virtual void Release();
};
extern void* hulk_at_0041c4d0[];
class Condition_1a5aa0 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class NodeIsNotRunningCondition_1a5aa0 : public Condition_1a5aa0 {
  public:
    NodeIsNotRunningCondition_1a5aa0* vfunc_5(signed char flags);
};
extern char threat_vftable_1a5ad0;
struct Obj_1a5ad0 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_1a5ad0*);
class Event_StringCondition_1a5ad0 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_StringCondition_1a5ad0* vfunc_5(unsigned char);
};
extern void* hulk_at_0041c510[];
class Condition_1a5b00 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class NodeShouldRunImmediatelyCondition_1a5b00 : public Condition_1a5b00 {
  public:
    NodeShouldRunImmediatelyCondition_1a5b00* vfunc_5(signed char flags);
};
extern void* hulk_at_0041c530[];
class Condition_1a5b30 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class Event_LocomotionStateNamePreviousCondition_1a5b30 : public Condition_1a5b30 {
  public:
    Event_LocomotionStateNamePreviousCondition_1a5b30* vfunc_5(signed char flags);
};
extern void* hulk_at_0041c550[];
class Condition_1a5b60 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class Event_LocomotionStateNameCondition_1a5b60 : public Condition_1a5b60 {
  public:
    Event_LocomotionStateNameCondition_1a5b60* vfunc_5(signed char flags);
};
extern void* hulk_at_0041c570[];
class Condition_1a5b90 {
  public:
    void Destroy_002345b0(); // FUN_00236d60, __thiscall, this in ecx
};
class Event_PropStateDescCondition_1a5b90 : public Condition_1a5b90 {
  public:
    Event_PropStateDescCondition_1a5b90* vfunc_5(signed char flags);
};
extern char threat_vftable_1a5bc0;
struct Obj_1a5bc0 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_1a5bc0*);
class Event_PropTypeCondition_1a5bc0 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_PropTypeCondition_1a5bc0* vfunc_5(unsigned char);
};
extern char threat_vftable_1a5bf0;
struct Obj_1a5bf0 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_1a5bf0*);
class Event_PropStateNameCondition_1a5bf0 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_PropStateNameCondition_1a5bf0* vfunc_5(unsigned char);
};
extern char threat_vftable_1a5c20;
struct Obj_1a5c20 {
    int x;
    void f1_0027af50();
    void f2_002345b0();
};
extern void thunk_FUN_00267090(Obj_1a5c20*);
class Event_PropNameCondition_1a5c20 {
  public:
    void* vftable;
    char pad[0x0c];
    Event_PropNameCondition_1a5c20* vfunc_5(unsigned char);
};
extern "C" char DAT_0041c5f0[];
struct Helper_1a5c50 {
    void Init_0027af50();
};
struct TrackBase_1a5c50 {
    void InitTrack_00236d60();
};
class EffectTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual EffectTrack* vfunc_5(unsigned char flag);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    char pad[0x58 - 4];
};
void __cdecl Destroy_0008d330(EffectTrack*);
class X_1a5e20 {
  public:
    char pad[0x24];
    struct Y_1a5e20* p24;
    Y_1a5e20* p28;
    void f();
};
class Y_1a5e20 {
  public:
    virtual void a();
    virtual void b();
};
extern void* hulk_at_0041c668[];
class Ref_1a5eb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1a5eb0 {
  public:
    void* vptr;
};
class EffectAction_1a5eb0 : public Action_1a5eb0 {
  public:
    char pad1c[0x18];
    void* m1c;
    Ref_1a5eb0* m20;
    char pad28[0x4];
    Ref_1a5eb0* m28;
    ~EffectAction_1a5eb0();
};
class CStageCondition_1a6440;
class ParamValue_1a6440 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a6440 : public ParamValue_1a6440 {
  public:
    int pad;
};
class CStageCondition_1a6490;
class ParamValue_1a6490 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a6490 : public ParamValue_1a6490 {
  public:
    int pad;
};
struct CAxisArcCondition_1a64d0;
class CStageCondition_1a64e0 {};
class ParamValue_1a64e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1a64e0 : public ParamValue_1a64e0 {
  public:
    virtual void f();
};
struct CAxisArcCondition_1a6560;
class CStageCondition_1a6570 {};
class ParamValue_1a6570 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1a6570 : public ParamValue_1a6570 {
  public:
    virtual void f();
};
struct CAxisArcCondition_1a65f0;
class CStageCondition_1a6600 {};
class ParamValue_1a6600 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1a6600 : public ParamValue_1a6600 {
  public:
    virtual void f();
};
class CStageCondition_1a6690;
class ParamValue_1a6690 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a6690 : public ParamValue_1a6690 {
  public:
    int pad;
};
struct CAxisArcCondition_1a66d0;
class CStageCondition_1a66e0 {};
class ParamValue_1a66e0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1a66e0 : public ParamValue_1a66e0 {
  public:
    virtual void f();
};
class CStageCondition_1a6770;
class ParamValue_1a6770 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a6770 : public ParamValue_1a6770 {
  public:
    int pad;
};
class CStageCondition_1a67c0;
class ParamValue_1a67c0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a67c0 : public ParamValue_1a67c0 {
  public:
    int pad;
};
class CStageCondition_1a6810;
class ParamValue_1a6810 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a6810 : public ParamValue_1a6810 {
  public:
    int pad;
};
struct CAxisArcCondition_1a6850;
class CStageCondition_1a6860 {};
class ParamValue_1a6860 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
class ParamValueEnum_1a6860 : public ParamValue_1a6860 {
  public:
    virtual void f();
};
class CStageCondition_1a68f0;
class ParamValue_1a68f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a68f0 : public ParamValue_1a68f0 {
  public:
    int pad;
};
class CStageCondition_1a6940;
class ParamValue_1a6940 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
};
class ParamValueInt_1a6940 : public ParamValue_1a6940 {
  public:
    int pad;
};
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);
} // namespace fn_fc5dbd2a
namespace fight {
class ConditionFactoryCaster_1a69c0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class NodeIsNotRunningCondition_1a69c0 {};
} }
namespace fn_fc5dbd2a {
extern char DAT_004c1e58;
class ConditionFactoryCaster_1a6a20 {
  public:
    virtual int check(const char*);
    virtual void other();
};
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(const char*, int, const void*, const void*, int);
extern char DAT_004c1f20;
extern char DAT_004c2280;
} // namespace fn_fc5dbd2a
namespace fight {
class ConditionFactoryCaster_1a6b80 {
  public:
    virtual int Test(void*);
    virtual void Other();
};
}
namespace hulkfight { namespace scenario {
class Event_PropStateDescCondition_1a6b80 {};
} }
namespace fn_fc5dbd2a {
extern char DAT_004c2350;
} // namespace fn_fc5dbd2a
namespace fight {
class ConditionFactoryCaster_1a6be0 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class Event_PropTypeCondition_1a6be0;
} }
namespace fn_fc5dbd2a {
extern char DAT_004c2418;
} // namespace fn_fc5dbd2a
namespace fight {
class ConditionFactoryCaster_1a6c20 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class Event_PropStateNameCondition_1a6c20;
} }
namespace fn_fc5dbd2a {
extern char DAT_004c24e8;
} // namespace fn_fc5dbd2a
namespace fight {
class TrackFactoryCaster_1a6d40 {
  public:
    virtual int vfunc_0(void*);
    virtual void vfunc_1();
};
}
namespace hulkfight { namespace scenario {
class NISAnimationTrack_1a6d40 {};
} }
namespace fn_fc5dbd2a {
extern char DAT_004c2650;
extern "C" char DAT_0048d5bc[];
extern "C" char DAT_004a15cc[];
extern "C" char DAT_004c26a4[];
extern "C" int Compare(void*, int, const char*, const char*, int);
extern const char hulk_at_0048d5bc[];
extern const char hulk_at_0049e11c[];
typedef unsigned int u32_1a6ee0;
typedef unsigned int u32_1a6f10;
class Item_1a8cb0 {
  public:
    virtual void A();
    virtual void B();
};
class Obj_1a8cb0 {
  public:
    char pad[4];
    Item_1a8cb0* a;
    Item_1a8cb0* b;
    Item_1a8cb0* c;
    Item_1a8cb0* d;
    Item_1a8cb0* e;
    void Init_001a5d50();
    void Clear();
};
extern void* hulk_at_0041cf24[];
class Ref_1a8db0 {
  public:
    virtual void F0();
    virtual void Release();
};
struct El {
    void Fin_001a5d50() throw();
    int p0;
    Ref_1a8db0* r1;
    Ref_1a8db0* r2;
    Ref_1a8db0* r3;
    Ref_1a8db0* r4;
    Ref_1a8db0* r5;
};
class NISAnimationAction_1a8db0;
class Action_1a8db0 {
  public:
    void* vptr;
    ~Action_1a8db0() throw();
};
class NISAnimationAction_1a8db0 : public Action_1a8db0 {
  public:
    char pad[0x1c - 4];
    void* m1c;
    Ref_1a8db0* m20;
    char pad2[0x2c - 0x24];
    El e[20];
    ~NISAnimationAction_1a8db0() throw();
};
struct Obj31 {
    char p[0x31];
    char f;
};
struct Mgr_1a8ee0 {
};
struct Hnd {
    void Rel_002080b0();
};
struct Ent_1a8ee0 {
    char p[0xa8];
    char f;
};
struct Hulk {
    void Fn2_0003dd00(int);
};
struct Sub_1a8ee0 {
    char p[0x124];
    Hulk* h;
};
struct Gl {
    char p[0x20];
    Sub_1a8ee0* s;
    char q[0x30];
    Mgr_1a8ee0* m;
};
extern Gl* g_1a8ee0;
struct NISAnimationAction_nv_1a8ee0 {
    void Inner_001a8e60();
};
class Track_1a8f50 {
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
};
class Param_1a8f50 {};
class EffectAction_1a8f50 {
  public:
    int Call_001a5e50(hulkfight::scenario::EffectTrack*, hulk_intptr);
};
extern EffectAction_1a8f50* GetThing_0008d690(int);
extern void* g_vftable_1a8f80[];
class Ref_1a8f80 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
class EffectAction {
  public:
    void* vptr;
    char p[0x18];
    int m1c;
    Ref_1a8f80* m20;
    char p24[4];
    Ref_1a8f80* m28;
    EffectAction* f2(int);
};
class EffectAction_1a8f80 {
  public:
};
extern void __cdecl thunk_FUN_00267090(EffectAction*);
struct Obj_1a9260 {
    Obj_1a9260* Get_00231640();
    Obj_1a9260* Target();
};
extern int __cdecl FUN_00344e74(Obj_1a9260*, int, void*, void*, int);
extern void* g1_1a9260;
extern void* hulk_at_004a15cc;
struct Obj_1a92a0 {
    Obj_1a92a0* Get_00231640();
    Obj_1a92a0* Target();
};
extern int __cdecl FUN_00344e74(Obj_1a92a0*, int, void*, void*, int);
extern void* g1_1a92a0;
extern void* hulk_at_004c26a4;
extern int __cdecl FUN_00344e74(owners::Obj_1a92e0*, int, void*, void*, int);
extern void* g1_1a92e0;
extern void* g2_1a92e0;
class DynamicCaster_1a9420 {
  public:
    virtual void Fna_001a6ee0(void*);
    virtual void b();
    virtual void Fnc_001a6f10(void*);
    virtual int d();
};
extern "C" __int64 __cdecl lookup(void*, int, int);
class LoadInventory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(DynamicCaster_1a9420*, __int64);
    hulk_intptr Load(void* p);
};
class ConditionFactoryCasterTemplate_1a94a0 {
  public:
    virtual bool Cast_001a69c0(void*);
};
extern "C" void* find(void*, ConditionFactoryCasterTemplate_1a94a0*);
class ConditionFactoryCasterTemplate_1a9560 {
  public:
    virtual bool Cast_001a6a60(void*);
};
class Owner {
  public:
    void Apply_00236760(void*);
    void Use_00236760(void*);
    void accept_002367c0(void*);
};
extern "C" void* __cdecl FUN_002343e0(void*, ConditionFactoryCasterTemplate_1a9560*);
class ConditionFactoryCasterTemplate_1a9590 {
  public:
    virtual bool Cast_001a6ac0(void*);
};
void* __cdecl Find_002343e0(void*, ConditionFactoryCasterTemplate_1a9590*);
class ConditionFactoryCasterTemplate_1a95c0 {
  public:
    virtual bool Cast_001a6b20(void*);
};
void* __cdecl Find_002343e0(void*, ConditionFactoryCasterTemplate_1a95c0*);
class ConditionFactoryCasterTemplate_1a9620 {
  public:
    virtual bool FnF_001a6be0(void*);
};
void* __cdecl Find_002343e0(char*, ConditionFactoryCasterTemplate_1a9620*);
class ConditionFactoryCasterTemplate_1a96b0 {
  public:
    virtual bool Cast_001a6c20(void*);
};
class Receiver {
  public:
    void Apply_00236760(void*);
};
extern "C++" __declspec(nothrow) void* FUN_002343e0(void*, ConditionFactoryCasterTemplate_1a96b0*);
class ConditionFactoryCasterTemplate_1a9740 {
  public:
    virtual bool Cast_001a6c60(void*);
};
class Obj {
  public:
    char _m_pad_0[0x2c];
    float angle;
    char _m_pad_30[0x14];
    float x;
    float y;
    float z;
    char _m_pad_50[0x34];
    int value;
    unsigned int FUN_001a2060(const Angles *angles);
    char Set(float);
    bool Set(int x);
    void set_00236760(void*);
    void Apply_00236760(void*);
    void Do_00236760(void*);
    void* Get_00236760(ConditionFactoryCasterTemplate_1a9740*);
    void Find_002367c0(void*);
};
extern ConditionFactoryCasterTemplate_1a9740* __cdecl Lookup_002343e0(void*, ConditionFactoryCasterTemplate_1a9740*);
class TrackFactoryCasterTemplate_1a97d0 {
  public:
    virtual bool Cast_001a6ca0(void*);
};
extern "C" void* FindTrack(void*, TrackFactoryCasterTemplate_1a97d0*);
class TrackFactoryCasterTemplate_1a9a90 {
  public:
    virtual bool dummy_001a6d40(void*);
};
extern "C" void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1a9a90*);
class Track_1a9ac0 {
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
    virtual int v10(int, int, int);
};
class Param_1a9ac0 {};
class NISAnimationAction_1a9ac0 {
  public:
    int helper_001a8d10(hulk_intptr, hulk_intptr);
};
extern "C" void* __cdecl FUN_0008d690(int);
} // namespace fn_fc5dbd2a
inline void* __cdecl operator new(size_t, void* where) {
    return where;
}
namespace fn_fc5dbd2a {
class TrackFactoryTemplate_1aa400 {
  public:
    TrackFactoryTemplate_1aa400() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" int NodeVtable;
class Factory_1aa440 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
};
class Node_1aa440 {
  public:
    void Init_00234590(int);
};
extern int hulk_at_0041d05c;
struct ConditionFactoryTemplate_1aa470 {
    void* m_vptr;
    void base1_dtor_001a2d50();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aa4a0 {
  public:
    TrackFactoryTemplate_1aa4a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
struct Base_1aa4e0 {
    Base_1aa4e0(int) throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_1aa4e0* f();
    int m4, m8;
};
struct Cond_1aa4e0 : Base_1aa4e0 {
    char mc;
    Cond_1aa4e0() throw() : Base_1aa4e0(0) { mc = 1; }
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_1aa4e0* f();
};
extern int hulk_at_0041d078;
struct ConditionFactoryTemplate_1aa510 {
    void* m_vptr;
    void base1_dtor_001a2e20();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aa540 {
  public:
    TrackFactoryTemplate_1aa540() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_0041d094;
struct ConditionFactoryTemplate_1aa5c0 {
    void* m_vptr;
    void base1_dtor_001a2e80();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aa5f0 {
  public:
    TrackFactoryTemplate_1aa5f0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0041c550[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Event_1aa630 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void V5();
    void Init_00234590(int);
    int a;
    int b;
    int c;
    int d;
};
extern int hulk_at_0041d0b0;
struct ConditionFactoryTemplate_1aa670 {
    void* m_vptr;
    void base1_dtor_001a2ef0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aa6a0 {
  public:
    TrackFactoryTemplate_1aa6a0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Condition_1aa6e0 {
  public:
    virtual void a();
    virtual bool Fnb_00234270(void*);
    virtual bool Fnc_002342b0(int);
    virtual bool Fnd_002344d0(hulk_intptr, int, hulk_intptr);
    virtual bool Fne_00234350(int, int);
    virtual void* Fnf_001a5b90(char);
    char pad[8];
    int val;
    Condition_1aa6e0(int) throw();
};
class Event_PropStateDescCondition_1aa6e0 : public Condition_1aa6e0 {
  public:
    Event_PropStateDescCondition_1aa6e0() throw() : Condition_1aa6e0(0) { val = 0; }
    virtual void a();
};
extern int hulk_at_0041d0cc;
struct ConditionFactoryTemplate_1aa710 {
    void* m_vptr;
    void base1_dtor_001a2f60();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aa740 {
  public:
    TrackFactoryTemplate_1aa740() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Track_1aa780 {
  public:
    hulk_intptr make_001a3240();
};
extern int hulk_at_0041d0e8;
class TrackFactoryTemplate_1aa9d0 {
  public:
    TrackFactoryTemplate_1aa9d0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_0041d10c;
struct ConditionFactoryTemplate_1aaa40 {
    void* m_vptr;
    void base1_dtor_001a2db0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aaa70 {
  public:
    TrackFactoryTemplate_1aaa70() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern char VT_1aaab0[];
class Sub_1aaab0 {
  public:
    void Init_0027af00();
};
class Event_PropTypeCondition_1aaab0 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    char pad[12];
    Sub_1aaab0 sub;
    Event_PropTypeCondition_1aaab0(int);
};
extern int hulk_at_0041d128;
struct ConditionFactoryTemplate_1aaae0 {
    void* m_vptr;
    void base1_dtor_001a2fc0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aab10 {
  public:
    TrackFactoryTemplate_1aab10() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern "C" char DAT_0041c5b0[];
struct Event_1aab50 {
    void Init_00234590(int);
};
struct Tail_1aab50 {
    void Run_0027af00();
};
extern int hulk_at_0041d144;
struct ConditionFactoryTemplate_1aab80 {
    void* m_vptr;
    void base1_dtor_001a3030();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aabb0 {
  public:
    TrackFactoryTemplate_1aabb0() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
extern int hulk_at_0041d160;
struct ConditionFactoryTemplate_1aac20 {
    void* m_vptr;
    void base1_dtor_001a30a0();
    void base2_dtor_002343d0();
    void* scalar_dtor(unsigned char flags);
};
class TrackFactoryTemplate_1aac50 {
  public:
    TrackFactoryTemplate_1aac50() {}
    virtual void vf0_00038290();
    virtual void vf1_000382a0();
    int mPad;
    TrackImpl mTrack;
};
class Dummy_1aac90 {
  public:
    hulk_intptr FUN_001a3140();
};

} // namespace fn_fc5dbd2a

// 0x001a1ed0 FUN_001a1ed0 (12 B): matches/0x001a1ed0.cpp
// sym: ?FUN_001a1ed0@Obj_1a1ed0@owners@@QAEEE@Z
unsigned char owners::Obj_1a1ed0::FUN_001a1ed0(unsigned char v) {
    value = v;
    return 1;
}


// 0x001a1ee0 FUN_001a1ee0 (4 B): matches/0x001a1ee0.cpp
// sym: ?FUN_001a1ee0@O_1a1ee0@owners@@QAEPAXXZ
void* owners::O_1a1ee0::FUN_001a1ee0() {
    return (char*)this + 0x10;
}


// 0x001a1ef0 FUN_001a1ef0 (12 B): matches/0x001a1ef0.cpp
// sym: ?FUN_001a1ef0@T_1a1ef0@owners@@QAE_NE@Z
bool owners::T_1a1ef0::FUN_001a1ef0(unsigned char x) {
    field = x;
    return true;
}

namespace fn_fc5dbd2a {

// 0x001a1f00 FUN_001a1f00 (12 B): matches/0x001a1f00.cpp
// sym: ?SetCompare_001a1f00@Obj_1a1f00@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a1f00::SetCompare_001a1f00(int x) {
    mValue = x;
    return 1;
}


// 0x001a1f10 FUN_001a1f10 (12 B): matches/0x001a1f10.cpp
// sym: ?SetOldState_001a1f10@Obj_1a1f10@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a1f10::SetOldState_001a1f10(int x) {
    mValue = x;
    return 1;
}


// 0x001a1f20 FUN_001a1f20 (12 B): matches/0x001a1f20.cpp
// sym: ?SetCompare_001a1f20@A_1a1f20@fn_fc5dbd2a@@QAE_NH@Z
bool A_1a1f20::SetCompare_001a1f20(int v) {
    m = v;
    return true;
}


// 0x001a1f30 FUN_001a1f30 (12 B): matches/0x001a1f30.cpp
// sym: ?SetNewState_001a1f30@X_1a1f30@fn_fc5dbd2a@@QAE_NH@Z
bool X_1a1f30::SetNewState_001a1f30(int x) {
    value = x;
    return true;
}


// 0x001a1f40 FUN_001a1f40 (12 B): matches/0x001a1f40.cpp
// sym: ?f@O_1a1f40@fn_fc5dbd2a@@QAEDH@Z
char O_1a1f40::f(int x) {
    mC = x;
    return 1;
}

} // namespace fn_fc5dbd2a

// 0x001a1f50 FUN_001a1f50 (4 B): matches/0x001a1f50.cpp
// sym: ?FUN_001a1f50@Obj_1a1f50@owners@@QAEPAHXZ
int* owners::Obj_1a1f50::FUN_001a1f50() {
    return (int*)((char*)this + 0x10);
}


// 0x001a1f60 FUN_001a1f60 (4 B): matches/0x001a1f60.cpp
// sym: ?FUN_001a1f60@X_1a1f60@owners@@QAEPAHXZ
int* owners::X_1a1f60::FUN_001a1f60() {
    return (int*)((char*)this + 0x10);
}

namespace fn_fc5dbd2a {

// 0x001a1f70 FUN_001a1f70 (4 B): matches/0x001a1f70.cpp
// sym: ?FUN_001a1f70@fn_fc5dbd2a@@YIPAUObj_1a1f70@1@PAU21@@Z
Obj_1a1f70* __fastcall FUN_001a1f70(Obj_1a1f70* self) {
    return (Obj_1a1f70*)((char*)self + 0x10);
}

} // namespace fn_fc5dbd2a

// 0x001a1f80 FUN_001a1f80 (12 B): matches/0x001a1f80.cpp
// sym: ?FUN_001a1f80@C_1a1f80@owners@@QAEDH@Z
char owners::C_1a1f80::FUN_001a1f80(int x) {
    m = x;
    return 1;
}


// 0x001a1fa0 FUN_001a1fa0 (12 B): matches/0x001a1fa0.cpp
// sym: ?FUN_001a1fa0@Obj_1a1fa0@owners@@QAEDH@Z
char owners::Obj_1a1fa0::FUN_001a1fa0(int value) {
    m10 = value;
    return 1;
}


// 0x001a1fb0 FUN_001a1fb0 (4 B): matches/0x001a1fb0.cpp
// sym: ?FUN_001a1fb0@Obj_1a1fb0@owners@@QAEPADXZ
char* owners::Obj_1a1fb0::FUN_001a1fb0() {
    return pad + 0x18;
}


// 0x001a1fc0 FUN_001a1fc0 (4 B): matches/0x001a1fc0.cpp
// sym: ?FUN_001a1fc0@Obj_1a1fc0@owners@@QAEPAHXZ
int* owners::Obj_1a1fc0::FUN_001a1fc0() {
    return (int*)((char*)this + 0x20);
}


// 0x001a1fe0 FUN_001a1fe0 (12 B): matches/0x001a1fe0.cpp
// sym: ?FUN_001a1fe0@Obj_1a1fe0@owners@@QAEDH@Z
char owners::Obj_1a1fe0::FUN_001a1fe0(int v) {
    *(int*)((char*)this + 0x28) = v;
    return 1;
}


// 0x001a1ff0 FUN_001a1ff0 (4 B): matches/0x001a1ff0.cpp
// sym: ?FUN_001a1ff0@O_1a1ff0@owners@@QAEPADXZ
char* owners::O_1a1ff0::FUN_001a1ff0() throw() {
    return (char*)((char*)this + 0x30);
}

namespace fn_fc5dbd2a {

// 0x001a2020 FUN_001a2020 (26 B): matches/0x001a2020.cpp
// sym: ?Set@Obj_1a2020@fn_fc5dbd2a@@QAE_NPAUVec3_1a2020@2@@Z
bool Obj_1a2020::Set(Vec3_1a2020* v) {
    v38 = v->x;
    v3c = v->y;
    v40 = v->z;
    return true;
}


// 0x001a2060 FUN_001a2060 (60 B): equivalent/0x001a2060.cpp
// sym: ?FUN_001a2060@Obj@fn_fc5dbd2a@@QAEIPBUAngles@2@@Z @86f8d276a4f3 @wc54065c84755
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001a2060 @ 0x001a2060
unsigned int Obj::FUN_001a2060(const Angles *angles) {
    x = angles->x * DAT_003f32b8;
    y = angles->y * DAT_003f32b8;
    z = angles->z * DAT_003f32b8;
    union { float f; unsigned int u; } bits;
    bits.f = z;
    return (bits.u & 0xffffff00u) | 1u;
}

} // namespace fn_fc5dbd2a

// 0x001a20b0 FUN_001a20b0 (12 B): matches/0x001a20b0.cpp
// sym: ?FUN_001a20b0@Obj_1a20b0@owners@@QAEDH@Z
char owners::Obj_1a20b0::FUN_001a20b0(int value) {
    *(int*)(pad + 0x50) = value;
    return 1;
}

namespace fn_fc5dbd2a {

// 0x001a20c0 FUN_001a20c0 (4 B): matches/0x001a20c0.cpp
// sym: ?Get@Obj_1a20c0@fn_fc5dbd2a@@QAEPAXXZ
void* Obj_1a20c0::Get() {
    return (char*)this + 0x58;
}

} // namespace fn_fc5dbd2a

// 0x001a20e0 FUN_001a20e0 (12 B): matches/0x001a20e0.cpp
// sym: ?FUN_001a20e0@C_1a20e0@owners@@QAEDH@Z
char owners::C_1a20e0::FUN_001a20e0(int v) {
    char* p = (char*)this;
    *(int*)(p + 0x60) = v;
    return 1;
}

namespace fn_fc5dbd2a {

// 0x001a20f0 FUN_001a20f0 (12 B): matches/0x001a20f0.cpp
// sym: ?Set@Obj_1a20f0@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a20f0::Set(int v) {
    mField = v;
    return true;
}


// 0x001a2100 FUN_001a2100 (12 B): matches/0x001a2100.cpp
// sym: ?Fn@Obj_1a2100@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a2100::Fn(int v) {
    *(int*)(m + 0x10) = v;
    return 1;
}


// 0x001a2120 FUN_001a2120 (12 B): matches/0x001a2120.cpp
// sym: ?Set@Obj_1a2120@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2120::Set(int x) {
    mField = x;
    return true;
}


// 0x001a2140 FUN_001a2140 (12 B): matches/0x001a2140.cpp
// sym: ?Set@Target_1a2140@fn_fc5dbd2a@@QAE_NH@Z
bool Target_1a2140::Set(int v) {
    mValue = v;
    return true;
}


// 0x001a2160 FUN_001a2160 (12 B): matches/0x001a2160.cpp
// sym: ?Set@Obj_1a2160@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a2160::Set(int x) {
    *(int*)((char*)this + 0x1c) = x;
    return 1;
}


// 0x001a2180 FUN_001a2180 (12 B): matches/0x001a2180.cpp
// sym: ?Set@Obj_1a2180@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2180::Set(int v) {
    mValue = v;
    return true;
}


// 0x001a21b0 FUN_001a21b0 (12 B): matches/0x001a21b0.cpp
// sym: ?Set@Obj_1a21b0@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a21b0::Set(int v) {
    *(int*)((char*)this + 0x28) = v;
    return 1;
}


// 0x001a21d0 FUN_001a21d0 (18 B): matches/0x001a21d0.cpp
// sym: ?Set@Obj@fn_fc5dbd2a@@QAEDM@Z
char Obj::Set(float x) {
    angle = x * 0.017453292519943295f;
    return 1;
}


// 0x001a2200 FUN_001a2200 (12 B): matches/0x001a2200.cpp
// sym: ?Set@C_1a2200@fn_fc5dbd2a@@QAEDD@Z
char C_1a2200::Set(char x) {
    m30 = x;
    return 1;
}


// 0x001a2220 FUN_001a2220 (12 B): matches/0x001a2220.cpp
// sym: ?Fn@O_1a2220@fn_fc5dbd2a@@QAEDH@Z
char O_1a2220::Fn(int a) {
    m34 = a;
    return 1;
}


// 0x001a2240 FUN_001a2240 (12 B): matches/0x001a2240.cpp
// sym: ?Set@Obj_1a2240@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2240::Set(int value) {
    m38 = value;
    return true;
}


// 0x001a2260 FUN_001a2260 (12 B): matches/0x001a2260.cpp
// sym: ?Set@Obj_1a2260@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2260::Set(int x) {
    m3c = x;
    return true;
}


// 0x001a2280 FUN_001a2280 (12 B): matches/0x001a2280.cpp
// sym: ?Set@C_1a2280@fn_fc5dbd2a@@QAEEH@Z
unsigned char C_1a2280::Set(int arg) {
    value = arg;
    return 1;
}


// 0x001a22a0 FUN_001a22a0 (12 B): matches/0x001a22a0.cpp
// sym: ?Set@Obj_1a22a0@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a22a0::Set(int x) {
    *(int*)((char*)this + 0x44) = x;
    return true;
}


// 0x001a22c0 FUN_001a22c0 (12 B): matches/0x001a22c0.cpp
// sym: ?f@O_1a22c0@fn_fc5dbd2a@@QAEDH@Z
char O_1a22c0::f(int x) {
    *(int*)((char*)this + 0x48) = x;
    return 1;
}


// 0x001a22e0 FUN_001a22e0 (12 B): matches/0x001a22e0.cpp
// sym: ?SetX@C_1a22e0@fn_fc5dbd2a@@QAE_NE@Z
bool C_1a22e0::SetX(unsigned char x) {
    m50 = x;
    return true;
}


// 0x001a2300 FUN_001a2300 (12 B): matches/0x001a2300.cpp
// sym: ?Set@O_1a2300@fn_fc5dbd2a@@QAEDD@Z
char O_1a2300::Set(char c) {
    m51 = c;
    return 1;
}


// 0x001a2320 FUN_001a2320 (12 B): matches/0x001a2320.cpp
// sym: ?Fn@O_1a2320@fn_fc5dbd2a@@QAEEE@Z
unsigned char O_1a2320::Fn(unsigned char x) {
    m = x;
    return 1;
}


// 0x001a2340 FUN_001a2340 (12 B): matches/0x001a2340.cpp
// sym: ?Set@X_1a2340@fn_fc5dbd2a@@QAEDH@Z
char X_1a2340::Set(int v) {
    m54 = v;
    return 1;
}


// 0x001a2360 FUN_001a2360 (12 B): matches/0x001a2360.cpp
// sym: ?f@C_1a2360@fn_fc5dbd2a@@QAEDE@Z
char C_1a2360::f(unsigned char x) {
    m[0x58] = x;
    return 1;
}


// 0x001a2380 FUN_001a2380 (12 B): matches/0x001a2380.cpp
// sym: ?Set@Obj_1a2380@fn_fc5dbd2a@@QAEDE@Z
char Obj_1a2380::Set(unsigned char c) {
    m59 = c;
    return 1;
}


// 0x001a23c0 FUN_001a23c0 (12 B): matches/0x001a23c0.cpp
// sym: ?Set@Obj_1a23c0@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a23c0::Set(int v) {
    m64 = v;
    return 1;
}


// 0x001a23e0 FUN_001a23e0 (12 B): matches/0x001a23e0.cpp
// sym: ?Set@Obj_1a23e0@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a23e0::Set(char v) {
    m68 = v;
    return 1;
}


// 0x001a2400 FUN_001a2400 (12 B): matches/0x001a2400.cpp
// sym: ?Fn@A_1a2400@fn_fc5dbd2a@@QAEDD@Z
char A_1a2400::Fn(char x) {
    m69 = x;
    return 1;
}


// 0x001a2440 FUN_001a2440 (12 B): matches/0x001a2440.cpp
// sym: ?Set@Obj_1a2440@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2440::Set(int x) {
    mValue = x;
    return true;
}


// 0x001a2460 FUN_001a2460 (12 B): matches/0x001a2460.cpp
// sym: ?f@O_1a2460@fn_fc5dbd2a@@QAEDD@Z
char O_1a2460::f(char v) {
    m[0x78] = v;
    return 1;
}


// 0x001a2480 FUN_001a2480 (12 B): matches/0x001a2480.cpp
// sym: ?Set@Obj_1a2480@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2480::Set(char c) {
    m79 = c;
    return 1;
}


// 0x001a24c0 FUN_001a24c0 (15 B): matches/0x001a24c0.cpp
// sym: ?Set@Obj@fn_fc5dbd2a@@QAE_NH@Z
bool Obj::Set(int x) {
    value = x;
    return true;
}


// 0x001a24e0 FUN_001a24e0 (15 B): matches/0x001a24e0.cpp
// sym: ?Set@X_1a24e0@fn_fc5dbd2a@@QAEDD@Z
char X_1a24e0::Set(char c) {
    value = c;
    return 1;
}


// 0x001a2500 FUN_001a2500 (15 B): matches/0x001a2500.cpp
// sym: ?Set@X_1a2500@fn_fc5dbd2a@@QAEDD@Z
char X_1a2500::Set(char c) {
    m = c;
    return 1;
}


// 0x001a2540 FUN_001a2540 (15 B): matches/0x001a2540.cpp
// sym: ?Set@Target_1a2540@fn_fc5dbd2a@@QAE_NH@Z
bool Target_1a2540::Set(int value) {
    m94 = value;
    return true;
}


// 0x001a2560 FUN_001a2560 (15 B): matches/0x001a2560.cpp
// sym: ?Set@A_1a2560@fn_fc5dbd2a@@QAEEE@Z
unsigned char A_1a2560::Set(unsigned char v) {
    value = v;
    return 1;
}


// 0x001a2580 FUN_001a2580 (15 B): matches/0x001a2580.cpp
// sym: ?Set@Obj_1a2580@fn_fc5dbd2a@@QAE_ND@Z
bool Obj_1a2580::Set(char c) {
    m99 = c;
    return true;
}


// 0x001a2590 FUN_001a2590 (7 B): matches/0x001a2590.cpp
// sym: ?Get@Obj_1a2590@fn_fc5dbd2a@@QAEHXZ
int Obj_1a2590::Get() {
    return m9c;
}


// 0x001a25c0 FUN_001a25c0 (15 B): matches/0x001a25c0.cpp
// sym: ?Set@A_1a25c0@fn_fc5dbd2a@@QAE_NH@Z
bool A_1a25c0::Set(int v) {
    value = v;
    return true;
}


// 0x001a25e0 FUN_001a25e0 (15 B): matches/0x001a25e0.cpp
// sym: ?F@X_1a25e0@fn_fc5dbd2a@@QAEDD@Z
char X_1a25e0::F(char c) {
    m[0xa8] = c;
    return 1;
}


// 0x001a2600 FUN_001a2600 (15 B): matches/0x001a2600.cpp
// sym: ?Set@X_1a2600@fn_fc5dbd2a@@QAE_ND@Z
bool X_1a2600::Set(char c) {
    f = c;
    return true;
}


// 0x001a2630 FUN_001a2630 (7 B): matches/0x001a2630.cpp
// sym: ?FUN_001a2630@fn_fc5dbd2a@@YIHPAVObj_1a2630@1@@Z
int __fastcall FUN_001a2630(Obj_1a2630* self) {
    return self->value;
}


// 0x001a2640 FUN_001a2640 (15 B): matches/0x001a2640.cpp
// sym: ?Set@Obj_1a2640@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2640::Set(int x) {
    m = x;
    return true;
}


// 0x001a2660 FUN_001a2660 (15 B): matches/0x001a2660.cpp
// sym: ?Set@Obj_1a2660@fn_fc5dbd2a@@QAEDE@Z
char Obj_1a2660::Set(unsigned char v) {
    field = v;
    return 1;
}


// 0x001a2680 FUN_001a2680 (15 B): matches/0x001a2680.cpp
// sym: ?Set@Obj_1a2680@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2680::Set(char x) {
    m[0xb9] = x;
    return 1;
}


// 0x001a26c0 FUN_001a26c0 (15 B): matches/0x001a26c0.cpp
// sym: ?Set@Obj_1a26c0@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a26c0::Set(int x) {
    value = x;
    return 1;
}


// 0x001a26d0 FUN_001a26d0 (7 B): matches/0x001a26d0.cpp
// sym: ?Get@X_1a26d0@fn_fc5dbd2a@@QAEEXZ
unsigned char X_1a26d0::Get() {
    return value;
}


// 0x001a26e0 FUN_001a26e0 (15 B): matches/0x001a26e0.cpp
// sym: ?SetFlag@Obj_1a26e0@fn_fc5dbd2a@@QAEEE@Z
unsigned char Obj_1a26e0::SetFlag(unsigned char v) {
    mFlag = v;
    return 1;
}


// 0x001a2700 FUN_001a2700 (15 B): matches/0x001a2700.cpp
// sym: ?Fn@X_1a2700@fn_fc5dbd2a@@QAEDD@Z
char X_1a2700::Fn(char b) {
    value = b;
    return 1;
}


// 0x001a2740 FUN_001a2740 (15 B): matches/0x001a2740.cpp
// sym: ?Set@Obj_1a2740@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2740::Set(int x) {
    value = x;
    return true;
}


// 0x001a2760 FUN_001a2760 (15 B): matches/0x001a2760.cpp
// sym: ?SetFlag@C_1a2760@fn_fc5dbd2a@@QAEEE@Z
unsigned char C_1a2760::SetFlag(unsigned char b) {
    mFlag = b;
    return 1;
}


// 0x001a2780 FUN_001a2780 (15 B): matches/0x001a2780.cpp
// sym: ?Fn@Obj_1a2780@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2780::Fn(char x) {
    m = x;
    return 1;
}


// 0x001a2790 FUN_001a2790 (7 B): matches/0x001a2790.cpp
// sym: ?FUN_001a2790@fn_fc5dbd2a@@YIHPAUA_1a2790@1@@Z
int __fastcall FUN_001a2790(A_1a2790* self) {
    return self->value;
}


// 0x001a27c0 FUN_001a27c0 (15 B): matches/0x001a27c0.cpp
// sym: ?Set@Obj_1a27c0@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a27c0::Set(int x) {
    value = x;
    return 1;
}


// 0x001a27e0 FUN_001a27e0 (15 B): matches/0x001a27e0.cpp
// sym: ?Set@X_1a27e0@fn_fc5dbd2a@@QAEDD@Z
char X_1a27e0::Set(char c) {
    m = c;
    return 1;
}


// 0x001a2800 FUN_001a2800 (15 B): matches/0x001a2800.cpp
// sym: ?Fn@O_1a2800@fn_fc5dbd2a@@QAEDD@Z
char O_1a2800::Fn(char x) {
    m[0xe9] = x;
    return 1;
}


// 0x001a2830 FUN_001a2830 (7 B): matches/0x001a2830.cpp
// sym: ?FUN_001a2830@Obj_1a2830@fn_fc5dbd2a@@QAEHXZ
int Obj_1a2830::FUN_001a2830() {
    return mVal;
}


// 0x001a2840 FUN_001a2840 (15 B): matches/0x001a2840.cpp
// sym: ?Set@X_1a2840@fn_fc5dbd2a@@QAE_NH@Z
bool X_1a2840::Set(int v) {
    mF4 = v;
    return true;
}


// 0x001a2860 FUN_001a2860 (15 B): matches/0x001a2860.cpp
// sym: ?Set@Obj_1a2860@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2860::Set(char x) {
    pad[0xf8] = x;
    return 1;
}


// 0x001a2880 FUN_001a2880 (15 B): matches/0x001a2880.cpp
// sym: ?Set@Obj_1a2880@fn_fc5dbd2a@@QAE_ND@Z
bool Obj_1a2880::Set(char c) {
    mVal = c;
    return true;
}


// 0x001a28c0 FUN_001a28c0 (15 B): matches/0x001a28c0.cpp
// sym: ?Set@Obj_1a28c0@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a28c0::Set(int value) {
    mValue = value;
    return true;
}


// 0x001a28d0 FUN_001a28d0 (7 B): matches/0x001a28d0.cpp
// sym: ?Get@Obj_1a28d0@fn_fc5dbd2a@@QAEEXZ
unsigned char Obj_1a28d0::Get() {
    return pad[0x108];
}


// 0x001a28e0 FUN_001a28e0 (15 B): matches/0x001a28e0.cpp
// sym: ?SetFlag@Obj_1a28e0@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a28e0::SetFlag(char b) {
    flag = b;
    return 1;
}


// 0x001a2900 FUN_001a2900 (15 B): matches/0x001a2900.cpp
// sym: ?Set@Obj_1a2900@fn_fc5dbd2a@@QAEDE@Z
char Obj_1a2900::Set(unsigned char v) {
    value = v;
    return 1;
}


// 0x001a2940 FUN_001a2940 (15 B): matches/0x001a2940.cpp
// sym: ?Set@Obj_1a2940@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a2940::Set(int x) {
    mVal = x;
    return 1;
}


// 0x001a2960 FUN_001a2960 (15 B): matches/0x001a2960.cpp
// sym: ?Fn@Obj_1a2960@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2960::Fn(char v) {
    value = v;
    return 1;
}


// 0x001a2970 FUN_001a2970 (7 B): matches/0x001a2970.cpp
// sym: ?Get@Obj_1a2970@fn_fc5dbd2a@@QAEEXZ
unsigned char Obj_1a2970::Get() {
    return pad[0x119];
}


// 0x001a2980 FUN_001a2980 (15 B): matches/0x001a2980.cpp
// sym: ?Set@X_1a2980@fn_fc5dbd2a@@QAEEE@Z
unsigned char X_1a2980::Set(unsigned char v) {
    m = v;
    return 1;
}


// 0x001a29c0 FUN_001a29c0 (15 B): matches/0x001a29c0.cpp
// sym: ?Set@Obj_1a29c0@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a29c0::Set(int v) {
    mVal = v;
    return 1;
}


// 0x001a29e0 FUN_001a29e0 (15 B): matches/0x001a29e0.cpp
// sym: ?Fn@Obj_1a29e0@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a29e0::Fn(char c) {
    m.m128 = c;
    return 1;
}


// 0x001a2a00 FUN_001a2a00 (15 B): matches/0x001a2a00.cpp
// sym: ?Set@Obj_1a2a00@fn_fc5dbd2a@@QAEEE@Z
unsigned char Obj_1a2a00::Set(unsigned char v) {
    value = v;
    return 1;
}


// 0x001a2a30 FUN_001a2a30 (7 B): matches/0x001a2a30.cpp
// sym: ?Get@A_1a2a30@fn_fc5dbd2a@@QAEHXZ
int A_1a2a30::Get() {
    return value;
}


// 0x001a2a40 FUN_001a2a40 (15 B): matches/0x001a2a40.cpp
// sym: ?FUN_001a2a40@Obj_1a2a40@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a2a40::FUN_001a2a40(int x) {
    m134 = x;
    return 1;
}


// 0x001a2a60 FUN_001a2a60 (15 B): matches/0x001a2a60.cpp
// sym: ?Set@Obj_1a2a60@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2a60::Set(char v) {
    mVal = v;
    return 1;
}


// 0x001a2a80 FUN_001a2a80 (15 B): matches/0x001a2a80.cpp
// sym: ?F@Obj_1a2a80@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2a80::F(char value) {
    m[0x139] = value;
    return 1;
}


// 0x001a2ac0 FUN_001a2ac0 (15 B): matches/0x001a2ac0.cpp
// sym: ?Set@A_1a2ac0@fn_fc5dbd2a@@QAE_NH@Z
bool A_1a2ac0::Set(int x) {
    m = x;
    return true;
}


// 0x001a2ae0 FUN_001a2ae0 (15 B): matches/0x001a2ae0.cpp
// sym: ?f4@X_1a2ae0@fn_fc5dbd2a@@QAEDE@Z
char X_1a2ae0::f4(unsigned char v) {
    m148 = (char)v;
    return 1;
}


// 0x001a2b00 FUN_001a2b00 (15 B): matches/0x001a2b00.cpp
// sym: ?SetB@X_1a2b00@fn_fc5dbd2a@@QAEDE@Z
char X_1a2b00::SetB(unsigned char b) {
    m[0x149] = b;
    return 1;
}


// 0x001a2b30 FUN_001a2b30 (7 B): matches/0x001a2b30.cpp
// sym: ?Get@Obj_1a2b30@fn_fc5dbd2a@@QAEHXZ
int Obj_1a2b30::Get() {
    return value;
}


// 0x001a2b40 FUN_001a2b40 (15 B): matches/0x001a2b40.cpp
// sym: ?Set@Obj_1a2b40@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a2b40::Set(int v) {
    m154 = v;
    return 1;
}


// 0x001a2b60 FUN_001a2b60 (15 B): matches/0x001a2b60.cpp
// sym: ?Fn@Obj_1a2b60@fn_fc5dbd2a@@QAEEE@Z
unsigned char Obj_1a2b60::Fn(unsigned char x) {
    value = x;
    return 1;
}


// 0x001a2b80 FUN_001a2b80 (15 B): matches/0x001a2b80.cpp
// sym: ?Set@Obj_1a2b80@fn_fc5dbd2a@@QAEDE@Z
char Obj_1a2b80::Set(unsigned char value) {
    m159 = value;
    return 1;
}


// 0x001a2bc0 FUN_001a2bc0 (15 B): matches/0x001a2bc0.cpp
// sym: ?Set@Obj_1a2bc0@fn_fc5dbd2a@@QAEDH@Z
char Obj_1a2bc0::Set(int v) {
    *(int*)(m + 0x164) = v;
    return 1;
}


// 0x001a2be0 FUN_001a2be0 (15 B): matches/0x001a2be0.cpp
// sym: ?Set@Obj_1a2be0@fn_fc5dbd2a@@QAEDE@Z
char Obj_1a2be0::Set(unsigned char v) {
    m = v;
    return 1;
}


// 0x001a2c00 FUN_001a2c00 (15 B): matches/0x001a2c00.cpp
// sym: ?Set@C_1a2c00@fn_fc5dbd2a@@QAE_NE@Z
bool C_1a2c00::Set(unsigned char value) {
    mValue = value;
    return true;
}


// 0x001a2c40 FUN_001a2c40 (15 B): matches/0x001a2c40.cpp
// sym: ?Set@Obj_1a2c40@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2c40::Set(int v) {
    m174 = v;
    return true;
}


// 0x001a2c60 FUN_001a2c60 (15 B): matches/0x001a2c60.cpp
// sym: ?Set@O_1a2c60@fn_fc5dbd2a@@QAEDD@Z
char O_1a2c60::Set(char c) {
    m178 = c;
    return 1;
}


// 0x001a2c80 FUN_001a2c80 (15 B): matches/0x001a2c80.cpp
// sym: ?Set@O_1a2c80@fn_fc5dbd2a@@QAEDD@Z
char O_1a2c80::Set(char v) {
    m = v;
    return 1;
}


// 0x001a2cc0 FUN_001a2cc0 (15 B): matches/0x001a2cc0.cpp
// sym: ?Set@Obj_1a2cc0@fn_fc5dbd2a@@QAE_NH@Z
bool Obj_1a2cc0::Set(int v) {
    mValue = v;
    return true;
}

} // namespace fn_fc5dbd2a

// 0x001a2ce0 FUN_001a2ce0 (15 B): matches/0x001a2ce0.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_001a2ce0@@QAEDD@Z
namespace fn_001a2ce0 {
class Obj {
  public:
    char pad[0x188];
    char value;
    char Set(char x);
};
char Obj::Set(char x) {
    value = x;
    return 1;
}
} // namespace fn_001a2ce0

namespace fn_fc5dbd2a {

// 0x001a2d00 FUN_001a2d00 (15 B): matches/0x001a2d00.cpp
// sym: ?Target@Obj_1a2d00@fn_fc5dbd2a@@QAEDD@Z
char Obj_1a2d00::Target(char v) {
    m189 = v;
    return 1;
}


// 0x001a2d20 FUN_001a2d20 (7 B): matches/0x001a2d20.cpp
// sym: ?FUN_001a2d20@Obj_1a2d20@fn_fc5dbd2a@@QAEHXZ
int Obj_1a2d20::FUN_001a2d20() {
    return value;
}


// 0x001a2d40 FUN_001a2d40 (15 B): matches/0x001a2d40.cpp
// sym: ?Set@T_1a2d40@fn_fc5dbd2a@@QAE_NH@Z
bool T_1a2d40::Set(int x) {
    Value = x;
    return true;
}


// 0x001a2d50 FUN_001a2d50 (19 B): matches/0x001a2d50.cpp
// sym: ?FUN_001a2d50@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a2d50() {
    FUN_00234810(((char*)&DAT_004e1708), ((char*)&DAT_004e170c));
}

} // namespace fn_fc5dbd2a

// 0x001a2d70 hulkfight::scenario::NodeIsNotRunningCondition::vfunc_0 (16 B): matches/0x001a2d70.cpp
// sym: ?vfunc_0@NodeIsNotRunningCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::NodeIsNotRunningCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1708;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a2db0 FUN_001a2db0 (19 B): matches/0x001a2db0.cpp
// sym: ?FUN_001a2db0@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a2db0() {
    FUN_00234810(((char*)&DAT_004e1710), ((char*)&DAT_004e1714));
}

} // namespace fn_fc5dbd2a

// 0x001a2dd0 hulkfight::scenario::Event_StringCondition::vfunc_0 (16 B): matches/0x001a2dd0.cpp
// sym: ?vfunc_0@Event_StringCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_StringCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1710;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a2e00 FUN_001a2e00 (25 B): matches/0x001a2e00.cpp
// sym: ??1Event_StringCondition_1a2e00@fn_fc5dbd2a@@QAE@XZ
Event_StringCondition_1a2e00::~Event_StringCondition_1a2e00() throw() {
    vptr = hulk_at_0041c4f0;
    sub.Fin_0027af50();
}


// 0x001a2e20 FUN_001a2e20 (19 B): matches/0x001a2e20.cpp
// sym: ?FUN_001a2e20@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a2e20() {
    FUN_00234810(((char*)&DAT_004e1718), ((char*)&DAT_004e171c));
}

} // namespace fn_fc5dbd2a

// 0x001a2e40 hulkfight::scenario::NodeShouldRunImmediatelyCondition::vfunc_0 (16 B): matches/0x001a2e40.cpp
// sym: ?vfunc_0@NodeShouldRunImmediatelyCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::NodeShouldRunImmediatelyCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1718;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a2e80 FUN_001a2e80 (19 B): matches/0x001a2e80.cpp
// sym: ?FUN_001a2e80@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a2e80() {
    FUN_00234810(((char*)&DAT_004e1720), ((char*)&DAT_004e1724));
}

} // namespace fn_fc5dbd2a

// 0x001a2ea0 hulkfight::scenario::Event_LocomotionStateNamePreviousCondition::vfunc_0 (16 B): matches/0x001a2ea0.cpp
// sym: ?vfunc_0@Event_LocomotionStateNamePreviousCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_LocomotionStateNamePreviousCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1720;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a2ef0 FUN_001a2ef0 (19 B): matches/0x001a2ef0.cpp
// sym: ?FUN_001a2ef0@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a2ef0() {
    FUN_00234810(((char*)&DAT_004e1728), ((char*)&DAT_004e172c));
}

} // namespace fn_fc5dbd2a

// 0x001a2f10 hulkfight::scenario::Event_LocomotionStateNameCondition::vfunc_0 (16 B): matches/0x001a2f10.cpp
// sym: ?vfunc_0@Event_LocomotionStateNameCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_LocomotionStateNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1728;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a2f60 FUN_001a2f60 (19 B): matches/0x001a2f60.cpp
// sym: ?FUN_001a2f60@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a2f60() {
    FUN_00234810(((char*)&DAT_004e1730), ((char*)&DAT_004e1734));
}

} // namespace fn_fc5dbd2a

// 0x001a2f80 hulkfight::scenario::Event_PropStateDescCondition::vfunc_0 (16 B): matches/0x001a2f80.cpp
// sym: ?vfunc_0@Event_PropStateDescCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_PropStateDescCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1730;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a2fc0 FUN_001a2fc0 (19 B): matches/0x001a2fc0.cpp
// sym: ?FUN_001a2fc0@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a2fc0() {
    FUN_00234810(((char*)&DAT_004e1738), ((char*)&DAT_004e173c));
}

} // namespace fn_fc5dbd2a

// 0x001a2fe0 hulkfight::scenario::Event_PropTypeCondition::vfunc_0 (16 B): matches/0x001a2fe0.cpp
// sym: ?vfunc_0@Event_PropTypeCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_PropTypeCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1738;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a2ff0 FUN_001a2ff0 (28 B): matches/0x001a2ff0.cpp
// sym: ??0Event_PropTypeCondition@fn_fc5dbd2a@@QAE@XZ
Event_PropTypeCondition::Event_PropTypeCondition() : Condition_1a2ff0(0), part() {}


// 0x001a3010 FUN_001a3010 (25 B): matches/0x001a3010.cpp
// sym: ??1Event_PropTypeCondition_1a3010@fn_fc5dbd2a@@QAE@XZ
Event_PropTypeCondition_1a3010::~Event_PropTypeCondition_1a3010() {
    vptr = hulk_at_0041c590;
    s.Init_0027af50();
    Fin_002345b0();
}


// 0x001a3030 FUN_001a3030 (19 B): matches/0x001a3030.cpp
// sym: ?FUN_001a3030@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a3030() {
    FUN_00234810(((char*)&DAT_004e1740), ((char*)&DAT_004e1744));
}

} // namespace fn_fc5dbd2a

// 0x001a3050 hulkfight::scenario::Event_PropStateNameCondition::vfunc_0 (16 B): matches/0x001a3050.cpp
// sym: ?vfunc_0@Event_PropStateNameCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_PropStateNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1740;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a3080 FUN_001a3080 (25 B): matches/0x001a3080.cpp
// sym: ?f@Event_PropStateNameCondition_1a3080@fn_fc5dbd2a@@QAEXXZ
void Event_PropStateNameCondition_1a3080::f() {
    vptr = hulk_at_0041c5b0;
    sub.Fin_0027af50();
    Fin_002345b0();
}


// 0x001a30a0 FUN_001a30a0 (19 B): matches/0x001a30a0.cpp
// sym: ?FUN_001a30a0@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a30a0() {
    FUN_00234810(((char*)&DAT_004e1748), ((char*)&DAT_004e174c));
}

} // namespace fn_fc5dbd2a

// 0x001a30c0 hulkfight::scenario::Event_PropNameCondition::vfunc_0 (16 B): matches/0x001a30c0.cpp
// sym: ?vfunc_0@Event_PropNameCondition@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::Event_PropNameCondition::vfunc_0(int index) {
    int* p = hulk_at_004e1748;
    return p[index];
}

namespace fn_fc5dbd2a {

// 0x001a30f0 FUN_001a30f0 (25 B): matches/0x001a30f0.cpp
// sym: ??1Event_PropNameCondition_1a30f0@fn_fc5dbd2a@@QAE@XZ
Event_PropNameCondition_1a30f0::~Event_PropNameCondition_1a30f0() throw() {
    vptr = hulk_at_0041c5d0;
    sub.Fin_0027af50();
}


// 0x001a3110 FUN_001a3110 (19 B): matches/0x001a3110.cpp
// sym: ?FUN_001a3110@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a3110() {
    FUN_00234810(((char*)&DAT_004e1750), ((char*)&DAT_004e1754));
}

} // namespace fn_fc5dbd2a

// 0x001a3130 hulkfight::scenario::EffectTrack::vfunc_0 (16 B): matches/0x001a3130.cpp
// sym: ?vfunc_0@EffectTrack@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::EffectTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1750;
    return p[index];
}


// 0x001a3140 FUN_001a3140 (102 B): equivalent/0x001a3140.cpp [wrapped: conflict: hulkfight::scenario::EffectTrack]
// sym: ??0EffectTrack@scenario@hulkfight@fn_001a3140@@QAE@XZ @877df6a30e7e @w6c4de4ba41a6
namespace fn_001a3140 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001a3140 @ 0x001a3140
struct Sub8_1a3140 {
    unsigned int a, b;
    void FUN_0027af00();
};

class __declspec(novtable) Track_1a3140 {
public:
    virtual hulk_intptr b0_001a3130(int);
    int pad04;
    int pad08;
    void FUN_00236d40();
    Track_1a3140() { FUN_00236d40(); }
};

namespace hulkfight {
namespace scenario {
class EffectTrack : public Track_1a3140 {
public:
    virtual bool vfunc_0_00234270(void*);
    virtual bool v1_002342b0(int);
    virtual bool v2_00236c50(hulk_intptr, int, hulk_intptr);
    virtual bool v3_00234350(int, int);
    virtual void* v4_001a5c50(char);
    virtual void v5_001a31b0();
    virtual void vfunc_6_001a31c0();
    virtual void* vfunc_7_00236ba0(void*, void*);

    int f0c;
    float f10;
    int pad14;
    Sub8_1a3140 s18;
    Sub8_1a3140 s20;
    int f28;
    int pad2c;
    Sub8_1a3140 s30;
    int f38, f3c, f40, f44, f48, f4c, f50;
    int pad54;
    Sub8_1a3140 s58;
    float f60;

    EffectTrack();
};
}
}

hulkfight::scenario::EffectTrack::EffectTrack() {
    f0c = 0;
    f10 = -1.0f;
    s18.FUN_0027af00();
    s20.FUN_0027af00();
    f28 = 0;
    s30.FUN_0027af00();
    f38 = 0; f3c = 0; f40 = 0; f44 = 0; f48 = 0; f4c = 0;
    f50 = 0;
    s58.FUN_0027af00();
    f60 = 1.0f;
    pad08 = 1;
}
} // namespace fn_001a3140


// 0x001a31b0 hulkfight::scenario::EffectTrack::vfunc_6 (4 B): matches/0x001a31b0.cpp
// sym: ?vfunc_6@EffectTrack@scenario@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::scenario::EffectTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001a31c0 hulkfight::scenario::EffectTrack::vfunc_7 (7 B): matches/0x001a31c0.cpp
// sym: ?vfunc_7@EffectTrack@scenario@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::scenario::EffectTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x001a31d0 FUN_001a31d0 (49 B): matches/0x001a31d0.cpp [wrapped: conflict: hulkfight::scenario::EffectTrack]
// sym: ??1EffectTrack@scenario@hulkfight@fn_001a31d0@@UAE@XZ
namespace fn_001a31d0 {
struct Helper_1a31d0 {
    ~Helper_1a31d0() throw(); // FUN_0027af50
    int x;
};

struct Track_1a31d0 {
    virtual ~Track_1a31d0() throw(); // FUN_00236d60
};

namespace hulkfight {
namespace scenario {

struct EffectTrack : Track_1a31d0 {
    virtual ~EffectTrack();
    virtual bool Fnf_00234270(void*);
    char p4[0x18 - 4];
    Helper_1a31d0 h18;
    char p1c[0x20 - 0x1c];
    Helper_1a31d0 h20;
    char p24[0x30 - 0x24];
    Helper_1a31d0 h30;
    char p34[0x58 - 0x34];
    Helper_1a31d0 h58;
};

EffectTrack::~EffectTrack() {}

} // namespace scenario
} // namespace hulkfight
} // namespace fn_001a31d0

namespace fn_fc5dbd2a {

// 0x001a3210 FUN_001a3210 (19 B): matches/0x001a3210.cpp
// sym: ?FUN_001a3210@fn_fc5dbd2a@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_001a3210() {
    FUN_00234810(((char*)&DAT_004e1758), ((char*)&DAT_004e175c));
}

} // namespace fn_fc5dbd2a

// 0x001a3230 hulkfight::scenario::NISAnimationTrack::vfunc_0 (16 B): matches/0x001a3230.cpp
// sym: ?vfunc_0@NISAnimationTrack@scenario@hulkfight@@UAEHH@Z
// Same code shape as 0x00048300 (propagated; names are from that function)
hulk_intptr hulkfight::scenario::NISAnimationTrack::vfunc_0(int index) {
    int* p = hulk_at_004e1758;
    return p[index];
}


// 0x001a3240 FUN_001a3240 (655 B): equivalent/0x001a3240.cpp [wrapped: conflict: hulkfight::scenario::NISAnimationTrack]
// sym: ??0NISAnimationTrack@scenario@hulkfight@fn_001a3240@@QAE@XZ @249e660236ca @wc3e8d41b84ee
namespace fn_001a3240 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_001a3240 @ 0x001a3240
namespace hulkfight { namespace scenario {

struct Slot_1a3240 {
    int a;
    int b;
    int c;
    char d;
    char e;
    char pad[2];
};

// equiv-map: ??0Base@scenario@hulkfight@@QAE@XZ = 0x00236d40
class Base {
public:
    Base();
    virtual void vfunc_0();
    int f4;
    int f8;
};

class NISAnimationTrack : public Base {
public:
    NISAnimationTrack();
    virtual void vfunc_0();
    int fc;
    float f10;
    float f14;
    int f18;
    int f1c;
    float f20;
    int f24;
    int f28;
    int f2c;
    char f30;
    char pad31[3];
    int f34[7];
    char f50;
    char f51;
    char f52;
    char pad53;
    int f54;
    char f58;
    char f59;
    char pad5a[2];
    Slot_1a3240 slots[19];     // 0x5c
    int f18c;
    int f190;
    int f194;
};

NISAnimationTrack::NISAnimationTrack() {
    f10 = -1.0f;
    f20 = -1.0f;
    f14 = 1.0f;
    fc = 0; f18 = 0; f1c = 0; f24 = 0; f28 = 0; f2c = 0;
    f30 = 1;
    for (int i = 0; i < 7; i++) f34[i] = 0;
    f50 = 0; f51 = 0; f52 = 1;
    f54 = 0; f58 = 0; f59 = 1;
    for (int i = 0; i < 19; i++) {
        slots[i].a = 0; slots[i].b = 0; slots[i].c = 0;
        slots[i].d = 0; slots[i].e = 1;
    }
    f18c = 0; f190 = 0; f194 = 0;
}
}}
} // namespace fn_001a3240


// 0x001a34d0 hulkfight::scenario::NISAnimationTrack::vfunc_6 (4 B): matches/0x001a34d0.cpp
// sym: ?vfunc_6@NISAnimationTrack@scenario@hulkfight@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg hulkfight::scenario::NISAnimationTrack::vfunc_6() {
    return this->f_0c;
}


// 0x001a34e0 hulkfight::scenario::NISAnimationTrack::vfunc_7 (7 B): matches/0x001a34e0.cpp
// sym: ?vfunc_7@NISAnimationTrack@scenario@hulkfight@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg hulkfight::scenario::NISAnimationTrack::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x001a34f0 FUN_001a34f0 (509 B): matches/0x001a34f0.cpp [wrapped: conflict: FUN_0008d340]
// sym: ??1NISAnimationTrack_1a34f0@fn_001a34f0@@QAE@XZ
namespace fn_001a34f0 {
extern void* DAT_0041c620[];
void FUN_0008d340(void*) throw();
class Track_1a34f0 {
  public:
    void* vptr;
    void Fin_00236d60();
};
class NISAnimationTrack_1a34f0 : public Track_1a34f0 {
  public:
    char p24[32];
    void* m24;
    char p4c[36];
    void* m4c;
    char p5c[12];
    void* m5c;
    void* m60;
    char p6c[8];
    void* m6c;
    void* m70;
    char p7c[8];
    void* m7c;
    void* m80;
    char p8c[8];
    void* m8c;
    void* m90;
    char p9c[8];
    void* m9c;
    void* ma0;
    char pac[8];
    void* mac;
    void* mb0;
    char pbc[8];
    void* mbc;
    void* mc0;
    char pcc[8];
    void* mcc;
    void* md0;
    char pdc[8];
    void* mdc;
    void* me0;
    char pec[8];
    void* mec;
    void* mf0;
    char pfc[8];
    void* mfc;
    void* m100;
    char p10c[8];
    void* m10c;
    void* m110;
    char p11c[8];
    void* m11c;
    void* m120;
    char p12c[8];
    void* m12c;
    void* m130;
    char p13c[8];
    void* m13c;
    void* m140;
    char p14c[8];
    void* m14c;
    void* m150;
    char p15c[8];
    void* m15c;
    void* m160;
    char p16c[8];
    void* m16c;
    void* m170;
    char p17c[8];
    void* m17c;
    void* m180;
    char p18c[8];
    void* m18c;
    void* m190;
    ~NISAnimationTrack_1a34f0() throw();
};
NISAnimationTrack_1a34f0::~NISAnimationTrack_1a34f0() throw() {
    vptr = DAT_0041c620;
    FUN_0008d340(m24);
    FUN_0008d340(m4c);
    FUN_0008d340(m5c);
    FUN_0008d340(m60);
    FUN_0008d340(m6c);
    FUN_0008d340(m70);
    FUN_0008d340(m7c);
    FUN_0008d340(m80);
    FUN_0008d340(m8c);
    FUN_0008d340(m90);
    FUN_0008d340(m9c);
    FUN_0008d340(ma0);
    FUN_0008d340(mac);
    FUN_0008d340(mb0);
    FUN_0008d340(mbc);
    FUN_0008d340(mc0);
    FUN_0008d340(mcc);
    FUN_0008d340(md0);
    FUN_0008d340(mdc);
    FUN_0008d340(me0);
    FUN_0008d340(mec);
    FUN_0008d340(mf0);
    FUN_0008d340(mfc);
    FUN_0008d340(m100);
    FUN_0008d340(m10c);
    FUN_0008d340(m110);
    FUN_0008d340(m11c);
    FUN_0008d340(m120);
    FUN_0008d340(m12c);
    FUN_0008d340(m130);
    FUN_0008d340(m13c);
    FUN_0008d340(m140);
    FUN_0008d340(m14c);
    FUN_0008d340(m150);
    FUN_0008d340(m15c);
    FUN_0008d340(m160);
    FUN_0008d340(m16c);
    FUN_0008d340(m170);
    FUN_0008d340(m17c);
    FUN_0008d340(m180);
    FUN_0008d340(m18c);
    FUN_0008d340(m190);
    Fin_00236d60();
}
} // namespace fn_001a34f0

namespace fn_fc5dbd2a {

// 0x001a36f0 FUN_001a36f0 (82 B): equivalent/0x001a36f0.cpp
// sym: ?FUN_001a36f0@Object@fn_fc5dbd2a@@QAEEPBD@Z @730fdd4c8c33 @w964984f6113e
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a36f0 @ 0x001a36f0
unsigned char Object::FUN_001a36f0(const char *value) { FUN_0008d340(text); if (!value) { text = 0; return 1; } unsigned int length = 0; while (value[length]) ++length; char *copy = (char *)FUN_0008d6d0(length + 1); text = copy; do { *copy++ = *value; } while (*value++); return 1; }


// 0x001a3750 FUN_001a3750 (82 B): equivalent/0x001a3750.cpp
// sym: ?FUN_001a3750@Item@fn_fc5dbd2a@@QAEHPBD@Z @55d4d8a923e2 @w9862036b34fa
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3750 @ 0x001a3750
hulk_intptr Item::FUN_001a3750(const char* value) { int result = FUN_0008d340(text); if (!value) { text = 0; return (result & ~255) | 1; } unsigned int length = 0; while (value[length]) ++length; char* allocated = (char*)FUN_0008d6d0(length + 1); text = allocated; char* dest = allocated; do { char c = *value++; *dest++ = c; } while (dest[-1]); return ((hulk_intptr)allocated & ~255) | 1; }


// 0x001a37b0 FUN_001a37b0 (82 B): equivalent/0x001a37b0.cpp
// sym: ?FUN_001a37b0@Object@fn_fc5dbd2a@@QAEHPBD@Z @60a4f059bfa7 @w6d0f2950bc79
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a37b0 @ 0x001a37b0
hulk_intptr Object::FUN_001a37b0(const char* text) { int result = FUN_0008d340(name); if (!text) { name = 0; return (result & ~255) | 1; } unsigned int size = 0; do { ++size; } while (text[size-1]); char* allocated = (char*)FUN_0008d6d0(size); name = allocated; char* dest = allocated; do { *dest++ = *text; } while (*text++); return ((hulk_intptr)allocated & ~255) | 1; }

} // namespace fn_fc5dbd2a

// 0x001a3810 FUN_001a3810 (82 B): equivalent/0x001a3810.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a3810@Object@fn_001a3810@@QAEEPBD@Z @85c07aa1b87d @w7a6fce08f99c
namespace fn_001a3810 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3810 @ 0x001a3810
extern "C++" __declspec(nothrow) void __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char pad[0x60]; char *text; unsigned char FUN_001a3810(const char *source); };
unsigned char Object::FUN_001a3810(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return 1; }
    unsigned int size = 0;
    while (source[size]) ++size;
    text = (char *)FUN_0008d6d0(size + 1);
    char *destination = text;
    do { *destination++ = *source; } while (*source++);
    return 1;
}
} // namespace fn_001a3810


// 0x001a3870 FUN_001a3870 (82 B): equivalent/0x001a3870.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a3870@Object@fn_001a3870@@QAEEPBD@Z @61c7d17f6111 @wc5fc0ae62399
namespace fn_001a3870 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3870 @ 0x001a3870
extern "C++" __declspec(nothrow) void __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char padding[0x6c]; char *text; unsigned char FUN_001a3870(const char *source); };
unsigned char Object::FUN_001a3870(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return 1; }
    const char *end = source;
    while (*end) ++end;
    char *result = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = result;
    do { *result++ = *source; } while (*source++);
    return 1;
}
} // namespace fn_001a3870


// 0x001a38d0 FUN_001a38d0 (82 B): matches/0x001a38d0.cpp [wrapped: conflict: FUN_0008d340]
// sym: ?set@Obj@fn_001a38d0@@QAEDPBD@Z
namespace fn_001a38d0 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned __cdecl strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif

void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
class Obj {
    char pad[0x70];
    char* text;

  public:
    char set(const char* s);
};
char Obj::set(const char* s) {
    FUN_0008d340(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}
} // namespace fn_001a38d0


// 0x001a3930 FUN_001a3930 (82 B): matches/0x001a3930.cpp [wrapped: conflict: Obj]
// sym: ?Set@Obj@fn_001a3930@@QAEDPBD@Z
namespace fn_001a3930 {
extern "C++" __declspec(nothrow) void release_0008d340(void*);
extern "C++" __declspec(nothrow) void* alloc_0008d6d0(hulk_uintptr);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strcpy(char*, const char*);
#endif

class Obj {
    char pad[0x7c];
    char* text;

  public:
    char Set(const char* s);
};
char Obj::Set(const char* s) {
    release_0008d340(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)alloc_0008d6d0(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}
} // namespace fn_001a3930

namespace fn_fc5dbd2a {

// 0x001a3990 FUN_001a3990 (97 B): matches/0x001a3990.cpp
// sym: ?SetName@Obj_1a3990@fn_fc5dbd2a@@QAE_NPBD@Z
bool Obj_1a3990::SetName(const char* s)
{
    thunk_FUN_00267090(name);
    if (s == 0) {
        name = 0;
        return true;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return true;
}

} // namespace fn_fc5dbd2a

// 0x001a3a00 FUN_001a3a00 (97 B): equivalent/0x001a3a00.cpp [wrapped: conflict: FUN_0008d340; Item]
// sym: ?FUN_001a3a00@Item@fn_001a3a00@@QAEIPBD@Z @f3c74008bc96 @w0b615932c400
namespace fn_001a3a00 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3a00 @ 0x001a3a00
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void *__cdecl FUN_0008d6d0(unsigned int);
struct Item {
    char padding[0x8c];
    char *text;
    unsigned int FUN_001a3a00(const char *source);
};
unsigned int Item::FUN_001a3a00(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & ~255u) | 1;
    }
    unsigned int length = 0;
    while (source[length]) ++length;
    char *allocated = (char *)FUN_0008d6d0(length + 1);
    text = allocated;
    char *dest = allocated;
    do {
        *dest++ = *source;
    } while (*source++);
    return ((hulk_uintptr)allocated & ~255u) | 1;
}
} // namespace fn_001a3a00

namespace fn_fc5dbd2a {

// 0x001a3a70 FUN_001a3a70 (97 B): matches/0x001a3a70.cpp
// sym: ?Set@Obj_1a3a70@fn_fc5dbd2a@@QAEDPBD@Z
char Obj_1a3a70::Set(const char* s) {
    release(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = allocate(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}

} // namespace fn_fc5dbd2a

// 0x001a3ae0 FUN_001a3ae0 (97 B): equivalent/0x001a3ae0.cpp [wrapped: conflict: FUN_0008d340; Object]
// sym: ?FUN_001a3ae0@Object@fn_001a3ae0@@QAEHPBD@Z @7c5bad41b05a @w3f96d9b3db47
namespace fn_001a3ae0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3ae0 @ 0x001a3ae0
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char pad[0x9c];
    char *text;
    int FUN_001a3ae0(const char *source);
};
int Object::FUN_001a3ae0(const char *source) {
    void *freeResult = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return ((hulk_uintptr)freeResult & ~255u) | 1;
    }
    const char *end = source;
    while (*end) ++end;
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = allocated;
    char *destination = allocated;
    do {
        *destination++ = *source;
    } while (*source++);
    return ((hulk_uintptr)allocated & ~255u) | 1;
}
} // namespace fn_001a3ae0

namespace fn_fc5dbd2a {

// 0x001a3b50 FUN_001a3b50 (97 B): matches/0x001a3b50.cpp
// sym: ?SetName@Obj_001a3b50@fn_fc5dbd2a@@QAE_NPBD@Z
bool Obj_001a3b50::SetName(const char* s)
{
    thunk_FUN_00267090(name);
    if (s == 0) {
        name = 0;
        return true;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return true;
}


// 0x001a3bc0 FUN_001a3bc0 (97 B): matches/0x001a3bc0.cpp
// sym: ?Set@Obj_1a3bc0@fn_fc5dbd2a@@QAEDPBD@Z
char Obj_1a3bc0::Set(const char* p) {
    Free(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)Alloc(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}


// 0x001a3c30 FUN_001a3c30 (97 B): equivalent/0x001a3c30.cpp
// sym: ?FUN_001a3c30@Holder@fn_fc5dbd2a@@QAEHPBD@Z @e19beb52aaec @wbb0cb7ccfc6e
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3c30 @ 0x001a3c30
hulk_intptr Holder::FUN_001a3c30(const char *source) {
    int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & ~255) | 1;
    }
    const char *end = source;
    while (*end) ++end;
    char *dest = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = dest;
    char *out = dest;
    do { *out++ = *source; } while (*source++);
    return ((hulk_intptr)dest & ~255) | 1;
}

} // namespace fn_fc5dbd2a

// 0x001a3ca0 FUN_001a3ca0 (97 B): equivalent/0x001a3ca0.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a3ca0@Object@fn_001a3ca0@@QAEHPBD@Z @6bd264dd14d8 @w04ed672be95e
namespace fn_001a3ca0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3ca0 @ 0x001a3ca0
struct Object { char pad[0xbc]; char* text; hulk_intptr FUN_001a3ca0(const char* value); }; int __cdecl FUN_0008d340(void*); void* __cdecl FUN_0008d6d0(unsigned int); hulk_intptr Object::FUN_001a3ca0(const char* value) { int result = FUN_0008d340(text); if (!value) { text = 0; return (result & ~255) | 1; } unsigned int length = 0; while (value[length]) ++length; char* allocated = (char*)FUN_0008d6d0(length + 1); text = allocated; char* dest = allocated; do { *dest++ = *value; } while (*value++); return ((hulk_intptr)allocated & ~255) | 1; }
} // namespace fn_001a3ca0


// 0x001a3d10 FUN_001a3d10 (97 B): equivalent/0x001a3d10.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a3d10@Object@fn_001a3d10@@QAEHPBD@Z @10ede74febbc @w2579a12a6f2d
namespace fn_001a3d10 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3d10 @ 0x001a3d10
int __cdecl FUN_0008d340(void *p);
void * __cdecl FUN_0008d6d0(unsigned int size);
struct Object {
    char padding[0xc0];
    char *name;
    hulk_intptr FUN_001a3d10(const char *text);
};
hulk_intptr Object::FUN_001a3d10(const char *text) {
    int result = FUN_0008d340(name);
    if (!text) {
        name = 0;
        return (result & ~255) | 1;
    }
    const char *end = text;
    while (*end) ++end;
    char *copy = (char *)FUN_0008d6d0((unsigned int)(end - text + 1));
    name = copy;
    char *destination = copy;
    do {
        *destination++ = *text;
    } while (*text++);
    return ((hulk_intptr)copy & ~255) | 1;
}
} // namespace fn_001a3d10


// 0x001a3d80 FUN_001a3d80 (97 B): equivalent/0x001a3d80.cpp [wrapped: conflict: FUN_0008d340; Object]
// sym: ?FUN_001a3d80@Object@fn_001a3d80@@QAEEPBD@Z @b22c8bd6058c @w2ee0837dcdbe
namespace fn_001a3d80 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3d80 @ 0x001a3d80
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char pad[0xcc];
    char *text;
    unsigned char FUN_001a3d80(const char *value);
};
unsigned char Object::FUN_001a3d80(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return 1;
    }
    const char *end = value;
    while (*end) ++end;
    char *result = (char *)FUN_0008d6d0((unsigned int)(end - value + 1));
    text = result;
    do {
        *result++ = *value;
    } while (*value++);
    return 1;
}
} // namespace fn_001a3d80

namespace fn_fc5dbd2a {

// 0x001a3df0 FUN_001a3df0 (97 B): matches/0x001a3df0.cpp
// sym: ?SetText@Obj_1a3df0@fn_fc5dbd2a@@QAEDPBD@Z
char Obj_1a3df0::SetText(const char* s) {
    freeMem_0008d340(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)allocMem(strlen(s) + 1);
    copy(text, s);
    return 1;
}


// 0x001a3e60 FUN_001a3e60 (97 B): matches/0x001a3e60.cpp
// sym: ?Set@Obj_1a3e60@fn_fc5dbd2a@@QAEDPAD@Z
char Obj_1a3e60::Set(char* s) {
    thunk_FUN_00267090(str);
    if (!s) {
        str = s;
        return 1;
    }
    str = (char*)malloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}

} // namespace fn_fc5dbd2a

// 0x001a3ed0 FUN_001a3ed0 (97 B): equivalent/0x001a3ed0.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a3ed0@Object@fn_001a3ed0@@QAEIPBD@Z @0524740d241f @w5b684cecafd4
namespace fn_001a3ed0 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a3ed0 @ 0x001a3ed0
struct Object { char pad[0xe0]; char* text; unsigned int FUN_001a3ed0(const char* value); };
unsigned int __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(unsigned int);
unsigned int Object::FUN_001a3ed0(const char* value) {
    unsigned int freed = FUN_0008d340(text);
    if (!value) { text = 0; return (freed & ~255u) | 1; }
    const char* end = value;
    while (*end) ++end;
    char* result = (char*)FUN_0008d6d0((unsigned int)(end - value + 1));
    text = result;
    char* dest = result;
    do { *dest++ = *value; } while (*value++);
    return ((hulk_uintptr)result & ~255u) | 1;
}
} // namespace fn_001a3ed0

namespace fn_fc5dbd2a {

// 0x001a3f40 FUN_001a3f40 (97 B): matches/0x001a3f40.cpp
// sym: ?Set@Obj_1a3f40@fn_fc5dbd2a@@QAEEPBD@Z
unsigned char Obj_1a3f40::Set(const char* s) {
    Free(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)Alloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}

} // namespace fn_fc5dbd2a

// 0x001a3fb0 FUN_001a3fb0 (97 B): matches/0x001a3fb0.cpp [wrapped: conflict: FUN_0008d340]
// sym: ?Set@Obj_1a3fb0@fn_001a3fb0@@QAEDPAD@Z
namespace fn_001a3fb0 {
void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif

class Obj_1a3fb0 {
    char pad[0xf0];
    char* text;

  public:
    char Set(char* s);
};
char Obj_1a3fb0::Set(char* s) {
    FUN_0008d340(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}
} // namespace fn_001a3fb0

namespace fn_fc5dbd2a {

// 0x001a4020 FUN_001a4020 (97 B): matches/0x001a4020.cpp
// sym: ?set@Obj_1a4020@fn_fc5dbd2a@@QAE_NPBD@Z
bool Obj_1a4020::set(const char* s) {
    release(text);
    if (!s) {
        text = 0;
        return true;
    }
    text = (char*)alloc(strlen(s) + 1);
    strcpy(text, s);
    return true;
}

} // namespace fn_fc5dbd2a

// 0x001a4090 FUN_001a4090 (97 B): equivalent/0x001a4090.cpp [wrapped: conflict: FUN_0008d340; Holder]
// sym: ?FUN_001a4090@Holder@fn_001a4090@@QAEIPBD@Z @f9509b6bc8eb @wed5ff5b72cff
namespace fn_001a4090 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4090 @ 0x001a4090
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Holder { char pad[0x100]; char *text; unsigned int FUN_001a4090(const char *source); };
unsigned int Holder::FUN_001a4090(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) { text = 0; return (result & 0xffffff00u) | 1; }
    const char *end = source;
    while (*end) ++end;
    char *destination = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = destination;
    char *out = destination;
    do { *out++ = *source; } while (*source++);
    return ((hulk_uintptr)destination & 0xffffff00u) | 1;
}
} // namespace fn_001a4090


// 0x001a4100 FUN_001a4100 (97 B): equivalent/0x001a4100.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a4100@Object@fn_001a4100@@QAEIPBD@Z @654f5a1fc25b @w4dc0106e81bf
namespace fn_001a4100 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4100 @ 0x001a4100
extern "C" unsigned int __cdecl thunk_FUN_0008d340(void *); extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char padding[0x10c]; char *text; unsigned int FUN_001a4100(const char *source); };
unsigned int Object::FUN_001a4100(const char *source) {
    unsigned int result = thunk_FUN_0008d340(text);
    if (!source) { text = 0; return (result & 0xffffff00U) | 1; }
    const char *end = source;
    while (*end) ++end;
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - source + 1));
    text = allocated;
    char *destination = allocated;
    do { *destination++ = *source; } while (*source++);
    return (((hulk_uintptr)allocated) & 0xffffff00U) | 1;
}
} // namespace fn_001a4100


// 0x001a4170 FUN_001a4170 (97 B): equivalent/0x001a4170.cpp [wrapped: conflict: FUN_0008d340; Object]
// sym: ?FUN_001a4170@Object@fn_001a4170@@QAEIPBD@Z @c1d6ac7e0c99 @w99e879f020a9
namespace fn_001a4170 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4170 @ 0x001a4170
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char pad[0x110]; char *name; unsigned int FUN_001a4170(const char *text); };
unsigned int Object::FUN_001a4170(const char *text) {
    hulk_uintptr result = FUN_0008d340(name);
    if (!text) { name = 0; return (result & 0xffffff00u) | 1; }
    const char *end = text;
    while (*end) ++end;
    name = (char *)FUN_0008d6d0((unsigned int)(end - text + 1));
    result = (hulk_uintptr)name;
    char *out = name;
    do { *out++ = *text; } while (*text++);
    return (result & 0xffffff00u) | 1;
}
} // namespace fn_001a4170

namespace fn_fc5dbd2a {

// 0x001a41e0 FUN_001a41e0 (97 B): matches/0x001a41e0.cpp
// sym: ?Set@X_1a41e0@fn_fc5dbd2a@@QAEEPBD@Z
unsigned char X_1a41e0::Set(const char* s) {
    freeBuf_0008d340(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)allocBuf_0008d6d0(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}


// 0x001a4250 FUN_001a4250 (97 B): matches/0x001a4250.cpp
// sym: ?Set@Obj_1a4250@fn_fc5dbd2a@@QAEEPBD@Z
unsigned char Obj_1a4250::Set(const char* s) {
    release(str);
    if (!s) {
        str = 0;
        return 1;
    }
    str = (char*)alloc(strlen(s) + 1);
    strcpy(str, s);
    return 1;
}


// 0x001a42c0 FUN_001a42c0 (97 B): matches/0x001a42c0.cpp
// sym: ?Set@Obj_1a42c0@fn_fc5dbd2a@@QAEEPBD@Z
unsigned char Obj_1a42c0::Set(const char* s) {
    Free(str);
    if (!s) {
        str = 0;
        return 1;
    }
    char* dst = (char*)Alloc(strlen(s) + 1);
    str = dst;
    Copy(dst, s);
    return 1;
}


// 0x001a4330 FUN_001a4330 (97 B): matches/0x001a4330.cpp
// sym: ?SetName@Obj_001a4330@fn_fc5dbd2a@@QAE_NPBD@Z
bool Obj_001a4330::SetName(const char* s)
{
    thunk_FUN_00267090(name);
    if (s == 0) {
        name = 0;
        return true;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return true;
}


// 0x001a43a0 FUN_001a43a0 (97 B): matches/0x001a43a0.cpp
// sym: ?Set@Obj_1a43a0@fn_fc5dbd2a@@QAEEPAD@Z
unsigned char Obj_1a43a0::Set(char* s) {
    release(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)alloc(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}


// 0x001a4410 FUN_001a4410 (97 B): matches/0x001a4410.cpp
// sym: ?SetName@Obj_001a4410@fn_fc5dbd2a@@QAE_NPBD@Z
bool Obj_001a4410::SetName(const char* s)
{
    thunk_FUN_00267090(name);
    if (s == 0) {
        name = 0;
        return true;
    }
    name = (char*)FUN_0008d6d0(strlen(s) + 1);
    strcpy(name, s);
    return true;
}

} // namespace fn_fc5dbd2a

// 0x001a4480 FUN_001a4480 (97 B): equivalent/0x001a4480.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a4480@Object@fn_001a4480@@QAEIPBD@Z @cdeb237fe679 @we17533420416
namespace fn_001a4480 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4480 @ 0x001a4480
extern "C" unsigned int __cdecl thunk_FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char pad[0x14c]; char *name; unsigned int FUN_001a4480(const char *text); };
unsigned int Object::FUN_001a4480(const char *text) {
    unsigned int result = thunk_FUN_0008d340(name);
    if (!text) { name = 0; return (result & ~255u) | 1; }
    const char *end = text;
    while (*end) ++end;
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - text + 1));
    name = allocated;
    char *dest = allocated;
    do { *dest++ = *text; } while (*text++);
    return ((hulk_uintptr)allocated & ~255u) | 1;
}
} // namespace fn_001a4480

namespace fn_fc5dbd2a {

// 0x001a44f0 FUN_001a44f0 (97 B): matches/0x001a44f0.cpp
// sym: ?Set@Obj_1a44f0@fn_fc5dbd2a@@QAEEPBD@Z
unsigned char Obj_1a44f0::Set(const char* s) {
    release(text);
    if (!s) {
        text = 0;
        return 1;
    }
    text = (char*)alloc(strlen(s) + 1);
    strcpy(text, s);
    return 1;
}

} // namespace fn_fc5dbd2a

// 0x001a4560 FUN_001a4560 (97 B): matches/0x001a4560.cpp [wrapped: conflict: FUN_0008d6d0]
// sym: ?Set@Obj_1a4560@fn_001a4560@@QAE_NPAD@Z
namespace fn_001a4560 {
extern "C++" __declspec(nothrow) void __cdecl thunk_FUN_00267090(char*);
extern "C++" __declspec(nothrow) char* __cdecl FUN_0008d6d0(unsigned int);

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* strcpy(char*, const char*);
#endif

class Obj_1a4560 {
  public:
    char pad[0x15c];
    char* text;
    bool Set(char*);
};
bool Obj_1a4560::Set(char* s) {
    thunk_FUN_00267090(text);
    if (!s) {
        text = 0;
        return true;
    }
    text = FUN_0008d6d0(strlen(s) + 1);
    strcpy(text, s);
    return true;
}
} // namespace fn_001a4560

namespace fn_fc5dbd2a {

// 0x001a45d0 FUN_001a45d0 (97 B): matches/0x001a45d0.cpp
// sym: ?SetName@Obj_1a45d0@fn_fc5dbd2a@@QAEEPBD@Z
unsigned char Obj_1a45d0::SetName(const char* s) {
    FreeMem_0008d340(name);
    if (!s) {
        name = 0;
        return 1;
    }
    name = (char*)AllocMem(strlen(s) + 1);
    strcpy(name, s);
    return 1;
}

} // namespace fn_fc5dbd2a

// 0x001a4640 FUN_001a4640 (97 B): equivalent/0x001a4640.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a4640@Object@fn_001a4640@@QAEIPBD@Z @26dc2c456289 @w3b33cbe005c9
namespace fn_001a4640 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4640 @ 0x001a4640
extern unsigned int __cdecl FUN_0008d340(void *);
extern void *__cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char padding[0x16c];
    char *text;
    unsigned int FUN_001a4640(const char *source);
};
unsigned int Object::FUN_001a4640(const char *source) {
    unsigned int result = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (result & 0xffffff00) | 1;
    }
    const char *end = source;
    do { ++end; } while (end[-1]);
    char *allocated = (char *)FUN_0008d6d0((unsigned int)(end - source));
    text = allocated;
    char *dest = allocated;
    do { *dest++ = *source; } while (*source++);
    return (((hulk_uintptr)allocated) & 0xffffff00) | 1;
}
} // namespace fn_001a4640


// 0x001a46b0 FUN_001a46b0 (97 B): matches/0x001a46b0.cpp [wrapped: conflict: FUN_0008d340]
// sym: ?Set@Obj_1a46b0@fn_001a46b0@@QAEDPBD@Z
namespace fn_001a46b0 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char*);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char* __cdecl strcpy(char*, const char*);
#endif

void __cdecl FUN_0008d340(void*);
void* __cdecl FUN_0008d6d0(hulk_uintptr);
class Obj_1a46b0 {
    char pad[0x170];
    char* s;

  public:
    char Set(const char* p);
};
char Obj_1a46b0::Set(const char* p) {
    FUN_0008d340(s);
    if (!p) {
        s = 0;
        return 1;
    }
    s = (char*)FUN_0008d6d0(strlen(p) + 1);
    strcpy(s, p);
    return 1;
}
} // namespace fn_001a46b0


// 0x001a4720 FUN_001a4720 (97 B): equivalent/0x001a4720.cpp [wrapped: conflict: FUN_0008d340; Object]
// sym: ?FUN_001a4720@Object@fn_001a4720@@QAEEPBD@Z @9ff81637498b @w530225f658bc
namespace fn_001a4720 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4720 @ 0x001a4720
extern void __cdecl FUN_0008d340(void *);
extern void * __cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char padding[0x17c];
    char *text;
    unsigned char FUN_001a4720(const char *value);
};
unsigned char Object::FUN_001a4720(const char *value) {
    FUN_0008d340(text);
    if (!value) {
        text = 0;
        return 1;
    }
    const char *end = value;
    do { ++end; } while (end[-1]);
    text = (char *)FUN_0008d6d0((unsigned int)(end - value));
    char *destination = text;
    do { *destination++ = *value; } while (*value++);
    return 1;
}
} // namespace fn_001a4720


// 0x001a4790 FUN_001a4790 (97 B): equivalent/0x001a4790.cpp [wrapped: conflict: FUN_0008d340; Object]
// sym: ?FUN_001a4790@Object@fn_001a4790@@QAEHPBD@Z @2ba81f6bf06d @w9f34832d4ed4
namespace fn_001a4790 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4790 @ 0x001a4790
extern "C++" __declspec(nothrow) unsigned int __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void *__cdecl FUN_0008d6d0(unsigned int);
struct Object {
    char padding[0x180];
    char *text;
    int FUN_001a4790(const char *source);
};
int Object::FUN_001a4790(const char *source) {
    unsigned int freed = FUN_0008d340(text);
    if (!source) {
        text = 0;
        return (freed & 0xffffff00u) | 1;
    }
    unsigned int length = 0;
    while (source[length]) ++length;
    char *allocated = (char *)FUN_0008d6d0(length + 1);
    text = allocated;
    char *destination = allocated;
    do {
        *destination++ = *source;
    } while (*source++);
    return ((hulk_uintptr)allocated & 0xffffff00u) | 1;
}
} // namespace fn_001a4790


// 0x001a4800 FUN_001a4800 (97 B): equivalent/0x001a4800.cpp [wrapped: conflict: Object]
// sym: ?FUN_001a4800@Object@fn_001a4800@@QAEEPBD@Z @128c33dc03f3 @wd4c00f543ddc
namespace fn_001a4800 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4800 @ 0x001a4800
extern "C++" __declspec(nothrow) void __cdecl FUN_0008d340(void *);
extern "C++" __declspec(nothrow) void * __cdecl FUN_0008d6d0(unsigned int);
struct Object { char pad[0x18c]; char *text; unsigned char FUN_001a4800(const char *source); };
unsigned char Object::FUN_001a4800(const char *source) {
    FUN_0008d340(text);
    if (!source) { text = 0; return 1; }
    unsigned int length = 0;
    while (source[length]) ++length;
    text = (char *)FUN_0008d6d0(length + 1);
    char *dest = text;
    do { *dest++ = *source; } while (*source++);
    return 1;
}
} // namespace fn_001a4800


// 0x001a4870 FUN_001a4870 (97 B): equivalent/0x001a4870.cpp [wrapped: conflict: Obj]
// sym: ?FUN_001a4870@Obj@fn_001a4870@@QAEHPBD@Z @8dd70595b6cd @w11884c6c8fc6
namespace fn_001a4870 {
// STATUS: equivalent (tools/equiv.py level 3: 2988 inputs, branch coverage 6/6)
// FUN_001a4870 @ 0x001a4870
struct Obj { char pad[0x190]; char *text; hulk_intptr FUN_001a4870(const char *value); }; int __cdecl FUN_0008d340(void *); void * __cdecl FUN_0008d6d0(unsigned int); hulk_intptr Obj::FUN_001a4870(const char *value) { int result = FUN_0008d340(text); if (!value) { text = 0; return (result & ~255) | 1; } const char *p = value; while (*p) ++p; char *allocated = (char *)FUN_0008d6d0((unsigned int)(p - value + 1)); text = allocated; char *dst = allocated; do { *dst++ = *value; } while (*value++); return ((hulk_intptr)allocated & ~255) | 1; }
} // namespace fn_001a4870

namespace fn_fc5dbd2a {

// 0x001a4990 FUN_001a4990 (43 B): matches/0x001a4990.cpp
// sym: ?Run@Holder_1a4990@fn_fc5dbd2a@@QAEPAHXZ
int* Holder_1a4990::Run() {
    Obj_1a4990* first = (Obj_1a4990*)this;
    first->Call(1, 6, 2, 1);
    if (second)
        second->Call(1, 2, 1, 1);
    return (int*)((char*)this + 0x28);
}

} // namespace fn_fc5dbd2a

// 0x001a49c0 hulkfight::scenario::NodeIsNotRunningCondition::vfunc_6 (69 B): matches/0x001a49c0.cpp [wrapped: conflict: FUN_00344e74]
// sym: ?vfunc_6@NodeIsNotRunningCondition@fn_001a49c0@@UAE_NPAX00@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_001a49c0 {
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

typedef unsigned char u8;
struct NodeIsNotRunningCondition {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual bool vfunc_6(void*, void*, void*);
    char pad[8];
    u8 mValue;
};
extern int FUN_00344e74(void*, int, const void*, const void*, int);
struct Runner_1a49c0 {
    bool run_001cb930(int);
};
struct World {
    char pad[0x30];
    Runner_1a49c0* runner;
};
extern char DAT_0048e0ac;
extern char DAT_0048e090;
bool NodeIsNotRunningCondition::vfunc_6(void* arg, void*, void*) {
    bool result = false;
    int value = FUN_00344e74(arg, 0, &DAT_0048e090, &DAT_0048e0ac, 0);
    if (value)
        result = DAT_004dd700->runner->run_001cb930(value);
    return result != mValue;
}
} // namespace fn_001a49c0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001a4a10 hulkfight::scenario::NodeShouldRunImmediatelyCondition::vfunc_6 (24 B): matches/0x001a4a10.cpp
// sym: ?vfunc_6@NodeShouldRunImmediatelyCondition@scenario@hulkfight@@UAE_NPAX00@Z
 // namespace hulkfight
bool hulkfight::scenario::NodeShouldRunImmediatelyCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_uintptr a = (hulk_uintptr)__p0; hulk_uintptr b = (hulk_uintptr)__p1; hulk_uintptr c = (hulk_uintptr)__p2;

    hulk_at_004dd700->inner->run_001cb770(a);
    return true;
}


// 0x001a4a30 hulkfight::scenario::Event_PropNameCondition::vfunc_6 (117 B): equivalent/0x001a4a30.cpp [wrapped: conflict: CScenarioParams; fight::Params; hulkfight::scenario::Event_PropNameCondition]
// sym: ?vfunc_6@Event_PropNameCondition@scenario@hulkfight@fn_001a4a30@@UAE_NHPAVParams@fight@4@H@Z @ea5e8c064055 @w5a307ef17c05
namespace fn_001a4a30 {
// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 15/16, incomplete)
// hulkfight::scenario::Event_PropNameCondition::vfunc_6 @ 0x001a4a30
namespace fight {
class Params {
public:
    virtual void v0();
};
}

struct PropInfo_1a4a30 {
    char pad0[4];
    int type;
    char pad8[0x18 - 8];
    int nameLo;
    int nameHi;
};

class CScenarioParams : public fight::Params {
public:
    virtual void v1();
    PropInfo_1a4a30 *FUN_001d03c0();
};

namespace hulkfight {
namespace scenario {
class Event_PropNameCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0x10 - 4];
    int wantLo;
    int wantHi;
};
}
}

bool hulkfight::scenario::Event_PropNameCondition::vfunc_6(int a, fight::Params *params, int c)
{
    CScenarioParams *sp = dynamic_cast<CScenarioParams *>(params);
    if (sp == 0)
        return false;
    PropInfo_1a4a30 *info = sp->FUN_001d03c0();
    if (info->type < 0x12 || info->type > 0x17)
        return false;
    return info->nameLo == wantLo && info->nameHi == wantHi;
}
} // namespace fn_001a4a30


// 0x001a4ac0 hulkfight::scenario::Event_PropStateDescCondition::vfunc_6 (66 B): matches/0x001a4ac0.cpp
// sym: ?vfunc_6@Event_PropStateDescCondition@scenario@hulkfight@@UAE_NPAX00@Z
bool hulkfight::scenario::Event_PropStateDescCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr b = (hulk_intptr)__p1; hulk_intptr c = (hulk_intptr)__p2;

    Obj_1a4ac0* x = (Obj_1a4ac0*)FUN_00344e74(b, 0, (hulk_intptr)&hulk_at_00494b44, (hulk_intptr)&hulk_at_004c13d0, 0);
    if (!x)
        return false;
    Result_1a4ac0* r = x->get_001d03c0();
    if (r->type != 0x17)
        return false;
    if (r->state == this->f_0c)
        return true;
    return false;
}


// 0x001a4b10 hulkfight::scenario::Event_PropTypeCondition::vfunc_6 (117 B): equivalent/0x001a4b10.cpp [wrapped: conflict: CScenarioParams; fight::Params; hulkfight::scenario::Event_PropTypeCondition]
// sym: ?vfunc_6@Event_PropTypeCondition@scenario@hulkfight@fn_001a4b10@@UAE_NHPAVParams@fight@4@H@Z @f0dce03fb346 @w0c7fdef454bd
namespace fn_001a4b10 {
// STATUS: equivalent (tools/equiv.py level 3: 3040 inputs, branch coverage 15/16, incomplete)
// hulkfight::scenario::Event_PropTypeCondition::vfunc_6 @ 0x001a4b10
namespace fight {
class Params {
public:
    virtual void v0();
};
}

struct PropInfo_1a4b10 {
    char pad0[4];
    int type;
    char pad8[0x20 - 8];
    int typeLo;
    int typeHi;
};

class CScenarioParams : public fight::Params {
public:
    virtual void v1();
    PropInfo_1a4b10 *FUN_001d03c0();
};

namespace hulkfight {
namespace scenario {
class Event_PropTypeCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0x10 - 4];
    int wantLo;
    int wantHi;
};
}
}

bool hulkfight::scenario::Event_PropTypeCondition::vfunc_6(int a, fight::Params *params, int c)
{
    CScenarioParams *sp = dynamic_cast<CScenarioParams *>(params);
    if (sp == 0)
        return false;
    PropInfo_1a4b10 *info = sp->FUN_001d03c0();
    if (info->type < 0x12 || info->type > 0x17)
        return false;
    return info->typeLo == wantLo && info->typeHi == wantHi;
}
} // namespace fn_001a4b10

namespace fn_fc5dbd2a {

// 0x001a4bf0 hulkfight::scenario::Event_LocomotionStateNameCondition::vfunc_6 (95 B): equivalent/0x001a4bf0.cpp
// sym: ?vfunc_6@Event_LocomotionStateNameCondition@fn_fc5dbd2a@@QAEIHPAXH@Z @79a8ccc02d8d @w006c0d7f0125
// STATUS: equivalent (tools/equiv.py level 3: 3021 inputs, branch coverage 12/12)
// hulkfight::scenario::Event_LocomotionStateNameCondition::vfunc_6 @ 0x001a4bf0
unsigned int Event_LocomotionStateNameCondition::vfunc_6(int unused0, void* params, int unused2)
{
    ScenarioParams* scenario = (ScenarioParams*)FUN_00344e74(params, 0, &DAT_00494b44, &DAT_004c13d0, 0);
    if (!scenario) return 0;
    ScenarioEvent* event = scenario->FUN_001d03c0();
    if (event->kind != 15) return (hulk_uintptr)event & ~255u;
    if (comparison == 0) return event->stateName == name;
    if (comparison == 1) return event->stateName != name;
    return (comparison - 1) & ~255u;
}


// 0x001a4cb0 FUN_001a4cb0 (309 B): equivalent/0x001a4cb0.cpp
// sym: _FUN_001a4cb0 @92b4308398ef @wc88de0f6e1c7
// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 28/28)
// FUN_001a4cb0 @ 0x001a4cb0
extern "C" const char *FUN_001a4cb0(void *t, unsigned int idx)
{
    const char *s = 0;
    if (idx < 20)
        s = ((Table_1a4cb0 *)t)->entries[idx].name;
    if (s != 0 && strlen(s) < 2)
        s = 0;
    return s;
}


// 0x001a4e40 FUN_001a4e40 (306 B): equivalent/0x001a4e40.cpp
// sym: _FUN_001a4e40 @e9a7a65c93f6 @wa737f6e93655
// STATUS: equivalent (tools/equiv.py level 3: 20054 inputs, branch coverage 28/28)
// FUN_001a4e40 @ 0x001a4e40
extern "C" const char *FUN_001a4e40(Table_1a4e40 *table, unsigned int index)
{
    if (index > 0x13)
        return 0;
    const char *name = table->entries[index].name;
    if (name == 0)
        return 0;
    if (strlen_inline(name) < 2)
        return 0;
    return name;
}


// 0x001a4fd0 FUN_001a4fd0 (234 B): equivalent/0x001a4fd0.cpp
// sym: ?FUN_001a4fd0@fn_fc5dbd2a@@YAEPBUState_1a4fd0@1@I@Z @8ad7c872b473 @w9357ebec8701
// STATUS: equivalent (tools/equiv.py level 3: 3044 inputs, branch coverage 22/22)
// FUN_001a4fd0 @ 0x001a4fd0
unsigned char __cdecl FUN_001a4fd0(const State_1a4fd0* state, unsigned int index)
{
    if (index > 19) return 1;
    return state->entries[index].value;
}


// 0x001a5110 FUN_001a5110 (234 B): equivalent/0x001a5110.cpp
// sym: _FUN_001a5110 @6b952ba84f76 @w5344386680df
// STATUS: equivalent (tools/equiv.py level 3: 3044 inputs, branch coverage 22/22)
// FUN_001a5110 @ 0x001a5110
extern "C" unsigned char __cdecl FUN_001a5110(const State_1a5110* state, unsigned int index)
{
    if (index >= 20) return 1;
    return state->entries[index].value;
}


// 0x001a5290 FUN_001a5290 (135 B): matches/0x001a5290.cpp
// sym: ?FUN_001a5290@Loader_1a5290@fn_fc5dbd2a@@QAE_NXZ
// FUN_001a5290 @ 0x001a5290
bool Loader_1a5290::FUN_001a5290()
{
    if (checker) {
        const char *name = info->name;
        if (name && strcmp(name, "1aa_01_vr_helmet.p3d") == 0) {
            if (checker->v22())
                return true;
        }
        if (!checker->v22())
            return false;
    }
    for (int i = 0; i < 20; i++) {
        if (slots[i].used && slots[i].resource) {
            if (!slots[i].resource->FUN_00222a00(slots[i].arg))
                return false;
        }
    }
    if (ready && !ready->v7())
        return false;
    return true;
}


// 0x001a5340 FUN_001a5340 (262 B): equivalent/0x001a5340.cpp
// sym: ?FUN_001a5340@Object@fn_fc5dbd2a@@QAEII@Z @32d90f1f79d1 @w70851b994609
// STATUS: equivalent (tools/equiv.py level 3: 3042 inputs, branch coverage 22/22)
// FUN_001a5340 @ 0x001a5340
unsigned int Object::FUN_001a5340(unsigned int index) { if (index > 19) return 1; return data->entries[index].value; }


// 0x001a55d0 FUN_001a55d0 (298 B): matches/0x001a55d0.cpp
// sym: ?FUN_001a55d0@Object@fn_fc5dbd2a@@QAEXXZ
void Object::FUN_001a55d0() {
    if (!node)
        return;
    Vec3_1a55d0 pivot;
    float offset;
    FUN_001a54a0(&pivot, &offset);
    float angle = settings->angle;
    Matrix transform;
    transform.FUN_0022b980();
    ((owners::Mat_22ba70 *)&transform)->FUN_0022ba70(angle + offset);
    ((owners::Target_22be40 *)&transform)->FUN_0022be40((const int *)(const Vec3_1a55d0 *)(&pivot));
    Node* target = (Node*)FUN_00344e74(node, 0, &DAT_0049e11c, &DAT_004a0a40, 0);
    Vec3_1a55d0 position = target->position;
    Vec3_1a55d0 direction = target->direction;
    Vec3_1a55d0 up = target->up;
    Vec3_1a55d0 newPosition, newDirection, newUp;
    ((owners::Mat_22c2b0 *)&transform)->FUN_0022c2b0((float *)(const Vec3_1a55d0 *)(&position), (float *)(Vec3_1a55d0 *)(&newPosition));
    ((owners::M_22c3b0 *)&transform)->FUN_0022c3b0((float *)(const Vec3_1a55d0 *)(&direction), (float *)(Vec3_1a55d0 *)(&newDirection));
    ((owners::M_22c3b0 *)&transform)->FUN_0022c3b0((float *)(const Vec3_1a55d0 *)(&up), (float *)(Vec3_1a55d0 *)(&newUp));
    ((owners::C_293af0 *)target)->FUN_00293af0((int *)(const Vec3_1a55d0 *)(&newPosition));
    ((owners::C_293a90 *)target)->FUN_00293a90((int *)(const Vec3_1a55d0 *)(&newDirection));
    target->FUN_00293ac0(&newUp);
}

} // namespace fn_fc5dbd2a

// 0x001a5700 FUN_001a5700 (73 B): matches/0x001a5700.cpp
// sym: ?FUN_001a5700@Item_1a5700@owners@@QAEXPAX@Z
void owners::Item_1a5700::FUN_001a5700(void* arg) {
    unsigned char* p = (unsigned char*)this + 0x34;
    for (int i = 0; i < 20; i++, p += 0x18) {
        if (*(p - 8) && *(Obj_1a5700**)p) {
            (*(Obj_1a5700**)p)->M1_00222f40(arg);
            (*(Obj_1a5700**)p)->M2_00223fa0();
            Other_1a5700* o = *(Other_1a5700**)(p + 4);
            if (o)
                o->Call_0003be00();
            (*(Obj_1a5700**)p)->M3_00223060();
        }
    }
}

namespace fn_fc5dbd2a {

// 0x001a5750 hulkfight::scenario::NISAnimationAction::vfunc_5 (114 B): matches/0x001a5750.cpp
// sym: ?vfunc_5@NISAnimationAction@fn_fc5dbd2a@@UAEDMM@Z
char NISAnimationAction::vfunc_5(float unused, float dt) {
    if (first && !first->Ready()) {
        first->Play(dt * 1000.0f, 1);
        F1_001a55d0();
    }
    if (second)
        second->Play(dt * 1000.0f, 1);
    F2_001a5700(dt);
    return !F3_001a5290();
}


// 0x001a57d0 FUN_001a57d0 (103 B): matches/0x001a57d0.cpp
// sym: ?Find@Obj_1a57d0@fn_fc5dbd2a@@QAEH_J@Z
int Obj_1a57d0::Find(__int64 k) {
    int i;
    for (i = 0; i < 20; i++) {
        Node* n = e[i].n0;
        if (n && n->k == k)
            return e[i].val;
    }
    for (i = 0; i < 20; i++) {
        Node* n = e[i].n1;
        if (n && n->k == k)
            return e[i].val;
    }
    return 0;
}

} // namespace fn_fc5dbd2a

// 0x001a5840 FUN_001a5840 (181 B): equivalent/0x001a5840.cpp
// sym: ?FUN_001a5840@EffectAction@scenario@hulkfight@@QAEXPAXII0@Z @d138e13fe834 @w4bc543de6abd
// STATUS: equivalent (tools/equiv.py level 3: 20011 inputs, branch coverage 8/8)
// FUN_001a5840 @ 0x001a5840
void hulkfight::scenario::EffectAction::FUN_001a5840(void* __p0, unsigned int a, unsigned int b, void* __p3) { Source_1a5840 * source = (Source_1a5840 *)__p0; Matrix_1a5840 * output = (Matrix_1a5840 *)__p3;

 if (!source) { output->FUN_0022b980(); return; }
 unsigned int index=0;
 if (a || b) { index=source->FUN_002843a0(a,b); if(index==0xffff) index=0; }
 Matrix_1a5840* selected=&source->matrices[index];
 for(int i=0;i<16;++i) output->data[i]=selected->data[i];
 if((*(Transform_1a5840 * *)&this->f_28)) {
 Matrix_1a5840 first;
 for(int j=0;j<16;++j) first.data[j]=selected->data[j];
 Matrix_1a5840* other=(*(Transform_1a5840 * *)&this->f_28)->slot17();
 Matrix_1a5840 second;
 for(int k=0;k<16;++k) second.data[k]=other->data[k];
 ((owners::Matrix_22ca90 *)output)->FUN_0022ca90((const owners::Matrix_22ca90 *)(const Matrix_1a5840 *)(&first), (const owners::Matrix_22ca90 *)(const Matrix_1a5840 *)(&second));
 }
}


// 0x001a5900 hulkfight::scenario::EffectAction::vfunc_5 (164 B): equivalent/0x001a5900.cpp [wrapped: conflict: hulkfight::scenario::EffectAction]
// sym: ?vfunc_5@EffectAction@scenario@hulkfight@fn_001a5900@@UAE_NHH@Z @772e487a8f8d @wc05cfffd0c2e
namespace fn_001a5900 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// hulkfight::scenario::EffectAction::vfunc_5 @ 0x001a5900
struct Mat_1a5900 {
    float m[16];
};

struct Xform_1a5900 {
    char data[0x10];
};

struct Holder;

class Anim_1a5900 {
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
    virtual void *v11();
};

struct Owner_1a5900 {
    Anim_1a5900 *FUN_002960d0();
};

struct Config_1a5900 {
    char pad0[0x50];
    int mode;               // 0x50
    char pad54[4];
    int arg58;              // 0x58
    int arg5c;              // 0x5c
};

struct Target_1a5900 {
    void FUN_0027ffc0(int handle, Mat_1a5900 *m);
};

struct MatOut {
    Mat_1a5900 data;
    void FUN_0022ca90(Xform_1a5900 *x, Mat_1a5900 *src);
};

Target_1a5900 *FUN_0027f250();

namespace hulkfight {
namespace scenario {
class EffectAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual bool vfunc_5(int a, int b);
    char pad04[0x1c - 4];
    Config_1a5900 *config;         // 0x1c
    char pad20[4];
    int handle;             // 0x24
    Owner_1a5900 *owner;           // 0x28
    Xform_1a5900 xform;            // 0x2c
    void FUN_001a5840(void *pos, int a, int b, Mat_1a5900 *out);
};
}
}

bool hulkfight::scenario::EffectAction::vfunc_5(int a, int b)
{
    if (owner == 0)
        return true;
    Target_1a5900 *target = FUN_0027f250();
    void *pos = owner->FUN_002960d0()->v11();
    struct Frame {
        MatOut first;
        MatOut second;
    } fr;
    switch (config->mode) {
    case 1:
        FUN_001a5840(pos, 0, 0, &fr.second.data);
        fr.first.FUN_0022ca90(&xform, &fr.second.data);
        target->FUN_0027ffc0(handle, &fr.first.data);
        break;
    case 2:
        FUN_001a5840(pos, config->arg58, config->arg5c, &fr.first.data);
        fr.second.FUN_0022ca90(&xform, &fr.first.data);
        target->FUN_0027ffc0(handle, &fr.second.data);
        break;
    }
    return true;
}
} // namespace fn_001a5900

namespace fn_fc5dbd2a {

// 0x001a5a30 FUN_001a5a30 (36 B): matches/0x001a5a30.cpp
// sym: ?Set@fn_fc5dbd2a@@YAXPAPAVRef@1@PAV21@@Z
void Set(Ref** slot, Ref* value) {
    if (value)
        value->AddRef();
    if (*slot)
        (*slot)->Release();
    *slot = value;
}


// 0x001a5aa0 hulkfight::scenario::NodeIsNotRunningCondition::vfunc_5 (36 B): matches/0x001a5aa0.cpp
// sym: ?vfunc_5@NodeIsNotRunningCondition_1a5aa0@fn_fc5dbd2a@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
NodeIsNotRunningCondition_1a5aa0* NodeIsNotRunningCondition_1a5aa0::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041c4d0;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001a5ad0 hulkfight::scenario::Event_StringCondition::vfunc_5 (46 B): matches/0x001a5ad0.cpp
// sym: ?vfunc_5@Event_StringCondition_1a5ad0@fn_fc5dbd2a@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
Event_StringCondition_1a5ad0* Event_StringCondition_1a5ad0::vfunc_5(unsigned char param) {
    Event_StringCondition_1a5ad0* p = this;
    *(char**)p = &threat_vftable_1a5ad0;
    ((Obj_1a5ad0*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_1a5ad0*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_1a5ad0*)p);
    return p;
}


// 0x001a5b00 hulkfight::scenario::NodeShouldRunImmediatelyCondition::vfunc_5 (36 B): matches/0x001a5b00.cpp
// sym: ?vfunc_5@NodeShouldRunImmediatelyCondition_1a5b00@fn_fc5dbd2a@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
NodeShouldRunImmediatelyCondition_1a5b00* NodeShouldRunImmediatelyCondition_1a5b00::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041c510;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001a5b30 hulkfight::scenario::Event_LocomotionStateNamePreviousCondition::vfunc_5 (36 B): matches/0x001a5b30.cpp
// sym: ?vfunc_5@Event_LocomotionStateNamePreviousCondition_1a5b30@fn_fc5dbd2a@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Event_LocomotionStateNamePreviousCondition_1a5b30* Event_LocomotionStateNamePreviousCondition_1a5b30::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041c530;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001a5b60 hulkfight::scenario::Event_LocomotionStateNameCondition::vfunc_5 (36 B): matches/0x001a5b60.cpp
// sym: ?vfunc_5@Event_LocomotionStateNameCondition_1a5b60@fn_fc5dbd2a@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Event_LocomotionStateNameCondition_1a5b60* Event_LocomotionStateNameCondition_1a5b60::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041c550;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001a5b90 hulkfight::scenario::Event_PropStateDescCondition::vfunc_5 (36 B): matches/0x001a5b90.cpp
// sym: ?vfunc_5@Event_PropStateDescCondition_1a5b90@fn_fc5dbd2a@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
Event_PropStateDescCondition_1a5b90* Event_PropStateDescCondition_1a5b90::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0041c570;
    Destroy_002345b0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}


// 0x001a5bc0 hulkfight::scenario::Event_PropTypeCondition::vfunc_5 (46 B): matches/0x001a5bc0.cpp
// sym: ?vfunc_5@Event_PropTypeCondition_1a5bc0@fn_fc5dbd2a@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
Event_PropTypeCondition_1a5bc0* Event_PropTypeCondition_1a5bc0::vfunc_5(unsigned char param) {
    Event_PropTypeCondition_1a5bc0* p = this;
    *(char**)p = &threat_vftable_1a5bc0;
    ((Obj_1a5bc0*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_1a5bc0*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_1a5bc0*)p);
    return p;
}


// 0x001a5bf0 hulkfight::scenario::Event_PropStateNameCondition::vfunc_5 (46 B): matches/0x001a5bf0.cpp
// sym: ?vfunc_5@Event_PropStateNameCondition_1a5bf0@fn_fc5dbd2a@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
Event_PropStateNameCondition_1a5bf0* Event_PropStateNameCondition_1a5bf0::vfunc_5(unsigned char param) {
    Event_PropStateNameCondition_1a5bf0* p = this;
    *(char**)p = &threat_vftable_1a5bf0;
    ((Obj_1a5bf0*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_1a5bf0*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_1a5bf0*)p);
    return p;
}


// 0x001a5c20 hulkfight::scenario::Event_PropNameCondition::vfunc_5 (46 B): matches/0x001a5c20.cpp
// sym: ?vfunc_5@Event_PropNameCondition_1a5c20@fn_fc5dbd2a@@QAEPAV12@E@Z
// Same code shape as 0x0012bc00 (propagated; names are from that function)
Event_PropNameCondition_1a5c20* Event_PropNameCondition_1a5c20::vfunc_5(unsigned char param) {
    Event_PropNameCondition_1a5c20* p = this;
    *(char**)p = &threat_vftable_1a5c20;
    ((Obj_1a5c20*)((char*)p + 0x10))->f1_0027af50();
    ((Obj_1a5c20*)p)->f2_002345b0();
    if (param & 1)
        thunk_FUN_00267090((Obj_1a5c20*)p);
    return p;
}


// 0x001a5c50 hulkfight::scenario::EffectTrack::vfunc_5 (70 B): matches/0x001a5c50.cpp
// sym: ?vfunc_5@EffectTrack@fn_fc5dbd2a@@UAEPAV12@E@Z
EffectTrack* EffectTrack::vfunc_5(unsigned char flag) {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0041c5f0);
    ((Helper_1a5c50*)((char*)this + 0x58))->Init_0027af50();
    ((Helper_1a5c50*)((char*)this + 0x30))->Init_0027af50();
    ((Helper_1a5c50*)((char*)this + 0x20))->Init_0027af50();
    ((Helper_1a5c50*)((char*)this + 0x18))->Init_0027af50();
    ((TrackBase_1a5c50*)this)->InitTrack_00236d60();
    if (flag & 1)
        Destroy_0008d330(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001a5ca0 hulkfight::scenario::NISAnimationTrack::vfunc_5 (30 B): matches/0x001a5ca0.cpp
// sym: ??_GNISAnimationTrack@scenario@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::scenario::NISAnimationTrack::~NISAnimationTrack() {}


// 0x001a5cc0 hulkfight::scenario::Event_PropStateNameCondition::vfunc_6 (141 B): equivalent/0x001a5cc0.cpp [wrapped: conflict: CScenarioParams; World; fight::Params; hulkfight::scenario::Event_PropStateNameCondition]
// sym: ?vfunc_6@Event_PropStateNameCondition@scenario@hulkfight@fn_001a5cc0@@UAE_NHPAVParams@fight@4@H@Z @95502132de7e @wc557cf227981
namespace fn_001a5cc0 {
// STATUS: equivalent (tools/equiv.py level 3: 3024 inputs, branch coverage 12/12)
// hulkfight::scenario::Event_PropStateNameCondition::vfunc_6 @ 0x001a5cc0
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

namespace fight {
class Params {
public:
    virtual void v0();
};
}

struct PropInfo_1a5cc0 {
    char pad0[4];
    int type;
    char pad8[0x18 - 8];
    int nameLo;
    int nameHi;
};

class CScenarioParams : public fight::Params {
public:
    virtual void v1();
    PropInfo_1a5cc0 *FUN_001d03c0();
};

struct NameEntry_1a5cc0 {
    char pad0[8];
    int idLo;
    int idHi;
};

class NameList_1a5cc0 {
public:
    char pad0[0x1c];
    NameEntry_1a5cc0 **entries;
};

class NameTable_1a5cc0 {
public:
    NameList_1a5cc0 *FUN_001d4fc0();
};

class Prop_1a5cc0 {
public:
    char pad0[0x40];
    int stateIndex;
    char pad44[0xec - 0x44];
    NameTable_1a5cc0 *names;
};

class PropRegistry {
public:
    Prop_1a5cc0 *FUN_001dee40(int lo, int hi);
};

class World {
public:
    char pad0[0xc];
    PropRegistry *props;
};

namespace hulkfight {
namespace scenario {
class Event_PropStateNameCondition {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual bool vfunc_6(int a, fight::Params *params, int c);
    char pad04[0x10 - 4];
    int wantLo;
    int wantHi;
};
}
}

bool hulkfight::scenario::Event_PropStateNameCondition::vfunc_6(int a, fight::Params *params, int c)
{
    CScenarioParams *sp = dynamic_cast<CScenarioParams *>(params);
    if (sp == 0)
        return false;
    bool result = false;
    PropInfo_1a5cc0 *info = sp->FUN_001d03c0();
    if (info->type != 0x17)
        return false;
    Prop_1a5cc0 *prop = DAT_004dd700->props->FUN_001dee40(info->nameLo, info->nameHi);
    if (prop != 0) {
        int index = prop->stateIndex;
        if (index != -1) {
            NameEntry_1a5cc0 *entry = prop->names->FUN_001d4fc0()->entries[index];
            if (entry->idLo == wantLo && entry->idHi == wantHi) {
                result = true;
            }
        }
    }
    return result;
}
} // namespace fn_001a5cc0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001a5d50 FUN_001a5d50 (203 B): equivalent/0x001a5d50.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_001a5d50@Owner_1a5d50@fn_001a5d50@@QAEXXZ @466cebcc2ad7 @w939f0995efe4
namespace fn_001a5d50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 20/20)
// FUN_001a5d50 @ 0x001a5d50
struct Resource_1a5d50 {
 virtual void unused();
 virtual void release();
 void FUN_0003dd00(int);
 void FUN_00222b90(int);
 void FUN_00222970(Resource_1a5d50*, int);
 void FUN_00298f90(int);
};
struct Manager_1a5d50 {
 int FUN_00024230(Resource_1a5d50*);
 void FUN_0002a4b0(int,int);
};
struct Context { char pad[0x20]; Manager_1a5d50* manager; };

#define DAT_004dd700 (*(Context* *)&::DAT_004dd700)

struct Owner_1a5d50 {
 unsigned char active, attached, flag2, flag3;
 Resource_1a5d50 *first, *second, *third, *fourth, *fifth;
 void FUN_001a5d50();
};
void Owner_1a5d50::FUN_001a5d50() {
 if (!active) return;
 if (third) {
  third->FUN_0003dd00(0);
  int handle = DAT_004dd700->manager->FUN_00024230(third);
  if (third) { third->release(); third=0; }
  if (attached) {
   DAT_004dd700->manager->FUN_0002a4b0(handle,1);
   second->FUN_00222b90(1);
  }
 }
 if (flag3) fourth->FUN_00298f90(0);
 if (second) second->FUN_00222970(first,1);
 if (first) { first->release(); first=0; }
 if (second) { second->release(); second=0; }
 if (fourth) { fourth->release(); fourth=0; }
 if (fifth) { fifth->release(); fifth=0; }
 active=0; attached=0; flag2=0; flag3=0;
}
} // namespace fn_001a5d50
#undef DAT_004dd700

namespace fn_fc5dbd2a {

// 0x001a5e20 FUN_001a5e20 (43 B): matches/0x001a5e20.cpp
// sym: ?f@X_1a5e20@fn_fc5dbd2a@@QAEXXZ
void X_1a5e20::f() {
    if (p28) {
        p28->b();
        p28 = 0;
    }
    if (p24) {
        p24->b();
        p24 = 0;
    }
}

} // namespace fn_fc5dbd2a

// 0x001a5e50 FUN_001a5e50 (82 B): equivalent/0x001a5e50.cpp [wrapped: conflict: hulkfight::scenario::EffectAction]
// sym: ??0EffectAction@scenario@hulkfight@fn_001a5e50@@QAE@IPAURefObject@3@@Z @642ad4fe9a4d @w9961948d3e64
namespace fn_001a5e50 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001a5e50 @ 0x001a5e50
struct RefObject { virtual void FUN_00000000(); virtual void FUN_00000001(); };
struct Action_1a5e50 {
    virtual void FUN_00000002();
    void FUN_00232660();
};
struct Subobject { void FUN_0022b980(); };
namespace hulkfight { namespace scenario {
struct EffectAction : Action_1a5e50 {
    virtual void FUN_00000003();
    char pad[0x18];
    unsigned int value;
    RefObject *object;
    unsigned int field24;
    unsigned int field28;
    Subobject member;
    EffectAction(unsigned int v, RefObject *p);
};
EffectAction::EffectAction(unsigned int v, RefObject *p)
    : Action_1a5e50((FUN_00232660(), *static_cast<Action_1a5e50*>(this))) {
    value = 0;
    object = 0;
    field24 = 0;
    field28 = 0;
    value = v;
    if (p) p->FUN_00000000();
    if (object) object->FUN_00000001();
    object = p;
    member.FUN_0022b980();
}
} }
} // namespace fn_001a5e50

namespace fn_fc5dbd2a {

// 0x001a5eb0 FUN_001a5eb0 (69 B): matches/0x001a5eb0.cpp
// sym: ??1EffectAction_1a5eb0@fn_fc5dbd2a@@QAE@XZ
EffectAction_1a5eb0::~EffectAction_1a5eb0() {
    vptr = hulk_at_0041c668;
    _ReadWriteBarrier();
    if (m28) {
        m28->Release();
        m28 = 0;
    }
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(Action_1a5eb0 *)this)->FUN_002326a0();
}

} // namespace fn_fc5dbd2a

// 0x001a5f00 hulkfight::scenario::EffectAction::vfunc_3 (1188 B): equivalent/0x001a5f00.cpp [wrapped: conflict: FUN_0027f250; World; hulkfight::scenario::EffectAction]
// sym: ?vfunc_3@EffectAction@scenario@hulkfight@fn_001a5f00@@UAE_NHH@Z @97c3a94a1802 @w0bb6d4647c65
namespace fn_001a5f00 {
// STATUS: equivalent (tools/equiv.py level 3: 3045 inputs, branch coverage 40/41, incomplete)
// hulkfight::scenario::EffectAction::vfunc_3 @ 0x001a5f00
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
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);
#endif


struct V3_1a5f00 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const V3_1a5f00 *t);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
    void FUN_0022c120();
};

class RefObj_1a5f00 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Anim_1a5f00 : public RefObj_1a5f00 {
public:
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual Anim_1a5f00 *v11();
    Anim_1a5f00 *FUN_002960d0();
};

struct Ctrl_1a5f00 {
    char pad0[8];
    unsigned int keylo;
    unsigned int keyhi;
    char padc[0x120 - 0x10];
    Ctrl_1a5f00 *f120;
    char pad124[0x1a4c - 0x124];
    float f1a4c;
    bool FUN_00035160(Matrix *out);
};

struct List_1a5f00 {
    char pad0[0xc];
    int count;
    Ctrl_1a5f00 *FUN_00024190(int i);
};

struct World {
    char pad0[0x20];
    List_1a5f00 *list;
};

class Cfg_1a5f00 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual float v6();
    char pad04[0xc - 4 + 0x0];
    char padc[0x10 - 0x1c + 0x10];
    float f10;
    char pad14[4];
    unsigned int key18lo;
    unsigned int key18hi;
    char sub20[8];
    int mode1;
    char pad2c[4];
    unsigned int key30lo;
    unsigned int key30hi;
    V3_1a5f00 v38;
    V3_1a5f00 v44;
    int mode2;
    char pad54[4];
    int f58;
    int f5c;
    float f60;
};

struct Mgr_1a5f00 {
    void *FUN_00283a40(void *a, Matrix *m, float t, float f60);
    void *FUN_00283b10(void *a, Ctrl_1a5f00 *c, void *b, Matrix *m, float t, float f60);
    void *FUN_00283be0(void *a, Ctrl_1a5f00 *c, float t, float f60);
};

struct Registry_1a5f00 {
    Anim_1a5f00 *FUN_001a57d0(unsigned int lo, unsigned int hi);
};
Mgr_1a5f00 *FUN_0027f250();

namespace hulkfight {
namespace scenario {
class EffectAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Cfg_1a5f00 *cfg;
    char pad20[4];
    void *result;
    Anim_1a5f00 *anim;
    Matrix cache;
    void FUN_001a5840(Ctrl_1a5f00 *c, unsigned int lo, unsigned int hi, Matrix *out);
};

bool EffectAction::vfunc_3(int a, int b)
{
    union Word {
        Ctrl_1a5f00 *ctrl;
        float t;
        unsigned int u;
        float f;
    };
    struct Frame {
        Word w10;
        Word w14;
        Word w18;
        Word w1c;
        V3_1a5f00 tmp2;
        V3_1a5f00 tmp4;
        V3_1a5f00 tmp1;
        Matrix mb;
        Matrix mc;
        Matrix ma;
    } f;

    Cfg_1a5f00 *c0 = cfg;
    unsigned int lo = c0->key18lo;
    unsigned int hi = c0->key18hi;
    Ctrl_1a5f00 *esi = 0;
    f.w10.ctrl = 0;
    f.w14.u = lo;
    f.w18.u = hi;
    if ((lo | hi) != 0) {
        List_1a5f00 *list = DAT_004dd700->list;
        bool searched = true;
        if (list->count > 0) {
            int i = 0;
            do {
                Ctrl_1a5f00 *item = list->FUN_00024190(i);
                if (item != 0 && item->keylo == f.w14.u && item->keyhi == f.w18.u) {
                    esi = item->f120;
                    f.w10.ctrl = item;
                    if (esi != 0)
                        searched = false;
                    break;
                }
                i++;
            } while (i < list->count);
        }
        if (searched && (*(Registry_1a5f00**)&DAT_004e1760) != 0) {
            Anim_1a5f00 *an = (*(Registry_1a5f00**)&DAT_004e1760)->FUN_001a57d0(f.w14.u, f.w18.u);
            if (an != 0)
                an->AddRef();
            if (anim != 0)
                anim->Release();
            anim = an;
            if (an != 0)
                esi = (Ctrl_1a5f00 *)an->FUN_002960d0()->v11();
        }
    }

    Mgr_1a5f00 *mgr = FUN_0027f250();
    switch (cfg->mode1) {
    case 0: {
        f.ma.FUN_0022b980();
        V3_1a5f00 *t = (V3_1a5f00 *)&f.w14;
        *t = cfg->v38;
        f.ma.FUN_0022be40(t);
        f.ma.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        break;
    }
    case 1:
        f.mb.FUN_0022b980();
        f.tmp1 = cfg->v38;
        f.mb.FUN_0022be40(&f.tmp1);
        f.mb.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        FUN_001a5840(esi, 0, 0, &f.mc);
        f.ma.FUN_0022ca90(&f.mb, &f.mc);
        break;
    case 2:
        f.mb.FUN_0022b980();
        f.tmp2 = cfg->v38;
        f.mb.FUN_0022be40(&f.tmp2);
        f.mb.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        FUN_001a5840(esi, cfg->key30lo, cfg->key30hi, &f.mc);
        f.ma.FUN_0022ca90(&f.mb, &f.mc);
        break;
    case 4:
        f.mc.FUN_0022b980();
        f.tmp4 = cfg->v38;
        f.mc.FUN_0022be40(&f.tmp4);
        f.mc.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        if (f.w10.ctrl != 0) {
            f.mb.FUN_0022b980();
            f.w10.ctrl->FUN_00035160(&f.mb);
            f.mb.m[13] = f.w10.ctrl->f1a4c;
        } else {
            FUN_001a5840(esi, 0, 0, &f.mb);
        }
        f.ma.FUN_0022ca90(&f.mc, &f.mb);
        break;
    default:
        break;
    }

    Cfg_1a5f00 *c1 = cfg;
    f.w10.t = c1->f10;
    f.w10.t = f.w10.t - c1->v6();
    f.w14.f = cfg->f60;
    switch (cfg->mode2) {
    case 0:
        result = mgr->FUN_00283a40(&cfg->sub20, &f.ma, f.w10.t, f.w14.f);
        return true;
    case 1:
        FUN_001a5840(esi, 0, 0, &f.mc);
        f.mc.FUN_0022c120();
        f.mb.FUN_0022ca90(&f.ma, &f.mc);
        if (anim == 0) {
            result = mgr->FUN_00283b10(&cfg->sub20, esi, 0, &f.mb, f.w10.t, f.w14.f);
        } else {
            memcpy(&cache, &f.mb, sizeof(Matrix));
            result = mgr->FUN_00283a40(&cfg->sub20, &f.ma, f.w10.t, f.w14.f);
        }
        return true;
    case 2:
        FUN_001a5840(esi, cfg->f58, cfg->f5c, &f.mc);
        f.mc.FUN_0022c120();
        f.mb.FUN_0022ca90(&f.ma, &f.mc);
        if (anim == 0) {
            result = mgr->FUN_00283b10(&cfg->sub20, esi, &cfg->f58, &f.mb, f.w10.t, f.w14.f);
        } else {
            memcpy(&cache, &f.mb, sizeof(Matrix));
            result = mgr->FUN_00283a40(&cfg->sub20, &f.ma, f.w10.t, f.w14.f);
        }
        return true;
    case 3:
        result = mgr->FUN_00283be0(&cfg->sub20, esi, f.w10.t, f.w14.f);
        return true;
    }
    return true;
}
}
}
} // namespace fn_001a5f00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001a6420 fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_6 (26 B): matches/0x001a6420.cpp
// sym: ?vfunc_6@?$ParamBool@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::**)(int))&this->f_10))(b);
}


// 0x001a6440 fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_2 (11 B): matches/0x001a6440.cpp
// sym: ?vfunc_2@?$ParamBool@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a6470 fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_6 (26 B): matches/0x001a6470.cpp
// sym: ?vfunc_6@?$ParamBool@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>*)a)->*(*(bool (fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::**)(int))&this->f_10))(b);
}


// 0x001a6490 fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_2 (11 B): matches/0x001a6490.cpp
// sym: ?vfunc_2@?$ParamBool@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a64d0 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_7 (6 B): matches/0x001a64d0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001a64e0 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_6 (30 B): matches/0x001a64e0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1a64e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1a64e0*)&DAT_003f335c));
}


// 0x001a6500 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_8 (26 B): matches/0x001a6500.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::**)(int))&this->f_18))(b);
}


// 0x001a6520 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_2 (11 B): matches/0x001a6520.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001a6560 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_7 (6 B): matches/0x001a6560.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001a6570 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_6 (30 B): matches/0x001a6570.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1a6570 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1a6570*)&DAT_003f335c));
}


// 0x001a6590 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_8 (26 B): matches/0x001a6590.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::**)(int))&this->f_18))(b);
}


// 0x001a65b0 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_2 (11 B): matches/0x001a65b0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001a65f0 fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_7 (6 B): matches/0x001a65f0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001a6600 fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_6 (30 B): matches/0x001a6600.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1a6600 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1a6600*)&DAT_003f335c));
}


// 0x001a6620 fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_8 (26 B): matches/0x001a6620.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::**)(int))&this->f_18))(b);
}


// 0x001a6640 fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_2 (11 B): matches/0x001a6640.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001a6670 fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::vfunc_6 (26 B): matches/0x001a6670.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VEffectTrack@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::**)(int))&this->f_10))(b);
}


// 0x001a6690 fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::vfunc_2 (11 B): matches/0x001a6690.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VEffectTrack@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a66d0 fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_7 (6 B): matches/0x001a66d0.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001a66e0 fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_6 (30 B): matches/0x001a66e0.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1a66e0 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1a66e0*)&DAT_003f335c));
}


// 0x001a6700 fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_8 (26 B): matches/0x001a6700.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::**)(int))&this->f_18))(b);
}


// 0x001a6720 fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_2 (11 B): matches/0x001a6720.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001a6750 fight::ParamVector<hulkfight::scenario::EffectTrack>::vfunc_6 (26 B): matches/0x001a6750.cpp
// sym: ?vfunc_6@?$ParamVector@VEffectTrack@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::scenario::EffectTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamVector<hulkfight::scenario::EffectTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamVector<hulkfight::scenario::EffectTrack>*)a)->*(*(bool (fight::ParamVector<hulkfight::scenario::EffectTrack>::**)(int))&this->f_10))(b);
}


// 0x001a6770 fight::ParamVector<hulkfight::scenario::EffectTrack>::vfunc_2 (11 B): matches/0x001a6770.cpp
// sym: ?vfunc_2@?$ParamVector@VEffectTrack@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamVector<hulkfight::scenario::EffectTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a67a0 fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_6 (26 B): matches/0x001a67a0.cpp
// sym: ?vfunc_6@?$ParamFloatConstRange@VEffectTrack@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>*)a)->*(*(bool (fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x001a67c0 fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_2 (11 B): matches/0x001a67c0.cpp
// sym: ?vfunc_2@?$ParamFloatConstRange@VEffectTrack@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a67f0 fight::ParamString<hulkfight::scenario::NISAnimationTrack>::vfunc_6 (26 B): matches/0x001a67f0.cpp
// sym: ?vfunc_6@?$ParamString@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::scenario::NISAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamString<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamString<hulkfight::scenario::NISAnimationTrack>*)a)->*(*(bool (fight::ParamString<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x001a6810 fight::ParamString<hulkfight::scenario::NISAnimationTrack>::vfunc_2 (11 B): matches/0x001a6810.cpp
// sym: ?vfunc_2@?$ParamString@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamString<hulkfight::scenario::NISAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a6850 fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_7 (6 B): matches/0x001a6850.cpp
// sym: ?vfunc_7@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEHH@Z
// Same code shape as 0x0004e4a0 (propagated; names are from that function)
template <> int fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_7(int arg) {
    return this->f_14;
}


// 0x001a6860 fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_6 (30 B): matches/0x001a6860.cpp
// sym: ?vfunc_6@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXHH@Z
// Same code shape as 0x0004df50 (propagated; names are from that function)
// data: zeroCondition = DAT_003f335c
template <> void* fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_6(int , int index) {
    if (index >= 0 && index < this->f_14)
        return (void*)((*(CStageCondition_1a6860 ** *)&this->f_10)[index]);
    return (void*)(((CStageCondition_1a6860*)&DAT_003f335c));
}


// 0x001a6880 fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_8 (26 B): matches/0x001a6880.cpp
// sym: ?vfunc_8@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004df70 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_8(int a, int b) {
    if (!(*(bool (fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_18))
        return false;
    return (reinterpret_cast<fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>*>(a)->*(*(bool (fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_18))(b);
}


// 0x001a68a0 fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_2 (11 B): matches/0x001a68a0.cpp
// sym: ?vfunc_2@?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004df90 (propagated; names are from that function)
template <> bool fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_2() {
    return this->f_18 == 0;
}


// 0x001a68d0 fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::vfunc_6 (26 B): matches/0x001a68d0.cpp
// sym: ?vfunc_6@?$ParamBool@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamBool<hulkfight::scenario::NISAnimationTrack>*)a)->*(*(bool (fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x001a68f0 fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::vfunc_2 (11 B): matches/0x001a68f0.cpp
// sym: ?vfunc_2@?$ParamBool@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a6920 fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_6 (26 B): matches/0x001a6920.cpp
// sym: ?vfunc_6@?$ParamIntConstRange@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAE_NHH@Z
// Same code shape as 0x0004dfd0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_6(hulk_intptr a, int b) {
    if (!(*(bool (fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))
        return false;
    return (((fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>*)a)->*(*(bool (fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::**)(int))&this->f_10))(b);
}


// 0x001a6940 fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_2 (11 B): matches/0x001a6940.cpp
// sym: ?vfunc_2@?$ParamIntConstRange@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAE_NXZ
// Same code shape as 0x0004dff0 (propagated; names are from that function)
template <> bool fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_2() {
    return this->f_10 == 0;
}


// 0x001a69c0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_0 (36 B): matches/0x001a69c0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c1e58, 0) != 0;
}


// 0x001a69f0 fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_0 (30 B): matches/0x001a69f0.cpp
// sym: ??_G?$ParamBool@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::scenario::NodeIsNotRunningCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a69f0)
#endif


// 0x001a6a20 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_0 (36 B): matches/0x001a6a20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_StringCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_0(void* __p0) { const char * s = (const char *)__p0;

    return FUN_00344e74(s, 0, &DAT_00491ca8, &DAT_004c1f20, 0) != 0;
}


// 0x001a6a60 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_0 (36 B): matches/0x001a6a60.cpp [wrapped: conflict: DAT_00491ca8]
// sym: ?vfunc_0@ConditionFactoryCasterTemplate@fn_001a6a60@@UAE_NPAX@Z
namespace fn_001a6a60 {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, void*, void*, int);
class NodeShouldRunImmediatelyCondition {};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
extern void *DAT_00491ca8, *DAT_004c1ff0;
bool ConditionFactoryCasterTemplate::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c1ff0, 0) != 0;
}
} // namespace fn_001a6a60


// 0x001a6a90 fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_0 (30 B): matches/0x001a6a90.cpp
// sym: ??_G?$ParamBool@VNodeShouldRunImmediatelyCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::scenario::NodeShouldRunImmediatelyCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6a90)
#endif


// 0x001a6ac0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_0 (36 B): matches/0x001a6ac0.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate]
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@fn_001a6ac0@@@fight@fn_001a6ac0@@UAE_NPAX@Z
namespace fn_001a6ac0 {
extern int hulk_at_00491ca8, hulk_at_004c20d0;
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_LocomotionStateNamePreviousCondition;
}
} // namespace hulkfight
template <>
bool fight::ConditionFactoryCasterTemplate<
    hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_0(void* p) {
    return ((int)(hulk_uintptr)__RTDynamicCast(p, 0, &hulk_at_00491ca8, &hulk_at_004c20d0, 0)) != 0;
}
} // namespace fn_001a6ac0


// 0x001a6af0 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_0 (30 B): matches/0x001a6af0.cpp
// sym: ??_G?$ParamEnumConstList@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6af0)
#endif


// 0x001a6b20 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_0 (36 B): matches/0x001a6b20.cpp [wrapped: conflict: fight::ConditionFactoryCaster; fight::ConditionFactoryCasterTemplate; hulkfight::scenario::Event_LocomotionStateNameCondition]
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_LocomotionStateNameCondition@scenario@hulkfight@fn_001a6b20@@@fight@fn_001a6b20@@UAE_NPAX@Z
namespace fn_001a6b20 {
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, void*, void*, void*, void*);
namespace fight {
class ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class Event_LocomotionStateNameCondition {};
} // namespace scenario
} // namespace hulkfight
extern void* g1;
extern void* hulk_at_004c21b0;
template <>
bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_0(
    void* p) {
    return FUN_00344e74(p, 0, &g1, &hulk_at_004c21b0, 0) != 0;
}
} // namespace fn_001a6b20


// 0x001a6b50 fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_0 (30 B): matches/0x001a6b50.cpp
// sym: ??_G?$ParamEnumConstList@VEvent_LocomotionStateNameCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6b50)
#endif


// 0x001a6b80 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_0 (36 B): matches/0x001a6b80.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_PropStateDescCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c2280, 0) != 0;
}


// 0x001a6bb0 fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_0 (30 B): matches/0x001a6bb0.cpp
// sym: ??_G?$ParamEnumConstList@VEvent_PropStateDescCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::Event_PropStateDescCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6bb0)
#endif


// 0x001a6be0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_0 (36 B): matches/0x001a6be0.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_PropTypeCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c2350, 0) != 0;
}


// 0x001a6c20 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_0 (36 B): matches/0x001a6c20.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_PropStateNameCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
 // namespace hulkfight
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c2418, 0) != 0;
}


// 0x001a6c60 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropNameCondition>::vfunc_0 (36 B): matches/0x001a6c60.cpp
// sym: ?vfunc_0@?$ConditionFactoryCasterTemplate@VEvent_PropNameCondition@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropNameCondition>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_00491ca8, &DAT_004c24e8, 0) != 0;
}


// 0x001a6ca0 fight::TrackFactoryCasterTemplate<hulkfight::scenario::EffectTrack>::vfunc_0 (36 B): matches/0x001a6ca0.cpp [wrapped: conflict: fight::TrackFactoryCaster; fight::TrackFactoryCasterTemplate; hulkfight::scenario::EffectTrack]
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VEffectTrack@scenario@hulkfight@fn_001a6ca0@@@fight@fn_001a6ca0@@UAE_NPAX@Z
namespace fn_001a6ca0 {
namespace fight {
class TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
template <class T> class TrackFactoryCasterTemplate : public TrackFactoryCaster {
  public:
    virtual bool vfunc_0(void*);
    virtual void vfunc_1();
};
} // namespace fight
namespace hulkfight {
namespace scenario {
class EffectTrack {};
} // namespace scenario
} // namespace hulkfight
extern int hulk_at_0049850c;
extern int hulk_at_004c25a0;
extern "C++" __declspec(nothrow) int __cdecl FUN_00344e74(void*, int, int*, int*, int);
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::scenario::EffectTrack>::vfunc_0(void* p) {
    return FUN_00344e74(p, 0, &hulk_at_0049850c, &hulk_at_004c25a0, 0) != 0;
}
} // namespace fn_001a6ca0


// 0x001a6cd0 fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::vfunc_0 (30 B): matches/0x001a6cd0.cpp
// sym: ??_G?$ParamFloatConstRange@VEffectTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::scenario::EffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6cd0)
#endif


// 0x001a6cf0 fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::vfunc_0 (30 B): matches/0x001a6cf0.cpp
// sym: ??_G?$ParamEnumConstList@VEffectTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::EffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6cf0)
#endif


// 0x001a6d10 fight::ParamVector<hulkfight::scenario::EffectTrack>::vfunc_0 (30 B): matches/0x001a6d10.cpp
// sym: ??_G?$ParamVector@VEffectTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamVector<hulkfight::scenario::EffectTrack>::~ParamVector() {}
#if defined(HULK_PTR64)
template class fight::ParamVector<hulkfight::scenario::EffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6d10)
#endif


// 0x001a6d40 fight::TrackFactoryCasterTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_0 (36 B): matches/0x001a6d40.cpp
// sym: ?vfunc_0@?$TrackFactoryCasterTemplate@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAE_NPAX@Z
template <> bool fight::TrackFactoryCasterTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    return FUN_00344e74(p, 0, &DAT_0049850c, &DAT_004c2650, 0) != 0;
}


// 0x001a6d70 fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_0 (30 B): matches/0x001a6d70.cpp
// sym: ??_G?$ParamFloatConstRange@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>::~ParamFloatConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamFloatConstRange<hulkfight::scenario::NISAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6d70)
#endif


// 0x001a6d90 fight::ParamString<hulkfight::scenario::NISAnimationTrack>::vfunc_0 (30 B): matches/0x001a6d90.cpp
// sym: ??_G?$ParamString@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamString<hulkfight::scenario::NISAnimationTrack>::~ParamString() {}
#if defined(HULK_PTR64)
template class fight::ParamString<hulkfight::scenario::NISAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6d90)
#endif


// 0x001a6db0 fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::vfunc_0 (30 B): matches/0x001a6db0.cpp
// sym: ??_G?$ParamEnumConstList@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>::~ParamEnumConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamEnumConstList<hulkfight::scenario::NISAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6db0)
#endif


// 0x001a6dd0 fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::vfunc_0 (30 B): matches/0x001a6dd0.cpp
// sym: ??_G?$ParamBool@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamBool<hulkfight::scenario::NISAnimationTrack>::~ParamBool() {}
#if defined(HULK_PTR64)
template class fight::ParamBool<hulkfight::scenario::NISAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6dd0)
#endif


// 0x001a6df0 fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::vfunc_0 (30 B): matches/0x001a6df0.cpp
// sym: ??_G?$ParamIntConstRange@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>::~ParamIntConstRange() {}
#if defined(HULK_PTR64)
template class fight::ParamIntConstRange<hulkfight::scenario::NISAnimationTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a6df0)
#endif


// 0x001a6e10 FUN_001a6e10 (61 B): matches/0x001a6e10.cpp
// sym: ?FUN_001a6e10@Owner_1a6e10@owners@@QAEPAXXZ
void* owners::Owner_1a6e10::FUN_001a6e10() {
    void* p = Get();
    while (p != 0 && FUN_00344e74(p, 0, (void*)((hulk_intptr)DAT_0048d5bc), (void*)((hulk_intptr)DAT_004a15cc), 0) == 0) {
        p = Get();
    }
    return p;
}


// 0x001a6e50 FUN_001a6e50 (61 B): matches/0x001a6e50.cpp
// sym: ?FUN_001a6e50@Obj_1a6e50@owners@@QAEPAU12@XZ
owners::Obj_1a6e50* owners::Obj_1a6e50::FUN_001a6e50() {
    owners::Obj_1a6e50* p = Get();
    while (p && ((int)(hulk_uintptr)__RTDynamicCast((void*)(p), 0, (void*)((const char*)((hulk_intptr)DAT_0048d5bc)), (void*)((const char*)((hulk_intptr)DAT_004c26a4)), 0)) == 0)
        p = Get();
    return p;
}


// 0x001a6e90 FUN_001a6e90 (61 B): matches/0x001a6e90.cpp
// sym: ?FUN_001a6e90@Obj_1a6e90@owners@@QAEPAXXZ
void* owners::Obj_1a6e90::FUN_001a6e90() {
    void* p = Get();
    while (p) {
        if (Compare(p, 0, hulk_at_0048d5bc, hulk_at_0049e11c, 0))
            break;
        p = Get();
    }
    return p;
}


// 0x001a6ee0 content::LoadInventory::DynamicCaster<pure3d::Skeleton>::vfunc_0 (30 B): matches/0x001a6ee0.cpp
// sym: ?vfunc_0@?$DynamicCaster@VSkeleton@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::Skeleton>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    __RTDynamicCast((void*)((hulk_uintptr)p), 0, (void*)(&type_refcount), (void*)(&type_animation), 0);
}


// 0x001a6f10 content::LoadInventory::DynamicCaster<pure3d::Camera>::vfunc_0 (30 B): matches/0x001a6f10.cpp
// sym: ?vfunc_0@?$DynamicCaster@VCamera@pure3d@@@LoadInventory@content@@UAEXPAX@Z
// Same code shape as 0x00021650 (propagated; names are from that function)
template <> void content::LoadInventory::DynamicCaster<pure3d::Camera>::vfunc_0(void* __p0) { void * p = (void *)__p0;

    __RTDynamicCast((void*)((hulk_uintptr)p), 0, (void*)(&type_refcount), (void*)(&type_animation), 0);
}


// 0x001a6ff0 FUN_001a6ff0 (192 B): equivalent/0x001a6ff0.cpp [wrapped: conflict: fight::ParamEnumConstList]
// sym: ?FUN_001a6ff0@fn_001a6ff0@@YAXXZ @aab37c4b29e9 @wb804426f98b8
namespace fn_001a6ff0 {
// STATUS: equivalent (tools/equiv.py level 3: 2993 inputs, branch coverage 6/6)
// FUN_001a6ff0 @ 0x001a6ff0


extern void SetCompare_001a1f00();
extern void SetOldState_001a1f10();
extern void* __cdecl FUN_0008d690(unsigned int);
struct Base_1a6ff0 { virtual void slot0(); void FUN_00234cc0(const char*); };
namespace hulkfight { namespace scenario { class Event_LocomotionStateNamePreviousCondition; } }
namespace fight { template<class T> struct ParamEnumConstList : Base_1a6ff0 {
 virtual void slot0();
 char pad[12];
 int* entries;
 int count;
 void (*callback)();
 int extra;
}; }
typedef fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition> Param;
extern void __cdecl FUN_002347b0(int*, Param**, int);
void FUN_001a6ff0() {
 if (!DAT_004e1724) {
  Param* list[2];
  Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) {
   int count = (*(int*)&DAT_00427760);
   p->FUN_00234cc0("compare");
   new (p) Param;
   p->entries = ((int*)&DAT_00427758);
   p->count = count;
   p->callback = SetCompare_001a1f00;
  }
  list[0] = p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) {
   int count = (*(int*)&DAT_003f5bbc);
   p->FUN_00234cc0("oldState");
   new (p) Param;
   p->entries = ((int*)&DAT_0048f590);
   p->count = count;
   p->callback = SetOldState_001a1f10;
  }
  list[1] = p;
  FUN_002347b0(&DAT_004e1720, list, 2);
 }
 ++DAT_004e1724;
}
} // namespace fn_001a6ff0


// 0x001a70b0 FUN_001a70b0 (192 B): equivalent/0x001a70b0.cpp [wrapped: conflict: Param; fight::ParamEnumConstList]
// sym: ?FUN_001a70b0@fn_001a70b0@@YAXXZ @e164b01a259f @wbf2c36df299a
namespace fn_001a70b0 {
// STATUS: equivalent (tools/equiv.py level 3: 2996 inputs, branch coverage 6/6)
// FUN_001a70b0 @ 0x001a70b0


extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(unsigned int);
extern "C" void SetCompare_001a1f20();
extern "C" void SetNewState_001a1f30();
namespace hulkfight { namespace scenario { class Event_LocomotionStateNameCondition; } }
namespace fight { template<class T> struct ParamEnumConstList {
 virtual void slot0();
 char padding[12];
 void* values;
 unsigned int count;
 void (*callback)();
 unsigned int tail;
 void FUN_00234cc0(const char*);
}; }
typedef fight::ParamEnumConstList<hulkfight::scenario::Event_LocomotionStateNameCondition> Param;
extern "C" void __cdecl FUN_002347b0(void*, Param**, unsigned int);
void __cdecl FUN_001a70b0() {
 if ((*(unsigned int*)&DAT_004e172c) == 0) {
  Param* entries[2];
  Param* p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) {
   unsigned int count = (*(unsigned int*)&DAT_00427760);
   p->FUN_00234cc0("compare");
   new (p) Param;
   p->values = ((char*)&DAT_00427758);
   p->count = count;
   p->callback = SetCompare_001a1f20;
  }
  entries[0] = p;
  p = (Param*)FUN_0008d690((int)sizeof(Param));
  if (p) {
   unsigned int count = (*(unsigned int*)&DAT_003f5bbc);
   p->FUN_00234cc0("newState");
   new (p) Param;
   p->values = ((char*)&DAT_0048f590);
   p->count = count;
   p->callback = SetNewState_001a1f30;
  }
  entries[1] = p;
  FUN_002347b0(((unsigned int*)&DAT_004e1728), entries, 2);
 }
 ++(*(unsigned int*)&DAT_004e172c);
}
} // namespace fn_001a70b0


// 0x001a7170 FUN_001a7170 (109 B): matches/0x001a7170.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ?target@fn_001a7170@@YAXXZ
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_001a7170 {
// data: gList_1a7170 = DAT_004e1730, gTable_1a7170 = DAT_004c165c


class ParamValueEnum_1a7170 {
  public:
    ParamValueEnum_1a7170(const char*) throw();
    virtual void v0();
    char pad[0xc];
};
class ParamEnumConstList_1a7170 : public ParamValueEnum_1a7170 {
  public:
    ParamEnumConstList_1a7170(const char*) throw();
    virtual void v0();
    const void* tbl;
    int count;
    void* fn;
    int pad2;
};
extern char hulk_at_001a1f40[];
extern void __cdecl Register_002347b0(void*, void**, int) throw();
ParamEnumConstList_1a7170::ParamEnumConstList_1a7170(const char* n) throw() : ParamValueEnum_1a7170(n) {
    tbl = ((char*)&DAT_004c165c);
    count = 8;
    fn = hulk_at_001a1f40;
}
void target() {
    if (!(*(int*)&DAT_004e1734)) {
        ParamEnumConstList_1a7170* p = new ParamEnumConstList_1a7170("stateDesc");
        Register_002347b0(((char*)&DAT_004e1730), (void**)&p, 1);
    }
    ++(*(int*)&DAT_004e1734);
}
} // namespace fn_001a7170


// 0x001a71e0 FUN_001a71e0 (6861 B): equivalent/0x001a71e0.cpp [wrapped: macros; using-directive]
// sym: ?FUN_001a71e0@fn_001a71e0@@YAXXZ @09dd873885cb @wb85070180fab
namespace fn_001a71e0 {
// STATUS: equivalent (tools/equiv.py level 3: 167 inputs, branch coverage 240/244, incomplete)
// FUN_001a71e0 @ 0x001a71e0

typedef void (*Callback)();
void* __cdecl FUN_0008d690(unsigned);
namespace hulkfight { namespace scenario { class NISAnimationTrack; } }
struct ParamBase { virtual void slot0(); char padding[12]; void FUN_00234960(const char*); void FUN_002349e0(const char*); void FUN_00234cc0(const char*); void FUN_00234860(const char*); void FUN_002348e0(const char*); };
namespace fight {
template<class T> struct ParamFloatConstRange: ParamBase { virtual void slot0(); Callback callback; unsigned extra; };
template<class T> struct ParamString: ParamBase { virtual void slot0(); Callback callback; unsigned extra; };
template<class T> struct ParamBool: ParamBase { virtual void slot0(); Callback callback; unsigned extra; };
template<class T> struct ParamIntConstRange: ParamBase { virtual void slot0(); Callback callback; unsigned extra; };
template<class T> struct ParamEnumConstList: ParamBase { virtual void slot0(); void* list; unsigned count; Callback callback; unsigned extra; };
}
using namespace fight;
typedef hulkfight::scenario::NISAnimationTrack Track;
void __cdecl FUN_002347b0(void*, ParamBase**, unsigned);
#define DECL(a) void FUN_##a();
DECL(001a20f0) DECL(001a2100) DECL(001a2120) DECL(001a2140) DECL(001a2160) DECL(001a2180) DECL(001a36f0) DECL(001a21b0) DECL(001a21d0) DECL(001a2200) DECL(001a2220) DECL(001a2240) DECL(001a2260) DECL(001a2280) DECL(001a22a0) DECL(001a22c0) DECL(001a3750) DECL(001a22e0) DECL(001a2300) DECL(001a2320) DECL(001a2340)
#define GROUPDECL(a,b,c,d,e) DECL(a) DECL(b) DECL(c) DECL(d) DECL(e)
GROUPDECL(001a2360,001a2380,001a37b0,001a3810,001a23c0)
GROUPDECL(001a23e0,001a2400,001a3870,001a38d0,001a2440)
GROUPDECL(001a2460,001a2480,001a3930,001a3990,001a24c0)
GROUPDECL(001a24e0,001a2500,001a3a00,001a3a70,001a2540)
GROUPDECL(001a2560,001a2580,001a3ae0,001a3b50,001a25c0)
GROUPDECL(001a25e0,001a2600,001a3bc0,001a3c30,001a2640)
GROUPDECL(001a2660,001a2680,001a3ca0,001a3d10,001a26c0)
GROUPDECL(001a26e0,001a2700,001a3d80,001a3df0,001a2740)
GROUPDECL(001a2760,001a2780,001a3e60,001a3ed0,001a27c0)
GROUPDECL(001a27e0,001a2800,001a3f40,001a3fb0,001a2840)
GROUPDECL(001a2860,001a2880,001a4020,001a4090,001a28c0)
GROUPDECL(001a28e0,001a2900,001a4100,001a4170,001a2940)
GROUPDECL(001a2960,001a2980,001a41e0,001a4250,001a29c0)
GROUPDECL(001a29e0,001a2a00,001a42c0,001a4330,001a2a40)
GROUPDECL(001a2a60,001a2a80,001a43a0,001a4410,001a2ac0)
GROUPDECL(001a2ae0,001a2b00,001a4480,001a44f0,001a2b40)
GROUPDECL(001a2b60,001a2b80,001a4560,001a45d0,001a2bc0)
GROUPDECL(001a2be0,001a2c00,001a4640,001a46b0,001a2c40)
GROUPDECL(001a2c60,001a2c80,001a4720,001a4790,001a2cc0)
GROUPDECL(001a2ce0,001a2d00,001a4800,001a4870,001a2d40)
#define MAKE(T,init,text,fn) { T<Track>* p=(T<Track>*)FUN_0008d690(sizeof(T<Track>)); if(p) { p->init(text); p->T<Track>::T(); p->callback=FUN_##fn; } params[n++]=p; }
#define F(text,fn) MAKE(ParamFloatConstRange,FUN_00234960,text,fn)
#define S(text,fn) MAKE(ParamString,FUN_002349e0,text,fn)
#define B(text,fn) MAKE(ParamBool,FUN_00234860,text,fn)
#define I(text,fn) MAKE(ParamIntConstRange,FUN_002348e0,text,fn)
#define E(text,fn,listdata,num) { ParamEnumConstList<Track>* p=(ParamEnumConstList<Track>*)FUN_0008d690(sizeof(ParamEnumConstList<Track>)); if(p) { unsigned count=num; p->FUN_00234cc0(text); p->ParamEnumConstList<Track>::ParamEnumConstList(); p->list=listdata; p->count=count; p->callback=FUN_##fn; } params[n++]=p; }
#define GROUP(k,a,b,c,d,e) B("is_Skeleton_" #k,a) B("drop_Weapon_" #k,b) S("animation" #k,c) S("character" #k,d) I("which_Drawable_" #k,e)
void __cdecl FUN_001a71e0() {
 if(!DAT_004e175c) { ParamBase* params[121]; unsigned n=0;
 F("timeBegin",001a20f0) F("timeEnd",001a2100) F("speed",001a2120) F("initFrame",001a2140) F("startFrame",001a2160) F("endFrame",001a2180)
 S("origin_Locator",001a36f0) E("originType",001a21b0,((char*)&DAT_004c167c),4) F("orientation",001a21d0) B("use_Camera",001a2200)
 E("blendInTransition",001a2220,((char*)&DAT_00496f9c),(*(unsigned*)&DAT_003fb8f8)) E("blendInBlend",001a2240,((char*)&DAT_00496fa4),(*(unsigned*)&DAT_003fb8fc)) F("blendInDuration",001a2260)
 E("blendOutTransition",001a2280,((char*)&DAT_00496f9c),(*(unsigned*)&DAT_003fb8f8)) E("blendOutBlend",001a22a0,((char*)&DAT_00496fa4),(*(unsigned*)&DAT_003fb8fc)) F("blendOutDuration",001a22c0)
 S("filename",001a3750) B("screw_Sound_Sync",001a22e0) B("draw_The_Hulk",001a2300) B("load_The_File",001a2320) I("which_Inventory",001a2340)
 GROUP(0,001a2360,001a2380,001a37b0,001a3810,001a23c0)
 GROUP(1,001a23e0,001a2400,001a3870,001a38d0,001a2440)
 GROUP(2,001a2460,001a2480,001a3930,001a3990,001a24c0)
 GROUP(3,001a24e0,001a2500,001a3a00,001a3a70,001a2540)
 GROUP(4,001a2560,001a2580,001a3ae0,001a3b50,001a25c0)
 GROUP(5,001a25e0,001a2600,001a3bc0,001a3c30,001a2640)
 GROUP(6,001a2660,001a2680,001a3ca0,001a3d10,001a26c0)
 GROUP(7,001a26e0,001a2700,001a3d80,001a3df0,001a2740)
 GROUP(8,001a2760,001a2780,001a3e60,001a3ed0,001a27c0)
 GROUP(9,001a27e0,001a2800,001a3f40,001a3fb0,001a2840)
 GROUP(10,001a2860,001a2880,001a4020,001a4090,001a28c0)
 GROUP(11,001a28e0,001a2900,001a4100,001a4170,001a2940)
 GROUP(12,001a2960,001a2980,001a41e0,001a4250,001a29c0)
 GROUP(13,001a29e0,001a2a00,001a42c0,001a4330,001a2a40)
 GROUP(14,001a2a60,001a2a80,001a43a0,001a4410,001a2ac0)
 GROUP(15,001a2ae0,001a2b00,001a4480,001a44f0,001a2b40)
 GROUP(16,001a2b60,001a2b80,001a4560,001a45d0,001a2bc0)
 GROUP(17,001a2be0,001a2c00,001a4640,001a46b0,001a2c40)
 GROUP(18,001a2c60,001a2c80,001a4720,001a4790,001a2cc0)
 GROUP(19,001a2ce0,001a2d00,001a4800,001a4870,001a2d40)
 FUN_002347b0(((unsigned*)&DAT_004e1758),params,121);
 } ++DAT_004e175c;
}
} // namespace fn_001a71e0
#undef B
#undef DECL
#undef E
#undef F
#undef GROUP
#undef GROUPDECL
#undef I
#undef MAKE
#undef S

namespace fn_fc5dbd2a {

// 0x001a8cb0 FUN_001a8cb0 (89 B): matches/0x001a8cb0.cpp
// sym: ?Clear@Obj_1a8cb0@fn_fc5dbd2a@@QAEXXZ
void Obj_1a8cb0::Clear() {
    Init_001a5d50();
    if (a) {
        a->B();
        a = 0;
    }
    if (b) {
        b->B();
        b = 0;
    }
    if (c) {
        c->B();
        c = 0;
    }
    if (d) {
        d->B();
        d = 0;
    }
    if (e) {
        e->B();
        e = 0;
    }
}

} // namespace fn_fc5dbd2a

// 0x001a8d10 FUN_001a8d10 (152 B): equivalent/0x001a8d10.cpp [wrapped: conflict: NISAnimationAction; World]
// sym: ?FUN_001a8d10@NISAnimationAction@fn_001a8d10@@QAEPAU12@HPAURefObj_1a8d10@2@@Z @5459bf92b313 @w92393a698bcd
namespace fn_001a8d10 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001a8d10 @ 0x001a8d10
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

extern char DAT_0041cf24[];

struct RefObj_1a8d10 {
    virtual void addRef();
    virtual void release();
};
struct SlotEntry_1a8d10 {
    char b0, b1, b2, b3;
    int v0, v1, v2, v3, v4;
};
struct Holder54_1a8d10 {  };
struct World { char pad[0x54]; Holder54_1a8d10* holder; };

struct NISAnimationAction;

struct NISAnimationAction {
    hulk_intptr vptr;
    char pad04[0x18];
    int f1c;
    RefObj_1a8d10* f20;
    int f24, f28;
    SlotEntry_1a8d10 slots[20];
    int f20c;
    int f210;
    char f214;
    void FUN_00232660();
    NISAnimationAction* FUN_001a8d10(int arg, RefObj_1a8d10* target);
};

NISAnimationAction* NISAnimationAction::FUN_001a8d10(int arg, RefObj_1a8d10* target)
{
    FUN_00232660();
    vptr = (hulk_intptr)DAT_0041cf24;
    f1c = 0;
    f20 = 0;
    f24 = 0;
    f28 = 0;
    for (int i = 0; i < 20; i++) {
        slots[i].b0 = 0;
        slots[i].b1 = 0;
        slots[i].b2 = 0;
        slots[i].b3 = 0;
        slots[i].v0 = 0;
        slots[i].v1 = 0;
        slots[i].v2 = 0;
        slots[i].v3 = 0;
        slots[i].v4 = 0;
    }
    f210 = 0;
    f214 = 0;
    f1c = arg;
    if (target)
        target->addRef();
    if (f20)
        f20->release();
    f20 = target;
    f20c = ((int)((owners::Target_862a0 *)(DAT_004dd700->holder))->FUN_000862a0());
    (*(NISAnimationAction**)&DAT_004e1760) = this;
    return this;
}
} // namespace fn_001a8d10
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_fc5dbd2a {

// 0x001a8db0 FUN_001a8db0 (163 B): matches/0x001a8db0.cpp
// sym: ??1NISAnimationAction_1a8db0@fn_fc5dbd2a@@QAE@XZ
// data: g_cur_1a8db0 = DAT_004e1760
NISAnimationAction_1a8db0::~NISAnimationAction_1a8db0() throw() {
    vptr = hulk_at_0041cf24;
    if ((*(NISAnimationAction_1a8db0**)&DAT_004e1760) == this)
        (*(NISAnimationAction_1a8db0**)&DAT_004e1760) = 0;
    if (m20) {
        m20->Release();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    El* p = e + 20;
    int n = 20;
    do {
        p--;
        p->Fin_001a5d50();
        if (p->r1) {
            p->r1->Release();
            p->r1 = 0;
        }
        if (p->r2) {
            p->r2->Release();
            p->r2 = 0;
        }
        if (p->r3) {
            p->r3->Release();
            p->r3 = 0;
        }
        if (p->r4) {
            p->r4->Release();
            p->r4 = 0;
        }
        if (p->r5) {
            p->r5->Release();
            p->r5 = 0;
        }
    } while (--n);
}

} // namespace fn_fc5dbd2a

// 0x001a8e60 FUN_001a8e60 (114 B): matches/0x001a8e60.cpp [wrapped: conflict: World]
// sym: ?FUN_001a8e60@Owner_1a8e60@fn_001a8e60@@QAEXXZ
namespace fn_001a8e60 {
// FUN_001a8e60 @ 0x001a8e60
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

struct Item_1a8e60 {
    char data[0x18];
    void FUN_001a5d50();
};
struct Releasable_1a8e60 {
    virtual void v0();
    virtual void release();
};
struct Config_1a8e60 {
    char pad0[0x52];
    char flag;
    char pad53;
    int f54;
};
struct Sink_1a8e60 {
    void FUN_00203e00(int value);
};
struct Inner_1a8e60 {
    void FUN_001b92c0(int arg);
};
struct Selector_1a8e60 {
};
struct World {
    char pad0[0x54];
    Selector_1a8e60 *f54;
};

struct Owner_1a8e60 {
    char pad0[0x1c];
    Config_1a8e60 *config;
    char pad20[4];
    Releasable_1a8e60 *f24;
    Releasable_1a8e60 *f28;
    Item_1a8e60 items[20];
    Sink_1a8e60 *sink;
    void FUN_001a8e60();
};

void Owner_1a8e60::FUN_001a8e60()
{
    ((Inner_1a8e60 *)((owners::Obj_86290 *)(DAT_004dd700->f54))->FUN_00086290())->FUN_001b92c0(0);
    for (int i = 0; i < 20; i++)
        items[i].FUN_001a5d50();
    if (f28) {
        f28->release();
        f28 = 0;
    }
    if (f24) {
        f24->release();
        f24 = 0;
    }
    if (config->flag)
        sink->FUN_00203e00(config->f54);
    (*(char*)&DAT_004e1764) = 0;
}
} // namespace fn_001a8e60
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001a8ee0 hulkfight::scenario::NISAnimationAction::vfunc_4 (101 B): matches/0x001a8ee0.cpp
// sym: ?vfunc_4@NISAnimationAction@scenario@hulkfight@@UAEXXZ
void hulkfight::scenario::NISAnimationAction::vfunc_4() {
    ((Obj31 *)((owners::Obj_86290 *)(g_1a8ee0->m))->FUN_00086290())->f = 1;
    ((NISAnimationAction_nv_1a8ee0*)this)->Inner_001a8e60();
    if (this->f_214) {
        (*(Hnd * *)&this->f_20c)->Rel_002080b0();
        this->f_214 = 0;
    }
    Hulk* x = g_1a8ee0->s->h;
    if (x) {
        ((Ent_1a8ee0 *)((owners::Obj_36a80 *)x)->FUN_00036a80(1))->f = 1;
        x->Fn2_0003dd00(0);
    }
}


// 0x001a8f50 hulkfight::scenario::EffectTrack::vfunc_10 (40 B): matches/0x001a8f50.cpp
// sym: ?vfunc_10@EffectTrack@scenario@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::scenario::EffectTrack::vfunc_10(hulk_intptr x, hulk_intptr , hulk_intptr ) {
    EffectAction_1a8f50* p = GetThing_0008d690(0x6c);
    if (p)
        return p->Call_001a5e50(this, x);
    return 0;
}

namespace fn_fc5dbd2a {

// 0x001a8f80 hulkfight::scenario::EffectAction::vfunc_2 (90 B): matches/0x001a8f80.cpp
// sym: ?f2@EffectAction@fn_fc5dbd2a@@QAEPAV12@H@Z
EffectAction* EffectAction::f2(int flags) {
    *(void* volatile*)this = &g_vftable_1a8f80;
    _ReadWriteBarrier();
    if (m28) {
        m28->f1();
        m28 = 0;
    }
    if (m20) {
        m20->f1();
        m20 = 0;
    }
    if (m1c)
        m1c = 0;
    ((fight::Action *)(((EffectAction_1a8f80*)this)))->FUN_002326a0();
    if (flags & 1)
        thunk_FUN_00267090(this);
    return this;
}


// 0x001a9040 fight::ParamName<hulkfight::scenario::Event_StringCondition>::vfunc_7 (12 B): matches/0x001a9040.cpp
// sym: ?vfunc_6@ParamBranch@fn_fc5dbd2a@@UAEXPAX@Z
// Same code shape as 0x00050240 (propagated; names are from that function)
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}

} // namespace fn_fc5dbd2a

// 0x001a9110 fight::ParamName<hulkfight::scenario::Event_PropTypeCondition>::vfunc_7 (12 B): matches/0x001a9110.cpp [wrapped: same definition as 0x001a9040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001a9110@@UAEXPAX@Z
namespace fn_001a9110 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_001a9110


// 0x001a9160 fight::ParamName<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_7 (12 B): matches/0x001a9160.cpp [wrapped: same definition as 0x001a9040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001a9160@@UAEXPAX@Z
namespace fn_001a9160 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_001a9160


// 0x001a91b0 fight::ParamName<hulkfight::scenario::Event_PropNameCondition>::vfunc_7 (12 B): matches/0x001a91b0.cpp [wrapped: same definition as 0x001a9040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001a91b0@@UAEXPAX@Z
namespace fn_001a91b0 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_001a91b0


// 0x001a9200 fight::ParamName<hulkfight::scenario::EffectTrack>::vfunc_7 (12 B): matches/0x001a9200.cpp [wrapped: same definition as 0x001a9040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001a9200@@UAEXPAX@Z
namespace fn_001a9200 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_001a9200


// 0x001a9230 fight::ParamNameConstList<hulkfight::scenario::EffectTrack>::vfunc_7 (12 B): matches/0x001a9230.cpp [wrapped: same definition as 0x001a9040 in this TU]
// sym: ?vfunc_6@ParamBranch@fn_001a9230@@UAEXPAX@Z
namespace fn_001a9230 {
// Same code shape as 0x00050240 (propagated; names are from that function)
class ParamValueBranch {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};
class ParamValue {};
class ParamBranch : public ParamValueBranch, public ParamValue {
  public:
    char pad[0x10 - sizeof(void*)];
    void(__fastcall* fn)(void*);
    virtual void vfunc_6(void*);
};
void ParamBranch::vfunc_6(void* p) {
    fn(p);
}
} // namespace fn_001a9230

namespace fn_fc5dbd2a {

// 0x001a9260 FUN_001a9260 (52 B): matches/0x001a9260.cpp
// sym: ?Target@Obj_1a9260@fn_fc5dbd2a@@QAEPAU12@XZ
Obj_1a9260* Obj_1a9260::Target() {
    Obj_1a9260* p = Get_00231640();
    if (FUN_00344e74(p, 0, &g1_1a9260, &hulk_at_004a15cc, 0))
        return p;
    return ((Obj_1a9260 *)((owners::Owner_1a6e10 *)this)->FUN_001a6e10());
}


// 0x001a92a0 FUN_001a92a0 (52 B): matches/0x001a92a0.cpp
// sym: ?Target@Obj_1a92a0@fn_fc5dbd2a@@QAEPAU12@XZ
// Same code shape as 0x001a9260 (propagated; names are from that function)
Obj_1a92a0* Obj_1a92a0::Target() {
    Obj_1a92a0* p = Get_00231640();
    if (FUN_00344e74(p, 0, &g1_1a92a0, &hulk_at_004c26a4, 0))
        return p;
    return ((Obj_1a92a0 *)((owners::Obj_1a6e50 *)this)->FUN_001a6e50());
}

} // namespace fn_fc5dbd2a

// 0x001a92e0 FUN_001a92e0 (52 B): matches/0x001a92e0.cpp
// sym: ?FUN_001a92e0@Obj_1a92e0@owners@@QAEPAU12@XZ
// Same code shape as 0x001a9260 (propagated; names are from that function)
owners::Obj_1a92e0* owners::Obj_1a92e0::FUN_001a92e0() {
    owners::Obj_1a92e0* p = Get();
    if (FUN_00344e74(p, 0, &g1_1a92e0, &g2_1a92e0, 0))
        return p;
    return Tail();
}


// 0x001a9320 fight::ParamName<hulkfight::scenario::Event_StringCondition>::vfunc_0 (30 B): matches/0x001a9320.cpp
// sym: ??_G?$ParamName@VEvent_StringCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_StringCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_StringCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a9320)
#endif


// 0x001a9340 fight::ParamName<hulkfight::scenario::Event_PropTypeCondition>::vfunc_0 (30 B): matches/0x001a9340.cpp
// sym: ??_G?$ParamName@VEvent_PropTypeCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_PropTypeCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_PropTypeCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a9340)
#endif


// 0x001a9360 fight::ParamName<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_0 (30 B): matches/0x001a9360.cpp
// sym: ??_G?$ParamName@VEvent_PropStateNameCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_PropStateNameCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_PropStateNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a9360)
#endif


// 0x001a9380 fight::ParamName<hulkfight::scenario::Event_PropNameCondition>::vfunc_0 (30 B): matches/0x001a9380.cpp
// sym: ??_G?$ParamName@VEvent_PropNameCondition@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::Event_PropNameCondition>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::Event_PropNameCondition>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a9380)
#endif


// 0x001a93a0 fight::ParamName<hulkfight::scenario::EffectTrack>::vfunc_0 (30 B): matches/0x001a93a0.cpp
// sym: ??_G?$ParamName@VEffectTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamName<hulkfight::scenario::EffectTrack>::~ParamName() {}
#if defined(HULK_PTR64)
template class fight::ParamName<hulkfight::scenario::EffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a93a0)
#endif


// 0x001a93c0 fight::ParamNameConstList<hulkfight::scenario::EffectTrack>::vfunc_0 (30 B): matches/0x001a93c0.cpp
// sym: ??_G?$ParamNameConstList@VEffectTrack@scenario@hulkfight@@@fight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
template <> fight::ParamNameConstList<hulkfight::scenario::EffectTrack>::~ParamNameConstList() {}
#if defined(HULK_PTR64)
template class fight::ParamNameConstList<hulkfight::scenario::EffectTrack>; // (ren2) native only: clang emits the scalar deleting destructor beside the vftable, which this instantiation emits (0x1a93c0)
#endif

namespace fn_fc5dbd2a {

// 0x001a9420 FUN_001a9420 (50 B): matches/0x001a9420.cpp
// sym: ?Load@LoadInventory@fn_fc5dbd2a@@QAEHPAX@Z
hulk_intptr LoadInventory::Load(void* p) {
    DynamicCaster_1a9420 caster;
    return d(&caster, lookup(p, 0, 0));
}


// 0x001a94a0 FUN_001a94a0 (38 B): matches/0x001a94a0.cpp
// sym: _FUN_001a94a0
extern "C" void FUN_001a94a0(Obj* obj, void* value) {
    ConditionFactoryCasterTemplate_1a94a0 caster;
    void* p = find(value, &caster);
    obj->set_00236760(p);
}

} // namespace fn_fc5dbd2a

// 0x001a94d0 FUN_001a94d0 (38 B): matches/0x001a94d0.cpp [wrapped: conflict: Find]
// sym: _FUN_001a94d0
namespace fn_001a94d0 {
class ConditionFactoryCasterTemplate_1a94d0 {
  public:
    virtual bool Cast_001a6a20(void*);
};
extern "C++" __declspec(nothrow) void* __cdecl Find_002343e0(void*, ConditionFactoryCasterTemplate_1a94d0*);
class Factory {
  public:
    void Use_00236760(void*);
};
extern "C" void __cdecl FUN_001a94d0(Factory* factory, void* item) {
    ConditionFactoryCasterTemplate_1a94d0 caster;
    factory->Use_00236760(Find_002343e0(item, &caster));
}
} // namespace fn_001a94d0

namespace fn_fc5dbd2a {

// 0x001a9560 FUN_001a9560 (38 B): matches/0x001a9560.cpp
// sym: _FUN_001a9560
extern "C" void FUN_001a9560(Owner* owner, void* value) {
    ConditionFactoryCasterTemplate_1a9560 caster;
    void* result = FUN_002343e0(value, &caster);
    owner->Apply_00236760(result);
}


// 0x001a9590 FUN_001a9590 (38 B): matches/0x001a9590.cpp
// sym: _FUN_001a9590
extern "C" void __cdecl FUN_001a9590(Obj* obj, void* value) {
    ConditionFactoryCasterTemplate_1a9590 caster;
    void* p = Find_002343e0(value, &caster);
    obj->Apply_00236760(p);
}


// 0x001a95c0 FUN_001a95c0 (38 B): matches/0x001a95c0.cpp
// sym: _FUN_001a95c0
extern "C" void __cdecl FUN_001a95c0(Obj* obj, void* p) {
    ConditionFactoryCasterTemplate_1a95c0 caster;
    obj->Do_00236760(Find_002343e0(p, &caster));
}

} // namespace fn_fc5dbd2a

// 0x001a95f0 FUN_001a95f0 (38 B): matches/0x001a95f0.cpp [wrapped: conflict: lookup]
// sym: _FUN_001a95f0
namespace fn_001a95f0 {
class ConditionFactoryCasterTemplate_1a95f0 {
  public:
    virtual bool Fnf_001a6b80(void*);
};
class Desc;
extern Desc* __cdecl lookup_002343e0(const char*, ConditionFactoryCasterTemplate_1a95f0*);
class Owner {
  public:
    void use_00236760(Desc*);
};
extern "C" void FUN_001a95f0(Owner* p, const char* s) {
    ConditionFactoryCasterTemplate_1a95f0 c;
    Desc* d = lookup_002343e0(s, &c);
    p->use_00236760(d);
}
} // namespace fn_001a95f0

namespace fn_fc5dbd2a {

// 0x001a9620 FUN_001a9620 (38 B): matches/0x001a9620.cpp
// sym: _FUN_001a9620
extern "C" void __cdecl FUN_001a9620(Owner* owner, char* name) {
    ConditionFactoryCasterTemplate_1a9620 c;
    void* p = Find_002343e0(name, &c);
    owner->Use_00236760(p);
}


// 0x001a96b0 FUN_001a96b0 (38 B): matches/0x001a96b0.cpp
// sym: _FUN_001a96b0
extern "C" void FUN_001a96b0(Receiver* r, void* p) {
    ConditionFactoryCasterTemplate_1a96b0 c;
    r->Apply_00236760(FUN_002343e0(p, &c));
}


// 0x001a9740 FUN_001a9740 (38 B): matches/0x001a9740.cpp
// sym: _FUN_001a9740
extern "C" void* FUN_001a9740(Obj* o, void* p) {
    ConditionFactoryCasterTemplate_1a9740 c;
    return o->Get_00236760(Lookup_002343e0(p, &c));
}


// 0x001a97d0 FUN_001a97d0 (38 B): matches/0x001a97d0.cpp
// sym: _FUN_001a97d0
extern "C" void FUN_001a97d0(Obj* obj, void* name) {
    TrackFactoryCasterTemplate_1a97d0 caster;
    obj->Find_002367c0(FindTrack(name, &caster));
}


// 0x001a9a90 FUN_001a9a90 (38 B): matches/0x001a9a90.cpp
// sym: _FUN_001a9a90
extern "C" void __cdecl FUN_001a9a90(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1a9a90 caster;
    owner->accept_002367c0(FUN_00236ac0(name, &caster));
}

} // namespace fn_fc5dbd2a

// 0x001a9ac0 hulkfight::scenario::NISAnimationTrack::vfunc_10 (43 B): matches/0x001a9ac0.cpp
// sym: ?vfunc_10@NISAnimationTrack@scenario@hulkfight@@UAEHHHH@Z
hulk_intptr hulkfight::scenario::NISAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* x = FUN_0008d690(0x218);
    if (x)
        return ((NISAnimationAction_1a9ac0*)x)->helper_001a8d10((hulk_intptr)this, c);
    return 0;
}


// 0x001a9af0 hulkfight::scenario::NISAnimationAction::vfunc_2 (30 B): matches/0x001a9af0.cpp
// sym: ??_GNISAnimationAction@scenario@hulkfight@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
hulkfight::scenario::NISAnimationAction::~NISAnimationAction() {}


// 0x001aa150 FUN_001aa150 (327 B): equivalent/0x001aa150.cpp [wrapped: using-directive]
// sym: ?FUN_001aa150@Controller_1aa150@fn_001aa150@@QAEXXZ @6542790abf19 @w4117c6ef06eb
namespace fn_001aa150 {
// STATUS: equivalent (tools/equiv.py level 3: 20021 inputs, branch coverage 12/12)
// FUN_001aa150 @ 0x001aa150
// FUN_001aa150 @ 0x001aa150
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

struct Placement_1aa150;
namespace core {
struct IRefCount_1aa150 {
    virtual void r0();
    virtual void r1();
    virtual void r2();
};
}

namespace pure3d {
namespace scenegraph {
class Scenegraph_1aa150 : public core::IRefCount_1aa150 {
public:
    virtual void s3();
};
class Node_1aa150 : public core::IRefCount_1aa150 {
public:
    virtual void n3();
};
class TransformNode_1aa150 : public Node_1aa150 {
public:
    virtual void t4();
    Placement_1aa150 *FUN_001a4990();
};
}
}

using namespace pure3d::scenegraph;

struct Vec3_1aa150 {
    float x, y, z;
};

struct Transform_1aa150 {
    char data[0x40];
    void FUN_0022b980();
};

struct Placement_1aa150 {
};

// Anything the controller can track; slot 9 is called on it.
class Entity : public core::IRefCount_1aa150 {
public:
    virtual void e3();
    virtual void e4();
    virtual void e5();
    virtual void e6();
    virtual void e7();
    virtual void e8();
    virtual void e9();
    class Sequence *FUN_002961d0();
};

class Sequence {
public:
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual int q11();
    virtual Node_1aa150 *q12(int a);
};

struct Cursor_1aa150 {
    unsigned int a;
    int b;
    void *c;
    void FUN_002314a0(unsigned int v);
    Entity *FUN_00231640();
};

struct Inner_1aa150 {
    char pad0[0xc];
    unsigned int f0c;
};

struct Registry_1aa150 {
};

struct Owner_1aa150 {
    char pad0[0x2c];
    float f2c;
    char pad30[0x54 - 0x30];
    int f54;
};

struct Finish_1aa150 {
    void FUN_001b92c0(Entity *e);
};

struct Handle_1aa150 {
};

struct World {
    char pad0[0x54];
    Handle_1aa150 *handle;
};


class Controller_1aa150 {
public:
    char pad0[0x1c];
    Owner_1aa150 *owner;
    char pad20[0x20c - 0x20];
    Registry_1aa150 *registry;
    Entity *entity;
    unsigned char noOwner;

    void FUN_001a54a0(Vec3_1aa150 *out1, float *out2);
    void FUN_001aa150();
};


void Controller_1aa150::FUN_001aa150()
{
    struct Frame {
        hulk_freg f;
        float extra;
        Cursor_1aa150 it;
        Vec3_1aa150 out1;
        Transform_1aa150 xf;
    } fr;

    int idx;
    if (noOwner)
        idx = 0;
    else
        idx = owner->f54;
    Inner_1aa150 *inner = ((Inner_1aa150 *)((owners::C_203d60 *)registry)->FUN_00203d60(idx));
    fr.it.FUN_002314a0(inner->f0c);
    fr.it.c = inner;
    Entity *e = fr.it.FUN_00231640();
    core::IRefCount_1aa150 *r = e;
    if (dynamic_cast<Scenegraph_1aa150 *>(r) != 0)
        entity = e;
    else
        entity = ((Entity *)((owners::Owner_1a6e10 *)&(fr.it))->FUN_001a6e10());
    if (entity != 0) {
        entity->e9();
        Sequence *seq = entity->FUN_002961d0();
        if (seq != 0 && seq->q11() != 0) {
            Node_1aa150 *n = seq->q12(0);
            TransformNode_1aa150 *tn = dynamic_cast<TransformNode_1aa150 *>(n);
            if (tn != 0) {
                FUN_001a54a0(&fr.out1, &fr.extra);
                fr.f = owner->f2c;
                fr.xf.FUN_0022b980();
                ((owners::Target_22be40 *)&(fr.xf))->FUN_0022be40((const int *)(const Vec3_1aa150 *)(&fr.out1));
                ((owners::Mat_22ba70 *)&(fr.xf))->FUN_0022ba70(fr.f + fr.extra);
                const Transform_1aa150 * arg1_ = &fr.xf;
                ((owners::Obj_98380 *)(tn->FUN_001a4990()))->FUN_00098380((hulk_uintptr)(const Transform_1aa150 *)arg1_);
            }
        }
    }
    Entity * arg2_ = entity;
    ((Finish_1aa150 *)((owners::Obj_86290 *)(DAT_004dd700->handle))->FUN_00086290())->FUN_001b92c0(arg2_);
}
} // namespace fn_001aa150
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001aa2a0 FUN_001aa2a0 (342 B): equivalent/0x001aa2a0.cpp [wrapped: conflict: DAT_004dd700]
// sym: ?FUN_001aa2a0@CameraRig@fn_001aa2a0@@QAEXXZ @fc86a1e61123 @w4183387694bd
namespace fn_001aa2a0 {
// STATUS: equivalent (tools/equiv.py level 3: 85 inputs, branch coverage 14/14)
// FUN_001aa2a0 @ 0x001aa2a0
namespace core {
struct IRefCount_1aa2a0 {
    virtual void r0();
    virtual void r1();
    virtual void r2();
};
}

namespace pure3d {
class Camera_1aa2a0 : public core::IRefCount_1aa2a0 {
};
class CameraAnimationController_1aa2a0 : public core::IRefCount_1aa2a0 {
public:
    Camera_1aa2a0 *FUN_00292f20();
};
}

namespace content {
class LoadInventory_1aa2a0 {
  public:
    template <class T> class DynamicCaster {
      public:
        virtual T *Cast(void *p);
    };
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void *Find(const DynamicCaster<pure3d::Camera_1aa2a0> &c, __int64 uid);
    char pad04[8];
    unsigned int f0c;
};
}

unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);

struct Cursor_1aa2a0 {
    unsigned int a;
    int b;
    content::LoadInventory_1aa2a0 *c;
    void FUN_002314a0(unsigned int v);
    core::IRefCount_1aa2a0 *FUN_00231640();
};

struct Owner_1aa2a0 {
    char pad00[0x30];
    unsigned char f30;
    char pad31[3];
    int f34, f38, f3c, f40, f44, f48;
    char pad4c[0x54 - 0x4c];
    int f54;
};

struct Registry_1aa2a0 {
};

struct Scene_1aa2a0 {
    void FUN_0009a400(struct Manager_1aa2a0 *m);
    void FUN_000990d0(int a, int b, int c, int d, int e, int f);
    void FUN_0009bf50(struct Manager_1aa2a0 *m, pure3d::Camera_1aa2a0 *cam);
};

struct Ent_1aa2a0 {
    char pad[0x31];
    unsigned char flag31;
};

struct EntList_1aa2a0 {
};

struct Manager_1aa2a0 {
    char pad00[8];
    Scene_1aa2a0 *scene;
    char pad0c[0x54 - 0xc];
    EntList_1aa2a0 *ents;
};


#define DAT_004dd700 (*(Manager_1aa2a0 * *)&::DAT_004dd700)


class CameraRig {
public:
    char pad00[0x1c];
    Owner_1aa2a0 *owner;
    char pad20[4];
    pure3d::CameraAnimationController_1aa2a0 *controller;
    pure3d::Camera_1aa2a0 *camera;
    char pad2c[0x20c - 0x2c];
    Registry_1aa2a0 *registry;
    char pad210[4];
    unsigned char noOwner;

    void FUN_001a55d0();
    void FUN_001aa2a0();
};

void CameraRig::FUN_001aa2a0()
{
    if (!owner->f30)
        return;

    int idx;
    if (noOwner)
        idx = 0;
    else
        idx = owner->f54;
    content::LoadInventory_1aa2a0 *inv = ((content :: LoadInventory_1aa2a0 *)((owners::C_203d60 *)registry)->FUN_00203d60(idx));

    Cursor_1aa2a0 it;
    it.FUN_002314a0(inv->f0c);
    it.c = inv;
    core::IRefCount_1aa2a0 *e = it.FUN_00231640();
    pure3d::CameraAnimationController_1aa2a0 *cc = dynamic_cast<pure3d::CameraAnimationController_1aa2a0 *>(e);
    if (cc != 0)
        controller = (pure3d::CameraAnimationController_1aa2a0 *)e;
    else
        controller = ((pure3d :: CameraAnimationController_1aa2a0 *)((owners::Obj_1a6e50 *)&it)->FUN_001a6e50());

    if (controller != 0) {
        controller->r0();
        camera = controller->FUN_00292f20();
    }
    if (camera == 0) {
        camera = (pure3d::Camera_1aa2a0 *)inv->Find(content::LoadInventory_1aa2a0::DynamicCaster<pure3d::Camera_1aa2a0>(), FUN_002672f0("nis_camera", 0));
        if (camera == 0) {
            Cursor_1aa2a0 it2;
            it2.FUN_002314a0(inv->f0c);
            it2.c = inv;
            camera = ((pure3d :: Camera_1aa2a0 *)((owners::Obj_1a92e0 *)&it2)->FUN_001a92e0());
        }
        FUN_001a55d0();
    }
    if (camera == 0)
        return;

    camera->r0();
    DAT_004dd700->scene->FUN_0009a400(DAT_004dd700);
    Owner_1aa2a0 *o = owner;
    DAT_004dd700->scene->FUN_000990d0(o->f34, o->f38, o->f3c, o->f40, o->f44, o->f48);
    DAT_004dd700->scene->FUN_0009bf50(DAT_004dd700, camera);
    ((Ent_1aa2a0 *)((owners::Obj_86290 *)(DAT_004dd700->ents))->FUN_00086290())->flag31 = 0;
}
} // namespace fn_001aa2a0
#undef DAT_004dd700


// 0x001aa400 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_1 (60 B): matches/0x001aa400.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aa400));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aa400* t = new (mem) TrackFactoryTemplate_1aa400();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aa440 fight::ConditionFactoryTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_5 (44 B): matches/0x001aa440.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VNodeIsNotRunningCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_5() {
    Node_1aa440* p = (Node_1aa440*)Alloc(0x10);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = (hulk_uintptr)&NodeVtable;
        *((unsigned char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc5dbd2a {

// 0x001aa470 fight::ConditionFactoryTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_2 (43 B): matches/0x001aa470.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aa470@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aa470::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d05c;
    base1_dtor_001a2d50();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aa4a0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_1 (60 B): matches/0x001aa4a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VNodeShouldRunImmediatelyCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aa4a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aa4a0* t = new (mem) TrackFactoryTemplate_1aa4a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aa4e0 fight::ConditionFactoryTemplate<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_5 (44 B): matches/0x001aa4e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VNodeShouldRunImmediatelyCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_5() {
    return (void*)(new Cond_1aa4e0);
}

namespace fn_fc5dbd2a {

// 0x001aa510 fight::ConditionFactoryTemplate<hulkfight::scenario::NodeShouldRunImmediatelyCondition>::vfunc_2 (43 B): matches/0x001aa510.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aa510@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aa510::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d078;
    base1_dtor_001a2e20();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aa540 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_1 (60 B): matches/0x001aa540.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_LocomotionStateNamePreviousCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aa540));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aa540* t = new (mem) TrackFactoryTemplate_1aa540();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc5dbd2a {

// 0x001aa5c0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_LocomotionStateNamePreviousCondition>::vfunc_2 (43 B): matches/0x001aa5c0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aa5c0@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aa5c0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d094;
    base1_dtor_001a2e80();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aa5f0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_1 (60 B): matches/0x001aa5f0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_LocomotionStateNameCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aa5f0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aa5f0* t = new (mem) TrackFactoryTemplate_1aa5f0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aa630 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_5 (54 B): matches/0x001aa630.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_LocomotionStateNameCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_5() {
    Event_1aa630* p = (Event_1aa630*)FUN_0008d690((int)sizeof(Event_1aa630));
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041c550);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)((Event_1aa630*)0);
}

namespace fn_fc5dbd2a {

// 0x001aa670 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_LocomotionStateNameCondition>::vfunc_2 (43 B): matches/0x001aa670.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aa670@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aa670::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d0b0;
    base1_dtor_001a2ef0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aa6a0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_1 (60 B): matches/0x001aa6a0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_PropStateDescCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aa6a0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aa6a0* t = new (mem) TrackFactoryTemplate_1aa6a0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aa6e0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_5 (47 B): matches/0x001aa6e0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_PropStateDescCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_5() {
    return (void*)(new Event_PropStateDescCondition_1aa6e0);
}

namespace fn_fc5dbd2a {

// 0x001aa710 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropStateDescCondition>::vfunc_2 (43 B): matches/0x001aa710.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aa710@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aa710::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d0cc;
    base1_dtor_001a2f60();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aa740 fight::TrackFactoryCasterTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_1 (60 B): matches/0x001aa740.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aa740));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aa740* t = new (mem) TrackFactoryTemplate_1aa740();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aa780 fight::TrackFactoryTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_5 (27 B): matches/0x001aa780.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VNISAnimationTrack@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::TrackFactoryTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_5() {
    Track_1aa780* p = (Track_1aa780*)operator new(0x198);
    if (p)
        return (void*)(p->make_001a3240());
    return (void*)(0);
}

namespace fn_fc5dbd2a {

// 0x001aa7a0 fight::TrackFactoryTemplate<hulkfight::scenario::NISAnimationTrack>::vfunc_2 (43 B): matches/0x001aa7a0.cpp
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d0e8;
    base1_dtor();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aa8e0 hulkfight::scenario::NISAnimationAction::vfunc_3 (229 B): equivalent/0x001aa8e0.cpp [wrapped: conflict: DAT_004dd700; World; hulkfight::scenario::NISAnimationAction]
// sym: ?vfunc_3@NISAnimationAction@scenario@hulkfight@fn_001aa8e0@@UAE_NHH@Z @2274962e3c19 @wfe3f6b6b4a95
namespace fn_001aa8e0 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 16/16)
// hulkfight::scenario::NISAnimationAction::vfunc_3 @ 0x001aa8e0
struct Script_1aa8e0 { char pad[0x51]; unsigned char flag; };
struct Character_1aa8e0 { char pad[0xaf1]; unsigned char active; void FUN_00207b90(); };
struct Result_1aa8e0 { char pad[0xa8]; unsigned char flag; };
struct Manager_1aa8e0 { void FUN_0003dd00(int); Result_1aa8e0* FUN_00036a80(int); void FUN_0003b620(int); };
struct World { char pad[0x124]; Manager_1aa8e0* manager; };
struct Root_1aa8e0 { char pad[0x20]; World* world; };

#define DAT_004dd700 (*(Root_1aa8e0* *)&::DAT_004dd700)

extern "C++" __declspec(nothrow) const char * __cdecl FUN_001a4cb0(void *, unsigned int);
extern bool __cdecl FUN_001a4fd0(Script_1aa8e0*, int);
namespace hulkfight { namespace scenario {
struct NISAnimationAction {
virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual bool vfunc_3(int,int); virtual void vfunc_4(); virtual void vfunc_5();
char pad0[0x18]; Script_1aa8e0* script; void* enabled; char pad1[0x1e8]; Character_1aa8e0* character; char pad2[4]; unsigned char started;
bool FUN_001aa7d0();
};
bool NISAnimationAction::vfunc_3(int,int) {
if (!enabled) return false;
if (!character->active) { character->FUN_00207b90(); started=1; }
Manager_1aa8e0* manager=DAT_004dd700->world->manager;
if (manager) {
manager->FUN_0003dd00(1);
Script_1aa8e0* s=script;
int i;
for(i=0;i<20;++i) {
const char* name=FUN_001a4cb0((Script_1aa8e0 *)s,(int)i);
if(name) {
const char* expected="hulk";
int n=0;
while(n<5 && name[n]==expected[n]) ++n;
if(n==5) break;
}
}
if(i<20) {
if(FUN_001a4fd0(s,i)) manager->FUN_0003b620(1);
} else if(!s->flag) {
Result_1aa8e0* result=manager->FUN_00036a80(1);
result->flag=0;
}
}
return FUN_001aa7d0();
}
}}
} // namespace fn_001aa8e0
#undef DAT_004dd700


// 0x001aa9d0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_1 (60 B): matches/0x001aa9d0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_StringCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aa9d0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aa9d0* t = new (mem) TrackFactoryTemplate_1aa9d0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc5dbd2a {

// 0x001aaa40 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_StringCondition>::vfunc_2 (43 B): matches/0x001aaa40.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aaa40@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aaa40::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d10c;
    base1_dtor_001a2db0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aaa70 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_1 (60 B): matches/0x001aaa70.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_PropTypeCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aaa70));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aaa70* t = new (mem) TrackFactoryTemplate_1aaa70();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aaab0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_5 (48 B): matches/0x001aaab0.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_PropTypeCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_5() {
    Event_PropTypeCondition_1aaab0* p = (Event_PropTypeCondition_1aaab0*)FUN_0008d690(0x18);
    if (p) {
        p->Event_PropTypeCondition_1aaab0::Event_PropTypeCondition_1aaab0(0);
        *(void**)p = VT_1aaab0;
        p->sub.Init_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc5dbd2a {

// 0x001aaae0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropTypeCondition>::vfunc_2 (43 B): matches/0x001aaae0.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aaae0@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aaae0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d128;
    base1_dtor_001a2fc0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aab10 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_1 (60 B): matches/0x001aab10.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_PropStateNameCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aab10));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aab10* t = new (mem) TrackFactoryTemplate_1aab10();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aab50 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_5 (48 B): matches/0x001aab50.cpp
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_PropStateNameCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_5() {
    Event_1aab50* p = (Event_1aab50*)FUN_0008d690(0x18);
    if (p) {
        p->Init_00234590(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041c5b0);
        ((Tail_1aab50*)((char*)p + 0x10))->Run_0027af00();
        return (void*)(p);
    }
    return (void*)(0);
}

namespace fn_fc5dbd2a {

// 0x001aab80 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropStateNameCondition>::vfunc_2 (43 B): matches/0x001aab80.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aab80@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aab80::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d144;
    base1_dtor_001a3030();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aabb0 fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropNameCondition>::vfunc_1 (60 B): matches/0x001aabb0.cpp
// sym: ?vfunc_1@?$ConditionFactoryCasterTemplate@VEvent_PropNameCondition@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::ConditionFactoryCasterTemplate<hulkfight::scenario::Event_PropNameCondition>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aabb0));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aabb0* t = new (mem) TrackFactoryTemplate_1aabb0();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}

namespace fn_fc5dbd2a {

// 0x001aac20 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropNameCondition>::vfunc_2 (43 B): matches/0x001aac20.cpp
// sym: ?scalar_dtor@ConditionFactoryTemplate_1aac20@fn_fc5dbd2a@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* ConditionFactoryTemplate_1aac20::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d160;
    base1_dtor_001a30a0();
    base2_dtor_002343d0();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_fc5dbd2a

// 0x001aac50 fight::TrackFactoryCasterTemplate<hulkfight::scenario::EffectTrack>::vfunc_1 (60 B): matches/0x001aac50.cpp
// sym: ?vfunc_1@?$TrackFactoryCasterTemplate@VEffectTrack@scenario@hulkfight@@@fight@@UAEPAXPAX@Z
// Same code shape as 0x00122f30 (propagated; names are from that function)
template <> void* fight::TrackFactoryCasterTemplate<hulkfight::scenario::EffectTrack>::vfunc_1(void* __p0) { void * arg = (void *)__p0;

    void* mem = operator new(sizeof(TrackFactoryTemplate_1aac50));
    if (mem) {
        ((InitHelper*)mem)->init();
        TrackFactoryTemplate_1aac50* t = new (mem) TrackFactoryTemplate_1aac50();
        ((owners::Target_27b040 *)&(t->mTrack))->FUN_0027b040((hulk_uintptr)arg);
        postInit();
        return (void*)(t);
    }
    return (void*)(0);
}


// 0x001aac90 fight::TrackFactoryTemplate<hulkfight::scenario::EffectTrack>::vfunc_5 (24 B): matches/0x001aac90.cpp
// sym: ?vfunc_5@?$TrackFactoryTemplate@VEffectTrack@scenario@hulkfight@@@fight@@UAEPAXXZ
// Same code shape as 0x0006f460 (propagated; names are from that function)
template <> void* fight::TrackFactoryTemplate<hulkfight::scenario::EffectTrack>::vfunc_5() {
    void* p = FUN_0008d690(0x68);
    if (p)
        return (void*)(((Dummy_1aac90*)p)->FUN_001a3140());
    return (void*)(0);
}


// 0x001aacb0 fight::TrackFactoryTemplate<hulkfight::scenario::EffectTrack>::vfunc_2 (43 B): matches/0x001aacb0.cpp [wrapped: same definition as 0x001aa7a0 in this TU]
// sym: ?scalar_dtor@TrackFactoryTemplate@fn_001aacb0@@QAEPAXE@Z
namespace fn_001aacb0 {
// Same code shape as 0x0006fb50 (propagated; names are from that function)
extern int hulk_at_0041d17c;

struct TrackFactoryTemplate {
    void* m_vptr;
    void base1_dtor_001a3110();
    void base2_dtor_00236ab0();
    void* scalar_dtor(unsigned char flags);
};

void thunk_delete_00263f30(void*);

void* TrackFactoryTemplate::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&hulk_at_0041d17c;
    base1_dtor_001a3110();
    base2_dtor_00236ab0();
    if (flags & 1)
        thunk_delete_00263f30(this);
    return this;
}
} // namespace fn_001aacb0

