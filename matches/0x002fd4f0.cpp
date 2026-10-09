struct Thing {
    char pad[0x70];
    void* a;
    void* b;
};
extern void __fastcall cleanup(void*);
extern void __fastcall next(void*);
void __fastcall target(Thing* self) {
    if (self->a)
        cleanup(self->a);
    if (self->b)
        next(*(void**)((char*)self->b + 0x20));
}