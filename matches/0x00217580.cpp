#include "compat/ptr.h"
struct Result_217580 {
    int value;
};
extern Result_217580* __cdecl FUN_00219e50(hulk_intptr, int);
int* __cdecl FUN_00217580(hulk_intptr ptr, int count, int param3) {
    Result_217580* p = FUN_00219e50(ptr, param3);
    if (p->value == 0) {
        *(unsigned char*)(ptr + 6) |= (unsigned char)(1 << count);
        return 0;
    }
    return (int*)p;
}