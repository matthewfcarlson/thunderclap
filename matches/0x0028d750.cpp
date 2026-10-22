#include "compat/ptr.h"
typedef void(__fastcall* Callback_28d750)(void*);
extern void __fastcall ElemCtor(void*);
extern void* Alloc(hulk_uintptr);
extern void __stdcall VecNew(void*, int, int, Callback_28d750);
class Mem_28d750 {
  public:
    void* Make(unsigned int, int);
};
class RotationChannel_28d750 {
  public:
    RotationChannel_28d750(int, int);
    virtual void v0();
    int m4, m8;
    Mem_28d750* mc;
    int m10, m14;
};
class CompressedQuaternionChannel_28d750 : public RotationChannel_28d750 {
  public:
    void* m18;
    CompressedQuaternionChannel_28d750(int, int);
    virtual void v1();
};
CompressedQuaternionChannel_28d750::CompressedQuaternionChannel_28d750(int x, int y) : RotationChannel_28d750(x, y) {
    m18 = 0;
    if (mc == 0) {
        int n = m10;
        void* p = Alloc(n * 4);
        m18 = (p ? (VecNew(p, 4, n, ElemCtor), p) : 0);
        return;
    }
    m18 = mc->Make(m10 << 2, 3);
}
