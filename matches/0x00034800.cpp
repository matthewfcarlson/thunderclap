struct Obj {
    char pad[0x340];
    float value;
};

float __fastcall FUN_00034800(Obj* self) {
    return self->value;
}
