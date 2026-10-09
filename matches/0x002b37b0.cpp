typedef unsigned int u32;
void __cdecl release(u32);
struct Obj { void* vf; char pad[12]; u32 a; u32 b; };
void __fastcall target(Obj* self) {
    self->vf = (void*)0x42e554;
    release(self->a);
    release(self->b);
    self->vf = (void*)0x3f6098;
}