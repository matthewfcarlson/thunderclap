#include "decls/address.h"
class HUDOverlay {
  public:
    HUDOverlay(int, int);
    virtual void f();
};
template <class T, class U, class V, class W, class X> class Method3 : public HUDOverlay {
  public:
    Method3(int, const char*);
    virtual void f();
    char pad[12];
    char a;
    char b;
    char c;
    char pad2[5];
    char d;
    char pad3[3];
    int id;
};
extern const char g1_ceb80[], g2[], g3[];
template <>
Method3<HUDOverlay, int, const char*, const char*, float>::Method3(int x, const char* y) : HUDOverlay(x, 3) {
    id = (int)y;
    d = FUN_001d04d0(g1_ceb80);
    a = FUN_001d04d0(g2);
    b = FUN_001d04d0(g2);
    c = FUN_001d04d0(g3);
}