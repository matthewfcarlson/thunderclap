#include "decls/data/engine/physics.h"
// data: gHalf = DAT_004d3188

class Thing_309b80 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual bool Check();
    virtual void Get(int*);
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void Apply(int);
};
extern "C" void FUN_00305800(int*, int, float);
void Thing_309b80::Apply(int x) {
    int local[3];
    if (!Check()) {
        Get(&local[0]);
        FUN_00305800(&local[0], x, (*(float*)&DAT_004d3188));
        Apply(x);
    }
}
