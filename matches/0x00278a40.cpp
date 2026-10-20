#include "gen/core.h"
extern int gLast;
struct XboxSaveDrive_nv_278a40 {
    int Init(int, int);
};
extern "C" core::XboxSaveDrive* __cdecl Alloc(int, int);
int __cdecl Make(int* out, int arg, int size) {
    gLast = size;
    core::XboxSaveDrive* p = Alloc(size, 0x910);
    *out = p ? ((XboxSaveDrive_nv_278a40*)(p))->Init(arg, size) : 0;
    return (int)(*out);
}
