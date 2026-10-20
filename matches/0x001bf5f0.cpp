#include "compat/ptr.h"
#include "gen/global.h"

class CSubtitleManager_1bf5f0 {
  public:
    void V0();
    void V1();
    void V2();
    void V3();
    void V4();
    void V5();
    void V6();
    void V7(int, int);
};
class Function_1bf5f0 {
  public:
    virtual void V0();
    virtual void V1();
};

template <> void Method2<CSubtitleManager, void, int, const char *>::vfunc_2(void* __p0, void* __p1, void* __p2) { hulk_intptr manager = (hulk_intptr)__p0; int * pair = (int *)__p1; hulk_intptr a = (hulk_intptr)__p2;

    int x = pair[0];
    int y = pair[1];
    CSubtitleManager_1bf5f0* m = (CSubtitleManager_1bf5f0*)manager;
    (m->*(*(void (CSubtitleManager_1bf5f0::**)(int, int))&this->f_1c))(x, y);
}
