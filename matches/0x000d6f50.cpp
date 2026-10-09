typedef unsigned int uint;
struct Obj {
    char pad[4];
    void* p4;
    void* p8;
    void* pc;
};
struct Helper {
    uint Get();
};
uint __fastcall FUN_000d6f50(Obj* self) {
    uint v = ((Helper*)self->p8)->Get();
    v &= 0xffffff7f;
    if (self->p4)
        v |= 0x80;
    if (self->pc)
        v |= 0x100;
    return v;
}