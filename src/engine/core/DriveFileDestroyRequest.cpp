// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002749a0..0x00274a50 (kind game, layer engine, confidence high), dominant class core::DriveFileDestroyRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fc3b1131 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fc3b1131 {} using namespace fn_fc3b1131;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fc3b1131 {
class V {
  public:
    virtual void A();
    virtual void B();
};
class Obj_2749a0 {
  public:
    char pad[4];
    V sub;
    char rest[0x10];
    int count;
};
struct Drive_2749e0 {
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
    virtual void slot16();
    virtual unsigned int slot17(void*);
    unsigned int FUN_00272880();
};
struct Lock_2749e0 {
    virtual void acquire();
    virtual void release();
};
struct State_2749e0 {
    unsigned int field0;
    Lock_2749e0 lock;
    unsigned int field8;
    Drive_2749e0* drive;
    char padding[8];
    unsigned int result;
};
class HalStream_274a30 {
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

} // namespace fn_fc3b1131

// 0x002749a0 FUN_002749a0 (53 B): matches/0x002749a0.cpp
// sym: ?FUN_002749a0@DriveRequest@core@@QAEXXZ
void core::DriveRequest::FUN_002749a0() {
    Obj_2749a0* p = (*(Obj_2749a0 * *)&this->f_08);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b9bc);
    p->sub.A();
    --(*(int*)((char*)(*(Obj_2749a0 * *)&this->f_08) + 0x14));
    p = (*(Obj_2749a0 * *)&this->f_08);
    p->sub.B();
    p = (*(Obj_2749a0 * *)&this->f_08);
    ((V*)p)->B();
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b914);
}


// 0x002749e0 core::DriveFileDestroyRequest::vfunc_1 (68 B): matches/0x002749e0.cpp
// sym: ?vfunc_1@DriveFileDestroyRequest@core@@UAEHXZ
 // namespace core
int core::DriveFileDestroyRequest::vfunc_1() {
    Drive_2749e0* drive = (*(State_2749e0 * *)&this->f_08)->drive;
    unsigned int result = drive->slot17(&(*(unsigned int *)&this->f_0c));
    unsigned int status = drive->FUN_00272880();
    (*(State_2749e0 * *)&this->f_08)->lock.acquire();
    (*(State_2749e0 * *)&this->f_08)->result = status;
    (*(State_2749e0 * *)&this->f_08)->lock.release();
    return (int)(result);
}


// 0x00274a30 core::DriveFileDestroyRequest::vfunc_5 (4 B): matches/0x00274a30.cpp
// sym: ?vfunc_5@DriveFileDestroyRequest@core@@UAEPAXXZ
// Same code shape as 0x0025c0b0 (propagated; names are from that function)
 // namespace audio
void* core::DriveFileDestroyRequest::vfunc_5() {
    return (void*)((core::DriveFileDestroyRequest*)((char*)&this->f_0c));
}


// 0x00274a40 core::DriveFileDestroyRequest::vfunc_6 (6 B): matches/0x00274a40.cpp
// sym: ?vfunc_6@DriveFileDestroyRequest@core@@UAEHXZ
int core::DriveFileDestroyRequest::vfunc_6() {
    return (int)(0x13);
}

