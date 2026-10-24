#include "compat/ptr.h"
struct Mat_2e1750 {
    char d[64];
    void Init();
};
void* Alloc(hulk_uintptr n);
class NonCopyable_2e1750 {
  public:
    NonCopyable_2e1750() { a = 0; }
    virtual void f0();
    int a;
};
class BoneMatrixList : public NonCopyable_2e1750 {
  public:
    BoneMatrixList(unsigned n);
    virtual void f0();
    Mat_2e1750* b;
    Mat_2e1750* c;
};
BoneMatrixList::BoneMatrixList(unsigned n) {
    if (n > 0 && (b = (Mat_2e1750*)Alloc(n * 64)) != 0) {
        c = b + n;
    } else {
        b = 0;
        c = 0;
    }
    for (unsigned i = 0; i < n; i++)
        b[i].Init();
}
