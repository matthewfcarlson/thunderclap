extern "C" char DAT_00433354[];
extern "C" char DAT_004333ac[];
typedef unsigned int U;
extern void __stdcall Release(U);
extern void __cdecl Dispose(U);
struct Texture {
    U vt;
    char pad[12];
    U a;
    U b;
    U c;
    char gap[0x68 - 0x1c];
    U d;
    void BaseDestroy();
};
void __fastcall FUN_00326290(Texture* self) {
    self->vt = ((int)DAT_004333ac);
    if (self->a)
        Release(self->a);
    if (self->b) {
        Release(self->b);
        Dispose(self->b);
    }
    if (self->c) {
        Release(self->c);
        Dispose(self->c);
    }
    if (self->d)
        Release(self->d);
    self->vt = ((int)DAT_00433354);
    self->BaseDestroy();
}