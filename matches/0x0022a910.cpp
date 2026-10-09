extern int g_count;
extern int vtable;
extern void cleanup();
struct Driver {
    int* vptr;
};
void __fastcall target(Driver* self) {
    self->vptr = &vtable;
    --g_count;
    cleanup();
}
