class C {
  public:
    char pad[0xf9];
    unsigned char value;
};
unsigned char __fastcall Target(C* self) {
    return self->value;
}