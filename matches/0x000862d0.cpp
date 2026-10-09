struct X {
    char pad[0x14];
    unsigned value;
};
unsigned __fastcall target(X* self) {
    return self->value;
}