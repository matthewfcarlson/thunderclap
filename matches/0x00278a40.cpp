#include "decls/data/engine/core.h"
// data: gLast = DAT_004cdbb0

#include "compat/ptr.h"
#include "gen/core.h"
struct XboxSaveDrive_nv_278a40 {
    int Init(int, int);
};
extern "C" core::XboxSaveDrive* __cdecl Alloc(hulk_intptr, int);
int __cdecl Make(int* out, int arg, int size) {
    DAT_004cdbb0 = size;
    core::XboxSaveDrive* p = Alloc(size, 0x910);
    *out = p ? ((XboxSaveDrive_nv_278a40*)(((core::XboxSaveDrive*)(p))))->Init(arg, size) : 0;
    return (int)(*out);
}
