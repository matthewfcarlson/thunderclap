// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002746e0..0x00274790 (kind game, layer engine, confidence high), dominant class core::DriveDestroyDirectoryRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f61dc6d2 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f61dc6d2 {} using namespace fn_f61dc6d2;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f61dc6d2 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_2746e0 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
class HalStream_274770 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
};

} // namespace fn_f61dc6d2

// 0x002746e0 FUN_002746e0 (53 B): matches/0x002746e0.cpp
// sym: ?FUN_002746e0@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_002746e0() {
    Obj_2746e0* p = (*(Obj_2746e0 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)(*(Obj_2746e0 * *)&this->f_08) + 0x14));
    p = (*(Obj_2746e0 * *)&this->f_08);
    p->sub.B();
    p = (*(Obj_2746e0 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x00274720 core::DriveDestroyDirectoryRequest::vfunc_1 (68 B): matches/0x00274720.cpp [wrapped: conflict: core::DriveDestroyDirectoryRequest]
// sym: ?vfunc_1@DriveDestroyDirectoryRequest@core@fn_00274720@@UAEIXZ
namespace fn_00274720 {
struct Path_274720;
struct Drive {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual unsigned slot16(Path_274720*);
    unsigned FUN_00272880();
};
struct Lock_274720 {
    virtual void acquire();
    virtual void release();
};
struct State_274720 {
    unsigned unknown0;
    Lock_274720 lock;
    unsigned unknown8;
    Drive* drive;
    char pad10[8];
    unsigned result;
};
struct Path_274720 {
    char data[4];
};
namespace core {
struct DriveDestroyDirectoryRequest {
    virtual void vfunc_0();
    virtual unsigned vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    unsigned unknown4;
    State_274720* state;
    Path_274720 path;
};
unsigned DriveDestroyDirectoryRequest::vfunc_1() {
    Drive* drive = state->drive;
    unsigned result = drive->slot16(&path);
    unsigned status = drive->FUN_00272880();
    state->lock.acquire();
    state->result = status;
    state->lock.release();
    return result;
}
} // namespace core
} // namespace fn_00274720


// 0x00274770 core::DriveDestroyDirectoryRequest::vfunc_5 (4 B): matches/0x00274770.cpp
// sym: ?vfunc_5@DriveDestroyDirectoryRequest@core@@UAEPAXXZ
// Same code shape as 0x0025c0b0 (propagated; names are from that function)
 // namespace audio
void* core::DriveDestroyDirectoryRequest::vfunc_5() {
    return (void*)((core::DriveDestroyDirectoryRequest*)((char*)this + 0xc));
}


// 0x00274780 core::DriveDestroyDirectoryRequest::vfunc_6 (6 B): matches/0x00274780.cpp
// sym: ?vfunc_6@DriveDestroyDirectoryRequest@core@@UAEHXZ
int core::DriveDestroyDirectoryRequest::vfunc_6() {
    return (int)(0xf);
}

