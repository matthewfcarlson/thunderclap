// Same code shape as 0x00086280 (propagated; names are from that function)
class C_284e50 {
    char pad[0x20];

  public:
    unsigned int value;
};
unsigned int __fastcall target(C_284e50* self) {
    return self->value;
}