class A_16e7e0 {
  public:
    char pad[0x38];
    float value;
    char Set(float degrees);
};
char A_16e7e0::Set(float degrees) {
    value = degrees * 0.017453292f;
    return 1;
}
