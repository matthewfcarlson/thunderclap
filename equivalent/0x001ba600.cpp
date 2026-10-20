// STATUS: equivalent (tools/equiv.py level 3: 20002 inputs, branch coverage 0/0)
// Closure6<CRenderManager,void,float,float,float,float,float,float>::vfunc_2 @ 0x001ba600
#include "gen/global.h"

struct CRenderManager_1ba600 {
    void FUN_001ba600(float, float, float, float, float, float);
};
struct Function_1ba600 {
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
};

template <> void Closure6<CRenderManager, void, float, float, float, float, float, float>::vfunc_2(void* __p0, void* __p1, void* __p2) { void * unused = (void *)__p0; const float * arguments = (const float *)__p1; void * unused2 = (void *)__p2;

    ((*(CRenderManager_1ba600 * *)&this->f_20)->*(*(void (CRenderManager_1ba600::**)(float, float, float, float, float, float))&this->f_1c))(arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
}
