#include "decls/data/engine/core.h"

extern "C" void _ReadWriteBarrier();
extern void* vDrive[];
extern void* vD4[];
extern void* vDc[];
extern void* vSafe[];
extern void* vBase[];
extern void* vIRef[];
class Part_272840 {
  public:
    void Fini() throw();
};
struct Drive_272840 {
    void* v0;
    void* v4;
    unsigned p8;
    void* vc;
    int pad;
    Part_272840 part;
    void Dtor() throw();
};
void Drive_272840::Dtor() throw() {
    v0 = vDrive;
    v4 = vD4;
    vc = vDc;
    part.Fini();
    vc = vSafe;
    _ReadWriteBarrier();
    unsigned t = p8;
    (*(unsigned*)&DAT_004cdbb0) = t;
    v4 = vBase;
    v0 = vIRef;
}
