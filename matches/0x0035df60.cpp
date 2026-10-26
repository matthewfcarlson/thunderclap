#include "decls/data/game/global.h"
// data: result = DAT_004e09d8, text = DAT_00400488

extern "C" __int64 parse(const char*);
void target() {
    (*(__int64*)&DAT_004e09d8) = parse(DAT_00400488);
}
