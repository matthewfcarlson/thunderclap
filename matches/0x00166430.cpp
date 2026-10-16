// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/hulkfight.h"

extern int* gTable_166430;
class CCondition_166430 {
  public:
    virtual int vfunc_0(int);
};

int hulkfight::motion::InLoadedRoomCondition::vfunc_0(int index) {
    int* p = gTable_166430;
    return p[index];
}
