// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000fb830..0x000fc460 (kind game, layer game, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f5c759cd {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f5c759cd {} using namespace fn_f5c759cd;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f5c759cd {
struct Measurer_fb830 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual float MeasureWidth(const unsigned short* text);
};
struct Settings_fb830 {
    char pad[0x10c];
    int mode;
};
Settings_fb830* __cdecl FUN_000fc1b0();
typedef unsigned int U_fc000;
extern void FUN_000fbc00(hulk_uintptr, U_fc000, hulk_uintptr, U_fc000*);
typedef unsigned int U_fc020;
hulk_intptr FUN_000fbe00(unsigned short* buf, unsigned int count, const unsigned short* fmt, char* ap);
extern "C" void* __cdecl FUN_0008d690(unsigned int size);
} // namespace fn_f5c759cd
inline void* operator new(size_t, void* p) throw() { return p; }
namespace fn_f5c759cd {
class FEThings_fc060;
class ControllerPoller_fc060 {
public:
    ControllerPoller_fc060(int a, FEThings_fc060* mgr) throw();
    virtual void v0();
};
class FEThings_fc060 {
public:
    FEThings_fc060(int a) throw();
    char pad0[0x182c];
    ControllerPoller_fc060* overlay;
    void FUN_000dddc0(int a, int b);
};
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
extern void __fastcall FUN_000dd970(void*);
extern void thunk_FUN_00267090(CCollisionAction*);
typedef unsigned int u32_fc100;
struct Obj_fc100 {
    void F5(u32_fc100, u32_fc100);
    void F0(u32_fc100);
};
struct Obj_fc130 {
    void f(unsigned int);
};
class C_fc150 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};
class C_fc160 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
};
struct X_fc170 {
    void A(int);
    void B(int);
};
struct Obj_fc1a0 {
    void Target();
};
struct Obj_fc1c0 {
    int f(unsigned int);
};
struct Inner_fc1e0 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc1e0 {
    int pad;
    Inner_fc1e0* field;
};
struct Inner_fc200 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc200 {
    int pad;
    Inner_fc200* field;
};
struct Inner_fc220 {
    void run(unsigned int, unsigned int);
};
struct Obj_fc220 {
    int pad;
    Inner_fc220* field;
};
struct Obj_fc260 {
    int f(unsigned int);
};
struct Global_fc280 {
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
    virtual void f14(int);
};
class C_fc2e0 {
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
};
class X_fc2f0 {
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
};
struct Obj_fc300 {
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
};
struct S_fc310 {
    char pad[0x175c];
    int value;
};
struct Obj_fc330 {
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
};
class GlobalThing_fc340 {
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
    virtual void v26(int);
};
class Obj_fc3a0 {
  public:
    void Fn(int x);
};
class ControllerPoller_fc3e0 {
  public:
    void Close();
};
class Second {
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
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void Use(int);
};
extern "C" void __cdecl FreeFirst(ControllerPoller_fc3e0*);


// 0x000fb830 FUN_000fb830 (466 B): equivalent/0x000fb830.cpp
// sym: _FUN_000fb830
// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 39/46, incomplete)
// FUN_000fb830 @ 0x000fb830
extern "C" int FUN_000fb830(unsigned short* out, int bufSize, const unsigned short* in, float maxWidth, Measurer_fb830* m) {
    if (bufSize == 2) return 1;
    const unsigned short* breakChars = (FUN_000fc1b0()->mode == 3) ? (const unsigned short*)L"):-\x200b\x3000\x3001\x3002\x3006\x3009\x300b\x300d\x300f\x3011\x3015\x3017\x3019\x301b\x3092\x30fb\xff01\xff09\xff1a\xff1f\xff61\xff64" : (const unsigned short*)L"-";
    unsigned short* cur = out;
    unsigned short* breakOut = 0;
    const unsigned short* breakIn = 0;
    unsigned short* lineStart = out;
    int lines = 1;
    *cur = 0;
    if (*in == 0) { *cur = 0; return lines; }
    unsigned int limit = bufSize - 4;
    for (;;) {
        if ((unsigned int)(cur - out) >= limit) break;
        unsigned short c = *in;
        if (c == 0) break;
        *cur = c;
        unsigned short* next = cur + 1;
        *next = 0;
        if (in[1] == 0) { cur = next; break; }
        if (*in == '\n') {
            breakOut = 0;
            breakIn = 0;
            lines++;
            lineStart = next;
        } else {
            if (m->MeasureWidth(lineStart) < maxWidth || breakOut == 0) {
                unsigned short d = *in;
                if (d == ' ' || d == 0x200b) {
                    breakOut = cur;
                    breakIn = in;
                } else {
                    for (const unsigned short* p = breakChars; *p != 0; p++) {
                        if (d == *p) {
                            breakOut = next;
                            breakIn = in;
                            break;
                        }
                    }
                }
            }
            if (!(m->MeasureWidth(lineStart) < maxWidth) && breakOut != 0) {
                while (breakOut > out && breakOut[-1] == ' ') breakOut--;
                lineStart = breakOut + 1;
                breakOut[1] = 0;
                breakOut[0] = '\n';
                cur = breakOut;
                in = breakIn;
                const unsigned short* p = breakIn + 1;
                while (*p == ' ') {
                    in = p;
                    p++;
                }
                lines++;
                breakOut = 0;
                breakIn = 0;
            }
        }
        in++;
        cur++;
        if (*in == 0) { *cur = 0; return lines; }
    }
    *cur = 0;
    return lines;
}

} // namespace fn_f5c759cd

// 0x000fba10 FUN_000fba10 (492 B): equivalent/0x000fba10.cpp [wrapped: conflict: FUN_000fc1b0]
// sym: _FUN_000fba10
namespace fn_000fba10 {
// STATUS: equivalent (tools/equiv.py level 3: 160 inputs, branch coverage 48/50, incomplete)
// FUN_000fba10 @ 0x000fba10

typedef unsigned short wc;

class Measurer_fba10 {
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
    virtual float measure(const wc *text);
};

struct Manager_fba10 {
    char pad[0x10c];
    int language;
};
Manager_fba10 *__cdecl FUN_000fc1b0();

extern "C" int __cdecl FUN_000fba10(wc **lines, int maxLines, int maxChars, const wc *src, float maxWidth,
                         Measurer_fba10 *m)
{
    if (maxChars == 2)
        return 1;

    const wc *breakSet = (FUN_000fc1b0()->language == 3) ? ((const wc*)&DAT_0040cf14) : ((const wc*)&DAT_0040cf10);
    wc *dst = lines[0];
    const wc *brkSrc = 0;
    wc *brkDst = 0;
    int line = 1;
    *dst = 0;
    wc *lineStart = dst;

    while (*src != 0) {
        bool newLine = false;
        if (line > maxLines)
            break;
        if ((unsigned)(dst - lines[line - 1]) >= (unsigned)(maxChars - 4))
            break;
        wc c = *src;
        if (c == 0)
            break;
        *dst = c;
        dst[1] = 0;
        if (src[1] == 0) {
            dst++;
            break;
        }
        if (*src == 0xa) {
            *dst = 0;
            dst = lines[line];
            brkDst = 0;
            brkSrc = 0;
            line++;
            lineStart = dst;
            newLine = true;
        } else {
            if (m->measure(lineStart) < maxWidth || brkDst == 0) {
                wc ch = *src;
                if (ch == 0x20 || ch == 0x200b) {
                    brkDst = dst;
                    brkSrc = src;
                } else {
                    for (const wc *b = breakSet; *b != 0; b++) {
                        if (ch == *b) {
                            brkDst = dst + 1;
                            brkSrc = src;
                            break;
                        }
                    }
                }
            }
            if (m->measure(lineStart) >= maxWidth && brkDst != 0) {
                wc *start = lines[line - 1];
                wc *e = brkDst;
                while (e > start && e[-1] == 0x20)
                    e--;
                *e = 0;
                *dst = 0;
                dst = lines[line];
                src = brkSrc;
                const wc *q = brkSrc + 1;
                wc cx = *q;
                while (cx != 0 && cx == 0x20) {
                    src = q;
                    cx = src[1];
                    q = src + 1;
                }
                lineStart = dst;
                brkDst = 0;
                brkSrc = 0;
                line++;
                newLine = true;
            }
        }
        src++;
        if (!newLine)
            dst++;
    }
    *dst = 0;
    return line;
}
} // namespace fn_000fba10

namespace fn_f5c759cd {

// 0x000fc000 FUN_000fc000 (29 B): matches/0x000fc000.cpp
// sym: _FUN_000fc000
extern "C" void FUN_000fc000(hulk_uintptr a, U_fc000 b, hulk_uintptr c, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, c);
    FUN_000fbc00(a, b, c, (U_fc000*)args);
#else
    FUN_000fbc00(a, b, c, (&c) + 1);
#endif
}


// 0x000fc020 FUN_000fc020 (29 B): matches/0x000fc020.cpp
// sym: _FUN_000fc020
// Same code shape as 0x000fc000 (propagated); the wide variant: it calls the wide formatter 0x000fbe00
extern "C" void FUN_000fc020(hulk_uintptr a, U_fc020 b, hulk_uintptr c, ...) {
#if defined(HULK_PTR64)
    __builtin_va_list args;
    __builtin_va_start(args, c);
    FUN_000fbe00((unsigned short*)a, b, (const unsigned short*)c, (char*)args);
#else
    FUN_000fbe00((unsigned short*)a, b, (const unsigned short*)c, (char*)((&c) + 1));
#endif
}


// 0x000fc060 FUN_000fc060 (121 B): equivalent/0x000fc060.cpp
// sym: _FUN_000fc060
// STATUS: equivalent (tools/equiv.py level 3: 19802 inputs, branch coverage 4/4)
// FUN_000fc060 @ 0x000fc060
// equiv-map: ??0Manager@@QAE@H@Z = 0x000ddbf0
// equiv-map: ??0Overlay@@QAE@HPAVManager@@@Z = 0x000dd940
extern "C" void FUN_000fc060(int a1, int a2, int a3, int a4) {
    void* mem = FUN_0008d690(0x223c);
    FEThings_fc060* mgr = 0;
    if (mem)
        mgr = new (mem) FEThings_fc060(a4);
    (*(FEThings_fc060**)&DAT_004e0a60) = mgr;
    mgr->FUN_000dddc0(a1, a3);
    void* mem2 = FUN_0008d690(0x3c);
    ControllerPoller_fc060* ov = 0;
    if (mem2)
        ov = new (mem2) ControllerPoller_fc060(a2, (*(FEThings_fc060**)&DAT_004e0a60));
    (*(ControllerPoller_fc060**)&DAT_004e0a64) = ov;
    ov->v0();
    (*(FEThings_fc060**)&DAT_004e0a60)->overlay = (*(ControllerPoller_fc060**)&DAT_004e0a64);
}


// 0x000fc0e0 FUN_000fc0e0 (30 B): matches/0x000fc0e0.cpp
// sym: ?vfunc_2@CCollisionAction@fn_f5c759cd@@UAEPAV12@E@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
CCollisionAction* CCollisionAction::vfunc_2(unsigned char flags) {
    FUN_000dd970((void*)(this));
    if ((flags & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}


// 0x000fc100 FUN_000fc100 (36 B): matches/0x000fc100.cpp
// sym: _FUN_000fc100
extern "C" void FUN_000fc100(u32_fc100 a, u32_fc100 b) {
    (*(Obj_fc100**)&DAT_004e0a60)->F5(a, b);
    (*(Obj_fc100**)&DAT_004e0a60)->F0(a);
}


// 0x000fc130 FUN_000fc130 (17 B): matches/0x000fc130.cpp
// sym: _FUN_000fc130
// data: gObject_fc130 = DAT_004e0a60
extern "C" void __cdecl FUN_000fc130(unsigned int value) {
    (*(Obj_fc130**)&DAT_004e0a60)->f(value);
}


// 0x000fc150 FUN_000fc150 (11 B): matches/0x000fc150.cpp
// sym: _FUN_000fc150
extern "C" void FUN_000fc150() {
    (*(C_fc150**)&DAT_004e0a60)->f5();
}


// 0x000fc160 FUN_000fc160 (11 B): matches/0x000fc160.cpp
// sym: _FUN_000fc160
extern "C" void FUN_000fc160() {
    (*(C_fc160**)&DAT_004e0a60)->e();
}


// 0x000fc170 FUN_000fc170 (40 B): matches/0x000fc170.cpp
// sym: _FUN_000fc170
extern "C" void __cdecl FUN_000fc170(int value) {
    (*(X_fc170**)&DAT_004e0a64)->A(0);
    (*(X_fc170**)&DAT_004e0a60)->B(value);
    ((owners::Obj_de1d0 *)((*(X_fc170**)&DAT_004e0a64)))->FUN_000de1d0();
}


// 0x000fc1a0 FUN_000fc1a0 (11 B): matches/0x000fc1a0.cpp
// sym: _FUN_000fc1a0
// data: g_object_fc1a0 = DAT_004e0a60
extern "C" void __cdecl FUN_000fc1a0(void) {
    (*(Obj_fc1a0**)&DAT_004e0a60)->Target();
}

} // namespace fn_f5c759cd

// 0x000fc1b0 FUN_000fc1b0 (14 B): matches/0x000fc1b0.cpp [wrapped: conflict: FUN_000fc1b0]
// sym: ?FUN_000fc1b0@fn_000fc1b0@@YAHXZ
namespace fn_000fc1b0 {

class A_fc1b0 {
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
    virtual int f44();
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
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80();
    virtual void f81();
    virtual void f82();
    virtual void f83();
    virtual void f84();
    virtual void f85();
    virtual void f86();
    virtual void f87();
    virtual void f88();
    virtual void f89();
    virtual void f90();
    virtual void f91();
    virtual void f92();
    virtual void f93();
    virtual void f94();
    virtual void f95();
    virtual void f96();
    virtual void f97();
    virtual void f98();
    virtual void f99();
    virtual void f100();
    virtual void f101();
    virtual void f102();
    virtual void f103();
    virtual void f104();
    virtual void f105();
    virtual void f106();
    virtual void f107();
    virtual void f108();
    virtual void f109();
    virtual void f110();
    virtual void f111();
    virtual void f112();
    virtual void f113();
    virtual void f114();
    virtual void f115();
    virtual void f116();
    virtual void f117();
    virtual void f118();
    virtual void f119();
    virtual void f120();
    virtual void f121();
    virtual void f122();
    virtual void f123();
    virtual void f124();
    virtual void f125();
    virtual void f126();
    virtual void f127();
    virtual void f128();
    virtual void f129();
    virtual void f130();
    virtual void f131();
    virtual void f132();
    virtual void f133();
    virtual void f134();
    virtual void f135();
    virtual void f136();
    virtual void f137();
    virtual void f138();
    virtual void f139();
    virtual void f140();
    virtual void f141();
    virtual void f142();
    virtual void f143();
    virtual void f144();
    virtual void f145();
    virtual void f146();
    virtual void f147();
    virtual void f148();
    virtual void f149();
    virtual void f150();
    virtual void f151();
    virtual void f152();
    virtual void f153();
    virtual void f154();
    virtual void f155();
    virtual void f156();
    virtual void f157();
    virtual void f158();
    virtual void f159();
    virtual void f160();
    virtual void f161();
    virtual void f162();
    virtual void f163();
    virtual void f164();
    virtual void f165();
    virtual void f166();
    virtual void f167();
    virtual void f168();
    virtual void f169();
    virtual void f170();
    virtual void f171();
    virtual void f172();
    virtual void f173();
    virtual void f174();
    virtual void f175();
    virtual void f176();
};
hulk_intptr FUN_000fc1b0() {
    return (*(A_fc1b0**)&DAT_004e0a60)->f44();
}
} // namespace fn_000fc1b0

namespace fn_f5c759cd {

// 0x000fc1c0 FUN_000fc1c0 (17 B): matches/0x000fc1c0.cpp
// sym: _FUN_000fc1c0
// Same code shape as 0x000fc130 (propagated; names are from that function)
// data: gObject_fc1c0 = DAT_004e0a60
extern "C" int __cdecl FUN_000fc1c0(unsigned int value) {
    return (*(Obj_fc1c0**)&DAT_004e0a60)->f(value);
}


// 0x000fc1e0 FUN_000fc1e0 (32 B): matches/0x000fc1e0.cpp
// sym: _FUN_000fc1e0
// data: g_flag_fc1e0 = DAT_004e0a68, g_obj_fc1e0 = DAT_004e0a60
extern "C" void FUN_000fc1e0(unsigned int a, unsigned int b) {
    (*(Obj_fc1e0**)&DAT_004e0a60)->field->run(a, b);
    (*(unsigned char*)&DAT_004e0a68) = 1;
}


// 0x000fc200 FUN_000fc200 (32 B): matches/0x000fc200.cpp
// sym: _FUN_000fc200
// Same code shape as 0x000fc1e0 (propagated; names are from that function)
// data: g_flag_fc200 = DAT_004e0a68, g_obj_fc200 = DAT_004e0a60
extern "C" void FUN_000fc200(unsigned int a, unsigned int b) {
    (*(Obj_fc200**)&DAT_004e0a60)->field->run(a, b);
    (*(unsigned char*)&DAT_004e0a68) = 1;
}


// 0x000fc220 FUN_000fc220 (32 B): matches/0x000fc220.cpp
// sym: _FUN_000fc220
// Same code shape as 0x000fc1e0 (propagated; names are from that function)
// data: g_flag_fc220 = DAT_004e0a68, g_obj_fc220 = DAT_004e0a60
extern "C" void FUN_000fc220(unsigned int a, unsigned int b) {
    (*(Obj_fc220**)&DAT_004e0a60)->field->run(a, b);
    (*(unsigned char*)&DAT_004e0a68) = 1;
}


// 0x000fc260 FUN_000fc260 (17 B): matches/0x000fc260.cpp
// sym: _FUN_000fc260
// Same code shape as 0x000fc130 (propagated; names are from that function)
// data: gObject_fc260 = DAT_004e0a60
extern "C" hulk_intptr __cdecl FUN_000fc260(hulk_uintptr value) {
    return (*(Obj_fc260**)&DAT_004e0a60)->f(value);
}


// 0x000fc280 FUN_000fc280 (17 B): matches/0x000fc280.cpp
// sym: _FUN_000fc280
extern "C" void FUN_000fc280(int x) {
    (*(Global_fc280**)&DAT_004e0a60)->f14(x);
}


// 0x000fc2e0 FUN_000fc2e0 (11 B): matches/0x000fc2e0.cpp
// sym: _FUN_000fc2e0
extern "C" void FUN_000fc2e0() {
    (*(C_fc2e0**)&DAT_004e0a60)->f20();
}


// 0x000fc2f0 FUN_000fc2f0 (11 B): matches/0x000fc2f0.cpp
// sym: _FUN_000fc2f0
extern "C" void __cdecl FUN_000fc2f0() {
    ((X_fc2f0*)*(hulk_uintptr*)((hulk_intptr)DAT_004e0a60))->f21();
}


// 0x000fc300 FUN_000fc300 (11 B): matches/0x000fc300.cpp
// sym: _FUN_000fc300
extern "C" void FUN_000fc300() {
    (*(Obj_fc300**)&DAT_004e0a60)->f23();
}


// 0x000fc310 FUN_000fc310 (12 B): matches/0x000fc310.cpp
// sym: _FUN_000fc310
extern "C" int FUN_000fc310() {
    return (*(S_fc310**)&DAT_004e0a60)->value;
}


// 0x000fc320 FUN_000fc320 (12 B): matches/0x000fc320.cpp
// sym: _FUN_000fc320
// data: g_data_fc320 = DAT_004e0a60
extern "C" int FUN_000fc320() {
    return *(int*)((char*)(*(int**)&DAT_004e0a60) + 0x1768);
}


// 0x000fc330 FUN_000fc330 (11 B): matches/0x000fc330.cpp
// sym: _FUN_000fc330
extern "C" void FUN_000fc330() {
    (*(Obj_fc330**)&DAT_004e0a60)->f24();
}


// 0x000fc340 FUN_000fc340 (17 B): matches/0x000fc340.cpp
// sym: _FUN_000fc340
// data: gThing_fc340 = DAT_004e0a60
extern "C" void FUN_000fc340(int a) {
    (*(GlobalThing_fc340**)&DAT_004e0a60)->v26(a);
}


// 0x000fc3a0 FUN_000fc3a0 (17 B): matches/0x000fc3a0.cpp
// sym: ?FUN_000fc3a0@fn_f5c759cd@@YAXH@Z
// data: g_obj_fc3a0 = DAT_004e0a60
void FUN_000fc3a0(int x) {
    (*(Obj_fc3a0**)&DAT_004e0a60)->Fn(x);
}


// 0x000fc3d0 FUN_000fc3d0 (6 B): matches/0x000fc3d0.cpp
// sym: _FUN_000fc3d0
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" hulk_intptr FUN_000fc3d0(void) {
    return (hulk_intptr)DAT_004e0a60[0];
}


// 0x000fc3e0 FUN_000fc3e0 (69 B): matches/0x000fc3e0.cpp
// sym: _FUN_000fc3e0
// data: gFirst = DAT_004e0a64, gSecond = DAT_004e0a60
extern "C" void FUN_000fc3e0() {
    if ((*(ControllerPoller_fc3e0**)&DAT_004e0a64)) {
        ControllerPoller_fc3e0* p = (*(ControllerPoller_fc3e0**)&DAT_004e0a64);
        (*(ControllerPoller_fc3e0**)&DAT_004e0a64)->Close();
        FreeFirst(p);
        (*(ControllerPoller_fc3e0**)&DAT_004e0a64) = 0;
    }
    if ((*(Second**)&DAT_004e0a60)) {
        (*(Second**)&DAT_004e0a60)->Use(1);
        (*(Second**)&DAT_004e0a60) = 0;
    }
}

} // namespace fn_f5c759cd
