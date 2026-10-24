// Same code shape as 0x000ff240 (propagated; names are from that function)
#include "gen/global.h"

struct Thing_103410 {
    virtual void f0();
    virtual void f1();
};
extern void* handvtable;
struct COccupationAgent_nv_103410 {
    void cleanup();
};

void COccupationAgent::FUN_00103410() {
    *(void**)this = &handvtable;
    (*(Thing_103410 * *)&this->f_5c)->f1();
    (*(Thing_103410 * *)&this->f_5c) = 0;
    ((COccupationAgent_nv_103410*)this)->cleanup();
}
