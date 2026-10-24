#include "gen/movie.h"

#include "compat/ptr.h"
extern "C" char DAT_00434300[];

movie::BinkCallback* movie::BinkCallback::FUN_003352a0() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00434300);
    this->f_0c = 0;
    return (BinkCallback*)(this);
}
