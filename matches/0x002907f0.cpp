struct Obj {
    int a;
    int b;
};
extern void __cdecl f(int, int);
extern void __cdecl g(int);
void __fastcall target(Obj* self) {
    if (self->a) {
        f(self->a, self->b);
        g(self->a);
    }
}