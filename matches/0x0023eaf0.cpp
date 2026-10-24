#include "gen/fight.h"

#include "compat/ptr.h"
extern "C" char DAT_00428e80[];
struct SubA_23eaf0 {
    void A();
};
struct SubB_23eaf0 {
    void B();
};
struct SpawnTrack_nv_23eaf0 {
    void Fin();
};

void fight::SpawnTrack::FUN_0023eaf0() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00428e80);
    ((SubA_23eaf0*)((char*)this + 0x20))->A();
    ((SubB_23eaf0*)((char*)this + 0x14))->B();
    ((SpawnTrack_nv_23eaf0*)this)->Fin();
}
