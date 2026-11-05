#include "compat/ptr.h"
extern "C" char DAT_0042bc80[];
class DriveCancelRequest {
  public:
    hulk_intptr value;
    DriveCancelRequest(hulk_intptr);
    void Init(int);
};
extern void Helper();
DriveCancelRequest::DriveCancelRequest(hulk_intptr arg) {
    Init(arg);
    value = ((hulk_intptr)DAT_0042bc80);
    Helper();
}