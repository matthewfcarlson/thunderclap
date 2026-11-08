#include "compat/ptr.h"
#include "decls/data/records.h"

namespace core {
// core::XboxDrive's IMutable base (+0xc of records.h CoreXboxDrive): enters the device's critical section
class XboxDrive {
  public:
    void vfunc_0_adjc();
};
} // namespace core
extern "C" void __cdecl FUN_0026d850(void*);
void core::XboxDrive::vfunc_0_adjc() {
    CoreXboxDrive* drive = (CoreXboxDrive*)((char*)this - (hulk_uintptr)&((CoreXboxDrive*)0)->drive.vftableMutable);
    FUN_0026d850(drive->lock);
}
