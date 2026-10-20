#include "compat/ptr.h"
extern "C" char DAT_0042aa40[];
extern void* gPtr;
extern int gCount_25fa80;
void InitMeta(void*, void*);
struct MetaType {
    void* vftable;
    void run();
};
void MetaType::run() {
    void* p = gPtr;
    vftable = (void*)((hulk_intptr)DAT_0042aa40);
    InitMeta(p, this);
    --gCount_25fa80;
}