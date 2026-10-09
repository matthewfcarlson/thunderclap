class C {
    char pad[0xb2];

  public:
    unsigned char value;
};
unsigned char __fastcall target(C* self) {
    return self->value;
}