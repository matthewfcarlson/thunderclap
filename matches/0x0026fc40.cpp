#include "decls/data/records.h"

// core::XboxDrive::vfunc_17 (records.h CoreXboxDrive): opens a directory (0x0026f330 makes the device path,
// 0x0026f3e0 converts the XAPI error)
class XboxDrive_26fc40 : public CoreXboxDrive {
  public:
    int vfunc_17(const char*);
    void FUN_0026f330(const char*, char*, int);
    unsigned int FUN_0026f3e0(unsigned int);
};
extern int __stdcall FUN_0021257d(char*);
extern unsigned int __stdcall GetLastError();
int XboxDrive_26fc40::vfunc_17(const char* path) {
    char buf[0x101];
    FUN_0026f330(path, buf, 0x101);
    if (FUN_0021257d(buf)) {
        drive.error = 0;
        return 1;
    }
    drive.error = FUN_0026f3e0(GetLastError());
    return 0;
}
