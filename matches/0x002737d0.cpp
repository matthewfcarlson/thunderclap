// Same code shape as 0x00273730 (propagated; names are from that function)
#include "compat/ptr.h"
class CompletionCallbackRequest {
  public:
    char pad[12];
};
class Request {};
class DriveCompletionRequest_2737d0 : public CompletionCallbackRequest, public Request {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual int vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
};
int DriveCompletionRequest_2737d0::vfunc_3() {
    return *(int*)(*(hulk_intptr*)((char*)this + 0xc) + 0xc);
}
