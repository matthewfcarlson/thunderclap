extern "C" void __cdecl thunk_FUN_00267090(int);

struct Target_30ebd0 {
    char pad[0x10];
    int value;
};

void __fastcall FUN_0030ebd0(Target_30ebd0* self, void*) {
    thunk_FUN_00267090(self->value);
}