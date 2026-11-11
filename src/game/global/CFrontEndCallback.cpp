// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000be1c0..0x000be230 (kind game, layer game, confidence high), dominant class CFrontEndCallback
#include "tree_prelude.h"
#define TREE_TU_BEGIN namespace fn_ff7380c5 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_ff7380c5 {} using namespace fn_ff7380c5;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_ff7380c5 {
class CFrontEndCallback {
  public:
    void Run();
};
typedef void (CFrontEndCallback::*CbFn)();
class CallbackHolder {
  public:
    virtual void vfunc_0();
    CFrontEndCallback* mObject;
    CbFn mFn;
};


// 0x000be1c0 CallbackHolder<CFrontEndCallback>::vfunc_0 (8 B): matches/0x000be1c0.cpp
// sym: ?vfunc_0@CallbackHolder@fn_ff7380c5@@UAEXXZ
void CallbackHolder::vfunc_0() {
    CbFn fn = mFn;
    (mObject->*fn)();
}

} // namespace fn_ff7380c5

// 0x000be1f0 CallbackHolderFloat<CFrontEndCallback>::vfunc_0 (8 B): matches/0x000be1f0.cpp [wrapped: same definition as 0x000be1c0 in this TU]
// sym: ?vfunc_0@CallbackHolder@fn_000be1f0@@UAEXXZ
namespace fn_000be1f0 {
// Same code shape as 0x000be1c0 (propagated; names are from that function)
class CFrontEndCallback {
  public:
    void Run();
};
typedef void (CFrontEndCallback::*CbFn)();
class CallbackHolder {
  public:
    virtual void vfunc_0();
    CFrontEndCallback* mObject;
    CbFn mFn;
};
void CallbackHolder::vfunc_0() {
    CbFn fn = mFn;
    (mObject->*fn)();
}
} // namespace fn_000be1f0


// 0x000be220 CallbackHolderInt<CFrontEndCallback>::vfunc_0 (8 B): matches/0x000be220.cpp [wrapped: same definition as 0x000be1c0 in this TU]
// sym: ?vfunc_0@CallbackHolder@fn_000be220@@UAEXXZ
namespace fn_000be220 {
// Same code shape as 0x000be1c0 (propagated; names are from that function)
class CFrontEndCallback {
  public:
    void Run();
};
typedef void (CFrontEndCallback::*CbFn)();
class CallbackHolder {
  public:
    virtual void vfunc_0();
    CFrontEndCallback* mObject;
    CbFn mFn;
};
void CallbackHolder::vfunc_0() {
    CbFn fn = mFn;
    (mObject->*fn)();
}
} // namespace fn_000be220

