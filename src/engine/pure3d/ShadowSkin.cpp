// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002deeb0..0x002df4d0 (kind game, layer engine, confidence high), dominant class pure3d::ShadowSkin
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fb97e5a1 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fb97e5a1 {} using namespace fn_fb97e5a1;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
void* operator new(size_t) HULK_NEW_THROW;
namespace fn_fb97e5a1 {
class MeshData {
  public:
    char pad[0x70];
    MeshData() throw();
};
class Shadow_2deeb0 {
  public:
    Shadow_2deeb0(int) throw();
    void Set_002a4500(int, MeshData*) throw();
    virtual void dummy();
};
class ShadowMesh : public Shadow_2deeb0 {
  public:
    ShadowMesh() throw();
    virtual void dummy();
};
extern void* hulk_at_0042f994[];
class Shadow_2def20 {
  public:
    void Destroy_002a4ff0(); // FUN_00236d60, __thiscall, this in ecx
};
class ShadowMesh_2def20 : public Shadow_2def20 {
  public:
    ShadowMesh_2def20* vfunc_5(signed char flags);
};
void* __cdecl alloc(hulk_uintptr);
class Shadow_2defb0 {
  public:
    Shadow_2defb0(int);
    virtual void v();
};
class ShadowSkin : public Shadow_2defb0 {
  public:
    ShadowSkin();
    virtual void v();
    void set_002a4500(int, void*);
};
class ShadowSkinImpl_2defb0 {
  public:
    void* get_002b55b0();
};
extern void* Shadow_2df020_vftable[];
class Shadow_2df020 {
  public:
    void Destroy_002a4ff0(); // FUN_00236d60, __thiscall, this in ecx
};
class ShadowSkin_2df020 : public Shadow_2df020 {
  public:
    ShadowSkin_2df020* vfunc_5(signed char flags);
};
extern "C" char DAT_0042fa64[];
struct ShadowSkin_nv_2df070 {
    void Init_002a4e40(pure3d::ShadowSkin*);
};
extern void* __cdecl alloc_00263ea0(int);
class ShadowMeshBuffer_2df0b0 {
  public:
    virtual void f();
    ShadowMeshBuffer_2df0b0* construct(void*);
};
struct ShadowSkin_nv_2df0b0 {
    void InitRestPose_002a4e10(void*);
};
extern void* Shadow_2df140_vftable[];
class Shadow_2df140 {
  public:
    void Destroy_002a4ff0(); // FUN_00236d60, __thiscall, this in ecx
};
class ShadowMeshBuffer_2df140 : public Shadow_2df140 {
  public:
    ShadowMeshBuffer_2df140* vfunc_5(signed char flags);
};
class Helper_2df210 {
  public:
    void run_002b4710();
};
class Helper_2df220 {
  public:
    void run_002b46c0(int, int);
};
class Helper_2df230 {
  public:
    void run_002b4890();
};
class Inner_2df240 {
  public:
    void Fnf_002b57d0(int);
};
class ShadowSkin_2df250 {
    char pad[0x48];
    struct Holder {
        int* p;
    }* holder;

  public:
    void vfunc_20(unsigned char a, int* b);
};
class Helper_2df290 {
  public:
    void run_002b4710();
};
class Helper_2df2a0 {
  public:
    void run_002b46c0(int, int);
};
class Helper_2df2b0 {
  public:
    void run_002b4890();
};


// 0x002deeb0 FUN_002deeb0 (66 B): matches/0x002deeb0.cpp
// sym: ??0ShadowMesh@fn_fb97e5a1@@QAE@XZ
ShadowMesh::ShadowMesh() throw() : Shadow_2deeb0(1) {
    MeshData* p = new MeshData;
    Set_002a4500(0, p);
}


// 0x002def00 pure3d::ShadowMesh::vfunc_15 (6 B): matches/0x002def00.cpp
// sym: ?FUN_002def00@fn_fb97e5a1@@YAIXZ
// Same code shape as 0x00036c80 (propagated; names are from that function)
unsigned int FUN_002def00(void) {
    return 0x20;
}

} // namespace fn_fb97e5a1

// 0x002def10 pure3d::ShadowMesh::vfunc_3 (3 B): matches/0x002def10.cpp
// sym: ?vfunc_3@ShadowMesh@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ShadowMesh::vfunc_3() {
    return true;
}

namespace fn_fb97e5a1 {

// 0x002def20 pure3d::ShadowMesh::vfunc_2 (36 B): matches/0x002def20.cpp
// sym: ?vfunc_5@ShadowMesh_2def20@fn_fb97e5a1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ShadowMesh_2def20* ShadowMesh_2def20::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_0042f994;
    Destroy_002a4ff0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb97e5a1

// 0x002def70 pure3d::ShadowMesh::vfunc_4 (44 B): matches/0x002def70.cpp [wrapped: conflict: ShadowMesh]
// sym: ?vfunc_4@ShadowMesh@fn_002def70@@QAEPAV12@XZ
namespace fn_002def70 {
class ShadowMesh {
  public:
    int* vptr;
    ShadowMesh* vfunc_4();
};
class ShadowSkin_2def70 {
  public:
    void Call_002a4e40(ShadowMesh*);
};
extern "C++" __declspec(nothrow) void* __cdecl thunk_FUN_0008d690(unsigned int);
extern int hulk_at_0042f9fc[];
ShadowMesh* ShadowMesh::vfunc_4() {
    ShadowMesh* p = (ShadowMesh*)thunk_FUN_0008d690(0x58);
    if (p) {
        ((ShadowSkin_2def70*)p)->Call_002a4e40(this);
        p->vptr = hulk_at_0042f9fc;
        return p;
    }
    return 0;
}
} // namespace fn_002def70

// 0x002defa0 pure3d::ShadowMesh::vfunc_8 (5 B): not yet verified
namespace fn_fb97e5a1 {

// 0x002defb0 FUN_002defb0 (69 B): matches/0x002defb0.cpp
// sym: ??0ShadowSkin@fn_fb97e5a1@@QAE@XZ
ShadowSkin::ShadowSkin() : Shadow_2defb0(1) {
    ShadowSkinImpl_2defb0* b = (ShadowSkinImpl_2defb0*)alloc_00263ea0(0x80);
    set_002a4500(0, b ? b->get_002b55b0() : 0);
}

} // namespace fn_fb97e5a1

// 0x002df000 pure3d::ShadowSkin::vfunc_15 (6 B): matches/0x002df000.cpp
// sym: ?vfunc_15@ShadowSkin@pure3d@@UAEHXZ
 // namespace pure3d
int pure3d::ShadowSkin::vfunc_15() {
    return 0x40;
}


// 0x002df010 pure3d::ShadowSkin::vfunc_3 (3 B): matches/0x002df010.cpp
// sym: ?vfunc_3@ShadowSkin@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ShadowSkin::vfunc_3() {
    return true;
}

namespace fn_fb97e5a1 {

// 0x002df020 pure3d::ShadowSkin::vfunc_2 (36 B): matches/0x002df020.cpp
// sym: ?vfunc_5@ShadowSkin_2df020@fn_fb97e5a1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ShadowSkin_2df020* ShadowSkin_2df020::vfunc_5(signed char flags) {
    *(void***)this = Shadow_2df020_vftable;
    Destroy_002a4ff0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb97e5a1

// 0x002df070 pure3d::ShadowSkin::vfunc_4 (44 B): matches/0x002df070.cpp
// sym: ?vfunc_4@ShadowSkin@pure3d@@UAEPAXXZ
void* pure3d::ShadowSkin::vfunc_4() {
    pure3d::ShadowSkin* q = (pure3d::ShadowSkin*)alloc_00263ea0(0x58);
    if (q) {
        ((ShadowSkin_nv_2df070*)(q))->Init_002a4e40(this);
        *(hulk_intptr*)q = ((hulk_intptr)DAT_0042fa64);
        return (void*)(q);
    }
    return (void*)(0);
}

// 0x002df0a0 pure3d::ShadowSkin::vfunc_8 (5 B): not yet verified
namespace fn_fb97e5a1 {

// 0x002df0b0 FUN_002df0b0 (25 B): matches/0x002df0b0.cpp
// sym: ?construct@ShadowMeshBuffer_2df0b0@fn_fb97e5a1@@QAEPAV12@PAX@Z
// Same code shape as 0x0022a5d0 (propagated; names are from that function)
ShadowMeshBuffer_2df0b0* ShadowMeshBuffer_2df0b0::construct(void* arg) {
    ((ShadowSkin_nv_2df0b0*)(((pure3d::ShadowSkin*)(((pure3d::ShadowSkin*)(this))))))->InitRestPose_002a4e10(arg);
    *(void**)this = &RestPoseVtable;
    return this;
}

} // namespace fn_fb97e5a1

// 0x002df0d0 pure3d::ShadowMeshBuffer::vfunc_20 (3 B): matches/0x002df0d0.cpp
// sym: ?vfunc_20@ShadowMeshBuffer@pure3d@@UAEXEPAX@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::ShadowMeshBuffer::vfunc_20(unsigned char __p0, void* __p1) { int a = (int)__p0; hulk_intptr b = (hulk_intptr)__p1;
}


// 0x002df0e0 pure3d::ShadowMeshBuffer::vfunc_19 (3 B): matches/0x002df0e0.cpp
// sym: ?vfunc_19@ShadowMeshBuffer@pure3d@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void pure3d::ShadowMeshBuffer::vfunc_19(int a, int b) {}

namespace fn_fb97e5a1 {

// 0x002df0f0 pure3d::ShadowMeshBuffer::vfunc_21 (1 B): matches/0x002df0f0.cpp
// sym: ?FUN_002df0f0@fn_fb97e5a1@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002df0f0() {}


// 0x002df100 pure3d::ShadowMeshBuffer::vfunc_22 (1 B): matches/0x002df100.cpp
// sym: ?FUN_002df100@fn_fb97e5a1@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_002df100() {}

} // namespace fn_fb97e5a1

// 0x002df110 pure3d::ShadowMeshBuffer::vfunc_23 (3 B): matches/0x002df110.cpp
// sym: ?vfunc_23@ShadowMeshBuffer@pure3d@@UAEXI@Z
// Same code shape as 0x000fc4c0 (propagated; names are from that function)
void pure3d::ShadowMeshBuffer::vfunc_23(unsigned int __p0) { int a = (int)__p0;

    (void)a;
}

namespace fn_fb97e5a1 {

// 0x002df120 pure3d::ShadowMeshBuffer::vfunc_15 (6 B): matches/0x002df120.cpp
// sym: ?FUN_002df120@fn_fb97e5a1@@YAIXZ
// Same code shape as 0x000c8180 (propagated; names are from that function)
unsigned int FUN_002df120(void) {
    return 0x80;
}

} // namespace fn_fb97e5a1

// 0x002df130 pure3d::ShadowMeshBuffer::vfunc_3 (3 B): matches/0x002df130.cpp
// sym: ?vfunc_3@ShadowMeshBuffer@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::ShadowMeshBuffer::vfunc_3() {
    return true;
}

namespace fn_fb97e5a1 {

// 0x002df140 pure3d::ShadowMeshBuffer::vfunc_2 (36 B): matches/0x002df140.cpp
// sym: ?vfunc_5@ShadowMeshBuffer_2df140@fn_fb97e5a1@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
ShadowMeshBuffer_2df140* ShadowMeshBuffer_2df140::vfunc_5(signed char flags) {
    *(void***)this = Shadow_2df140_vftable;
    Destroy_002a4ff0();
    if (flags & 1) {
        SweepTrack_DeleteThis(this);
    }
    return this;
}

} // namespace fn_fb97e5a1

// 0x002df190 pure3d::ShadowMeshBuffer::vfunc_4 (44 B): matches/0x002df190.cpp [wrapped: conflict: pure3d::Shadow; pure3d::ShadowMeshBuffer]
// sym: ?vfunc_4@ShadowMeshBuffer@pure3d@fn_002df190@@UAEPAV123@XZ
namespace fn_002df190 {
/* size_t: tree_prelude.h */

namespace pure3d {
class Shadow {
  public:
    virtual void f0_00038290();
    Shadow(Shadow*) throw();
};
class ShadowMeshBuffer : public Shadow {
    char pad[0x58 - sizeof(Shadow)];

  public:
    virtual void f1_000382a0();
    virtual void* f2_002df140(char);
    virtual void f3_002df130();
    virtual ShadowMeshBuffer* vfunc_4();
    ShadowMeshBuffer(ShadowMeshBuffer* p) throw() : Shadow(p) {}
};
ShadowMeshBuffer* ShadowMeshBuffer::vfunc_4() {
    return new ShadowMeshBuffer(this);
}
} // namespace pure3d
} // namespace fn_002df190

// 0x002df1c0 pure3d::ShadowMeshBuffer::vfunc_8 (5 B): not yet verified

// 0x002df1d0 pure3d::ShadowMesh::vfunc_20 (36 B): matches/0x002df1d0.cpp [wrapped: conflict: ShadowMesh]
// sym: ?vfunc_20@ShadowMesh@fn_002df1d0@@QAEXEPAH@Z
namespace fn_002df1d0 {
class ShadowMesh {
    char pad[0x48];
    struct Holder {
        int* p;
    }* holder;

  public:
    void vfunc_20(unsigned char a, int* b);
};
void ShadowMesh::vfunc_20(unsigned char a, int* b) {
    int* x = holder->p;
    *((unsigned char*)x + 0x54) = a;
    *((int*)((char*)x + 0x64)) = b[0];
    *((int*)((char*)x + 0x68)) = b[1];
    *((int*)((char*)x + 0x6c)) = b[2];
}
} // namespace fn_002df1d0


// 0x002df200 pure3d::ShadowMesh::vfunc_23 (15 B): matches/0x002df200.cpp
// sym: ?vfunc_23@ShadowMesh@pure3d@@UAEXI@Z
void pure3d::ShadowMesh::vfunc_23(unsigned int x) {
    *(unsigned int*)(*(hulk_uintptr*)(*(void * *)&this->f_48) + 0x50) = x;
}


// 0x002df210 pure3d::ShadowMesh::vfunc_21 (10 B): matches/0x002df210.cpp
// sym: ?vfunc_21@ShadowMesh@pure3d@@UAEXXZ
void pure3d::ShadowMesh::vfunc_21() {
    (*(*(Helper_2df210 ** *)&this->f_48))->run_002b4710();
}


// 0x002df220 pure3d::ShadowMesh::vfunc_19 (10 B): matches/0x002df220.cpp
// sym: ?vfunc_19@ShadowMesh@pure3d@@UAEXHH@Z
// Same code shape as 0x002df210 (propagated; names are from that function)
void pure3d::ShadowMesh::vfunc_19(int a0, int a1) {
    (*(*(Helper_2df220 ** *)&this->f_48))->run_002b46c0(a0, a1);
}


// 0x002df230 pure3d::ShadowMesh::vfunc_22 (10 B): matches/0x002df230.cpp
// sym: ?vfunc_22@ShadowMesh@pure3d@@UAEXXZ
// Same code shape as 0x002df210 (propagated; names are from that function)
void pure3d::ShadowMesh::vfunc_22() {
    (*(*(Helper_2df230 ** *)&this->f_48))->run_002b4890();
}


// 0x002df240 pure3d::ShadowSkin::vfunc_24 (10 B): matches/0x002df240.cpp
// sym: ?vfunc_24@ShadowSkin@pure3d@@UAEXH@Z
void pure3d::ShadowSkin::vfunc_24(int a0) {
    Inner_2df240* p = (*(Inner_2df240 * *)&this->f_48);
    Inner_2df240* q = (Inner_2df240*)*(volatile void* const volatile*)p;
    q->Fnf_002b57d0(a0);
}

namespace fn_fb97e5a1 {

// 0x002df250 pure3d::ShadowSkin::vfunc_20 (36 B): matches/0x002df250.cpp
// sym: ?vfunc_20@ShadowSkin_2df250@fn_fb97e5a1@@QAEXEPAH@Z
// Same code shape as 0x002df1d0 (propagated; names are from that function)
void ShadowSkin_2df250::vfunc_20(unsigned char a, int* b) {
    int* x = holder->p;
    *((unsigned char*)x + 0x54) = a;
    *((int*)((char*)x + 0x64)) = b[0];
    *((int*)((char*)x + 0x68)) = b[1];
    *((int*)((char*)x + 0x6c)) = b[2];
}

} // namespace fn_fb97e5a1

// 0x002df280 pure3d::ShadowSkin::vfunc_23 (15 B): matches/0x002df280.cpp
// sym: ?vfunc_23@ShadowSkin@pure3d@@UAEXI@Z
// Same code shape as 0x002df200 (propagated; names are from that function)
void pure3d::ShadowSkin::vfunc_23(unsigned int x) {
    *(unsigned int*)(*(hulk_uintptr*)(*(void * *)&this->f_48) + 0x50) = x;
}


// 0x002df290 pure3d::ShadowSkin::vfunc_21 (10 B): matches/0x002df290.cpp
// sym: ?vfunc_21@ShadowSkin@pure3d@@UAEXXZ
// Same code shape as 0x002df210 (propagated; names are from that function)
void pure3d::ShadowSkin::vfunc_21() {
    (*(*(Helper_2df290 ** *)&this->f_48))->run_002b4710();
}


// 0x002df2a0 pure3d::ShadowSkin::vfunc_19 (10 B): matches/0x002df2a0.cpp
// sym: ?vfunc_19@ShadowSkin@pure3d@@UAEXHH@Z
// Same code shape as 0x002df210 (propagated; names are from that function)
void pure3d::ShadowSkin::vfunc_19(int a0, int a1) {
    (*(*(Helper_2df2a0 ** *)&this->f_48))->run_002b46c0(a0, a1);
}


// 0x002df2b0 pure3d::ShadowSkin::vfunc_22 (10 B): matches/0x002df2b0.cpp
// sym: ?vfunc_22@ShadowSkin@pure3d@@UAEXXZ
// Same code shape as 0x002df210 (propagated; names are from that function)
void pure3d::ShadowSkin::vfunc_22() {
    (*(*(Helper_2df2b0 ** *)&this->f_48))->run_002b4890();
}


// 0x002df2c0 pure3d::ShadowSkin::vfunc_10 (10 B): matches/0x002df2c0.cpp [wrapped: conflict: pure3d::ShadowSkin]
// sym: ?vfunc_10@ShadowSkin@pure3d@fn_002df2c0@@QAEXH@Z
namespace fn_002df2c0 {
namespace pure3d {
struct ShadowSkin {
    char pad[0x48];
    struct Link {
        struct Value {
            void FUN_002b57a0(int);
        }* value;
    }* link;
    void vfunc_10(int);
};
} // namespace pure3d
void pure3d::ShadowSkin::vfunc_10(int a0) {
    link->value->FUN_002b57a0(a0);
}
} // namespace fn_002df2c0


// 0x002df2d0 pure3d::ShadowSkin::vfunc_25 (9 B): matches/0x002df2d0.cpp
// sym: ?vfunc_25@ShadowSkin@pure3d@@UAEHXZ
int pure3d::ShadowSkin::vfunc_25() {
    return *(int*)(*(hulk_intptr*)(*(void * *)&this->f_48) + 0x7c);
}


// 0x002df2e0 pure3d::ShadowSkin::vfunc_26 (9 B): matches/0x002df2e0.cpp
// sym: ?vfunc_26@ShadowSkin@pure3d@@UAEIXZ
unsigned int pure3d::ShadowSkin::vfunc_26() {
    return *(unsigned int*)(*(hulk_uintptr*)(*(void * *)&this->f_48) + 0x70);
}

