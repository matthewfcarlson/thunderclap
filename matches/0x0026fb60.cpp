#include "decls/data/records.h"

extern "C" __stdcall unsigned long GetLastError();
int __stdcall FUN_00355c13(char* path, int flag);

namespace core {
// core::XboxDrive::vfunc_15 (records.h CoreXboxDrive): creates a directory (0x0026f330 makes the device path,
// 0x0026f3e0 converts the XAPI error)
class XboxDrive_26fb60 : public CoreXboxDrive {
  public:
    int vfunc_15(const char* p);
    void FUN_0026f330(const char* p, char* out, int n);
    unsigned int FUN_0026f3e0(unsigned int e);
};
int XboxDrive_26fb60::vfunc_15(const char* p) {
    char buf[0x101];
    FUN_0026f330(p, buf, 0x101);
    if (FUN_00355c13(buf, 0)) {
        drive.error = 0;
        return 1;
    }
    drive.error = FUN_0026f3e0(GetLastError());
    return 0;
}
} // namespace core
