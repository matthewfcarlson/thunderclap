#include "decls/data/engine/om.h"
// data: gCount_25fa80 = DAT_004e79cc

#include "compat/ptr.h"
extern "C" char DAT_0042aa40[];
extern "C" void __cdecl FUN_0025f390(void *, void *);
struct MetaType {
    void* vftable;
    void run();
};
void MetaType::run() {
    void* p = (*(void**)&DAT_004cd360);
    vftable = (void*)((hulk_intptr)DAT_0042aa40);
    FUN_0025f390(p, this);
    --(*(int*)&DAT_004e79cc);
}