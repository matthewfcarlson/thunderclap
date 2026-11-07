#include "compat/ptr.h"
#include "gen/om.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"

// the tree remove (records.h OmType: the type's node in the tree of types by key, 0x004cd1a8)
extern "C" void __cdecl FUN_00258730(OmTree* tree, OmType* entry);

void om::Type::vfunc_1() {
    FUN_00258730((OmTree*)((char*)&DAT_004cd1a8), (OmType*)this);
}
