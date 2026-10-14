// Same code shape as 0x00086280 (propagated; names are from that function)
class C_285230 {
    char pad[0x20];

  public:
    unsigned int value;
};
unsigned int __fastcall target(C_285230* self) {
    return self->value;
}