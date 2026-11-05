#include "compat/ptr.h"
unsigned char Find(hulk_intptr value, int* array, int count) {
    int i = 0;
    if (count > 0) {
        do {
            if (value == array[i])
                return 1;
            ++i;
        } while (i < count);
    }
    return 0;
}