#include "compat/ptr.h"
struct Object {
    Object* FUN_001d4830();
};
extern Object* DAT_004e23cc;
void* __cdecl FUN_0008d690(hulk_uintptr);
Object* FUN_001d4c90() {
    if (!DAT_004e23cc) {
        void* memory = FUN_0008d690(0x5494);
        if (memory) {
            DAT_004e23cc = ((Object*)memory)->FUN_001d4830();
            return DAT_004e23cc;
        }
        DAT_004e23cc = 0;
    }
    return DAT_004e23cc;
}