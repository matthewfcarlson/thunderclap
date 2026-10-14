void __cdecl thunk_FUN_00267090(int);
struct Target_304350 {
    int a;
    int b;
};
void __fastcall FUN_00304350(Target_304350* self) {
    int v = self->a;
    self->b = v;
    if (v)
        thunk_FUN_00267090(v);
}