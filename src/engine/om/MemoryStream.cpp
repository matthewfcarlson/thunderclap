// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00247220..0x00247310 (kind game, layer engine, confidence medium), dominant class om::MemoryStream
#include "tree_prelude.h"
#include "compat/ptr.h"
#define TREE_TU_BEGIN namespace fn_f22e0a19 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f22e0a19 {} using namespace fn_f22e0a19;
#include "engine/om.h"

// ---- declarations shared by the functions below
namespace fn_f22e0a19 {
extern "C" void __cdecl FUN_002469e0();
extern "C" void __cdecl FUN_002469f0();
extern "C" void __cdecl FUN_00246a10();
extern "C" void __cdecl FUN_00246a40();
extern "C" void __cdecl FUN_00246a60();
extern "C" char DAT_0042921c[];
struct Base_247220 {
    virtual void F();
};
class ContentStream {
  public:
    hulk_uintptr vptr, a, b, c, d, e;
    unsigned char flag;
    unsigned char pad[3];
    Base_247220* source;
    ContentStream* Make(Base_247220*);
};
extern "C" void __cdecl FUN_00246ab0();
extern "C" void __cdecl FUN_00246b00();
extern "C" void __cdecl FUN_00246b50();
extern "C" void __cdecl FUN_00246b70();
extern "C" void __cdecl FUN_00246b90();
extern "C" char DAT_00429224[];
class MemoryStream {
  public:
    hulk_intptr vp;
    void (*p1)();
    void (*p2)();
    void (*p3)();
    void (*p4)();
    void (*p5)();
    unsigned char b18;
    char pad[3];
    int x1;
    int x2;
    int x3;
    unsigned char flag;
    MemoryStream(int a, int b, unsigned char c);
};
class Stream_2472c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public Stream_2472c0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x00247220 FUN_00247220 (65 B): matches/0x00247220.cpp
// sym: ?Make@ContentStream@fn_f22e0a19@@QAEPAV12@PAUBase_247220@2@@Z
ContentStream* ContentStream::Make(Base_247220* arg) {
    a = ((hulk_intptr)(void (__cdecl*)())&FUN_002469e0);
    b = ((hulk_intptr)(void (__cdecl*)())&FUN_002469f0);
    c = ((hulk_intptr)(void (__cdecl*)())&FUN_00246a10);
    d = ((hulk_intptr)(void (__cdecl*)())&FUN_00246a40);
    e = ((hulk_intptr)(void (__cdecl*)())&FUN_00246a60);
    flag = 0;
    vptr = ((hulk_intptr)DAT_0042921c);
    source = arg;
    arg->F();
    return this;
}


// 0x00247270 FUN_00247270 (74 B): matches/0x00247270.cpp
// sym: ??0MemoryStream@fn_f22e0a19@@QAE@HHE@Z
MemoryStream::MemoryStream(int a, int b, unsigned char c) {
    x1 = b;
    p1 = FUN_00246ab0;
    p2 = FUN_00246b00;
    p3 = FUN_00246b50;
    p4 = FUN_00246b70;
    p5 = FUN_00246b90;
    b18 = 0;
    vp = ((hulk_intptr)DAT_00429224);
    x2 = a;
    x3 = a;
    flag = c;
}


// 0x002472c0 om::MemoryStream::vfunc_0 (31 B): matches/0x002472c0.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f22e0a19@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f22e0a19
