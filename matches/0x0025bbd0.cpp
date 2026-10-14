typedef unsigned int u32_25bbd0;
void FUN_0025b7d0(u32_25bbd0);
void thunk_FUN_00267090(u32_25bbd0);
struct S_25bbd0 {
    u32_25bbd0 value;
};
void __fastcall target(S_25bbd0* self) {
    if (self->value != 0) {
        FUN_0025b7d0(self->value);
        if (self->value != 0)
            thunk_FUN_00267090(self->value);
        self->value = 0;
    }
}