#include "decls/data/platform/xbox/unknown.h"

extern "C" {
struct S_240e00 {
    char pad[0x98];
    float value;
};
void __cdecl FUN_00240e00(float x) {
    (*(S_240e00**)&DAT_004e5ce0)->value = x;
}
}