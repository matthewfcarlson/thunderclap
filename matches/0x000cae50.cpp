struct X {
    char pad[0xb8];
    unsigned int value;
};
unsigned int __fastcall target(X* self) {
    return self->value;
}