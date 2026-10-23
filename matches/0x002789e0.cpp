#include "gen/core.h"
struct Obj_2789e0 {
    char pad[0xb4];
    int value;
};
struct XboxSaveDrive_nv_2789e0 {
    int FUN_002787c0(int);
};
bool __fastcall target(Obj_2789e0* self, void*, int arg) {
    int result = ((XboxSaveDrive_nv_2789e0*)(((core::XboxSaveDrive*)(((core::XboxSaveDrive*)(self))))))->FUN_002787c0(arg);
    self->value = result;
    return result == 0;
}