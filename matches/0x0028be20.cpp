#include "compat/ptr.h"
typedef void(__fastcall* Callback_28be20)(void*);
extern void __fastcall ElemCtor(void*);
extern void* Alloc(hulk_uintptr);
extern void __stdcall VecNew(void*, int, int, Callback_28be20);
class Mem_28be20 {
  public:
    void* Make(unsigned int, int);
};
class VectorChannel_28be20 {
  public:
    VectorChannel_28be20(int, int);
    virtual void v0();
    int m4, m8;
    Mem_28be20* mc;
    int m10, m14;
};
struct Z4 {
    int a, b, c, d;
    Z4() {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
};
class Vector2DOFChannel_28be20 : public VectorChannel_28be20 {
  public:
    Z4 z;
    hulk_intptr m28;
    Vector2DOFChannel_28be20(int, int);
    virtual void v1();
};
Vector2DOFChannel_28be20::Vector2DOFChannel_28be20(int x, int y) : VectorChannel_28be20(x, y) {

    m28 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc(n * 8);
        m28 = (hulk_intptr)(p ? (VecNew(p, 8, n, ElemCtor), p) : 0);
        return;
    }
    m28 = (hulk_intptr)mc->Make(m10 << 3, 3);
}
