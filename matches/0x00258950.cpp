#include "compat/ptr.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"

// the om type with this key (the tree of types by key, 0x004cd1a8; records.h OmType)
typedef unsigned int U_258950;
extern "C" OmType* __cdecl FUN_00258870(OmTree* tree, const OmKey* key);
int __cdecl FUN_00258950(U_258950 key) {
    return ((int)(hulk_uintptr)FUN_00258870((OmTree*)((char*)&DAT_004cd1a8), (const OmKey*)(hulk_uintptr)(unsigned int)key));
}
