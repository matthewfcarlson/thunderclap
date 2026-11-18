// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002efb70..0x002efca0 (kind game, layer engine, confidence high), dominant class physics::ManualSimState
#include "tree_prelude.h"
#include "decls/data/engine/physics.h"
#include "gen/physics.h"
#define TREE_TU_BEGIN namespace fn_f97c6302 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f97c6302 {} using namespace fn_f97c6302;
#include "engine/physics.h"

// ---- declarations shared by the functions below
namespace fn_f97c6302 {
class SimState_2efb70 {
    char a[4];
};
class DataHandler {
  public:
    class ObjectCreator {
        char b[4];
    };
};
class ManualSimState_2efb70 : public SimState_2efb70, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};
class SimState_2efb80 {
    char a[4];
};
class ManualSimState_2efb80 : public SimState_2efb80, public DataHandler::ObjectCreator {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual const char* vfunc_3(void*);
};


// 0x002efb70 physics::ManualSimState::vfunc_4 (8 B): matches/0x002efb70.cpp
// sym: ?vfunc_3@ManualSimState_2efb70@fn_f97c6302@@UAEPBDPAX@Z
// Same code shape as 0x00078c40 (propagated; names are from that function)
// data: gWaypoint = DAT_004d2978
const char* ManualSimState_2efb70::vfunc_3(void*) {
    return DAT_004d2978;
}


// 0x002efb80 physics::ManualSimState::vfunc_5 (8 B): matches/0x002efb80.cpp
// sym: ?vfunc_3@ManualSimState_2efb80@fn_f97c6302@@UAEPBDPAX@Z
// Same code shape as 0x00078c40 (propagated; names are from that function)
// data: gWaypoint = DAT_004d29a8
const char* ManualSimState_2efb80::vfunc_3(void*) {
    return DAT_004d29a8;
}

} // namespace fn_f97c6302

// 0x002efb90 physics::ManualSimState::vfunc_6 (3 B): matches/0x002efb90.cpp
// sym: ?vfunc_6@ManualSimState@physics@@UAEXHH@Z
// Same code shape as 0x00306fc0 (propagated; names are from that function)
void physics::ManualSimState::vfunc_6(int a, int b) {}


// 0x002efba0 physics::ManualSimState::vfunc_2 (30 B): matches/0x002efba0.cpp
// sym: ?vfunc_2@ManualSimState_2efba0@fn_002efba0@@QAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
// (x64t21, D114) an explicit function: `physics::ManualSimState::~ManualSimState() {}` stood for it, which natively
// defines no function for the vftable slot (with the `??_G` signature, as other views call the slot). The destructor's
// body 0x002ef2c0, then (flags & 1) operator delete.
namespace fn_002efba0 {
struct ManualSimState_2efba0 {
    void FUN_002ef2c0();   // the destructor's body
    void* vfunc_2(unsigned int flags);
};
void* ManualSimState_2efba0::vfunc_2(unsigned int flags) {
    FUN_002ef2c0();
    if (flags & 1)
        operator delete(this);
    return this;
}
} // namespace fn_002efba0
// (x64t21) the destructor itself, which other objects' code references:
physics::ManualSimState::~ManualSimState() {}

