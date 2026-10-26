#include "decls/data/engine/pure3d.h"
// data: threshold_284ef0 = DAT_0042c5b4

class SimpleFrameController {
  public:
    char pad[0x28];
    float value;
    int vfunc_22();
};
int SimpleFrameController::vfunc_22() {
    return value <= DAT_0042c5b4;
}
