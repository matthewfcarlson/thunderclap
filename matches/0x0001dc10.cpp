#include "gen/fight.h"
extern "C" void _ReadWriteBarrier();
extern void* g_vftable_1dc10[];
class Ref_1dc10 {
  public:
    virtual void F0();
    virtual void Release();
};
class Action_1dc10 {
  public:
    void* vptr;
};
class CAction_1dc10 : public Action_1dc10 {
  public:
    char pad[24];
    Ref_1dc10* m;
    ~CAction_1dc10();
};
CAction_1dc10::~CAction_1dc10() {
    vptr = g_vftable_1dc10;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    ((fight::Action *)(Action_1dc10 *)this)->FUN_002326a0();
}
