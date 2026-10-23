#include "compat/ptr.h"
#include "gen/pure3d.h"
extern "C" hulk_intptr Alloc(hulk_intptr);
class Inner_966f0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void Send(int, int);
};
struct Shader_nv_966f0 {
    pure3d::Shader* Init();
};
extern "C" unsigned char gEnabled_966f0;
extern "C" pure3d::Shader* gObject_966f0;
void Target() {
    if (gEnabled_966f0 && gObject_966f0 == 0) {
        pure3d::Shader* p = (pure3d::Shader*)Alloc(0x20);
        if (p)
            p = ((Shader_nv_966f0*)(p))->Init();
        else
            p = 0;
        gObject_966f0 = p;
        gObject_966f0->vfunc_0();
        (*(Inner_966f0 * *)&gObject_966f0->f_10)->Send(0x444d4c42, 1);
    }
}
