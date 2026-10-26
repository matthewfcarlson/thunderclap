#include "decls/data/game/unknown.h"
// data: g_buffer = DAT_004e238c, g_flag_1c6af0 = DAT_004e239c

#include "compat/ptr.h"
typedef unsigned char u8;
typedef unsigned int u32_1c6af0;
class Obj_1c6af0 {
  public:
    char pad[16];
    hulk_uintptr mPtr;
};
char* __fastcall target(Obj_1c6af0* self) {
    if (self->mPtr)
        return (char*)(self->mPtr + 0x2c);
    if ((((u8*)&(*(u32_1c6af0*)&DAT_004e239c))[0] & 1) == 0)
        (*(u32_1c6af0*)&DAT_004e239c) |= 1;
    return ((char*)&DAT_004e238c);
}