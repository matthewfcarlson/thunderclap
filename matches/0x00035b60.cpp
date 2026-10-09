struct X {
    char pad[0x22e4];
    unsigned int value;
};
unsigned int __fastcall target(X* self) {
    return self->value;
}