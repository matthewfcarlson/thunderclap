#include "compat/ptr.h"
typedef unsigned int uint_335270;
hulk_uintptr FUN_00335270(hulk_uintptr x) {
    return (x & 0xff00 | x << 16) << 8 | (x & 0xff0000 | x >> 16) >> 8;
}