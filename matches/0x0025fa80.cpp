// om::MetaType_25fa80's destructor body: the vftable, the removal from the tree of meta types (0x004e79b8, records.h).
#include "decls/data/engine/om.h"
#include "decls/data/records.h"

#include "compat/ptr.h"
extern "C" char DAT_0042aa40[];
extern "C" void __cdecl FUN_0025f390(void *, void *);
struct MetaType_25fa80 : OmMetaType {
    void run();
};
void MetaType_25fa80::run() {
    void* p = (*(void**)&DAT_004cd360);
    vftable = DAT_0042aa40;
    FUN_0025f390(p, this);
    --DAT_004e79b8.count;
}
