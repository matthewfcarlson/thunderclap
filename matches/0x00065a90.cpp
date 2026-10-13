struct Obj {
    char p[0x1a0];
    unsigned char value;
};
unsigned char __fastcall FUN_00065a90(Obj* self) {
    return self->value;
}