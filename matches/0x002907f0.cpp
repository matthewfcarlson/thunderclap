struct Obj_2907f0 {
    int a;
    int b;
};
extern void __cdecl f(int, int);
extern void __cdecl g(int);
void __fastcall target(Obj_2907f0* self) {
    if (self->a) {
        f(self->a, self->b);
        g(self->a);
    }
}