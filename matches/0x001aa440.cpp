#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" void* __cdecl Alloc(hulk_uintptr);
extern "C" int NodeVtable;
class Factory_1aa440 {
  public:
    virtual void V0();
    virtual void V1();
    virtual void V2();
    virtual void V3();
    virtual void V4();
    virtual void* V5();
};
class Node_1aa440 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::NodeIsNotRunningCondition>::vfunc_5() {
    Node_1aa440* p = (Node_1aa440*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = (hulk_uintptr)&NodeVtable;
        *((unsigned char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
