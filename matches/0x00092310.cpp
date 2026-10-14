// Same code shape as 0x00086280 (propagated; names are from that function)
class C_92310 {
    char pad[0x20];

  public:
    unsigned int value;
};
unsigned int __fastcall target(C_92310* self) {
    return self->value;
}