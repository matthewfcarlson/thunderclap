#include "compat/ptr.h"
namespace pure3d {
typedef void(__fastcall* Callback_28bba0)(void*);
extern void __fastcall ElemCtor(void*);
extern void* Alloc(unsigned int);
extern void __stdcall VecNew(void*, int, int, Callback_28bba0);
class Mem_28bba0 {
  public:
    void* Make(unsigned int, int);
};
class Base_28bba0 {
  public:
    Base_28bba0(int, int);
    virtual void v0();
    int m4, m8;
    Mem_28bba0* mc;
    int m10, m14;
};
class Float2Channel : public Base_28bba0 {
  public:
    hulk_intptr m18;
    Float2Channel(int, int);
    virtual void v1();
};
Float2Channel::Float2Channel(int x, int y) : Base_28bba0(x, y) {
    m18 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc(n * 8);
        m18 = (hulk_intptr)(p ? (VecNew(p, 8, n, ElemCtor), p) : 0);
        return;
    }
    m18 = (hulk_intptr)mc->Make(m10 << 3, 3);
}
} // namespace pure3d
