#include "decls/data/engine/core.h"
// data: gLast = DAT_004cdbb0

#include "compat/ptr.h"
#include "gen/core.h"
// core::XboxSaveDrive's constructor (0x00278500: the drive's name, its heap)
struct XboxSaveDrive_nv_278a40 {
    void* FUN_00278500(const char* name, void* heap);
};
extern "C" void* FUN_00266e00(int a, int b);
extern "C" void __cdecl FUN_00278a40(void** out, const char* name, int heap) {
    HULK_SIZE32(CoreXboxSaveDrive, 0x910);
    DAT_004cdbb0 = heap;
    void* p = FUN_00266e00(heap, (int)sizeof(CoreXboxSaveDrive));
    *out = p ? ((XboxSaveDrive_nv_278a40*)p)->FUN_00278500(name, (void*)(hulk_intptr)heap) : 0;
}
