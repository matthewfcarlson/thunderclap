#include "gen/global.h"

class A_17980 {
  public:
    void* f();
};
class B_17980 {
  public:
    void* f(int);
};
class C_17980 {
  public:
    void f();
};
extern A_17980* gGlobal_17980;

void CHapticEventAction::vfunc_4() {
    if (*((char*)(*(void * *)&this->f_20) + 0x1c)) {
        void* p = gGlobal_17980->f();
        B_17980* b = (B_17980*)p;
        C_17980* c = (C_17980*)b->f(0);
        c->f();
    }
}
