#include "gen/global.h"
#include "gen/owners.h"

class Helper_49d40 {
  public:
    void* Second();
};

bool CIsGrappledCondition::vfunc_7(void* __p0) { Helper_49d40 * p = (Helper_49d40 *)__p0;

    void* a = ((void *)((owners::Object_592a0 *)p)->FUN_000592a0());
    void* b = ((Helper_49d40*)a)->Second();
    return *(int*)((char*)b + 0x338) != 0;
}
