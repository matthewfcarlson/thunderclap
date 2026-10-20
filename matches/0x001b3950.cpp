#include "compat/ptr.h"
typedef void(__cdecl* Fn)(int, int, int, int, int);
void FUN_001b3950(int unused, int* p, int unused2, Fn fn) {
    int a = *p++;
    int b = *p++;
    int* q = p;
    *(int* volatile*)&p = (int*)*q++;
    int e = q[1];
    int d = q[0];
    fn(a, b, (hulk_intptr)*(int* volatile*)&p, d, e);
}