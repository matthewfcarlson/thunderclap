#include "compat/ptr.h"
#include "decls/data/records.h"
// core::XboxDrive::vfunc_16 (records.h CoreXboxDrive): checks a path (0x0026f330 makes the device path, 0x0026f3e0
// converts the XAPI error)
class XboxDrive_26fbd0 : public CoreXboxDrive {
  public:
    int v16(const char*);
    void FUN_0026f330(const char*, char*, int);
    unsigned int FUN_0026f3e0(unsigned int);
};
extern "C" int __stdcall FUN_00355c7f(const char*);
extern "C" hulk_ulongptr __stdcall GetLastError();
int XboxDrive_26fbd0::v16(const char* path) {
    char buf[0x101];
    FUN_0026f330(path, buf, 0x101);
    if (FUN_00355c7f(buf)) {
        drive.error = 0;
        return 1;
    }
    drive.error = FUN_0026f3e0((unsigned int)GetLastError());
    return 0;
}
