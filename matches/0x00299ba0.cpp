// Same code shape as 0x002907f0 (propagated; names are from that function)
struct Obj_299ba0 {
    int a;
    int b;
};
extern void __cdecl f(int, int);
extern void __cdecl g(int);
void __fastcall target(Obj_299ba0* self) {
    if (self->a) {
        f(self->a, self->b);
        g(self->a);
    }
}