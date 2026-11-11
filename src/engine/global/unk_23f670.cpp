// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0023f670..0x0023fa40 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c4408d {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f9c4408d {} using namespace fn_f9c4408d;
#include "common.h"

// ---- declarations shared by the functions below
namespace fn_f9c4408d {
class A_23f670 {
  public:
    int a;
    int b;
};
class Target_23f6b0 {
  public:
    int pad;
    int value;
};
class C_23f6c0 {
  public:
    int pad;
    int value;
};
class ParamValue {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual unsigned char vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
};
class FEControl {
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
    virtual bool vfunc_10(hulk_intptr, hulk_intptr);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
};
class Entity {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual bool vfunc_4(hulk_intptr a);
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
};
class CAgent {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7(int a);
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
};
typedef unsigned int u32_23f790;
class CGameCamera {
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
    virtual void vfunc_33(hulk_intptr, int, int);
};
class C_23f990 {
  public:
    char pad[8];
    unsigned short value;
};


// 0x0023f670 FUN_0023f670 (16 B): matches/0x0023f670.cpp
// sym: ?FUN_0023f670@fn_f9c4408d@@YIPAVA_23f670@1@PAV21@@Z
A_23f670* __fastcall FUN_0023f670(A_23f670* self) {
    self->a = 0;
    self->b = 0;
    return self;
}

} // namespace fn_f9c4408d

// 0x0023f690 FUN_0023f690 (9 B): matches/0x0023f690.cpp
// sym: ?FUN_0023f690@C_23f690@owners@@QAEXH@Z
void owners::C_23f690::FUN_0023f690(hulk_intptr v) {
    x = ((int)v);
}

namespace fn_f9c4408d {

// 0x0023f6b0 FUN_0023f6b0 (8 B): matches/0x0023f6b0.cpp
// sym: ?TargetFn@fn_f9c4408d@@YIXPAVTarget_23f6b0@1@@Z
void __fastcall TargetFn(Target_23f6b0* self) {
    self->value = 1;
}


// 0x0023f6c0 FUN_0023f6c0 (8 B): matches/0x0023f6c0.cpp
// sym: ?Target@fn_f9c4408d@@YIXPAVC_23f6c0@1@@Z
void __fastcall Target(C_23f6c0* self) {
    self->value = 0;
}


// 0x0023f6d0 FUN_0023f6d0 (1 B): matches/0x0023f6d0.cpp
// sym: ?FUN_0023f6d0@fn_f9c4408d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0023f6d0() {}


// 0x0023f6e0 FUN_0023f6e0 (1 B): matches/0x0023f6e0.cpp
// sym: ?FUN_0023f6e0@fn_f9c4408d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0023f6e0() {}


// 0x0023f6f0 FUN_0023f6f0 (1 B): matches/0x0023f6f0.cpp
// sym: ?FUN_0023f6f0@fn_f9c4408d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0023f6f0() {}


// 0x0023f700 FUN_0023f700 (1 B): matches/0x0023f700.cpp
// sym: ?FUN_0023f700@fn_f9c4408d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0023f700() {}


// 0x0023f710 FUN_0023f710 (3 B): matches/0x0023f710.cpp
// sym: ?vfunc_2@ParamValue@fn_f9c4408d@@UAEEXZ
// Same code shape as 0x00050220 (propagated; names are from that function)
unsigned char ParamValue::vfunc_2() {
    return 0;
}


// 0x0023f720 FUN_0023f720 (5 B): matches/0x0023f720.cpp
// sym: ?vfunc_10@FEControl@fn_f9c4408d@@UAE_NHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
bool FEControl::vfunc_10(hulk_intptr, hulk_intptr) {
    return false;
}


// 0x0023f730 FUN_0023f730 (5 B): matches/0x0023f730.cpp
// sym: ?vfunc_4@Entity@fn_f9c4408d@@UAE_NH@Z
// Same code shape as 0x00244f40 (propagated; names are from that function)
bool Entity::vfunc_4(hulk_intptr a) {
    return false;
}


// 0x0023f740 FUN_0023f740 (1 B): matches/0x0023f740.cpp
// sym: ?FUN_0023f740@fn_f9c4408d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0023f740() {}


// 0x0023f750 FUN_0023f750 (3 B): matches/0x0023f750.cpp
// sym: ?vfunc_7@CAgent@fn_f9c4408d@@UAEXH@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void CAgent::vfunc_7(int a) {
    (void)a;
}


// 0x0023f760 FUN_0023f760 (7 B): matches/0x0023f760.cpp
// sym: ?FUN_0023f760@fn_f9c4408d@@YGEIIE@Z
unsigned char __stdcall FUN_0023f760(unsigned int unused1, unsigned int unused2, unsigned char value) {
    return value;
}

} // namespace fn_f9c4408d

// 0x0023f770 FUN_0023f770 (5 B): matches/0x0023f770.cpp [wrapped: same definition as 0x0023f720 in this TU]
// sym: ?vfunc_10@FEControl@fn_0023f770@@UAE_NHH@Z
namespace fn_0023f770 {
// Same code shape as 0x000d7a40 (propagated; names are from that function)
class FEControl {
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
    virtual bool vfunc_10(hulk_intptr, int);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
};
bool FEControl::vfunc_10(hulk_intptr, int) {
    return false;
}
} // namespace fn_0023f770

namespace fn_f9c4408d {

// 0x0023f790 FUN_0023f790 (7 B): matches/0x0023f790.cpp
// sym: ?FUN_0023f790@fn_f9c4408d@@YGIIIIII@Z
u32_23f790 __stdcall FUN_0023f790(u32_23f790 a, u32_23f790 b, u32_23f790 c, u32_23f790 d, u32_23f790 e) {
    return e;
}


// 0x0023f7b0 FUN_0023f7b0 (3 B): matches/0x0023f7b0.cpp
// sym: ?FUN_0023f7b0@fn_f9c4408d@@YGXPAX000@Z
void __stdcall FUN_0023f7b0(void*, void*, void*, void*) {}


// 0x0023f7d0 FUN_0023f7d0 (3 B): matches/0x0023f7d0.cpp
// sym: ?FUN_0023f7d0@fn_f9c4408d@@YGXPAX000@Z
// Same code shape as 0x0023f7b0 (propagated; names are from that function)
void __stdcall FUN_0023f7d0(void*, void*, void*, void*) {}


// 0x0023f820 FUN_0023f820 (3 B): matches/0x0023f820.cpp
// sym: ?FUN_0023f820@fn_f9c4408d@@YGXPAX000@Z
// Same code shape as 0x0023f7b0 (propagated; names are from that function)
void __stdcall FUN_0023f820(void*, void*, void*, void*) {}


// 0x0023f890 FUN_0023f890 (3 B): matches/0x0023f890.cpp
// sym: ?FUN_0023f890@fn_f9c4408d@@YGXPAX000@Z
// Same code shape as 0x0023f7b0 (propagated; names are from that function)
void __stdcall FUN_0023f890(void*, void*, void*, void*) {}


// 0x0023f8a0 FUN_0023f8a0 (3 B): matches/0x0023f8a0.cpp
// sym: ?vfunc_33@CGameCamera@fn_f9c4408d@@UAEXHHH@Z
// Same code shape as 0x00098430 (propagated; names are from that function)
void CGameCamera::vfunc_33(hulk_intptr, int, int) {}


// 0x0023f8b0 FUN_0023f8b0 (3 B): matches/0x0023f8b0.cpp
// sym: ?FUN_0023f8b0@fn_f9c4408d@@YGXPAX000@Z
// Same code shape as 0x0023f7b0 (propagated; names are from that function)
void __stdcall FUN_0023f8b0(void*, void*, void*, void*) {}


// 0x0023f8c0 FUN_0023f8c0 (1 B): matches/0x0023f8c0.cpp
// sym: _FUN_0023f8c0
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_0023f8c0() {}


// 0x0023f8f0 FUN_0023f8f0 (1 B): matches/0x0023f8f0.cpp
// sym: ?FUN_0023f8f0@fn_f9c4408d@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_0023f8f0() {}


// 0x0023f990 FUN_0023f990 (5 B): matches/0x0023f990.cpp
// sym: ?FUN_0023f990@fn_f9c4408d@@YIIPAVC_23f990@1@@Z
unsigned int __fastcall FUN_0023f990(C_23f990* self) {
    return self->value;
}

} // namespace fn_f9c4408d
