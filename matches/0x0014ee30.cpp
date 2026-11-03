#include "compat/ptr.h"
#include "gen/hulkfight.h"
#include "gen/owners.h"

class Helper_14ee30 {
  public:
    void* f59a30();
};

bool hulkfight::motion::InterruptPriorityAction::vfunc_3(hulk_intptr , hulk_intptr ) {
    Helper_14ee30* h = (*(Helper_14ee30 * *)&this->f_20);
    Helper_14ee30* q = (Helper_14ee30*)((void *)((owners::Object_592a0 *)h)->FUN_000592a0());
    void* r = q->f59a30();
    *(int*)((char*)r + 0x31c) += *(int*)((char*)(*(Helper_14ee30 * *)&this->f_1c) + 0x14);
    return true;
}
