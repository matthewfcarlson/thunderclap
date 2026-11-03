#include "decls/data/engine/unknown.h"

#include "compat/ptr.h"
extern float* FUN_00219e50(int a, int b);

float* FUN_002175b0(hulk_intptr object, int* desc, int index) {
    int key;
    switch (*desc) {
    case 5:
        key = ((int*)desc[1])[2];
        break;
    case 7:
        key = ((int*)desc[1])[2];
        break;
    default:
        return (float*)&(*(const float*)&DAT_00426824);
    }
    if (key != 0) {
        int* arr = *(int**)((char*)object + 0x10);
        int elem = *(int*)((char*)arr + index * 4 + 0x74);
        return FUN_00219e50(key, elem);
    }
    return (float*)&(*(const float*)&DAT_00426824);
}
