class C {
    char pad[0x20];

  public:
    unsigned int value;
};
unsigned int __fastcall target(C* self) {
    return self->value;
}