#include "compat/ptr.h"
#include "decls/data/records.h"

class B_272b80 {
  public:
    int FUN_002730c0();
};
// core::Drive (records.h CoreDrive): asks its drive thread whether requests are queued (0x002730c0)
class A_272b80 : public CoreDrive {
  public:
    int run();
};
int A_272b80::run() {
    return ((B_272b80*)driveThread)->FUN_002730c0();
}
