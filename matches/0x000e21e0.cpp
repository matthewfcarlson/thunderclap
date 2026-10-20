#include "compat/ptr.h"
extern int vtbl;
class VScroll {
  public:
    void init(int, int);
    VScroll(int a, int q);
    unsigned int vf;
    char pre[0x3c];
    unsigned int arr[0x80];
    unsigned int a[7];
    char gap[0x0c];
    unsigned int b;
};
VScroll::VScroll(int a, int q) {
    init(a, q);
    vf = (hulk_uintptr)&vtbl;
    for (int i = 0; i < 0x80; i++)
        arr[i] = 0;
    this->a[0] = 0;
    this->a[1] = 0;
    this->a[2] = 0;
    this->a[3] = 0;
    this->a[4] = 0;
    this->a[5] = 0;
    this->b = 0;
    this->a[6] = 0;
}
