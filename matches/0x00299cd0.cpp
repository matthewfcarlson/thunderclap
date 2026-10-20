#include "compat/ptr.h"
extern int vt1_299cd0;
extern void* Alloc(hulk_uintptr) throw();
struct Buf_299cd0 {
    char* b;
    char* e;
    void Init(unsigned n) throw() {
        if (n > 0) {
            b = (char*)Alloc(n);
            if (b) {
                e = b + n;
                return;
            }
        }
        b = 0;
        e = 0;
    }
};
struct Sub_299cd0 {
    void Fill(unsigned, const unsigned char*) throw();
};
class D {
  public:
    void* vptr;
    int a4;
    Buf_299cd0 x8;
    int p10;
    Buf_299cd0 x14;
    int p1c;
    char c20;
    char p21[3];
    Buf_299cd0 x24;
    int p2c;
    Buf_299cd0 x30;
    int p38;
    Sub_299cd0 s3c;
    D(unsigned char n) throw();
};
D::D(unsigned char n) throw() {
    a4 = 0;
    vptr = &vt1_299cd0;
    x8.Init(0x20);
    x14.Init(0x20);
    unsigned len = n;
    c20 = 0;
    x24.Init(len);
    x30.Init(len);
    s3c.Fill(len, &n);
    for (unsigned i = 0; i < 0x20; i++) {
        x8.b[i] = 0;
        x14.b[i] = 0;
    }
}
