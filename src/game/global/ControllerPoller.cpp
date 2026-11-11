// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000dd710..0x000ddbe0 (kind game, layer game, confidence high), dominant class ControllerPoller
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_f09842b8 {
#define TREE_TU_END }
namespace fn_f09842b8 {} using namespace fn_f09842b8;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f09842b8 {
extern void* hulk_at_0040bcb4;
extern void* hulk_at_0040bc80;
void __cdecl Release_0008d330(void*);
class ControllerState_dd7a0 {
  public:
    void* vt;
    char pad[8];
    void* a;
    void* b;
    void Clear();
};
struct Block_dd830 {
    unsigned long x[10];
};
struct Other_dd830 {
    virtual void f0();
    virtual void f1(void*, void*);
};
class IDollyControllerState_dd880 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual float vfunc_5(int);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
};
class pddiObject_dd8a0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_dd8a0 : public pddiObject_dd8a0 {};
class pddiBaseShader_dd8a0 : public pddiShader_dd8a0 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_dd8a0 : public pddiBaseShader_dd8a0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
struct Pair_dd8b0 {
    int a, b;
};
struct IDollyControllerState_dd8b0 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual float vfunc_7(int);
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
};
class IDollyControllerState_dd8d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual float vfunc_8(int);
    virtual void f9();
    virtual void f10();
    virtual void f11();
};
struct Pair_dd8d0 {
    int a, b;
};
class pddiObject_dd8f0 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_dd8f0 : public pddiObject_dd8f0 {};
class pddiBaseShader_dd8f0 : public pddiShader_dd8f0 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_dd8f0 : public pddiBaseShader_dd8f0 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class IDollyControllerState_dd900 {
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
    virtual float vfunc_10(int arg);
    virtual void vfunc_11();
    char pad[8];
};
extern const int hulk_at_004a0d74[][2];
class IDollyControllerState_dd920 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual float vfunc_8(int);
    virtual void f9();
    virtual void f10();
    virtual void f11();
};
struct Pair_dd920 {
    int a, b;
};
struct PollMapping {
    int button;
    int code;
};
class ControllerPollerBase_dda90 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual int vfunc_5(int);
};
class Helper_dda90 {
  public:
    int run_000dd710(int, int);
};
extern "C" void* __cdecl FUN_0008d690(int);
class ControllerPollerBase_ddb40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual bool f2();
    virtual bool f3();
    virtual bool f4(int, int);
    virtual void f5();
};

} // namespace fn_f09842b8

// 0x000dd710 FUN_000dd710 (144 B): equivalent/0x000dd710.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??0ControllerState@fn_000dd710@@QAE@HH@Z
namespace fn_000dd710 {
// STATUS: equivalent (tools/equiv.py level 3: 2979 inputs, branch coverage 4/4)
// FUN_000dd710 @ 0x000dd710
void *__cdecl FUN_0008d690(unsigned int size);

struct Block_dd710 {
    int word[10];
};

class ControllerState {
public:
    virtual void v0();
    int a;                   // 0x04
    int b;                   // 0x08
    Block_dd710 *first;            // 0x0c
    Block_dd710 *second;           // 0x10
    ControllerState(int x, int y);
};

static Block_dd710 *NewBlock() {
    Block_dd710 *block = (Block_dd710 *)FUN_0008d690(sizeof(Block_dd710));
    if (block) {
        for (int i = 0; i < 10; i++)
            block->word[i] = 0;
    }
    return block;
}

ControllerState::ControllerState(int x, int y) {
    a = y;
    b = x;
    first = NewBlock();
    second = NewBlock();
}
} // namespace fn_000dd710

namespace fn_f09842b8 {

// 0x000dd7a0 FUN_000dd7a0 (63 B): matches/0x000dd7a0.cpp
// sym: ?Clear@ControllerState_dd7a0@fn_f09842b8@@QAEXXZ
void ControllerState_dd7a0::Clear() {
    vt = &hulk_at_0040bcb4;
    if (a) {
        Release_0008d330(a);
        a = 0;
    }
    if (b) {
        Release_0008d330(b);
        b = 0;
    }
    vt = &hulk_at_0040bc80;
}

} // namespace fn_f09842b8

// 0x000dd7e0 ControllerState::vfunc_1 (67 B): equivalent/0x000dd7e0.cpp
// sym: ?vfunc_1@ControllerState@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 19799 inputs, branch coverage 0/0)
// ControllerState::vfunc_1 @ 0x000dd7e0
void ControllerState::vfunc_1() {
    unsigned int *p = (*(unsigned int * *)&this->f_0c);
    p[0]=0; p[1]=0; p[2]=0; p[3]=0; p[4]=0;
    p[5]=0; p[6]=0; p[7]=0; p[8]=0; p[9]=0;
    p = (*(unsigned int * *)&this->f_10);
    p[0]=0; p[1]=0; p[2]=0; p[3]=0; p[4]=0;
    p[5]=0; p[6]=0; p[7]=0; p[8]=0; p[9]=0;
}


// 0x000dd830 ControllerState::vfunc_2 (36 B): matches/0x000dd830.cpp
// sym: ?vfunc_2@ControllerState@@UAEXXZ
void ControllerState::vfunc_2() {
    *reinterpret_cast<Block_dd830*>((*(unsigned long * *)&this->f_10)) = *reinterpret_cast<Block_dd830*>((*(unsigned long * *)&this->f_0c));
    (*(Other_dd830 * *)&this->f_08)->f1((*(void * *)&this->f_04), (*(unsigned long * *)&this->f_0c));
}


// 0x000dd860 ControllerState::vfunc_3 (6 B): matches/0x000dd860.cpp
// sym: ?vfunc_3@ControllerState@@UAEHXZ
// Same code shape as 0x00050230 (propagated; names are from that function)
int ControllerState::vfunc_3() {
    return 10;
}


// 0x000dd870 ControllerState::vfunc_4 (13 B): matches/0x000dd870.cpp
// sym: ?vfunc_4@ControllerState@@UAEMH@Z
hulk_freg ControllerState::vfunc_4(int index) {
    return (*(float * *)&this->f_0c)[index];
}


// 0x000dd880 ControllerState::vfunc_5 (13 B): matches/0x000dd880.cpp
// sym: ?vfunc_5@ControllerState@@UAEMH@Z
hulk_freg ControllerState::vfunc_5(int index) {
    return (*(float * *)&this->f_10)[index];
}


// 0x000dd8a0 ControllerState::vfunc_6 (6 B): matches/0x000dd8a0.cpp
// sym: ?vfunc_6@ControllerState@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int ControllerState::vfunc_6() {
    return 1;
}


// 0x000dd8b0 ControllerState::vfunc_7 (30 B): matches/0x000dd8b0.cpp
// sym: ?vfunc_7@ControllerState@@UAEMH@Z
hulk_freg ControllerState::vfunc_7(hulk_intptr index) {
    float* p = (*(float * *)&this->f_0c);
    return p[((Pair_dd8b0*)&DAT_004a0d6c)[index].a] - p[((Pair_dd8b0*)&DAT_004a0d6c)[index].b];
}


// 0x000dd8d0 ControllerState::vfunc_8 (30 B): matches/0x000dd8d0.cpp
// sym: ?vfunc_8@ControllerState@@UAEMH@Z
hulk_freg ControllerState::vfunc_8(int i) {
    float* p = (*(float * *)&this->f_10);
    return p[((Pair_dd8d0*)&DAT_004a0d6c)[i].a] - p[((Pair_dd8d0*)&DAT_004a0d6c)[i].b];
}


// 0x000dd8f0 ControllerState::vfunc_9 (6 B): matches/0x000dd8f0.cpp
// sym: ?vfunc_9@ControllerState@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int ControllerState::vfunc_9() {
    return 1;
}


// 0x000dd900 ControllerState::vfunc_10 (30 B): matches/0x000dd900.cpp
// sym: ?vfunc_10@ControllerState@@UAEMH@Z
hulk_freg ControllerState::vfunc_10(int arg) {
    float* a = (*(float * *)&this->f_0c);
    const int* p = hulk_at_004a0d74[arg];
    return a[p[0]] - a[p[1]];
}


// 0x000dd920 ControllerState::vfunc_11 (30 B): matches/0x000dd920.cpp
// sym: ?vfunc_11@ControllerState@@UAEMH@Z
// Same code shape as 0x000dd8d0 (propagated; names are from that function)
hulk_freg ControllerState::vfunc_11(int i) {
    float* p = (*(float * *)&this->f_10);
    return p[((Pair_dd920*)&DAT_004a0d74)[i].a] - p[((Pair_dd920*)&DAT_004a0d74)[i].b];
}


// 0x000dd940 FUN_000dd940 (37 B): matches/0x000dd940.cpp [wrapped: conflict: ControllerPoller]
// sym: ??0ControllerPoller@fn_000dd940@@QAE@HH@Z
namespace fn_000dd940 {
class ControllerPollerBase_dd940 {
  public:
    virtual void Dummy();
    ControllerPollerBase_dd940(int);
};
class ControllerPoller : public ControllerPollerBase_dd940 {
  public:
    virtual void Poll();
    char pad[4];
    int m8;
    char pad2[0x2c];
    int m38;
    ControllerPoller(int a, int b);
};
ControllerPoller::ControllerPoller(int a, int b) : ControllerPollerBase_dd940(b) {
    m8 = b;
    m38 = a;
}
} // namespace fn_000dd940


// 0x000dd970 FUN_000dd970 (11 B): matches/0x000dd970.cpp [wrapped: conflict: CEffectStopTrack]
// sym: @FUN_000dd970@4
namespace fn_000dd970 {
// Same code shape as 0x00060920 (propagated; names are from that function)
extern int hulk_at_0040bce8;
class CEffectStopTrack {
  public:
};
void __fastcall FUN_000de170(CEffectStopTrack*);
extern "C" void __fastcall FUN_000dd970(CEffectStopTrack* self) {
    *(hulk_intptr*)self = (hulk_intptr)&hulk_at_0040bce8;
    FUN_000de170(self);
}
} // namespace fn_000dd970


// 0x000dd980 ControllerPoller::vfunc_2 (267 B): equivalent/0x000dd980.cpp
// sym: ?vfunc_2@ControllerPoller@@UAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 11/12, incomplete)
// ControllerPoller::vfunc_2 @ 0x000dd980
void ControllerPoller::vfunc_2() {
    PollMapping* mappings = (PollMapping*)&DAT_004de800;
    int* count = (int*)&DAT_004de8c0;
    for (int button = 4; button <= 9 && *count < 24; ++button) {
        int code;
        switch (button) {
        case 4:
            code = 8;
            break;
        case 5:
            code = 10;
            break;
        case 6:
            code = 11;
            break;
        case 7:
            code = 9;
            break;
        case 8:
            code = 12;
            break;
        default:
            code = 13;
            break;
        }
        mappings[*count].button = button;
        mappings[*count].code = code;
        ++*count;
    }
}


// 0x000dda90 ControllerPoller::vfunc_5 (43 B): matches/0x000dda90.cpp
// sym: ?vfunc_5@ControllerPoller@@UAEHH@Z
int ControllerPoller::vfunc_5(int param) {
    Helper_dda90* p = (Helper_dda90*)FUN_0008d690(0x14);
    if (p)
        return p->run_000dd710(this->f_38, param);
    return 0;
}


// 0x000ddac0 ControllerPoller::vfunc_4 (125 B): equivalent/0x000ddac0.cpp [wrapped: conflict: ControllerPoller]
// sym: ?vfunc_4@ControllerPoller@fn_000ddac0@@UAEDHH@Z
namespace fn_000ddac0 {
// STATUS: equivalent (tools/equiv.py level 3: 86 inputs, branch coverage 12/12)
// ControllerPoller::vfunc_4 @ 0x000ddac0

struct Binding_ddac0 {
    int axis;       // index into the sample buffer
    int button;     // button id this axis is bound to
};

                // number of bindings
             // axis threshold (writable, 0.05f)
               // latch: a press is being held

class Device_ddac0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1(int pad, float* samples);
};

class ControllerPoller {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual char vfunc_4(int button, int pad);
    virtual void vfunc_5();
    char pad04[0x38 - 4];
    Device_ddac0* device;         // 0x38
};

// True when an axis bound to the button is pressed past the threshold; a held press reports once.
char ControllerPoller::vfunc_4(int button, int pad)
{
    float samples[10];
    device->vfunc_1(pad, samples);
    char pressed = 0;
    int i = 0;
    if ((*(int*)&DAT_004de8c0) > 0) {
        do {
            if (((Binding_ddac0*)&DAT_004de800)[i].button == button && samples[((Binding_ddac0*)&DAT_004de800)[i].axis] > DAT_004a0e68)
                pressed = 1;
            i++;
        } while (i < (*(int*)&DAT_004de8c0));
    }
    if ((*(char*)&DAT_004e222d)) {
        if (pressed)
            return 0;
        (*(char*)&DAT_004e222d) = pressed;
    }
    return pressed;
}
} // namespace fn_000ddac0


// 0x000ddb40 ControllerPoller::vfunc_3 (49 B): matches/0x000ddb40.cpp
// sym: ?vfunc_3@ControllerPoller@@UAE_NH@Z
bool ControllerPoller::vfunc_3(int arg) {
    int i = 0;
    do {
        if (vfunc_4(arg, i))
            return true;
        ++i;
    } while (i < 1);
    return false;
}


// 0x000ddb80 ControllerState::vfunc_0 (83 B): matches/0x000ddb80.cpp [wrapped: conflict: ControllerState]
// sym: ?vfunc_0@ControllerState@fn_000ddb80@@UAEPAV12@E@Z
namespace fn_000ddb80 {
class ControllerState {
  public:
    virtual ControllerState* vfunc_0(unsigned char);
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
    hulk_intptr p4, p8, mA, mB;
};
extern void __cdecl thunk_FUN_00267090(void*);
extern void* cvtable_ddb80;
extern void* ivtable;
ControllerState* ControllerState::vfunc_0(unsigned char param) {
    *(void**)this = &cvtable_ddb80;
    if (mA) {
        thunk_FUN_00267090((void*)mA);
        mA = 0;
    }
    if (mB) {
        thunk_FUN_00267090((void*)mB);
        mB = 0;
    }
    *(void**)this = &ivtable;
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_000ddb80

