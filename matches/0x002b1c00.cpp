#include "gen/pure3d.h"

int pure3d::MultiController::vfunc_19() {
    if (!this->f_3c) {
        for (unsigned int i = 0; i < (unsigned int)this->f_44; ++i)
            if (!(*(pure3d::MultiController ** *)&this->f_48)[i]->vfunc_19())
                return 0;
        return 1;
    }
    return this->f_38;
}
