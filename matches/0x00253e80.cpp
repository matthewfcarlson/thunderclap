#include "gen/audio.h"

void audio::SeqActionStream::vfunc_2(int , int __p1) { char flag = (char)__p1;

    this->f_18 = 100;
    this->f_20 = 1;
    if (flag) {
        this->f_14 = 0;
        this->f_0c = -1;
        this->f_10 = -1;
    }
}
