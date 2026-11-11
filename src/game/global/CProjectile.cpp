// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b6800..0x001b69c0 (kind game, layer game, confidence high), dominant class CProjectile
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f270ee22 {
#define TREE_TU_END }
namespace fn_f270ee22 {} using namespace fn_f270ee22;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f270ee22 {
extern void* hulk_at_003f6098;
class ZeroBlock {
  public:
    int words[32];
    ZeroBlock();
};
extern int hulk_at_004e21f0;
struct A_1b68d0 {
    char pad[12];
    int value;
};
class Obj {
  public:
    Obj() throw();
    char data[0x80];
};
} // namespace fn_f270ee22
void* __cdecl operator new(size_t) HULK_NEW_THROW;
namespace fn_f270ee22 {
extern Obj* volatile hulk_at_004e21f4;

} // namespace fn_f270ee22

// 0x001b6800 FUN_001b6800 (30 B): matches/0x001b6800.cpp [wrapped: conflict: CProjectile]
// sym: ??0CProjectile@fn_001b6800@@QAE@XZ
namespace fn_001b6800 {
class CProjectile {
  public:
    hulk_intptr a;
    int b;
    int c;
    int d;
    unsigned char e;
    int f;
    CProjectile();
};
extern int hulk_at_0041dad8;
CProjectile::CProjectile() {
    b = 0;
    this->a = (hulk_intptr)&hulk_at_0041dad8;
    c = -1;
    d = 0;
    e = 0;
    f = 0;
}
} // namespace fn_001b6800

namespace fn_f270ee22 {

// 0x001b6820 FUN_001b6820 (7 B): matches/0x001b6820.cpp
// sym: ?FUN_001b6820@fn_f270ee22@@YIXPAX@Z
void __fastcall FUN_001b6820(void* self) {
    *(void**)self = &hulk_at_003f6098;
}

} // namespace fn_f270ee22

// 0x001b6830 CProjectile::vfunc_6 (8 B): matches/0x001b6830.cpp
// sym: ?vfunc_6@CProjectile@@UAEHHHHHH@Z
int CProjectile::vfunc_6(int , int , int , int , int ) {
    return 1;
}

namespace fn_f270ee22 {

// 0x001b6840 CProjectile::vfunc_5 (3 B): matches/0x001b6840.cpp
// sym: ?GetZero@fn_f270ee22@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}


// 0x001b6850 FUN_001b6850 (102 B): matches/0x001b6850.cpp
// sym: ??0ZeroBlock@fn_f270ee22@@QAE@XZ
ZeroBlock::ZeroBlock() {
    int* p = words;
    for (int i = 0; i < 32; ++i)
        p[i] = 0;
}


// 0x001b68d0 FUN_001b68d0 (16 B): matches/0x001b68d0.cpp
// sym: ?FUN_001b68d0@fn_f270ee22@@YGXPAUA_1b68d0@1@@Z
void __stdcall FUN_001b68d0(A_1b68d0* p) {
    hulk_at_004e21f0 = p->value;
}

} // namespace fn_f270ee22

// 0x001b68e0 FUN_001b68e0 (24 B): matches/0x001b68e0.cpp
// sym: ?FUN_001b68e0@C_1b68e0@owners@@QAEHH@Z
hulk_intptr owners::C_1b68e0::FUN_001b68e0(int index) {
    if (index >= 0 && index < 0x20)
        return ((int*)this)[index];
    return 0;
}


// 0x001b6960 CProjectile::vfunc_2 (35 B): matches/0x001b6960.cpp [wrapped: conflict: CProjectile]
// sym: ?vfunc_2@CProjectile@fn_001b6960@@UAEPAV12@E@Z
namespace fn_001b6960 {
typedef unsigned char byte_1b6960;
extern int gVtable_1b6960;
class Alloc_1b6960 {
  public:
    void Fnf_0008ff00(void*, unsigned int);
};
extern Alloc_1b6960 hulk_at_004e2210;
class CProjectile {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CProjectile* vfunc_2(byte_1b6960);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
};
CProjectile* CProjectile::vfunc_2(byte_1b6960 flags) {
    *(hulk_intptr*)this = (hulk_intptr)&gVtable_1b6960;
    if ((flags & 1) != 0)
        hulk_at_004e2210.Fnf_0008ff00(this, 0x18);
    return this;
}
} // namespace fn_001b6960

namespace fn_f270ee22 {

// 0x001b6990 FUN_001b6990 (47 B): matches/0x001b6990.cpp
// sym: _FUN_001b6990
extern "C" Obj* __cdecl FUN_001b6990() {
    Obj* p = hulk_at_004e21f4;
    if (!p)
        hulk_at_004e21f4 = p = new Obj;
    return p;
}

} // namespace fn_f270ee22
