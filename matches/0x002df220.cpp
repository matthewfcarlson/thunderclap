// Same code shape as 0x002df210 (propagated; names are from that function)
#include "gen/pure3d.h"

class Helper_2df220 {
  public:
    void run(int, int);
};

void pure3d::ShadowMesh::vfunc_19(int a0, int a1) {
    (*(*(Helper_2df220 ** *)&this->f_48))->run(a0, a1);
}
