#include "gen/owners.h"
typedef unsigned int U32_f7960;
void ReleaseThing(U32_f7960);
void owners::Thing_f7960::FUN_000f7960() {
    if (mFirst) {
        ReleaseThing(mFirst);
        mFirst = 0;
    }
    if (mSecond) {
        ReleaseThing(mSecond);
        mSecond = 0;
    }
}