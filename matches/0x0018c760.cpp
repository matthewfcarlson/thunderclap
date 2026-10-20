#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_004192fc[];
class Sub_18c760 {
  public:
    void initSub();
};
class PropSetStateByNameTrack_18c760 {
  public:
    void baseInit();
    char pad[0x18];
    Sub_18c760 sub;
};
extern void* __cdecl operator_new(unsigned int);

template <> void* fight::TrackFactoryTemplate<hulkfight::motion::PropSetStateByNameTrack>::vfunc_5() {
    PropSetStateByNameTrack_18c760* p = (PropSetStateByNameTrack_18c760*)operator_new(0x20);
    if (p) {
        p->baseInit();
        *(hulk_ulongptr*)p = ((hulk_intptr)DAT_004192fc);
        *(unsigned long*)((char*)p + 0xc) = 0;
        *(unsigned long*)((char*)p + 0x10) = 0xffffffff;
        p->sub.initSub();
        *(unsigned long*)((char*)p + 8) = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
