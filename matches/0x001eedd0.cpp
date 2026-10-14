struct Sub_1eedd0 {
    int x;
};
struct X_1eedd0 {
    void* vptr;
    char pad[0x14];
    Sub_1eedd0 sub;
};
extern "C" void __fastcall Init(Sub_1eedd0*);
extern void* VTable_1eedd0;
void __fastcall Target(X_1eedd0* self) {
    Init(&self->sub);
    self->vptr = &VTable_1eedd0;
}