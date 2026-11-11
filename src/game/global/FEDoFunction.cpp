// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e1970..0x000e1b30 (kind game, layer game, confidence medium), dominant class FEDoFunction
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/unknown.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f701c7df {
#define TREE_TU_END }
namespace fn_f701c7df {} using namespace fn_f701c7df;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f701c7df {
class Obj_e19b0 {
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
    virtual void f49(void*);
};
struct Inner_e19b0 {
    int pad;
    Obj_e19b0* ptr;
};
struct FEDoAction_e19b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    char pad[0xc];
    Inner_e19b0* field;
};
class Obj_e1ad0 {
    char pad[0x3c];
    int* items;

  public:
    void Set(int index, int value);
};
extern int __cdecl Make(int value);
class FEDoAction_e1b00 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
};
class Check_e1b00 {
  public:
    virtual int Call(int, int);
};
class Obj_e1b00 {
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
    virtual void f48(int);
};
struct Holder_e1b00 {
    int x;
    Obj_e1b00* p;
};

} // namespace fn_f701c7df

// 0x000e1970 FUN_000e1970 (59 B): matches/0x000e1970.cpp [wrapped: conflict: FEDoSound]
// sym: ?Init@FEDoSound@fn_000e1970@@QAEPAV12@IPBD@Z
namespace fn_000e1970 {

extern "C" char DAT_0040c02c[];
typedef unsigned int u32_e1970;
class FEDoSound {
  public:
    hulk_intptr vtable;
    int pad4;
    int a;
    int b;
    int c;
    char flag;
    char pad15[0x1f];
    char name[0x20];
    FEDoSound* Init(hulk_uintptr, const char*);
};
extern void __cdecl FUN_000dfcc0(char*, int, const char*, ...);
FEDoSound* FEDoSound::Init(hulk_uintptr id, const char* soundName) {
    a = -1;
    b = -1;
    c = id;
    flag = 0;
    vtable = ((hulk_intptr)DAT_0040c02c);
    FUN_000dfcc0(name, 0x20, ((const char*)&DAT_003f3f38), soundName);
    return this;
}
} // namespace fn_000e1970


// 0x000e19b0 FEDoSound::vfunc_1 (21 B): matches/0x000e19b0.cpp
// sym: ?vfunc_1@FEDoSound@@UAEXXZ
void FEDoSound::vfunc_1() {
    (*(Inner_e19b0 * *)&this->f_10)->ptr->f49((char*)this + 0x34);
}


// 0x000e19d0 FUN_000e19d0 (136 B): equivalent/0x000e19d0.cpp [wrapped: conflict: FEDoFunction]
// sym: ??0FEDoFunction@fn_000e19d0@@QAE@PAUOwner_e19d0@1@HH@Z
namespace fn_000e19d0 {
// STATUS: equivalent (tools/equiv.py level 3: 226 inputs, branch coverage 10/10)
// FUN_000e19d0 @ 0x000e19d0
struct Tbl_e19d0 { void* FUN_000df970(int id); };
struct Reg_e19d0 { char pad[4]; Tbl_e19d0* tbl; };
struct Owner_e19d0 { char pad[4]; Reg_e19d0* reg; };
extern "C" void* __cdecl FUN_0008d6d0(unsigned size);
struct FEDoFunction {
 virtual void slot0();
 int pad4; int v8, vc;
 Owner_e19d0* owner;
 char v14;
 char pad[0x34 - 0x15];
 void* fn; int count; int* table;
 FEDoFunction(Owner_e19d0* o, hulk_intptr id, int n);
};
FEDoFunction::FEDoFunction(Owner_e19d0* o, hulk_intptr id, int n) {
 v8 = -1;
 vc = -1;
 owner = o;
 v14 = 0;
 count = n;
 table = 0;
 fn = o->reg->tbl->FUN_000df970(id);
 if (fn) {
  if (count > 0) {
   table = (int*)FUN_0008d6d0(count * 4);
   if (!table) return;
  }
  for (int i = 0; i < count; i++) table[i] = 0;
 }
}
} // namespace fn_000e19d0


// 0x000e1a60 FUN_000e1a60 (101 B): matches/0x000e1a60.cpp [wrapped: conflict: FEDoFunction]
// sym: ??1FEDoFunction@fn_000e1a60@@QAE@XZ
namespace fn_000e1a60 {
extern int vtFunction;
extern int vtAction;
extern void __cdecl thunk_FUN_00267090(void*);
class FEDoFunction {
  public:
    hulk_intptr vptr;
    int pad[13];
    int count;
    void** items;
    ~FEDoFunction();
};
FEDoFunction::~FEDoFunction() {
    vptr = (hulk_intptr)&vtFunction;
    if (items) {
        int i = 0;
        if (count > 0)
            do {
                void* p = items[i];
                if (p) {
                    thunk_FUN_00267090(p);
                    items[i] = 0;
                }
                ++i;
            } while (i < count);
        if (items) {
            thunk_FUN_00267090(items);
            items = 0;
        }
    }
    vptr = (hulk_intptr)&vtAction;
}
} // namespace fn_000e1a60

namespace fn_f701c7df {

// 0x000e1ad0 FUN_000e1ad0 (37 B): matches/0x000e1ad0.cpp
// sym: ?Set@Obj_e1ad0@fn_f701c7df@@QAEXHH@Z
void Obj_e1ad0::Set(int index, int value) {
    if (items)
        items[index] = Make(value);
}

} // namespace fn_f701c7df

// 0x000e1b00 FEDoFunction::vfunc_1 (46 B): matches/0x000e1b00.cpp
// sym: ?vfunc_1@FEDoFunction@@UAEXXZ
void FEDoFunction::vfunc_1() {
    if ((*(Check_e1b00 * *)&this->f_34) && (*(Check_e1b00 * *)&this->f_34)->Call(this->f_38, this->f_3c))
        (*(Holder_e1b00 * *)&this->f_10)->p->f48(7);
}

