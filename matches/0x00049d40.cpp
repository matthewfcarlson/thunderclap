#include "gen/global.h"

class Helper_49d40 {
  public:
    void* First();
    void* Second();
};

bool CIsGrappledCondition::vfunc_7(void* __p0) { Helper_49d40 * p = (Helper_49d40 *)__p0;

    void* a = p->First();
    void* b = ((Helper_49d40*)a)->Second();
    return *(int*)((char*)b + 0x338) != 0;
}
