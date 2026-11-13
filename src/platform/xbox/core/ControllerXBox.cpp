// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00268300..0x00269680 (kind game, layer platform/xbox, confidence high), dominant class core::ControllerXBox
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/core.h"
#include "gen/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_fc99ffef {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc99ffef {} using namespace fn_fc99ffef;
namespace fn_fc99ffef { extern "C" char DAT_003f6098[]; }   // (x64t6) the game vftables the placeholders stood for (verify_relocs)
#include "platform/xbox/core.h"

// ---- declarations shared by the functions below
namespace fn_fc99ffef {
class IRefCount {
  public:
    virtual void AddRef();
    virtual void Release();
    virtual ~IRefCount();
};
extern "C" char hulk_at_003f6094[];
int helper();
class Pad_2683f0 {
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
    virtual void f18(int);
};
class IControllerSystem_268460 {
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
    virtual void f10(int);
    virtual void f11();
    virtual void f12();
};
class Obj_268490 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2(int);
};
class X_2684c0 {
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
};
namespace pure3d {
class NonCopyable_268500 : public ::core::IControllerInputPoint {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_268500* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_268500*);
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042b14c[];
extern "C" void __stdcall XInputClose(void*);
class IRefCount_268580 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
struct InputState {
    int packet;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    short field_14;
};
extern "C" unsigned long __stdcall XInputGetState(void* handle, InputState* state);
extern "C" unsigned long __stdcall XInputSetState(void* handle, void* feedback);
class Receiver_2685a0 {
  public:
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void r4();
    virtual void r5(InputState* state);
};
class Motor {
  public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual float m5();
};
class Dispatch_268690 {
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
};
class Item_268690 {
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
    virtual void call(int);
};
class Target_268760 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4(unsigned int);
};
class Elem_2687e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* Name();
    char pad[0x30];
};
class ControllerXBox_2687e0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual int Count(const char* name);
    char pad[0x10];
    unsigned int mCount;
    Elem_2687e0 mElems[1];
};
struct Elem_268860 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual const char* Name();
    int pad[3];
};
struct ControllerXBox_268860 {
    char pad[0x428];
    Elem_268860 e[2];
    int Count(const char* s);
};
class NameHolder_2688e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual const char* GetName();
    char pad[0x30];
};
class ControllerXBox {
  public:
    virtual void _m_vf0();
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual ControllerXBox* Find(const char*, int);
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void vfunc_17(int arg);
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    unsigned int connected;
    void* handle;
    char _m_pad_c[0x8];
    int count;
    NameHolder_2688e0 entries[1];
    char _m_pad_4c[0x3dc];
    Motor leftMotor;
    char _m_pad_42c[0xc];
    Motor rightMotor;
    char _m_pad_43c[0x18];
    Receiver_2685a0* receiver;
    unsigned long feedbackStatus;
    int feedbackField;
    char _m_pad_460[0x3a];
    short lastLeft;
    short lastRight;
    char _m_pad_49e[0x2];
};
class Entry_268a10 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual char* Name();
};
class Item_268a80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual const char* get();
};
struct X_268b10 {
    char pad[0x14];
    unsigned value;
};
namespace pure3d {
class NonCopyable_268ba0 : public ::core::IController {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_268ba0* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_268ba0*);
class IRefCount_268be0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
class core_IRefCount {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
};
class IControllerOutputPoint_268c30 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(float);
};
namespace pure3d {
class NonCopyable_268c70 : public ::core::IControllerOutputPoint {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_268c70* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_268c70*);
class IRefCount_268cd0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
typedef unsigned int u32_268d10;
struct This_GetPointX {
    float GetPointX(u32_268d10);
};
class C_268e00 {
    char pad[0x20];

  public:
    unsigned int value;
};
class Callback_268f00 {
  public:
    virtual void Call(int, float);
};
struct This_Convert {
    float Convert(int);
};
namespace pure3d {
class NonCopyable_268f80 : public ::core::IControllerInputPointXBox {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_268f80* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_268f80*);
unsigned int GetTime();
class Pad_269170 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual bool Ready();
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
    virtual void Update(unsigned int t);
    char pad[0x49e - 4];
    bool mActive;
    char pad2[1];
};
struct ControllerSystemXBox_nv_269170 {
    void Poll();
};
namespace XAPILIB {
int __stdcall XInputGetState(unsigned int, void *);
}
struct Triple_2692c0 { unsigned int a,b,c; };
struct Input_2692c0 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(void *);
};
struct Entry_2692c0 { Input_2692c0 input; char padding[0x1c]; Triple_2692c0 values; char rest[8]; };
struct Device_2692c0 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15();
    virtual void f16(); virtual void f17(); virtual void f18(unsigned int);
    virtual void f19(); virtual void f20(unsigned int,unsigned int);
    unsigned int unknown4;
    unsigned int handle;
    unsigned int slot;
    unsigned int port;
    unsigned int count;
    Entry_2692c0 entries[20];
    char pad[0x430 - 0x18 - 20*0x34];
    char *leftName;
    char pad2[12];
    char *rightName;
    char pad3[4];
    unsigned int name0,name1,name2;
    unsigned int other;
    unsigned char zeros[0x46];
    unsigned char active;
    void FUN_002692c0(hulk_uintptr a,unsigned int b,unsigned int c,unsigned int d,unsigned int e,unsigned int f,unsigned int g);
};
class Pad_2693f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool f3();
    char rest[0x49c];
};
class Pad_269420 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual bool IsConnected();
    char data[0x49c];
};
} // namespace fn_fc99ffef
namespace core {
struct ControllerDevice {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual const char* vfunc_6();
    char padding[0x4a0 - 4];
};
}
namespace fn_fc99ffef {
class Pad_2694f0 {
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
    virtual void f19(unsigned int);
};
typedef unsigned char u8_269560;
class ControllerSystemXBox {
  public:
    void cleanup();
    virtual void f0();
    virtual void f1();
    virtual ControllerSystemXBox* f2(u8_269560);
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
};
typedef unsigned int u32_269640;
extern "C" u32_269640 __cdecl FUN_00266e00(u32_269640, u32_269640);
struct ControllerSystemXBox_nv_269640 {
    u32_269640 Make(u32_269640, u32_269640);
};


// 0x00268300 FUN_00268300 (7 B): matches/0x00268300.cpp
// sym: ??1IRefCount@fn_fc99ffef@@UAE@XZ
IRefCount::~IRefCount() {}

} // namespace fn_fc99ffef

// 0x00268330 FUN_00268330 (7 B): matches/0x00268330.cpp
// sym: ?FUN_00268330@IRefCount@core@@QAEXXZ
void core::IRefCount::FUN_00268330() {
    *(hulk_intptr*)this = ((hulk_intptr)(hulk_at_003f6094 + 0x4));
}


// 0x00268390 core::ControllerSystemXBox::vfunc_6 (88 B): matches/0x00268390.cpp [wrapped: conflict: core::ControllerSystemXBox]
// sym: ?vfunc_6@ControllerSystemXBox@core@fn_00268390@@UAEXH@Z
namespace fn_00268390 {
namespace core {
class ControllerSystemXBox {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void vfunc_6(int);
    virtual void f7(int, int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    char pad[0x10 - 4];
    unsigned char active;
    char pad1[7];
    int param;
    char pad2[0x12a0 - 0x1c];
    int field;
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20(int, int);
};
} // namespace core
void core::ControllerSystemXBox::vfunc_6(int p) {
    if (p == 0) {
        active = 0;
        f7(p, p);
        p = 10;
    } else
        active = 1;
    int x = field;
    param = p;
    ControllerSystemXBox* q = (ControllerSystemXBox*)((char*)this + 0x20);
    for (int i = 0; i < 4; i++, q = (ControllerSystemXBox*)((char*)q + 0x4a0))
        if (*((char*)q + 0x49e))
            q->g20(p, x);
}
} // namespace fn_00268390


// 0x002683f0 core::ControllerSystemXBox::vfunc_7 (74 B): matches/0x002683f0.cpp
// sym: ?vfunc_7@ControllerSystemXBox@core@@UAEXHH@Z
void core::ControllerSystemXBox::vfunc_7(int a, int b) {
    this->f_14 = b - a;
    char* p = (*(char (*)[4736])&this->f_20);
    int i = 4;
    do {
        if (p[0x49e]) {
            Pad_2683f0* q = (Pad_2683f0*)p;
            q->f18(helper() + this->f_14);
        }
        p += 0x4a0;
        --i;
    } while (i);
}


// 0x00268440 core::ControllerSystemXBox::vfunc_9 (22 B): matches/0x00268440.cpp
// sym: ?vfunc_9@ControllerSystemXBox@core@@UAEXH@Z
void core::ControllerSystemXBox::vfunc_9(int value) {
    this->f_12a0 = value;
    vfunc_6(this->f_18);
}


// 0x00268460 core::ControllerSystemXBox::vfunc_10 (17 B): matches/0x00268460.cpp
// sym: ?vfunc_10@ControllerSystemXBox@core@@UAEXH@Z
void core::ControllerSystemXBox::vfunc_10(int x) {
    if (this->f_1c == 0)
        this->f_1c = x;
}

namespace fn_fc99ffef {

// 0x00268490 FUN_00268490 (28 B): matches/0x00268490.cpp
// sym: _FUN_00268490
// data: g_obj_268490 = DAT_00528398
extern "C" void FUN_00268490() {
    if ((*(Obj_268490**)&DAT_00528398))
        (*(Obj_268490**)&DAT_00528398)->f2(1);
    (*(Obj_268490**)&DAT_00528398) = 0;
}


// 0x002684b0 FUN_002684b0 (6 B): matches/0x002684b0.cpp
// sym: _FUN_002684b0
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" hulk_intptr FUN_002684b0(void) {
    return (*(int*)&DAT_00528398);
}


// 0x002684c0 FUN_002684c0 (16 B): matches/0x002684c0.cpp
// sym: _FUN_002684c0
extern "C" void FUN_002684c0() {
    if ((*(X_2684c0**)&DAT_00528398))
        (*(X_2684c0**)&DAT_00528398)->m();
}

} // namespace fn_fc99ffef

// 0x002684e0 FUN_002684e0 (7 B): matches/0x002684e0.cpp [wrapped: conflict: core::IRefCount]
// sym: ??1IRefCount@core@fn_002684e0@@UAE@XZ
namespace fn_002684e0 {
namespace core {
class IRefCount {
  public:
    virtual ~IRefCount() throw();
};
IRefCount::~IRefCount() throw() {}
} // namespace core
} // namespace fn_002684e0

namespace fn_fc99ffef {

// 0x00268500 core::IControllerInputPointXBox::vfunc_2 (31 B): matches/0x00268500.cpp
// sym: ?f2@NonCopyable_268500@pure3d@fn_fc99ffef@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_268500* pure3d::NonCopyable_268500::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fc99ffef

// 0x00268520 FUN_00268520 (84 B): matches/0x00268520.cpp
// sym: ?FUN_00268520@ControllerXBox@core@@QAEXXZ
void core::ControllerXBox::FUN_00268520() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b14c);
    if ((*(void * *)&this->f_08))
        XInputClose((*(void * *)&this->f_08));
    unsigned long* q = (unsigned long*)((char*)this + 0x448);
    int n = 2;
    do {
        q -= 4;
        n--;
        *(hulk_uintptr*)q = ((hulk_intptr)DAT_003f6098);
    } while (n);
    q = (unsigned long*)((char*)this + 0x428);
    n = 0x14;
    do {
        q -= 0xd;
        n--;
        *(hulk_uintptr*)q = ((hulk_intptr)DAT_003f6098);
    } while (n);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f6098);
}


// 0x00268580 core::ControllerXBox::vfunc_0 (4 B): matches/0x00268580.cpp
// sym: ?vfunc_0@ControllerXBox@core@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void core::ControllerXBox::vfunc_0() {
    ++this->f_04;
}


// 0x00268590 core::ControllerXBox::vfunc_1 (4 B): matches/0x00268590.cpp
// sym: ?vfunc_1@ControllerXBox@core@@UAEXXZ
 // namespace core
void core::ControllerXBox::vfunc_1() {
    --this->f_04;
}

namespace fn_fc99ffef {

// 0x002685a0 core::ControllerXBox::vfunc_17 (233 B): equivalent/0x002685a0.cpp
// sym: ?vfunc_17@ControllerXBox@fn_fc99ffef@@UAEXH@Z @19c100d944fd @wfee701f9b2a9
// STATUS: equivalent (tools/equiv.py level 3: 20010 inputs, branch coverage 12/12)
// core::ControllerXBox::vfunc_17 @ 0x002685a0
void ControllerXBox::vfunc_17(int arg) {
    if (connected == 0)
        return;
    if (handle != 0) {
        InputState state;
        state.field_04 = 0;
        state.field_08 = 0;
        state.field_0c = 0;
        state.field_10 = 0;
        state.field_14 = 0;
        state.packet = 0;
        if (XInputGetState(handle, &state) == 0) {
            state.packet = arg;
            receiver->r5(&state);
        }
    }
    if (feedbackStatus == 0x3e5)
        return;
    short left = (short)(int)((&leftMotor)->m5() * 65535.0f);
    short right = (short)(int)((&rightMotor)->m5() * 65535.0f);
    if (left != lastLeft || right != lastRight) {
        feedbackStatus = 0;
        feedbackField = 0;
        lastLeft = left;
        lastRight = right;
        XInputSetState(handle, &feedbackStatus);
    }
}

} // namespace fn_fc99ffef

// 0x00268690 core::ControllerXBox::vfunc_18 (59 B): matches/0x00268690.cpp
// sym: ?vfunc_18@ControllerXBox@core@@UAEXH@Z
void core::ControllerXBox::vfunc_18(int arg) {
    (*(Dispatch_268690 * *)&this->f_454)->i();
    for (unsigned int i = 0; i < this->f_14; ++i)
        ((Item_268690*)((char*)this + 0x18 + i * 0x34))->call(arg);
}


// 0x002686d0 core::ControllerXBox::vfunc_19 (139 B): equivalent/0x002686d0.cpp [wrapped: conflict: core::ControllerXBox]
// sym: ?vfunc_19@ControllerXBox@core@fn_002686d0@@UAEXI@Z @01414db21563 @w283e631369bd
namespace fn_002686d0 {
// STATUS: equivalent (tools/equiv.py level 3: 65 inputs, branch coverage 12/12)
// core::ControllerXBox::vfunc_19 @ 0x002686d0
namespace core {
struct Event_2686d0 { unsigned first; unsigned second; char rest[16]; };
struct Input_2686d0 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5();
 virtual unsigned char vfunc_6(void **, unsigned); virtual unsigned char vfunc_7(Event_2686d0 *);
};
struct Listener_2686d0 {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13();
 virtual void vfunc_14(void *, unsigned *);
 char padding[0x30];
};
struct ControllerXBox {
 virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual void vfunc_11(); virtual void vfunc_12(); virtual void vfunc_13(); virtual void vfunc_14(); virtual void vfunc_15(); virtual void vfunc_16(); virtual void vfunc_17(); virtual void vfunc_18();
 virtual void vfunc_19(unsigned);
 unsigned active; char pad0[0xc]; unsigned listenerCount; Listener_2686d0 listeners[1]; char pad1[0x454 - 0x18 - 0x34]; Input_2686d0 *input;
};
void ControllerXBox::vfunc_19(unsigned unused) {
 if (!active) return;
 void *item = 0;
 if (!input->vfunc_6(&item,4)) return;
 Event_2686d0 event;
 do {
  if (input->vfunc_7(&event) != 1) break;
  for (unsigned i = 0; i < listenerCount; ++i)
   listeners[i].vfunc_14(item,&event.second);
 } while (input->vfunc_6(&item,4));
}
}
} // namespace fn_002686d0


// 0x00268760 core::ControllerXBox::vfunc_20 (30 B): matches/0x00268760.cpp
// sym: ?vfunc_20@ControllerXBox@core@@UAEXII@Z
void core::ControllerXBox::vfunc_20(unsigned int a, unsigned int b) {
    (*(Target_268760 * *)&this->f_454)->f4(a / b + 2);
}


// 0x002687b0 core::ControllerXBox::vfunc_3 (11 B): matches/0x002687b0.cpp
// sym: ?vfunc_3@ControllerXBox@core@@UAE_NXZ
 // namespace core
bool core::ControllerXBox::vfunc_3() {
    return this->f_08 != 0;
}

namespace fn_fc99ffef {

// 0x002687c0 core::ControllerXBox::vfunc_4 (6 B): matches/0x002687c0.cpp
// sym: _FUN_002687c0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002687c0() {
    return &(*(int*)&DAT_0042b1a8);
}


// 0x002687d0 core::ControllerXBox::vfunc_5 (6 B): matches/0x002687d0.cpp
// sym: _FUN_002687d0
// Same code shape as 0x0008ceb0 (propagated; names are from that function)
extern "C" int* FUN_002687d0() {
    return &(*(int*)&DAT_0042b1b8);
}


// 0x002687e0 core::ControllerXBox::vfunc_8 (120 B): matches/0x002687e0.cpp
// sym: ?Count@ControllerXBox_2687e0@fn_fc99ffef@@UAEHPBD@Z
int ControllerXBox_2687e0::Count(const char* name) {
    int n = 0;
    for (unsigned int i = 0; i < mCount; i++) {
        if (strcmp(mElems[i].Name(), name) == 0)
            n++;
    }
    return n;
}


// 0x00268860 core::ControllerXBox::vfunc_13 (115 B): matches/0x00268860.cpp
// sym: ?Count@ControllerXBox_268860@fn_fc99ffef@@QAEHPBD@Z
int ControllerXBox_268860::Count(const char* s) {
    int n = 0;
    for (int i = 0; i < 2; i++) {
        if (strcmp(e[i].Name(), s) == 0)
            n++;
    }
    return n;
}


// 0x002688e0 core::ControllerXBox::vfunc_9 (130 B): matches/0x002688e0.cpp
// sym: ?Find@ControllerXBox@fn_fc99ffef@@UAEPAV12@PBDH@Z
ControllerXBox* ControllerXBox::Find(const char* name, int which) {
    int found = 0;
    for (unsigned i = 0; i < (unsigned)count; ++i) {
        if (strcmp(entries[i].GetName(), name) == 0) {
            if (found == which)
                return (ControllerXBox*)((char*)this + 0x18 + i * 0x34);
            ++found;
        }
    }
    return 0;
}

} // namespace fn_fc99ffef

// 0x00268970 core::ControllerXBox::vfunc_14 (153 B): equivalent/0x00268970.cpp [wrapped: conflict: core::ControllerXBox]
// sym: ?vfunc_14@ControllerXBox@core@fn_00268970@@UAEPAUEntry_268970@23@PBDH@Z @709984aa058c @w62b4e32ea790
namespace fn_00268970 {
// STATUS: equivalent (tools/equiv.py level 3: 81 inputs, branch coverage 13/14, incomplete)
// core::ControllerXBox::vfunc_14 @ 0x00268970
namespace core {
struct Entry_268970 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual const char* vfunc_4();
    char reserved[12];
};
struct ControllerXBox {
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
    virtual Entry_268970* vfunc_14(const char* name, int ordinal);
    char reserved[0x424];
    Entry_268970 entries[2];
};
Entry_268970* ControllerXBox::vfunc_14(const char* name, int ordinal) {
    int matches = 0;
    for (unsigned int i = 0; i < 2; ++i) {
        const char* candidate = entries[i].vfunc_4();
        const char* requested = name;
        while (*candidate == *requested) {
            if (*candidate == '\0') {
                if (matches == ordinal)
                    return &entries[i];
                ++matches;
                break;
            }
            ++candidate;
            ++requested;
        }
    }
    return 0;
}
}
} // namespace fn_00268970


// 0x00268a10 core::ControllerXBox::vfunc_10 (111 B): matches/0x00268a10.cpp
// sym: ?vfunc_10@ControllerXBox@core@@UAEPAXPAX@Z
void* core::ControllerXBox::vfunc_10(void* __p0) { const char * s = (const char *)__p0;

    unsigned int i;
    for (i = 0; i < this->f_14; i++) {
        Entry_268a10* e = (Entry_268a10*)((char*)this + 0x18 + i * 0x34);
        if (strcmp(s, e->Name()) == 0)
            return (void*)((Entry_268a10*)((char*)this + 0x18 + i * 0x34));
    }
    return (void*)(0);
}


// 0x00268a80 core::ControllerXBox::vfunc_15 (118 B): matches/0x00268a80.cpp
// sym: ?vfunc_15@ControllerXBox@core@@UAEPAXPAX@Z
void* core::ControllerXBox::vfunc_15(void* __p0) { const char * s = (const char *)__p0;

    for (unsigned i = 0; i < 2; i++) {
        Item_268a80* p = (Item_268a80*)((char*)this + 0x428 + i * 16);
        if (strcmp(s, p->get()) == 0)
            return (void*)((core::ControllerXBox*)((char*)this + i * 16 + 0x428));
    }
    return (void*)(0);
}


// 0x00268b00 core::ControllerXBox::vfunc_6 (7 B): matches/0x00268b00.cpp
// sym: ?vfunc_6@ControllerXBox@core@@UAEPAXXZ
 // namespace core
void* core::ControllerXBox::vfunc_6() {
    return (void*)((char*)this + 0x448);
}

namespace fn_fc99ffef {

// 0x00268b10 core::ControllerXBox::vfunc_7 (4 B): matches/0x00268b10.cpp
// sym: ?target@fn_fc99ffef@@YIIPAUX_268b10@1@@Z
// Same code shape as 0x000862d0 (propagated; names are from that function)
unsigned __fastcall target(X_268b10* self) {
    return self->value;
}

} // namespace fn_fc99ffef

// 0x00268b20 core::ControllerXBox::vfunc_11 (24 B): matches/0x00268b20.cpp
// sym: ?vfunc_11@ControllerXBox@core@@UAEPAXI@Z
void* core::ControllerXBox::vfunc_11(unsigned int index) {
    if (index < this->f_14)
        return (void*)((core::ControllerXBox*)((char*)this + index * 0x34 + 0x18));
    return (void*)(0);
}


// 0x00268b40 core::ControllerXBox::vfunc_12 (6 B): matches/0x00268b40.cpp
// sym: ?vfunc_12@ControllerXBox@core@@UAEHXZ
// Same code shape as 0x0004e0b0 (propagated; names are from that function)
int core::ControllerXBox::vfunc_12() {
    return 2;
}


// 0x00268b50 core::ControllerXBox::vfunc_16 (27 B): matches/0x00268b50.cpp
// sym: ?vfunc_16@ControllerXBox@core@@UAEPAXI@Z
void* core::ControllerXBox::vfunc_16(unsigned int index) {
    if (index < 2)
        return (void*)((char*)this + index * 16 + 0x428);
    return (void*)(0);
}


// 0x00268b70 core::ControllerXBox::vfunc_2 (30 B): matches/0x00268b70.cpp
// sym: ??_GControllerXBox@core@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
core::ControllerXBox::~ControllerXBox() {}

namespace fn_fc99ffef {

// 0x00268ba0 core::IControllerXBox::vfunc_2 (31 B): matches/0x00268ba0.cpp
// sym: ?f2@NonCopyable_268ba0@pure3d@fn_fc99ffef@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_268ba0* pure3d::NonCopyable_268ba0::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fc99ffef

// 0x00268be0 core::ControllerOutputPointXBox::vfunc_0 (4 B): matches/0x00268be0.cpp
// sym: ?vfunc_0@ControllerOutputPointXBox@core@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void core::ControllerOutputPointXBox::vfunc_0() {
    ++this->f_04;
}


// 0x00268bf0 core::ControllerOutputPointXBox::vfunc_1 (4 B): matches/0x00268bf0.cpp
// sym: ?vfunc_1@ControllerOutputPointXBox@core@@UAEXXZ
// Same code shape as 0x00268590 (propagated; names are from that function)
 // namespace core
void core::ControllerOutputPointXBox::vfunc_1() {
    --this->f_04;
}

namespace fn_fc99ffef {

// 0x00268c00 core::ControllerOutputPointXBox::vfunc_3 (4 B): matches/0x00268c00.cpp
// sym: ?FUN_00268c00@fn_fc99ffef@@YIHPAX@Z
// Same code shape as 0x00086320 (propagated; names are from that function)
int __fastcall FUN_00268c00(void* p) {
    return *(int*)((char*)p + 8);
}

} // namespace fn_fc99ffef

// 0x00268c10 core::ControllerOutputPointXBox::vfunc_4 (6 B): matches/0x00268c10.cpp
// sym: ?vfunc_4@ControllerOutputPointXBox@core@@UAEPAXXZ
void* core::ControllerOutputPointXBox::vfunc_4() {
    return (void*)("Analog");
}


// 0x00268c20 core::ControllerOutputPointXBox::vfunc_5 (4 B): matches/0x00268c20.cpp
// sym: ?vfunc_5@ControllerOutputPointXBox@core@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg core::ControllerOutputPointXBox::vfunc_5() {
    return this->f_0c;
}


// 0x00268c30 core::ControllerOutputPointXBox::vfunc_6 (64 B): matches/0x00268c30.cpp
// sym: ?vfunc_6@ControllerOutputPointXBox@core@@UAEXM@Z
void core::ControllerOutputPointXBox::vfunc_6(float x) {
    if (x < 0.0f)
        this->f_0c = 0.0f;
    else if (x > 1.0f)
        this->f_0c = 1.0f;
    else
        this->f_0c = x;
}

namespace fn_fc99ffef {

// 0x00268c70 core::ControllerOutputPointXBox::vfunc_2 (31 B): matches/0x00268c70.cpp
// sym: ?f2@NonCopyable_268c70@pure3d@fn_fc99ffef@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_268c70* pure3d::NonCopyable_268c70::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fc99ffef

// 0x00268cd0 core::ControllerInputPointXBox::vfunc_0 (4 B): matches/0x00268cd0.cpp
// sym: ?vfunc_0@ControllerInputPointXBox@core@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void core::ControllerInputPointXBox::vfunc_0() {
    ++this->f_04;
}


// 0x00268ce0 core::ControllerInputPointXBox::vfunc_1 (4 B): matches/0x00268ce0.cpp
// sym: ?vfunc_1@ControllerInputPointXBox@core@@UAEXXZ
// Same code shape as 0x00268590 (propagated; names are from that function)
 // namespace core
void core::ControllerInputPointXBox::vfunc_1() {
    --this->f_04;
}


// 0x00268cf0 core::ControllerInputPointXBox::vfunc_13 (17 B): matches/0x00268cf0.cpp
// sym: ?vfunc_13@ControllerInputPointXBox@core@@UAEXH@Z
void core::ControllerInputPointXBox::vfunc_13(int value) {
    this->f_18 = 0;
    this->f_1c = value;
}


// 0x00268d10 core::ControllerInputPointXBox::vfunc_12 (20 B): matches/0x00268d10.cpp
// sym: ?vfunc_12@ControllerInputPointXBox@core@@UAEXH@Z
 // namespace core
void core::ControllerInputPointXBox::vfunc_12(int __p0) { u32_268d10 arg = (u32_268d10)__p0;

    this->f_08 = ((This_GetPointX*)this)->GetPointX(arg);
}


// 0x00268d30 FUN_00268d30 (181 B): equivalent/0x00268d30.cpp
// sym: ?FUN_00268d30@InputValue_268d30@owners@@QAENPAI@Z @a4e9745d7414 @we22be9effbbe
// STATUS: equivalent (tools/equiv.py level 3: 20006 inputs, branch coverage 14/14)
// FUN_00268d30 @ 0x00268d30
double owners::InputValue_268d30::FUN_00268d30(unsigned int *source)
{
    if (!source) return 0.0;
    if (kind == (*(void**)&DAT_004cd698)) return ((*source & data) != 0) ? 1.0f : 0.0f;
    if (kind == (*(void**)&DAT_004cd69c)) return ((unsigned char *)(data + (hulk_uintptr)source))[0] * 0.00392156862745098;
    if (kind == (*(void**)&DAT_004cd6a0) || kind == (*(void**)&DAT_004cd6a4)) {
        short value = ((short *)(data + (hulk_uintptr)source))[0];
        if (value > 0) return (double)value * 1.52592547e-05f + 0.5f;
        return (double)value * 1.52587891e-05f + 0.5f;
    }
    return 0.0;
}


// 0x00268df0 core::ControllerInputPointXBox::vfunc_3 (4 B): matches/0x00268df0.cpp
// sym: ?vfunc_3@ControllerInputPointXBox@core@@UAEHXZ
// Same code shape as 0x00086290 (propagated; names are from that function)
int core::ControllerInputPointXBox::vfunc_3() {
    return this->f_24;
}

namespace fn_fc99ffef {

// 0x00268e00 core::ControllerInputPointXBox::vfunc_4 (4 B): matches/0x00268e00.cpp
// sym: ?target@fn_fc99ffef@@YIIPAVC_268e00@1@@Z
// Same code shape as 0x00086280 (propagated; names are from that function)
unsigned int __fastcall target(C_268e00* self) {
    return self->value;
}

} // namespace fn_fc99ffef

// 0x00268e10 core::ControllerInputPointXBox::vfunc_5 (64 B): matches/0x00268e10.cpp
// sym: ?vfunc_5@ControllerInputPointXBox@core@@UAEXM@Z
 // namespace core
void core::ControllerInputPointXBox::vfunc_5(float input) {
    if (input < DAT_003f32e0)
        this->f_14 = 0.0f;
    else if (input > DAT_003f32dc)
        this->f_14 = 1.0f;
    else
        this->f_14 = input;
}


// 0x00268e50 core::ControllerInputPointXBox::vfunc_6 (4 B): matches/0x00268e50.cpp
// sym: ?vfunc_6@ControllerInputPointXBox@core@@UAEMXZ
// Same code shape as 0x00069050 (propagated; names are from that function)
hulk_freg core::ControllerInputPointXBox::vfunc_6() {
    return this->f_14;
}


// 0x00268e60 core::ControllerInputPointXBox::vfunc_7 (24 B): matches/0x00268e60.cpp
// sym: ?vfunc_7@ControllerInputPointXBox@core@@UAEXHH@Z
void core::ControllerInputPointXBox::vfunc_7(int a, int b) {
    if (*(int*)((char*)&this->f_2c) == 0) {
        *(int*)((char*)&this->f_30) = b;
        *(int*)((char*)&this->f_2c) = a;
    }
}


// 0x00268e80 core::ControllerInputPointXBox::vfunc_8 (20 B): matches/0x00268e80.cpp
// sym: ?vfunc_8@ControllerInputPointXBox@core@@UAEXH@Z
void core::ControllerInputPointXBox::vfunc_8(int x) {
    if (this->f_2c == x) {
        this->f_2c = 0;
        this->f_30 = 0;
    }
}


// 0x00268ea0 core::ControllerInputPointXBox::vfunc_9 (28 B): matches/0x00268ea0.cpp
// sym: ?vfunc_9@ControllerInputPointXBox@core@@UAEMPAX@Z
hulk_freg core::ControllerInputPointXBox::vfunc_9(void* __p0) { unsigned int * p = (unsigned int *)__p0;

    if (p)
        *p = this->f_18;
    return (this->f_10 - this->f_0c) * this->f_08 + this->f_0c;
}


// 0x00268ec0 core::ControllerInputPointXBox::vfunc_10 (17 B): matches/0x00268ec0.cpp
// sym: ?vfunc_10@ControllerInputPointXBox@core@@UAEXPAX0@Z
void core::ControllerInputPointXBox::vfunc_10(void* __p0, void* __p1) { void * x = (void *)__p0; void * y = (void *)__p1;

    (*(hulk_intptr *)&this->f_0c) = (hulk_intptr)x;
    (*(hulk_intptr *)&this->f_10) = (hulk_intptr)y;
}


// 0x00268ee0 core::ControllerInputPointXBox::vfunc_11 (29 B): matches/0x00268ee0.cpp
// sym: ?vfunc_11@ControllerInputPointXBox@core@@UAEXPAX0@Z
void core::ControllerInputPointXBox::vfunc_11(void* __p0, void* __p1) { unsigned long * a = (unsigned long *)__p0; unsigned long * b = (unsigned long *)__p1;

    if (a)
        *a = (*(unsigned long *)&this->f_0c);
    if (b)
        *b = (*(unsigned long *)&this->f_10);
}


// 0x00268f00 core::ControllerInputPointXBox::vfunc_14 (123 B): matches/0x00268f00.cpp
// sym: ?vfunc_14@ControllerInputPointXBox@core@@UAEXHH@Z
void core::ControllerInputPointXBox::vfunc_14(int a, int b) {
    float value = ((This_Convert*)this)->Convert(b);
    if (value == this->f_08 || !((float)fabs(value - this->f_08) >= this->f_14))
        this->f_18 = a - this->f_1c;
    else {
        this->f_08 = value;
        this->f_1c = a;
        this->f_18 = 0;
        if ((*(Callback_268f00 * *)&this->f_2c))
            (*(Callback_268f00 * *)&this->f_2c)->Call(this->f_30, (this->f_10 - this->f_0c) * value + this->f_0c);
    }
}

namespace fn_fc99ffef {

// 0x00268f80 core::ControllerInputPointXBox::vfunc_2 (31 B): matches/0x00268f80.cpp
// sym: ?f2@NonCopyable_268f80@pure3d@fn_fc99ffef@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_268f80* pure3d::NonCopyable_268f80::f2(unsigned char param) {
    *(void**)this = (void**)DAT_003f6098;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fc99ffef

// 0x00268fa0 FUN_00268fa0 (133 B): equivalent/0x00268fa0.cpp [wrapped: conflict: core::ControllerInputPointXBox; core::ControllerOutputPointXBox; core::ControllerXBox]
// sym: ??0ControllerXBox@core@fn_00268fa0@@QAE@XZ @9c5980027dd9 @wcd20624430d8
namespace fn_00268fa0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00268fa0 @ 0x00268fa0
namespace core {
struct ControllerInputPointXBox {
    virtual void dummy();
    int values[3];
    float scale;
    int rest[8];
};
struct ControllerOutputPointXBox {
    virtual void dummy();
    int values[3];
};
struct ControllerXBox {
    virtual void dummy();
    int values[5];
    ControllerInputPointXBox inputs[20];
    ControllerOutputPointXBox outputs[2];
    char reserved[0x56];
    char active;
    ControllerXBox();
};
ControllerXBox::ControllerXBox() {
    for (int i = 0; i < 5; ++i) values[i] = 0;
    for (int j = 0; j < 20; ++j) {
        for (int k = 0; k < 3; ++k) inputs[j].values[k] = 0;
        inputs[j].scale = 1.0f;
        for (int k = 0; k < 8; ++k) inputs[j].rest[k] = 0;
    }
    for (int j = 0; j < 2; ++j)
        for (int k = 0; k < 3; ++k) outputs[j].values[k] = 0;
    active = 0;
}
}
} // namespace fn_00268fa0


// 0x00269030 FUN_00269030 (278 B): equivalent/0x00269030.cpp [wrapped: conflict: core::ControllerSystemXBox; core::IControllerSystem; core::Object]
// sym: ??0ControllerSystemXBox@core@fn_00269030@@QAE@HH@Z @32c9a96c3c00 @w13cafe2c7baa
namespace fn_00269030 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 12/12)
// FUN_00269030 @ 0x00269030

struct ControllerXBox_269030 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(int, int);
    char reserved[0x49a]; unsigned char enabled; char end;
    void FUN_00268fa0();
};
struct Device_269030 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(int, int); };
int FUN_002705f0();
int FUN_00267f80();
void __cdecl FUN_00270940(Device_269030**, int);
namespace core {
struct Object { virtual void b0(); int id; Object() : id(DAT_004cdbb0) { FUN_002705f0(); } };
struct IControllerSystem {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void a5(); virtual void a6(int) = 0; virtual void a7(int, int) = 0;
};
struct ControllerSystemXBox : IControllerSystem, Object {
    int valuec; unsigned char value10; char gap11[3];
    int value14; int value18; int value1c;
    char padBytes[4 * 0x4a0];
    int value12a0; int value12a4;
    virtual void a6(int);
    virtual void a7(int, int);
    virtual void b0();
    void vfunc_7(int, int);
    ControllerSystemXBox(int first, int second);
};
ControllerSystemXBox::ControllerSystemXBox(int first, int second) {
    ControllerXBox_269030* pads = (ControllerXBox_269030*)padBytes;
    valuec = 0; value10 = 0; value14 = 0; value18 = 0; value1c = 0;
    for (int i = 0; i < 4; ++i) pads[i].FUN_00268fa0();
    FUN_002705f0();
    value12a0 = 10;
    value12a4 = FUN_00267f80();
    Device_269030** devices = ((Device_269030**)&DAT_00528388);
    for (int j = 0; j < 4; ++j) {
        FUN_00270940(&devices[j], second);
        devices[j]->d3(3, 22);
    }
    if (first && !value1c) value1c = first;
    value12a0 = 10;
    IControllerSystem* sys = this;
    sys->a6(value18);
    ControllerSystemXBox::vfunc_7(0, 0);
    value10 = 0;
    sys->a7(0, 0);
    int x = value12a0;
    value18 = 10;
    for (int k = 0; k < 4; ++k)
        if (pads[k].enabled) pads[k].m20(10, x);
}
}
} // namespace fn_00269030


// 0x00269150 core::ControllerSystemXBox::vfunc_0 (4 B): matches/0x00269150.cpp
// sym: ?vfunc_0@ControllerSystemXBox@core@@UAEXXZ
// Same code shape as 0x00267ba0 (propagated; names are from that function)
void core::ControllerSystemXBox::vfunc_0() {
    ++this->f_0c;
}


// 0x00269160 core::ControllerSystemXBox::vfunc_1 (4 B): matches/0x00269160.cpp
// sym: ?vfunc_1@ControllerSystemXBox@core@@UAEXXZ
 // namespace core
void core::ControllerSystemXBox::vfunc_1() {
    --this->f_0c;
}


// 0x00269170 core::ControllerSystemXBox::vfunc_12 (120 B): matches/0x00269170.cpp
// sym: ?vfunc_12@ControllerSystemXBox@core@@UAEXXZ
void core::ControllerSystemXBox::vfunc_12() {
    unsigned int now = GetTime();
    if (now - this->f_12a4 >= (*(unsigned int *)&this->f_12a0)) {
        this->f_12a4 = now;
        ((ControllerSystemXBox_nv_269170*)this)->Poll();
        for (int i = 0; i < 4; i++) {
            if ((*(Pad_269170 (*)[4])&this->f_20)[i].mActive && (*(Pad_269170 (*)[4])&this->f_20)[i].Ready())
                (*(Pad_269170 (*)[4])&this->f_20)[i].Update((*(unsigned int *)&this->f_14) + now);
        }
        if (!(*(bool *)&this->f_10))
            vfunc_8(GetTime());
    }
}


// 0x002691f0 FUN_002691f0 (199 B): equivalent/0x002691f0.cpp [wrapped: conflict: FUN_00267f80]
// sym: ?FUN_002691f0@Manager_2691f0@fn_002691f0@@QAEXXZ @030c1c3a8411 @w1a9964fcd244
namespace fn_002691f0 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_002691f0 @ 0x002691f0

struct Device_2691f0 {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(void*);
    char padding[0x49a];
    unsigned char active;
    char endpad;
    void FUN_002692c0(void*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
struct Observer_2691f0 { virtual void slot0(Device_2691f0*); };
struct Manager_2691f0 {
    char pad[0x14];
    unsigned base;
    unsigned param;
    Observer_2691f0* observer;
    Device_2691f0 devices[4];
    unsigned extra;
    void FUN_002691f0();
};
extern int DAT_003ea774;
namespace XAPILIB {
    int __stdcall XGetDeviceChanges(int*, unsigned*, unsigned*);
    void* __stdcall XInputOpen(int*, unsigned, unsigned, unsigned);
}
extern unsigned FUN_00267f80();
void Manager_2691f0::FUN_002691f0() {
    unsigned inserted = 0, removed = 0;
    if (!XAPILIB::XGetDeviceChanges(&DAT_003ea774, &inserted, &removed)) return;
    for (unsigned i = 0; i < 4; ++i) {
        if (((inserted | removed) & (1u << i)) == 0) continue;
        Device_2691f0& device = devices[i];
        void* handle = XAPILIB::XInputOpen(&DAT_003ea774, i, 0, 0);
        if (handle) {
            if (device.active) device.slot21(handle);
            else {
                unsigned time = FUN_00267f80();
                device.FUN_002692c0(handle, i, 0, time + base, param, extra, ((hulk_uintptr*)&DAT_00528388)[i]);
            }
        } else if (device.active) {
            device.slot21(0);
        }
        if (observer) observer->slot0(&device);
    }
}
} // namespace fn_002691f0

namespace fn_fc99ffef {

// 0x002692c0 FUN_002692c0 (300 B): equivalent/0x002692c0.cpp
// sym: ?FUN_002692c0@Device_2692c0@fn_fc99ffef@@QAEXIIIIIII@Z @674bbbb8e9be @wdfe7d9fec6c8
// STATUS: equivalent (tools/equiv.py level 3: 280 inputs, branch coverage 4/4)
// FUN_002692c0 @ 0x002692c0
void Device_2692c0::FUN_002692c0(hulk_uintptr a,unsigned int b,unsigned int c,unsigned int d,unsigned int e,unsigned int f,unsigned int g)
{
    handle=a; slot=b; port=c; count=0;
    active=0;
    for(int i=0;i<0x46;i++) zeros[i]=0;
    other=g;
    name0=(*(unsigned int*)&DAT_0042b2f0); name1=(*(unsigned int*)((char*)&DAT_0042b2f0 + 4)); name2=(*(unsigned int*)((char*)&DAT_0042b2f0 + 8));
    ((unsigned char*)&name2)[2]=(unsigned char)(c+0x30);
    ((unsigned char*)&name1)[0]=(unsigned char)(b+0x30);
    count=20;
    for(unsigned int j=0;j<count;j++) {
        entries[j].values=((Triple_2692c0*)&DAT_004cd6a8)[j];
        if(handle) {
            unsigned char state[22];
            for(int k=0;k<22;k++) state[k]=0;
            XAPILIB::XInputGetState(handle,state);
            (&entries[j].input)->f12(state+4);
        }
    }
    leftName=((char*)&DAT_0042b2e4);
    rightName=((char*)&DAT_0042b2d8);
    active=1;
    f20(e,f);
    f18(d);
}

} // namespace fn_fc99ffef

// 0x002693f0 core::ControllerSystemXBox::vfunc_3 (43 B): matches/0x002693f0.cpp
// sym: ?vfunc_3@ControllerSystemXBox@core@@UAEHXZ
int core::ControllerSystemXBox::vfunc_3() {
    int n = 0;
    for (int i = 0; i < 4; ++i)
        if ((*(Pad_2693f0 (*)[4])&this->f_20)[i].f3())
            ++n;
    return n;
}


// 0x00269420 core::ControllerSystemXBox::vfunc_4 (72 B): matches/0x00269420.cpp
// sym: ?vfunc_4@ControllerSystemXBox@core@@UAEPAXH@Z
void* core::ControllerSystemXBox::vfunc_4(int param) {
    int count = 0;
    for (unsigned int i = 0; i < 4; i++) {
        if ((*(Pad_269420 (*)[4])&this->f_20)[i].IsConnected()) {
            if (count == param)
                return (void*)(&(*(Pad_269420 (*)[4])&this->f_20)[i]);
            ++count;
        }
    }
    return (void*)(0);
}


// 0x00269470 core::ControllerSystemXBox::vfunc_5 (127 B): equivalent/0x00269470.cpp
// sym: ?vfunc_5@ControllerSystemXBox@core@@UAEPAXH@Z @cb84156f988c @w67b8abfc0109
// STATUS: equivalent (tools/equiv.py level 3: 70 inputs, branch coverage 13/14, incomplete)
// core::ControllerSystemXBox::vfunc_5 @ 0x00269470
void* core::ControllerSystemXBox::vfunc_5(hulk_intptr __p0) { const char * name = (const char *)__p0;

    for (unsigned i = 0; i < 4; ++i) {
        ControllerDevice* device = &(*(ControllerDevice (*)[4])&this->f_20)[i];
        if (!device->vfunc_3()) continue;
        const char* candidate = device->vfunc_6();
        const char* requested = name;
        while (*candidate && *candidate == *requested) {
            ++candidate;
            ++requested;
        }
        if (*candidate == *requested) return (void*)(device);
    }
    return (void*)(0);
}


// 0x002694f0 core::ControllerSystemXBox::vfunc_8 (49 B): matches/0x002694f0.cpp
// sym: ?vfunc_8@ControllerSystemXBox@core@@UAEXI@Z
void core::ControllerSystemXBox::vfunc_8(unsigned int arg) {
    char* p = (char*)&this->f_20;
    for (int i = 0; i < 4; i++, p += 0x4a0) {
        if (p[0x49e])
            ((Pad_2694f0*)p)->f19(arg);
    }
}


// 0x00269530 core::ControllerSystemXBox::vfunc_11 (19 B): matches/0x00269530.cpp
// sym: ?vfunc_11@ControllerSystemXBox@core@@UAEXH@Z
void core::ControllerSystemXBox::vfunc_11(int param) {
    if (this->f_1c == param)
        this->f_1c = 0;
}


// 0x00269550 core::ControllerSystemXBox::vfunc_0_adj4 (8 B): matches/0x00269550.cpp [wrapped: no out-of-line definition (target defined in a class body)]
// sym: ?f@C_269550@fn_00269550@@W3AEXH@Z
namespace fn_00269550 {
class A_269550 {
  public:
    virtual void f(int);
};

class B_269550 {
  public:
    virtual void f(int);
};

class C_269550 : public A_269550, public B_269550 {
  public:
    virtual void f(int);
};


C_269550 gC_269550;
} // namespace fn_00269550

namespace fn_fc99ffef {

// 0x00269560 core::ControllerSystemXBox::vfunc_2 (36 B): matches/0x00269560.cpp
// sym: ?f2@ControllerSystemXBox@fn_fc99ffef@@UAEPAV12@E@Z
// data: globalValue = DAT_004cdbb0
ControllerSystemXBox* ControllerSystemXBox::f2(u8_269560 flag) {
    cleanup();
    if (flag & 1)
        FUN_00266f00(DAT_004cdbb0, this);
    return this;
}

} // namespace fn_fc99ffef

// 0x00269590 FUN_00269590 (165 B): equivalent/0x00269590.cpp [wrapped: conflict: ControllerSystemXBox; ControllerXBox; DAT_003f6098; DAT_0042b14c]
// sym: ?FUN_00269590@ControllerSystemXBox@fn_00269590@@QAEXXZ @67a23f167f37 @w28355f818bfd
namespace fn_00269590 {
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 6/6)
// FUN_00269590 @ 0x00269590

struct RefObject_269590 { virtual void slot0(); virtual void FUN_virtual1(); };
extern void* DAT_0042b2a4[];
extern void* DAT_0042b29c[];
extern void* DAT_0042b14c[];
extern void* DAT_003f6098[];
extern void* DAT_0042af64[];
extern "C++" __declspec(nothrow) void __stdcall XInputClose(void*);
extern "C" void __stdcall FUN_00013420(void*,int,int,void*);
extern "C" void FUN_00268330();
extern "C" void FUN_002684e0();
struct ControllerXBox { void** vtable; char pad[4]; void* handle; char rest[0x4a0-12]; };
struct ControllerSystemXBox { void** vtable; void** vtable2; int value; char pad[0x20-12]; ControllerXBox controllers[4]; void FUN_00269590(); };
void ControllerSystemXBox::FUN_00269590() {
 vtable=DAT_0042b2a4;
 vtable2=DAT_0042b29c;
 for(unsigned i=0;i<4;i++) { ((RefObject_269590**)&DAT_00528388)[i]->FUN_virtual1(); ((RefObject_269590**)&DAT_00528388)[i]=0; }
 for(int i=3;i>=0;--i) {
  ControllerXBox& c=controllers[i];
  void* h=c.handle;
  c.vtable=DAT_0042b14c;
  if(h) XInputClose(h);
  FUN_00013420((char*)&c+0x428,0x10,2,(void*)&FUN_00268330);
  FUN_00013420((char*)&c+0x18,0x34,0x14,(void*)&FUN_002684e0);
  c.vtable=DAT_003f6098;
 }
 DAT_004cdbb0=value;
 vtable2=DAT_0042af64;
 vtable=DAT_003f6098;
}
} // namespace fn_00269590

namespace fn_fc99ffef {

// 0x00269640 FUN_00269640 (61 B): matches/0x00269640.cpp
// sym: _FUN_00269640
extern "C" void __cdecl FUN_00269640(u32_269640 a, u32_269640 b) {
    HULK_SIZE32(CoreControllerSystemXBox, 0x12a8);
    u32_269640 v = b;
    *(volatile u32_269640*)((hulk_intptr)((char*)&DAT_004cdbb0)) = v;
    hulk_uintptr x = FUN_00266e00(v, (u32_269640)sizeof(CoreControllerSystemXBox));
    if (x)
        *(volatile u32_269640*)((hulk_intptr)DAT_00528398) = ((ControllerSystemXBox_nv_269640*)(((core::ControllerSystemXBox*)(((core::ControllerSystemXBox*)x)))))->Make(a, v);
    else
        *(volatile u32_269640*)((hulk_intptr)DAT_00528398) = 0;
}

} // namespace fn_fc99ffef
