class C {
  public:
    char pad[0x270];
    float value;
};
float __fastcall target(C* self) {
    return self->value;
}