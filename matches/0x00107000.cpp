// Same code shape as 0x000ff240 (propagated; names are from that function)
#include "gen/global.h"

struct Thing_107000 {
    virtual void f0();
    virtual void f1();
};
extern void* handvtable;
struct CRangedAgent_nv_107000 {
    void cleanup();
};

void CRangedAgent::FUN_00107000() {
    *(void**)this = &handvtable;
    (*(Thing_107000 * *)&this->f_5c)->f1();
    (*(Thing_107000 * *)&this->f_5c) = 0;
    ((CRangedAgent_nv_107000*)this)->cleanup();
}
