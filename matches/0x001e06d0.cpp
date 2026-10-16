#include "gen/global.h"

namespace math {
struct Vector_1e06d0 {
    float x, y, z;
};
} // namespace math
class CSPManager_1e06d0 {
  public:
    void doIt(const char*, const char*, math::Vector_1e06d0);
};
class Function_1e06d0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(CSPManager_1e06d0*, void*, void*);
};

template <> void Method3<CSPManager, void, const char *, const char *,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { CSPManager_1e06d0 * obj = (CSPManager_1e06d0 *)__p0; void * raw = (void *)__p1;

    const char** p = (const char**)raw;
    const char* a = *p++;
    const char* b = *p++;
    math::Vector_1e06d0 v = *(math::Vector_1e06d0*)p;
    (obj->*(*(void (CSPManager_1e06d0::**)(const char *, const char *, math::Vector_1e06d0))&this->f_1c))(a, b, v);
}
