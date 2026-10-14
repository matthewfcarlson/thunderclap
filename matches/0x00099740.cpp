class A_99740 {
  public:
    int pad;
    unsigned int value;
};
unsigned int __fastcall target(A_99740* self) {
    return (self->value >> 2) & 1;
}