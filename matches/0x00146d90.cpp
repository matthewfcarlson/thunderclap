class A {
  public:
    char pad[0x30];
    float f30;
    char Set(float v);
};
char A::Set(float v) {
    f30 = v * 0.017453292f;
    return 1;
}
