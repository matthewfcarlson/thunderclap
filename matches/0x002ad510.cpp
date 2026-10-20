#include "compat/ptr.h"
#include "gen/pure3d.h"

typedef unsigned int u32_2ad510;

struct HandlerBase {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e(u32_2ad510, u32_2ad510, u32_2ad510, u32_2ad510);
};
struct Query_2ad510 {
    void* GetType();
};
struct DefaultParticleEmitterHandler_nv_2ad510 {
    void Dispatch(u32_2ad510, hulk_uintptr, u32_2ad510, u32_2ad510);
};

void pure3d::DefaultParticleEmitterHandler::vfunc_4(int __p0, int __p1, int __p2, int __p3) { u32_2ad510 first = (u32_2ad510)__p0; hulk_uintptr obj = (u32_2ad510)__p1; u32_2ad510 third = (u32_2ad510)__p2; u32_2ad510 fourth = (u32_2ad510)__p3;

    if ((hulk_uintptr)((Query_2ad510*)obj)->GetType() == 0x15900)
        ((DefaultParticleEmitterHandler_nv_2ad510*)this)->Dispatch(first, obj, third, fourth);
}
