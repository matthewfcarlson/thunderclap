extern "C" char DAT_003f6098[];
extern "C" char DAT_0042e554[];
typedef unsigned int u32_2b37b0;
void __cdecl release(u32_2b37b0);
struct Obj_2b37b0 {
    void* vf;
    char pad[12];
    u32_2b37b0 a;
    u32_2b37b0 b;
};
void __fastcall target(Obj_2b37b0* self) {
    self->vf = (void*)((int)DAT_0042e554);
    release(self->a);
    release(self->b);
    self->vf = (void*)((int)DAT_003f6098);
}