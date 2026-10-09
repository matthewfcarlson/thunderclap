struct Obj {
    char pad[0x20];
    int value;
};
void __cdecl thunk(int);
void __fastcall target(Obj* self) {
    thunk(self->value);
    self->value = 0;
}