class A {
  public:
    char pad[0x120];
    int value;
};
bool __fastcall target(A* self) {
    return self->value != 0;
}