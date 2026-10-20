#include "compat/ptr.h"
struct X {
    unsigned int a, b;
    X(int n);
};
extern "C" unsigned __int64 __cdecl make(int, int, hulk_intptr);
X::X(int n) {
    unsigned __int64 v = 0;
    a = (unsigned int)v;
    b = (unsigned int)(v >> 32);
    v = n ? make(n, 0, 0) : 0;
    a = (unsigned int)v;
    b = (unsigned int)(v >> 32);
}