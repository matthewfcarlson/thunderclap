#include "decls/data/game/unknown.h"
// data: gEnabled_966f0 = DAT_004dd8e4, gObject_966f0 = DAT_004dd930

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
void Target() {
    if ((*(unsigned char*)&DAT_004dd8e4) && (*(pure3d::Shader**)&DAT_004dd930) == 0) {
        pure3d::Shader* p = (pure3d::Shader*)Alloc(0x20);
        if (p)
            p = ((Shader_nv_966f0*)(p))->Init();
        else
            p = 0;
        (*(pure3d::Shader**)&DAT_004dd930) = p;
        (*(pure3d::Shader**)&DAT_004dd930)->vfunc_0();
        (*(Inner_966f0 * *)&(*(pure3d::Shader**)&DAT_004dd930)->f_10)->Send(0x444d4c42, 1);
    }
}
