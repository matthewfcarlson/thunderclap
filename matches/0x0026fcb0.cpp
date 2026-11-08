#include "decls/data/records.h"

// core::XboxDrive::vfunc_14 (records.h CoreXboxDrive): formats the utility drive when bit 3 of its type word says
// it is one; 0x0026f3e0 converts the XAPI error
class XboxDrive_26fcb0 : public CoreXboxDrive {
  public:
    int vfunc_14();
    unsigned int FUN_0026f3e0(unsigned int);
};
extern int XFormatUtilityDrive();
extern unsigned int __stdcall GetLastError();
int XboxDrive_26fcb0::vfunc_14() {
    if ((*(unsigned char*)&type & 8) != 0) {
        if (XFormatUtilityDrive() == 0)
            drive.error = FUN_0026f3e0(GetLastError());
    }
    drive.error = 0;
    return 1;
}
