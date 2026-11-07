#include "gen/om.h"
#include "decls/data/engine/om.h"
#include "decls/data/records.h"
// data: TypeName = DAT_004cd1a8 (the tree of types by key)

// the tree insert (records.h OmType: the type's node, keyed by its own key)
bool __cdecl FUN_00258530(OmTree* tree, OmType* item, const OmKey* key);

void om::Type::vfunc_0() {
    FUN_00258530((OmTree*)((char*)&DAT_004cd1a8), (OmType*)this, &((OmType*)this)->body.key);
}
