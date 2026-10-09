struct Obj {
    char pad[0x510c];
    void* p;
};
int __fastcall FUN_003375a0(Obj* self) {
    if (self->p)
        return *(int*)((char*)self->p + 0x824);
    return -1;
}