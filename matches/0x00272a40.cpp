#include "compat/ptr.h"
#include "decls/data/records.h"

class Inner_272a40 {
  public:
    virtual void A();
    virtual void B();
};
// the drive thread's requeue (0x00273120)
class Other_272a40 {
  public:
    void FUN_00273120(int);
};
// core::Drive (records.h CoreDrive): clears the active request under the IMutable lock, then tells the drive thread
class Drive_272a40 : public CoreDrive {
  public:
    void Target(int);
};
void Drive_272a40::Target(int arg) {
    ((Inner_272a40*)&vftableMutable)->A();
    active = 0;
    request = 0;
    ((Inner_272a40*)&vftableMutable)->B();
    ((Other_272a40*)driveThread)->FUN_00273120(arg);
}
