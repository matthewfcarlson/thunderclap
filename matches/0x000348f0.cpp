struct Obj {
    char pad[0x384];
    char value;
};
char __fastcall FUN_000348f0(Obj* self) {
    return self->value;
}