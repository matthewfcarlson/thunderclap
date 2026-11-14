// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028b970..0x0028d100 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f8c9e634 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f8c9e634 {} using namespace fn_f8c9e634;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f8c9e634 {
void __cdecl thunk_FUN_0008d340(void *);
extern void *DAT_0042c920[];
extern void *DAT_0042c930[];
struct Resource {
    virtual void FUN_00000000();
    virtual void FUN_00000001();
};
struct SimpleChannel {
    void **vtable;
    char padding[8];
    Resource *resource;
    char padding2[4];
    void *data;
    void FUN_0028b970();
};
void* __cdecl FUN_0008d6d0(unsigned size);
struct Allocator {
    void* FUN_002888c0(unsigned int, int);
};
namespace pure3d {
struct FUN_0028b420 {
    virtual void unusedVirtual();
    int unused4;
    int unused8;
    Allocator* allocator;
    int count;
    int unused14;
    void* values;
    FUN_0028b420(int first, void* second);   // (x64t7) second: the parent channel (0x0028b420 keeps it as a pointer; was `int`)
};
}
namespace pure3d {
struct IntChannel : public FUN_0028b420 {
    virtual void unusedVirtual();
    IntChannel(int first, void* second);
};
}
extern void* g_f2[];
extern void* hulk_at_0042c920[];
void __cdecl Drop_0008d340(void*);
class Res_28ba20 {
  public:
    virtual void F0();
    virtual void Release();
};
class IntChannel_28ba20 {
  public:
    void* vptr;
    char pad[8];
    Res_28ba20* p0;
    char pad2[4];
    void* p1;
    void* p2;
    void Reset() {
        if (!p0)
            Drop_0008d340(p1);
        else {
            _ReadWriteBarrier();
            if (p0) {
                p0->Release();
                p0 = 0;
            }
        }
        p1 = 0;
    }
    void F();
};
extern void* hulk_at_0042c97c[];
extern void* hulk_at_0042c930[];
extern void* g_vC[];
} // namespace fn_f8c9e634
void operator delete(void*);
namespace fn_f8c9e634 {
class Ref_28bb10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Float1Channel_28bb10 {
  public:
    void* vptr;
    char pad[8];
    Ref_28bb10* m0c;
    char pad2[4];
    void* m14;
    void* m18;
    ~Float1Channel_28bb10() throw();
};
namespace pure3d {
typedef void(__fastcall* Callback_28bba0)(void*);
}
namespace pure3d {
extern void __fastcall ElemCtor_000c7920(void*);
}
namespace pure3d {
extern void* Alloc_0008d6d0(unsigned int);
}
namespace pure3d {
extern void __stdcall VecNew_00011520(void*, int, int, Callback_28bba0);
}
namespace pure3d {
class Mem_28bba0 {
  public:
    void* Make_002888c0(unsigned int, int);
};
}
namespace pure3d {
class Base_28bba0 {
  public:
    Base_28bba0(int, int);
    virtual void v0();
    int m4, m8;
    Mem_28bba0* mc;
    int m10, m14;
};
}
namespace pure3d {
class Float2Channel : public Base_28bba0 {
  public:
    hulk_intptr m18;
    Float2Channel(int, hulk_intptr);
    virtual void v1_0028b570();
};
}
extern void* g_c_28bc20[];
class Res_28bc20 {
  public:
    virtual void F0();
    virtual void Release();
};
class Float2Channel_28bc20 {
  public:
    void* vptr;
    char pad[8];
    Res_28bc20* p0;
    char pad2[4];
    void* p1;
    void* p2;
    void Reset() {
        if (!p0)
            Drop_0008d340(p1);
        else {
            _ReadWriteBarrier();
            if (p0) {
                p0->Release();
                p0 = 0;
            }
        }
        p1 = 0;
    }
    void F();
};
void thunk_FUN_00267090(void*) throw();
class Owner_28bcd0 {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
};
namespace pure3d {
class Channel {
public:
    virtual ~Channel() throw() {}
    char pad4[8];
    Owner_28bcd0* owner;
    char pad10[4];
    void* frames;
};
}
namespace pure3d {
class SimpleChannel : public Channel {
public:
    __forceinline virtual ~SimpleChannel() throw() {
        if (owner == 0) {
            thunk_FUN_00267090(frames);
        } else if (owner != 0) {
            owner->vfunc_1();
            owner = 0;
        }
        frames = 0;
    }
};
}
namespace pure3d {
class VectorChannel : public SimpleChannel {
public:
    virtual ~VectorChannel() throw();
};
}
void* Alloc_0008d6d0(int n);
struct Allocator_28bd40 {  };
class VectorChannel_28bd40 {
  public:
    VectorChannel_28bd40(int a, int b);
    virtual void f0();
    int pad[2];
    int m0c;
    int m10;
    int pad2[1];
};
class Vector1DOFChannel : public VectorChannel_28bd40 {
  public:
    Vector1DOFChannel(int a, hulk_intptr b);
    virtual void f0();
    int m18, m1c, m20, m24;
    void* m28;
};
typedef void(__fastcall* Callback_28be20)(void*);
extern void* Alloc(hulk_uintptr);
extern void __stdcall VecNew_00011520(void*, int, int, Callback_28be20);
class Mem_28be20 {
  public:
};
class VectorChannel_28be20 {
  public:
    VectorChannel_28be20(int, int);
    virtual void v0();
    int m4, m8;
    Mem_28be20* mc;
    int m10, m14;
};
struct Z4 {
    int a, b, c, d;
    Z4() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
};
class Vector2DOFChannel_28be20 : public VectorChannel_28be20 {
  public:
    Z4 z;
    hulk_intptr m28;
    Vector2DOFChannel_28be20(int, hulk_intptr);
    virtual void v1_0028b610();
};
class Res_28beb0 {
  public:
    virtual void F0();
    virtual void Release();
};
class VectorChannel_28beb0 {
  public:
    void* vptr;
    char pad[8];
    Res_28beb0* p0;
    void Fin_0028bcd0();
};
class Vector2DOFChannel_28beb0 : public VectorChannel_28beb0 {
  public:
    char pad2[4];
    void* p1;
    char pad3[0x28 - 0x18];
    void* p2;
    void F();
};
extern char DAT_0042c9f0[];
void __stdcall FUN_00011520(void* base, unsigned size, int count, void* ctor);
// the element constructor (thiscall: the element first; returns it), passed to the vector helper as a function
void* __fastcall FUN_00011090(void* element);
struct Pool_28bf20 {
};
class Vector3DOFChannel_28bf20 {
public:
    hulk_intptr vptr;
    int field_04;
    int field_08;
    Pool_28bf20* parent;
    int count;
    int field_14;
    void* data;
    Vector3DOFChannel_28bf20* FUN_0028b420(int a, int b);
    Vector3DOFChannel_28bf20* Construct(int a, hulk_intptr b);
};
extern char DAT_0042ca2c[];
// the element constructor (thiscall: the element first; returns it), passed to the vector helper as a function
void* __fastcall FUN_00011450(void* element);
struct Pool_28c0b0 {
};
class QuaternionChannel {
public:
    hulk_intptr vptr;
    int field_04;
    int field_08;
    Pool_28c0b0* parent;
    int count;
    int field_14;
    void* data;
    QuaternionChannel* FUN_0028b420(int a, int b);
    QuaternionChannel* Construct(int a, hulk_intptr b);
};
class Res_28c130 {
  public:
    virtual void F0();
    virtual void Release();
};
class RotationChannel_28c130 {
  public:
    void* vptr;
    char pad[8];
    Res_28c130* p0;
    void Fin_0028c040();
};
class QuaternionChannel_28c130 : public RotationChannel_28c130 {
  public:
    char pad2[4];
    void* p1;

    void* p2;
    void F();
};
extern void* g_c_28c240[];
class Res_28c240 {
  public:
    virtual void F0();
    virtual void Release();
};
class StringChannel_28c240 {
  public:
    void* vptr;
    char pad[8];
    Res_28c240* p0;
    char pad2[4];
    void* p1;
    void* p2;
    void Reset() {
        if (!p0)
            Drop_0008d340(p1);
        else {
            _ReadWriteBarrier();
            if (p0) {
                p0->Release();
                p0 = 0;
            }
        }
        p1 = 0;
    }
    void Clear_0028b760();
    void F();
};
extern void* g_c_28c310[];
class Res_28c310 {
  public:
    virtual void F0();
    virtual void Release();
};
class EntityChannel_28c310 {
  public:
    void* vptr;
    char pad[8];
    Res_28c310* p0;
    char pad2[4];
    void* p1;
    void* p2;
    void Reset() {
        if (!p0)
            Drop_0008d340(p1);
        else {
            _ReadWriteBarrier();
            if (p0) {
                p0->Release();
                p0 = 0;
            }
        }
        p1 = 0;
    }
    void Clear_0028b7d0();
    void F();
};
extern void* g_c_28c3e0[];
class Res_28c3e0 {
  public:
    virtual void F0();
    virtual void Release();
};
class BoolChannel_28c3e0 {
  public:
    void* vptr;
    char pad[8];
    Res_28c3e0* p0;
    char pad2[4];
    void* p1;
    void* p2;
    void Reset() {
        if (!p0)
            Drop_0008d340(p1);
        else {
            _ReadWriteBarrier();
            if (p0) {
                p0->Release();
                p0 = 0;
            }
        }
        p1 = 0;
    }
    void F();
};
extern char DAT_0042ca7c[];
// the element constructor (thiscall: the element first; returns it), passed to the vector helper as a function
void* __fastcall FUN_000115b0(void* element);
struct Pool_28c470 {
};
class ColourChannel_28c470 {
public:
    hulk_intptr vptr;
    int field_04;
    int field_08;
    Pool_28c470* parent;
    int count;
    int field_14;
    void* data;
    ColourChannel_28c470* FUN_0028b420(int a, int b);
    ColourChannel_28c470* Construct(int a, hulk_intptr b);
};
extern void* g_c_28c4f0[];
class Res_28c4f0 {
  public:
    virtual void F0();
    virtual void Release();
};
class ColourChannel_28c4f0 {
  public:
    void* vptr;
    char pad[8];
    Res_28c4f0* p0;
    char pad2[4];
    void* p1;
    void* p2;
    void Reset() {
        if (!p0)
            Drop_0008d340(p1);
        else {
            _ReadWriteBarrier();
            if (p0) {
                p0->Release();
                p0 = 0;
            }
        }
        p1 = 0;
    }
    void F();
};
struct Stream {
};
struct IntChannel_28c580 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    void *field_18;
    IntChannel_28c580 *FUN_0028b9c0(unsigned x, IntChannel_28c580 *parent);
};
struct Parent_28c580 {
};
struct Reader {
  public:
    char _m_pad_0[0x284];
    Stream *stream;
    char FUN_002669f0();
    hulk_intptr FUN_00266a30();
    void FUN_00266be0();
    int FUN_00266c30();
    void FUN_002647e0(void*, unsigned, unsigned, unsigned);
};
extern "C" void *FUN_0008d690(unsigned size);
struct Float1Channel_28c6b0 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    void *field_18;
    Float1Channel_28c6b0 *FUN_0028bab0(unsigned x, Float1Channel_28c6b0 *parent);
};
struct Parent_28c6b0 {
};
struct Float2Channel_28c7e0 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    void *field_18;
    Float2Channel_28c7e0 *FUN_0028bba0(unsigned x, Float2Channel_28c7e0 *parent);
};
struct Parent_28c7e0 {
};
struct Obj_28c910 {
    int pad0;
    int field4;
    int field8;
    char padc[8];
    short *data14;
};
struct Vector3DOFChannel_28c910 : public Obj_28c910 {
    int *data18;
    Vector3DOFChannel_28c910 *FUN_0028bf20(int id, Obj_28c910 *existing);
};
struct ObjA_28c910 : public Obj_28c910 {
    int field18;
    int field1c, field20, field24;
    int *data28;
    ObjA_28c910 *FUN_0028bd40(int id, Obj_28c910 *existing);
};
struct Vector2DOFChannel_28c910 : public ObjA_28c910 {
    Vector2DOFChannel_28c910 *FUN_0028be20(int id, Obj_28c910 *existing);
};
union Arg1_28c910 { Reader *reader; int id; short count16; };
union Arg3_28c910 { Obj_28c910 *obj; int value; };
struct Context { char pad[0x284]; Reader* reader; };
struct Pool_28cd80 { void* FUN_002888c0(unsigned, unsigned); };
struct Text_28cd80 { char data[8]; void FUN_0027b040(const char*); };
struct Result_28cd80 { char pad[8]; unsigned value; char pad2[8]; void* entries; Text_28cd80* names; Result_28cd80* FUN_0028c1a0(unsigned, Pool_28cd80*); };
struct Owner_28ceb0 { char pad[0x284]; Stream* stream; };
struct Pool_28ceb0 {  };
struct BoolChannel_28ceb0 { char pad0[8]; unsigned value; char pad1[8]; unsigned short* entries; unsigned* bits; BoolChannel_28ceb0* FUN_0028c370(unsigned, Pool_28ceb0*); };
struct ColourChannel_28cfd0 {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    void *field_14;
    void *field_18;
    ColourChannel_28cfd0 *FUN_0028c470(unsigned x, ColourChannel_28cfd0 *parent);
};
struct Parent_28cfd0 {
};


// 0x0028b970 FUN_0028b970 (70 B): equivalent/0x0028b970.cpp
// sym: ?FUN_0028b970@SimpleChannel@fn_f8c9e634@@QAEXXZ @a744b4570613 @wc2f041e4b675
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 3/4, incomplete)
// FUN_0028b970 @ 0x0028b970
void SimpleChannel::FUN_0028b970() {
    vtable = DAT_0042c930;
    if (resource == 0) {
        thunk_FUN_0008d340(data);
    } else {
        resource->FUN_00000001();
        resource = 0;
    }
    data = 0;
    vtable = DAT_0042c920;
}


// 0x0028b9c0 FUN_0028b9c0 (87 B): matches/0x0028b9c0.cpp
// sym: ??0IntChannel@pure3d@fn_f8c9e634@@QAE@HPAX@Z
namespace pure3d {
IntChannel::IntChannel(int first, void* second) : FUN_0028b420(first, second) {
    values = 0;
    if (allocator == 0)
        values = FUN_0008d6d0(count * 4);
    else
        values = allocator->FUN_002888c0(count * 4, 3);
}
}


// 0x0028ba20 FUN_0028ba20 (130 B): matches/0x0028ba20.cpp
// sym: ?F@IntChannel_28ba20@fn_f8c9e634@@QAEXXZ
void IntChannel_28ba20::F() {
    vptr = g_f2;
    if (!p0)
        Drop_0008d340(p2);
    p2 = 0;
    Reset();
    vptr = (void**)DAT_0042c930;
    Reset();
    vptr = hulk_at_0042c920;
}

} // namespace fn_f8c9e634

// 0x0028bab0 FUN_0028bab0 (87 B): matches/0x0028bab0.cpp [wrapped: conflict: FUN_0008d6d0]
// sym: ??0Float1Channel_28bab0@fn_0028bab0@@QAE@HH@Z
namespace fn_0028bab0 {
void* __cdecl FUN_0008d6d0(unsigned int) throw();
class Mem_28bab0 {
  public:
};
struct SimpleChannel_28bab0 {
    virtual void a();
    SimpleChannel_28bab0(int, int) throw();
    int m4, m8;
    Mem_28bab0* mc;
    int m10;
};
struct Float1Channel_28bab0 : SimpleChannel_28bab0 {
    void* m14;
    void* m18;
    Float1Channel_28bab0(int x, hulk_intptr y) throw();
    virtual void a();
};
Float1Channel_28bab0::Float1Channel_28bab0(int x, hulk_intptr y) throw() : SimpleChannel_28bab0(x, y) {
    m18 = 0;
    if (mc == 0)
        m18 = FUN_0008d6d0(m10 * 4);
    else
        m18 = ((void *)((owners::C_2888c0 *)mc)->FUN_002888c0((unsigned)(m10 * 4), 3));
}
} // namespace fn_0028bab0

namespace fn_f8c9e634 {

// 0x0028bb10 FUN_0028bb10 (130 B): matches/0x0028bb10.cpp
// sym: ??1Float1Channel_28bb10@fn_f8c9e634@@QAE@XZ
Float1Channel_28bb10::~Float1Channel_28bb10() throw() {
    vptr = hulk_at_0042c97c;
    if (!m0c)
        operator delete(m18);
    m18 = 0;
    if (!m0c) {
        operator delete(m14);
    } else {
        _ReadWriteBarrier();
        if (m0c) {
            m0c->Release();
            m0c = 0;
        }
    }
    m14 = 0;
    vptr = hulk_at_0042c930;
    if (!m0c) {
        operator delete(m14);
        m14 = 0;
    } else {
        _ReadWriteBarrier();
        if (m0c) {
            m0c->Release();
            m0c = 0;
        }
        m14 = 0;
    }
    vptr = g_vC;
}


// 0x0028bba0 FUN_0028bba0 (128 B): matches/0x0028bba0.cpp
// sym: ??0Float2Channel@pure3d@fn_f8c9e634@@QAE@HH@Z
namespace pure3d {
Float2Channel::Float2Channel(int x, hulk_intptr y) : Base_28bba0(x, y) {
    m18 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc_0008d6d0(n * 8);
        m18 = (hulk_intptr)(p ? (VecNew_00011520(p, 8, n, ElemCtor_000c7920), p) : 0);
        return;
    }
    m18 = (hulk_intptr)mc->Make_002888c0(m10 << 3, 3);
}
}


// 0x0028bc20 FUN_0028bc20 (130 B): matches/0x0028bc20.cpp
// sym: ?F@Float2Channel_28bc20@fn_f8c9e634@@QAEXXZ
void Float2Channel_28bc20::F() {
    vptr = g_f2;
    if (!p0)
        Drop_0008d340(p2);
    p2 = 0;
    Reset();
    vptr = (void**)DAT_0042c930;
    Reset();
    vptr = g_c_28bc20;
}


// 0x0028bcd0 FUN_0028bcd0 (110 B): equivalent/0x0028bcd0.cpp
// sym: ??1VectorChannel@pure3d@fn_f8c9e634@@UAE@XZ @7cd129283b1a @w7f462c1e9446
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 6/8, incomplete)
// FUN_0028bcd0 @ 0x0028bcd0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
namespace pure3d {
VectorChannel::~VectorChannel() throw() {
    if (owner == 0) {
        thunk_FUN_00267090(frames);
    } else if (owner != 0) {
        owner->vfunc_1();
        owner = 0;
    }
    frames = 0;
}
}


// 0x0028bd40 FUN_0028bd40 (97 B): matches/0x0028bd40.cpp
// sym: ??0Vector1DOFChannel@fn_f8c9e634@@QAE@HH@Z
Vector1DOFChannel::Vector1DOFChannel(int a, hulk_intptr b) : VectorChannel_28bd40(a, b) {
    int* p = &m18;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    hulk_intptr c = m0c;
    p[4] = 0;
    if (c == 0)
        m28 = Alloc_0008d6d0(m10 << 2);
    else
        m28 = ((void *)((owners::C_2888c0 *)(((Allocator_28bd40*)c)))->FUN_002888c0((unsigned)(m10 << 2), 3));
}

} // namespace fn_f8c9e634

// 0x0028bdb0 FUN_0028bdb0 (103 B): equivalent/0x0028bdb0.cpp [wrapped: conflict: pure3d::Channel]
// sym: ??1Vector1DOFChannel@pure3d@fn_0028bdb0@@UAE@XZ @725c91af60f2 @w26cb4bdfe256
namespace fn_0028bdb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_0028bdb0 @ 0x0028bdb0
// equiv-map: ??1Channel@pure3d@@UAE@XZ = 0x0028bcd0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void thunk_FUN_00267090(void*) throw();
class Owner_28bdb0 {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
};
namespace pure3d {
class Channel {
public:
    virtual ~Channel() throw();
    char pad4[8];
    Owner_28bdb0* owner;
    char pad10[4];
    void* frames;
};
class Vector1DOFChannel : public Channel {
public:
    virtual ~Vector1DOFChannel() throw();
    char pad18[16];
    void* values;
};
pure3d::Vector1DOFChannel::~Vector1DOFChannel() throw() {
    if (owner == 0)
        thunk_FUN_00267090(values);
    values = 0;
    if (owner == 0) {
        thunk_FUN_00267090(frames);
        frames = 0;
    } else {
        if (owner != 0) {
            owner->vfunc_1();
            owner = 0;
        }
        frames = 0;
    }
}
}
} // namespace fn_0028bdb0

namespace fn_f8c9e634 {

// 0x0028be20 FUN_0028be20 (142 B): matches/0x0028be20.cpp
// sym: ??0Vector2DOFChannel_28be20@fn_f8c9e634@@QAE@HH@Z
Vector2DOFChannel_28be20::Vector2DOFChannel_28be20(int x, hulk_intptr y) : VectorChannel_28be20(x, y) {

    m28 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc_0008d6d0(n * 8);
        m28 = (hulk_intptr)(p ? (VecNew_00011520(p, 8, n, ElemCtor), p) : 0);
        return;
    }
    m28 = (hulk_intptr)((void *)((owners::C_2888c0 *)mc)->FUN_002888c0((unsigned)(m10 << 3), 3));
}


// 0x0028beb0 FUN_0028beb0 (103 B): matches/0x0028beb0.cpp
// sym: ?F@Vector2DOFChannel_28beb0@fn_f8c9e634@@QAEXXZ
void Vector2DOFChannel_28beb0::F() {
    if (!p0) {
        vptr = g_f2;
        Drop_0008d340(p2);
    } else
        vptr = g_f2;
    p2 = 0;
    if (!p0) {
        Drop_0008d340(p1);
    } else {
        _ReadWriteBarrier();
        if (p0) {
            p0->Release();
            p0 = 0;
        }
    }
    p1 = 0;
    Fin_0028bcd0();
}


// 0x0028bf20 FUN_0028bf20 (130 B): equivalent/0x0028bf20.cpp
// sym: ?Construct@Vector3DOFChannel_28bf20@fn_f8c9e634@@QAEPAV12@HH@Z @6e464a0bbc85 @wab18543f1773
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0028bf20 @ 0x0028bf20
// 0x0028bf20: channel constructor holding 12-byte elements, allocated from the parent pool or the heap
Vector3DOFChannel_28bf20* Vector3DOFChannel_28bf20::Construct(int a, hulk_intptr b)
{
    FUN_0028b420(a, b);
    vptr = (hulk_intptr)DAT_0042c9f0;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 12);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 12, n, (void*)&FUN_00011090);
        data = mem;
        return this;
    }
    data = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((unsigned)(count * 12), 3));
    return this;
}

} // namespace fn_f8c9e634

// 0x0028bfb0 FUN_0028bfb0 (103 B): equivalent/0x0028bfb0.cpp [wrapped: conflict: pure3d::Channel]
// sym: ??1Vector3DOFChannel@pure3d@fn_0028bfb0@@UAE@XZ @ca4634c1bc08 @w5069b4fdf171
namespace fn_0028bfb0 {
// STATUS: equivalent (tools/equiv.py level 3: 3018 inputs, branch coverage 5/6, incomplete)
// FUN_0028bfb0 @ 0x0028bfb0
// equiv-map: ??1Channel@pure3d@@UAE@XZ = 0x0028bcd0
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void thunk_FUN_00267090(void*) throw();
class Owner_28bfb0 {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
};
namespace pure3d {
class Channel {
public:
    virtual ~Channel() throw();
    char pad4[8];
    Owner_28bfb0* owner;
    char pad10[4];
    void* frames;
};
class Vector3DOFChannel : public Channel {
public:
    virtual ~Vector3DOFChannel() throw();
    void* values;
};
pure3d::Vector3DOFChannel::~Vector3DOFChannel() throw() {
    if (owner == 0)
        thunk_FUN_00267090(values);
    values = 0;
    if (owner == 0) {
        thunk_FUN_00267090(frames);
        frames = 0;
    } else {
        if (owner != 0) {
            owner->vfunc_1();
            owner = 0;
        }
        frames = 0;
    }
}
}
} // namespace fn_0028bfb0


// 0x0028c040 FUN_0028c040 (110 B): equivalent/0x0028c040.cpp [wrapped: conflict: pure3d::Channel; pure3d::SimpleChannel]
// sym: ??1RotationChannel@pure3d@fn_0028c040@@UAE@XZ @69dc5d1951a0 @w57f312baaa6f
namespace fn_0028c040 {
// STATUS: equivalent (tools/equiv.py level 3: 3036 inputs, branch coverage 6/8, incomplete)
// FUN_0028c040 @ 0x0028c040
// equiv-map: ?thunk_FUN_00267090@@YAXPAX@Z = 0x0008d340
void thunk_FUN_00267090(void*) throw();
class Owner_28c040 {
public:
    virtual void vfunc_0() throw();
    virtual void vfunc_1() throw();
};
namespace pure3d {
class Channel {
public:
    virtual ~Channel() throw() {}
    char pad4[8];
    Owner_28c040* owner;
    char pad10[4];
    void* frames;
};
class SimpleChannel : public Channel {
public:
    virtual ~SimpleChannel() throw() {
        if (owner != 0) {
            owner->vfunc_1();
            owner = 0;
        } else {
            thunk_FUN_00267090(frames);
        }
        frames = 0;
    }
};
class RotationChannel : public SimpleChannel {
public:
    virtual ~RotationChannel() throw();
};
RotationChannel::~RotationChannel() throw() {
    if (owner == 0) {
        thunk_FUN_00267090(frames);
    } else if (owner != 0) {
        owner->vfunc_1();
        owner = 0;
    }
    frames = 0;
}
}
} // namespace fn_0028c040

namespace fn_f8c9e634 {

// 0x0028c0b0 FUN_0028c0b0 (126 B): equivalent/0x0028c0b0.cpp
// sym: ?Construct@QuaternionChannel@fn_f8c9e634@@QAEPAV12@HH@Z @9b97d2549955 @w56dff3c77ee2
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_0028c0b0 @ 0x0028c0b0
// 0x0028c0b0: quaternion channel constructor holding 16-byte elements, allocated from the parent pool or the heap
QuaternionChannel* QuaternionChannel::Construct(int a, hulk_intptr b)
{
    FUN_0028b420(a, b);
    vptr = (hulk_intptr)DAT_0042ca2c;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 16);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 16, n, (void*)&FUN_00011450);
        data = mem;
        return this;
    }
    data = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((unsigned)(count * 16), 3));
    return this;
}


// 0x0028c130 FUN_0028c130 (103 B): matches/0x0028c130.cpp
// sym: ?F@QuaternionChannel_28c130@fn_f8c9e634@@QAEXXZ
void QuaternionChannel_28c130::F() {
    if (!p0) {
        vptr = g_f2;
        Drop_0008d340(p2);
    } else
        vptr = g_f2;
    p2 = 0;
    if (!p0) {
        Drop_0008d340(p1);
    } else {
        _ReadWriteBarrier();
        if (p0) {
            p0->Release();
            p0 = 0;
        }
    }
    p1 = 0;
    Fin_0028c040();
}

} // namespace fn_f8c9e634

// 0x0028c1a0 FUN_0028c1a0 (150 B): matches/0x0028c1a0.cpp [wrapped: conflict: Allocator; pure3d::Channel]
// sym: ??0StringChannel@pure3d@fn_0028c1a0@@QAE@II@Z
namespace fn_0028c1a0 {
// FUN_0028c1a0 @ 0x0028c1a0
// equiv-map: ??0Channel@pure3d@@QAE@II@Z = 0x0028b420

struct Name_28c1a0 {
    int lo, hi;
    void FUN_0027af00();
};

struct Allocator {
    Name_28c1a0 *FUN_002888c0(unsigned int bytes, int flags);
};

void *__cdecl FUN_0008d6d0(unsigned int size);
void __stdcall FUN_00011520(void *p, unsigned int size, unsigned int count, void (Name_28c1a0::*ctor)());

namespace pure3d {

class Channel {
public:
    Channel(unsigned int a, unsigned int b);
    virtual void v0();
    char pad04[8];
    Allocator *alloc;       // 0xc
    unsigned int count;     // 0x10
    char pad14[4];
};

class StringChannel : public Channel {
public:
    Name_28c1a0 *names;            // 0x18
    StringChannel(unsigned int a, hulk_uintptr b);
    virtual void v0();
};

StringChannel::StringChannel(unsigned int a, hulk_uintptr b) : Channel(a, b)
{
    names = 0;
    if (alloc == 0) {
        unsigned int n = count;
        unsigned int *raw = (unsigned int *)FUN_0008d6d0(n * sizeof(Name_28c1a0) + 4);
        Name_28c1a0 *arr = 0;
        if (raw != 0) {
            arr = (Name_28c1a0 *)(raw + 1);
            raw[0] = n;
            FUN_00011520(arr, sizeof(Name_28c1a0), n, &Name_28c1a0::FUN_0027af00);
        }
        names = arr;
    } else {
        names = alloc->FUN_002888c0(count * sizeof(Name_28c1a0), 3);
        for (unsigned int i = 0; i < count; i++) {
            Name_28c1a0 *p = &names[i];
            if (p != 0)
                p->FUN_0027af00();
        }
    }
}

}
} // namespace fn_0028c1a0

namespace fn_f8c9e634 {

// 0x0028c240 FUN_0028c240 (81 B): matches/0x0028c240.cpp
// sym: ?F@StringChannel_28c240@fn_f8c9e634@@QAEXXZ
void StringChannel_28c240::F() {
    vptr = g_f2;
    Clear_0028b760();
    vptr = (void**)DAT_0042c930;
    Reset();
    vptr = g_c_28c240;
}

} // namespace fn_f8c9e634

// 0x0028c2a0 FUN_0028c2a0 (107 B): matches/0x0028c2a0.cpp [wrapped: conflict: FUN_0008d6d0; pure3d::Channel]
// sym: ??0EntityChannel@pure3d@fn_0028c2a0@@QAE@HPAVOwner@2@@Z
namespace fn_0028c2a0 {
// FUN_0028c2a0 @ 0x0028c2a0
// equiv-map: ??0Channel@pure3d@@QAE@HPAVOwner@@@Z = 0x0028b420
extern void* __cdecl FUN_0008d6d0(unsigned int size) throw();

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memset(void*, int, unsigned int) throw();
#endif


class Owner {
public:
    virtual void v0();
    void* FUN_002888c0(unsigned int size, int tag) throw();
};

namespace pure3d {

class Channel {
public:
    Channel(int count, Owner* owner) throw();
    virtual ~Channel() throw();
    char pad04[8];
    Owner* owner;          // 0x0c
    int count;             // 0x10
    char pad14[4];
};

class EntityChannel : public Channel {
public:
    EntityChannel(int count, Owner* owner) throw();
    virtual ~EntityChannel() throw();
    void* values;          // 0x18
};

EntityChannel::EntityChannel(int count_, Owner* owner_) throw() : Channel(count_, owner_)
{
    values = 0;
    if (owner == 0)
        values = FUN_0008d6d0(count << 2);
    else
        values = owner->FUN_002888c0(count << 2, 3);
    memset(values, 0, count << 2);
}

}
} // namespace fn_0028c2a0

namespace fn_f8c9e634 {

// 0x0028c310 FUN_0028c310 (81 B): matches/0x0028c310.cpp
// sym: ?F@EntityChannel_28c310@fn_f8c9e634@@QAEXXZ
void EntityChannel_28c310::F() {
    vptr = g_f2;
    Clear_0028b7d0();
    vptr = (void**)DAT_0042c930;
    Reset();
    vptr = g_c_28c310;
}

} // namespace fn_f8c9e634

// 0x0028c370 FUN_0028c370 (106 B): matches/0x0028c370.cpp [wrapped: conflict: memset]
// sym: ??0BoolChannel@fn_0028c370@@QAE@HH@Z
namespace fn_0028c370 {

#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* memset(void*, int, unsigned);
#endif

void* FUN_0008d6d0(unsigned int n);
struct Allocator_28c370 { void* Alloc2_002888c0(unsigned n, int f); };
class SimpleChannel_28c370 {
  public:
    SimpleChannel_28c370(int a, int b);
    virtual void f0();
    int pad[2];
    hulk_intptr m0;
    unsigned cnt;
};
class BoolChannel : public SimpleChannel_28c370 {
  public:
    BoolChannel(int a, int b);
    virtual void f0();
    int pad2;
    unsigned* bits;
};
BoolChannel::BoolChannel(int a, int b) : SimpleChannel_28c370(a, b) {
    int n = ((cnt - 1) >> 5) + 1;
    bits = 0;
    if (m0 == 0)
        bits = (unsigned*)FUN_0008d6d0(n * 4);
    else
        bits = (unsigned*)((Allocator_28c370*)m0)->Alloc2_002888c0(n * 4, 3);
    memset(bits, 0, n * 4);
}
} // namespace fn_0028c370

namespace fn_f8c9e634 {

// 0x0028c3e0 FUN_0028c3e0 (130 B): matches/0x0028c3e0.cpp
// sym: ?F@BoolChannel_28c3e0@fn_f8c9e634@@QAEXXZ
void BoolChannel_28c3e0::F() {
    vptr = g_f2;
    if (!p0)
        Drop_0008d340(p2);
    p2 = 0;
    Reset();
    vptr = (void**)DAT_0042c930;
    Reset();
    vptr = g_c_28c3e0;
}


// 0x0028c470 FUN_0028c470 (128 B): equivalent/0x0028c470.cpp
// sym: ?Construct@ColourChannel_28c470@fn_f8c9e634@@QAEPAV12@HH@Z @61f9315b2fde @w87134c3f6ce3
// STATUS: equivalent (tools/equiv.py level 3: 20000 inputs, branch coverage 4/4)
// FUN_0028c470 @ 0x0028c470
// 0x0028c470: channel constructor holding 4-byte elements, allocated from the parent pool or the heap
ColourChannel_28c470* ColourChannel_28c470::Construct(int a, hulk_intptr b)
{
    FUN_0028b420(a, b);
    vptr = (hulk_intptr)DAT_0042ca7c;
    data = 0;
    if (parent == 0) {
        int n = count;
        void* mem = FUN_0008d6d0(n * 4);
        if (mem == 0) {
            data = 0;
            return this;
        }
        FUN_00011520(mem, 4, n, (void*)&FUN_000115b0);
        data = mem;
        return this;
    }
    data = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((unsigned)(count * 4), 3));
    return this;
}


// 0x0028c4f0 FUN_0028c4f0 (130 B): matches/0x0028c4f0.cpp
// sym: ?F@ColourChannel_28c4f0@fn_f8c9e634@@QAEXXZ
void ColourChannel_28c4f0::F() {
    vptr = g_f2;
    if (!p0)
        Drop_0008d340(p2);
    p2 = 0;
    Reset();
    vptr = (void**)DAT_0042c930;
    Reset();
    vptr = g_c_28c4f0;
}


// 0x0028c580 FUN_0028c580 (300 B): equivalent/0x0028c580.cpp
// sym: ?FUN_0028c580@fn_f8c9e634@@YGPAUIntChannel_28c580@1@PAUReader@1@IPAUParent_28c580@1@@Z @1e751bb5778e @wb8398d7821b2
// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/12)
// FUN_0028c580 @ 0x0028c580
IntChannel_28c580 * __stdcall FUN_0028c580(Reader *r, unsigned unused, Parent_28c580 *parent)
{
    unsigned x;
    unsigned a;
    IntChannel_28c580 *node;

    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);

    if (parent == 0) {
        void *mem = FUN_0008d690((int)sizeof(IntChannel_28c580));
        node = 0;
        if (mem)
            node = ((IntChannel_28c580 *)mem)->FUN_0028b9c0(x, 0);
    } else {
        void *mem = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((int)sizeof(IntChannel_28c580), 7));
        node = 0;
        if (mem)
            node = ((IntChannel_28c580 *)mem)->FUN_0028b9c0(x, (IntChannel_28c580 *)parent);
    }

    node->field_08 = a;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_14), (hulk_intptr)x, 2, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_18), (hulk_intptr)x, 4, (hulk_intptr)1);

    while (r->FUN_002669f0()) {
        if ((char *)r->FUN_00266a30() == ((char*)0x00121110)) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&parent), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
            node->field_04 = x;
        }
        r->FUN_00266be0();
    }
    return node;
}


// 0x0028c6b0 FUN_0028c6b0 (300 B): equivalent/0x0028c6b0.cpp
// sym: ?FUN_0028c6b0@fn_f8c9e634@@YGPAUFloat1Channel_28c6b0@1@PAUReader@1@IPAUParent_28c6b0@1@@Z @97413ebf2aef @w9b93d9d6949e
// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/12)
// FUN_0028c6b0 @ 0x0028c6b0
Float1Channel_28c6b0 * __stdcall FUN_0028c6b0(Reader *r, unsigned unused, Parent_28c6b0 *parent)
{
    unsigned x;
    unsigned a;
    Float1Channel_28c6b0 *node;

    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);

    if (parent == 0) {
        void *mem = FUN_0008d690((int)sizeof(Float1Channel_28c6b0));
        node = 0;
        if (mem)
            node = ((Float1Channel_28c6b0 *)mem)->FUN_0028bab0(x, 0);
    } else {
        void *mem = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((int)sizeof(Float1Channel_28c6b0), 7));
        node = 0;
        if (mem)
            node = ((Float1Channel_28c6b0 *)mem)->FUN_0028bab0(x, (Float1Channel_28c6b0 *)parent);
    }

    node->field_08 = a;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_14), (hulk_intptr)x, 2, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_18), (hulk_intptr)x, 4, (hulk_intptr)1);

    while (r->FUN_002669f0()) {
        if ((char *)r->FUN_00266a30() == ((char*)0x00121110)) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&parent), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
            node->field_04 = x;
        }
        r->FUN_00266be0();
    }
    return node;
}


// 0x0028c7e0 FUN_0028c7e0 (300 B): equivalent/0x0028c7e0.cpp
// sym: ?FUN_0028c7e0@fn_f8c9e634@@YGPAUFloat2Channel_28c7e0@1@PAUReader@1@IPAUParent_28c7e0@1@@Z @70ee799d65e0 @wb07886d18268
// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/12)
// FUN_0028c7e0 @ 0x0028c7e0
Float2Channel_28c7e0 * __stdcall FUN_0028c7e0(Reader *r, unsigned unused, Parent_28c7e0 *parent)
{
    unsigned x;
    unsigned a;
    Float2Channel_28c7e0 *node;

    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);

    if (parent == 0) {
        void *mem = FUN_0008d690((int)sizeof(Float2Channel_28c7e0));
        node = 0;
        if (mem)
            node = ((Float2Channel_28c7e0 *)mem)->FUN_0028bba0(x, 0);
    } else {
        void *mem = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((int)sizeof(Float2Channel_28c7e0), 7));
        node = 0;
        if (mem)
            node = ((Float2Channel_28c7e0 *)mem)->FUN_0028bba0(x, (Float2Channel_28c7e0 *)parent);
    }

    node->field_08 = a;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_14), (hulk_intptr)x, 2, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_18), (hulk_intptr)(x * 2), 4, (hulk_intptr)1);

    while (r->FUN_002669f0()) {
        if ((char *)r->FUN_00266a30() == ((char*)0x00121110)) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&parent), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
            node->field_04 = x;
        }
        r->FUN_00266be0();
    }
    return node;
}


// 0x0028c910 FUN_0028c910 (1135 B): equivalent/0x0028c910.cpp
// sym: ?FUN_0028c910@fn_f8c9e634@@YGPAUObj_28c910@1@TArg1_28c910@1@HTArg3_28c910@1@@Z @9faf4dd57fac @wdfd6ee311c5e
// STATUS: equivalent (tools/equiv.py level 3: 3054 inputs, branch coverage 42/42)
// FUN_0028c910 @ 0x0028c910
Obj_28c910 *__stdcall FUN_0028c910(Arg1_28c910 a1, int a2, Arg3_28c910 a3) {
    Reader *r = a1.reader;
    struct { int l10, l14, l18, l1c, l20, l24, l28; } f;
    Obj_28c910 *obj;
    int id;
    switch (r->FUN_00266c30()) {
    case 0x121102:
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l1c), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.count16), (hulk_intptr)1, 2, (hulk_intptr)1);
        {
            int s = a1.count16;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l20), (hulk_intptr)3, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
            id = a1.id;
            ObjA_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690((int)sizeof(ObjA_28c910));
                o = 0;
                if (mem)
                    o = ((ObjA_28c910 *)mem)->FUN_0028bd40(id, 0);
            } else {
                o = (ObjA_28c910 *)((void *)((owners::C_2888c0 *)(Obj_28c910 *)(a3.obj))->FUN_002888c0((int)sizeof(ObjA_28c910), 7));
                if (o)
                    o = o->FUN_0028bd40(id, a3.obj);
            }
            o->field8 = f.l1c;
            o->field18 = s;
            o->field1c = f.l20;
            o->field20 = f.l24;
            o->field24 = f.l28;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data14), (hulk_intptr)id, 2, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data28), (hulk_intptr)id, 4, (hulk_intptr)1);
            obj = o;
        }
        break;
    case 0x121103:
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l10), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.count16), (hulk_intptr)1, 2, (hulk_intptr)1);
        {
            int s = a1.count16;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l14), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l18), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l1c), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
            id = a1.id;
            Vector2DOFChannel_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690((int)sizeof(Vector2DOFChannel_28c910));
                o = 0;
                if (mem)
                    o = ((Vector2DOFChannel_28c910 *)mem)->FUN_0028be20(id, 0);
            } else {
                o = (Vector2DOFChannel_28c910 *)((void *)((owners::C_2888c0 *)(Obj_28c910 *)(a3.obj))->FUN_002888c0((int)sizeof(Vector2DOFChannel_28c910), 7));
                if (o)
                    o = o->FUN_0028be20(id, a3.obj);
            }
            o->field8 = f.l10;
            o->field18 = s;
            o->field1c = f.l14;
            o->field20 = f.l18;
            o->field24 = f.l1c;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data14), (hulk_intptr)id, 2, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data28), (hulk_intptr)(id * 2), 4, (hulk_intptr)1);
            obj = o;
        }
        break;
    case 0x121104:
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&f.l10), (hulk_intptr)1, 4, (hulk_intptr)1);
        ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
        {
            id = a1.id;
            Vector3DOFChannel_28c910 *o;
            if (a3.obj == 0) {
                void *mem = FUN_0008d690((int)sizeof(Vector3DOFChannel_28c910));
                o = 0;
                if (mem)
                    o = ((Vector3DOFChannel_28c910 *)mem)->FUN_0028bf20(id, 0);
            } else {
                o = (Vector3DOFChannel_28c910 *)((void *)((owners::C_2888c0 *)(Obj_28c910 *)(a3.obj))->FUN_002888c0((int)sizeof(Vector3DOFChannel_28c910), 7));
                if (o)
                    o = o->FUN_0028bf20(id, a3.obj);
            }
            o->field8 = f.l10;
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data14), (hulk_intptr)id, 2, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(o->data18), (hulk_intptr)(id * 3), 4, (hulk_intptr)1);
            obj = o;
        }
        break;
    default:
        return 0;
    }
    while (r->FUN_002669f0()) {
        if (r->FUN_00266a30() == 0x121110) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a1.id), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a3.value), (hulk_intptr)1, 4, (hulk_intptr)1);
            obj->field4 = a3.value;
        }
        r->FUN_00266be0();
    }
    return obj;
}


// 0x0028cd80 FUN_0028cd80 (289 B): equivalent/0x0028cd80.cpp
// sym: ?FUN_0028cd80@fn_f8c9e634@@YGPAUResult_28cd80@1@PAUContext@1@IPAUPool_28cd80@1@@Z @0d8f303f2aba @wd8dbf2972f3a
// STATUS: equivalent (tools/equiv.py level 3: 78 inputs, branch coverage 10/10)
// FUN_0028cd80 @ 0x0028cd80
Result_28cd80* __stdcall FUN_0028cd80(Context* context, unsigned unused, Pool_28cd80* pool) {
 unsigned value, count;
 context->reader->FUN_002647e0(&value,1,4,1);
 context->reader->FUN_002647e0(&value,1,4,1);
 context->reader->FUN_002647e0(&count,1,4,1);
 void* memory = pool ? pool->FUN_002888c0(0x1c,7) : FUN_0008d690(0x1c);
 Result_28cd80* result = memory ? ((Result_28cd80*)memory)->FUN_0028c1a0(count,pool) : 0;
 result->value = value;
 context->reader->FUN_002647e0(result->entries,count,2,1);
 for(unsigned i=0;i<count;++i) {
 unsigned char length;
 char buffer[256];
 context->reader->FUN_002647e0(&length,1,1,1);
 context->reader->FUN_002647e0(buffer,length,1,1);
 buffer[length]=0;
 result->names[i].FUN_0027b040(buffer);
 }
 return result;
}


// 0x0028ceb0 FUN_0028ceb0 (288 B): equivalent/0x0028ceb0.cpp
// sym: ?FUN_0028ceb0@fn_f8c9e634@@YGPAUBoolChannel_28ceb0@1@PAUOwner_28ceb0@1@IPAUPool_28ceb0@1@@Z @2763adcc6244 @w5e4f629e961e
// STATUS: equivalent (tools/equiv.py level 3: 95 inputs, branch coverage 18/18)
// FUN_0028ceb0 @ 0x0028ceb0
BoolChannel_28ceb0* __stdcall FUN_0028ceb0(Owner_28ceb0* owner, unsigned unused, Pool_28ceb0* pool) {
 unsigned count; unsigned value;
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 4, (hulk_intptr)1);
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&value), (hulk_intptr)1, 4, (hulk_intptr)1);
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 2, (hulk_intptr)1);
 bool active = (unsigned short)count == 1;
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)(&count), (hulk_intptr)1, 4, (hulk_intptr)1);
 BoolChannel_28ceb0* storage = (BoolChannel_28ceb0*)(pool ? ((void *)((owners::C_2888c0 *)pool)->FUN_002888c0((int)sizeof(BoolChannel_28ceb0), 7)) : FUN_0008d690((int)sizeof(BoolChannel_28ceb0)));
 BoolChannel_28ceb0* result = storage ? storage->FUN_0028c370(count+1,pool) : 0;
 unsigned short* destination = result->entries + 1;
 result->value = value;
 ((owners::X_2647e0 *)(owner->stream))->FUN_002647e0((hulk_intptr)destination, (hulk_intptr)count, 2, (hulk_intptr)1);
 result->entries[0] = 0xffff;
 unsigned total = count+1;
 for(unsigned i=0;i<total;++i) {
 if(active) result->bits[i/32] |= 1u << (i%32);
 active = !active;
 }
 return result;
}


// 0x0028cfd0 FUN_0028cfd0 (300 B): equivalent/0x0028cfd0.cpp
// sym: ?FUN_0028cfd0@fn_f8c9e634@@YGPAUColourChannel_28cfd0@1@PAUReader@1@IPAUParent_28cfd0@1@@Z @1b3f51412d7f @w1d1d4fa5533c
// STATUS: equivalent (tools/equiv.py level 3: 142 inputs, branch coverage 12/12)
// FUN_0028cfd0 @ 0x0028cfd0
ColourChannel_28cfd0 * __stdcall FUN_0028cfd0(Reader *r, unsigned unused, Parent_28cfd0 *parent)
{
    unsigned x;
    unsigned a;
    ColourChannel_28cfd0 *node;

    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&a), (hulk_intptr)1, 4, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);

    if (parent == 0) {
        void *mem = FUN_0008d690((int)sizeof(ColourChannel_28cfd0));
        node = 0;
        if (mem)
            node = ((ColourChannel_28cfd0 *)mem)->FUN_0028c470(x, 0);
    } else {
        void *mem = ((void *)((owners::C_2888c0 *)parent)->FUN_002888c0((int)sizeof(ColourChannel_28cfd0), 7));
        node = 0;
        if (mem)
            node = ((ColourChannel_28cfd0 *)mem)->FUN_0028c470(x, (ColourChannel_28cfd0 *)parent);
    }

    node->field_08 = a;
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_14), (hulk_intptr)x, 2, (hulk_intptr)1);
    ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(node->field_18), (hulk_intptr)x, 4, (hulk_intptr)1);

    while (r->FUN_002669f0()) {
        if ((char *)r->FUN_00266a30() == ((char*)0x00121110)) {
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&parent), (hulk_intptr)1, 4, (hulk_intptr)1);
            ((owners::X_2647e0 *)(r->stream))->FUN_002647e0((hulk_intptr)(&x), (hulk_intptr)1, 4, (hulk_intptr)1);
            node->field_04 = x;
        }
        r->FUN_00266be0();
    }
    return node;
}

} // namespace fn_f8c9e634
