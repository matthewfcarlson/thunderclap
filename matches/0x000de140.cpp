#include "decls/data/game/global.h"

typedef unsigned char u8;
class ControllerPollerBase {
  public:
    virtual void f();
    int a;
    void* p;
    u8 c[4];
    int d;
    ControllerPollerBase(void*);
};
ControllerPollerBase::ControllerPollerBase(void* x) {
    p = x;
    a = 0;
    (*(u8*)&DAT_004de7a8) = 0;
    d = 0;
    c[0] = 0;
}