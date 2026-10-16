#include "decls/data/engine/om.h"

extern void* vEntity[];
extern void* vIRef[];
extern void FUN_00244b20(void*, void*);
struct Target_244f70 {
    void* vf;
    void Dtor() throw();
};
void Target_244f70::Dtor() throw() {
    void* g = (*(void**)&DAT_004cc08c);
    vf = vEntity;
    FUN_00244b20(g, this);
    DAT_004e5f0c = DAT_004e5f0c - 1;
    vf = vIRef;
}
