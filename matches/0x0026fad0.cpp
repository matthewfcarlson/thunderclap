#include "compat/ptr.h"
#include "decls/data/records.h"

namespace core {
// core::Drive::vfunc_19 (records.h CoreXboxDrive's drive): finds the next file of a directory (0x00355bc2, the XAPI
// find-next), 0x0026f4b0 fills the caller's result
class Drive_26fad0 : public CoreDrive {
  public:
    int vfunc_19(int* a, int b);
    int FUN_0026f4b0(void* result, void* entry, int* handle);
};
} // namespace core
extern "C" int __stdcall FUN_00355bc2(int a, int* b);

int core::Drive_26fad0::vfunc_19(int* a, int b) {
    int t;
    char buf[0x140];
    int v = *a;
    if (v == -1) {
        error = 1;
        return 0;
    }
    if (FUN_00355bc2(v, (int*)buf) == 0) {
        t = -1;
        error = FUN_0026f4b0((void*)(hulk_intptr)b, buf, &t);
    } else {
        error = FUN_0026f4b0((void*)(hulk_intptr)b, buf, a);
    }
    return error == 0;
}
