#include "compat/ptr.h"
#include "decls/data/records.h"

class B_272b70 {
  public:
    void FUN_00273050(int, int);
};
// core::Drive (records.h CoreDrive): forwards to its drive thread (0x00273050)
class A_272b70 : public CoreDrive {
  public:
    void run(int, int);
};
void A_272b70::run(int a0, int a1) {
    ((B_272b70*)driveThread)->FUN_00273050(a0, a1);
}
