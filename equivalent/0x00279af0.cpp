// STATUS: equivalent (tools/equiv.py level 3: 90 inputs, branch coverage 14/14)
// core::XboxSaveDrive::vfunc_11 @ 0x00279af0
#include "decls/data/platform/xbox/core.h"

namespace core { struct XboxSaveDrive { virtual void vfunc_0(); virtual void vfunc_1(); virtual void vfunc_2(); virtual void vfunc_3(); virtual void vfunc_4(); virtual void vfunc_5(); virtual void vfunc_6(); virtual void vfunc_7(); virtual void vfunc_8(); virtual void vfunc_9(); virtual void vfunc_10(); virtual bool vfunc_11(void*, int); char pad[0xb4-4]; int error; char pad2[0xe0-0xb8]; unsigned int slots[4]; bool FUN_002788c0(); bool FUN_00278de0(); bool FUN_00279490(void*, int); int FUN_002787c0(unsigned int); }; }
extern "C" int __stdcall FUN_002109b6(void*, int);
namespace XAPILIB { unsigned int __stdcall GetLastError(); }
bool core::XboxSaveDrive::vfunc_11(void* handle, int unused) {
    if (!FUN_002788c0() || !FUN_00278de0()) return false;
    unsigned int i;
    for (i = 0; i < 4; ++i) if (slots[i] == (*(unsigned int*)((char*)&DAT_0052c270 + 4))) break;
    if (i < 4) {
        if (!FUN_00279490(handle, 0)) return false;
        int result = FUN_002109b6(handle, 0);
        if (result == -1) { error = FUN_002787c0(XAPILIB::GetLastError()); return false; }
        *(*(int**)&DAT_0052c270) = result;
        (*(int*)((char*)&DAT_0052c270 + 12)) = 2;
        if (!FUN_00278de0()) return false;
        slots[i] = -1;
    }
    error = 0;
    return true;
}