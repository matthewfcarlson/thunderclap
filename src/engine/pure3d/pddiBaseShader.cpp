// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00327910..0x00328250 (kind game, layer engine, confidence high), dominant class pure3d::pddiBaseShader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fbec554b {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fbec554b {} using namespace fn_fbec554b;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fbec554b {
extern void* vShader[];
class pddiObject_327910 {
  public:
    void* vptr;
    pddiObject_327910();
};
class pddiShader : public pddiObject_327910 {
  public:
    pddiShader();
};
extern "C" char DAT_00433568[];
extern "C" char DAT_0043359c[];
typedef unsigned int u32_327930;
extern u32_327930 g_327930;
extern "C" void __fastcall FUN_0031bae0(void*);
class pddiShader_327a40 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
class Handler_327a40 {
  public:
    void h(int);
};
typedef void (Handler_327a40::*HFn)(int);
struct Entry_327a40 {
    int key;
    int a;
    HFn fn;
    int off;
    int p1;
    int p2;
};
class pddiBaseShader_327a40 : public pddiShader_327a40 {
  public:
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
    virtual Entry_327a40* f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    char pad[8];
    int member;
};
class Helper_327aa0 {
  public:
    void run(int);
};
struct Node {
    int key;
    int pad;
    void (Helper_327aa0::*fn)(int);
    int context;
    char pad10[8];
};
class pddiBaseShader_327aa0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual unsigned char f7(int, int);
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual Node* get();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    char pad4[8];
    int id;
};
class Target_327b60 {
  public:
    void m(int);
};
struct Entry_327b60 {
    int key;
    int p1;
    void (Target_327b60::*fn)(int);
    int off;
    int pad1;
    int pad2;
};
class Callback_327bc0 {
  public:
    void Dummy();
};
typedef void (Callback_327bc0::*InvokeFn)(int);
struct Item_327bc0 {
    int key;
    int x;
    InvokeFn fn;
    int adj;
    int pad[2];
};
class pddiBaseShader {
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
    virtual bool f9(int, int);
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual Entry_327b60* f19();
    virtual Item_327bc0* GetResult();
    char _m_pad_4[0x8];
    int id;
    bool v10(int key, int arg);
};
struct Entry_327c20 { char text[64]; unsigned int value1; unsigned int value2; };
typedef int(__cdecl* Handler_327c70)(int, const char*, int);
struct Entry_327c70 {
    char name[64];
    Handler_327c70 handler;
    int context;
};
class Target_327d00 {
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
    virtual int Check();
    int pad[2];
    int value;
    int TargetFunction();
};
typedef unsigned int u32_327d20;
class Obj_327d20 {
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
    virtual int l();
    virtual void m();
    virtual void n();
    virtual void o(u32_327d20);
    void target(u32_327d20);
};
extern int g_current;
class Target_327d80 {
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
    virtual void v14(int);
    char pad[8];
    int key;
    void run(int, char);
};
class Obj_327dd0 {
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
};
class pddiShader_327e00 {
  public:
    pddiShader_327e00();
    virtual void f();
};
class pddiBaseShader_327e00 : public pddiShader_327e00 {
  public:
    pddiBaseShader_327e00();
    int pad[2];
    int id;
};
} // namespace fn_fbec554b
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_fbec554b {
class d3dErrorShader_327e60 {
  public:
    d3dErrorShader_327e60(int) throw();
    char pad[0x80];
};
void* FUN_0008d690(unsigned int);
class d3dSimpleShader_327e90 {
  public:
    d3dSimpleShader_327e90* Init(void* arg);
};
extern "C" void* __cdecl Alloc(hulk_uintptr);
class d3dLightMapShader_327ec0 {
  public:
    char pad[0x94];
};
class d3dReflShader_327ef0 {
  public:
    d3dReflShader_327ef0(int) throw();
    char pad[0x8c];
};
} // namespace fn_fbec554b
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_fbec554b {
class Obj {
  public:
    void* Fn(void* arg);
};
void* __cdecl FUN_0008d690(int n);
class O {
  public:
    int M(int a);
};
class d3dLayeredLMapShader_327fb0 {
    char pad[0xa0];

  public:
    d3dLayeredLMapShader_327fb0(int) throw();
};
class d3dRefractVertexShader_327fe0 {
  public:
    d3dRefractVertexShader_327fe0(void*) throw();
    char pad[0x9c];
};
class d3dBumpMapVertexShader_3280d0 {
  public:
    void* Fn(void* a);
};
class d3dFBEffectsShader_328100 {
    char pad[0x98];

  public:
    d3dFBEffectsShader_328100(int) throw();
};
typedef void (__cdecl *Callback_328130)();
void __cdecl FUN_00327e60();
void __cdecl FUN_00327e90();
void __cdecl FUN_00327ec0();
void __cdecl FUN_00327ef0();
void __cdecl FUN_00327f20();
void __cdecl FUN_00327f50();
void __cdecl FUN_00327f80();
void __cdecl FUN_00327fb0();
void __cdecl FUN_00327fe0();
void __cdecl FUN_00328010();
void __cdecl FUN_00328040();
void __cdecl FUN_00328070();
void __cdecl FUN_003280a0();
void __cdecl FUN_003280d0();
void __cdecl FUN_00328100();
void __cdecl FUN_00327c20(const char*, Callback_328130, int);


// 0x00327910 FUN_00327910 (18 B): matches/0x00327910.cpp
// sym: ??0pddiShader@fn_fbec554b@@QAE@XZ
pddiShader::pddiShader() : pddiObject_327910() {
    vptr = vShader;
}


// 0x00327930 FUN_00327930 (35 B): matches/0x00327930.cpp
// sym: ?target@fn_fbec554b@@YIXPAI@Z
void __fastcall target(u32_327930* self) {
    *(hulk_uintptr*)self = ((hulk_intptr)DAT_0043359c);
    if (g_327930 == (hulk_uintptr)self)
        g_327930 = 0;
    *(hulk_uintptr*)self = ((hulk_intptr)DAT_00433568);
    FUN_0031bae0((void*)(self));
}


// 0x00327960 pure3d::pddiBaseShader::vfunc_12 (1 B): matches/0x00327960.cpp
// sym: ?FUN_00327960@fn_fbec554b@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00327960() {}


// 0x00327970 pure3d::pddiBaseShader::vfunc_13 (1 B): matches/0x00327970.cpp
// sym: ?FUN_00327970@fn_fbec554b@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_00327970() {}


// 0x00327980 pure3d::pddiBaseShader::vfunc_15 (3 B): matches/0x00327980.cpp
// sym: ?GetZero@fn_fbec554b@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_fbec554b

// 0x00327990 pure3d::pddiBaseShader::vfunc_16 (3 B): matches/0x00327990.cpp [wrapped: same definition as 0x00327980 in this TU]
// sym: ?GetZero@fn_00327990@@YAIXZ
namespace fn_00327990 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_00327990


// 0x003279a0 pure3d::pddiBaseShader::vfunc_17 (3 B): matches/0x003279a0.cpp [wrapped: same definition as 0x00327980 in this TU]
// sym: ?GetZero@fn_003279a0@@YAIXZ
namespace fn_003279a0 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_003279a0


// 0x003279b0 pure3d::pddiBaseShader::vfunc_18 (3 B): matches/0x003279b0.cpp [wrapped: same definition as 0x00327980 in this TU]
// sym: ?GetZero@fn_003279b0@@YAIXZ
namespace fn_003279b0 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_003279b0


// 0x003279c0 pure3d::pddiBaseShader::vfunc_19 (3 B): matches/0x003279c0.cpp [wrapped: same definition as 0x00327980 in this TU]
// sym: ?GetZero@fn_003279c0@@YAIXZ
namespace fn_003279c0 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_003279c0


// 0x003279d0 pure3d::pddiBaseShader::vfunc_20 (3 B): matches/0x003279d0.cpp [wrapped: same definition as 0x00327980 in this TU]
// sym: ?GetZero@fn_003279d0@@YAIXZ
namespace fn_003279d0 {
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}
} // namespace fn_003279d0


// 0x003279e0 pure3d::pddiBaseShader::vfunc_5 (93 B): matches/0x003279e0.cpp [wrapped: conflict: pure3d::pddiBaseShader]
// sym: ?vfunc_5@pddiBaseShader@pure3d@fn_003279e0@@UAE_NII@Z
namespace fn_003279e0 {

struct ReceiverBaseA {
    int a;
};
struct ReceiverBaseB {
    int b;
};
struct Receiver_3279e0 : ReceiverBaseA, ReceiverBaseB {
    void set(unsigned int);
};
struct ParameterEntry_3279e0 {
    unsigned int key;
    unsigned int reserved;
    void (Receiver_3279e0::*setter)(unsigned int);
    unsigned int extra[2];
};
namespace pure3d {
struct pddiBaseShader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void FUN_00344f51();
    virtual bool vfunc_5(unsigned int key, unsigned int value);
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void slot11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void slot14();
    virtual ParameterEntry_3279e0* vfunc_15();
    unsigned int fields[2];
    unsigned int serial;
};
bool pddiBaseShader::vfunc_5(unsigned int key, unsigned int value) {
    ParameterEntry_3279e0* entry = vfunc_15();
    if (!entry)
        return false;
    for (; entry->key; ++entry) {
        if (entry->key == key) {
            (reinterpret_cast<Receiver_3279e0*>(this)->*(entry->setter))(value);
            unsigned int next = DAT_005555b8 + 1;
            DAT_005555b8 = next;
            if (next == 0xffffffffU)
                DAT_005555b8 = next = 0;
            serial = next;
            ++DAT_005555b8;
            return true;
        }
    }
    return false;
}
} // namespace pure3d
} // namespace fn_003279e0

namespace fn_fbec554b {

// 0x00327a40 pure3d::pddiBaseShader::vfunc_6 (93 B): matches/0x00327a40.cpp
// sym: ?f6@pddiBaseShader_327a40@fn_fbec554b@@UAE_NHH@Z
// data: counter = DAT_005555b8
bool pddiBaseShader_327a40::f6(int key, int arg) {
    Entry_327a40* e = f16();
    if (e && e->key) {
        do {
            if (e->key == key) {
                Handler_327a40* h = (Handler_327a40*)((char*)this + e->off);
                (h->*(e->fn))(arg);
                ++(*(int*)&DAT_005555b8);
                if ((*(int*)&DAT_005555b8) == -1)
                    (*(int*)&DAT_005555b8) = 0;
                member = (*(int*)&DAT_005555b8);
                ++(*(int*)&DAT_005555b8);
                return true;
            }
            e = (Entry_327a40*)((char*)e + 24);
        } while (e->key);
    }
    return false;
}


// 0x00327aa0 pure3d::pddiBaseShader::vfunc_7 (93 B): matches/0x00327aa0.cpp
// sym: ?f7@pddiBaseShader_327aa0@fn_fbec554b@@UAEEHH@Z
// data: gCounter_327aa0 = DAT_005555b8
unsigned char pddiBaseShader_327aa0::f7(int key, int arg) {
    Node* p = get();
    if (p) {
        while (p->key) {
            if (p->key == key) {
                Helper_327aa0* h = (Helper_327aa0*)((char*)this + p->context);
                (h->*(p->fn))(arg);
                int n = (*(int*)&DAT_005555b8) + 1;
                (*(int*)&DAT_005555b8) = n;
                if (n == -1) {
                    n = 0;
                    (*(int*)&DAT_005555b8) = n;
                }
                id = n;
                ++(*(int*)&DAT_005555b8);
                return 1;
            }
            p++;
        }
    }
    return 0;
}

} // namespace fn_fbec554b

// 0x00327b00 pure3d::pddiBaseShader::vfunc_8 (93 B): matches/0x00327b00.cpp [wrapped: conflict: pure3d::pddiBaseShader]
// sym: ?vfunc_8@pddiBaseShader@pure3d@fn_00327b00@@UAE_NII@Z
namespace fn_00327b00 {

struct Receiver_327b00 {
    void set(unsigned);
};
typedef void (Receiver_327b00::*Setter_327b00)(unsigned);
struct ParameterEntry_327b00 {
    unsigned key;
    unsigned reserved;
    Setter_327b00 setter;
    int receiverOffset;
    unsigned unused[2];
};
namespace pure3d {
struct pddiBaseShader {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void slot4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual bool vfunc_8(unsigned key, unsigned value);
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void slot11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void slot14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual ParameterEntry_327b00* vfunc_18();
    unsigned unused[2];
    unsigned changeId;
};
bool pddiBaseShader::vfunc_8(unsigned key, unsigned value) {
    ParameterEntry_327b00* entry = vfunc_18();
    if (!entry)
        return false;
    for (; entry->key; ++entry) {
        if (entry->key == key) {
            Receiver_327b00* receiver =
                reinterpret_cast<Receiver_327b00*>(reinterpret_cast<char*>(this) + entry->receiverOffset);
            (receiver->*entry->setter)(value);
            unsigned id = DAT_005555b8 + 1;
            DAT_005555b8 = id;
            if (id == ~0u) {
                id = 0;
                DAT_005555b8 = 0;
            }
            changeId = id;
            ++DAT_005555b8;
            return true;
        }
    }
    return false;
}
} // namespace pure3d
} // namespace fn_00327b00

namespace fn_fbec554b {

// 0x00327b60 pure3d::pddiBaseShader::vfunc_9 (93 B): matches/0x00327b60.cpp
// sym: ?f9@pddiBaseShader@fn_fbec554b@@UAE_NHH@Z
// data: counter = DAT_005555b8
bool pddiBaseShader::f9(int key, int arg) {
    Entry_327b60* e = f19();
    if (e) {
        while (e->key) {
            if (e->key == key) {
                Target_327b60* o = (Target_327b60*)((char*)this + e->off);
                (o->*e->fn)(arg);
                ++(*(int*)&DAT_005555b8);
                if ((*(int*)&DAT_005555b8) == -1)
                    (*(int*)&DAT_005555b8) = 0;
                id = (*(int*)&DAT_005555b8);
                ++(*(int*)&DAT_005555b8);
                return true;
            }
            e = (Entry_327b60*)((char*)e + 24);
        }
    }
    return false;
}


// 0x00327bc0 pure3d::pddiBaseShader::vfunc_10 (93 B): matches/0x00327bc0.cpp
// sym: ?v10@pddiBaseShader@fn_fbec554b@@QAE_NHH@Z
// data: counter = DAT_005555b8
bool pddiBaseShader::v10(int key, int arg) {
    Item_327bc0* p = GetResult();
    if (p) {
        int k = p->key;
        while (k) {
            if (k == key) {
                Callback_327bc0* cb = (Callback_327bc0*)((char*)this + p->adj);
                (cb->*(p->fn))(arg);
                (*(int*)&DAT_005555b8)++;
                if ((*(int*)&DAT_005555b8) == -1)
                    (*(int*)&DAT_005555b8) = 0;
                id = (*(int*)&DAT_005555b8);
                (*(int*)&DAT_005555b8)++;
                return true;
            }
            p++;
            k = p->key;
        }
    }
    return false;
}


// 0x00327c20 FUN_00327c20 (72 B): equivalent/0x00327c20.cpp
// sym: ?FUN_00327c20@fn_fbec554b@@YAXPBDII@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_00327c20 @ 0x00327c20
void __cdecl FUN_00327c20(const char* text, hulk_uintptr value1, unsigned int value2)
{
    unsigned int index = (*(unsigned int*)&DAT_005555c0);
    char* out = ((Entry_327c20*)&DAT_005555c8)[index].text;
    char c;
    do { c = *text++; *out++ = c; } while (c != 0);
    (*(unsigned int*)&DAT_005555c0) = index + 1;
    ((Entry_327c20*)&DAT_005555c8)[index].value1 = value1;
    ((Entry_327c20*)&DAT_005555c8)[index].value2 = value2;
}


// 0x00327c70 FUN_00327c70 (129 B): matches/0x00327c70.cpp
// sym: _FUN_00327c70
extern "C" int __cdecl FUN_00327c70(int first, const char* name, int context) {
    int count = (*(int*)&DAT_005555c0);
    for (int i = 0; i < count; ++i) {
        if (strcmp(name, ((Entry_327c70*)&DAT_005555c8)[i].name) == 0) {
            int replacement = ((Entry_327c70*)&DAT_005555c8)[i].context;
            if (replacement)
                context = replacement;
            return ((Entry_327c70*)&DAT_005555c8)[i].handler(first, name, context);
        }
    }
    return ((Entry_327c70*)&DAT_005555c8)[0].handler(first, name, context);
}


// 0x00327d00 FUN_00327d00 (25 B): matches/0x00327d00.cpp
// sym: ?TargetFunction@Target_327d00@fn_fbec554b@@QAEHXZ
// data: gValue_327d00 = DAT_004d40d8
int Target_327d00::TargetFunction() {
    if (value == DAT_004d40d8) {
        if (Check() == 1)
            return 1;
    }
    return 0;
}


// 0x00327d20 FUN_00327d20 (94 B): matches/0x00327d20.cpp
// sym: ?target@Obj_327d20@fn_fbec554b@@QAEXI@Z
// data: gSentinel_327d20 = DAT_004d40d8
void Obj_327d20::target(u32_327d20 arg) {
    if (*(u32_327d20*)((char*)this + 12) != (*(u32_327d20*)&DAT_004d40d8)) {
        if ((*(Obj_327d20**)&DAT_005555bc))
            (*(Obj_327d20**)&DAT_005555bc)->n();
        (*(u32_327d20*)&DAT_004d40d8) = *(u32_327d20*)((char*)this + 12);
        m();
        o(arg);
        (*(Obj_327d20**)&DAT_005555bc) = this;
    } else if (l() != 1)
        o(arg);
}


// 0x00327d80 FUN_00327d80 (74 B): matches/0x00327d80.cpp
// sym: ?run@Target_327d80@fn_fbec554b@@QAEXHD@Z
// data: g_obj_327d80 = DAT_005555bc
void Target_327d80::run(int arg, char flag) {
    if (key != g_current) {
        if ((*(Target_327d80**)&DAT_005555bc))
            (*(Target_327d80**)&DAT_005555bc)->v13();
        g_current = key;
        v12();
        (*(Target_327d80**)&DAT_005555bc) = this;
    }
    if (flag)
        v14(arg);
}


// 0x00327dd0 FUN_00327dd0 (36 B): matches/0x00327dd0.cpp
// sym: ?target@fn_fbec554b@@YAXXZ
// data: gState_327dd0 = DAT_004d40d8
void target() {
    Obj_327dd0* p = (*(Obj_327dd0**)&DAT_005555bc);
    DAT_004d40d8 = -1;
    (*(Obj_327dd0**)&DAT_005555bc) = 0;
    if (p)
        p->f13();
}


// 0x00327e00 FUN_00327e00 (32 B): matches/0x00327e00.cpp
// sym: ??0pddiBaseShader_327e00@fn_fbec554b@@QAE@XZ
// data: gCounter_327e00 = DAT_005555b8
pddiBaseShader_327e00::pddiBaseShader_327e00() {
    id = (*(int*)&DAT_005555b8)++;
}

} // namespace fn_fbec554b

// 0x00327e20 pure3d::pddiBaseShader::vfunc_3 (62 B): matches/0x00327e20.cpp [wrapped: conflict: pure3d::pddiBaseShader]
// sym: ?vfunc_3@pddiBaseShader@pure3d@fn_00327e20@@QAEPAV123@E@Z
namespace fn_00327e20 {
// data: g_cur_327e20 = DAT_005555bc

extern void* vD[];
extern void* vB[];
extern "C" void _ReadWriteBarrier();
extern "C" void thunk_FUN_00267090(void*) throw();
namespace pure3d { class pddiBaseShader; }
namespace pure3d { class pddiBaseShader {
  public:
    void* vptr;
    pddiBaseShader* vfunc_3(unsigned char f) throw();
    void Fini() throw();
}; }
pure3d::pddiBaseShader* pure3d::pddiBaseShader::vfunc_3(unsigned char f) throw() {
    vptr = vD;
    _ReadWriteBarrier();
    if ((*(pure3d::pddiBaseShader**)&DAT_005555bc) == this)
        (*(pure3d::pddiBaseShader**)&DAT_005555bc) = 0;
    vptr = vB;
    Fini();
    if (f & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_00327e20

namespace fn_fbec554b {

// 0x00327e60 FUN_00327e60 (33 B): matches/0x00327e60.cpp
// sym: ?FUN_00327e60@fn_fbec554b@@YAPAVd3dErrorShader_327e60@1@H@Z
d3dErrorShader_327e60* __cdecl FUN_00327e60(int x) {
    return new d3dErrorShader_327e60(x);
}


// 0x00327e90 FUN_00327e90 (33 B): matches/0x00327e90.cpp
// sym: ?FUN_00327e90@fn_fbec554b@@YAPAVd3dSimpleShader_327e90@1@PAX@Z
d3dSimpleShader_327e90* FUN_00327e90(void* arg) {
    d3dSimpleShader_327e90* r = (d3dSimpleShader_327e90*)FUN_0008d690(0x94);
    if (r)
        return r->Init(arg);
    return 0;
}


// 0x00327ec0 FUN_00327ec0 (33 B): matches/0x00327ec0.cpp
// sym: ?FUN_00327ec0@fn_fbec554b@@YAPAVd3dLightMapShader_327ec0@1@H@Z
d3dLightMapShader_327ec0* __cdecl FUN_00327ec0(int a) {
    d3dLightMapShader_327ec0* p = (d3dLightMapShader_327ec0*)Alloc(sizeof(d3dLightMapShader_327ec0));
    if (p)
        return ((d3dLightMapShader_327ec0 *)((pure3d::d3dLightMapShader *)p)->FUN_0032ba30(a));
    return 0;
}


// 0x00327ef0 FUN_00327ef0 (33 B): matches/0x00327ef0.cpp
// sym: ?FUN_00327ef0@fn_fbec554b@@YAPAVd3dReflShader_327ef0@1@H@Z
d3dReflShader_327ef0* __cdecl FUN_00327ef0(int x) {
    return new d3dReflShader_327ef0(x);
}


// 0x00327f20 FUN_00327f20 (33 B): matches/0x00327f20.cpp
// sym: ?FUN_00327f20@fn_fbec554b@@YAPAVObj@1@H@Z
Obj* FUN_00327f20(int x) {
    Obj* p = (Obj*)FUN_0008d690(0xc8);
    if (p)
        return ((Obj *)((pure3d::d3dProjectedTextureShader *)p)->FUN_0032cbc0((void *)(hulk_uintptr)(int)x));
    return 0;
}

} // namespace fn_fbec554b

// 0x00327f50 FUN_00327f50 (33 B): matches/0x00327f50.cpp [wrapped: conflict: operatornew]
// sym: ?FUN_00327f50@fn_00327f50@@YAPAVd3dPointSpriteShader_327f50@1@H@Z
namespace fn_00327f50 {
/* size_t: tree_prelude.h */

class d3dPointSpriteShader_327f50 {
  public:
    d3dPointSpriteShader_327f50(int) throw();
    char pad[0xa4];
};
d3dPointSpriteShader_327f50* __cdecl FUN_00327f50(int n) {
    return new d3dPointSpriteShader_327f50(n);
}
} // namespace fn_00327f50

namespace fn_fbec554b {

// 0x00327f80 FUN_00327f80 (33 B): matches/0x00327f80.cpp
// sym: ?FUN_00327f80@fn_fbec554b@@YAHH@Z
int __cdecl FUN_00327f80(int a) {
    O* p = (O*)FUN_0008d690(0x9c);
    if (p)
        return p->M(a);
    return 0;
}


// 0x00327fb0 FUN_00327fb0 (33 B): matches/0x00327fb0.cpp
// sym: ?Make@fn_fbec554b@@YAPAVd3dLayeredLMapShader_327fb0@1@H@Z
d3dLayeredLMapShader_327fb0* __cdecl Make(int x) {
    return new d3dLayeredLMapShader_327fb0(x);
}


// 0x00327fe0 FUN_00327fe0 (33 B): matches/0x00327fe0.cpp
// sym: ?makeItem@fn_fbec554b@@YAPAVd3dRefractVertexShader_327fe0@1@PAX@Z
d3dRefractVertexShader_327fe0* __cdecl makeItem(void* p) {
    return new d3dRefractVertexShader_327fe0(p);
}

} // namespace fn_fbec554b

// 0x00328010 FUN_00328010 (33 B): matches/0x00328010.cpp [wrapped: conflict: FUN_0008d690]
// sym: ?FUN_00328010@fn_00328010@@YAPAVd3dToon2VertexShader_328010@1@H@Z
namespace fn_00328010 {
class d3dToon2VertexShader_328010 {
  public:
    d3dToon2VertexShader_328010* Init(int x);
};
d3dToon2VertexShader_328010* FUN_0008d690(int n);
d3dToon2VertexShader_328010* FUN_00328010(int x) {
    d3dToon2VertexShader_328010* r = FUN_0008d690(0xdc);
    if (r)
        return r->Init(x);
    return 0;
}
} // namespace fn_00328010

namespace fn_fbec554b {

// 0x00328040 FUN_00328040 (33 B): matches/0x00328040.cpp
// sym: ?Target@fn_fbec554b@@YAPAXPAX@Z
void* Target(void* self) {
    void* p = Alloc(0xec);
    if (p)
        return ((Obj*)p)->Fn(self);
    return 0;
}

} // namespace fn_fbec554b

// 0x00328070 FUN_00328070 (33 B): matches/0x00328070.cpp [wrapped: conflict: Alloc]
// sym: ?Target@fn_00328070@@YAPAUd3dSpheremapVertexShader_328070@1@H@Z
namespace fn_00328070 {
extern "C++" __declspec(nothrow) void* __cdecl Alloc(hulk_intptr size);

struct d3dSpheremapVertexShader_328070 {
    char data[0x98];
    d3dSpheremapVertexShader_328070* Create(int arg);
};

d3dSpheremapVertexShader_328070* __cdecl Target(int arg) {
    d3dSpheremapVertexShader_328070* p = (d3dSpheremapVertexShader_328070*)Alloc(0x98);
    if (p)
        return p->Create(arg);
    return 0;
}
} // namespace fn_00328070


// 0x003280a0 FUN_003280a0 (33 B): matches/0x003280a0.cpp [wrapped: compile error in a shared declaration (C2732)]
// sym: ?FUN_003280a0@fn_003280a0@@YAPAUd3dBuildingShader_3280a0@1@PAX@Z
namespace fn_003280a0 {
typedef unsigned int uint;
extern "C++" __declspec(nothrow) void* __cdecl FUN_0008d690(uint);
struct d3dBuildingShader_3280a0 {
    d3dBuildingShader_3280a0(void*);
    d3dBuildingShader_3280a0* fn(void* p);
};
d3dBuildingShader_3280a0* __cdecl FUN_003280a0(void* p) {
    d3dBuildingShader_3280a0* r = (d3dBuildingShader_3280a0*)FUN_0008d690(0x90);
    if (r)
        return r->fn(p);
    return 0;
}
} // namespace fn_003280a0

namespace fn_fbec554b {

// 0x003280d0 FUN_003280d0 (33 B): matches/0x003280d0.cpp
// sym: ?FUN_003280d0@fn_fbec554b@@YAPAXPAX@Z
void* __cdecl FUN_003280d0(void* a) {
    d3dBumpMapVertexShader_3280d0* p = (d3dBumpMapVertexShader_3280d0*)FUN_0008d690(0x90);
    if (p)
        return p->Fn(a);
    return 0;
}


// 0x00328100 FUN_00328100 (33 B): matches/0x00328100.cpp
// sym: ?FUN_00328100@fn_fbec554b@@YAPAVd3dFBEffectsShader_328100@1@H@Z
d3dFBEffectsShader_328100* __cdecl FUN_00328100(int n) {
    return new d3dFBEffectsShader_328100(n);
}


// 0x00328130 FUN_00328130 (282 B): matches/0x00328130.cpp
// sym: _FUN_00328130
// FUN_00328130 @ 0x00328130
extern "C" void __cdecl FUN_00328130() {
 FUN_00327c20("error", FUN_00327e60, 0);
 FUN_00327c20("simple", FUN_00327e90, 0);
 FUN_00327c20("lightweight", FUN_00327e90, 0);
 FUN_00327c20("lightmap", FUN_00327ec0, 0);
 FUN_00327c20("environment", FUN_00327ef0, 0);
 FUN_00327c20("projtex", FUN_00327f20, 0);
 FUN_00327c20("pointsprite", FUN_00327f50, 0);
 FUN_00327c20("layered", FUN_00327f80, 0);
 FUN_00327c20("layeredlmap", FUN_00327fb0, 0);
 FUN_00327c20("toon2", FUN_00328010, 0);
 FUN_00327c20("toon", FUN_00328040, 0);
 FUN_00327c20("refract", FUN_00327fe0, 0);
 FUN_00327c20("spheremap", FUN_00328070, 0);
 FUN_00327c20("bumpmap", FUN_003280d0, 0);
 FUN_00327c20("layeredReflect", FUN_003280a0, 0);
 FUN_00327c20("fbeffectsshader", FUN_00328100, 0);
}

} // namespace fn_fbec554b
