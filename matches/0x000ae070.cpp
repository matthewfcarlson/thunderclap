#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_00405d38[];
class CController {
  public:
    void a();
    void b();
    void run();
};
void CController::run() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00405d38);
    a();
    b();
    *(hulk_intptr*)this = ((hulk_intptr)DAT_003f6098);
}
