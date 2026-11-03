#include "gen/core.h"
extern "C" unsigned int __cdecl FUN_002698b0(char*);
struct CementLibrary_nv_277b40 {
    unsigned int f(unsigned int, unsigned int);
};
struct C_277b40 {
    unsigned int f(char*, unsigned int);
};
unsigned int C_277b40::f(char* path, unsigned int arg) {
    if (*path == '\\')
        ++path;
    unsigned int x = FUN_002698b0(path);
    return ((CementLibrary_nv_277b40*)(((core::CementLibrary*)this)))->f(x, arg);
}