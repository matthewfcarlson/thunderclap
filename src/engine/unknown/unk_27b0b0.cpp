// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0027b0b0..0x0027b510 (kind game, layer engine, confidence low)
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d.h"
#include "decls/data/engine/unknown.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fdc3a51a {
#define TREE_TU_END }
#define TREE_LOCAL_CEffectStopTrack
namespace fn_fdc3a51a {} using namespace fn_fdc3a51a;
#include "engine/unknown.h"

// ---- declarations shared by the functions below
namespace fn_fdc3a51a {
class Entity {
  public:
    void* vptr;
    int a;
    int b;
    int c;
};
class Entity_27b0b0 {
  public:
    void* vptr;
    int a;
    int b;
    int c;
    Entity_27b0b0(void*);
};
extern void* Entity_vftable;
struct X {
    unsigned int a, b;
    X(hulk_intptr n);
};
extern "C" unsigned __int64 __cdecl make(int, int, hulk_intptr);
extern void __cdecl release(void*);
struct Entry { unsigned int first; unsigned int second; };
struct Table { char pad0[0x10]; unsigned int count; char pad1[0x10]; Entry *entries; unsigned int FUN_0027b200(unsigned int first, unsigned int second); };
struct Pose_nv_27b240 {
    int DoThing(pure3d::Pose*, int);
};
extern "C" pure3d::Pose* __cdecl FUN_0008d690(int);
struct Matrix { unsigned int words[16];   };
struct Local_27b270 { unsigned int words[4];  };
struct Object { char pad[16]; unsigned int count; Local_27b270* locals; Matrix* localMatrices; Matrix* worldMatrices; Matrix* inverseMatrices; unsigned int unknown24; unsigned short* parents; void update(); };
extern "C" void* __cdecl FUN_0008d6d0(unsigned int);
extern "C" void* __cdecl Allocate(unsigned int);


// 0x0027b0b0 FUN_0027b0b0 (42 B): matches/0x0027b0b0.cpp
// sym: ??0Entity_27b0b0@fn_fdc3a51a@@QAE@PAX@Z
Entity_27b0b0::Entity_27b0b0(void* param) {
    a = 0;
    vptr = &Entity_vftable;
    b = 0;
    c = 0;
    if (param) {
        b = ((int*)param)[2];
        c = ((int*)param)[3];
    }
}


// 0x0027b0e0 FUN_0027b0e0 (53 B): matches/0x0027b0e0.cpp
// sym: ??0X@fn_fdc3a51a@@QAE@H@Z
X::X(hulk_intptr n) {
    unsigned __int64 v = 0;
    a = (unsigned int)v;
    b = (unsigned int)(v >> 32);
    v = n ? make(n, 0, 0) : 0;
    a = (unsigned int)v;
    b = (unsigned int)(v >> 32);
}


// 0x0027b1d0 FUN_0027b1d0 (37 B): matches/0x0027b1d0.cpp
// sym: _FUN_0027b1d0
// data: count = DAT_0052c288
extern "C" void FUN_0027b1d0() {
    if (--(*(int*)&DAT_0052c288) == 0) {
        if (DAT_004ce410)
            release(DAT_004ce410);
        DAT_004ce410 = 0;
    }
}


// 0x0027b200 FUN_0027b200 (55 B): equivalent/0x0027b200.cpp
// sym: ?FUN_0027b200@Table@fn_fdc3a51a@@QAEIII@Z
// STATUS: equivalent (tools/equiv.py level 3: 153 inputs, branch coverage 8/8)
// FUN_0027b200 @ 0x0027b200
unsigned int Table::FUN_0027b200(unsigned int first, unsigned int second) { for (unsigned int i = 0; i < count; ++i) { if (entries[i].first == first && entries[i].second == second) return i; } return 0xffff; }


// 0x0027b240 FUN_0027b240 (33 B): matches/0x0027b240.cpp
// sym: ?target@fn_fdc3a51a@@YIHPAVPose@pure3d@@PAX@Z
int __fastcall target(pure3d::Pose* self, void*) {
    pure3d::Pose* p = FUN_0008d690((int)sizeof(pure3d::Pose));
    if (p)
        return ((Pose_nv_27b240*)(((pure3d::Pose*)(p))))->DoThing(self, 0);
    return 0;
}


// 0x0027b270 FUN_0027b270 (204 B): equivalent/0x0027b270.cpp
// sym: ?update@Object@fn_fdc3a51a@@QAEXXZ
// STATUS: equivalent (tools/equiv.py level 3: 147 inputs, branch coverage 4/4)
// FUN_0027b270 @ 0x0027b270
void Object::update() {
 ((owners::Quat_22b370 *)locals)->FUN_0022b370((const float *)(Matrix *)localMatrices);
 Matrix* src=localMatrices;
 Matrix* dst=worldMatrices;
 for(unsigned int j=0;j<16;++j) dst->words[j]=src->words[j];
 Matrix* inv=inverseMatrices;
 src=localMatrices;
 for(unsigned int k=0;k<16;++k) inv->words[k]=src->words[k];
 ((owners::Matrix_22c120 *)inv)->FUN_0022c120();
 for(unsigned int i=1;i<count;++i) {
 unsigned short parent=parents[i];
 ((owners::Quat_22b370 *)&(locals[i]))->FUN_0022b370((const float *)(Matrix *)(localMatrices+i));
 ((owners::Matrix_22ca90 *)&(worldMatrices[i]))->FUN_0022ca90((const owners::Matrix_22ca90 *)(Matrix *)(localMatrices+i), (const owners::Matrix_22ca90 *)(Matrix *)(worldMatrices+parent));
 Matrix* out=inverseMatrices+i;
 src=worldMatrices+i;
 for(unsigned int n=0;n<16;++n) out->words[n]=src->words[n];
 ((owners::Matrix_22c120 *)out)->FUN_0022c120();
 }
}


// 0x0027b340 FUN_0027b340 (46 B): equivalent/0x0027b340.cpp
// sym: _FUN_0027b340
// STATUS: equivalent (tools/equiv.py level 3: 2991 inputs, branch coverage 4/4)
// FUN_0027b340 @ 0x0027b340
// equiv-conv: FUN_0027b340 eax
extern "C" char* FUN_0027b340(const char* source) {
    const char* end = source;
    do { ++end; } while (end[-1]);
    unsigned int length = (unsigned int)(end - source);
    char* result = (char*)FUN_0008d6d0(length);
    char* destination = result;
    do { *destination++ = *source; } while (*source++);
    return result;
}

} // namespace fn_fdc3a51a

// 0x0027b3b0 FUN_0027b3b0 (75 B): matches/0x0027b3b0.cpp
// sym: ?FUN_0027b3b0@Buffer_27b3b0@owners@@QAE_NH@Z
bool owners::Buffer_27b3b0::FUN_0027b3b0(int count) {
    int* p;
    if (count != 0) {
        p = (int*)Allocate(count * 24);
        mStart = p;
        if (p != 0) {
            mCurrent = p;
            mEnd = (int*)((char*)p + count * 24);
            return true;
        }
    } else
        mStart = 0;
    mCurrent = 0;
    mEnd = 0;
    return false;
}

