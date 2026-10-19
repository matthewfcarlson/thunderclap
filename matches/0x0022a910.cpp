extern int g_count_22a910;
extern int vtable_22a910;
extern void __fastcall cleanup(void*);
struct Driver {
    int* vptr;
};
void __fastcall target(Driver* self) {
    self->vptr = &vtable_22a910;
    --g_count_22a910;
    cleanup((void*)(self));
}
