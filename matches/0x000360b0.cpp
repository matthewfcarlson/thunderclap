extern const float g_zero_360b0;
struct Obj_360b0 {
    char pad[0x11c];
    void* ptr;
    char pad2[0x1b14 - 0x120];
    float value;
};
float __fastcall FUN_000360b0(Obj_360b0* p) {
    if (p->ptr)
        return p->value * *(float*)((char*)p->ptr + 0x134);
    return g_zero_360b0;
}