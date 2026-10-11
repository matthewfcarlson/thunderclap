extern "C" char DAT_003f6098[];
extern "C" char DAT_0042e554[];
typedef unsigned int u32;
void __cdecl release(u32);
struct Obj {
    void* vf;
    char pad[12];
    u32 a;
    u32 b;
};
void __fastcall target(Obj* self) {
    self->vf = (void*)((int)DAT_0042e554);
    release(self->a);
    release(self->b);
    self->vf = (void*)((int)DAT_003f6098);
}