// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001d0360..0x001d0480 (kind game, layer game, confidence medium), dominant class CScenarioParams
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#define TREE_TU_BEGIN namespace fn_f2d3e6ac {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f2d3e6ac {} using namespace fn_f2d3e6ac;
namespace fn_f2d3e6ac {
void __cdecl SweepTrack_DeleteThis_0008d330(void* p);   // (unb4) the thunk to free (or free) this TU's SweepTrack_DeleteThis reaches
}
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f2d3e6ac {
extern "C" char DAT_00422370[];
} // namespace fn_f2d3e6ac
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
#endif
namespace fn_f2d3e6ac {
struct DataInit {
    void Init_001cb120();
};
struct CScenarioParams {
    hulk_uintptr vf;
    unsigned int pad4;
    unsigned int id;
    unsigned int padc;
    DataInit data;
    void InitBase_00236a60();
    CScenarioParams* target(const unsigned int* src);
};
struct Obj_1d03c0 {
    char pad[0x10];
};
typedef unsigned int u32_1d0430;
extern void* hulk_at_00422370[];
class Params_1d0450 {
  public:
    void Destroy_00236a50(); // FUN_00236d60, __thiscall, this in ecx
};
class CScenarioParams_1d0450 : public Params_1d0450 {
  public:
    CScenarioParams_1d0450* vfunc_5(signed char flags);
};


// 0x001d0360 FUN_001d0360 (68 B): matches/0x001d0360.cpp
// sym: ?target@CScenarioParams@fn_f2d3e6ac@@QAEPAU12@PBI@Z
// data: g_counter_1d0360 = DAT_004e23c8
CScenarioParams* CScenarioParams::target(const unsigned int* src) {
    InitBase_00236a60();
    vf = ((hulk_intptr)DAT_00422370);
    data.Init_001cb120();
    unsigned int n = *src;
    memcpy(&data, src, n);
    ++(*(unsigned int*)&DAT_004e23c8);
    id = (*(unsigned int*)&DAT_004e23c8);
    return this;
}


// 0x001d03c0 FUN_001d03c0 (4 B): matches/0x001d03c0.cpp
// sym: ?FUN_001d03c0@fn_f2d3e6ac@@YIPAUObj_1d03c0@1@PAU21@@Z
Obj_1d03c0* __fastcall FUN_001d03c0(Obj_1d03c0* self) {
    return (Obj_1d03c0*)((char*)self + 0x10);
}

} // namespace fn_f2d3e6ac

// 0x001d03d0 CScenarioParams::vfunc_3 (91 B): matches/0x001d03d0.cpp [wrapped: conflict: CScenarioParams]
// sym: ?v3@CScenarioParams@fn_001d03d0@@UAEPAV12@XZ
inline void* __cdecl operator new(size_t, void* p) {
    return p;
}
void* __cdecl operator new(size_t);
namespace fn_001d03d0 {
// data: gCount_1d03d0 = DAT_004e23c8

/* size_t: tree_prelude.h */



#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" void* __cdecl memcpy(void*, const void*, size_t);
#endif

class Params_1d03d0 {
  public:
    Params_1d03d0();
    virtual void v0_00018b30();
    virtual void v1_00018b40();
    virtual void v2();
    virtual Params_1d03d0* v3();
    int a;
    int count;
    int b;
};
class Payload_1d03d0 {
  public:
    Payload_1d03d0();
    int length;
    char data[0xdc];
};
class CScenarioParams : public Params_1d03d0 {
  public:
    Payload_1d03d0 payload;
    CScenarioParams() {}
    virtual void v2();
    virtual CScenarioParams* v3();
};
CScenarioParams* CScenarioParams::v3() {
    CScenarioParams* q = (CScenarioParams*)operator new(sizeof(CScenarioParams));
    if (q) {
        Payload_1d03d0* src = &payload;
        q = new (q) CScenarioParams;
        memcpy(&q->payload, src, src->length);
        int n = ++(*(int*)&DAT_004e23c8);
        q->count = n;
        return q;
    }
    return 0;
}
} // namespace fn_001d03d0

namespace fn_f2d3e6ac {

// 0x001d0430 FUN_001d0430 (10 B): matches/0x001d0430.cpp
// sym: _FUN_001d0430
// data: gValue_1d0430 = DAT_004e23c4
extern "C" void FUN_001d0430(u32_1d0430 value) {
    (*(u32_1d0430*)&DAT_004e23c4) = value;
}


// 0x001d0440 FUN_001d0440 (6 B): matches/0x001d0440.cpp
// sym: _FUN_001d0440
// Same code shape as 0x00085cd0 (propagated; names are from that function)
extern "C" int FUN_001d0440(void) {
    return *(int*)&DAT_004e23c4;
}


// 0x001d0450 CScenarioParams::vfunc_2 (36 B): matches/0x001d0450.cpp
// sym: ?vfunc_5@CScenarioParams_1d0450@fn_f2d3e6ac@@QAEPAV12@C@Z
// Same code shape as 0x0006b7e0 (propagated; names are from that function)
// Target: CSweepTrack::vfunc_5 (slot 5)
 // thunk_FUN_00267090
CScenarioParams_1d0450* CScenarioParams_1d0450::vfunc_5(signed char flags) {
    *(void***)this = hulk_at_00422370;
    Destroy_00236a50();
    if (flags & 1) {
        SweepTrack_DeleteThis_0008d330(this);
    }
    return this;
}

} // namespace fn_f2d3e6ac
