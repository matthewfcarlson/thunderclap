class A {
  public:
    char pad[0xa4];
    float value;
};
float __fastcall target(A* self) {
    return self->value;
}