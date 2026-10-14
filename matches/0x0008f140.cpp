struct Obj_8f140 {
    char pad[0x20];
    int value;
};
void __cdecl thunk(int);
void __fastcall target(Obj_8f140* self) {
    thunk(self->value);
    self->value = 0;
}