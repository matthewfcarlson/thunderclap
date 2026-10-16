// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 14/14)
// FUN_00268d30 @ 0x00268d30
#include "decls/data/platform/xbox/core.h"

struct InputValue {
    char padding[0x20];
    void *kind;
    char gap[4];
    unsigned int data;
    double FUN_00268d30(unsigned int *source);
};
double InputValue::FUN_00268d30(unsigned int *source)
{
    if (!source) return 0.0;
    if (kind == (*(void**)&DAT_004cd698)) return ((*source & data) != 0) ? 1.0f : 0.0f;
    if (kind == (*(void**)&DAT_004cd69c)) return ((unsigned char *)(data + (unsigned int)source))[0] * 0.00392156862745098;
    if (kind == (*(void**)&DAT_004cd6a0) || kind == (*(void**)&DAT_004cd6a4)) {
        short value = ((short *)(data + (unsigned int)source))[0];
        if (value > 0) return (double)value * 1.52593e-05f + 0.5f;
        return (double)value * 1.52588e-05f + 0.5f;
    }
    return 0.0;
}