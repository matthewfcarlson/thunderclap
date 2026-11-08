#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b934[];
class Obj_274ba0 {
  public:
    virtual void A();
};
extern "C" int* FUN_002705f0();
// core::CompletionEventRequest's constructor: core::Request (the queue link), then its own: the semaphore to
// release when it runs (0x002735f0) and the drive (a reference)
struct CompletionEventRequest_274ba0 {
    const void* vf;
    void* next;
    hulk_uintptr* signal;
    Obj_274ba0* pC;
    CompletionEventRequest_274ba0* Init(hulk_uintptr*, Obj_274ba0*);
};
CompletionEventRequest_274ba0* CompletionEventRequest_274ba0::Init(hulk_uintptr* a, Obj_274ba0* b) {
    vf = DAT_0042b914;
    next = 0;
    FUN_002705f0();
    vf = DAT_0042b934;
    signal = a;
    pC = b;
    FUN_002705f0();
    pC->A();
    return this;
}
