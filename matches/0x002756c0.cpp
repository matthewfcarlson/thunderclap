#include "compat/ptr.h"
extern "C" char DAT_0042bb60[];
class DriveOpenRequest {
  public:
    hulk_intptr vptr;
    void Init(int);
    DriveOpenRequest(hulk_intptr);
};
extern void __stdcall Finish();
DriveOpenRequest::DriveOpenRequest(hulk_intptr a) {
    Init(a);
    vptr = ((hulk_intptr)DAT_0042bb60);
    Finish();
}