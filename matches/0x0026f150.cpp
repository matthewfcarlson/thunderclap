// Same code shape as 0x0023c920 (propagated; names are from that function)
#include "decls/data/records.h"
#include "gen/core.h"

// core::SafeRefCount's release (0x0026f160) on the drive's IMutable base (+0xc; records.h CoreDrive)
class Helper_26f150 {
  public:
    void FUN_0026f160();
};

void core::Drive::vfunc_1() {
    ((Helper_26f150*)&((CoreDrive*)this)->vftableMutable)->FUN_0026f160();
}
