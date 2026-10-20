#include "compat/ptr.h"
extern "C" char DAT_003f98d0[];
extern "C" char DAT_003fbb34[];
struct Helper_695b0 {
    void Fin();
};
class CTrack {
  public:
    void Base();
};
class CKeyPoseTrack {
  public:
    void Dtor();
    char pad[0x60];
};
void CKeyPoseTrack::Dtor() {
    *(void**)this = (void*)((hulk_intptr)DAT_003fbb34);
    ((Helper_695b0*)((char*)this + 0x60))->Fin();
    ((Helper_695b0*)((char*)this + 0x10))->Fin();
    *(void**)this = (void*)((hulk_intptr)DAT_003f98d0);
    ((CTrack*)this)->Base();
}
