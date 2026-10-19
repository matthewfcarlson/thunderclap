// Same code shape as 0x0022a910 (propagated; names are from that function)
extern int g_count_22a9c0;
extern int vtable_22a9c0;
struct ThisCall_002222d0 {
    void cleanup();
};
struct Driver {
    int* vptr;
};
void __fastcall target(Driver* self) {
    self->vptr = &vtable_22a9c0;
    --g_count_22a9c0;
    ((ThisCall_002222d0*)(self))->cleanup();
}
