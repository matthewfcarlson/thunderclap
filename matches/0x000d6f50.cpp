typedef unsigned int uint_d6f50;
struct Obj_d6f50 {
    char pad[4];
    void* p4;
    void* p8;
    void* pc;
};
struct Helper_d6f50 {
    uint_d6f50 Get();
};
uint_d6f50 __fastcall FUN_000d6f50(Obj_d6f50* self) {
    uint_d6f50 v = ((Helper_d6f50*)self->p8)->Get();
    v &= 0xffffff7f;
    if (self->p4)
        v |= 0x80;
    if (self->pc)
        v |= 0x100;
    return v;
}