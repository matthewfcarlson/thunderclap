// Same code shape as 0x0024ea30 (propagated; names are from that function)
#include "gen/audio.h"

void audio::SeqActionExpression::vfunc_6(int ) {
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
