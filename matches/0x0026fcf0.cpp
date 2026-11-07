#include "decls/data/engine/core.h"
#include "compat/ptr.h"
#include "gen/core.h"

// core::XboxDrive on its heap (0x0026f570 constructs it: the path, the heap), then its slot 21 with the details
// buffer, whose result is the function's
extern "C" void* FUN_00266e00(int a, int b);
struct XboxDrive_nv_26fcf0 {
    core::XboxDrive* FUN_0026f570(const char* name, const char* source);
};
struct DriveSlots_26fcf0 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5();
    virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17();
    virtual void s18(); virtual void s19(); virtual void s20(); virtual int s21(char*);
};
int __cdecl FUN_0026fcf0(core::XboxDrive** result, const char* path, int heap, char* details) {
    HULK_SIZE32(CoreXboxDrive, 0x1e4);
    DAT_004cdbb0 = heap;
    void* allocated = FUN_00266e00(heap, (int)sizeof(CoreXboxDrive));
    core::XboxDrive* object = allocated ? ((XboxDrive_nv_26fcf0*)allocated)->FUN_0026f570(path, (const char*)(hulk_intptr)heap) : 0;
    *result = object;
    return ((DriveSlots_26fcf0*)object)->s21(details);
}
