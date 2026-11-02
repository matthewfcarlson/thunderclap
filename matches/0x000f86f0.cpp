#include "compat/ptr.h"
extern "C" void* FUN_0008d6d0(hulk_uintptr n);

class Obj_f86f0 {
  public:
    void Init(int a, int b);
    char* m0;
    unsigned m4;
    char pad8[4];
    int* mC;
    unsigned m10;
    char pad14[4];
    void* m18;
    int m1c;
    char pad20[0x110 - 0x20];
    char m110;
    char pad111[0x11c - 0x111];
    unsigned* m11c;
};

void Obj_f86f0::Init(int a, int b) {
    m4 = b * 2;
    m0 = (char*)FUN_0008d6d0((unsigned)(m4 >> 1) * 2);
    m10 = a;
    mC = (int*)FUN_0008d6d0(a * 4);
    unsigned v = m10;
    unsigned n = (v + 0x1f) >> 5;
    unsigned* p = (unsigned*)FUN_0008d6d0(n * 4 + 4);
    *p = v;
    if (n > 0) {
        unsigned* q = p + 1;
        for (unsigned i = n; i != 0; i--)
            *q++ = 0;
    }
    m11c = p;
    unsigned k = (*p + 0x1f) >> 5;
    if (k > 0) {
        unsigned* q = p + 1;
        for (; k != 0; k--)
            *q++ = 0;
    }
    m1c = a;
    m18 = FUN_0008d6d0(a * 8);
    m110 = 1;
}
