#include "decls/data/engine/unknown.h"
// data: s_math = DAT_00434af0, s_mptr = DAT_00434970, s_pow = DAT_004269e4

typedef unsigned int u32_33bca0;
typedef int (*Fn_33bca0)(void);
extern void f3390(void*, const char*, const char*, int);
extern void f213340(void*, u32_33bca0);
extern void f213790(void*, int, const char*);
extern void f2134a0(void*, Fn_33bca0, int);
extern int f33b880();
int target(void* p) {
    f3390(p, DAT_00434af0, ((const char*)&DAT_00434970), 0);
    f213340(p, 0x40490fdb);
    f213790(p, -2, DAT_00434aec);
    f2134a0(p, f33b880, 0);
    f213790(p, -10001, DAT_004269e4);
    return 1;
}