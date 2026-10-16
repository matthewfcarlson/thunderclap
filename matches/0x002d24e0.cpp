#include "gen/pure3d.h"

void pure3d::ParticlePointGenerator::vfunc_7(int x, int y) {
    switch (x) {
    case 1:
        (*(int *)&this->f_44) = y;
        break;
    case 2:
        (*(int *)&this->f_48) = y;
        break;
    case 3:
        (*(int *)&this->f_4c) = y;
        break;
    }
}
