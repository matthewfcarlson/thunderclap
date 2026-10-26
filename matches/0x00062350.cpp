// Same code shape as 0x00048300 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/global.h"

extern int* gTable_62350;
class CCondition_62350 {
  public:
    virtual int vfunc_0(int);
};

hulk_intptr CSmartPropUpdateAttachmentTrack::vfunc_0(int index) {
    int* p = gTable_62350;
    return p[index];
}
