struct Inner_5a010 {
    void f(int);
};
struct Obj_5a010 {
    char pad[8];
    Inner_5a010* a;
    int b;
};
extern void __fastcall FUN_00059d30(Obj_5a010*);
extern void __cdecl thunk_FUN_00267090(int);
void __fastcall FUN_0005a010(Obj_5a010* self) {
    FUN_00059d30(self);
    if (self->a)
        self->a->f(3);
    int value = self->b;
    self->a = 0;
    thunk_FUN_00267090(value);
    self->b = 0;
}