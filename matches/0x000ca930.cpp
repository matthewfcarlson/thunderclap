struct Inner {
    void Init();
};
struct Obj {
    void* vptr;
    char pad[0x50];
};
extern void* HUD_vftable;
extern void* Overlay_vftable;
void __fastcall Target(Obj* self) {
    self->vptr = &HUD_vftable;
    ((Inner*)((char*)self + 0x54))->Init();
    self->vptr = &Overlay_vftable;
}