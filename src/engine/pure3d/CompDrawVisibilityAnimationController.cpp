// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a7b90..0x002a83e0 (kind game, layer engine, confidence high), dominant class pure3d::CompDrawVisibilityAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fadd80aa {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fadd80aa {} using namespace fn_fadd80aa;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_fadd80aa {
extern "C" char DAT_0042dc24[];
class SceneGraphVisibilityAnimationController {
  public:
    void* vtable;
    char pad[0x3c];
    int a;
    int b;
    void base_ctor_00284cd0();
    void base_init_00284ad0(int);
    void* init();
};
struct SceneGraphVisibilityAnimationController_nv_2a7c30 {
    void init_00285780(pure3d::SceneGraphVisibilityAnimationController*);
    void setup_00284ad0(int);
};
extern void* __cdecl alloc_00263ea0(hulk_uintptr);
extern int hulk_at_0042dc24;
struct Helper_2a7d10 {
    void Decode_0028ac90(void* a, u8* out);
};
extern "C" char DAT_0048f610[];
extern "C" char DAT_004ce8a4[];
typedef unsigned int u32_2a7e90;
extern void* const EntityRTTI_2a7e90;
extern void* const VisibilityNodeRTTI;
extern u32_2a7e90 __cdecl FindType(hulk_uintptr, int, void*, void*, int);
class Obj_2a7ec0 {
  public:
    void Fn_0028ac90(void*, unsigned char*);
};
struct A_2a7ec0 {
    char pad[0x28];
    int count;
};
struct B_2a7ec0 {
    char pad[0x3c];
    unsigned char* bytes;
};
struct C_2a7ec0 {
    char pad[0x44];
    B_2a7ec0* b;
};
typedef unsigned int u32_2a7fa0;
void __cdecl thunk_FUN_00267090(u32_2a7fa0);
struct X_2a7fa0 {
    u32_2a7fa0 a;
    u32_2a7fa0 b;
    void f();
};
typedef unsigned int u32_2a7fd0;
void __cdecl thunk_FUN_00267090(u32_2a7fd0);
struct X_2a7fd0 {
    u32_2a7fd0 a;
    u32_2a7fd0 b;
    void f();
};
extern void* Alloc_0008d6d0(hulk_uintptr);
extern "C" int * __cdecl FUN_002a7f30(int *, int, const int *);
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" char * __cdecl FUN_002a7f60(char *, int, const char *);
extern void* hulk_at_0042dc94[];
class SimpleFrameController_2a80c0 {
  public:
    SimpleFrameController_2a80c0();
    virtual void f0();
    char pad[0x3c];
};
class CompDrawVisibilityAnimationController_2a80c0 : public SimpleFrameController_2a80c0 {
  public:
    CompDrawVisibilityAnimationController_2a80c0();
    virtual void f0();
    int m40;
    int m44;
    int m48;
    int pad4c;
    int m50;
    int m54;
};
extern int vt1_2a80f0;
extern void Free_0008d340(void*);
class SimpleFrameController_2a80f0 {
  public:
    void* vptr;
    ~SimpleFrameController_2a80f0() throw();
};
class CompDrawVisibilityAnimationController_2a80f0 : public SimpleFrameController_2a80f0 {
  public:
    char p[0x3c];
    int a40;
    hulk_intptr a44;
    char q[8];
    void* a50;
    ~CompDrawVisibilityAnimationController_2a80f0() throw();
};
extern int vt1_2a8170;
extern void Free2_00263f30(void*);
class SimpleFrameController_2a8170 {
  public:
    void* vptr;
    void Fini_00285800();
};
class CompDrawVisibilityAnimationController_2a8170 : public SimpleFrameController_2a8170 {
  public:
    char p[0x3c];
    int a40;
    hulk_intptr a44;
    char q[8];
    void* a50;
    CompDrawVisibilityAnimationController_2a8170* vfunc2(unsigned char f);
};
struct Key_2a81c0 { unsigned a,b; };
struct Item_2a81c0 { char pad[8]; Key_2a81c0 key; unsigned FUN_00288960(unsigned, unsigned); };
struct Source_2a81c0 { char pad[0x28]; int count;  };
struct Lookup_2a81c0 { unsigned char FUN_00298960(Key_2a81c0*); };
struct Context_2a81c0 { char pad[0x44]; Lookup_2a81c0* lookup; };
void __cdecl FUN_0008d340(void*);
struct ByteArray { unsigned char* data; unsigned size;  };
struct WordArray { unsigned* data; unsigned size;  };
class SimpleFrameController {
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
    virtual void vfunc_24(int, int, int);
};
class CompDrawVisibilityAnimationController : public SimpleFrameController {
  public:
    void vfunc_24(int, int, int);
};
struct CompDrawVisibilityAnimationController_nv_2a8310 {
};
extern "C" char DAT_0042dc94[];
typedef unsigned int u32_2a8360;
class Obj_2a8360 {
  public:
    hulk_uintptr vf;
    char pad[0x3c];
    u32_2a8360 value;
    u32_2a8360 a44;
    u32_2a8360 a48;
    u32_2a8360 unused4c;
    u32_2a8360 a50;
    u32_2a8360 a54;
    void init_00285780(pure3d::CompDrawVisibilityAnimationController*);
};
extern void* __cdecl FUN_00344e74(void*, int, const void*, const void*, int);
struct Helper_2a83b0 {
};
extern char hulk_at_0048f610;
extern char hulk_at_0049b9b8;


// 0x002a7b90 FUN_002a7b90 (35 B): matches/0x002a7b90.cpp
// sym: ?init@SceneGraphVisibilityAnimationController@fn_fadd80aa@@QAEPAXXZ
void* SceneGraphVisibilityAnimationController::init() {
    base_ctor_00284cd0();
    vtable = (void*)((hulk_intptr)DAT_0042dc24);
    a = 0;
    b = 0;
    base_init_00284ad0(1);
    return this;
}

} // namespace fn_fadd80aa

// 0x002a7c20 pure3d::SceneGraphVisibilityAnimationController::vfunc_3 (3 B): matches/0x002a7c20.cpp
// sym: ?vfunc_3@SceneGraphVisibilityAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::SceneGraphVisibilityAnimationController::vfunc_3() {
    return true;
}


// 0x002a7c30 pure3d::SceneGraphVisibilityAnimationController::vfunc_4 (72 B): matches/0x002a7c30.cpp
// sym: ?vfunc_4@SceneGraphVisibilityAnimationController@pure3d@@UAEPAXXZ
void* pure3d::SceneGraphVisibilityAnimationController::vfunc_4() {
    pure3d::SceneGraphVisibilityAnimationController* p = (pure3d::SceneGraphVisibilityAnimationController*)alloc_00263ea0(0x48);
    if (p) {
        ((SceneGraphVisibilityAnimationController_nv_2a7c30*)(p))->init_00285780(this);
        *(hulk_intptr*)p = (hulk_intptr)&hulk_at_0042dc24;
        (*(int *)&p->f_40) = (*(int *)&this->f_40);
        p->f_44 = 0;
        ((SceneGraphVisibilityAnimationController_nv_2a7c30*)(p))->setup_00284ad0(1);
        p->f_44 = this->f_44;
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x002a7c80 pure3d::SceneGraphVisibilityAnimationController::vfunc_24 (59 B): matches/0x002a7c80.cpp [wrapped: conflict: SceneGraphVisibilityAnimationController]
// sym: ?vfunc_24@SceneGraphVisibilityAnimationController@fn_002a7c80@@UAEXHHH@Z
namespace fn_002a7c80 {

class SimpleFrameController {
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
    virtual void vfunc_24(int, int, int);
    virtual void f25();
    char pad[0x38];
};
class D {
  public:
    void* get_00288960(void*, int);
};
class C_2a7c80 {
  public:
};
class SceneGraphVisibilityAnimationController : public SimpleFrameController {
  public:
    C_2a7c80* field3c;
    void* field40;
    virtual void vfunc_24(int, int, int);
};
void SceneGraphVisibilityAnimationController::vfunc_24(int a, int b, int c) {
    SimpleFrameController::vfunc_24(a, b, c);
    D* d = ((D *)((owners::Target_288a10 *)field3c)->FUN_00288a10(0));
    field40 = d->get_00288960((void*)((hulk_intptr)((char*)0x534956)), 0x4c4f4f42);
}
} // namespace fn_002a7c80


// 0x002a7cc0 pure3d::SceneGraphVisibilityAnimationController::vfunc_26 (39 B): matches/0x002a7cc0.cpp
// sym: ?vfunc_26@SceneGraphVisibilityAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::SceneGraphVisibilityAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && *(int*)((char*)p + 0x28) > 0)
        return *(int*)((char*)p + 0x1c) == 0x53495653;
    return false;
}


// 0x002a7cf0 FUN_002a7cf0 (10 B): matches/0x002a7cf0.cpp
// sym: ?FUN_002a7cf0@Thing_2a7cf0@owners@@QAEXH@Z
void owners::Thing_2a7cf0::FUN_002a7cf0(hulk_intptr x) {
    value = ((int)x);
}


// 0x002a7d10 pure3d::SceneGraphVisibilityAnimationController::vfunc_7 (34 B): matches/0x002a7d10.cpp
// sym: ?vfunc_7@SceneGraphVisibilityAnimationController@pure3d@@UAEXXZ
void pure3d::SceneGraphVisibilityAnimationController::vfunc_7() {
    u8 x;
    (*(Helper_2a7d10 * *)&this->f_40)->Decode_0028ac90((*(void * *)&this->f_34), &x);
    *((u8*)(*(void * *)&this->f_44) + 0x28) = x;
}


// 0x002a7d40 pure3d::CompDrawVisibilityAnimationController::vfunc_3 (3 B): matches/0x002a7d40.cpp
// sym: ?vfunc_3@CompDrawVisibilityAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::CompDrawVisibilityAnimationController::vfunc_3() {
    return true;
}


// 0x002a7d50 pure3d::CompDrawVisibilityAnimationController::vfunc_26 (39 B): matches/0x002a7d50.cpp
// sym: ?vfunc_26@CompDrawVisibilityAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::CompDrawVisibilityAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p != 0) {
        int* q = (int*)p;
        if (q[10] > 0) {
            return q[7] == 0x53495650;
        }
    }
    return false;
}


// 0x002a7e60 pure3d::SceneGraphVisibilityAnimationController::vfunc_2 (43 B): matches/0x002a7e60.cpp [wrapped: conflict: SceneGraphVisibilityAnimationController]
// sym: ?f2@SceneGraphVisibilityAnimationController@fn_002a7e60@@UAEPAV12@E@Z
namespace fn_002a7e60 {
typedef unsigned char byte_2a7e60;
class SceneGraphVisibilityAnimationController {
  public:
    virtual void f0();
    virtual void f1();
    virtual SceneGraphVisibilityAnimationController* f2(byte_2a7e60);
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
    char pad[0x44 - 4];
};
extern void* visibilityVtable;
struct ThisCall_00285800 {
    void FUN_00285800();
};
extern void thunk_FUN_00267090(SceneGraphVisibilityAnimationController*);
SceneGraphVisibilityAnimationController* SceneGraphVisibilityAnimationController::f2(byte_2a7e60 param) {
    *(void**)this = &visibilityVtable;
    *(int*)((char*)this + 0x44) = 0;
    ((ThisCall_00285800*)(this))->FUN_00285800();
    if (param & 1)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002a7e60


// 0x002a7e90 pure3d::SceneGraphVisibilityAnimationController::vfunc_5 (37 B): matches/0x002a7e90.cpp
// sym: ?vfunc_5@SceneGraphVisibilityAnimationController@pure3d@@UAEXPAX@Z
void pure3d::SceneGraphVisibilityAnimationController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    *(u32_2a7e90*)((char*)this + 0x44) = FindType(arg, 0, (void*)((hulk_intptr)DAT_0048f610), (void*)((hulk_intptr)DAT_004ce8a4), 0);
}


// 0x002a7ec0 pure3d::CompDrawVisibilityAnimationController::vfunc_7 (92 B): matches/0x002a7ec0.cpp
// sym: ?vfunc_7@CompDrawVisibilityAnimationController@pure3d@@UAEXXZ
void pure3d::CompDrawVisibilityAnimationController::vfunc_7() {
    int n = (*(A_2a7ec0 * *)&this->f_3c)->count;
    for (int i = 0; i < n; i++) {
        if ((*(unsigned char * *)&this->f_50)[i] != 0xff && (*(Obj_2a7ec0 ** *)&this->f_44)[i]) {
            unsigned char x;
            (*(Obj_2a7ec0 ** *)&this->f_44)[i]->Fn_0028ac90((*(void * *)&this->f_34), &x);
            (*(C_2a7ec0 * *)&this->f_40)->b->bytes[(*(unsigned char * *)&this->f_50)[i] * 12] = x;
        }
    }
}

namespace fn_fadd80aa {

// 0x002a7f30 FUN_002a7f30 (40 B): matches/0x002a7f30.cpp
// sym: _FUN_002a7f30
// Same code shape as 0x002ab530 (propagated; names are from that function)
extern "C" int* FUN_002a7f30(int* dst, int count, const int* src) {
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


// 0x002a7f60 FUN_002a7f60 (38 B): matches/0x002a7f60.cpp
// sym: _FUN_002a7f60
extern "C" char* FUN_002a7f60(char* dest, int count, const char* src) {
    if (count) {
        int n = count;
        char* p = dest;
        do {
            if (p)
                *p = *src;
            ++p;
            --n;
        } while (n);
        return p;
    }
    return dest;
}


// 0x002a7fa0 FUN_002a7fa0 (33 B): matches/0x002a7fa0.cpp
// sym: ?f@X_2a7fa0@fn_fadd80aa@@QAEXXZ
// Same code shape as 0x002a47d0 (propagated; names are from that function)
void X_2a7fa0::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}


// 0x002a7fd0 FUN_002a7fd0 (33 B): matches/0x002a7fd0.cpp
// sym: ?f@X_2a7fd0@fn_fadd80aa@@QAEXXZ
// Same code shape as 0x002a47d0 (propagated; names are from that function)
void X_2a7fd0::f() {
    if (a != 0)
        thunk_FUN_00267090(a);
    a = 0;
    b = 0;
}

} // namespace fn_fadd80aa

// 0x002a8000 FUN_002a8000 (95 B): matches/0x002a8000.cpp
// sym: ?FUN_002a8000@Buffer_2a8000@owners@@QAE_NIPAX@Z
// Same code shape as 0x00290790 (propagated; names are from that function)
bool owners::Buffer_2a8000::FUN_002a8000(unsigned int count, void* arg) {
    if (begin != 0)
        return false;
    if (count > 0) {
        int* p = (int*)Alloc_0008d6d0(count * 4);
        begin = p;
        if (p != 0) {
            end = p + count;
            FUN_002a7f30((int *)(void *)p, (unsigned int)count, (const int *)(void *)arg);
            return true;
        }
    }
    begin = 0;
    end = 0;
    return false;
}


// 0x002a8060 FUN_002a8060 (86 B): matches/0x002a8060.cpp
// sym: ?FUN_002a8060@Buffer_2a8060@owners@@QAE_NII@Z
bool owners::Buffer_2a8060::FUN_002a8060(unsigned int size, hulk_uintptr arg) {
    if (mData != 0)
        return false;
    if (size > 0) {
        void* p = FUN_0008d6d0(size);
        mData = p;
        if (p != 0) {
            mEnd = (char*)p + size;
            FUN_002a7f60((char *)(void *)p, (unsigned int)size, (const char *)(hulk_uintptr)(unsigned int)((unsigned int)arg));
            return true;
        }
    }
    mData = 0;
    mEnd = 0;
    return false;
}

namespace fn_fadd80aa {

// 0x002a80c0 FUN_002a80c0 (35 B): matches/0x002a80c0.cpp
// sym: ??0CompDrawVisibilityAnimationController_2a80c0@fn_fadd80aa@@QAE@XZ
CompDrawVisibilityAnimationController_2a80c0::CompDrawVisibilityAnimationController_2a80c0() {
    m40 = 0;
    *(void**)this = hulk_at_0042dc94;
    _ReadWriteBarrier();
    m44 = 0;
    m48 = 0;
    m50 = 0;
    m54 = 0;
}


// 0x002a80f0 FUN_002a80f0 (56 B): matches/0x002a80f0.cpp
// sym: ??1CompDrawVisibilityAnimationController_2a80f0@fn_fadd80aa@@QAE@XZ
CompDrawVisibilityAnimationController_2a80f0::~CompDrawVisibilityAnimationController_2a80f0() throw() {
    vptr = &vt1_2a80f0;
    a40 = 0;
    _ReadWriteBarrier();
    if (a50)
        Free_0008d340(a50);
    if (a44)
        Free_0008d340((void*)a44);
}


// 0x002a8170 pure3d::CompDrawVisibilityAnimationController::vfunc_2 (77 B): matches/0x002a8170.cpp
// sym: ?vfunc2@CompDrawVisibilityAnimationController_2a8170@fn_fadd80aa@@QAEPAV12@E@Z
CompDrawVisibilityAnimationController_2a8170* CompDrawVisibilityAnimationController_2a8170::vfunc2(unsigned char f) {
    vptr = &vt1_2a8170;
    a40 = 0;
    _ReadWriteBarrier();
    if (a50)
        Free_0008d340(a50);
    if (a44)
        Free_0008d340((void*)a44);
    Fini_00285800();
    if (f & 1)
        Free2_00263f30(this);
    return this;
}

} // namespace fn_fadd80aa

// 0x002a81c0 FUN_002a81c0 (277 B): equivalent/0x002a81c0.cpp
// sym: ?FUN_002a81c0@CompDrawVisibilityAnimationController@pure3d@@QAEXXZ @7e461c8a5249 @w9768680e7646
// STATUS: equivalent (tools/equiv.py level 3: 11844 inputs, branch coverage 16/16)
// FUN_002a81c0 @ 0x002a81c0
void pure3d::CompDrawVisibilityAnimationController::FUN_002a81c0() {
 if ((*(Source_2a81c0 * *)&this->f_3c) && (*(Context_2a81c0 * *)&this->f_40)) {
  struct Frame {          // (the original's slot order)
   char pad[3];
   unsigned char zeroByte;
   union { unsigned zeroWord; Key_2a81c0 key; } u;
   int count;
  } f;
  f.count=(*(Source_2a81c0 * *)&this->f_3c)->count;
  if((*(ByteArray *)&this->f_50).data) FUN_0008d340((*(ByteArray *)&this->f_50).data);
  (*(ByteArray *)&this->f_50).data=0; (*(ByteArray *)&this->f_50).size=0;
  f.zeroByte=0;
  ((owners::Buffer_2a8060 *)&((*(ByteArray *)&this->f_50)))->FUN_002a8060((unsigned int)(f.count), (hulk_uintptr)(&f.zeroByte));
  if((*(WordArray *)&this->f_44).data) FUN_0008d340((*(WordArray *)&this->f_44).data);
  (*(WordArray *)&this->f_44).data=0; (*(WordArray *)&this->f_44).size=0;
  f.u.zeroWord=0;
  ((owners::Buffer_2a8000 *)&((*(WordArray *)&this->f_44)))->FUN_002a8000((unsigned int)(f.count), &f.u.zeroWord);
  for(int i=0;i<f.count;++i) {
   Item_2a81c0* item=((Item_2a81c0 *)((owners::Target_288a10 *)((*(Source_2a81c0 * *)&this->f_3c)))->FUN_00288a10(i));
   f.u.key=item->key;
   unsigned char* dest=(*(ByteArray *)&this->f_50).data+i;
   unsigned char result=(*(Context_2a81c0 * *)&this->f_40)->lookup->FUN_00298960(&f.u.key);
   *dest=result;
   unsigned* out=(*(WordArray *)&this->f_44).data+i;
   item=((Item_2a81c0 *)((owners::Target_288a10 *)((*(Source_2a81c0 * *)&this->f_3c)))->FUN_00288a10(i));
   *out=item->FUN_00288960(0x534956,0x4c4f4f42);
  }
 } else {
  if((*(ByteArray *)&this->f_50).data) FUN_0008d340((*(ByteArray *)&this->f_50).data);
  (*(ByteArray *)&this->f_50).data=0; (*(ByteArray *)&this->f_50).size=0;
  if((*(WordArray *)&this->f_44).data) FUN_0008d340((*(WordArray *)&this->f_44).data);
  (*(WordArray *)&this->f_44).data=0; (*(WordArray *)&this->f_44).size=0;
 }
}

namespace fn_fadd80aa {

// 0x002a82e0 pure3d::CompDrawVisibilityAnimationController::vfunc_24 (36 B): matches/0x002a82e0.cpp
// sym: ?vfunc_24@CompDrawVisibilityAnimationController@fn_fadd80aa@@UAEXHHH@Z
void CompDrawVisibilityAnimationController::vfunc_24(int a, int b, int c) {
    SimpleFrameController::vfunc_24(a, b, c);
    ((pure3d::CompDrawVisibilityAnimationController *)this)->FUN_002a81c0();
}

} // namespace fn_fadd80aa

// 0x002a8310 FUN_002a8310 (15 B): matches/0x002a8310.cpp
// sym: ?FUN_002a8310@CompDrawVisibilityAnimationController@pure3d@@QAEXH@Z
void pure3d::CompDrawVisibilityAnimationController::FUN_002a8310(int x) {
    (*(int *)&this->f_40) = x;
    ((pure3d::CompDrawVisibilityAnimationController *)(((CompDrawVisibilityAnimationController_nv_2a8310*)this)))->FUN_002a81c0();
}


// 0x002a8360 pure3d::CompDrawVisibilityAnimationController::vfunc_4 (77 B): matches/0x002a8360.cpp
// sym: ?vfunc_4@CompDrawVisibilityAnimationController@pure3d@@UAEPAXXZ
void* pure3d::CompDrawVisibilityAnimationController::vfunc_4() {
    Obj_2a8360* p = (Obj_2a8360*)alloc_00263ea0(0x60);
    if (p) {
        p->init_00285780(this);
        p->value = 0;
        p->vf = ((hulk_intptr)DAT_0042dc94);
        p->a44 = 0;
        p->a48 = 0;
        p->a50 = 0;
        p->a54 = 0;
        p->value = (*(u32_2a8360 *)&this->f_40);
        ((pure3d::CompDrawVisibilityAnimationController *)p)->FUN_002a81c0();
        return (void*)(p);
    }
    return (void*)(0);
}


// 0x002a83b0 pure3d::CompDrawVisibilityAnimationController::vfunc_5 (44 B): matches/0x002a83b0.cpp
// sym: ?vfunc_5@CompDrawVisibilityAnimationController@pure3d@@UAEXPAX@Z
void pure3d::CompDrawVisibilityAnimationController::vfunc_5(void* __p0) { void * arg = (void *)__p0;

    (*(void * *)&this->f_40) = FUN_00344e74(arg, 0, &hulk_at_0048f610, &hulk_at_0049b9b8, 0);
    ((pure3d::CompDrawVisibilityAnimationController *)(((Helper_2a83b0*)this)))->FUN_002a81c0();
}

