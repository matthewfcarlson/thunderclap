class X {
  public:
    char pad[0xb8];
    float value;
    float Get();
};
float X::Get() {
    return value;
}
