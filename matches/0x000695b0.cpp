#include "gen/global.h"

#include "compat/ptr.h"
extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fbb34[];
struct Helper_695b0 {
    void Fin();
};
class CTrack_695b0 {
  public:
    void Base();
};

void CKeyPoseTrack::FUN_000695b0() {
    *(void**)this = (void*)((hulk_intptr)DAT_003fbb34);
    ((Helper_695b0*)((char*)this + 0x60))->Fin();
    ((Helper_695b0*)((char*)this + 0x10))->Fin();
    *(void**)this = (void*)((hulk_intptr)DAT_003f98d0);
    ((CTrack_695b0*)this)->Base();
}
