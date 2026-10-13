struct Obj {
    char pad[0x34];
    float value;
};
float __fastcall FUN_00012020(Obj* self) {
    return self->value;
}
