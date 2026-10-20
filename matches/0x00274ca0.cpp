#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b954[];
extern "C" char DAT_0042b9dc[];
void init();
class Intf {
  public:
    virtual void f0();
    virtual void f1();
};
class Obj_274ca0 {
  public:
    virtual void v0();
    Intf sub;
    char pad[0x10];
    int count;
};
class Target_274ca0 {
  public:
    virtual void Go();
};
class FileCompletionRequest {
  public:
    int v;
    int a;
    int b;
    Obj_274ca0* c;
    Target_274ca0* d;
    int e;
    FileCompletionRequest(int x, Obj_274ca0* y, Target_274ca0* z, int w);
};
FileCompletionRequest::FileCompletionRequest(int x, Obj_274ca0* y, Target_274ca0* z, int w) {
    v = ((hulk_intptr)DAT_0042b914);
    a = 0;
    init();
    v = ((hulk_intptr)DAT_0042b9dc);
    b = x;
    init();
    v = ((hulk_intptr)DAT_0042b954);
    c = y;
    d = z;
    e = w;
    init();
    d->Go();
    c->sub.f0();
    c->count++;
    c->sub.f1();
    c->v0();
}
