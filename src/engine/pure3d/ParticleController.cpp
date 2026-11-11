// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a6fb0..0x002a7730 (kind game, layer engine, confidence high), dominant class pure3d::ParticleController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fa907639 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fa907639 {} using namespace fn_fa907639;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace pure3d {
class AnimationFrameController_2a7000 {
  public:
    float vfunc_20();
};
}
namespace pure3d {
const float gMaxFloat = 3.402823466e+38F;
}
namespace fn_fa907639 {
extern hulk_freg __cdecl FUN_002899e0(float*, float*, float, float, int, int, bool, int);
class Item_2a7150 {
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
    virtual void Update(float, float);
};
struct Vec_2a7150 {
    Item_2a7150** begin;
    Item_2a7150** end;
    hulk_uintptr size() const { return end - begin; }
    Item_2a7150* at(unsigned i) const { return begin[i]; }
};
class ParticleController_2a7150 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void vfunc_7();
    char pad08[0x1c];
    int m20;
    int m24;
    float m28;
    int m2c;
    int m30;
    float m34;
    float m38;
    char pad3c[0x0c];
    float m48;
    float m4c;
    Vec_2a7150 v;
};
class Item {
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
    virtual unsigned int Count();
};
class SimpleFrameController_2a71d0 {
  public:
    virtual unsigned char vfunc_22();
};
class ParticleController : public SimpleFrameController_2a71d0 {
    char pad[0x4c];
    Item** begin;
    Item** end;

  public:
    virtual unsigned char vfunc_22();
};
typedef unsigned int u32_2a7340;
void __cdecl thunk_FUN_00267090(u32_2a7340);
struct X_2a7340 {
    u32_2a7340 a;
    u32_2a7340 b;
    void f();
};
extern void* Alloc(hulk_uintptr);
extern "C" int * __cdecl FUN_002a72b0(int *, int, const int *);
class Buffer_2a7370 {
  public:
    int* begin;
    int* end;
    bool Create(unsigned int count, void* arg);
};
struct SimpleFrameController_2a73d0 {
    virtual void f0();
    SimpleFrameController_2a73d0();
    char pad[0x3c];
};
struct ParticleController_2a73d0 : SimpleFrameController_2a73d0 {
    ParticleController_2a73d0();
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
    virtual void hulk_slot_vfunc_23(); void vfunc_23();
    char m40;
    float m44;
    float m48;
    int m4c;
    int m50;
    int m54;
};
class Other_2a7540 {
  public:
    hulk_intptr helper(pure3d::ParticleController*);
};
class Owned_2a75a0 {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
};
struct SourceEntry_2a75a0 {
    Owned_2a75a0 *item;
    int pad[3];
};
struct Source_2a75a0 {
    char pad00[0x48];
    SourceEntry_2a75a0 *begin;
    SourceEntry_2a75a0 *end;
    char pad50[8];
    char flag;
    char pad59[3];
    int valueA;
    int valueB;
};
void *__cdecl FUN_0008d6d0(unsigned int size);
void __cdecl FUN_0008d340(void *p);
class Holder_2a75a0 {
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
    virtual void vfunc_14(int a, int b);
    char pad04[0x24 - 4];
    int notFlag;
    char pad28[0x40 - 0x28];
    char flag;
    char pad41[3];
    int valueA;
    int valueB;
    char pad4c[4];
    Owned_2a75a0 **begin;
    Owned_2a75a0 **end;
    void FUN_002a75a0(const Source_2a75a0 *src);
};
typedef unsigned int U_2a7700;
extern U_2a7700 __cdecl Query(hulk_uintptr, U_2a7700, const void*, const void*, U_2a7700);
extern char EntityRTTI_2a7700;
struct ParticleController_nv_2a7700 {
    void Finish(U_2a7700);
};

} // namespace fn_fa907639

// 0x002a6fb0 pure3d::ParticleController::vfunc_3 (3 B): matches/0x002a6fb0.cpp
// sym: ?vfunc_3@ParticleController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ParticleController::vfunc_3() {
    return true;
}


// 0x002a6fc0 pure3d::ParticleController::vfunc_26 (5 B): matches/0x002a6fc0.cpp
// sym: ?vfunc_26@ParticleController@pure3d@@UAE_NPAX@Z
// Same code shape as 0x00244f40 (propagated; names are from that function)
bool pure3d::ParticleController::vfunc_26(void* __p0) { hulk_intptr a = (hulk_intptr)__p0;

    return false;
}


// 0x002a6fd0 pure3d::ParticleController::vfunc_6 (16 B): matches/0x002a6fd0.cpp
// sym: ?vfunc_6@ParticleController@pure3d@@UAEXMD@Z
void pure3d::ParticleController::vfunc_6(float param, char __p1) { int unused = (int)__p1;

    this->f_4c = param * this->f_18 + this->f_4c;
}


// 0x002a6fe0 pure3d::ParticleController::vfunc_10 (4 B): matches/0x002a6fe0.cpp
// sym: ?vfunc_10@ParticleController@pure3d@@UAEMXZ
// Same code shape as 0x00069120 (propagated; names are from that function)
hulk_freg pure3d::ParticleController::vfunc_10() {
    return this->f_48;
}


// 0x002a6ff0 pure3d::ParticleController::vfunc_11 (4 B): matches/0x002a6ff0.cpp
// sym: ?vfunc_11@ParticleController@pure3d@@UAEMXZ
// Same code shape as 0x00069110 (propagated; names are from that function)
hulk_freg pure3d::ParticleController::vfunc_11() {
    return *(float*)((char*)this + 0x44);
}


// 0x002a7000 pure3d::ParticleController::vfunc_20 (32 B): matches/0x002a7000.cpp
// sym: ?vfunc_20@ParticleController@pure3d@@UAEMXZ
 // namespace pure3d
hulk_freg pure3d::ParticleController::vfunc_20() {
    if (this->f_20 == 0) {
        if (this->f_40 == 1)
            return gMaxFloat;
        return (*(float *)&this->f_30) - (*(float *)&this->f_2c);
    }
    return ((AnimationFrameController_2a7000*)this)->vfunc_20();
}

namespace fn_fa907639 {

// 0x002a7150 pure3d::ParticleController::vfunc_7 (128 B): matches/0x002a7150.cpp
// sym: ?vfunc_7@ParticleController_2a7150@fn_fa907639@@UAEXXZ
void ParticleController_2a7150::vfunc_7() {
    float delta = m48 * m4c * 0.001f;
    m34 = FUN_002899e0(&m28, &m38, m34, delta, m2c, m30, m24 == 0, m20);
    unsigned i = 0;
    if (v.size() > 0) {
        do {
            v.at(i)->Update(m34, delta);
            i++;
        } while (i < v.size());
    }
    m4c = 0.0f;
}


// 0x002a71d0 pure3d::ParticleController::vfunc_22 (75 B): matches/0x002a71d0.cpp
// sym: ?vfunc_22@ParticleController@fn_fa907639@@UAEEXZ
unsigned char ParticleController::vfunc_22() {
    if (SimpleFrameController_2a71d0::vfunc_22() == 1) {
        for (unsigned int i = 0; i < (unsigned int)(end - begin); ++i) {
            if (begin[i]->Count() > 0)
                return 0;
        }
        return 1;
    }
    return 0;
}

} // namespace fn_fa907639

// 0x002a7220 pure3d::ParticleController::vfunc_23 (97 B): matches/0x002a7220.cpp [wrapped: conflict: pure3d::ParticleController]
// sym: ?vfunc_23@ParticleController@pure3d@fn_002a7220@@UAEXXZ
namespace fn_002a7220 {
namespace pure3d {
class Particle_2a7220 {
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
};
class ParticleController {
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
    virtual float v20();
    virtual void v21();
    virtual void v22();
    virtual void vfunc_23();
    char pad[0x20 - 4];
    int a20;
    int a24;
    float a28;
    int a2c;
    int a30;
    int a34;
    char a38;
    char pad2[7];
    char a40;
    char pad3[3];
    int a44;
    int a48;
    int a4c;
    Particle_2a7220** begin;
    Particle_2a7220** end;
};
void ParticleController::vfunc_23() {
    int x = a44;
    a20 = 0;
    a2c = 0;
    a34 = 0;
    a24 = (a40 != 1);
    a30 = x;
    a28 = v20();
    volatile char* flag = &a38;
    *flag = 1;
    for (unsigned i = 0; i < (unsigned)(end - begin); ++i)
        begin[i]->f15();
    a4c = 0;
}
} // namespace pure3d
} // namespace fn_002a7220

namespace fn_fa907639 {

// 0x002a72b0 FUN_002a72b0 (40 B): matches/0x002a72b0.cpp
// sym: _FUN_002a72b0
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002a72b0(int* dst, int count, const int* src) {
    if (count) {
        int n = count;
        int* p = dst;
        const int* s = src;
        do {
            if (p)
                *p = *s;
            p = (int*)((char*)p + 4);
        } while (--n);
        return p;
    }
    return dst;
}


// 0x002a7340 FUN_002a7340 (33 B): matches/0x002a7340.cpp
// sym: ?f@X_2a7340@fn_fa907639@@QAEXXZ
// Same code shape as 0x002a47d0 (propagated; names are from that function)
void X_2a7340::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}


// 0x002a7370 FUN_002a7370 (95 B): matches/0x002a7370.cpp
// sym: ?Create@Buffer_2a7370@fn_fa907639@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool Buffer_2a7370::Create(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002a72b0((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002a73d0 FUN_002a73d0 (54 B): matches/0x002a73d0.cpp
// sym: ??0ParticleController_2a73d0@fn_fa907639@@QAE@XZ
ParticleController_2a73d0::ParticleController_2a73d0() {
    m40 = 1;
    m44 = 100.0f;
    m48 = 30.0f;
    m4c = 0;
    _ReadWriteBarrier();
    m50 = 0;
    m54 = 0;
    vfunc_23();
}

} // namespace fn_fa907639

// 0x002a7410 FUN_002a7410 (197 B): equivalent/0x002a7410.cpp [wrapped: conflict: pure3d::ParticleController]
// sym: ??0ParticleController@pure3d@fn_002a7410@@QAE@ABU012@@Z @4e6625c347c6 @w5df8bb1efc7d
namespace fn_002a7410 {
// STATUS: equivalent (tools/equiv.py level 3: 56 inputs, branch coverage 12/12)
// FUN_002a7410 @ 0x002a7410
typedef unsigned int uint;
struct RefObject_2a7410 { virtual void AddRef(); virtual void Release(); };
void* __cdecl FUN_0008d6d0(uint);
struct SimpleFrameController_2a7410 { virtual void v0(); char pad[0x3c]; SimpleFrameController_2a7410(const SimpleFrameController_2a7410&); };
namespace pure3d {
struct ParticleController : SimpleFrameController_2a7410 {
 virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void vfunc_23();
 unsigned char flag; char gap[3]; uint a,b,c; RefObject_2a7410** begin; RefObject_2a7410** end;
 ParticleController(const ParticleController&);
};
ParticleController::ParticleController(const ParticleController& src) : SimpleFrameController_2a7410(src) {
 flag=src.flag; a=src.a; b=src.b; c=src.c;
 uint count=(uint)(((int)((char*)src.end-(char*)src.begin))>>2);
 if(count) {
 uint bytes=count*4;
 RefObject_2a7410** allocated=(RefObject_2a7410**)FUN_0008d6d0(bytes);
 begin=allocated;
 if(allocated) end=(RefObject_2a7410**)((char*)allocated+bytes);
 else { begin=0; end=0; }
 } else { begin=0; end=0; }
 for(uint i=0;i<(uint)(((int)((char*)end-(char*)begin))>>2);++i) {
 begin[i]=0;
 RefObject_2a7410* obj=src.begin[i];
 RefObject_2a7410** slot=begin+i;
 if(obj) obj->AddRef();
 if(*slot) (*slot)->Release();
 *slot=obj;
 }
 ParticleController::vfunc_23();
}
}
} // namespace fn_002a7410


// 0x002a74e0 FUN_002a74e0 (95 B): matches/0x002a74e0.cpp [wrapped: conflict: pure3d::ParticleController; pure3d::SimpleFrameController]
// sym: ??1ParticleController@pure3d@fn_002a74e0@@UAE@XZ
namespace fn_002a74e0 {
namespace pure3d {
extern void Free(void*) throw();
class Ref_2a74e0 {
  public:
    virtual void f0() throw();
    virtual void Release() throw();
};
template <class T> struct Vec_2a74e0 {
    T* b;
    T* e;
    T* c;
    unsigned size() const { return (unsigned)(e - b); }
    T& operator[](unsigned i) { return b[i]; }
    ~Vec_2a74e0() throw() {
        if (b)
            Free(b);
    }
};
class SimpleFrameController {
  public:
    virtual ~SimpleFrameController() throw();
    char p[0x4c];
};
class ParticleController : public SimpleFrameController {
  public:
    Vec_2a74e0<Ref_2a74e0*> v;
    virtual ~ParticleController() throw();
};
ParticleController::~ParticleController() throw() {
    for (unsigned i = 0; i < v.size(); i++) {
        Ref_2a74e0*& r = v[i];
        if (r) {
            r->Release();
            r = 0;
        }
    }
}
} // namespace pure3d
} // namespace fn_002a74e0


// 0x002a7540 pure3d::ParticleController::vfunc_4 (31 B): matches/0x002a7540.cpp
// sym: ?vfunc_4@ParticleController@pure3d@@UAEPAXXZ
void* pure3d::ParticleController::vfunc_4() {
    pure3d::ParticleController* self = this;
    Other_2a7540* p = (Other_2a7540*)allocate(0x60);
    if (p)
        return (void*)(p->helper(self));
    return (void*)(0);
}

namespace fn_fa907639 {

// 0x002a75a0 FUN_002a75a0 (340 B): equivalent/0x002a75a0.cpp
// sym: ?FUN_002a75a0@Holder_2a75a0@fn_fa907639@@QAEXPBUSource_2a75a0@2@@Z @d0f761b50a98 @wce4032f9f209
// STATUS: equivalent (tools/equiv.py level 3: 34 inputs, branch coverage 25/30, incomplete)
// FUN_002a75a0 @ 0x002a75a0
void Holder_2a75a0::FUN_002a75a0(const Source_2a75a0 *src)
{
    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        Owned_2a75a0 **slot = &begin[i];
        Owned_2a75a0 *o = *slot;
        if (o) {
            o->vfunc_1();
            *slot = 0;
        }
    }

    if ((unsigned int)(src->end - src->begin) != (unsigned int)(end - begin)) {
        if (begin)
            FUN_0008d340(begin);
        begin = 0;
        end = 0;
        unsigned int n = (unsigned int)(src->end - src->begin);
        if (n == 0) {
            begin = 0;
            end = 0;
        } else {
            Owned_2a75a0 **mem = (Owned_2a75a0 **)FUN_0008d6d0(n * sizeof(Owned_2a75a0 *));
            begin = mem;
            if (mem == 0) {
                begin = 0;
                end = 0;
            } else {
                end = mem + n;
                for (; n != 0; n--) {
                    if (mem)
                        *mem = 0;
                    mem++;
                }
            }
        }
    }

    for (unsigned int i = 0; i < (unsigned int)(end - begin); i++) {
        Owned_2a75a0 *o = src->begin[i].item;
        Owned_2a75a0 **slot = &begin[i];
        if (o)
            o->vfunc_0();
        if (*slot)
            (*slot)->vfunc_1();
        *slot = o;
    }

    flag = src->flag;
    notFlag = (src->flag == 0);
    valueA = src->valueA;
    valueB = src->valueB;
    vfunc_14(0, src->valueA);
}

} // namespace fn_fa907639

// 0x002a7700 pure3d::ParticleController::vfunc_5 (42 B): matches/0x002a7700.cpp
// sym: ?vfunc_5@ParticleController@pure3d@@UAEXPAX@Z
// Same code shape as 0x00293970 (propagated; names are from that function)
void pure3d::ParticleController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    U_2a7700 x = Query(arg, 0, &EntityRTTI_2a7700, &CameraRTTI, 0);
    ((ParticleController_nv_2a7700*)this)->Finish(x);
}

