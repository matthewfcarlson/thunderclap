#include "gen/owners.h"
struct Inner_ca930 {
};
struct Obj_ca930 {
    void* vptr;
    char pad[0x50];
};
extern void* HUD_vftable;
extern void* Overlay_vftable;
void __fastcall Target(Obj_ca930* self) {
    self->vptr = &HUD_vftable;
    ((owners::Thing_f7960 *)(((Inner_ca930*)((char*)self + 0x54))))->FUN_000f7960();
    self->vptr = &Overlay_vftable;
}