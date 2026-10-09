typedef unsigned int u32;
void FUN_0025b7d0(u32);
void thunk_FUN_00267090(u32);
struct S { u32 value; };
void __fastcall target(S* self) {
    if (self->value != 0) {
        FUN_0025b7d0(self->value);
        if (self->value != 0)
            thunk_FUN_00267090(self->value);
        self->value = 0;
    }
}