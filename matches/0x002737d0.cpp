// Same code shape as 0x00273730 (propagated; names are from that function)
#include "gen/core.h"

#include "compat/ptr.h"
class CompletionCallbackRequest_2737d0 {
  public:
    char pad[12];
};
class Request_2737d0 {};

int core::DriveCompletionRequest::vfunc_3() {
    return *(int*)(*(hulk_intptr*)((char*)this + 0xc) + 0xc);
}
