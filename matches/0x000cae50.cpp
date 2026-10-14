struct X_cae50 {
    char pad[0xb8];
    unsigned int value;
};
unsigned int __fastcall target(X_cae50* self) {
    return self->value;
}