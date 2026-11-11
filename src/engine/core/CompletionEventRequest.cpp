// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x00273500..0x00273670 (kind game, layer engine, confidence high), dominant class core::CompletionEventRequest
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/core.h"
#include "decls/data/records.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_f3d75464 {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f3d75464 {} using namespace fn_f3d75464;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_f3d75464 {
struct Obj_273560 {
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
    virtual void* f13();
};
extern "C" int __cdecl FUN_0026d8a0(hulk_uintptr*);
class pddiObject_273630 {
  public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
};
class pddiShader_273630 : public pddiObject_273630 {};
class pddiBaseShader_273630 : public pddiShader_273630 {
  public:
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual int UsesLayeredTexture();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc19();
    virtual void vfunc20();
};
class d3dShader_273630 : public pddiBaseShader_273630 {
  public:
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void vfunc21();
};
class Request_273650 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int vfunc_6();
};


// 0x00273500 FUN_00273500 (1 B): matches/0x00273500.cpp
// sym: _FUN_00273500
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00273500() {}


// 0x00273510 FUN_00273510 (1 B): matches/0x00273510.cpp
// sym: _FUN_00273510
// Same code shape as 0x00025410 (propagated; names are from that function)
extern "C" void FUN_00273510() {}


// 0x00273520 FUN_00273520 (3 B): matches/0x00273520.cpp
// sym: ?FUN_00273520@fn_f3d75464@@YAHXZ
int __cdecl FUN_00273520() {
    return 0;
}


// 0x00273530 FUN_00273530 (48 B): matches/0x00273530.cpp
// sym: _FUN_00273530
// data: tag = DAT_0042b904
// the "FileRequest" pool (0x00273560 allocates from it): every core::Request the drives queue comes from it, so
// its item is the largest request class, core::DriveFindFirstRequest (0x114 bytes on the 32-bit build)
extern "C" void FUN_00273530(int a, int b) {
    HULK_SIZE32(core::DriveFindFirstRequest, 0x114);
    FUN_0026d820(((char*)&DAT_0052a1c8));
    FUN_002702a0((void**)((char*)&DAT_0052a1e4), (int)sizeof(core::DriveFindFirstRequest), a, 0, b, (hulk_intptr)DAT_0042b904, 4);
}


// 0x00273560 FUN_00273560 (44 B): matches/0x00273560.cpp
// sym: _FUN_00273560
// data: gObjStorage = DAT_0052a1c8
// pops an item of the core memory pool (slot 13) under the lock; the item is a pointer on every target; the callers
// pass the item's size, which the pool's item size already is
extern "C" void* FUN_00273560(unsigned int size) {
    FUN_0026d850(((char*)&DAT_0052a1c8));
    void* r = (*(Obj_273560**)&DAT_0052a1e4)->f13();
    FUN_0026d840(((char*)&DAT_0052a1c8));
    return r;
}

} // namespace fn_f3d75464

// 0x002735d0 FUN_002735d0 (25 B): matches/0x002735d0.cpp [wrapped: helper definitions (2 out-of-line function bodies)]
// sym: ??1CompletionEventRequest@fn_002735d0@@UAE@XZ
namespace fn_002735d0 {
class CompletionEventRequest_2735d0 {
  public:
    virtual void F0();
    virtual void F1_002735f0();
    virtual ~CompletionEventRequest_2735d0() throw();
};
class CompletionEventRequest : public CompletionEventRequest_2735d0 {
  public:
    char pad[0x0c - sizeof(CompletionEventRequest_2735d0)];
    CompletionEventRequest_2735d0* mRequest;
    virtual ~CompletionEventRequest() throw();
};
CompletionEventRequest_2735d0::~CompletionEventRequest_2735d0() throw() {}
CompletionEventRequest::~CompletionEventRequest() throw() {
    mRequest->F1_002735f0();
}
} // namespace fn_002735d0


// 0x002735f0 core::CompletionEventRequest::vfunc_1 (18 B): matches/0x002735f0.cpp
// sym: ?vfunc_1@CompletionEventRequest@core@@UAEHXZ
// releases the semaphore the requester waits on (0x00274ba0 stores its address at +8)
int core::CompletionEventRequest::vfunc_1() {
    FUN_0026d8a0((hulk_uintptr*)this->f_08);
    return 1;
}


// 0x00273610 core::CompletionEventRequest::vfunc_2 (5 B): matches/0x00273610.cpp
// sym: ?vfunc_2@CompletionEventRequest@core@@UAE_NH@Z
// Same code shape as 0x00244f40 (propagated; names are from that function)
bool core::CompletionEventRequest::vfunc_2(int a) {
    return false;
}


// 0x00273620 core::CompletionEventRequest::vfunc_3 (4 B): matches/0x00273620.cpp
// sym: ?vfunc_3@CompletionEventRequest@core@@UAEHXZ
// Same code shape as 0x001cc840 (propagated; names are from that function)
// the request's drive (0x00274ba0 stores it at +0xc)
hulk_intptr core::CompletionEventRequest::vfunc_3() {
    return (hulk_intptr)(this->f_0c);
}


// 0x00273630 core::CompletionEventRequest::vfunc_4 (6 B): matches/0x00273630.cpp
// sym: ?vfunc_4@CompletionEventRequest@core@@UAEHXZ
// Same code shape as 0x0032d960 (propagated; names are from that function)
int core::CompletionEventRequest::vfunc_4() {
    return 1;
}

namespace fn_f3d75464 {

// 0x00273640 core::CompletionEventRequest::vfunc_5 (3 B): matches/0x00273640.cpp
// sym: ?GetZero@fn_f3d75464@@YAIXZ
// Same code shape as 0x0026ef40 (propagated; names are from that function)
unsigned int GetZero() {
    return 0;
}

} // namespace fn_f3d75464

// 0x00273650 core::CompletionEventRequest::vfunc_6 (6 B): matches/0x00273650.cpp
// sym: ?vfunc_6@CompletionEventRequest@core@@UAEHXZ
int core::CompletionEventRequest::vfunc_6() {
    return 0x16;
}

