#include "gen/fight.h"
#include "gen/owners.h"

struct Inner_23b1f0 {
};
struct ScriptReader_nv_23b1f0 {
    void helper();
    void finish();
};

void fight::ScriptReader::vfunc_17() {
    --this->f_10;
    ((owners::Target_27b040 *)(((Inner_23b1f0*)((char*)this + 0x118))))->FUN_0027b040((hulk_uintptr)0);
    ((ScriptReader_nv_23b1f0*)this)->helper();
    if (this->f_10 >= 0) {
        int x = (*(volatile int *)&this->f_120);
        x |= (*(volatile int *)&this->f_124);
        if (x == 0)
            ((ScriptReader_nv_23b1f0*)this)->finish();
    }
}
