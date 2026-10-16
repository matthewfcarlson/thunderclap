#include "gen/fight.h"

struct Inner_23b1f0 {
    void call(int);
};
struct ScriptReader_nv_23b1f0 {
    void helper();
    void finish();
};

void fight::ScriptReader::vfunc_17() {
    --this->f_10;
    ((Inner_23b1f0*)((char*)this + 0x118))->call(0);
    ((ScriptReader_nv_23b1f0*)this)->helper();
    if (this->f_10 >= 0) {
        int x = (*(volatile int *)&this->f_120);
        x |= (*(volatile int *)&this->f_124);
        if (x == 0)
            ((ScriptReader_nv_23b1f0*)this)->finish();
    }
}
