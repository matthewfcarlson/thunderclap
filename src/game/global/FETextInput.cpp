// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000dc230..0x000dd6c0 (kind game, layer game, confidence high), dominant class FETextInput
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fb73efad {
#define TREE_TU_END }
namespace fn_fb73efad {} using namespace fn_fb73efad;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fb73efad {
extern void* hulk_at_0040bb9c[];
void Free_0008d340(void*) throw();
class FEControl_dc600 {
  public:
    void* vptr;
    void Fin_000e92b0();
};
class FETextInput_dc600 : public FEControl_dc600 {
  public:
    char p[0x14c];
    int n;
    void* m154;
    void* m158;
    void* m15c;
    void* m160;
    void** a;
    void** b;
    void* m16c;
    ~FETextInput_dc600() throw();
};
struct Settings_dc730 {
    char pad00[0xbc0];
    char flag;              // 0xbc0
};
struct Session_dc730 {
    char pad00[0x175c];
    Settings_dc730 *settings;     // 0x175c
};
struct Inner_dc730 {
    char pad00[4];
    Session_dc730 *session;       // 0x4
};
struct Middle {
    char pad00[8];
    Inner_dc730 *inner;           // 0x8
};
struct Label_dc730 {
};
} // namespace fn_fb73efad
struct Singleton_4dd6ec {
    Label_dc730 *FUN_00086280();
};
namespace fn_fb73efad {
class FETextInput_dc730 {
public:
    char pad00[0x14];
    Middle *middle;         // 0x14
    char pad18[0x178 - 0x18];
    int state;              // 0x178
    void FUN_000dc730();
};
class FEControl_dc7c0 {
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
    virtual void q();
    virtual void r();
    virtual void s();
};
struct FETextInput_nv_dc7c0 {
    void helper_000dc730();
};
struct Vec3_dc810 {
    float x, y, z;
};
extern "C" void *FUN_0008d6d0(unsigned int size);
class ParticleBuffers {
public:
    char pad000[0x150];
    int count;                // 0x150
    int used;                 // 0x154
    char *flags;              // 0x158
    Vec3_dc810 *positions;          // 0x15c
    Vec3_dc810 *velocities;         // 0x160
    void **links0;            // 0x164
    void **links1;            // 0x168
    int *ids;                 // 0x16c

    void FUN_000dc810(int newCount);
};
class Obj_dc9e0 {
  public:
    char pad[0x150];
    int limit;
    int count;
    char pad2[0x14];
    int* items;
};

} // namespace fn_fb73efad

// 0x000dc590 FUN_000dc590 (112 B): equivalent/0x000dc590.cpp [wrapped: conflict: FEControl; FETextInput]
// sym: ??0FETextInput@fn_000dc590@@QAE@H@Z @e6a5b88bffbd @w29466f467d50
namespace fn_000dc590 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_000dc590 @ 0x000dc590
class FEBase_dc590 {
public:
    FEBase_dc590(int arg) throw();
    virtual void v0_000e1360();
    char pad04[0x44 - 4];
    int link;
    char pad48[0x118 - 0x48];
};

class FEControl : public FEBase_dc590 {
public:
    FEControl(int arg) throw();
    virtual void c0();
    int slots[10];
    bool flag0;
    bool flag1;
    bool flag2;
    bool flag3;
    char flag4;
    char pad145[3];
    int link0;
    int link1;
};

class FETextInput : public FEControl {
public:
    FETextInput(int arg) throw();
    virtual void t0();
    int cursor[8];      // 0x150
    unsigned int color; // 0x170
    int f174;
    int f178;
    char f17c;
};

// equiv-map: ??0FEControl@@QAE@H@Z = 0x000e9240
FETextInput::FETextInput(int arg) throw() : FEControl(arg)
{
    for (int i = 0; i < 8; i++)
        cursor[i] = 0;
    color = 0x50ffffff;
    f174 = -1;
    f178 = 1;
    f17c = 1;
}
} // namespace fn_000dc590

namespace fn_fb73efad {

// 0x000dc600 FUN_000dc600 (258 B): matches/0x000dc600.cpp
// sym: ??1FETextInput_dc600@fn_fb73efad@@QAE@XZ
FETextInput_dc600::~FETextInput_dc600() throw() {
    vptr = hulk_at_0040bb9c;
    if (m158) {
        Free_0008d340(m158);
        m158 = 0;
    }
    if (m15c) {
        Free_0008d340(m15c);
        m15c = 0;
    }
    if (m160) {
        Free_0008d340(m160);
        m160 = 0;
    }
    for (int i = 0; i < n; i++) {
        if (a[i]) {
            Free_0008d340(a[i]);
            a[i] = 0;
        }
        if (b[i]) {
            Free_0008d340(b[i]);
            b[i] = 0;
        }
    }
    if (a) {
        Free_0008d340(a);
        a = 0;
    }
    if (b) {
        Free_0008d340(b);
        b = 0;
    }
    if (m16c) {
        Free_0008d340(m16c);
        m16c = 0;
    }
    Fin_000e92b0();
}

// 0x000dc710 FETextInput::vfunc_3 (5 B): not yet verified

// 0x000dc720 FETextInput::vfunc_4 (1 B): matches/0x000dc720.cpp
// sym: ?FUN_000dc720@fn_fb73efad@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000dc720() {}


// 0x000dc730 FUN_000dc730 (131 B): equivalent/0x000dc730.cpp
// sym: ?FUN_000dc730@FETextInput_dc730@fn_fb73efad@@QAEXXZ @2a9066bb2bd4 @w1de361245a13
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 6/6)
// FUN_000dc730 @ 0x000dc730
void FETextInput_dc730::FUN_000dc730()
{
    bool pressed = middle->inner->session->settings->flag != 0;
    int id;
    if (pressed)
        id = 0xb;
    else if (state == 2)
        id = 0xc;
    else
        id = 0xa;
    ((owners::MenuScreen_bc9f0 *)(DAT_004dd6ec->FUN_00086280()))->FUN_000bc9f0((hulk_intptr)"DynamicControlButtonLabel", id);
}

} // namespace fn_fb73efad

// 0x000dc7c0 FETextInput::vfunc_13 (25 B): matches/0x000dc7c0.cpp
// sym: ?vfunc_13@FETextInput@@UAEXH@Z
void FETextInput::vfunc_13(int ) {
    if ((*(unsigned char *)&this->f_74)) {
        this->f_178 = 1;
        ((FETextInput_nv_dc7c0*)this)->helper_000dc730();
    }
}


// 0x000dc7e0 FETextInput::vfunc_14 (20 B): matches/0x000dc7e0.cpp
// sym: ?vfunc_14@FETextInput@@UAEXH@Z
void FETextInput::vfunc_14(int ) {
    if ((*(unsigned char *)&this->f_74))
        this->f_178 = 0;
}


// 0x000dc800 FETextInput::vfunc_10 (5 B): matches/0x000dc800.cpp
// sym: ?vfunc_10@FETextInput@@UAEDHH@Z
// Same code shape as 0x000d7a40 (propagated; names are from that function)
char FETextInput::vfunc_10(int , int ) {
    return (char)(false);
}

namespace fn_fb73efad {

// 0x000dc810 FUN_000dc810 (464 B): matches/0x000dc810.cpp
// sym: ?FUN_000dc810@ParticleBuffers@fn_fb73efad@@QAEXH@Z
// FUN_000dc810 @ 0x000dc810
void ParticleBuffers::FUN_000dc810(int newCount)
{
    for (int i = 0; i < count; i++) {
        if (links0[i]) {
            FUN_0008d340(links0[i]);
            links0[i] = 0;
        }
        if (links1[i]) {
            FUN_0008d340(links1[i]);
            links1[i] = 0;
        }
    }
    if (links0) {
        FUN_0008d340(links0);
        links0 = 0;
    }
    if (links1) {
        FUN_0008d340(links1);
        links1 = 0;
    }

    count = newCount;
    used = 0;
    if (flags) {
        FUN_0008d340(flags);
        flags = 0;
    }
    if (positions) {
        FUN_0008d340(positions);
        positions = 0;
    }
    if (velocities) {
        FUN_0008d340(velocities);
        velocities = 0;
    }
    if (ids) {
        FUN_0008d340(ids);
        ids = 0;
    }

    flags = (char *)FUN_0008d6d0(count + 1);
    flags[0] = 0;
    positions = (Vec3_dc810 *)FUN_0008d6d0(count * 12);
    velocities = (Vec3_dc810 *)FUN_0008d6d0(count * 12);
    links0 = (void **)FUN_0008d6d0(count * sizeof(void *));
    links1 = (void **)FUN_0008d6d0(count * sizeof(void *));
    ids = (int *)FUN_0008d6d0(count * 4);

    for (int i = 0; i < count; i++) {
        ids[i] = -1;
        links0[i] = 0;
        links1[i] = 0;
    }
}


// 0x000dc9e0 FUN_000dc9e0 (95 B): matches/0x000dc9e0.cpp
// sym: ?target@fn_fb73efad@@YI_NPAVObj_dc9e0@1@@Z
bool __fastcall target(Obj_dc9e0* p) {
    int i = p->count;
    if (i > 0) {
        if (i < p->limit) {
            do {
                p->items[i] = -1;
                ++i;
            } while (i < p->limit);
        }
        --p->count;
        return true;
    }
    if (i == 0) {
        i = 0;
        if (p->limit > 0)
            do {
                p->items[i] = -1;
                ++i;
            } while (i < p->limit);
        return true;
    }
    return false;
}

} // namespace fn_fb73efad

// 0x000dca40 FUN_000dca40 (82 B): matches/0x000dca40.cpp
// sym: ?FUN_000dca40@FETextInput@@QAE_NXZ
// data: alphabet = DAT_004a0d38
bool FETextInput::FUN_000dca40() {
    int i = 0;
    if (this->f_150 > 0) {
        do {
            int value = (*(int * *)&this->f_16c)[i];
            if (value >= 0)
                (*(char * *)&this->f_158)[i] = ((const char*)&DAT_004a0d38)[value];
            else
                (*(char * *)&this->f_158)[i] = 0;
            ++i;
        } while (i < this->f_150);
    }
    (*(char * *)&this->f_158)[this->f_150] = 0;
    return true;
}


// 0x000dcac0 FETextInput::vfunc_2 (30 B): matches/0x000dcac0.cpp
// sym: ??_GFETextInput@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
FETextInput::~FETextInput() {}


// 0x000dcae0 FETextInput::vfunc_5 (1376 B): equivalent/0x000dcae0.cpp [wrapped: conflict: DAT_004a0d38; FETextInput]
// sym: ?vfunc_5@FETextInput@fn_000dcae0@@UAEXXZ @010f95ab1e3d @w7c95b38f7b60
namespace fn_000dcae0 {
// STATUS: equivalent (tools/equiv.py level 3: 3009 inputs, branch coverage 38/38)
// FETextInput::vfunc_5 @ 0x000dcae0

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void __fastcall __security_check_cookie(unsigned int);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif


class FETextInput;
struct Cell {
    float v;
    int f4;
    int f8;
    int f0c;
    int f10;
    int f14;
};

struct Lay {
    void *p;
    int f04;
    __declspec(align(8)) char data[0x80];
    int idx;
    int pad8c;
    void FUN_000f7fe0(void *r) throw();
    void FUN_000f78e0() throw();
    void FUN_000f80e0(const char *buf, int z, const void *style) throw();
};

class Y {
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
    virtual void *v44();
};

class X {
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
    virtual void v48(int a, void *b);
    Y *f04;
    char pad08[0x958 - 8];
    char s958[0x14];
    float f96c;
    char pad970[8];
    char s978[0x10];
    unsigned int f988;
};

class Owner {
public:
    int pad04;
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
    virtual char v13(FETextInput *t);
    X *f08;
};

class Obj {
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
    virtual void v15(int z);
    virtual void v16(int z);
};

struct P2 {
    Obj *obj;
    void FUN_00293d00(void *arg) throw();
};

struct Widget {
    void FUN_000e9100(void *a) throw();
    void FUN_000e9130(void *a) throw();
};

extern unsigned int DAT_004d9968;
extern P2 *DAT_0052c2ac;
extern signed char DAT_004a0d38[];
Widget *__cdecl FUN_000fc260(const char *name) throw();

class FETextInput {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void vfunc_5();
    char pad04[0x10];
    Owner *f14;
    char pad18[0x3c - 0x18];
    union {
        int f3c;
        struct {
            char b3c, b3d, b3e, b3f;
        };
    };
    char pad40[0x60 - 0x40];
    void *f60;
    void *f64;
    char b68;
    char pad69[0x74 - 0x69];
    char b74;
    char pad75[0x150 - 0x75];
    int f150;
    int f154;
    char pad158[4];
    char *f15c;
    char *f160;
    int *f164;
    int *f168;
    int *f16c;
    char pad170[4];
    union {
        unsigned int f174;
        struct {
            unsigned char b174, b175, b176, b177;
        };
    };
    int f178;
    float FUN_000e2840() throw();
    float FUN_000e2850() throw();
};

void FETextInput::vfunc_5()
{
    struct Frame {
        Lay L1;
        Lay L2;
        char buf2[8];
        char buf1[0x44];
        unsigned int cookie;
    } f;
    int tmp;
    int off;
    int i;

    f.cookie = DAT_004d9968;
    if (b74 != 0) {
        f.L1.FUN_000f7fe0(f14->f08->f04->v44());
        f.L2.FUN_000f7fe0(f14->f08->f04->v44());
        float s = FUN_000e2850();
        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->v = FUN_000e2840() * s;
        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f8 = 2;
        float s2 = FUN_000e2850();
        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->v = FUN_000e2840() * s2;
        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f8 = 2;
        sprintf(f.buf1, "___");
        Widget *w = FUN_000fc260("enter_code_text");
        if (f178 == 1) {
            if (w != 0) {
                if (f14->v13(this)) {
                    if (f60 != 0 && b68 == 0)
                        w->FUN_000e9100(f60);
                }
                if (!f14->v13(this)) {
                    if (f64 != 0)
                        w->FUN_000e9130(f64);
                }
            }
        } else if (w != 0) {
            w->FUN_000e9100(0);
            w->FUN_000e9130(0);
        }
        i = 0;
        if (f150 > 0) {
            off = 0;
            do {
                if (f168[i] != 0) {
                    DAT_0052c2ac->obj->v15(0);
                    f14->f08->v48(f168[i], f160 + off);
                    DAT_0052c2ac->FUN_00293d00(f160 + off);
                    Cell *c = (Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16);
                    c->f4 = 1;
                    ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f0c = f3c;
                    f.L1.f04 = f3c;
                    if ((f178 == 2 && f154 == i) || f178 == 1) {
                        X *x = f14->f08;
                        float fa = x->f96c * 255.0f;
                        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f0c = 0;
                        X *x2 = f14->f08;
                        tmp = x2->f988;
                        x2->f988 = (255 - (int)fa) << 24;
                        f.L1.FUN_000f80e0(f.buf1, 0, f14->f08->s978);
                        x2->f988 = tmp;
                        tmp = b177 * (unsigned char)b3f;
                        int a = (int)((float)tmp * 0.003921569f);
                        unsigned int col = (((((a << 8) | b176) << 8) | b175) << 8) | (f174 & 0xff);
                        ((Cell *)((char *)&f.L1 + 8 + f.L1.idx * 16))->f0c = col;
                        f.L1.FUN_000f80e0(f.buf1, 0, x->s958);
                    } else {
                        f.L1.FUN_000f80e0(f.buf1, 0, f14->f08->s978);
                    }
                    DAT_0052c2ac->obj->v16(0);
                }
                if (f16c[i] >= 0 && f164[i] != 0) {
                    sprintf(f.buf2, "%c", (int)DAT_004a0d38[f16c[i]]);
                    DAT_0052c2ac->obj->v15(0);
                    f14->f08->v48(f164[i], f15c + off);
                    DAT_0052c2ac->FUN_00293d00(f15c + off);
                    Cell *c = (Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16);
                    c->f4 = 1;
                    ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f0c = f3c;
                    f.L2.f04 = f3c;
                    if (f178 == 2 && f154 == i) {
                        X *x = f14->f08;
                        float fa = x->f96c * 255.0f;
                        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f0c = 0;
                        X *x2 = f14->f08;
                        tmp = x2->f988;
                        x2->f988 = (255 - (int)fa) << 24;
                        f.L2.FUN_000f80e0(f.buf2, 0, f14->f08->s978);
                        x2->f988 = tmp;
                        tmp = b177 * (unsigned char)b3f;
                        int a = (int)((float)tmp * 0.003921569f);
                        unsigned int col = (((((a << 8) | b176) << 8) | b175) << 8) | (f174 & 0xff);
                        ((Cell *)((char *)&f.L2 + 8 + f.L2.idx * 16))->f0c = col;
                        f.L2.FUN_000f80e0(f.buf2, 0, x->s958);
                    } else {
                        f.L2.FUN_000f80e0(f.buf2, 0, f14->f08->s978);
                    }
                    DAT_0052c2ac->obj->v16(0);
                }
                i = i + 1;
                off = off + 0xc;
            } while (i < f150);
        }
        f.L2.FUN_000f78e0();
        f.L1.FUN_000f78e0();
    }
    __security_check_cookie(f.cookie);
}
} // namespace fn_000dcae0


// 0x000dd040 FETextInput::vfunc_12 (735 B): equivalent/0x000dd040.cpp [wrapped: conflict: FETextInput]
// sym: ?vfunc_12@FETextInput@fn_000dd040@@UAE_NHH@Z @1b7558c77339 @w797caa867e70
namespace fn_000dd040 {
// STATUS: equivalent (tools/equiv.py level 3: 3088 inputs, branch coverage 60/60)
// FETextInput::vfunc_12 @ 0x000dd040
struct Win {
    virtual void w0(); virtual void w1(); virtual void w2(); virtual void w3(); virtual void w4(); virtual void w5(); virtual void w6(); virtual void w7(); virtual void w8(); virtual void w9(); virtual void w10(); virtual void w11(); virtual void w12(); virtual void w13(); virtual void w14(); virtual void w15(); virtual void w16(); virtual void w17(); virtual void w18(); virtual void w19(); virtual void w20(); virtual void w21(); virtual void w22(); virtual void w23(); virtual void w24(); virtual void w25(); virtual void w26(); virtual void w27(); virtual void w28(); virtual void w29(); virtual void w30(); virtual void w31(); virtual void w32(); virtual void w33(); virtual void w34(); virtual void w35(); virtual void w36(); virtual void w37(); virtual void w38(); virtual void w39(); virtual void w40(); virtual void w41(); virtual void w42(); virtual void w43(); virtual void w44(); virtual void w45(); virtual void w46(); virtual void w47();
    virtual void w48(int v);
};

struct B_dd040 {
    char pad0[4];
    Win *win;               // 0x4
};

struct A_dd040 {
    char pad0[8];
    B_dd040 *b;                   // 0x8
};

class FETextInput {
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
    virtual bool vfunc_12(int cmd, int arg);
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    char pad04[0x10];
    A_dd040 *owner;               // 0x14
    char pad18[0x74 - 0x18];
    char enabled;           // 0x74
    char pad75[0x150 - 0x75];
    int count;              // 0x150
    int cursor;             // 0x154
    char *text;             // 0x158
    char pad15c[0x16c - 0x15c];
    int *slots;             // 0x16c
    char pad170[0x178 - 0x170];
    int state;              // 0x178
    char flag;              // 0x17c
    void FUN_000dc730();
    void FUN_000dca40();
    void FUN_000dc9e0();
    void FUN_000e2c90(int a, int b, int c);
};

bool FETextInput::vfunc_12(int cmd, int arg)
{
    if (!enabled)
        return false;
    switch (cmd) {
    case 8:
    case 11:
        if (state == 1) {
            state = 2;
            FUN_000dc730();
            cursor = 0;
            text[0] = 0;
            if (count > 0) {
                int i = 0;
                do {
                    slots[i] = -1;
                    i++;
                } while (i < count);
            }
            slots[0] = 0;
            owner->b->win->w48(0);
            return true;
        }
        FUN_000dca40();
        state = 1;
        FUN_000dc730();
        FUN_000e2c90(0, -1, -1);
        if (flag != 0) {
            text[0] = 0;
            if (count > 0) {
                int i = 0;
                do {
                    slots[i] = -1;
                    i++;
                } while (i < count);
            }
        }
        return true;
    case 10: {
        FUN_000dc9e0();
        int old = state;
        state = 1;
        FUN_000dc730();
        text[0] = 0;
        if (count > 0) {
            int i = 0;
            do {
                slots[i] = -1;
                i++;
            } while (i < count);
        }
        cursor = 0;
        return old != 1;
    }
    case 2: {
        if (state != 2)
            return false;
        if (slots[cursor] < 0)
            slots[cursor] = 0;
        owner->b->win->w48(2);
        int c = cursor + 1;
        cursor = c;
        if (!(c < count))
            cursor = 0;
        int *p = &slots[cursor];
        if (*p < 0)
            *p = 0;
        return true;
    }
    case 6: {
        if (state != 2)
            return false;
        cursor = cursor - 1;
        if (cursor < 0) {
            cursor = count - 1;
            if (count > 0) {
                int i = 0;
                do {
                    int *q = &slots[i];
                    if (*q < 0)
                        *q = 0;
                    i++;
                } while (i < count);
            }
        }
        owner->b->win->w48(2);
        int *p = &slots[cursor];
        if (*p < 0)
            *p = 0;
        return true;
    }
    case 0: {
        if (state != 2)
            return false;
        int *p = &slots[cursor];
        int v = *p;
        if (v > 0)
            v = v - 1;
        else
            v = 0x23;
        *p = v;
        owner->b->win->w48(3);
        return true;
    }
    case 4: {
        if (state != 2)
            return false;
        int *p = &slots[cursor];
        int v = *p + 1;
        if (!(v < 0x24))
            v = 0;
        *p = v;
        owner->b->win->w48(3);
        return true;
    }
    default:
        return false;
    }
}
} // namespace fn_000dd040

