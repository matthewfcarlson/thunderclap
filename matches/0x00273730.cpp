#include "gen/core.h"

#include "compat/ptr.h"
class CompletionCallbackRequest_273730 {
  public:
    char pad[12];
};
class Request_273730 {};

int core::FileCompletionRequest::vfunc_3() {
    return *(int*)(*(hulk_intptr*)((char*)this + 0xc) + 0xc);
}
