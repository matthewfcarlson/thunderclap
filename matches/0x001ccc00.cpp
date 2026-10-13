class X {
  public:
    char pad[0x11a4];
    float value;
    float Get();
};

float X::Get() {
    return value;
}
