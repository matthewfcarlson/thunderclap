#include "decls/data/engine/audio.h"
#include "gen/owners.h"

struct Item_263300 {
    char pad[0x20];
    Item_263300* F(unsigned char);
};
void __cdecl FUN_00247550(void*, Item_263300*);
Item_263300* Item_263300::F(unsigned char flags) {
    ((owners::Str_240060 *)(((Item_263300*)((char*)this + 0x10))))->FUN_00240060();
    ((owners::Str_240060 *)(((Item_263300*)((char*)this + 4))))->FUN_00240060();
    if (flags & 1)
        FUN_00247550(((char*)&DAT_004e7b98), this);
    return this;
}