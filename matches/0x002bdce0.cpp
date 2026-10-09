// Same code shape as 0x00086380 (propagated; names are from that function)
class A {
    char pad[0x4c];

  public:
    unsigned int value;
};
unsigned int __fastcall target(A* self) {
    return self->value;
}