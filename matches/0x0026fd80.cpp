#include "compat/ptr.h"
typedef unsigned int uint_26fd80;
extern "C" hulk_uintptr FUN_0026fd80(hulk_uintptr value, uint_26fd80 alignment) {
    if (alignment != 0)
        value = (value / alignment) * alignment;
    return value;
}