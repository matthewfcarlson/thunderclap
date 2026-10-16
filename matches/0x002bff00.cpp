// Same code shape as 0x002bfd50 (propagated; names are from that function)
#include "gen/pure3d.h"

void pure3d::Image8::vfunc_10(int x, int y, int __p2) { unsigned char value = (unsigned char)__p2;

    (*(unsigned char * *)&this->f_24)[this->f_10 * y + x] = value;
}
