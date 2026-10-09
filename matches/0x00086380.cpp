class A {
    char pad[0x4c];

  public:
    unsigned int value;
};
unsigned int __fastcall target(A* self) {
    return self->value;
}