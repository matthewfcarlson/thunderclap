// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_49e80;
class CCondition_49e80 {
  public:
    virtual int vfunc_0(int);
};

int CLuaNumberCondition::vfunc_0(int index) {
    int* p = gTable_49e80;
    return p[index];
}
