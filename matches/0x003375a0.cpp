struct Obj_3375a0 {
    char pad[0x510c];
    void* p;
};
int __fastcall FUN_003375a0(Obj_3375a0* self) {
    if (self->p)
        return *(int*)((char*)self->p + 0x824);
    return -1;
}