#include "gen/core.h"

struct Callee_2736e0 {
    void f(core::FileCompletionRequest*);
};
struct Inner_2736e0 {
    char pad[12];
    Callee_2736e0* callee;
};
class CompletionCallbackRequest_2736e0 {
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

int core::FileCompletionRequest::vfunc_1() {
    (*(Inner_2736e0 * *)&this->f_0c)->callee->f(this);
    return 3;
}
