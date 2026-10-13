extern void* g_vftable[];
struct Obj {
    void* vptr;
    Obj() { vptr = g_vftable; }
};
extern void* g_vftable[] = {(void*)0x433774};
void* __fastcall FUN_003290a0(Obj* self) {
    self->vptr = g_vftable;
    return self;
}
