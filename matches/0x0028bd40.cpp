#include "compat/ptr.h"
#include "gen/owners.h"
void* Alloc(int n);
struct Allocator_28bd40 {  };
class VectorChannel_28bd40 {
  public:
    VectorChannel_28bd40(int a, int b);
    virtual void f0();
    int pad[2];
    int m0c;
    int m10;
    int pad2[1];
};
class Vector1DOFChannel : public VectorChannel_28bd40 {
  public:
    Vector1DOFChannel(int a, hulk_intptr b);
    virtual void f0();
    int m18, m1c, m20, m24;
    void* m28;
};
Vector1DOFChannel::Vector1DOFChannel(int a, hulk_intptr b) : VectorChannel_28bd40(a, b) {
    int* p = &m18;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    hulk_intptr c = m0c;
    p[4] = 0;
    if (c == 0)
        m28 = Alloc(m10 << 2);
    else
        m28 = ((void *)((owners::C_2888c0 *)(((Allocator_28bd40*)c)))->FUN_002888c0((unsigned)(m10 << 2), 3));
}
