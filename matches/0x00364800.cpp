#include "decls/data/engine/pure3d.h"
// data: gExtension = DAT_004d3a0c

extern void* pddiExtensionVtable;
extern "C" void FUN_00364800() {
    (*(void**)&DAT_004d3a0c) = &pddiExtensionVtable;
}
