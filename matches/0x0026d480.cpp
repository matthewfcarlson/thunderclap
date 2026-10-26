#include "gen/core.h"
#include "decls/data/engine/core.h"
// data: gValue_26d480 = DAT_004cdbb0

#include "compat/ptr.h"
extern "C" char DAT_0042afa8[];
extern "C" char DAT_0042b3a4[];
extern "C" char DAT_0042b3ac[];
extern "C" char DAT_0042b3b4[];
extern "C" char DAT_0042b3fc[];
void Init();

int* core::MemoryTwoWayAllocator::FUN_0026d480() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042b3fc);
    ((hulk_intptr*)this)[1] = ((hulk_intptr)DAT_0042afa8);
    ((int*)this)[2] = DAT_004cdbb0;
    Init();
    ((hulk_intptr*)this)[1] = ((hulk_intptr)DAT_0042b3a4);
    ((int*)this)[3] = 0;
    Init();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_0042b3b4);
    ((hulk_intptr*)this)[1] = ((hulk_intptr)DAT_0042b3ac);
    ((int*)this)[4] = 0;
    ((int*)this)[5] = 0;
    ((int*)this)[6] = 0;
    ((int*)this)[7] = 0;
    ((int*)this)[8] = 0;
    ((int*)this)[9] = 0;
    ((int*)this)[10] = 0;
    Init();
    return (int*)((int*)this);
}
