#include "gen/owners.h"
unsigned char owners::Converter_1d2da0::FUN_001d2da0(hulk_uintptr value, int* result) {
    float number;
    unsigned char ok = FUN_001d2d40(((unsigned int)value), &number);
    if (ok)
        *result = (int)(__int64)(number + 0.5f);
    return ok;
}