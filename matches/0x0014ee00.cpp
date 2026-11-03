#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class Helper_14ee00 {
  public:
    void* second();
};

bool hulkfight::motion::InterruptAccumulatorSetAction::vfunc_3(hulk_intptr __p0, hulk_intptr __p1) {
    Helper_14ee00* h = (*(Helper_14ee00 * *)&this->f_20);
    void* a = ((void *)((owners::Object_592a0 *)h)->FUN_000592a0());
    void* b = ((Helper_14ee00*)a)->second();
    *(int*)((char*)b + 0x320) = *(int*)((char*)(*(void * *)&this->f_1c) + 0x10);
    return false;
}
