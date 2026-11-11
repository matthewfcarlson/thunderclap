// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0028edb0..0x0028f240 (kind game, layer engine, confidence high), dominant class pure3d::ShaderVectorBroadcast
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#define TREE_TU_BEGIN namespace fn_f4b93973 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f4b93973 {} using namespace fn_f4b93973;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f4b93973 {
extern "C" char DAT_0042cb44[];
typedef unsigned int u32_28edb0;
struct Service_28edb0 {
    virtual void f0();
};
struct Manager_28edb0 {
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
    virtual Service_28edb0* Get(const char*, int);
};
extern Manager_28edb0* gManager_28edb0;
struct Entity_28edb0 {
    Entity_28edb0();
};
struct Shader : Entity_28edb0 {
    void* vtable;
    char pad4[0xc];
    Service_28edb0* mService;
    unsigned char flag;
    char pad15[3];
    u32_28edb0 value;
    Shader();
};
typedef unsigned int u32_28ee30;
struct Receiver_28ee30 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6(u32_28ee30, u32_28ee30);
};
struct ShaderIntBroadcast {
    char pad[8];
    u32_28ee30 mA;
    u32_28ee30 mB;
    hulk_intptr vfunc_3(void* param);
};
extern "C" char DAT_0042cb5c[];
class ShaderFloatBroadcast {
  public:
    hulk_intptr mVft;
    int mZero;
    int mA;
    int mB;
    ShaderFloatBroadcast(int a, int b);
};
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
namespace pure3d {
struct Texture { char pad[16]; void* data; };
}
namespace pure3d {
struct Shader {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual void vfunc_3();
 virtual void vfunc_4();
 virtual void vfunc_5(int, void*);
};
}
namespace pure3d {
struct Context { char pad[16]; Shader* shader; };
}
namespace pure3d {
struct ShaderTextureBroadcast {
 virtual void vfunc_0();
 virtual void vfunc_1();
 virtual void vfunc_2();
 virtual Context* vfunc_3(Context*);
 virtual void vfunc_4();
 virtual void vfunc_5();
 char pad[4];
 int id;
 Texture* texture;
};
}
class Data_28f020 {
  public:
    char pad[0x10];
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j(int, int*);
};
class ShaderVectorBroadcast_28f020 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int vfunc_3(int);
    virtual void d();
    virtual void e();
    int pad;
    int source;
    struct V {
        int a, b, c;
    } vec;
};
class ShaderCallback {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual int vfunc_3(int);
    virtual void f4();
    virtual void f5();
};
struct Matrix {
    unsigned long x[16];
};
class ShaderMatrixBroadcast : public ShaderCallback {
  public:
    int pad;
    int value;
    Matrix matrix;
    int vfunc_3(int param);
};
class Receiver_28f0c0 {
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
    virtual void send(int value, Matrix* matrix);
};
extern void* g_vftable_0042cb44[];
class Ref_28f100 {
  public:
    virtual void F0();
    virtual void Release();
};
class Entity_28f100 {
  public:
    void* vptr;
    void Fin();
};
class Shader_28f100 : public Entity_28f100 {
  public:
    char pad[12];
    Ref_28f100* m;
    ~Shader_28f100();
};
class ShaderCallback_28f170 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
namespace pure3d {
class NonCopyable : public ShaderCallback_28f170 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable*);


// 0x0028edb0 FUN_0028edb0 (52 B): matches/0x0028edb0.cpp
// sym: ??0Shader@fn_f4b93973@@QAE@XZ
Shader::Shader() {
    vtable = (void*)((hulk_intptr)DAT_0042cb44);
    flag = 0;
    value = 0;
    mService = gManager_28edb0->Get("simple", 0);
    mService->f0();
}

} // namespace fn_f4b93973

// 0x0028edf0 FUN_0028edf0 (58 B): matches/0x0028edf0.cpp [wrapped: on include/gen/, and its TU merges more functions without the headers]
// sym: ?Ctor@Shader@fn_0028edf0@@QAEPAV12@HH@Z
namespace fn_0028edf0 {
// data: gFactory_28edf0 = DAT_0052c2a0

extern "C" char DAT_0042cb44[];
class Obj_28edf0 {
  public:
    virtual void f0();
};
class Shader {
  public:
    hulk_intptr vft;
    char pad4[12];
    Obj_28edf0* field10;
    char flag;
    char pad15[3];
    int field18;
    Shader* Ctor(hulk_intptr a, int b);
};
class Factory_28edf0 {
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
    virtual Obj_28edf0* Get(int a, int b);
};
struct ThisCall_0027b070 {
    void BaseInit();
};
Shader* Shader::Ctor(hulk_intptr a, int b) {
    ((ThisCall_0027b070*)(this))->BaseInit();
    vft = ((hulk_intptr)DAT_0042cb44);
    flag = 0;
    field18 = 0;
    Obj_28edf0* p = (*(Factory_28edf0**)&DAT_0052c2a0)->Get(a, b);
    field10 = p;
    p->f0();
    return this;
}
} // namespace fn_0028edf0

namespace fn_f4b93973 {

// 0x0028ee30 pure3d::ShaderIntBroadcast::vfunc_3 (35 B): matches/0x0028ee30.cpp
// sym: ?vfunc_3@ShaderIntBroadcast@fn_f4b93973@@QAEHPAX@Z
hulk_intptr ShaderIntBroadcast::vfunc_3(void* param) {
    if (param) {
        Receiver_28ee30* r = *(Receiver_28ee30**)((char*)param + 0x10);
        r->f6(mA, mB);
    }
    return (hulk_intptr)param;
}


// 0x0028ee60 FUN_0028ee60 (32 B): matches/0x0028ee60.cpp
// sym: ??0ShaderFloatBroadcast@fn_f4b93973@@QAE@HH@Z
ShaderFloatBroadcast::ShaderFloatBroadcast(int a, int b) {
    mZero = 0;
    mVft = ((hulk_intptr)DAT_0042cb5c);
    mA = a;
    mB = b;
}


// 0x0028ee80 pure3d::ShaderFloatBroadcast::vfunc_4 (7 B): matches/0x0028ee80.cpp
// sym: ?vfunc_1@?$Store@URoom@fn_f4b93973@@@fn_f4b93973@@UAEII@Z
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}

} // namespace fn_f4b93973

// 0x0028ee90 pure3d::ShaderFloatBroadcast::vfunc_5 (7 B): matches/0x0028ee90.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028ee90@@@fn_0028ee90@@UAEII@Z
namespace fn_0028ee90 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028ee90


// 0x0028eef0 pure3d::ShaderColourBroadcast::vfunc_4 (7 B): matches/0x0028eef0.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028eef0@@@fn_0028eef0@@UAEII@Z
namespace fn_0028eef0 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028eef0


// 0x0028ef00 pure3d::ShaderColourBroadcast::vfunc_5 (7 B): matches/0x0028ef00.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028ef00@@@fn_0028ef00@@UAEII@Z
namespace fn_0028ef00 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028ef00


// 0x0028ef10 pure3d::ShaderColourBroadcast::vfunc_3 (35 B): matches/0x0028ef10.cpp [wrapped: conflict: Shader]
// sym: ?vfunc_3@ShaderColourBroadcast@fn_0028ef10@@UAEPAVShader@2@PAV32@@Z
namespace fn_0028ef10 {
class Target {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void set(int, int);
};
class Shader {
    char pad[16];

  public:
    Target* target;
};
class ShaderColourBroadcast {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Shader* vfunc_3(Shader*);
    virtual void f4();
    virtual void f5();
    int pad, a;
    volatile int b;
};
Shader* ShaderColourBroadcast::vfunc_3(Shader* s) {
    if (s) {
        int y = b;
        int x = a;
        s->target->set(x, y);
    }
    return s;
}
} // namespace fn_0028ef10


// 0x0028ef60 pure3d::ShaderTextureBroadcast::vfunc_4 (7 B): matches/0x0028ef60.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028ef60@@@fn_0028ef60@@UAEII@Z
namespace fn_0028ef60 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028ef60


// 0x0028ef70 pure3d::ShaderTextureBroadcast::vfunc_5 (7 B): matches/0x0028ef70.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028ef70@@@fn_0028ef70@@UAEII@Z
namespace fn_0028ef70 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028ef70

namespace fn_f4b93973 {

// 0x0028ef80 pure3d::ShaderTextureBroadcast::vfunc_3 (60 B): equivalent/0x0028ef80.cpp
// sym: ?vfunc_3@ShaderTextureBroadcast@pure3d@fn_f4b93973@@UAEPAUContext@23@PAU423@@Z
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// pure3d::ShaderTextureBroadcast::vfunc_3 @ 0x0028ef80
namespace pure3d {
Context* ShaderTextureBroadcast::vfunc_3(Context* context) {
 if (context) context->shader->vfunc_5(id, texture ? texture->data : 0);
 return context;
}
}

} // namespace fn_f4b93973

// 0x0028f000 pure3d::ShaderVectorBroadcast::vfunc_4 (7 B): matches/0x0028f000.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028f000@@@fn_0028f000@@UAEII@Z
namespace fn_0028f000 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028f000


// 0x0028f010 pure3d::ShaderVectorBroadcast::vfunc_5 (7 B): matches/0x0028f010.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028f010@@@fn_0028f010@@UAEII@Z
namespace fn_0028f010 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028f010

namespace fn_f4b93973 {

// 0x0028f020 pure3d::ShaderVectorBroadcast::vfunc_3 (65 B): matches/0x0028f020.cpp
// sym: ?vfunc_3@ShaderVectorBroadcast_28f020@fn_f4b93973@@UAEHH@Z
int ShaderVectorBroadcast_28f020::vfunc_3(int p) {
    V local;
    if (p) {
        local = vec;
        Data_28f020* d = *(Data_28f020**)((char*)p + 0x10);
        d->j(source, (int*)&local);
    }
    return p;
}

} // namespace fn_f4b93973

// 0x0028f0a0 pure3d::ShaderMatrixBroadcast::vfunc_4 (7 B): matches/0x0028f0a0.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028f0a0@@@fn_0028f0a0@@UAEII@Z
namespace fn_0028f0a0 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028f0a0


// 0x0028f0b0 pure3d::ShaderMatrixBroadcast::vfunc_5 (7 B): matches/0x0028f0b0.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028f0b0@@@fn_0028f0b0@@UAEII@Z
namespace fn_0028f0b0 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028f0b0

namespace fn_f4b93973 {

// 0x0028f0c0 pure3d::ShaderMatrixBroadcast::vfunc_3 (58 B): matches/0x0028f0c0.cpp
// sym: ?vfunc_3@ShaderMatrixBroadcast@fn_f4b93973@@UAEHH@Z
int ShaderMatrixBroadcast::vfunc_3(int param) {
    Matrix copy;
    if (param) {
        int v = value;
        copy = matrix;
        Receiver_28f0c0* r = *(Receiver_28f0c0**)((char*)param + 0x10);
        r->send(v, &copy);
    }
    return param;
}


// 0x0028f100 FUN_0028f100 (36 B): matches/0x0028f100.cpp
// sym: ??1Shader_28f100@fn_f4b93973@@QAE@XZ
Shader_28f100::~Shader_28f100() {
    vptr = g_vftable_0042cb44;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin();
}

} // namespace fn_f4b93973

// 0x0028f150 pure3d::ShaderIntBroadcast::vfunc_4 (7 B): matches/0x0028f150.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028f150@@@fn_0028f150@@UAEII@Z
namespace fn_0028f150 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028f150


// 0x0028f160 pure3d::ShaderIntBroadcast::vfunc_5 (7 B): matches/0x0028f160.cpp [wrapped: same definition as 0x0028ee80 in this TU]
// sym: ?vfunc_1@?$Store@URoom@fn_0028f160@@@fn_0028f160@@UAEII@Z
namespace fn_0028f160 {
// Same code shape as 0x001c7ca0 (propagated; names are from that function)
struct StoreBase {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
template <class T> struct Store : StoreBase {
    virtual unsigned int vfunc_1(unsigned int x);
};
struct Room {};
template <> unsigned int Store<Room>::vfunc_1(unsigned int x) {
    return x;
}
} // namespace fn_0028f160

namespace fn_f4b93973 {

// 0x0028f170 pure3d::ShaderIntBroadcast::vfunc_2 (31 B): matches/0x0028f170.cpp
// sym: ?f2@NonCopyable@pure3d@fn_f4b93973@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_f4b93973

// 0x0028f190 pure3d::ShaderFloatBroadcast::vfunc_2 (31 B): matches/0x0028f190.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0028f190@@UAEPAV123@E@Z
namespace fn_0028f190 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ShaderCallback_28f190 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ShaderCallback_28f190 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0028f190


// 0x0028f1b0 pure3d::ShaderColourBroadcast::vfunc_2 (31 B): matches/0x0028f1b0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0028f1b0@@UAEPAV123@E@Z
namespace fn_0028f1b0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ShaderCallback_28f1b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ShaderCallback_28f1b0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0028f1b0


// 0x0028f1d0 pure3d::ShaderTextureBroadcast::vfunc_2 (31 B): matches/0x0028f1d0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0028f1d0@@UAEPAV123@E@Z
namespace fn_0028f1d0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ShaderCallback_28f1d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ShaderCallback_28f1d0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0028f1d0


// 0x0028f1f0 pure3d::ShaderVectorBroadcast::vfunc_2 (31 B): matches/0x0028f1f0.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0028f1f0@@UAEPAV123@E@Z
namespace fn_0028f1f0 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ShaderCallback_28f1f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ShaderCallback_28f1f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0028f1f0


// 0x0028f210 pure3d::ShaderMatrixBroadcast::vfunc_2 (31 B): matches/0x0028f210.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_0028f210@@UAEPAV123@E@Z
namespace fn_0028f210 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ShaderCallback_28f210 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ShaderCallback_28f210 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_0028f210

