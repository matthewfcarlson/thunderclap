// Same code shape as 0x00085cd0 (propagated); reads 0x004d4ce8, a pointer item
#include "compat/ptr.h"
#include "decls/data/platform/xbox/pure3d.h"

hulk_intptr FUN_00328510(void) {
    return *(hulk_intptr*)&DAT_004d4ce8;
}
