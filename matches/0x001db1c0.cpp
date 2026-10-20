#include "compat/ptr.h"
extern "C" char DAT_003f6308[];
extern "C" char DAT_00423114[];
extern "C" char DAT_00423124[];
class CSPListener {
  public:
    void* vptr;
    void* vptr4;
    int zero;
    void* param;
    CSPListener(void*);
};
CSPListener::CSPListener(void* p) {
    volatile unsigned* q = (volatile unsigned*)this;
    q[1] = ((hulk_intptr)DAT_003f6308);
    q[2] = 0;
    q[0] = ((hulk_intptr)DAT_00423124);
    q[1] = ((hulk_intptr)DAT_00423114);
    q[3] = (hulk_uintptr)p;
}