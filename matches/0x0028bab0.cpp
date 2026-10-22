#include "compat/ptr.h"
void* __cdecl Alloc(hulk_uintptr) throw();
class Mem_28bab0 {
  public:
    void* Make(unsigned int, int) throw();
};
struct SimpleChannel_28bab0 {
    virtual void a();
    SimpleChannel_28bab0(int, int) throw();
    int m4, m8;
    Mem_28bab0* mc;
    int m10;
};
struct Float1Channel_28bab0 : SimpleChannel_28bab0 {
    void* m14;
    void* m18;
    Float1Channel_28bab0(int x, int y) throw();
    virtual void a();
};
Float1Channel_28bab0::Float1Channel_28bab0(int x, int y) throw() : SimpleChannel_28bab0(x, y) {
    m18 = 0;
    if (mc == 0)
        m18 = Alloc(m10 * 4);
    else
        m18 = mc->Make(m10 * 4, 3);
}
