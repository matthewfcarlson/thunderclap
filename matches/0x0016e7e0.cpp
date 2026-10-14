class A {
  public:
    char pad[0x38];
    float value;
    char Set(float degrees);
};
char A::Set(float degrees) {
    value = degrees * 0.017453292f;
    return 1;
}
