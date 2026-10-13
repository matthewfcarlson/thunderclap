class X {
  public:
    char pad[0x14];
    float value;
    float Get();
};

float X::Get() {
    return value;
}
