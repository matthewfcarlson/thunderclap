class A_99740 {
  public:
    int pad;
    unsigned int value;
};
extern "C" unsigned int __fastcall FUN_00099740(A_99740* self) {
    return (self->value >> 2) & 1;
}