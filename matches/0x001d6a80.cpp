class A_1d6a80 {
  public:
    char pad[0x120];
    int value;
};
bool __fastcall target(A_1d6a80* self) {
    return self->value != 0;
}