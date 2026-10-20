#include "compat/ptr.h"
extern "C" char DAT_0042bb60[];
class DriveOpenRequest {
  public:
    hulk_intptr vptr;
    void Init(int);
    DriveOpenRequest(int);
};
extern void __stdcall Finish();
DriveOpenRequest::DriveOpenRequest(int a) {
    Init(a);
    vptr = ((hulk_intptr)DAT_0042bb60);
    Finish();
}