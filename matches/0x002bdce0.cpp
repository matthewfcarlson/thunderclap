// Same code shape as 0x00086380 (propagated; names are from that function)
class A_2bdce0 {
    char pad[0x4c];

  public:
    unsigned int value;
};
unsigned int __fastcall target(A_2bdce0* self) {
    return self->value;
}