struct Inner {
    void f(int);
};
struct Obj {
    char pad[8];
    Inner* a;
    int b;
};
extern void __fastcall FUN_00059d30(Obj*);
extern void __cdecl thunk_FUN_00267090(int);
void __fastcall FUN_0005a010(Obj* self) {
    FUN_00059d30(self);
    if (self->a)
        self->a->f(3);
    int value = self->b;
    self->a = 0;
    thunk_FUN_00267090(value);
    self->b = 0;
}