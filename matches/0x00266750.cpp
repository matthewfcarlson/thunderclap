class C {
  public:
    char pad[0x14];
    int x;
};
bool __fastcall target(C* self) {
    return self->x == 3;
}