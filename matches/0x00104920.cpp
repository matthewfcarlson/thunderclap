class X {
  public:
    char pad[0x88];
    unsigned char value;
};
unsigned char __fastcall FUN_00104920(X* self) {
    return self->value;
}