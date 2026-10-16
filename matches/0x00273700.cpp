#include "gen/core.h"

struct I0 {
    virtual void f();
    virtual void g();
};
struct I3 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d(int);
};
struct Obj_273700 {
    void* v;
    I0 sub;
    char pad[0x10];
    int count;
};

void core::FileCompletionRequest::vfunc_7() {
    (*(Obj_273700 * *)&this->f_0c)->sub.f();
    --(*(Obj_273700 * *)&this->f_0c)->count;
    (*(Obj_273700 * *)&this->f_0c)->sub.g();
    (*(I3 * *)&this->f_10)->d(this->f_14);
}
