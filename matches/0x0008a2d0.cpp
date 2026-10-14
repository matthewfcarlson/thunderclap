struct O {
    char pad[0x80];
    int a;
    int b;
    void* p;
};
void* __fastcall FUN_0008a2d0(O* self) {
    if (self->a == -1)
        return 0;
    if (self->b == -1)
        return 0;
    return (char*)&self->p;
}
