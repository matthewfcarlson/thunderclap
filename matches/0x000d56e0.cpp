#include "gen/global.h"

namespace math {
struct Vector_d56e0 {
    float x, y, z;
};
} // namespace math
class MessageOverlay_d56e0 {
  public:
    void Show(const char*, int, math::Vector_d56e0);
};
class Function_d56e0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};

template <> void Method3<MessageOverlay, void, const char *, int,math::Vector>::vfunc_2(void* __p0, void* __p1, void* __p2) { MessageOverlay_d56e0 * obj = (MessageOverlay_d56e0 *)__p0; void * args = (void *)__p1; void * other = (void *)__p2;

    char* p = (char*)args;
    const char* s = *(const char**)p;
    p += 4;
    int i = *(int*)p;
    p += 4;
    math::Vector_d56e0 v = *(math::Vector_d56e0*)p;
    (obj->*(*(void (MessageOverlay_d56e0::**)(const char *, int, math::Vector_d56e0))&this->f_1c))(s, i, v);
}
