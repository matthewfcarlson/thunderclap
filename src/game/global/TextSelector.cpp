// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000e2ec0..0x000e36a0 (kind game, layer game, confidence high), dominant class TextSelector
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f3398797 {
#define TREE_TU_END }
namespace fn_f3398797 {} using namespace fn_f3398797;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f3398797 {
class W_e2f80 {
  public:
    char p[8];
};
class Z {
  public:
    char p[8];
    W_e2f80* w;
};
class Y_e2f80 {
  public:
    char p[4];
    Z* z;
};
class X_e2f80 {
  public:
    char p[8];
    Y_e2f80* y;
};
class Obj_e2f80 {
  public:
    char p[0x14];
    X_e2f80* x;
    char q[0x1d94 - 0x18];
    int* arr;
    void f(hulk_intptr);
};
class Gate_e30a0 {
  public:
    void FnH_000f8b90(int);
};
class FEControl_e30c0 {
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
};
struct Notifier_e30c0 { void Notify_000f8b90(int); };
class Notifier {
  public:
    void Notify_000f8b90(int);
};
class FEControl_e3660 {
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
};
class FEObject_e3660 {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
};
class IValueChangedReceiver_e3660 {
  public:
    virtual void h0();
};
class IValueChangedSender_e3660 {
  public:
    virtual void i0();
};
struct Receiver { void FUN_000f92f0(int, int, int); };

} // namespace fn_f3398797

// 0x000e2ec0 FUN_000e2ec0 (150 B): matches/0x000e2ec0.cpp
// sym: ?FUN_000e2ec0@Obj_e2ec0@owners@@QAEXPAU12@@Z
void owners::Obj_e2ec0::FUN_000e2ec0(owners::Obj_e2ec0* src) {
    Init(src);
    memcpy(f118, src->f118, 40);
    f158 = src->f158;
    f15c = src->f15c;
    f160 = src->f160;
    f164 = src->f164;
    f150 = src->f150;
    f168 = src->f168;
    f78 = src->f78;
    f7c = src->f7c;
    f80 = src->f80;
    f17c = src->f17c;
}


// 0x000e2f60 TextSelector::vfunc_1 (24 B): matches/0x000e2f60.cpp
// sym: ?vfunc_1@TextSelector@@UAEXH@Z
void TextSelector::vfunc_1(int param) {
    if (param == this->f_1d94)
        this->f_154 = *(int*)(this->f_1d94 + 0x40);
}

namespace fn_f3398797 {

// 0x000e2f80 FUN_000e2f80 (67 B): matches/0x000e2f80.cpp
// sym: ?f@Obj_e2f80@fn_f3398797@@QAEXH@Z
void Obj_e2f80::f(hulk_intptr arg) {
    int* p = ((int *)((owners::Obj_f8d70 *)(x->y->z->w))->FUN_000f8d70((hulk_intptr)arg));
    arr = p;
    if (p) {
        int i = 0;
        while (i < 4 && p[i + 1] != 0)
            ++i;
        if (i != 4)
            p[i + 1] = (hulk_intptr)this;
    }
}

} // namespace fn_f3398797

// 0x000e3040 TextSelector::vfunc_21 (33 B): matches/0x000e3040.cpp
// sym: ?vfunc_21@TextSelector@@UAEXHE@Z
void TextSelector::vfunc_21(int index, unsigned char value) {
    if (index >= 0 && index < this->f_1d58)
        ((char*)this)[index * 0x38 + 0x18c] = value;
}


// 0x000e3070 TextSelector::vfunc_22 (13 B): matches/0x000e3070.cpp
// sym: ?vfunc_22@TextSelector@@UAEXI@Z
void TextSelector::vfunc_22(unsigned int x) {
    this->f_1d68 = x;
}


// 0x000e3080 TextSelector::vfunc_23 (13 B): matches/0x000e3080.cpp
// sym: ?vfunc_23@TextSelector@@UAEXH@Z
void TextSelector::vfunc_23(int x) {
    this->f_1d70 = x;
}


// 0x000e3090 TextSelector::vfunc_24 (13 B): matches/0x000e3090.cpp
// sym: ?vfunc_24@TextSelector@@UAEXH@Z
void TextSelector::vfunc_24(int value) {
    this->f_1d6c = value;
}


// 0x000e30a0 FUN_000e30a0 (32 B): matches/0x000e30a0.cpp
// sym: ?FUN_000e30a0@TextSelector@@QAEXXZ
void TextSelector::FUN_000e30a0() {
    if ((*(Gate_e30a0 * *)&this->f_1d94))
        (*(Gate_e30a0 * *)&this->f_1d94)->FnH_000f8b90(this->f_154);
    vfunc_0();
}


// 0x000e30c0 TextSelector::vfunc_25 (47 B): matches/0x000e30c0.cpp
// sym: ?vfunc_25@TextSelector@@UAEXH@Z
void TextSelector::vfunc_25(int p) {
    if (this->f_154 != p) {
        this->f_154 = p;
        if (*(int*)((char*)this + 0x1d94))
            (*(Notifier_e30c0**)((char*)this + 0x1d94))->Notify_000f8b90(p);
        vfunc_0();
    }
}


// 0x000e30f0 TextSelector::vfunc_26 (52 B): matches/0x000e30f0.cpp
// sym: ?vfunc_26@TextSelector@@UAEXHH@Z
void TextSelector::vfunc_26(int index, int value) {
    *(int*)((char*)this + (index + 7) * 0x38) = value;
    if ((*(Notifier * *)&this->f_1d94))
        (*(Notifier * *)&this->f_1d94)->Notify_000f8b90(this->f_154);
    vfunc_0();
}


// 0x000e3130 TextSelector::vfunc_13 (28 B): matches/0x000e3130.cpp
// sym: ?vfunc_13@TextSelector@@UAEXH@Z
void TextSelector::vfunc_13(int x) {
    this->f_148 = this->f_14c;
    int v = this->f_14c;
    if ((*(void * *)&this->f_1d88))
        *(int*)((char*)(*(void * *)&this->f_1d88) + 0x44) = v;
}


// 0x000e3150 TextSelector::vfunc_14 (25 B): matches/0x000e3150.cpp
// sym: ?vfunc_14@TextSelector@@UAEXH@Z
void TextSelector::vfunc_14(int x) {
    this->f_148 = this->f_44;
    if ((*(void * *)&this->f_1d88))
        *(int*)((char*)(*(void * *)&this->f_1d88) + 0x44) = this->f_44;
}


// 0x000e3170 TextSelector::vfunc_12 (1235 B): equivalent/0x000e3170.cpp [wrapped: macros]
// sym: ?vfunc_12@TextSelector@fn_000e3170@@UAEDIH@Z
namespace fn_000e3170 {
// STATUS: equivalent (tools/equiv.py level 3: 3073 inputs, branch coverage 86/97, incomplete)
// TextSelector::vfunc_12 @ 0x000e3170
class Ctl {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual char v4(int kind, int snd, int from, int to);
};

class Obj4 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual void w17();
    virtual void w18();
    virtual void w19();
    virtual void w20();
    virtual void w21();
    virtual void w22();
    virtual void w23();
    virtual void w24();
    virtual void w25();
    virtual void w26();
    virtual void w27();
    virtual void w28();
    virtual void w29();
    virtual void w30();
    virtual void w31();
    virtual void w32();
    virtual void w33();
    virtual void w34();
    virtual void w35();
    virtual void w36();
    virtual void w37();
    virtual void w38();
    virtual void w39();
    virtual void w40();
    virtual void w41();
    virtual void w42();
    virtual void w43();
    virtual void w44();
    virtual void w45();
    virtual void w46();
    virtual void w47();
    virtual void v48(int n);
};

struct Obj8 {
    char pad0[4];
    Obj4 *f4;
};

struct Obj14 {
    char pad0[8];
    Obj8 *f8;
};

struct Entry {
    void *items;
    int f4;
    int count;
    int cur;
    char rest[0x38 - 0x10];
};

class TextSelector {
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
    virtual char vfunc_12(unsigned int action, int a2);
    char pad04[0x14 - 4];
    Obj14 *f14;
    char pad18[0xa8 - 0x18];
    int snd;
    char padac[0x118 - 0xac];
    Ctl *ctl[10];
    char pad140[0x154 - 0x140];
    int sel;
    char pad158[0x17c - 0x158];
    Entry entries[127];
    char pad2[0x14];
    int total;
    int mode;
    char pad1d60[0x1d7c - 0x1d60];
    int top;
    int bottom;
    char wrap;
    void FUN_000e30a0();

    void Refresh();
};

#define BROADCAST(FROM, TO)                                  \
    for (Ctl **pp = ctl; pp != &ctl[10]; pp++) {             \
        if (*pp == 0)                                        \
            break;                                           \
        if ((*pp)->v4(4, snd, (FROM), (TO)))                 \
            (*pp)->v1();                                     \
    }

__forceinline void TextSelector::Refresh()
{
    FUN_000e30a0();
    f14->f8->f4->v48(3);
}

char TextSelector::vfunc_12(unsigned int action, int a2)
{
    switch (action) {
    case 2:
        if (mode == 2) {
            Entry *e = &entries[sel];
            int count = e->count;
            if (count > 1) {
                int cur = e->cur;
                if (cur < count - 1) {
                    e->cur = cur + 1;
                    BROADCAST(-1, -1);
                    f14->f8->f4->v48(3);
                    return 1;
                }
            }
            return 1;
        } else {
            int cur = sel;
            if (cur == 0x7f || cur + 1 == total) {
                if (wrap) {
                    BROADCAST(cur, 0);
                    sel = 0;
                    Refresh();
                }
                return 1;
            }
            BROADCAST(cur, cur + 1);
            sel = sel + 1;
            Refresh();
            if (sel > bottom) {
                bottom = bottom + 1;
                top = top + 1;
            }
            return 1;
        }
    case 6:
        if (mode == 2) {
            Entry *e = &entries[sel];
            if (e->count > 1) {
                int cur = e->cur;
                if (cur > 0) {
                    e->cur = cur - 1;
                    BROADCAST(-1, -1);
                    f14->f8->f4->v48(3);
                    return 1;
                }
            }
            return 1;
        } else {
            int cur = sel;
            if (cur == 0) {
                if (wrap) {
                    int last = total - 1;
                    BROADCAST(0, last);
                    sel = total - 1;
                    Refresh();
                }
                return 1;
            }
            BROADCAST(cur, cur - 1);
            sel = sel - 1;
            Refresh();
            if (sel < top) {
                bottom = bottom - 1;
                top = top - 1;
            }
            return 1;
        }
    case 0:
        if (mode != 2)
            return 0;
        {
            int cur = sel;
            if (cur == 0)
                return 0;
            BROADCAST(cur, cur - 1);
            sel = sel - 1;
            Refresh();
            if (sel < top) {
                bottom = bottom - 1;
                top = top - 1;
            }
            return 1;
        }
    case 4:
        if (mode != 2)
            return 0;
        {
            int cur = sel;
            if (cur == 0x7f)
                return 0;
            if (cur + 1 >= total)
                return 0;
            BROADCAST(cur, cur + 1);
            sel = sel + 1;
            Refresh();
            if (sel > bottom) {
                bottom = bottom + 1;
                top = top + 1;
            }
            return 1;
        }
    }
    return 0;
}
} // namespace fn_000e3170
#undef BROADCAST


// 0x000e3660 TextSelector::vfunc_9 (7 B): matches/0x000e3660.cpp
// sym: ?vfunc_9@TextSelector@@UAEMXZ
hulk_freg TextSelector::vfunc_9() {
    return this->f_1d60;
}


// 0x000e3670 TextSelector::vfunc_6 (42 B): equivalent/0x000e3670.cpp
// sym: ?vfunc_6@TextSelector@@UAEXH@Z
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 2/2)
// TextSelector::vfunc_6 @ 0x000e3670
void TextSelector::vfunc_6(hulk_intptr __p0) { Receiver * receiver = (Receiver *)__p0;

    if (this->f_90 != 0 || this->f_94 != 0)
        receiver->FUN_000f92f0(this->f_90, this->f_94, (*(signed char *)&this->f_154));
}

