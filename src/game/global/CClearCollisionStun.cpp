// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0006afc0..0x0006b070 (kind game, layer game, confidence high), dominant class CClearCollisionStun
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"
#include "gen/global.h"
#define TREE_TU_BEGIN namespace fn_fa1ead05 {
#define TREE_TU_END }
namespace fn_fa1ead05 {} using namespace fn_fa1ead05;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fa1ead05 {
extern "C" int* g_table_6afe0;
struct Param_6b040 {
  public:
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc4();
};
struct CTrack_6b040 {
  public:
    virtual void tfunc3();
    virtual void tfunc8();
    virtual void tfunc9();
};
class Obj_6b050 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual Obj_6b050* get();
};


// 0x0006afc0 FUN_0006afc0 (19 B): matches/0x0006afc0.cpp
// sym: ?FUN_0006afc0@fn_fa1ead05@@YAXXZ
// Same code shape as 0x000482e0 (propagated; names are from that function)
void FUN_0006afc0() {
    FUN_00234810(((char*)&DAT_004dd010), ((char*)&DAT_004dd014));
}

} // namespace fn_fa1ead05

// 0x0006afe0 CClearCollisionStun::vfunc_0 (16 B): matches/0x0006afe0.cpp
// sym: ?vfunc_0@CClearCollisionStun@@UAEHH@Z
hulk_intptr CClearCollisionStun::vfunc_0(int x) {
    return g_table_6afe0[x];
}


// 0x0006aff0 FUN_0006aff0 (39 B): matches/0x0006aff0.cpp [wrapped: conflict: CClearCollisionStun]
// sym: ??0CClearCollisionStun@fn_0006aff0@@QAE@XZ
namespace fn_0006aff0 {
class CTrack_6aff0 {
  public:
    CTrack_6aff0();
    virtual void f();
    char pad[8];
};
class CClearCollisionStun : public CTrack_6aff0 {
  public:
    CClearCollisionStun();
    virtual void f();
    int a;
    float b;
};
CClearCollisionStun::CClearCollisionStun() {
    a = 0;
    b = -1.0f;
    *(int*)((char*)this + 8) = 1;
}
} // namespace fn_0006aff0


// 0x0006b020 CClearCollisionStun::vfunc_13 (13 B): matches/0x0006b020.cpp
// sym: ?vfunc_13@CClearCollisionStun@@UAEXPAX@Z
// Same code shape as 0x0005e010 (propagated; names are from that function)
void CClearCollisionStun::vfunc_13(void* __p0) { int * p = (int *)__p0;

    *p = -1;
}


// 0x0006b030 CClearCollisionStun::vfunc_6 (4 B): matches/0x0006b030.cpp
// sym: ?vfunc_6@CClearCollisionStun@@UAEMXZ
// Same code shape as 0x0010d280 (propagated; names are from that function)
 // namespace hulkfight
hulk_freg CClearCollisionStun::vfunc_6() {
    return this->f_0c;
}


// 0x0006b040 CClearCollisionStun::vfunc_7 (7 B): matches/0x0006b040.cpp
// sym: ?vfunc_7@CClearCollisionStun@@UAEMXZ
// Same code shape as 0x0012b630 (propagated; names are from that function)
hulk_freg CClearCollisionStun::vfunc_7() {
    return (hulk_freg)this->f_10 - this->f_0c;
}


// 0x0006b050 CClearCollisionStun::vfunc_12 (21 B): matches/0x0006b050.cpp
// sym: ?vfunc_12@CClearCollisionStun@@UAEHH@Z
hulk_intptr CClearCollisionStun::vfunc_12(hulk_intptr __p0) { Obj_6b050 * p = (Obj_6b050 *)__p0;

    Obj_6b050* q = p->get();
    *(int*)((char*)q + 0x68) = 0;
    return 0;
}

