class A {
  public:
    char pad[0x60];
    float value;
    float Get();
};

float A::Get() {
    return value;
}
