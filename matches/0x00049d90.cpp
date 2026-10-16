// Same code shape as 0x00048300 (propagated; names are from that function)
#include "gen/global.h"

extern int* gTable_49d90;
class CCondition_49d90 {
  public:
    virtual int vfunc_0(int);
};

int CGrappleSizeCondition::vfunc_0(int index) {
    int* p = gTable_49d90;
    return p[index];
}
