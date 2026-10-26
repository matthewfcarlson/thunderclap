#include "decls/data/game/global.h"
// data: globalValue = DAT_004de688

extern "C" __int64 getValue(const char*);
void FUN_0035d930() {
    (*(__int64*)&DAT_004de688) = getValue("load");
}