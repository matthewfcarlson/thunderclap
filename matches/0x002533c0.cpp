// Same code shape as 0x002523a0 (propagated; names are from that function)
#include "gen/audio.h"

bool FUN_0025ac10(void*, void*);
class SeqEventVarPitchRand_2533c0 : public audio::SeqEvent {
  public:
    char pad[8];
    int x;
    int y;
    int vfunc_0(void* p);
};
int SeqEventVarPitchRand_2533c0::vfunc_0(void* p) {
    char r = (char)audio::SeqEvent::vfunc_0(p);
    if (r) {
        if (FUN_0025ac10(p, (char*)this + 8)) {
            if (FUN_0025ac10(p, (char*)this + 12))
                return 1;
        }
    }
    return 0;
}
