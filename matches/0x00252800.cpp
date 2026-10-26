// Same code shape as 0x0024ea30 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/audio.h"

void audio::SeqActionVarVolume::vfunc_6(hulk_intptr ) {
    int i = this->f_0c;
    --i;
    if (i != 0) {
        i -= 3;
        if (i != 0) {
            --i;
            if (i == 0)
                this->f_0c = 0;
            return;
        }
    }
    this->f_0c = 2;
}
