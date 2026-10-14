class C {
  public:
    char pad[0x18];
    float m18;
    bool Set(float f);
};
bool C::Set(float f) {
    m18 = f * 0.0174532925f;
    return true;
}
