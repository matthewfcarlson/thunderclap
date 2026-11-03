#include "compat/ptr.h"
extern "C" hulk_uintptr FUN_0026fd50(hulk_uintptr value, unsigned int alignment) {
    if (alignment != 0 && value % alignment != 0)
        return (value - value % alignment) + alignment;
    return value;
}
