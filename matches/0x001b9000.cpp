#include "gen/global.h"

#include "compat/ptr.h"
#include "decls/data/game/global.h"

class CDHGameObjectCreator_1b9000 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual const char* f3(void*);
};
class DataHandlerObjectCreator {
  public:
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual const char* g3(void*);
};

void* CRenderManager::vfunc_3(void* __p0) { void * p = (void *)__p0;

    return (void*)((const char*)((p != 0) - 1 & ((hulk_intptr)((char*)&DAT_00420dd8))));
}
