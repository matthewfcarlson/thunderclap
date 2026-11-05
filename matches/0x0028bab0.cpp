#include "compat/ptr.h"
#include "gen/owners.h"
void* __cdecl FUN_0008d6d0(hulk_uintptr) throw();
class Mem_28bab0 {
  public:
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
    Float1Channel_28bab0(int x, hulk_intptr y) throw();
    virtual void a();
};
Float1Channel_28bab0::Float1Channel_28bab0(int x, hulk_intptr y) throw() : SimpleChannel_28bab0(x, y) {
    m18 = 0;
    if (mc == 0)
        m18 = FUN_0008d6d0(m10 * 4);
    else
        m18 = ((void *)((owners::C_2888c0 *)mc)->FUN_002888c0((unsigned)(m10 * 4), 3));
}
