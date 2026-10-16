// Same code shape as 0x002736e0 (propagated; names are from that function)
#include "gen/core.h"

struct Callee_273780 {
    void f(core::DriveCompletionRequest*);
};
struct Inner_273780 {
    char pad[12];
    Callee_273780* callee;
};
class CompletionCallbackRequest_273780 {
  public:
    virtual void v0();
    virtual int v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};

int core::DriveCompletionRequest::vfunc_1() {
    (*(Inner_273780 * *)&this->f_0c)->callee->f(this);
    return 3;
}
