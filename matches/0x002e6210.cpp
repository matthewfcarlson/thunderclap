// Same code shape as 0x002907f0 (propagated; names are from that function)
struct Obj_2e6210 {
    int a;
    int b;
};
extern void __cdecl f(int, int);
extern void __cdecl g(int);
void __fastcall target(Obj_2e6210* self) {
    if (self->a) {
        f(self->a, self->b);
        g(self->a);
    }
}