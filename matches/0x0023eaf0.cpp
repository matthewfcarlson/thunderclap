#include "compat/ptr.h"
extern "C" char DAT_00428e80[];
struct SubA_23eaf0 {
    void A();
};
struct SubB_23eaf0 {
    void B();
};
struct SpawnTrack {
    void Fin();
    void Run();
};
void SpawnTrack::Run() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00428e80);
    ((SubA_23eaf0*)((char*)this + 0x20))->A();
    ((SubB_23eaf0*)((char*)this + 0x14))->B();
    Fin();
}
